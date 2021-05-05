#include "libasm.h"

int     main()
{
    char        *phrase1 = "Hello";
    char        *phrase2 = "Hello world";
    char        *phrase3 = "";
    char        *phrase4 = "§1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./";
    char        *dst;
    int fd0;
    int fd1;
    int fd2;
    int fd3;
    char    *write_0 = "Testing write and read man 2\n\n";
    char    *write_1 = "Testing write and read asmlb\n\n";
    char    *buf0;
    char    *buf1;

    dst = (char *)malloc(sizeof(char));
    fd0 = open("write.txt", O_CREAT | O_TRUNC | O_RDWR, 0777);
    fd1 = open("write_asm.txt", O_CREAT | O_TRUNC | O_RDWR, 0777);
    fd2 = open("read.txt", O_RDONLY);
    fd3 = open("read_asm.txt", O_RDONLY);
    buf0 = (char *)malloc(124);
    buf1 = (char *)malloc(130);
    printf("\033[1;32mSTRLEN\n\033[0m");
    printf("\033[1;32mstring: %s\nstrlen: %zu\nasmlen: %zu\n\033[0m", phrase1, strlen(phrase1), ft_strlen(phrase1));
    printf("\033[1;32mstring: %s\nstrlen: %zu\nasmlen: %zu\n\033[0m", phrase2, strlen(phrase2), ft_strlen(phrase2));
    printf("\033[1;32mstring: %s\nstrlen: %zu\nasmlen: %zu\n\033[0m", phrase3, strlen(phrase3), ft_strlen(phrase3));
    printf("\033[1;32mstring: %s\nstrlen: %zu\nasmlen: %zu\n\033[0m", phrase4, strlen(phrase4), ft_strlen(phrase4));
    printf("\n\n\n");

    printf("\033[1;35mSTRCPY\n\033[0m");
    printf("\033[1;35mstring: %s\nstrcpy: %s\nasmcpy: %s\n\033[0m", phrase1, strcpy(dst, phrase1),ft_strcpy(dst, phrase1));
    printf("\033[1;35mstring: %s\nstrcpy: %s\nasmcpy: %s\n\033[0m", phrase2, strcpy(dst, phrase2),ft_strcpy(dst, phrase2));
    printf("\033[1;35mstring: %s\nstrcpy: %s\nasmcpy: %s\n\033[0m", phrase3, strcpy(dst, phrase3),ft_strcpy(dst, phrase3));
    printf("\033[1;35mstring: %s\nstrcpy: %s\nasmcpy: %s\n\033[0m", phrase4, strcpy(dst, phrase4),ft_strcpy(dst, phrase4));
    printf("\n\n\n");

    printf("\033[1;33mSTRCMP\n\033[0m");
    printf("\033[1;33mstring1: %s\nstring2: %s\nstrcmp: %d\nasmcmp: %d\n\033[0m", phrase1, phrase2, strcmp(phrase1, phrase2), ft_strcmp(phrase1, phrase2));
    printf("\033[1;33mstring1: %s\nstring2: %s\nstrcmp: %d\nasmcmp: %d\n\033[0m", phrase2, phrase3, strcmp(phrase2, phrase3), ft_strcmp(phrase2, phrase3));
    printf("\033[1;33mstring1: %s\nstring2: %s\nstrcmp: %d\nasmcmp: %d\n\033[0m", phrase3, phrase4, strcmp(phrase3, phrase4), ft_strcmp(phrase3, phrase4));
    printf("\033[1;33mstring1: %s\nstring2: %s\nstrcmp: %d\nasmcmp: %d\n\033[0m", phrase4, phrase1, strcmp(phrase4, phrase1), ft_strcmp(phrase4, phrase1));
    printf("\n\n\n");

    write(1, write_0, 30);
    printf("\n");
    write(fd0, "Test std\n", 9);
    printf("\n");
    ft_write(1, write_1, 30);
    printf("\n\n");
    ft_write(fd1, "Test asm\n", 9);
    printf("\n\n");
    write(fd0, NULL, 1);
    printf("WRITE STD error NULL buff: %s\n", strerror(errno));
    write(-1, "Test std\n", 9);
    printf("WRITE STD error wrong fd: %s\n", strerror(errno));
    write(fd0, "Test std\n", -1);
    printf("WRITE STD error size too small: %s\n", strerror(errno));
    printf("\n\n\n");
    ft_write(fd1, NULL, 1);
    printf("WRITE ASM error NULL buff: %s\n", strerror(errno));
    ft_write(-1, "Test asm\n", 9);
    printf("WRITE ASM error wrong fd: %s\n", strerror(errno));
    ft_write(fd1, "Test asm\n", -1);
    printf("WRITE ASM error size too small: %s\n", strerror(errno));
    printf("\n\n\n");

    read(fd2, buf0, 123);
    printf("READ text from file STD:\n%s\n", buf0);
    printf("\n\n\n");
    ft_read(fd3, buf1, 129);
    printf("READ text from file ASM:\n%s\n", buf1);
    printf("\n\n");
    read(fd2, NULL, 1);
    printf("READ STD error NULL buff: %s\n", strerror(errno));
    read(-1, buf0, 123);
    printf("READ STD error wrong fd: %s\n", strerror(errno));
    read(fd2, buf0, -1);
    printf("READ STD error size too small: %s\n", strerror(errno));
    printf("\n\n\n");
    ft_read(fd3, NULL, 1);
    printf("READ ASM error NULL buff: %s\n", strerror(errno));
    ft_read(-1, buf1, 129);
    printf("READ ASM error wrong fd: %s\n", strerror(errno));
    ft_read(fd3, buf1, -1);
    printf("READ ASM error size too small: %s\n", strerror(errno));
    printf("\n\n\n");

    close(fd0);
    close(fd1);
    close(fd2);
    close(fd3);
    free(buf0);
    free(buf1);

    printf("\033[1;36mSTRDUP\n\033[0m");
    printf("\033[1;36mSTRDUP string: %s\nstrdup: %s\nasmdup: %s\n\033[0m", phrase1, strdup(phrase1), ft_strdup(phrase1));
    printf("\033[1;36mSTRDUP string: %s\nstrdup: %s\nasmdup: %s\n\033[0m", phrase2, strdup(phrase2), ft_strdup(phrase2));
    printf("\033[1;36mSTRDUP string: %s\nstrdup: %s\nasmdup: %s\n\033[0m", phrase3, strdup(phrase3), ft_strdup(phrase3));
    printf("\033[1;36mSTRDUP string: %s\nstrdup: %s\nasmdup: %s\n\033[0m", phrase4, strdup(phrase4), ft_strdup(phrase4));

    return (0);
}