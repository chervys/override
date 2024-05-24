ghidra:
void clear_stdin(void)
{
  int iVar1;
  
  do {
    iVar1 = getchar();
    if ((char)iVar1 == '\n') {
      return;
    }
  } while ((char)iVar1 != -1);
  return;
}

undefined4 get_unum(void)
{
  undefined4 local_10 [3];
  
  local_10[0] = 0;
  fflush(stdout);
  __isoc99_scanf(&DAT_08048ad0,local_10);
  clear_stdin();
  return local_10[0];
}

void prog_timeout(void)
{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x80);
  (*pcVar1)();
  return;
}

undefined4 store_number(int param_1)
{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  printf(" Number: ");
  uVar1 = get_unum();
  printf(" Index: ");
  uVar2 = get_unum();
  if ((uVar2 % 3 == 0) || (uVar1 >> 0x18 == 0xb7)) {
    puts(" *** ERROR! ***");
    puts("   This index is reserved for wil!");
    puts(" *** ERROR! ***");
    uVar3 = 1;
  }
  else {
    *(uint *)(uVar2 * 4 + param_1) = uVar1;
    uVar3 = 0;
  }
  return uVar3;
}

undefined4 read_number(int param_1)
{
  int iVar1;
  
  printf(" Index: ");
  iVar1 = get_unum();
  printf(" Number at data[%u] is %u\n",iVar1,*(undefined4 *)(iVar1 * 4 + param_1));
  return 0;
}

undefined4 main(undefined4 param_1,char **param_2,char **param_3)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  char *pcVar5;
  byte *pbVar6;
  int in_GS_OFFSET;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  byte bVar10;
  char **local_1c8;
  char **local_1c4;
  undefined4 local_1bc [100];
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  
  bVar10 = 0;
  local_1c4 = param_2;
  local_1c8 = param_3;
  local_14 = *(int *)(in_GS_OFFSET + 0x14);
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  puVar4 = local_1bc;
  for (iVar2 = 100; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  for (; *local_1c4 != (char *)0x0; local_1c4 = local_1c4 + 1) {
    uVar3 = 0xffffffff;
    pcVar5 = *local_1c4;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + (uint)bVar10 * -2 + 1;
    } while (cVar1 != '\0');
    memset(*local_1c4,0,~uVar3 - 1);
  }
  for (; *local_1c8 != (char *)0x0; local_1c8 = local_1c8 + 1) {
    uVar3 = 0xffffffff;
    pcVar5 = *local_1c8;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + (uint)bVar10 * -2 + 1;
    } while (cVar1 != '\0');
    memset(*local_1c8,0,~uVar3 - 1);
  }
  puts(
      "----------------------------------------------------\n  Welcome to wil\'s crappy number storage service!   \n----------------------------------------------------\n Commands:                                          \n    store - store a number into the data storage    \n    read  - read a number from the data storage     \n    quit  - exit the program                        \n----------------------------------------------------\n   wil has reserved some storage :>                 \n----------------------------------------------------\n"
      );
  do {
    printf("Input command: ");
    local_2c = 1;
    fgets((char *)&local_28,0x14,stdin);
    uVar3 = 0xffffffff;
    puVar4 = &local_28;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *(char *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + (uint)bVar10 * -2 + 1);
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    bVar7 = uVar3 == 1;
    bVar9 = uVar3 == 2;
    *(undefined *)((int)&local_2c + uVar3 + 2) = 0;
    iVar2 = 5;
    puVar4 = &local_28;
    pbVar6 = (byte *)"store";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar7 = *(byte *)puVar4 < *pbVar6;
      bVar9 = *(byte *)puVar4 == *pbVar6;
      puVar4 = (undefined4 *)((int)puVar4 + (uint)bVar10 * -2 + 1);
      pbVar6 = pbVar6 + (uint)bVar10 * -2 + 1;
    } while (bVar9);
    bVar8 = false;
    bVar7 = (!bVar7 && !bVar9) == bVar7;
    if (bVar7) {
      local_2c = store_number(local_1bc);
    }
    else {
      iVar2 = 4;
      puVar4 = &local_28;
      pbVar6 = &DAT_08048d61;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar8 = *(byte *)puVar4 < *pbVar6;
        bVar7 = *(byte *)puVar4 == *pbVar6;
        puVar4 = (undefined4 *)((int)puVar4 + (uint)bVar10 * -2 + 1);
        pbVar6 = pbVar6 + (uint)bVar10 * -2 + 1;
      } while (bVar7);
      bVar9 = false;
      bVar7 = (!bVar8 && !bVar7) == bVar8;
      if (bVar7) {
        local_2c = read_number(local_1bc);
      }
      else {
        iVar2 = 4;
        puVar4 = &local_28;
        pbVar6 = &DAT_08048d66;
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar9 = *(byte *)puVar4 < *pbVar6;
          bVar7 = *(byte *)puVar4 == *pbVar6;
          puVar4 = (undefined4 *)((int)puVar4 + (uint)bVar10 * -2 + 1);
          pbVar6 = pbVar6 + (uint)bVar10 * -2 + 1;
        } while (bVar7);
        if ((!bVar9 && !bVar7) == bVar9) {
          if (local_14 == *(int *)(in_GS_OFFSET + 0x14)) {
            return 0;
          }
                    // WARNING: Subroutine does not return
          __stack_chk_fail();
        }
      }
    }
    if (local_2c == 0) {
      printf(" Completed %s command successfully\n",&local_28);
    }
    else {
      printf(" Failed to do %s command\n",&local_28);
    }
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
  } while( true );
}

