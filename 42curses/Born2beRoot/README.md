```
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    README.md                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 18:34:52 by ael-khni          #+#    #+#              #
#    Updated: 2021/11/23 18:34:52 by ael-khni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
```

## Evaluation

### Project overview
1. How the virtual machine work?
2. What is the basic differences between CentOS and Debian?
3. What is the purpose of virtual machines?
4. If you chose CentOS, Then what is SELinux and DNF are?
5. If you chose Debian, Then what is the difference between aptitude and apt?
6. What APPArmor is?
7. The script must display information all every 10 minutes.

### Simple setup
1. Pay attention to the password chosen, it must follow the rules imposed in the subject.
2. Check that the UFW service is started.
3. Check that the SSH service is started.
4. Check that the chosen OS is Debian or CentOS.
5. Check that a user with your login is present on the VM.

### User
1. Check that the user has been added and it belongs to the "sudo" and "user42" groups.
2. Create a new user. Assign it a password of your choice, respecting the subject rules.
3. Explain how you were able to set up the rules resquested.
4. Create a group named "evaluating" & add the new user to this group.
5. Check if that user belongs to the "evaluating" group.
6. Explain the advantages of this password policy as well as the advantages and disadvantages of its implementation.

### Hostname and partitions
1. Check that the hostname of the machine is correctly formatted.
2. Modify this hostname then restart the machine. The hostname should be updated.
3. Restore the machine to its original hostname.
4. View the partitions for this VM.
5. Compare the output with the example given in the subject.
6. Briefly explain how LVM works and what it is all about.  

### SUDO
1. Check that the "sudo" program is properly installed on the VM.
2. Assign the new user to the sudo group.
3. The subject imposes strict rules for sudo. Explain the value and operation of sudo.
4. Show the implementation of the rules imposed by the subject.
5. Verify that "/var/log/sudo/" forlder exists and has at least one file.
6. Check the contents of the files in this folder. (you should see a history of the commands used with sudo)
7. Run a command via sudo & and see if the file(s) in the "/var/log/sudo/" folder have been updated.

### UFW
1. Check that the "UFW" program is properly installed on the VM.
2. Check that it is working properly.
3. Explain what is UFW and the value of using it.
4. List the active rules in UFW. A rule must exist for port 4242
5. Add a new rules to open port 8080. Check that this one has been added by listing the active rules.
6. Delete the new rule.

### SSH
1. Check that the "SSH" service is properly installed on the VM.
2. Check that it is working properly.
3. Explain what is SSH and the value of using it.
4. Verify that the SSH service only uses port 4242.
5. Log in with the newly created user using SSH.
6. Make sure that you cannot use SSH with the "root" user.

### Script monitoring
1. Explain how the script works by showing the code.
2. Explain what "corn" is.
3. Explain how you set up the script so that it runs every 10 minutes from when the server starts.
4. Ensure that this script runs every minute.
5. Make the script stop running when the server has started up. (without modifying the script itself)

### BONUS



## VirtualBox 101

1. New: To create a new virtual OS
	- Name: descriptive name of the virtual machine
	- Machine Folder: The destination folder for the new virtual machine image.
	- Type: Linux
	- Version: Debian (64-bit)
2. Memory size: Select of RAM to be allocated.
3. Hard disk:
	- Create a virtual hard disk now.
4. Hard disk file type:
	- VDI (VirtualBox Disk Image) < choose this.
	- VHD (Virtual Hard Disk)
	- VMDK (Virtual Machine Disk)
5. Storage on physical hard disk:
	- Dynamically allocated: the new virtual hard disk file should grow as it is used
	- Fixed size
6. File location and size:
	- Select the size of the virtual hard disk.
7. Go to Settings > Storage > Controller: IDE > Empty > Attributes > Optical Drive
	- & choose the iso file of the OS.
8. Start.
9. You can scale the screen from: View > Virtual Screen.
10. Click the windows botton when u want to move the mouse from the virtual machine to your desktop.

