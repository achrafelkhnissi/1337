## Git commit
- Objective: Write a shell script that returns the last 5 hashes in your git #deposit.
- Used files: git, cat.

## Solution:
- Git is very usefull tool, check a tutorial.
```sh
git log -5 --format='%H' | cat -e
```
