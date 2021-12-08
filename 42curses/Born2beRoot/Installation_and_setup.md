```
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Installation_and_setup.md                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-khni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 13:03:37 by ael-khni          #+#    #+#              #
#    Updated: 2021/12/01 13:03:37 by ael-khni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
```

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
	- sda1:
		- Select the FREE SPACE
		- Create a new partition
		- New partition size: 500M
		- Type for the new partition: Primary
		- Location for the new partition: Beginning
		- Partition settings > Mount point > boot > done setting up the partition.
	- sda5:
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


## Installation & Configuration

### Sudo
- Switch to root and its enviroment: `su root` or `su -`
- Install sudo: `apt install sudo`
- Verify installation: `dpkg -l | grep sudo`
- Add 'user' to sudo group: `adduser <username> sudo`
- Verify whether user was added: `getent group sudo`
- `reboot` for changes to take effect
- Verify sudopowers: `sudo -v`
- From here on out, run root-privileged commands via prefix `sudo`
- Configuring sudo: `sudo visudo`:
	- To change visudo edirot from nano to vim: `sudo update-alternatives --config editor`
	- To limit authentication using sudo to 3 attempts in the event of an incorrect password: `Defaults	passwd_tries=3`
	- To add a custom error message in the event of an incorrect password: `Defaults badpass_message="<custo-error-message>"` or `Defaults	insults`
	- To archive all sudo inputs & outputs to `/var/log/sudo`: `Defaults	log_input, log_output` && `Defaults	logfile=/var/log/sudo/sudo.log` && `Defaults iolog_dir="/var/log/sudo"`
	- To require TTV: `Defaults requiretty`
	- To set sudo paths: `Defaults        secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"`
- U can delete a user using `userdel` command and delete a group using `groupdel` command.
### SSH
- Install openssh-server: `sudo apt install openssh-server`
- Verify installation: `dpkg -l | grep ssh`
- Configure SSH: `sudo vim /etc/ssh/sshd_config`
	- To set up SSH using Port 4242 replace the following like with 4242: `13 #Port 22` with `13 Port 4242`
	- To disable SSH login as root irregardless of authentication mechanism replace: `32 #PermitRootLogin prohibit-password` with `32 PermitRootLogin no`
	- Check SSH status: `sudo service ssh status` or `systemctl status ssh`

### UFW
- Install ufw: `sudo apt install ufw`
- Verify installaiton: `dpkg -l | grep ufw`
- Enabe FireWall: `sudo ufw enable`
- Allowing incomming connections using Port 4242: `sudo ufw allow 4242`
- Check UFW status: `sudo ufw status`

### Connecting to Server via SSH
- SSH into your virtual machine using Port 4242: `ssh <username>@<ip> -p 4242`
- Terminate SSH session at any time with: `logout` or `exit`

## User Management

### Setting up a Strong 

#### Password Age

- Configure password age policy: `sudo vim /etc/login.defs`
- To set password to expire every 30 days replace `160 PASS_MAX_DAYS 99999` with `160 PASS_MAX_DAYS 30`
- To set minimum number of days between password changes to 2 days replace `161 PASS_MIN_DAYS 0` with `161 PASS_MAX_DAYS 2`
- To send user a warning message 7 days before password expire: `162 PASS_WARN_AGE 7`

#### Password Strength
- To set up policies in relation to password strength, install: `sudo apt install libpam-pwquality`
- Verify installation: `dpkg -l | grep libmap-pwquality`
- Configure password strength policy via: `sudo vim /etc/pam.d/common-password`
- Specifically the followin line: `25 password		requisite	pam_pwquality.so rety=3`
- To set password minimum length to 10 characters, add the following option to the above line: `minlen=10`
- To require password to contain at least an uppercase character and a numeric character: `ucredit=-1 dcredit=-1`
- To set a maximum of 3 consecutive identical characters: `maxrepeat=3`
- To reject the password if it contains <username> in some form: `reject_username`
- To set the number of changes required in the new password from the old password to 7: `difok=7`
- To implement the same policy on root: `enforce_for_root`
- Finally, it should look like the bellow:
```
password        requisite                       pam_pwquality.so retry=3 minlen=10 ucredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root
```
- To set the minimum number of days between password change: 
#### Creating a new user
- Create a new user: `sudo adduser <username>`
- Verify whether user was successfully created: `getent passwd <username>`
- Verify newly-created user's password expire information: `sudo chage -l <username>`

#### Creating a new group
- Create new user42 group: `sudo addgroup user42`
- Add user to user42 group: `sudo adduser <username> user42`
- Verify whether user was successfully added to user42 group: `getent group user42`

#### Setting up a cron job
- Configure cron as root: `sudo crontab -u root -e`
- To schedule a shell script to run every 10 minutes replace: `23 # m h dom mon dow command` with `23 */10 * * * * sh /path/to/script`
- Check root's scheduled cron jobs: `sudo crontab -u root -l`


