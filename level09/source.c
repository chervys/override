ghidra:
void secret_backdoor(void)
{
  char local_88 [128];
  
  fgets(local_88,0x80,_stdin);
  system(local_88);
  return;
}

void handle_msg(void)
{
  undefined local_c8 [140];
  undefined8 local_3c;
  undefined8 local_34;
  undefined8 local_2c;
  undefined8 local_24;
  undefined8 local_1c;
  undefined4 local_14;
  
  local_3c = 0;
  local_34 = 0;
  local_2c = 0;
  local_24 = 0;
  local_1c = 0;
  local_14 = 0x8c;
  set_username(local_c8);
  set_msg(local_c8);
  puts(">: Msg sent!");
  return;
}

void set_msg(char *param_1)
{
  long lVar1;
  undefined8 *puVar2;
  undefined8 local_408 [128];
  
  puVar2 = local_408;
  for (lVar1 = 0x80; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puts(">: Msg @Unix-Dude");
  printf(">>: ");
  fgets((char *)local_408,0x400,_stdin);
  strncpy(param_1,(char *)local_408, 140);
//   strncpy(param_1,(char *)local_408,(long)*(int *)(param_1 + 0xb4));
  return;
}

void set_username(long param_1)
{
  long lVar1;
  undefined8 *puVar2;
  undefined8 local_98 [17];
  int local_c;
  
  puVar2 = local_98;
  for (lVar1 = 0x10; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puts(">: Enter your username");
  printf(">>: ");
  fgets((char *)local_98,0x80,_stdin);
  for (local_c = 0; (local_c < 0x29 && (*(char *)((long)local_98 + (long)local_c) != '\0'));
      local_c = local_c + 1) {
    *(undefined *)(param_1 + 0x8c + (long)local_c) = *(undefined *)((long)local_98 + (long)local_c);
  }
  printf(">: Welcome, %s",param_1 + 0x8c);
  return;
}

undefined8 main(void)
{
  puts(
      "--------------------------------------------\n|   ~Welcome to l33t-m$n ~    v1337        |\n--------------------------------------------"
      );
  handle_msg();
  return 0;
}

hex-rays:
int secret_backdoor()
{
  char s[128]; // [rsp+0h] [rbp-80h] BYREF

  fgets(s, 128, stdin);
  return system(s);
}

//----- (00000000000008C0) ----------------------------------------------------
int handle_msg()
{
  char v1[140]; // [rsp+0h] [rbp-C0h] BYREF
  __int64 v2; // [rsp+8Ch] [rbp-34h]
  __int64 v3; // [rsp+94h] [rbp-2Ch]
  __int64 v4; // [rsp+9Ch] [rbp-24h]
  __int64 v5; // [rsp+A4h] [rbp-1Ch]
  __int64 v6; // [rsp+ACh] [rbp-14h]
  int v7; // [rsp+B4h] [rbp-Ch]

  v2 = 0LL;
  v3 = 0LL;
  v4 = 0LL;
  v5 = 0LL;
  v6 = 0LL;
  v7 = 140;
  set_username((__int64)v1);
  set_msg((__int64)v1);
  return puts(">: Msg sent!");
}

//----- (0000000000000932) ----------------------------------------------------
char *__fastcall set_msg(__int64 a1)
{
  char s[1024]; // [rsp+10h] [rbp-400h] BYREF

  memset(s, 0, sizeof(s));
  puts(">: Msg @Unix-Dude");
  printf(">>: ");
  fgets(s, 1024, stdin);
  return strncpy((char *)a1, s, 140 ??);
//   return strncpy((char *)a1, s, *(int *)(a1 + 180));
}

//----- (00000000000009CD) ----------------------------------------------------
int __fastcall set_username(__int64 dest)
{
  char s[140]; // [rsp+10h] [rbp-90h] BYREF
  int i; // [rsp+9Ch] [rbp-4h]

  memset(s, 0, 0x80uLL);
  puts(">: Enter your username");
  printf(">>: ");
  fgets(s, 128, stdin);
  for ( i = 0; i <= 40 && s[i]; ++i )
    dest[i + 140] = s[i];
  return printf(">: Welcome, %s", a1 + 140);
}
// 9CD: using guessed type char s[140];

//----- (0000000000000AA8) ----------------------------------------------------
int __fastcall main(int argc, const char **argv, const char **envp)
{
  puts(
    "--------------------------------------------\n"
    "|   ~Welcome to l33t-m$n ~    v1337        |\n"
    "--------------------------------------------");
  handle_msg();
  return 0;
}