## Born2beRoot

1. Basic Configuration:
	- Hotname: ael-khni42 (login42)
	- Domain name: ael-khni1337.net
	- Root password: theDARKsideofme4-
	- Full name for the new user: Achraf El Khnissi
	- Username for your account: ael-khni
	- Password for the new user: Leet1337+
2. Partition disks:
	- Manual
	- SCSI3 (0, 0, 0) (sda) - 32.2 GB ATA VBOX HARDDISK
	- Create new empty partition table on this device? (yes)
	- sda1: ?
		- Select the FREE SPACE
		- Create a new partition
		- New partition size: 500M
		- Type for the new partition: Primary
		- Location for the new partition: Beginning
		- Partition settings > Mount point > boot > done setting up the partition.
	- sda5: ?
		- Select the FREE SPACE
		- Create a new partition
		- New partition size: max 
		- Type for the new partition: Logical
		- Partition settings > Mount point > Do not mount it > done setting up the partition.
	- Configure encrypted valumes:
		- Write the changes to disk and configure encryptedd volumes? (yes)
		- Create encrypted valumes
		- Devices to encrypt: (sda5)
		- Done setting up the partition
		- Finish
		- Really erase the data on sda5? (yes)
		- Encryption passshrase: Born2beRoot
	- Configure the Logical Volume Manager (LVM):
		- Write the changes to disks and configure LVM? (yes)
		- Create volume group
		- Volume group name: LVMGroup 
		- Devices for the new volume group: /dev/mapper/sda5_crypt
		- LVM configuration action: Create logical volume > Volume group: LVMGroup > Logical volume name: root > size: 10GB 
		- LVM configuration action: Create logical volume > Volume group: LVMGroup > Logical volume name: swap > size: 2.3GB 
		- LVM configuration action: Create logical volume > Volume group: LVMGroup > Logical volume name: home > size: 5GB 
		- LVM configuration action: Create logical volume > Volume group: LVMGroup > Logical volume name: var > size: 3GB 
		- LVM configuration action: Create logical volume > Volume group: LVMGroup > Logical volume name: srv > size: 3GB 
		- LVM configuration action: Create logical volume > Volume group: LVMGroup > Logical volume name: tmp > size: 3GB 
		- LVM configuration action: Create logical volume > Volume group: LVMGroup > Logical volume name: var-log > size: 4GB 
		- Finish
	- Editing partitions:
		- Choose "home" partition > how to use this partition? : Ext4 > Mount point: home > Done.
		- Choose "root" partition > how to use this partition? : Ext4 > Mount point: root> Done.
		- Choose "srv" partition > how to use this partition? : Ext4 > Mount point: srv> Done.
		- Choose "swap" partition > how to use this partition? : Swap erea > done.
		- Choose "var" partition > how to use this partition? : Ext4 > Mount point: var > Done.
		- Choose "var-log" partition > how to use this partition? : Ext4 > Mount point: Manually > var/log > Done.
		- Finish partitioning and write changes to disk. > (yes)
	- Scan extra installation media? (No)
	- Choose software to install: "remove all"
	- Install the GRUB boot loader to your primary drive? (yes)
	- Device for boot loader installation: /dev/sda
	- Installation complete
3. Installing
	- Installing sudo: `apt install sudo`
	- Verify whether sudo was successfully installed: `dpkg -l | grep sudo`
	- Installing SSH: `sudo apt install openssh-server`
	- Verify whether ssh was successfully installed: `dpkg -l | grep ssh`


#### Mandatory part:

- What is VirtualBox?
VirtualBox is designed to run virtual machines on your physical machine without reinstalling your OS that is running on a physical machine.

- What is a VM?
A virtual machine (VM) is a virtual environment that works like a computer inside of a computer. It will run on an isolated partition of its host computer with its own resources of CPU power, memory, an operating system, and other resources.

