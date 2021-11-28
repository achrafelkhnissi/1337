cat /etc/passwd | grep -v "#" | awk "NR%2==0" | awk -F: '{print $1}' | rev | sort -r | sed -n "$FT_LINE1,$FT_LINE2 p" | tr '\n' ',' | sed 's/,/, /g' | sed 's/, $/./' | xargs -I{} echo -n {}
