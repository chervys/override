# level 02

## get_binary

```shell
scp -P 4242 level02@192.168.0.0:/home/users/level02/level02 level02.bin
```

## fake_password

```shell
python2.7 -c 'print("B" * 42);' > /tmp/.pass
chmod 777 /tmp/.pass
gdb level02
#  4008a2:       48 89 d6                mov    rsi,rdx
#  4008a5:       48 89 c7                mov    rdi,rax
#  4008a8:       e8 53 fe ff ff          call   400700 <fopen@plt>
(gdb) break *0x4008a8
(gdb) run
(gdb) info register
rax            0x400bb2 4197298
rdx            0x400bb0 4197296
(gdb) x/s 0x400bb2
0x400bb2:        "/home/users/level03/.pass"
(gdb) x/s 0x400bb0
0x400bb0:        "r"
set (char[11])*0x400bb2="/tmp/.pass"
(gdb) x/s 0x400bb2
0x400bb2:        "/tmp/.pass"
(gdb) step
Single stepping until exit from function main,
which has no line number information.
===== [ Secure Access System v1.0 ] =====
/***************************************\
| You must login to access this system. |
\**************************************/
--[ Username: BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
--[ Password: BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
*****************************************
Greetings, BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB!
$ whoami
level02
```

## exploit