#include "out.h"

int _init(EVP_PKEY_CTX* ctx)
{
    int iVar1;

    __gmon_start__();
    frame_dummy();
    iVar1 = __do_global_ctors_aux();
    return iVar1;
}

void FUN_08048500(void)
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
size_t strcspn(char* __s, char* __reject)
{
    size_t sVar1;

    sVar1 = strcspn(__s, __reject);
    return sVar1;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked
int fflush(FILE* __stream)
{
    int iVar1;

    iVar1 = fflush(__stream);
    return iVar1;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked
int getchar(void)
{
    int iVar1;

    iVar1 = getchar();
    return iVar1;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked
char* fgets(char* __s, int __n, FILE* __stream)
{
    char* pcVar1;

    pcVar1 = fgets(__s, __n, __stream);
    return pcVar1;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked
__sighandler_t signal(int __sig, __sighandler_t __handler)
{
    __sighandler_t p_Var1;

    p_Var1 = signal(__sig, __handler);
    return p_Var1;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked
uint alarm(uint __seconds)
{
    uint uVar1;

    uVar1 = alarm(__seconds);
    return uVar1;
}

void __stack_chk_fail(void)
{
    // WARNING: Subroutine does not return
    __stack_chk_fail();
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

// WARNING: Unknown calling convention -- yet parameter storage is locked
size_t strnlen(char* __string, size_t __maxlen)
{
    size_t sVar1;

    sVar1 = strnlen(__string, __maxlen);
    return sVar1;
}

void __isoc99_scanf(void)
{
    __isoc99_scanf();
    return;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked
long ptrace(__ptrace_request __request, ...)
{
    long lVar1;

    lVar1 = ptrace(__request);
    return lVar1;
}

void processEntry _start(undefined4 param_1, undefined4 param_2)
{
    undefined auStack_4[4];

    __libc_start_main(main, param_2, &stack0x00000004, __libc_csu_init, __libc_csu_fini, param_1, auStack_4);
    do {
        // WARNING: Do nothing block with infinite loop
    } while (true);
}

// WARNING: Removing unreachable block (ram,0x0804865a)
// WARNING: Removing unreachable block (ram,0x08048660)
void __do_global_dtors_aux(void)
{
    if (completed_6159 == '\0') {
        completed_6159 = '\x01';
    }
    return;
}

// WARNING: Removing unreachable block (ram,0x0804869f)
// WARNING: Removing unreachable block (ram,0x080486a8)
void frame_dummy(void)
{
    return;
}

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
    undefined4 local_10[3];

    local_10[0] = 0;
    fflush(stdout);
    __isoc99_scanf(&DAT_08048a60, local_10);
    clear_stdin();
    return local_10[0];
}

void prog_timeout(void)
{
    code* pcVar1;

    pcVar1 = (code*)swi(0x80);
    (*pcVar1)();
    return;
}

void enable_timeout_cons(void)
{
    signal(0xe, prog_timeout);
    alarm(0x3c);
    return;
}

// WARNING: Removing unreachable block (ram,0x08048782)
// WARNING: Restarted to delay deadcode elimination for space: stack
undefined4 auth(char* param_1, uint param_2)
{
    size_t sVar1;
    undefined4 uVar2;
    long lVar3;
    int local_18;
    uint local_14;

    sVar1 = strcspn(param_1, "\n");
    param_1[sVar1] = '\0';
    sVar1 = strnlen(param_1, 0x20);
    if ((int)sVar1 < 6) {
        uVar2 = 1;
    } else {
        lVar3 = ptrace(PTRACE_TRACEME);
        if (lVar3 == -1) {
            puts("\x1b[32m.---------------------------.");
            puts("\x1b[31m| !! TAMPERING DETECTED !!  |");
            puts("\x1b[32m\'---------------------------\'");
            uVar2 = 1;
        } else {
            local_14 = ((int)param_1[3] ^ 0x1337U) + 0x5eeded;
            for (local_18 = 0; local_18 < (int)sVar1; local_18 = local_18 + 1) {
                if (param_1[local_18] < ' ') {
                    return 1;
                }
                local_14 = local_14 + ((int)param_1[local_18] ^ local_14) % 0x539;
            }
            if (param_2 == local_14) {
                uVar2 = 0;
            } else {
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
    char local_34[32];
    int local_14;

    local_14 = *(int*)(in_GS_OFFSET + 0x14);
    puts("***********************************");
    puts("*\t\tlevel06\t\t  *");
    puts("***********************************");
    printf("-> Enter Login: ");
    fgets(local_34, 0x20, stdin);
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
    if (local_14 != *(int*)(in_GS_OFFSET + 0x14)) {
        // WARNING: Subroutine does not return
        __stack_chk_fail();
    }
    return iVar1 != 0;
}

// WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx
void __libc_csu_init(undefined4 param_1, undefined4 param_2, undefined4 param_3)
{
    int iVar1;
    EVP_PKEY_CTX* in_stack_ffffffd4;

    _init(in_stack_ffffffd4);
    iVar1 = 0;
    do {
        (*(code*)(&__DT_INIT_ARRAY)[iVar1])(param_1, param_2, param_3);
        iVar1 = iVar1 + 1;
    } while (iVar1 != 1);
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

// WARNING: Removing unreachable block (ram,0x08048a21)
// WARNING: Removing unreachable block (ram,0x08048a28)
void __do_global_ctors_aux(void)
{
    return;
}

void _fini(void)
{
    __do_global_dtors_aux();
    return;
}
