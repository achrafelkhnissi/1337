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

- Create a user with your login and add it to sudo && user42 group.

## VirtualBox 101



## Born2beRoot

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
- What is LVM? (Logical Valume Manager)
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

## Notes

- MBR (Master Boot Record)

## Recourses

- Partitions: https://tldp.org/LDP/sag/html/partitions.html
- Filesystems: https://tldp.org/LDP/sag/html/filesystems.html
- Unix/Linux - User Administration: https://www.tutorialspoint.com/unix/unix-user-administration.htm
- Mounting Definition: http://www.linfo.org/mounting.html

