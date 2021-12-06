# 'uname -a' prints: hardware machine name & info
# uname -- Print operating system name
Architecture=$(uname -a)

# The number of physical processors
# lscpu - display information about the CPU architecture
CPU_physical=$(lscpu | awk '$1 == "CPU(s):" {print $2}') #$(nproc --all)

# The number of virtual processors
# -c:  Only a count of selected lines is written to standard output.
vCPU=$(grep -c "^processor" /proc/cpuinfo)

# The current available RAM on the server and its utilization rate
# rule of 3: https://www.smartick.com/blog/math/rule-of-3/
# free - Display amount of free and used memory in the system
# -m: Display the amount of memory in mebibytes.
uram=$(free -m | awk '$1 == "Mem:" {print $3}')
tram=$(free -m | awk '$1 == "Mem:" {printf("%dMB", $2)}')
pram=$(free -m | awk '$1 == "Mem:" {printf ("(%.2f%%)", ($3 * 100) / $2)}')

Memory_Usage=$(free -m | awk '$1 = "Mem:" {printf("%d/%dMB (%.2f%%)", $2, $3, ($3 * 100) / $2)}')

# The current available memory on the server and its utilization rate
# df -- display free disk space
# -h: "Human-readable" output.
# --total: elide all entries insignificant to available space, and produce a grand total
Disk_Usage=$(df --total -h | awk '$1 == "total" {printf("%d/%dGb (%.2f%%)", $3 * 1024, $2, ($3 * 100) / $2)}')

# The current utilization rate of the processors
# X us - This tells us that the processor is spending X% of its time running user space processes.
# X sy - This is the amount of time the CPU spent running the kernel.
# resource : https://scoutapm.com/blog/understanding-linuxs-cpu-stats
# -b :Batch-mode operation
#     Starts top in Batch mode, which could be useful for sending output from top to other programs or to a file.  In this mode, top will not accept input  and  runs
#     until the iterations limit you've set with the `-n' command-line option or until killed.
# -n  :Number-of-iterations limit as:  -n number
#	Specifies the maximum number of iterations, or frames, top should produce before ending.
CPU_load=$(top -bn1 | grep '^%Cpu' | awk '{printf("%.2f%%", $2 + $4)}')

# The date and time of the last reboot
#  -b    Time of last system boot.
Last_boot=$(who -b | awk '{print $3 " " $4}')

# Whether LVM is active or not:
# lsblk - list block devices
check_lvm=$(lsblk | grep -c "lvm")
LVM_use=$(if [ $check_lvm -eq 0 ]; then echo no; else echo yes; fi) #-eq = equal

# The number of active connections
Connexions_TCP=$(cat /proc/net/sockstat | awk '$1 == "TCP:" {print $3}')

# The number of users using the server
#  users - print the user names of users currently logged in to the current host
User_log=$(users | wc -w)

# The IPv4 address of the server and its MAC address
ip=$(hostname -I)
# ip - show / manipulate routing, network devices, interfaces and tunnels
# link   - network device.
mac=$(ip link | awk '$1 == "link/ether" {print $2}')

# The number of commands executed with the sudo program.
Sudo=$(grep "COMMAND" /var/log/sudo/sudo.log | wc -l)

# wall - write a message to all users
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
