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
- What is the differences between aptitude and apt?
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

## Notes

- MBR (Master Boot Record)

## Recourses

- Using Disks and Other Storage Media: https://tldp.org/LDP/sag/html/partitions.html
- 

