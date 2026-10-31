/* ************************************************************************** */
/*                                                                            */
/*   main.c - comparaison entre printf et ft_printf                          */
/*                                                                            */
/*   Compilation :                                                            */
/*   cc -Wall -Wextra -Werror main.c ft_printf.c ft_printf_var.c -o test     */
/*   ./test                                                                   */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int	compare_files(FILE *expected, FILE *actual)
{
	char	expected_buffer[4096];
	char	actual_buffer[4096];
	size_t	expected_size;
	size_t	actual_size;

	rewind(expected);
	rewind(actual);
	expected_size = fread(expected_buffer, 1, sizeof(expected_buffer), expected);
	actual_size = fread(actual_buffer, 1, sizeof(actual_buffer), actual);
	if (expected_size != actual_size)
		return (0);
	return (memcmp(expected_buffer, actual_buffer, expected_size) == 0);
}

#define TEST(label, ...)                                                     \
	do                                                                       \
	{                                                                        \
		FILE	*expected_file;                                             \
		FILE	*actual_file;                                               \
		int		expected_return;                                           \
		int		actual_return;                                             \
		int		saved_stdout;                                              \
		int		same_output;                                               \
                                                                               \
		expected_file = tmpfile();                                         \
		actual_file = tmpfile();                                           \
		if (!expected_file || !actual_file)                                \
			return (1);                                                    \
		saved_stdout = dup(STDOUT_FILENO);                                 \
		dup2(fileno(expected_file), STDOUT_FILENO);                        \
		expected_return = printf(__VA_ARGS__);                              \
		fflush(stdout);                                                     \
		dup2(fileno(actual_file), STDOUT_FILENO);                           \
		actual_return = ft_printf(__VA_ARGS__);                             \
		fflush(stdout);                                                     \
		dup2(saved_stdout, STDOUT_FILENO);                                  \
		close(saved_stdout);                                                \
		same_output = compare_files(expected_file, actual_file);            \
		printf("%-42s : %s", label,                                              \
			(same_output && expected_return == actual_return)                \
			? "OK" : "KO");                                                  \
		if (!same_output || expected_return != actual_return)                \
			printf(" (printf=%d, ft_printf=%d)", expected_return,            \
				actual_return);                                               \
		printf("\n");                                                        \
		fclose(expected_file);                                               \
		fclose(actual_file);                                                 \
	} while (0)

int	main(void)
{
	int				number;
	unsigned int	unsigned_number;
	char			*string;
	int				value;

	number = -42;
	unsigned_number = 4294967295U;
	string = "Hello ft_printf";
	value = 42;
	printf("========== Comparaison printf / ft_printf ==========\n\n");
	TEST("texte simple", "Bonjour le monde !\n");
	TEST("texte vide", "");
	TEST("pourcentage", "100%%\n");
	TEST("caractere", "[%c]\n", 'A');
	TEST("caractere espace", "[%c]\n", ' ');
	TEST("plusieurs caracteres", "[%c] [%c] [%c]\n", 'X', 'Y', 'Z');
	TEST("chaine", "[%s]\n", string);
	TEST("chaine vide", "[%s]\n", "");
	TEST("chaine NULL", "[%s]\n", (char *)0);
	TEST("entier negatif", "[%d]\n", number);
	TEST("entier zero", "[%d]\n", 0);
	TEST("entier positif", "[%d]\n", 42);
	TEST("INT_MAX", "[%d]\n", INT_MAX);
	TEST("INT_MIN", "[%d]\n", INT_MIN);
	TEST("conversion i", "[%i]\n", number);
	TEST("plusieurs d et i", "[%d] [%i] [%d]\n", -1, 0, 1);
	TEST("unsigned zero", "[%u]\n", 0U);
	TEST("unsigned normal", "[%u]\n", 42U);
	TEST("unsigned max", "[%u]\n", unsigned_number);
	TEST("hexadecimal zero", "[%x] [%X]\n", 0U, 0U);
	TEST("hexadecimal normal", "[%x] [%X]\n", 255U, 255U);
	TEST("hexadecimal long", "[%x] [%X]\n", 305441741U, 305441741U);
	TEST("hexadecimal max", "[%x] [%X]\n", unsigned_number,
		unsigned_number);
	TEST("pointeur chaine", "[%p]\n", (void *)string);
	TEST("pointeur variable", "[%p]\n", (void *)&value);
	TEST("pointeur NULL", "[%p]\n", (void *)0);
	TEST("format mixte",
		"c=%c s=%s d=%d u=%u x=%x X=%X p=%p %%\n",
		'F', string, number, unsigned_number, 48879U, 48879U,
		(void *)string);
	TEST("plusieurs formats",
		"%c %s %d %i %u %x %X %p %%\n",
		'Z', "test", -123, 123, 123U, 123U, 123U, (void *)string);
	printf("\n=====================================================\n");
	return (0);
}