- What is UTM?
- What is a server?
- What is Debian?
- What is CentOS?
- What is KDump? (for CentOS)
- What is the difference between Debian and CentOS?
- What is SELinux? (for CentOS)
- What is AppArmor? (for Debian)
- What is LVM? (Logical Valume Manager) and what its uses?
	- Creating single logical valumes off multiple physical volumes or entire hard disks, allowing for dynamic volume resizing.
	- Managing large hard disk farms by allowing disks to be added and replaced iwhtout downtime or service disruption.
	- On small systems (like a desktop), instead of having to estimate at installation time how big a partition might need to be, LVM allows filesystems to be esily resized as needed.
	- Performing consistent backups by taking snapshots of the logical volumes.
	- Encrypting multiple physical partitions with one password.
	- In Linux, LVM is a device mapper framework that provides logical valume managment for the linux kernel.
	- https://tldp.org/HOWTO/LVM-HOWTO/
	- https://en.wikipedia.org/wiki/Logical\_Volume\_Manager\_(Linux)
- What is partitioning in Linux? (related to LVM)
	- Partitioning also allows you to divide your hard drive into isolated sections, where each section behaves as its own hard drive.
	- The idea is that if you have one hard disk, and want to have, say, two operating systems on it, you can divide the disk into two patitions. Each operating system uses its partition as it wishes and doesn't touch the other one. This way the two operating sysytems can co-exist peacefully on the same hard disk. Without partitions one would have to buy a hard disk for each operating sysytem.
	- Logical Partitions: 
	- Extended Partitions: 
	- Primary Partitions:
	- Sub-Partitions:
	- Each partition and extended partition has its own device file. The naming convention for these fles is that a partition's number is appended after the name of the whole disk, with the convention that 1-4 are primary partitions(regardless of how mamy primary partitions there are) and number greater than 5 are logical partitions (regardless of within which primary partition they reside). For example, `dev/hda1` is the first primary partition on the first IDE hard disk, and `/dev/sdb7` is the third extended partition on the second SCSI hard disk.
- What is a Device Mapper? (related to LVM)
	- The Device Mapper is a framework provided by the Linux Kernel for mapping  physical block dvices
	- You can view block devices informations with the lsblk command.
	- Block Devices:
	- Character Devices:
	- Using the `ls -l /dev/` command: The first character in the first column, i.e 'c', tells an informed user the type of the file, in this case a character device. For 'b' for block devices, 'd' for directories, '-' for ordinary files, 'l' for Symbolic link files (links on any regular files), 'p' Named pipe (a mechanism for interprocess communication), 's' for socket (used for interprocess communication).
- What is the differences between aptitude and apt?
- What is APPArmor?
- What is SSH?
- What is ports?
- What is UFW firewall?
- What is DNF? (to install UFW on CentOF)
- What is cron?
- In the network settings of the virtualbox! what is the difference between "NAT" and "Bridged Adapter"?

#### Bonus part:

- What is WordPress?
- What is lighttpd, MariaDB, and PHP?
- What is NGINX / Apache2? and what can i use as thier alternative?
- What is a signature.txt file?
- What is sha1 format?


#### Extra

- What is BIOS?
- What is the kernel?
	- The kernel is the heart of the operating system. It interacts with the hardware and most of the tasks like memory management, task scheduling and file management.
