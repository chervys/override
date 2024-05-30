#include "out.h"

int _init(EVP_PKEY_CTX* ctx)
{
    int iVar1;

    __gmon_start__();
    frame_dummy();
    iVar1 = __do_global_ctors_aux();
    return iVar1;
}

void FUN_08048370(void)
{
    // WARNING: Treating indirect jump as call
    (*(code*)(undefined*)0x0)();
    return;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked
int printf(char* __format, ...)
{
    int iVar1;

    iVar1 = printf(__format);
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
int system(char* __command)
{
    int iVar1;

    iVar1 = system(__command);
    return iVar1;
}

void __gmon_start__(void)
{
    __gmon_start__();
    return;
}

void __libc_start_main(void)
{
    __libc_start_main();
    return;
}

void __isoc99_scanf(void)
{
    __isoc99_scanf();
    return;
}

void processEntry _start(undefined4 param_1, undefined4 param_2)
{
    undefined auStack_4[4];

    __libc_start_main(main, param_2, &stack0x00000004, __libc_csu_init, __libc_csu_fini, param_1, auStack_4);
    do {
        // WARNING: Do nothing block with infinite loop
    } while (true);
}

// WARNING: Removing unreachable block (ram,0x0804843a)
// WARNING: Removing unreachable block (ram,0x08048440)
void __do_global_dtors_aux(void)
{
    if (completed_6159 == '\0') {
        completed_6159 = '\x01';
    }
    return;
}

// WARNING: Removing unreachable block (ram,0x0804847f)
// WARNING: Removing unreachable block (ram,0x08048488)
void frame_dummy(void)
{
    return;
}

bool main(void)
{
    int local_14[4];

    puts("***********************************");
    puts("* \t     -Level00 -\t\t  *");
    puts("***********************************");
    printf("Password:");
    __isoc99_scanf(&DAT_08048636, local_14);
    if (local_14[0] != 0x149c) {
        puts("\nInvalid Password!");
    } else {
        puts("\nAuthenticated!");
        system("/bin/sh");
    }
    return local_14[0] != 0x149c;
}

// WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx
// WARNING: Removing unreachable block (ram,0x08048550)
// WARNING: Removing unreachable block (ram,0x08048558)
void __libc_csu_init(void)
{
    EVP_PKEY_CTX* in_stack_ffffffd4;

    _init(in_stack_ffffffd4);
    return;
}

void __libc_csu_fini(void)
{
    return;
}

// WARNING: This is an inlined function
void __i686_get_pc_thunk_bx(void)
{
    return;
}

// WARNING: Removing unreachable block (ram,0x080485b1)
// WARNING: Removing unreachable block (ram,0x080485b8)
void __do_global_ctors_aux(void)
{
    return;
}

void _fini(void)
{
    __do_global_dtors_aux();
    return;
}
