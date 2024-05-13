undefined4 main(void)
{
  int iVar1;
  undefined4 *puVar2;
  byte bVar3;
  uint local_a4;
  undefined4 local_a0 [32];
  long local_18;
  __pid_t local_14;
  
  bVar3 = 0;
  local_14 = fork();
  puVar2 = local_a0;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + (uint)bVar3 * -2 + 1;
  } // bzero
  local_18 = 0;
  local_a4 = 0;
  if (local_14 == 0) {
    prctl(1,1);
    ptrace(PTRACE_TRACEME,0,0,0);
    puts("Give me some shellcode, k");
    gets((char *)local_a0);
  }
  else {
    do {
      wait(&local_a4);
      if (((local_a4 & 0x7f) == 0) || (((local_a4 & 0x7f) + 1) >> 1) > 0) { // WIFEXITED(status)
        puts("child is exiting...");
        return 0;
      }
      local_18 = ptrace(PTRACE_PEEKUSER,local_14,0x2c,0);
    } while (local_18 != 0xb);
    puts("no exec() for you");
    kill(local_14,9);
  }
  return 0;
}