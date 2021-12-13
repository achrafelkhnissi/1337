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
<h1 align="center">
	الشامل في البورن تو بي رووت 
</h1>

# Table of Contents

## Installation & Setup

1. [Installation & setup](https://github.com/achrafelkhnissi/1337/blob/master/42curses/Born2beRoot/Installation_and_setup.md)
	- [VirtualBox 101](https://github.com/achrafelkhnissi/1337/blob/master/42curses/Born2beRoot/Installation_and_setup.md#virtualbox-101)
	- [Setting up LVM & Partitions](https://github.com/achrafelkhnissi/1337/blob/master/42curses/Born2beRoot/Installation_and_setup.md#born2beroot)
	- [Installing & Configuring SUDO](https://github.com/achrafelkhnissi/1337/blob/master/42curses/Born2beRoot/Installation_and_setup.md#sudo)
	- [Installing & Configuring SSH](https://github.com/achrafelkhnissi/1337/blob/master/42curses/Born2beRoot/Installation_and_setup.md#ssh)
	- [Installing & Configuring UFW](https://github.com/achrafelkhnissi/1337/blob/master/42curses/Born2beRoot/Installation_and_setup.md#ufw)
	- [Connecting to Server via SSH](https://github.com/achrafelkhnissi/1337/blob/master/42curses/Born2beRoot/Installation_and_setup.md#connecting-to-server-via-ssh)
2. [User Management](https://github.com/achrafelkhnissi/1337/blob/master/42curses/Born2beRoot/Installation_and_setup.md#user-management)
	- [Password Age](https://github.com/achrafelkhnissi/1337/blob/master/42curses/Born2beRoot/Installation_and_setup.md#password-age)
	- [Password Strength](https://github.com/achrafelkhnissi/1337/blob/master/42curses/Born2beRoot/Installation_and_setup.md#password-strength)
	- [Creating a new user](https://github.com/achrafelkhnissi/1337/blob/master/42curses/Born2beRoot/Installation_and_setup.md#creating-a-new-user)
	- [Creating a new group](https://github.com/achrafelkhnissi/1337/blob/master/42curses/Born2beRoot/Installation_and_setup.md#creating-a-new-group)
	- [Setting up a cron job](https://github.com/achrafelkhnissi/1337/blob/master/42curses/Born2beRoot/Installation_and_setup.md#setting-up-a-cron-job)
3. [Linux Lighttpd MariaDB PHP (LLMP) Stack](https://github.com/achrafelkhnissi/1337/blob/master/42curses/Born2beRoot/Installation_and_setup.md#linux-lighttpd-mariadb-php-llmp-stack)
	- [Lighttpd](https://github.com/achrafelkhnissi/1337/blob/master/42curses/Born2beRoot/Installation_and_setup.md#lighttpd)
	- [MariaDB](https://github.com/achrafelkhnissi/1337/blob/master/42curses/Born2beRoot/Installation_and_setup.md#mariadb)
	- [PHP](https://github.com/achrafelkhnissi/1337/blob/master/42curses/Born2beRoot/Installation_and_setup.md#php)
	- [WordPress](https://github.com/achrafelkhnissi/1337/blob/master/42curses/Born2beRoot/Installation_and_setup.md#wordpress)
4. [File Transfer Protocol (FTP)](https://github.com/achrafelkhnissi/1337/blob/master/42curses/Born2beRoot/Installation_and_setup.md#file-transfer-protocol-ftp)
	- [Installing & Configuring FTP](https://github.com/achrafelkhnissi/1337/blob/master/42curses/Born2beRoot/Installation_and_setup.md#installing--configuring-ftp)
	- [Connecting to Server via FTP](https://github.com/achrafelkhnissi/1337/blob/master/42curses/Born2beRoot/Installation_and_setup.md#connecting-to-server-via-ftp)

## Evaluation

1. [Evaluation](https://github.com/achrafelkhnissi/1337/blob/master/42curses/Born2beRoot/evaluation.md#evaluation)
	- [Project overview](https://github.com/achrafelkhnissi/1337/blob/master/42curses/Born2beRoot/evaluation.md#project-overview)
	- [Simple setup](https://github.com/achrafelkhnissi/1337/blob/master/42curses/Born2beRoot/evaluation.md#simple-setup)
	- [User](https://github.com/achrafelkhnissi/1337/blob/master/42curses/Born2beRoot/evaluation.md#user)
	- [Hostname and partitions](https://github.com/achrafelkhnissi/1337/blob/master/42curses/Born2beRoot/evaluation.md#hostname-and-partitions)
	- [SUDO](https://github.com/achrafelkhnissi/1337/blob/master/42curses/Born2beRoot/evaluation.md#sudo)
	- [UFW](https://github.com/achrafelkhnissi/1337/blob/master/42curses/Born2beRoot/evaluation.md#ufw)
	- [SSH](https://github.com/achrafelkhnissi/1337/blob/master/42curses/Born2beRoot/evaluation.md#ssh)
	- [Script monitoring](https://github.com/achrafelkhnissi/1337/blob/master/42curses/Born2beRoot/evaluation.md#script-monitoring)
2. [Q&A](https://github.com/achrafelkhnissi/1337/blob/master/42curses/Born2beRoot/evaluation.md#q&a)
2. [Notes](https://github.com/achrafelkhnissi/1337/blob/master/42curses/Born2beRoot/evaluation.md#notes)
2. [Resources](https://github.com/achrafelkhnissi/1337/blob/master/42curses/Born2beRoot/evaluation.md#resources)
