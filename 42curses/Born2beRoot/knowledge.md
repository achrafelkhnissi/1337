```
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    knowledge.md                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 12:56:16 by ael-khni          #+#    #+#              #
#    Updated: 2021/12/01 12:56:16 by ael-khni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
```


# Evaluation

## Project overview

#### 1. How the virtual machine work?

A virtual machine (VM) is a virtual environment that works like a computer inside of a computer. It will run on an isolated partition of its host computer with its own resources of CPU power, memory, an operating system, and other resources. \
Virtualization uses software to simulate virtual hardware that allows multiple VMs to run on a single machine. The physical machine is known as the host while the VMs running on it are called guests. This process is managed by software known as a hypervisor.

#### 2. What is the basic differences between CentOS and Debian?

I choose Debian it's easier to install and configure than CentOS (and i haven't use CentOS befoe) \
CentOS is a free downstream rebuild of the commercial Red Hat Enterprise Linux distribution where, in contrast, Debian is the free upstream distribution that is the base for other distributions, including the Ubuntu Linux distribution.

#### 3. What is the purpose of virtual machines?

The main purpose of VMs is to operate multiple operating systems at the same time, from the same piece of hardware. Without virtualization, operating multiple systems — like Windows and Linux — would require two separate physical units. \

#### 4. If you chose CentOS, Then what is SELinux and DNF are?

#### 5. If you chose Debian, Then what is the difference between aptitude and apt?

- In Debian-based OS distributions, the default package manager we can use is dpkg. This tool allows us to install, remove and manage programs on our operating system. However, in most cases, these programs come with a list of dependencies that must be installed for the main program to function properly. One option is to manually install these dependencies. However, APT (Advanced Package Tool), which is a tool that uses dpkg, can be used to install all the necessary dependencies when installing a program. So now we can install a useful program with a single command. 
- APT can work with different back-ends and fron-ends to make use of its services. One of them is apt-get, which allows us to install and remove packages. Along with apt-get, there are also many tools like apt-cache to manage programs. In this case, apt-get and apt-cache are used by apt. Thanks to apt we can install .deb programs easily and without worrying about dependencies. But in case we want to use a graphical interface, we will have to use aptitude. Aptitude also does better control of dependencies, allowing the user to choose between different dependencies when installing a program.

#### 6. What APPArmor is?

AppArmor provides Mandatory Access Control (MAC) security. In fact, AppAmor allows the system administrator to restrict the actions that processes can perform. For example, if an installed application can take photos by accessing the camera application, but the administrator denies this privilege, the application will not be able to access the camera application. If a vulnerability occurs (some of the restricted tasks are performed), AppArmor blocks the application so that the damage does not spread to the rest of the system. \
In AppArmor, processes are restricted by profiles. Profiles can work in complain-mode and in enforce-mode. In enforce mode, AppArmor prohibits applications from performing restricted tasks. In complain-mode, AppArmor allows applications to do these tasks, but creates a registry entry to display the complaint.

- To check AppArmor status: `sudo aa-status`

## Simple setup

#### 1. Pay attention to the password chosen, it must follow the rules imposed in the subject.

1. Password Age:
- `sudo vim /etc/login.defs`
- Password expire every 30 days: `PASS_MAX_DAYS	30`
- The minimum number of days between password change: `PASS_MIN_DAYS 2`
- Send a warning to a user 7 days before password expire: `PASS_WARN_AGE 7`
2. Password Strength:
- `sudo vim /etc/pam.d/common-password`
- `minlen=10`: passowrd minimum length is 10.
- `ucredit=-1 dcredit=-1`: It must contain at least an uppercase character and a numeric character.
- `maxrepeat=3`: To only allow 3 consecutive identical characters.
- `reject_username`: To reject the password if it contains the username in some form.
- `difok=7`: The number of change required in the new password from the old password is 7.
- `enforce_for_root`: Implement the same policy on root.

#### 2. Check that the UFW service is started.

- `sudo service ufw status`
- `sudo ufw status`

#### 3. Check that the SSH service is started.

- `sudo service ssh status`

#### 4. Check that the chosen OS is Debian or CentOS.

- `head -n 2 /etc/os-release`

#### 5. Check that a user with your login is present on the VM.

-  `awk -F: '{ print $1}' /etc/passwd`

## User

#### 1. Check that the user has been added and it belongs to the "sudo" and "user42" groups.
#### 2. Create a new user. Assign it a password of your choice, respecting the subject rules.
#### 3. Explain how you were able to set up the rules resquested.
#### 4. Create a group named "evaluating" & add the new user to this group.
#### 5. Check if that user belongs to the "evaluating" group.
#### 6. Explain the advantages of this password policy as well as the advantages and disadvantages of its implementation.

