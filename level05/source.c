ghidra:
void main(void)
{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  byte bVar4;
  byte local_78 [100];
  uint local_14;
  
  bVar4 = 0;
  local_14 = 0;
  fgets((char *)local_78,100,stdin);
  local_14 = 0;
  do {
    uVar2 = 0xffffffff;
    pbVar3 = local_78;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      bVar1 = *pbVar3;
      pbVar3 = pbVar3 + (uint)bVar4 * -2 + 1;
    } while (bVar1 != 0); // strlen ?
    if (~uVar2 - 1 <= local_14) {
      printf((char *)local_78);
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
    if (('@' < (char)local_78[local_14]) && ((char)local_78[local_14] < '[')) {
      local_78[local_14] = local_78[local_14] ^ 0x20;
    }
    local_14 = local_14 + 1;
  } while( true );
}

hex-rays:
int __cdecl __noreturn main(int argc, const char **argv, const char **envp)
{
  char s[100]; // [esp+28h] [ebp-70h] BYREF
  unsigned int i; // [esp+8Ch] [ebp-Ch]

  i = 0;
  fgets(s, 100, stdin);
  for ( i = 0; i < strlen(s); ++i )
  {
    if ( s[i] > 64 && s[i] <= 90 )
      s[i] ^= 0x20u;
  }
  printf(s);
  exit(0);
}