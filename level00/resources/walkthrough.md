# level 00

## get_binary

```shell
scp -P 4242 level00@192.168.0.0:/home/users/level00/level00 level00.bin
```

## Exploit

```shell
# Dec  <--> Hex
# 5276 <--> 149C
echo 5276 > /tmp/exploit.txt
chmod 777 /tmp/exploit.txt
cat /tmp/exploit.txt - | ./level00
whoami
cat /home/users/level01/.pass
uSq2ehEGT6c9S24zbshexZQBXUGrncxn5sD5QfGL
```
