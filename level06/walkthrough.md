# level 06

## get_binary

```shell
scp -P 4242 level06@192.168.0.0:/home/users/level06/level06 level06.bin
```

## Exploit

```shell
# 80487b5:       e8 36 fe ff ff          call   80485f0 <ptrace@plt>
# 80487ba:       83 f8 ff                cmp    eax,0xffffffff
(gdb) break *0x80487ba
# 8048866:       3b 45 f0                cmp    eax,DWORD PTR [ebp-0x10]
(gdb) break *0x8048866
(gdb) run
Starting program: /home/users/level06/level06 
***********************************
*               level06           *
***********************************
-> Enter Login: chervy
***********************************
***** NEW ACCOUNT DETECTED ********
***********************************
-> Enter Serial: ...

Breakpoint 1, 0x080487ba in auth ()
(gdb) set $eax=0
(gdb) step
Single stepping until exit from function auth,
which has no line number information.

Breakpoint 2, 0x08048866 in auth ()
(gdb) info registers
eax            0x1      1
ecx            0x5f1662 6231650
edx            0x4ce    1230
ebx            0xf7fceff4       -134418444
esp            0xffffd680       0xffffd680
ebp            0xffffd6a8       0xffffd6a8
esi            0x0      0
edi            0x0      0
eip            0x8048866        0x8048866 <auth+286>
eflags         0x246    [ PF ZF IF ]
cs             0x23     35
ss             0x2b     43
ds             0x2b     43
es             0x2b     43
fs             0x0      0
gs             0x63     99
(gdb) x/d $ebp-0x10
0xffffd698:     6232809
```

```shell
level06@OverRide:~$ ./level06 
***********************************
*               level06           *
***********************************
-> Enter Login: chervy
***********************************
***** NEW ACCOUNT DETECTED ********
***********************************
-> Enter Serial: 6232809
Authenticated!
$ whoami
level07
$ pwd
/home/users/level06
$ cat /home/users/level07/.pass
GbcPDRgsFK77LNnnuh7QyFYA2942Gp8yKj9KrWD8
```