## Linux Lighttpd MariaDB PHP (LLMP) Stack

### Lighttpd

- Install lighttpd: `sudo apt install lighttpd`
- Verify installation: `dpkg -l | grep lighttpd`
- Allow incoming connections using port 80: `sudo ufw allow 80`
- Configure Lighttpd: Enable below modules
```
$ sudo lighty-enable-mod fastcgi
$ sudo lighty-enable-mod fastcgi-php
$ sudo service lighttpd force-reload
``` 
- Check the lighty status: `systemctl status lighttpd.service` 
- In case it failed to activate/start user: `sudo apt install --reinstall lighttpd`

### MariaDB 

- install mariadb: `sudo apt install mariadb-server`
- verify installation: `dpkg -l | grep mariadb-server`
- start intractive script to remove insecure default settings:
```
$ sudo mysql_secure_installation
Enter current password for root (enter for none): #Just press Enter (do not confuse database root with system root)
Set root password? [Y/n] n
Remove anonymous users? [Y/n] Y
Disallow root login remotely? [Y/n] Y
Remove test database and access to it? [Y/n] Y
Reload privilege tables now? [Y/n] Y
```
- Log in to MariaDB console: `sudo mariadb`
- Create new database: `CREATE DATABASE <database-name>;`
- Create new database user and grant them full privileges on the newly-created database: ` GRANT ALL PRIVILEGES ON database-name.* to 'username'@'localhost' IDENTIFIED BY 'password';`
- Flush the privileges: `FLUSH PRIVILEGES;`
- Exit MariaDB shell: `exit`
- Verify whether database user was successfully created: `mariadb -u <username> -p` (then enter the password from previous step)
- Confirm whether database user has access to the database: `SHOW DATABASES;`
```
MariaDB [(none)]> SHOW DATABASES;
+--------------------+
| Database           |
+--------------------+
| <database-name>    |
| information_schema |
+--------------------+
```
- Exit the MariaDB shell: `exit`
- Note: In case you want to remove MariaDB -> https://askubuntu.com/questions/806107/remove-mariadb-mysql-databases/806441#806441

###  PHP

- Install: `sudo apt install php-cgi php-mysql php7.4`
- Verify installation: `dpkg -l | grep php`

### WordPress

- Install wget: `sudo apt install wget`
- Download WordPress to `/var/www/html`: `sudo wget http://wordpress.org/latest.tar.gz -P /var/www/html`
- Extract downloaded content: `sudo tar -xzvf /var/www/html/latest.tar.gz`
- Remove tarball: `sudo rm /var/www/html/latest.tar.gz`
- Copy content of `/var/www/html/wordpress` to `/var/www/html`: `sudo cp -r /var/www/html/wordpress/* /var/www/html`
- Remove wordpress directory: `sudo rm -rf /var/www/html/wordpress`
- Create WordPress configuration file from its sample: `sudo cp /var/www/html/wp-config-sample.php /var/www/html/wp-config.php`
- Configure WordPress to reference previously-created MariaDB database & user: `sudo vim /var/www/html/wp-config.php`
- Add your prevously created database:
```
23 define( 'DB_NAME', 'database_name_here' );^M
26 define( 'DB_USER', 'username_here' );^M
29 define( 'DB_PASSWORD', 'password_here' );^M
```

## File Transfer Protocol (FTP)

### Installing & Configuring FTP

- Install FTP: `sudo apt install vsftpd`
- Verify installation: `dpkg -l | grep vsftpd`
- Allow incomming connections using Port 21: `sudo ufw allow 21`
- Configure vsftpd: `sudo vim /etc/vsftpd.conf`
- To enable any form of FTP write command, uncomment `31 #write_enable=YES`
- To set root folder for FTP-connected user to `/home/<username>/ftp` add below lines:

```
$ sudo mkdir /home/<username>/ftp
$ sudo mkdir /home/<username>/ftp/files
$ sudo chown nobody:nogroup /home/<username>/ftp
$ sudo chmod a-w /home/<username>/ftp
<~~~>
user_sub_token=$USER
local_root=/home/$USER/ftp
<~~~>
```

- To prevent user from accessing files or using commands outside the directory tree, uncomment: `114 $chroot_local_user=YES`
- To whitelist FTP, add below lines:
```
$ sudo vi /etc/vsftpd.userlist
$ echo <username> | sudo tee -a /etc/vsftpd.userlist
<~~~>
userlist_enable=YES
userlist_file=/etc/vsftpd.userlist
userlist_deny=NO
<~~~>
```

### Connecting to Server via FTP

- FTP into your virtual machine: `ftp <ip-address>`
- Or: `sftp -P <port> <username>@<ip-address>`

<!--
- Wordpress login: ael-khni
- pass: `oPni$pdb)al*wyP!nI`
-->