- What is a FileSystem? (files and directoies)
	- All the data of Unix is organized into files. All files are then organized into directories. These directories are further organized into a tree-like structure called filesystem.
	- `/` : This is the root directory which should contain only the directories needed at the top level of the file structure.
	- `/bin` : This is where the executable files are located. These files are available to all users.
	- `/dev` : There are device drivers.
	- `/etc` : Supervisor directory commands, configuration files, disk configuration files, valid user lists, groups, ethernet, hosts, where to send critical messages.
	- `/lib` : Contains shared library files and sometimes other kernel-related files.
	- `/boot` : Contains files for booting the system.
	- `/home` : Contains the home directory for users and other accounts.
	- `/mnt` : Used to mount other temporary files systems, such as `cdrom` and `floppy` for the `CD-ROM` drive and `floppy diskette drive`, respectively.
	- `/proc` : Contains all processes marked as a file by `process number` or other information that is dynamic to the system.
	- `/tmp` : Holds temporary files used between system boots.
	- `/usr` : Used for miscellaneous purposes, and can be used by many users. Includes admninistrative commands, shared files, library files, and others.
	- `/var` : Typically contains variable-length files such as log and print files and any other type of file that may contain a variable amount of data.
	- `/sbin` : Contains binary (executable) files, usually for system administration. For example, `fdisk` and `ifconfig` utilities.
	- `/kernel` : Contains kernel files.
- What is SELinux and DNF? (related to CentOS)
- What is mounting in linux?
	- The mount command attaches the filesystem of an external device to the filesystem of a system. It instructs the operating system that filesystem is ready to use and associate it with a particular piont in the system's heirarchy. Mounting will make files, directories and devices available to the users.
	- Mounting is the attaching of an additional filesystem to the currently accessible filesystem of a computer.
- What is VFS (Virtual File System)?
- What is a Device File:
	- Represent Hardware devices to User-Mode applications. Look it a normal files at first glance. Do not contain any data - they are used for communications only. in 'ls -l', the first letter is either 'c' or 'b', depending on the device type. Have a major number, describe the type fo the Device. Have a minor number, describing the instance of the Device (allows several Devices of the same type)
	- Block Device:
		- A Block Device is a device whose driver communicates by sending entire blocks of data. Example - hard disks, USB cameras, Disk-On-Key. (Note: Filesystems can only be mounted if they are on block devices.)
	- Character Device:
		- A Character Device is a device whose driver communicates by sending and receiving single characters (bytes, octets). Example - serial ports, parallel ports, sound cards, keyboard.
	- 3 differences between character devices and block devices:
		- Character devices can only be accessed in bytes, while block devices are accessed in blocks, such as 512 bytes, 1024 bytes, etc.
		- Block devices can be accessed randomly, but character devices cannot.
		- There are no restrictions on the size of character and blocks, and blocks also can be accessed in bytes.

## Notes

- MBR (Master Boot Record)
- Root account: This is also called `superuser` and would have complete and unfettered control of the system.
- System accounts: System accounts are those needed for the operation of system-specific components for example mail accounts and the `sshd` accounts. These accounts are usually needed for some specific function on your system, and any modification to them could adversely affect the system.
- User accounts: User accounts provide interactive access to the system for users and groups of users. General users are typically assigned to these accounts and usually have limited access to critical system files and directories.
- Unix supports a concept of `Group Account` which logically groups a number of accounts. Every account would be a part of another group account. A unix group plays important role in handling file permissions and process management.
- There are four main user  administration files:
	- `/etc/passwd` - Keeps the user account and password information. This file holds the majority of information about accounts on the Unix System.
	- `/etc/shadow` - Holds the encrypted password of the corresponding account. Not all the systems support this file.
	- `/etc/group` - This file contains the group information for each account.
	- `/etc/gshadow` - This file contains secure group account information.

## Recourses

- Partitions: https://tldp.org/LDP/sag/html/partitions.html
- Filesystems: https://tldp.org/LDP/sag/html/filesystems.html
- Unix/Linux - User Administration: https://www.tutorialspoint.com/unix/unix-user-administration.htm
- Mounting Definition: http://www.linfo.org/mounting.html
- Linux Partitions and Directories: https://www.dell.com/support/kbdoc/en-uk/000131456/the-types-and-definitions-of-ubuntu-linux-partitions-and-directories-explained
- Device Driver Basics: https://tldp.org/LDP/khg/HyperNews/get/devices/basics.html
- LVM HOWTO: https://tldp.org/HOWTO/LVM-HOWTO/
- The Linux System Administrator's Guide: https://tldp.org/LDP/sag/html/index.html 