hex-rays:
//----- (080485C4) --------------------------------------------------------
int clear_stdin()
{
  int result; // eax

  do
    result = getchar();
  while ( (_BYTE)result != 10 && (_BYTE)result != 0xFF );
  return result;
}

//----- (080485E7) --------------------------------------------------------
int get_unum()
{
  int v1[3]; // [esp+1Ch] [ebp-Ch] BYREF

  v1[0] = 0;
  fflush(stdout);
  __isoc99_scanf(&unk_8048AD0, v1);
  clear_stdin();
  return v1[0];
}
// 8048500: using guessed type int __cdecl __isoc99_scanf(_DWORD, _DWORD);
// 80485E7: using guessed type int var_C[3];

//----- (0804861F) --------------------------------------------------------
void __noreturn prog_timeout()
{
  int v0; // eax

  v0 = sys_exit(1);
}
// 804861F: using guessed type void __noreturn prog_timeout();

//----- (08048630) --------------------------------------------------------
int __cdecl store_number(int a1)
{
  unsigned int unum; // [esp+18h] [ebp-10h]
  unsigned int index; // [esp+1Ch] [ebp-Ch]

  printf(" Number: ");
  unum = get_unum();
  printf(" Index: ");
  index = get_unum();
  if ( index == 3 * (index / 3) || HIBYTE(unum) == 0xb7 )
  {
    puts(" *** ERROR! ***");
    puts("   This index is reserved for wil!");
    puts(" *** ERROR! ***");
    return 1;
  }
  else
  {
    *(_DWORD *)(a1 + 4 * index) = unum;
    return 0;
  }
}

//----- (080486D7) --------------------------------------------------------
int __cdecl read_number(int a1)
{
  int unum; // [esp+1Ch] [ebp-Ch]

  printf(" Index: ");
  unum = get_unum();
  printf(" Number at data[%u] is %u\n", unum, *(_DWORD *)(a1 + 4 * unum));
  return 0;
}

//----- (08048723) --------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  _BYTE v6[400]; // [esp+24h] [ebp-1B8h] BYREF
  int number; // [esp+1B4h] [ebp-28h]
  char s[4]; // [esp+1B8h] [ebp-24h] BYREF
  int v9; // [esp+1BCh] [ebp-20h]
  int v10; // [esp+1C0h] [ebp-1Ch]
  int v11; // [esp+1C4h] [ebp-18h]
  int v12; // [esp+1C8h] [ebp-14h]
  unsigned int v13; // [esp+1CCh] [ebp-10h]

  v13 = __readgsdword(0x14u);
  number = 0;
  *(_DWORD *)s = 0;
  v9 = 0;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  memset(v6, 0, sizeof(v6));
  while ( *argv )
  {
    memset((void *)*argv, 0, strlen(*argv));
    ++argv;
  }
  while ( *envp )
  {
    memset((void *)*envp, 0, strlen(*envp));
    ++envp;
  }
  puts(
    "----------------------------------------------------\n"
    "  Welcome to wil's crappy number storage service!   \n"
    "----------------------------------------------------\n"
    " Commands:                                          \n"
    "    store - store a number into the data storage    \n"
    "    read  - read a number from the data storage     \n"
    "    quit  - exit the program                        \n"
    "----------------------------------------------------\n"
    "   wil has reserved some storage :>                 \n"
    "----------------------------------------------------\n");
  while ( 1 )
  {
    printf("Input command: ");
    number = 1;
    fgets(s, 20, stdin);
    s[strlen(s) - 1] = 0;
    if ( !memcmp(s, "store", 5u) )
    {
      number = store_number((int)v6);
      goto LABEL_13;
    }
    if ( !memcmp(s, "read", 4u) )
    {
      number = read_number((int)v6);
      goto LABEL_13;
    }
    if ( !memcmp(s, "quit", 4u) )
      return 0;
LABEL_13:
    if ( number )
      printf(" Failed to do %s command\n", s);
    else
      printf(" Completed %s command successfully\n", s);
    *(_DWORD *)s = 0;
    v9 = 0;
    v10 = 0;
    v11 = 0;
    v12 = 0;
  }
}