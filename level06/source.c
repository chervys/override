/* This file was generated by the Hex-Rays decompiler version 8.3.0.230608.
   Copyright (c) 2007-2021 Hex-Rays <info@hex-rays.com>

   Detected compiler: GNU C++
*/

#include <defs.h>

//-------------------------------------------------------------------------
// Function declarations

void (*init_proc())(void);
int sub_8048500();
// int printf(const char *format, ...);
// size_t strcspn(const char *s, const char *reject);
// int fflush(FILE *stream);
// int getchar(void);
// char *fgets(char *s, int n, FILE *stream);
// __sighandler_t signal(int sig, __sighandler_t handler);
// unsigned int alarm(unsigned int seconds);
// int puts(const char *s);
// int system(const char *command);
// int __gmon_start__(void); weak
// int __cdecl __libc_start_main(int (__cdecl *main)(int, char **, char **), int argc, char **ubp_av, void (*init)(void), void (*fini)(void), void (*rtld_fini)(void), void *stack_end);
// int __cdecl strnlen(_DWORD, _DWORD); weak
// int __cdecl __isoc99_scanf(_DWORD, _DWORD); weak
// int ptrace(enum __ptrace_request request, ...);
// void __usercall __noreturn start(int a1@<eax>, void (*a2)(void)@<edx>);
void _do_global_dtors_aux();
int frame_dummy();
int clear_stdin();
int get_unum();
void __cdecl __noreturn prog_timeout(int a1);
unsigned int enable_timeout_cons();
_BOOL4 __cdecl auth(char* s, int a2);
int __cdecl main(int argc, const char** argv, const char** envp);
void _libc_csu_init(void); // idb
void _libc_csu_fini(void); // idb
void (*_do_global_ctors_aux())(void);
void term_proc();

//-------------------------------------------------------------------------
// Data declarations

_UNKNOWN unk_8048A60; // weak
int (*_init_array_start)() = &enable_timeout_cons; // weak
int _CTOR_LIST__ = -1; // weak
int _DTOR_LIST__[] = { -1 }; // weak
int _DTOR_END__ = 0; // weak
int _JCR_LIST__ = 0; // weak
Elf32_Dyn* GLOBAL_OFFSET_TABLE_ = &DYNAMIC; // weak
int (*dword_8049FFC)(void) = NULL; // weak
FILE* stdin; // idb
FILE* stdout; // idb
char completed_6159; // weak
int dtor_idx_6161; // weak
// extern _UNKNOWN _gmon_start__; weak

//----- (080484D0) --------------------------------------------------------
void (*init_proc())(void)
{
    if (&_gmon_start__)
        __gmon_start__();
    frame_dummy();
    return _do_global_ctors_aux();
}
// 80485B0: using guessed type int __gmon_start__(void);

//----- (08048500) --------------------------------------------------------
int sub_8048500()
{
    return dword_8049FFC();
}
// 8049FFC: using guessed type int (*dword_8049FFC)(void);

//----- (08048600) --------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall __noreturn start(int a1 @<eax>, void (*a2)(void) @<edx>)
{
    int v2; // esi
    int v3; // [esp-4h] [ebp-4h] BYREF
    char* retaddr; // [esp+0h] [ebp+0h] BYREF

    v2 = v3;
    v3 = a1;
    __libc_start_main((int(__cdecl*)(int, char**, char**))main, v2, &retaddr, _libc_csu_init, _libc_csu_fini, a2, &v3);
    __halt();
}
// 8048603: positive sp value 4 has been found

//----- (08048630) --------------------------------------------------------
void _do_global_dtors_aux()
{
    int v0; // eax
    unsigned int i; // ebx

    if (!completed_6159) {
        v0 = dtor_idx_6161;
        for (i = &_DTOR_END__ - _DTOR_LIST__ - 1; dtor_idx_6161 < i; v0 = dtor_idx_6161) {
            dtor_idx_6161 = v0 + 1;
            ((void (*)(void))_DTOR_LIST__[v0 + 1])();
        }
        completed_6159 = 1;
    }
}
// 8049F0C: using guessed type int _DTOR_LIST__[];
// 8049F10: using guessed type int _DTOR_END__;
// 804A084: using guessed type char completed_6159;
// 804A088: using guessed type int dtor_idx_6161;

