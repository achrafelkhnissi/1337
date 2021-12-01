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

## Extra 

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

- What is WordPress?
- What is lighttpd, MariaDB, and PHP?
- What is NGINX / Apache2? and what can i use as thier alternative?
- What is a signature.txt file?
- What is sha1 format?

```
                                           ##################################
                                           #    Part one: Evaluation Q&A    #
                                           ##################################
!GOOGLE IT IF YOU WANT MORE!

Q: Why Debian?
A: It's easier to install and configure than CentOS (and i haven't use CentOS befoe)

Q: What is virtual machine?
A: A Virtual Machine (VM) is a compute resource that uses software instead of a physical computer to run programs and deploy
apps. Each virtual machine runs its own operating system and functions separately from the other VMs, even when they are all
running on the same host. For example, you can run a virtual MacOS machine on a physical PC.

Q: What it's purpose?
A: VMs may be deployed to accommodate different levels of processing power needs, to run software that requires a different
operating system, or to test applications in a safe, sandboxed environment.

Q: How does it works?
A: VM working through "Virtualization" technology. Virtualization uses software to simulate virtual hardware that allows
VMs to run on a single host machine.

Q: Diff between aptitude and apt?
A: Aptitude is a high-level package manager while APT is lower-level package manager which can be used by other
higher-level package managers
(read more: https://www.tecmint.com/difference-between-apt-and-aptitude/)

Q: What is AppArmor?
A: AppArmor ("Application Armor") is a Linux kernel security module that allows the system administrator to restrict programs'
capabilities with per-program profiles.
(read more: https://en.wikipedia.org/wiki/AppArmor)

Q: What is SSH?
A: SSH, also known as Secure Shell or Secure Socket Shell, is a network protocol that gives users, particularly system
administrators, a secure way to access a computer over an unsecured network.
(read more: https://searchsecurity.techtarget.com/definition/Secure-Shell)

/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\
| You have to create a new user here.        |
| $ sudo adduser username                    | <- creating new user (yes (no))
| $ sudo chage -l username                   | <- Verify password expire info for new user
| $ sudo adduser username sudo               |
| $ sudo adduser username user42             | <- assign new user to sudo and user42 groups
\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/

Q: How your script works?
A: ... README.md

                                           ##################################
                                           #    Part two: What to check?    #
                                           ##################################
|***************************************|
| 1) lsblk                              1 <- Check partitions
| 2) sudo aa-status                     2 <- AppArmor status
| 3) getent group sudo                  3 <- sudo group users
| 4) getent group user42                4 <- user42 group users
| 5) sudo service ssh status            5 <- ssh status, yep
| 6) sudo ufw status                    6 <- ufw status
| 7) ssh username@ipadress -p 4242      7 <- connect to VM from your host (physical) machine via SSH
| 8) nano /etc/sudoers.d/<filename>     8 <- yes, sudo config file. You can $ ls /etc/sudoers.d first
| 9) nano /etc/login.defs               9 <- password expire policy
| 10) nano /etc/pam.d/common-password  10 <- password policy
| 11) sudo crontab -l                  11 <- cron schedule
|***************************************|


I think this one need an addition to make it more easy to pass evaluation. So, here we are on our checklist and his commands.

How to change hostname?
[$sudo nano /etc/hostname]

Where is sudo logs in /var/log/sudo?
[$cd /var/log/sudo/00/00 && ls]
You will see a lot of directories with names like 01 2B 9S 4D etc. They contain the logs we need.
[$ sudo apt update]
[$ ls]
Now you see that we have a new directory here.
[$ cd <nameofnewdirectory> && ls]
[$ cat log] <- Input log
[$ cat ttyout] <- Output log

How to add and remove port 8080 in UFW?
[$ sudo ufw allow 8080] <- allow
[$ sudo ufw status] <- check
[$ sudo ufw deny 8080] <- deny (yes yes)

How to run script every 30 seconds?
[$ sudo crontab -e]
Remove or commit previous cron "schedule" and add next lines in crontab file
|*************************************************|
| */1 * * * * /path/to/monitoring.sh              |
| */1 * * * * sleep 30s && /path/to/monitoring.sh |
|*************************************************|
To stop script running on boot you just need to remove or commit
|********************************|
| @reboot /path/to/monitoring.sh |
|********************************|
line in crontab file.
```
