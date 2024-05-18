# level 03

## get_binary

```shell
scp -P 4242 level03@192.168.0.0:/home/users/level03/level03 level03.bin
```

## Exploit

```shell
# result = decrypt(a2 - a1);
# a1 = 322424845
# a2 = password;
# "Q}|u`sfg~sf{}|a3" -> "Congratulations!"

Q = 01010001
C = 01000011

01010001 XOR X = 01000011

X = 00010010 = 18

322424845 - 18 = 322424827
```

```shell
level03@OverRide:~$ ./level03 
***********************************
*               level03         **
***********************************
Password:322424827
$ whoami
level04
$ cat /home/users/level04/.pass
kgv3tkEb9h2mLkRsPkXRfc2mHbjMxQzvb2FrgKkf
```