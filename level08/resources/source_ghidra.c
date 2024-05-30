#include "out.h"

int _init(EVP_PKEY_CTX* ctx)

{
    int iVar1;

    call_gmon_start();
    frame_dummy();
    iVar1 = __do_global_ctors_aux();
    return iVar1;
}

void FUN_004006e0(void)

{
    // WARNING: Treating indirect jump as call
    (*(code*)(undefined*)0x0)();
    return;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked

char* strcpy(char* __dest, char* __src)

{
    char* pcVar1;

    pcVar1 = strcpy(__dest, __src);
    return pcVar1;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked

ssize_t write(int __fd, void* __buf, size_t __n)

{
    ssize_t sVar1;

    sVar1 = write(__fd, __buf, __n);
    return sVar1;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked

int fclose(FILE* __stream)

{
    int iVar1;

    iVar1 = fclose(__stream);
    return iVar1;
}

void __stack_chk_fail(void)

{
    // WARNING: Subroutine does not return
    __stack_chk_fail();
}

// WARNING: Unknown calling convention -- yet parameter storage is locked

int printf(char* __format, ...)

{
    int iVar1;

    iVar1 = printf(__format);
    return iVar1;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked

int snprintf(char* __s, size_t __maxlen, char* __format, ...)

{
    int iVar1;

    iVar1 = snprintf(__s, __maxlen, __format);
    return iVar1;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked

char* strncat(char* __dest, char* __src, size_t __n)

{
    char* pcVar1;

    pcVar1 = strncat(__dest, __src, __n);
    return pcVar1;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked

int fgetc(FILE* __stream)

{
    int iVar1;

    iVar1 = fgetc(__stream);
    return iVar1;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked

int close(int __fd)

{
    int iVar1;

    iVar1 = close(__fd);
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

int fprintf(FILE* __stream, char* __format, ...)

{
    int iVar1;

    iVar1 = fprintf(__stream, __format);
    return iVar1;
}

// WARNING: Unknown calling convention -- yet parameter storage is locked

int open(char* __file, int __oflag, ...)

{
    int iVar1;

    iVar1 = open(__file, __oflag);
    return iVar1;
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

// WARNING: Removing unreachable block (ram,0x00400862)
// WARNING: Removing unreachable block (ram,0x00400868)

void __do_global_dtors_aux(void)

{
    if (completed_6531 == '\0') {
        completed_6531 = '\x01';
    }
    return;
}

// WARNING: Removing unreachable block (ram,0x004008ae)
// WARNING: Removing unreachable block (ram,0x004008b8)

void frame_dummy(void)

{
    return;
}

void log_wrapper(FILE* param_1, char* param_2, char* param_3)

{
    char cVar1;
    size_t sVar2;
    ulong uVar3;
    ulong uVar4;
    char* pcVar5;
    long in_FS_OFFSET;
    byte bVar6;
    undefined8 local_120;
    char local_118[264];
    long local_10;

    bVar6 = 0;
    local_10 = *(long*)(in_FS_OFFSET + 0x28);
    local_120 = param_1;
    strcpy(local_118, param_2);
    uVar3 = 0xffffffffffffffff;
    pcVar5 = local_118;
    do {
        if (uVar3 == 0)
            break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + (ulong)bVar6 * -2 + 1;
    } while (cVar1 != '\0');
    uVar4 = 0xffffffffffffffff;
    pcVar5 = local_118;
    do {
        if (uVar4 == 0)
            break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + (ulong)bVar6 * -2 + 1;
    } while (cVar1 != '\0');
    snprintf(local_118 + (~uVar4 - 1), 0xfe - (~uVar3 - 1), param_3);
    sVar2 = strcspn(local_118, "\n");
    local_118[sVar2] = '\0';
    fprintf(local_120, "LOG: %s\n", local_118);
    if (local_10 != *(long*)(in_FS_OFFSET + 0x28)) {
        // WARNING: Subroutine does not return
        __stack_chk_fail();
    }
    return;
}

undefined8 main(int param_1, undefined8* param_2)

{
    char cVar1;
    int __fd;
    int iVar2;
    FILE* pFVar3;
    FILE* __stream;
    ulong uVar4;
    undefined8* puVar5;
    long in_FS_OFFSET;
    byte bVar6;
    char local_79;
    undefined8 local_78;
    undefined2 local_70;
    char local_6e;
    long local_10;

    bVar6 = 0;
    local_10 = *(long*)(in_FS_OFFSET + 0x28);
    local_79 = -1;
    if (param_1 != 2) {
        printf("Usage: %s filename\n", *param_2);
    }
    pFVar3 = fopen("./backups/.log", "w");
    if (pFVar3 == (FILE*)0x0) {
        printf("ERROR: Failed to open %s\n", "./backups/.log");
        // WARNING: Subroutine does not return
        exit(1);
    }
    log_wrapper(pFVar3, "Starting back up: ", param_2[1]);
    __stream = fopen((char*)param_2[1], "r");
    if (__stream == (FILE*)0x0) {
        printf("ERROR: Failed to open %s\n", param_2[1]);
        // WARNING: Subroutine does not return
        exit(1);
    }
    local_78._0_1_ = '.';
    local_78._1_1_ = '/';
    local_78._2_1_ = 'b';
    local_78._3_1_ = 'a';
    local_78._4_1_ = 'c';
    local_78._5_1_ = 'k';
    local_78._6_1_ = 'u';
    local_78._7_1_ = 'p';
    local_70._0_1_ = 's';
    local_70._1_1_ = '/';
    local_6e = '\0';
    uVar4 = 0xffffffffffffffff;
    puVar5 = &local_78;
    do {
        if (uVar4 == 0)
            break;
        uVar4 = uVar4 - 1;
        cVar1 = *(char*)puVar5;
        puVar5 = (undefined8*)((long)puVar5 + (ulong)bVar6 * -2 + 1);
    } while (cVar1 != '\0');
    strncat((char*)&local_78, (char*)param_2[1], 99 - (~uVar4 - 1));
    __fd = open((char*)&local_78, 0xc1, 0x1b0);
    if (__fd < 0) {
        printf("ERROR: Failed to open %s%s\n", "./backups/", param_2[1]);
        // WARNING: Subroutine does not return
        exit(1);
    }
    while (true) {
        iVar2 = fgetc(__stream);
        local_79 = (char)iVar2;
        if (local_79 == -1)
            break;
        write(__fd, &local_79, 1);
    }
    log_wrapper(pFVar3, "Finished back up ", param_2[1]);
    fclose(__stream);
    close(__fd);
    if (local_10 != *(long*)(in_FS_OFFSET + 0x28)) {
        // WARNING: Subroutine does not return
        __stack_chk_fail();
    }
    return 0;
}

// WARNING: Removing unreachable block (ram,0x00400caa)
// WARNING: Removing unreachable block (ram,0x00400cb0)

void __libc_csu_init(EVP_PKEY_CTX* param_1)

{
    _init(param_1);
    return;
}

void __libc_csu_fini(void)

{
    return;
}

// WARNING: Removing unreachable block (ram,0x00400d16)
// WARNING: Removing unreachable block (ram,0x00400d20)

void __do_global_ctors_aux(void)

{
    return;
}

void _fini(void)

{
    __do_global_dtors_aux();
    return;
}
