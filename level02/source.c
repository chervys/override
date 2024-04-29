#include "out.h"

int _init(EVP_PKEY_CTX* ctx)
{
    int iVar1;

    call_gmon_start();
    frame_dummy();
    iVar1 = __do_global_ctors_aux();
    return iVar1;
}

void FUN_00400660(void)
{
    // WARNING: Treating indirect jump as call
    (*(code*)(undefined*)0x0)();
    return;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked
int strncmp(char* __s1, char* __s2, size_t __n)
{
    int iVar1;

    iVar1 = strncmp(__s1, __s2, __n);
    return iVar1;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked
int puts(char* __s)
{
    int iVar1;

    iVar1 = puts(__s);
    return iVar1;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked
size_t fread(void* __ptr, size_t __size, size_t __n, FILE* __stream)
{
    size_t sVar1;

    sVar1 = fread(__ptr, __size, __n, __stream);
    return sVar1;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked
int fclose(FILE* __stream)
{
    int iVar1;

    iVar1 = fclose(__stream);
    return iVar1;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked
int system(char* __command)
{
    int iVar1;

    iVar1 = system(__command);
    return iVar1;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked
int printf(char* __format, ...)
{
    int iVar1;

    iVar1 = printf(__format);
    return iVar1;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked
size_t strcspn(char* __s, char* __reject)
{
    size_t sVar1;

    sVar1 = strcspn(__s, __reject);
    return sVar1;
}

void __libc_start_main(void)
{
    __libc_start_main();
    return;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked

char* fgets(char* __s, int __n, FILE* __stream)
{
    char* pcVar1;

    pcVar1 = fgets(__s, __n, __stream);
    return pcVar1;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked

FILE* fopen(char* __filename, char* __modes)
{
    FILE* pFVar1;

    pFVar1 = fopen(__filename, __modes);
    return pFVar1;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked

void exit(int __status)
{
    // WARNING: Subroutine does not return
    exit(__status);
}

// WARNING: Unknown calling convention -- yet parameter storage is locked
size_t fwrite(void* __ptr, size_t __size, size_t __n, FILE* __s)
{
    size_t sVar1;

    sVar1 = fwrite(__ptr, __size, __n, __s);
    return sVar1;
}

void processEntry _start(undefined8 param_1, undefined8 param_2)
{
    undefined auStack_8[8];

    __libc_start_main(main, param_2, &stack0x00000008, __libc_csu_init, __libc_csu_fini, param_1, auStack_8);
    do {
        // WARNING: Do nothing block with infinite loop
    } while (true);
}

void call_gmon_start(void)
{
    __gmon_start__();
    return;
}

// WARNING: Removing unreachable block (ram,0x004007b2)
// WARNING: Removing unreachable block (ram,0x004007b8)
void __do_global_dtors_aux(void)
{
    if (completed_6531 == '\0') {
        completed_6531 = '\x01';
    }
    return;
}

// WARNING: Removing unreachable block (ram,0x00400808)
// WARNING: Globals starting with '_' overlap smaller symbols at the same address
void frame_dummy(void)
{
    return;
}

undefined8 main(void)
{
    int iVar1;
    size_t sVar2;
    long lVar3;
    undefined8* puVar4;
    undefined8 local_118[14];
    undefined8 local_a8[6];
    undefined8 local_78[12];
    int local_14;
    FILE* local_10;

    puVar4 = local_78;
    for (lVar3 = 0xc; lVar3 != 0; lVar3 = lVar3 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
    }
    *(undefined4*)puVar4 = 0;
    puVar4 = local_a8;
    for (lVar3 = 5; lVar3 != 0; lVar3 = lVar3 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
    }
    *(undefined*)puVar4 = 0;
    puVar4 = local_118;
    for (lVar3 = 0xc; lVar3 != 0; lVar3 = lVar3 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
    }
    *(undefined4*)puVar4 = 0;
    local_10 = (FILE*)0x0;
    local_14 = 0;
    local_10 = fopen("/home/users/level03/.pass", "r");
    if (local_10 == (FILE*)0x0) {
        fwrite("ERROR: failed to open password file\n", 1, 0x24, stderr);
        // WARNING: Subroutine does not return
        exit(1);
    }
    sVar2 = fread(local_a8, 1, 0x29, local_10);
    local_14 = (int)sVar2;
    sVar2 = strcspn((char*)local_a8, "\n");
    *(undefined*)((long)local_a8 + sVar2) = 0;
    if (local_14 != 0x29) {
        fwrite("ERROR: failed to read password file\n", 1, 0x24, stderr);
        fwrite("ERROR: failed to read password file\n", 1, 0x24, stderr);
        // WARNING: Subroutine does not return
        exit(1);
    }
    fclose(local_10);
    puts("===== [ Secure Access System v1.0 ] =====");
    puts("/***************************************\\");
    puts("| You must login to access this system. |");
    puts("\\**************************************/");
    printf("--[ Username: ");
    fgets((char*)local_78, 100, stdin);
    sVar2 = strcspn((char*)local_78, "\n");
    *(undefined*)((long)local_78 + sVar2) = 0;
    printf("--[ Password: ");
    fgets((char*)local_118, 100, stdin);
    sVar2 = strcspn((char*)local_118, "\n");
    *(undefined*)((long)local_118 + sVar2) = 0;
    puts("*****************************************");
    iVar1 = strncmp((char*)local_a8, (char*)local_118, 0x29);
    if (iVar1 == 0) {
        printf("Greetings, %s!\n", local_78);
        system("/bin/sh");
        return 0;
    }
    printf((char*)local_78);
    puts(" does not have access!");
    // WARNING: Subroutine does not return
    exit(1);
}

// WARNING: Removing unreachable block (ram,0x00400b0a)
// WARNING: Removing unreachable block (ram,0x00400b10)
void __libc_csu_init(EVP_PKEY_CTX* param_1)
{
    _init(param_1);
    return;
}

void __libc_csu_fini(void)
{
    return;
}

void __do_global_ctors_aux(void)
{
    code* pcVar1;
    code** ppcVar2;

    if (__CTOR_LIST__ != (code*)0xffffffffffffffff) {
        ppcVar2 = &__CTOR_LIST__;
        pcVar1 = __CTOR_LIST__;
        do {
            ppcVar2 = ppcVar2 + -1;
            (*pcVar1)();
            pcVar1 = *ppcVar2;
        } while (pcVar1 != (code*)0xffffffffffffffff);
    }
    return;
}

void _fini(void)
{
    __do_global_dtors_aux();
    return;
}