//----- (08048690) --------------------------------------------------------
int frame_dummy()
{
    int result; // eax

    result = _JCR_LIST__;
    if (_JCR_LIST__)
        return 0;
    return result;
}
// 8049F14: using guessed type int _JCR_LIST__;

//----- (080486B4) --------------------------------------------------------
int clear_stdin()
{
    int result; // eax

    do
        result = getchar();
    while ((_BYTE)result != 10 && (_BYTE)result != 0xFF);
    return result;
}

//----- (080486D7) --------------------------------------------------------
int get_unum()
{
    int v1[3]; // [esp+1Ch] [ebp-Ch] BYREF

    v1[0] = 0;
    fflush(stdout);
    __isoc99_scanf(&unk_8048A60, v1);
    clear_stdin();
    return v1[0];
}
// 80485E0: using guessed type int __cdecl __isoc99_scanf(_DWORD, _DWORD);
// 80486D7: using guessed type int var_C[3];

//----- (0804870F) --------------------------------------------------------
void __cdecl __noreturn prog_timeout(int a1)
{
    int v1; // eax

    v1 = sys_exit(1);
}

//----- (08048720) --------------------------------------------------------
unsigned int enable_timeout_cons()
{
    signal(14, (__sighandler_t)prog_timeout);
    return alarm(0x3Cu);
}

//----- (08048748) --------------------------------------------------------
_BOOL4 __cdecl auth(char* s, int a2)
{
    int i; // [esp+14h] [ebp-14h]
    int v4; // [esp+18h] [ebp-10h]
    int v5; // [esp+1Ch] [ebp-Ch]

    s[strcspn(s, "\n")] = 0;
    v5 = strnlen(s, 32);
    if (v5 <= 5)
        return 1;
    if (ptrace(PTRACE_TRACEME, 0, 1, 0) == -1) {
        puts("\x1B[32m.---------------------------.");
        puts("\x1B[31m| !! TAMPERING DETECTED !!  |");
        puts("\x1B[32m'---------------------------'");
        return 1;
    } else {
        v4 = (s[3] ^ 0x1337) + 6221293;
        for (i = 0; i < v5; ++i) {
            if (s[i] <= 31)
                return 1;
            v4 += (v4 ^ (unsigned int)s[i]) % 0x539;
        }
        return a2 != v4;
    }
}
// 80485D0: using guessed type int __cdecl strnlen(_DWORD, _DWORD);

//----- (08048879) --------------------------------------------------------
int __cdecl main(int argc, const char** argv, const char** envp)
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
    if (auth(s, v4))
        return 1;
    puts("Authenticated!");
    system("/bin/sh");
    return 0;
}
// 80485E0: using guessed type int __cdecl __isoc99_scanf(_DWORD, _DWORD);

//----- (08048990) --------------------------------------------------------
void _libc_csu_init(void)
{
    int v0; // edi
    int i; // esi

    init_proc();
    v0 = ((char*)&_CTOR_LIST__ - ((char*)&GLOBAL_OFFSET_TABLE_ + (_DWORD)(&_init_array_start - 33630205))) >> 2;
    if (v0) {
        for (i = 0; i != v0; ++i)
            (*(&_init_array_start + i))();
    }
}
// 8049F00: using guessed type int (*_init_array_start)();
// 8049F04: using guessed type int _CTOR_LIST__;
// 8049FF4: using guessed type Elf32_Dyn *GLOBAL_OFFSET_TABLE_;

//----- (08048A10) --------------------------------------------------------
void (*_do_global_ctors_aux())(void)
{
    void (*result)(void); // eax
    void (**v1)(void); // ebx

    result = (void (*)(void))_CTOR_LIST__;
    if (_CTOR_LIST__ != -1) {
        v1 = (void (**)(void)) & _CTOR_LIST__;
        do {
            --v1;
            result();
            result = *v1;
        } while (*v1 != (void (*)(void)) - 1);
    }
    return result;
}
// 8049F04: using guessed type int _CTOR_LIST__;

//----- (08048A3C) --------------------------------------------------------
void term_proc()
{
    _do_global_dtors_aux();
}

// nfuncs=46 queued=14 decompiled=14 lumina nreq=0 worse=0 better=0
// ALL OK, 14 function(s) have been successfully decompiled
