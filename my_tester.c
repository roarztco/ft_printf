#include <stdio.h>
#include <limits.h>
#include "printf.h"

#define TEST(...) do { \
	int a; \
	int b; \
	printf("printf   : |"); \
	fflush(stdout); \
	a = printf(__VA_ARGS__); \
	fflush(stdout); \
	printf("|\n"); \
	printf("ft_printf: |"); \
	fflush(stdout); \
	b = ft_printf(__VA_ARGS__); \
	printf("|\n"); \
	printf("return   : %d vs %d -> %s\n\n", a, b, a == b ? "OK" : "KO"); \
} while (0)

int	main(void)
{
	int	x = 42;

	TEST("hello world");
	TEST("%c|%c|%c", 'A', '0', ' ');
	TEST("%s|%s|%s", "hello", "", (char *)NULL);
	TEST("%d|%d|%d|%d|%d", 0, -1, 42, INT_MAX, INT_MIN);
	TEST("%i|%i|%i", 0, -42, 1000000);
	TEST("%u|%u|%u", 0, 42, UINT_MAX);
	TEST("%u", -1);
	TEST("%x|%x|%x|%x", 0, 255, 4096, UINT_MAX);
	TEST("%X|%X|%X|%X", 0, 255, 4096, UINT_MAX);
	TEST("%p|%p|%p", &x, (void *)0, (void *)-1);
	TEST("%p", (void *)16);
	TEST("100%%|%%|%%%%");
	TEST("%c%s%d%i%u%x%X%p%%", 'z', "s", 1, 2, 3, 4, 5, &x);
	TEST("no specifiers at all\n");
	TEST("a%db%sc%cd", 10, "mid", 'X');
	return (0);
}