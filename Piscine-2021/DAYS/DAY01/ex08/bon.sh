ldapsearch -xLLL "sn=*bon*" sn | grep sn | wc -l | sed 's/     //'
