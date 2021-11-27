## EXERCISE 06

* Now that you're LDAP expert, you are going to be able to add your phone number into the mobile field.
* Here's and LDIF file template:
```
dn: uid=pnom,ou=people,dc=42,dc=fr
changetype: modify
delete: pouette
```
* To check if your command has worked, try to look yourself up on LDAP!

HINTS:
1. Add your real number: your future teammates will be happy to know how to reach you!.
2. Don't hesitate to fill in other fields if you're up for it. However, you donÄt have all the permissions, we're not idiots ;)
3. You can change your address any time, via the 'email-address' field.

