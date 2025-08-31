/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:52:54 by sdhal             #+#    #+#             */
/*   Updated: 2025/08/31 12:51:32 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	write_number(int number)
{
	char	digit;

	if (number >= 10)
		write_number(number / 10);
	digit = (number % 10) + '0';
	write(1, &digit, 1);
}

void	write_result(int passed, int total)
{
	write_number(passed);
	write(1, "/", 1);
	write_number(total);
	write(1, " tests passed\n", 15);
}

void	write_output(char *str1, char *str2, char *str3)
{
	write(1, YELLOW, 5);
	while (*str1)
		write(1, str1++, 1);
	write(1, ": ", 2);
	write(1, RESET, 4);
	while (*str2)
		write(1, str2++, 1);
	write(1, ": ", 2);
	if (str3[1] == 'O')
		write(1, GREEN, 5);
	else
		write(1, RED, 5);
	while (*str3)
		write(1, str3++, 1);
	write(1, "\n", 1);
	write(1, RESET, 4);
}
