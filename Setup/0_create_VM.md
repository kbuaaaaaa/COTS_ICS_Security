# Step 0: Setting up the Virtual Machines

There will be 5 virtual machines in the virtual testbed. Consists of:
* 2 Pfsense Router
* 2 Windows10 VMs
* 1 Kali Linux VM

The following section will give instruction on creating the virtual machines.

## Kali Linux
The setup instruction for Kali Linux on VirtualBox can be found on the Kali Linux official website, [here](https://www.kali.org/docs/virtualization/install-virtualbox-guest-vm/).


## Windows 10
The ISO image for Windows 10 can be downloaded [here](https://www.microsoft.com/en-gb/software-download/windows10ISO) (select the 64 bit).

To create a Windows10 VM, following these steps:

* Open VirtualBox
* Click New ![](images/new.png)
* In the ISO image field, select the ISO you downloaded.![](images/windowiso.png)
* Keep clicking Next. But make sure you give it at least 2048MB base memory and 20GB virtual hard disk.
* Start the VM and let the Window installer run itself.
* Do the same step for the second Windows10 VM

## Pfsense router
The ISO image for the router can be downloaded [here](https://www.pfsense.org/download/).
You must choose the options shown below.
![](images/pfsense_download.png)

To create a Pfsense router VM, following these steps:

* Open VirtualBox
* Click New ![](images/new.png)
* In the ISO image field, select the ISO you downloaded. And select the options specified below. ![](images/pfsenseiso.png)
* Keep clicking Next. But make sure you give it at least 1024MB base memory and 10GB virtual hard disk.
* Start the VM and follow the PFsense router installation wizard.
* Do the same step for the second Pfsense VM