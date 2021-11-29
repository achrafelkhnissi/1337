# 'uname -a' prints: hardware machine name & info
Architecture=$(uname -a)

# The number of physical processors
CPU_physical=$(lscpu | awk '$1 == "CPU(s):" {print $2}') #$(nproc --all)

# The number of virtual processors
vCPU=$(grep -c "^processor" /proc/cpuinfo)

# The current available RAM on the server and its utilization rate
uram=$(free -m | awk '$1 == "Mem:" {print $3}')
tram=$(free -m | awk '$1 == "Mem:" {printf("%dMB", $2)}')
pram=$(free -m | awk '$1 == "Mem:" {printf ("(%.2f%%)", ($3 * 100) / $2)}')

Memory_Usage=$(free -m | awk '$1 = "Mem:" {printf("%d/%dMB (%.2f%%)", $2, $3, ($3 * 100) / $2)}')

# The current available memory on the server and its utilization rate
Disk_Usage=$(df --total -h | awk '$1 == "total" {printf("%d/%dGb (%.2f%%)", $3 * 1024, $2, ($3 * 100) / $2)}')

# The current utilization rate of the processors
# X us - This tells us that the processor is spending X% of its time running user space processes.
# X sy - This is the amount of time the CPU spent running the kernel.
# resource : https://scoutapm.com/blog/understanding-linuxs-cpu-stats
CPU_load=$(top -bn1 | grep '^%Cpu' | awk '{printf("%.2f%%", $2 + $4)}')

# The date and time of the last reboot
Last_boot=$(who -b | awk '{print $3 " " $4}')

#Whether LVM is active or not:
check_lvm=$(lsblk | grep -c "lvm")
LVM_use=$(if [ $check_lvm -eq 0 ]; then echo no; else echo yes; fi) #-eq = equal

#Install net tools for the next step (sudo apt install net-tools)
# The number of active connections
Connexions_TCP=$(cat /proc/net/sockstat | awk '$1 == "TCP:" {print $3}')

# The number of users using the server
User_log=$(users | wc -w)

# The IPv4 address of the server and its MAC address
ip=$(hostname -I)
mac=$(ip link | awk '$1 == "link/ether" {print $2}')

# The number of commands executed with the sudo program.
Sudo=$(grep "COMMAND" /var/log/sudo.log | wc -l)

wall "
	#Architecture	: $Architecture
	#CPU physical	: $CPU_physical
	#vCPU		: $vCPU
	#Memory Usage	: $uram/$tram $pram
	#Disk Usage	: $Disk_Usage
	#CPU load	: $CPU_load
	#Last boot	: $Last_boot
	#LVM use	: $LVM_use
	#Connexions TCP	: $Connexions_TCP ESTABLISHED
	#User log	: $User_log
	#Network	: IP $ip ($mac)
	#Sudo		: $Sudo cmd
"
