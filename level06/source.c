hex-rays:
_BOOL4 __cdecl auth(char *s, int a2)
{
  int i; // [esp+14h] [ebp-14h]
  int v4; // [esp+18h] [ebp-10h]
  int v5; // [esp+1Ch] [ebp-Ch]

  s[strcspn(s, "\n")] = 0; // faille
  v5 = strnlen(s, 32);
  if ( v5 <= 5 )
    return 1;
  if ( ptrace(PTRACE_TRACEME, 0, 1, 0) == -1 )
  {
    puts("\x1B[32m.---------------------------.");
    puts("\x1B[31m| !! TAMPERING DETECTED !!  |");
    puts("\x1B[32m'---------------------------'");
    return 1;
  }
  else
  {
    v4 = (s[3] ^ 0x1337) + 6221293;
    for ( i = 0; i < v5; ++i )
    {
      if ( s[i] <= 31 )
        return 1;
      v4 += (v4 ^ (unsigned int)s[i]) % 0x539;
    }
    return a2 != v4;
  }
}
// 80485D0: using guessed type int __cdecl strnlen(_DWORD, _DWORD);

//----- (08048879) --------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  int v4; // [esp+2Ch] [ebp-24h] BYREF
  char s[28]; // [esp+30h] [ebp-20h] BYREF
  unsigned int v6; // [esp+4Ch] [ebp-4h]

  v6 = __readgsdword(0x14u);
  puts("***********************************");
  puts("*\t\tlevel06\t\t  *");
  puts("***********************************");
  printf("-> Enter Login: ");
  fgets(s, 32, stdin);
  puts("***********************************");
  puts("***** NEW ACCOUNT DETECTED ********");
  puts("***********************************");
  printf("-> Enter Serial: ");
  __isoc99_scanf(&unk_8048A60, &v4);
  if ( auth(s, v4) )
    return 1;
  puts("Authenticated!");
  system("/bin/sh");
  return 0;
}

ghidra:
undefined4 auth(char *username,uint pass)
{
  size_t sVar1;
  undefined4 uVar2;
  long lVar3;
  int i;
  uint local_14;
  
  sVar1 = strcspn(username,"\n");
  username[sVar1] = '\0';
  sVar1 = strnlen(username,0x20);
  if ((int)sVar1 < 6) {
    uVar2 = 1;
  }
  else {
    lVar3 = ptrace(PTRACE_TRACEME);
    if (lVar3 == -1) {
      puts("\x1b[32m.---------------------------.");
      puts("\x1b[31m| !! TAMPERING DETECTED !!  |");
      puts("\x1b[32m\'---------------------------\'");
      uVar2 = 1;
    }
    else {
      local_14 = (username[3] ^ 0x1337) + 0x5eeded;
      for ( i = 0; i < (int)sVar1; i++ ) {
        if (username[i] < ' ') {
          return 1;
        }
        local_14 = local_14 + (username[i] ^ local_14) % 0x539;
      }
      if (pass == local_14) {
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}



// WARNING: Removing unreachable block (ram,0x0804889a)
// WARNING: Restarted to delay deadcode elimination for space: stack

bool main(void)
{
  int iVar1;
  int in_GS_OFFSET;
  char local_34 [32];
  int local_14;
  
  local_14 = *(int *)(in_GS_OFFSET + 0x14);
  puts("***********************************");
  puts("*\t\tlevel06\t\t  *");
  puts("***********************************");
  printf("-> Enter Login: ");
  fgets(local_34,0x20,stdin);
  puts("***********************************");
  puts("***** NEW ACCOUNT DETECTED ********");
  puts("***********************************");
  printf("-> Enter Serial: ");
  __isoc99_scanf();
  iVar1 = auth();
  if (iVar1 == 0) {
    puts("Authenticated!");
    system("/bin/sh");
  }
  if (local_14 != *(int *)(in_GS_OFFSET + 0x14)) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return iVar1 != 0;
}