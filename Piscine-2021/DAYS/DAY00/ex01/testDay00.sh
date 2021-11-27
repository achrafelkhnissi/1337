#!/bin/bash

#-------------------------------------------------------------------------------
mkfile 40 testDay00 && touch -amt 202106012342 testDay00
#Create and change file timestamp to a specified timeline.
#-------------------------------------------------------------------------------
#fallocate -l 40 testShell00 # Or use dd file.
#Change file size, you can use dd file if you want, check man dd.
#-------------------------------------------------------------------------------
chmod 455 testDay00 
#Change file attributs.
#-------------------------------------------------------------------------------
tar -cf testDay00.tar testDay00
tar --extract -f testDay00.tar
#Archive the file && extract it
#-------------------------------------------------------------------------------
stat testDay00
#Display file status.
#-------------------------------------------------------------------------------