## Hostname and partitions
#### 1. Check that the hostname of the machine is correctly formatted.
#### 2. Modify this hostname then restart the machine. The hostname should be updated.
#### 3. Restore the machine to its original hostname.
#### 4. View the partitions for this VM.
#### 5. Compare the output with the example given in the subject.
#### 6. Briefly explain how LVM works and what it is all about.  

## SUDO
#### 1. Check that the "sudo" program is properly installed on the VM.
#### 2. Assign the new user to the sudo group.
#### 3. The subject imposes strict rules for sudo. Explain the value and operation of sudo.
#### 4. Show the implementation of the rules imposed by the subject.
#### 5. Verify that "/var/log/sudo/" forlder exists and has at least one file.
#### 6. Check the contents of the files in this folder. (you should see a history of the commands used with sudo)
#### 7. Run a command via sudo & and see if the file(s) in the "/var/log/sudo/" folder have been updated.

## UFW
#### 1. Check that the "UFW" program is properly installed on the VM.
#### 2. Check that it is working properly.
#### 3. Explain what is UFW and the value of using it.
#### 4. List the active rules in UFW. A rule must exist for port 4242
#### 5. Add a new rules to open port 8080. Check that this one has been added by listing the active rules.
#### 6. Delete the new rule.

## SSH
#### 1. Check that the "SSH" service is properly installed on the VM.
#### 2. Check that it is working properly.
#### 3. Explain what is SSH and the value of using it.
#### 4. Verify that the SSH service only uses port 4242.
#### 5. Log in with the newly created user using SSH.
#### 6. Make sure that you cannot use SSH with the "root" user.

## Script monitoring
#### 1. Explain how the script works by showing the code.
#### 2. Explain what "corn" is.
#### 3. Explain how you set up the script so that it runs every 10 minutes from when the server starts.
#### 4. Ensure that this script runs every minute.
#### 5. Make the script stop running when the server has started up. (without modifying the script itself)

# Q&A

### What is VirtualBox?

VirtualBox is designed to run virtual machines on your physical machine without reinstalling your OS that is running on a physical machine.

### What is a hypervisor?

A hypervisor is software that creates and runs virtual machines (VMs). A hypervisor, sometimes called a virtual machine monitor (VMM), isolates the hypervisor operating system and resources from the virtual machines and enables the creation and management of those VMs.

### How does a hypervisor work? 

Hypervisors support the creation and management of virtual machines (VMs) by abstracting a computer's software from its hardware. Hypervisors make virtualization possible by translating requests between the physical and virtual resources.
<!--
- What is UTM?
-->

### What is a server?

A server is a piece of computer hardware or software (computer program) that provides functionality for other programs or devices, called "clients". This architecture is called the client–server model. Servers can provide various functionalities, often called "services", such as sharing data or resources among multiple clients, or performing computation for a client. \
A server is a computer or system that provides resources, data, services, or programs to other computers, known as clients, over a network.

### What is a web server?

On the hardware side, a web server is a computer that stores web server software and a website's component files.

### What is TTY mode?

When requiretty is set, sudo must be run from a logged-in terminal session (a tty). This prevents sudo from being used from daemons or other detached processes like cronjobs or webserver plugins. It also means you can't run it directly from an ssh call without setting up a terminal session.

This can prevent certain kinds of escalation attacks. For example, if I have a way to modify the crontab for a user who has NOPASSWD sudo permissions, I could use that to kick off a job as root. With requiretty, I can't do that...

<!--
### What is CentOS?

### What is KDump? (for CentOS)

### What is SELinux and DNF? (related to CentOS)

### What is a signature.txt file?

-->

### What is LVM? (Logical Valume Manager) and what its uses?

Creating single logical valumes off multiple physical volumes or entire hard disks, allowing for dynamic volume resizing. \
Managing large hard disk farms by allowing disks to be added and replaced iwhtout downtime or service disruption.\
On small systems (like a desktop), instead of having to estimate at installation time how big a partition might need to be, LVM allows filesystems to be esily resized as needed.
- Performing consistent backups by taking snapshots of the logical volumes.
- Encrypting multiple physical partitions with one password.
- In Linux, LVM is a device mapper framework that provides logical valume managment for the linux kernel.
- https://tldp.org/HOWTO/LVM-HOWTO/
- https://en.wikipedia.org/wiki/Logical\_Volume\_Manager\_(Linux)
- LVM (Logical Volume Manager) is an abstraction layer between a storage device and a file system. We get many advantages from using LVM, but the main advantage is that we have much more flexibility when it comes to managing partitions. Suppose we create four partitions on our storage disk. If for any reason we need to expand the storage of the first three partitions, we will not be able to because there is no space available next to them. In case we want to extend the last partition, we will always have the limit imposed by the disk. In other words, we will not be able to manipulate partitions in a friendly way. Thanks to LVM, all these problems are solved.
By using LVM, we can expand the storage of any partition (now known as a logical volume) whenever we want without worrying about the contiguous space available on each logical volume. We can do this with available storage located on different physical disks (which we cannot do with traditional partitions). We can also move different logical volumes between physical devices. Of course, services and processes will work the same way they always have. But to understand all this, we have to know:	
	- Physical Volume (PV): physical storage device. It can be a hard disk, an SD card, a floppy disk, etc. This device provides us with storage available to use.
	- Volume Group (VG): to use the space provided by a PV, it must be allocated in a volume group. It is like a virtual storage disk that will be used by logical volumes. VGs can grow over time by adding new VPs.
	- Logical volume (LV): these devices will be the ones we will use to create file systems, swaps, virtual machines, etc. If the VG is the storage disk, the LV are the partitions that are made on this disk.

