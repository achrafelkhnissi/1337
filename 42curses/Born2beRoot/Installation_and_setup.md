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
	- Verify whether database user was successfully created: `mariadb -u <username> ] -p` (then enter the password from previous step)
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
3. PHP
	- Install: `sudo apt install php-cgi php-mysql php7.4`
	- Verify installation: `dpkg -l | grep php`
### WordPress
	- Install wget: `sudo apt install wget`
	- Download WordPress to `/var/www/html`: `sudo wget http://wordpress.org/lastest.tart.gz -P /var/www/html`
	- Extract downloaded content: `sudo tar -xzvf /var/www/html/lastest.tar.gz`
	- Remove tarball: `sudo rm /var/www/html/lastest.tar.gz`
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
