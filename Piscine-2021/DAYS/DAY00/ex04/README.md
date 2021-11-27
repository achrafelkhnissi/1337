## EXERCISE 04

* Now that you have a Kerkebos ticket, it's time to find out who you are!
* As you may already know, all users at the school are on LDAP: some sort of rudimentary digital phonebook - for those who remember what a phonebook is..
* In a file called **who_am_i.sh**, type in the command that will return only the value of the distinguished name.
* For example, with the "test" Kerberos ticket:
```
%>sh who_am_i.sh uid=test,ou=2013,ou=people,dc=42,dc=fr
%>
```

HINT: All commands to communicate with LDAP start with ... ldap.\
NOTE!: The first four lines (starting with SASL) will never be taken into account for mysterious reasons you'll understand later on.

#### Here is a Kerberos useful link:
------------------------------------------------------------------------------------------------------------------------------------------------
### [Kerberos](https://www.roguelynn.com/words/explain-like-im-5-kerberos/?fbclid=IwAR25Mf4XjM1teYggK_4XNe9keDd3LC1jKWbstLcs_ibvgZEV_gOcyrq_xtE)
------------------------------------------------------------------------------------------------------------------------------------------------