### What is partitioning in Linux? (related to LVM)

- Partitioning also allows you to divide your hard drive into isolated sections, where each section behaves as its own hard drive.
- The idea is that if you have one hard disk, and want to have, say, two operating systems on it, you can divide the disk into two patitions. Each operating system uses its partition as it wishes and doesn't touch the other one. This way the two operating sysytems can co-exist peacefully on the same hard disk. Without partitions one would have to buy a hard disk for each operating sysytem.
- Logical Partitions:
- Extended Partitions:
- Primary Partitions:
- Sub-Partitions:
- Each partition and extended partition has its own device file. The naming convention for these fles is that a partition's number is appended after the name of the whole disk, with the convention that 1-4 are primary partitions(regardless of how mamy primary partitions there are) and number greater than 5 are logical partitions (regardless of within which primary partition they reside). For example, `dev/hda1` is the first primary partition on the first IDE hard disk, and `/dev/sdb7` is the third extended partition on the second SCSI hard disk.

### What is a Device Mapper? (related to LVM)

- The Device Mapper is a framework provided by the Linux Kernel for mapping  physical block dvices
- You can view block devices informations with the lsblk command.
- Block Devices:
- Character Devices:
- Using the `ls -l /dev/` command: The first character in the first column, i.e 'c', tells an informed user the type of the file, in this case a character device. For 'b' for block devices, 'd' for directories, '-' for ordinary files, 'l' for Symbolic link files (links on any regular files), 'p' Named pipe (a mechanism for interprocess communication), 's' for socket (used for interprocess communication).

### What is SSH?

SSH or Secure Shell is a remote administration protocol that allows users to control and modify their servers over the Internet thanks to an authentication mechanism. Provides a mechanism to authenticate a user remotely, transfer data from the client to the host, and return a response to the request made by the client. \
SSH was created as an alternative to Telnet, which does not encrypt the information that is sent. SSH uses encryption techniques to ensure that all client-to-host and host-to-client communications are done in encrypted form. One of the advantages of SSH is that a user using Linux or MacOS can use SSH on their server to communicate with it remotely through their computer's terminal. Once authenticated, that user will be able to use the terminal to work on the server.\
There are three different techniques that SSH uses to encrypt:
- Symmetric encryption: a method that uses the same secret key for both encryption and decryption of a message, for both the client and the host. Anyone who knows the password can access the message that has been transmitted.
- Asymmetric encryption: uses two separate keys for encryption and decryption. These are known as the public key and the private key. Together, they form the public-private key pair.
- Hashing: another form of cryptography used by SSH. Hash functions are made in a way that they don't need to be decrypted. If a client has the correct input, they can create a cryptographic hash and SSH will check if both hashes are the same.

### What is ports?

A port is a virtual point where network connections start and end. Ports are software-based and managed by a computer's operating system. Each port is associated with a specific process or service.

### What is UFW firewall?

- FW (Uncomplicated Firewall) is a software application responsible for ensuring that the system administrator can manage iptables in a simple way. Since it is very difficult to work with iptables, UFW provides us with an interface to modify the firewall of our device (netfilter) without compromising security. Once we have UFW installed, we can choose which ports we want to allow connections, and which ports we want to close. This will also be very useful with SSH, greatly improving all security related to communications between devices.

### What is a cron job?

- Linux task manager that allows us to execute commands at a certain time. We can automate some tasks just by telling cron what command we want to run at a specific time. For example, if we want to restart our server every day at 4:00 am, instead of having to wake up at that time, cron will do it for us.
- The cron command line utility, also known as cron job is a job scheduler on unix-like operating systems.
```
* * * * * command to be executed
- - - - -
| | | | |
| | | | ----- Day of week (0 - 7) (Sunday=0 or 7)
| | | ------- Month (1 - 12)
| | --------- Day of month (1 - 31)
| ----------- Hour (0 - 23)
------------- Minute (0 - 59)
```

