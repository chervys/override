#include <iostream>
#include <cstdint>
#include <cstring>

int main(int argc, char **argv)
{
    char *str;
    uint32_t truc;
    int i;
    int len;

    if (argc != 2)
        return (1);
    str = argv[1];
    len = strlen(str);
    if (len < 6 || len > 30)
        return (1);
    truc = str[3];
    truc = (truc ^ 0x1337) + 0x5eeded;
    i = 0;
    while (i < len)
    {
        truc = truc + (str[i] ^ truc) % 0x539;
        i++;
    }
    std::cout << "username = " << str << std::endl;
    std::cout << "pass = " << truc << std::endl;
    return (0);
}