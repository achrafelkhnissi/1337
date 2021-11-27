cat /etc/passwd | sed -e 's/#.*//' -e 's/[ ^I]*$//' -e '/^$/ d' -e 's/:.*//g' \
 | tr '\n' ',' | rev | tr "," "\n" | sort -r | tr "\n" ","  \
 | sed -e 's/, */, /g' -e 's/.$//' -e 's/.\{3\}$//'

# cat -e /etc/passwd | grep -v '^#' | awk 'NR % 2 == 0' | awk -F : '{ print $1 }' | rev | tail -r | awk -v ln1=$FT_LINE1 -v ln2=$FT_LINE2 'NR >= ln1 && NR <= ln2' | awk '{ printf $0", " }' | sed 's/.\{2\}$/./'