### What is `wall` command?

- command used by the root user to send a message to all users currently connected to the server. If the system administrator wants to alert about a major server change that could cause users to log out, the root user could alert them with wall.

### In the network settings of the virtualbox! what is the difference between "NAT" and "Bridged Adapter"?

NAT mode will mask all network activity as if it came from your Host OS, although the VM can access external resources. Bridged mode replicates another node on the physical network and your VM will receive it's own IP address if DHCP is enabled in the network.

### What is WordPress?

WordPress is a content management system (CMS) that allows you to host and build websites. WordPress contains plugin architecture and a template system, so you can customize any website to fit your business, blog, portfolio, or online store.

### What is NGINX / Apache2? and what can i use as thier alternative?

- NGINX is open source software for web serving, reverse proxying, caching, load balancing, media streaming, and more. It started out as a web server designed for maximum performance and stability.

- Apache2 Web Server. Apache is the most commonly used Web server on Linux systems. Web servers are used to serve Web pages requested by client computers. Clients typically request and view Web pages using Web browser applications such as Firefox, Opera, Chromium, or Internet Explorer.

- Lighttpd

### What is lighttpd, MariaDB, and PHP?

### What is sha1 format?

n cryptography, SHA-1 is a cryptographic hash function which takes an input and produces a 160-bit hash value known as a message digest – typically rendered as a hexadecimal number, 40 digits long. It was designed by the United States National Security Agency, and is a U.S. Federal Information Processing Standard.

### What is BIOS?

BIOS (basic input/output system) is the program a computer's microprocessor uses to start the computer system after it is powered on. It also manages data flow between the computer's operating system (OS) and attached devices, such as the hard disk, video adapter, keyboard, mouse and printer.

### What is the kernel?

- The kernel is the heart of the operating system. It interacts with the hardware and most of the tasks like memory management, task scheduling and file management.

### What is a FileSystem? (files and directoies)

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


### What is mounting in linux?

- The mount command attaches the filesystem of an external device to the filesystem of a system. It instructs the operating system that filesystem is ready to use and associate it with a particular piont in the system's heirarchy. Mounting will make files, directories and devices available to the users.
- Mounting is the attaching of an additional filesystem to the currently accessible filesystem of a computer.

### What is VFS (Virtual File System)?

A virtual file system or virtual filesystem switch is an abstract layer on top of a more concrete file system. The purpose of a VFS is to allow client applications to access different types of concrete file systems in a uniform way. 

### What is a Device File:

- Represent Hardware devices to User-Mode applications. Look it a normal files at first glance. Do not contain any data - they are used for communications only. in 'ls -l', the first letter is either 'c' or 'b', depending on the device type. Have a major number, describe the type fo the Device. Have a minor number, describing the instance of the Device (allows several Devices of the same type)
- Block Device: A Block Device is a device whose driver communicates by sending entire blocks of data. Example - hard disks, USB cameras, Disk-On-Key. (Note: Filesystems can only be mounted if they are on block devices.)
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
- `man pam_pwquality`

## Answers

1. How to get the hostname:
	- `hostname`
	- `cat /proc/sys/kernel/hostname`
	- `hostnamectl`
2. Check os version in Linux
	- `cat /etc/os-release`
	- `hostnamectl`
3. How to change hostname?
	- `sudo vim /etc/hostname` 
## Resources

- LVM: https://wiki.ubuntu.com/Lvm
- Partitions: https://tldp.org/LDP/sag/html/partitions.html
- Filesystems: https://tldp.org/LDP/sag/html/filesystems.html
- Unix/Linux - User Administration: https://www.tutorialspoint.com/unix/unix-user-administration.htm
- Mounting Definition: http://www.linfo.org/mounting.html
- Linux Partitions and Directories: https://www.dell.com/support/kbdoc/en-uk/000131456/the-types-and-definitions-of-ubuntu-linux-partitions-and-directories-explained
- Device Driver Basics: https://tldp.org/LDP/khg/HyperNews/get/devices/basics.html
- LVM HOWTO: https://tldp.org/HOWTO/LVM-HOWTO/
- The Linux System Administrator's Guide: https://tldp.org/LDP/sag/html/index.html
- How to change visudo editor from nano to vim?: https://askubuntu.com/questions/539243/how-to-change-visudo-editor-from-nano-to-vim
- How to add jobs to cron: https://www.cyberciti.biz/faq/how-do-i-add-jobs-to-cron-under-linux-or-unix-oses/
- 42cursus - Born2beRoot: https://github.com/ayoub0x1/born2beroot
