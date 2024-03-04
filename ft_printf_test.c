/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:45:47 by rpandipe          #+#    #+#             */
/*   Updated: 2024/03/01 19:32:13 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

#include "../ft_printf/ft_printf.h"
#include "../ft_printf/ft_printf.c"
#include "../ft_printf/ft_printstr.c"
#include "../ft_printf/ft_printnbr.c"
#include "../ft_printf/ft_bonus1.c"
#include "../ft_printf/ft_bonussorter.c"
#include "../ft_printf/ft_savestr.c"
#include "../ft_printf/ft_savenbr.c"
#include "../ft_printf/ft_savemem.c"
#include "../ft_printf/ft_width.c"
#include "../ft_printf/libft/libft.h"
#include "../ft_printf/libft/ft_putchar_fd.c"
#include "../ft_printf/libft/ft_putstr_fd.c"
#include "../ft_printf/libft/ft_putnbr_fd.c"
#include "../ft_printf/ft_printmem.c"
#include "../ft_printf/libft/ft_strlen.c"
#include "../ft_printf/libft/ft_strlcpy.c"
#include "../ft_printf/libft/ft_isdigit.c"
#include "../ft_printf/libft/ft_memmove.c"
#include "../ft_printf/libft/ft_memcpy.c"
#include "../ft_printf/libft/ft_memset.c"
#include "../ft_printf/libft/ft_itoa.c"

int	main()
{
	int count;
	int count_c;

	/**
	//Testing Character
	count = ft_printf("Test character : %c\n", 'c');
	printf("With printf \n");
	count_c = printf("Test character : %c\n", 'c');
	if (count == count_c)
		ft_printf("Passed\n");
	else
		ft_printf("Failed\nExpected : %d\n Result: %d\n", count_c, count);

	// Testing String
	count = ft_printf("Test string : %s\n", "String Test");
	printf("With printf \n");
	count_c = printf("Test string : %s\n", "String Test");
	if (count == count_c)
		ft_printf("Passed\n");
        else
		ft_printf("Failed\nExpected : %d\n Result: %d\n", count_c, count);

	// Testing Integer
	count = ft_printf("Test number : %d\n", 42);
	printf("With printf \n");
	count_c = printf("Test number : %d\n", 42);
	if (count == count_c)
                ft_printf("Passed\n");
        else
                ft_printf("Failed\nExpected : %d\n Result: %d\n", count_c, count);
	count = ft_printf("Test string : %d\n", -42);
	printf("With printf \n");
	count_c = printf("Test string : %d\n", -42);
        if (count == count_c)
                ft_printf("Passed\n");
        else
                ft_printf("Failed\nExpected : %d\n Result: %d\n", count_c, count);

	// Testing Unsigned Integer
	count = ft_printf("Test unsigned int : %u\n", 42);
	printf("With printf \n");
	count_c = printf("Test unsigned int : %u\n", 42);
        if (count == count_c)
                ft_printf("Passed\n");
        else
                ft_printf("Failed\nExpected : %d\n Result: %d\n", count_c, count);
        count = ft_printf("Test unsigned int : %u\n", -42);
	printf("With printf \n");
	count_c = printf("Test unsigned int : %u\n", -42);
        if (count == count_c)
                ft_printf("Passed\n");
        else
                ft_printf("Failed\nExpected : %d\n Result: %d\n", count_c, count);
	
	// Testing small Hexdecimal
        count = ft_printf("Test lower hex : %x\n", 42);
	printf("With printf \n");
	count_c = printf("Test lower hex : %x\n", 42);
        if (count == count_c)
                ft_printf("Passed\n");
        else
                ft_printf("Failed\nExpected : %d\n Result: %d\n", count_c, count);
        count = ft_printf("Test lower hex : %x\n", -42);
	printf("With printf \n");
	count_c = printf("Test lower hex : %x\n", -42);
        if (count == count_c)
                ft_printf("Passed\n");
        else
                ft_printf("Failed\nExpected : %d\n Result: %d\n", count_c, count);

	// Testing upper Hexdecimal
        count = ft_printf("Test upper hex : %X\n", 42);
	printf("With printf \n");
	count_c = printf("Test upper hex : %X\n", 42);
        if (count == count_c)
                ft_printf("Passed\n");
        else
                ft_printf("Failed\nExpected : %d\n Result: %d\n", count_c, count);
        count = ft_printf("Test upper hex : %X\n", -42);
	printf("With printf \n");
	count_c = printf("Test upper hex : %X\n", -42);
        if (count == count_c)
                ft_printf("Passed\n");
        else
                ft_printf("Failed\nExpected : %d\n Result: %d\n", count_c, count);

	//Testing %
	count = ft_printf("Test percentage : %%\n");
        printf("With printf \n");
        count_c = printf("Test percentage : %%\n");
        if (count == count_c)
                ft_printf("Passed\n");
        else
                ft_printf("Failed\nExpected : %d\n Result: %d\n", count_c, count);

	//Testing address
	int value = 42;
	int *ptr = &value;

	printf("Address of the variable 'value': %p\n", (void*)ptr);
	ft_printf("Address of the variable 'value': %p\n", (void*)ptr);
	
	printf("Address of the variable 'value': %p\n", ((void*)0));
        ft_printf("Address of the variable 'value': %p\n", ((void*)0));

	//Extreme tests
	count_c = printf(" %c  %c  %c \n", '0', 0, '1');
	count = ft_printf(" %c  %c  %c \n", '0', 0, '1');
	if (count == count_c)
                ft_printf("Passed\n");
        else
                ft_printf("Failed\n\tExpected : %d\n\tResult: %d\n", count_c, count);

	count_c = printf(" %c  %c  %c \n", '1', '2', '3');
        count = ft_printf(" %c  %c  %c \n", '1', '2', '3');
        if (count == count_c)
                ft_printf("Passed\n");
        else
                ft_printf("Failed\n\tExpected : %d\n\tResult: %d\n", count_c, count);

	count_c = printf(" %c  %c  %c \n", '2', '1', 0);
        count = ft_printf(" %c  %c  %c \n", '2', '1', 0);
        if (count == count_c)
                ft_printf("Passed\n");
        else
                ft_printf("Failed\n\tExpected : %d\n\tResult: %d\n", count_c, count);

	count_c = printf(" %c  %c  %c \n", 'a', '\t', 'b');
        count = ft_printf(" %c  %c  %c \n", 'a', '\t', 'b');
        if (count == count_c)
                ft_printf("Passed\n");
        else
                ft_printf("Failed\n\tExpected : %d\n\tResult: %d\n", count_c, count);
*/
/*	count_c = printf(" %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
        count = ft_printf(" %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
        if (count == count_c)
                ft_printf("Passed\n");
        else
                ft_printf("Failed\n\tExpected : %d\n\tResult: %d\n", count_c, count);
*/
/*	count_c = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
       printf("\n");
       	count = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
       // if (count == count_c)
        //        ft_printf("Passed\n");
       // else
         //       ft_printf("Failed\n\tExpected : %d\n\tResult: %d\n", count_c, count);

*/

	//Testing Bonus
	// flag = -
        /*count = ft_printf("%-5c\n", 'w');
        printf("With printf \n");
        count_c = printf("%-5c\n", 'w');
        if (count == count_c)
                ft_printf("Passed\n");
        else
                ft_printf("Failed\nExpected : %d\nResult: %d\n", count_c, count);


	count = ft_printf("%-6s\n", "Left");
        printf("With printf \n");
        count_c = printf("%-6s\n", "Left");
        if (count == count_c)
                ft_printf("Passed\n");
        else
                ft_printf("Failed\nExpected : %d\nResult: %d\n", count_c, count);

	int value = 42;
        int *ptr = &value;

        printf("Address of the variable 'value': %-6p\n", (void*)ptr);
        ft_printf("Address of the variable 'value': %-6p\n", (void*)ptr);

        printf("Address of the variable 'value': %-6p\n", ((void*)0));
        ft_printf("Address of the variable 'value': %-6p\n", ((void*)0));

	count = ft_printf("%-6d\n", 42);
        printf("With printf \n");
        count_c = printf("%-6d\n", 42);
        if (count == count_c)
                ft_printf("Passed\n");
        else
                ft_printf("Failed\nExpected : %d\nResult: %d\n", count_c, count);

	count = ft_printf("%-6i\n", 42);
        printf("With printf \n");
        count_c = printf("%-6i\n", 42);
        if (count == count_c)
                ft_printf("Passed\n");
        else
                ft_printf("Failed\nExpected : %d\nResult: %d\n", count_c, count);

	count = ft_printf("%-6u\n", 42);
        printf("With printf \n");
        count_c = printf("%-6u\n", 42);
        if (count == count_c)
                ft_printf("Passed\n");
        else
                ft_printf("Failed\nExpected : %d\nResult: %d\n", count_c, count);

	count = ft_printf("Test lower hex : %-6x\n", 42);
        printf("With printf \n");
        count_c = printf("Test lower hex : %-6x\n", 42);
        if (count == count_c)
                ft_printf("Passed\n");
        else
                ft_printf("Failed\nExpected : %d\n Result: %d\n", count_c, count);

	count = ft_printf("Test lower hex : %-6X\n", 42);
        printf("With printf \n");
        count_c = printf("Test lower hex : %-6X\n", 42);
        if (count == count_c)
                ft_printf("Passed\n");
        else
                ft_printf("Failed\nExpected : %d\n Result: %d\n", count_c, count);

	count = ft_printf("Test percentage : %-6%\n");
        printf("With printf \n");
        //count_c = printf("Test percentage : %-6%\n");
        if (count == count_c)
                ft_printf("Passed\n");
        else
                ft_printf("Failed\nExpected : %d\n Result: %d\n", count_c, count);
        
        count = ft_printf("%10c", 'a');
        printf("\nWith printf \n");
        count_c = printf("%10c", 'a');
        fflush(stdout);
        if (count == count_c)
                ft_printf("Passed\n");
        else
                ft_printf("Failed\nExpected : %d\nResult: %d\n", count_c, count);
        
        //printf(" Here \n");
        
        count = ft_printf("%c", '\0');
        printf("\nWith printf \n");
        count_c = printf("%c", '\0');
        if (count == count_c)
                ft_printf("Passed\n");
        else
                ft_printf("Failed\nExpected : %d\nResult: %d\n", count_c, count);
		
	count = ft_printf("%p %p", 0, 0);
        printf("\nWith printf \n");
        count_c = printf("%p %p", 0, 0);
        fflush(stdout);
        if (count == count_c)
                ft_printf("Passed\nExpected : %d\nResult: %d\n", count_c, count);
        else
                ft_printf("Failed\nExpected : %d\nResult: %d\n", count_c, count);
*/

	ft_printf("With ft \n");
	count = ft_printf("%-1c%-2c%-3c ", 0, '1', '2');
        printf("\nWith printf \n");
        count_c = printf("%-1c%-2c%-3c ", 0, '1', '2');
        fflush(stdout);
        if (count == count_c)
                ft_printf("Passed\nExpected : %d\nResult: %d\n", count_c, count);
        else
                ft_printf("Failed\nExpected : %d\nResult: %d\n", count_c, count);

}

