/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:48:53 by ldick             #+#    #+#             */
/*   Updated: 2025/08/30 18:09:55 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static void	write_number(int number)
{
	char	digit;

	if (number >= 10)
		write_number(number / 10);
	digit = (number % 10) + '0';
	write(1, &digit, 1);
}

static void	write_result(int passed, int total)
{
	write_number(passed);
	write(1, "/", 1);
	write_number(total);
	write(1, " tests checked\n", 16);
}

static void	write_output(char *str1, char *str2, char *str3)
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

void	load_test(t_unit_test **list, char *name, int (*test_func)(void))
{
	t_unit_test	*temp;
	t_unit_test	*new;

	new = malloc(sizeof(t_unit_test));
	if (!new)
		return ;
	new->name = name;
	new->test_func = test_func;
	new->next = NULL;
	if (!*list)
		*list = new;
	else
	{
		temp = *list;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

int	launch_tests(char *name, t_unit_test **list)
{
	int			total;
	int			passed;
	int			pid;
	int			status;
	t_unit_test	*tmp;

	tmp = *list;
	total = 0;
	passed = 0;
	while (tmp)
	{
		total++;
		pid = fork();
		if (pid == 0)
		{
			if (tmp->test_func() == 0)
				exit(0);
			else
				exit(255);
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
			{
				write_output(name, tmp->name, "[OK]");
				passed++;
			}
			else if (WIFEXITED(status) && WEXITSTATUS(status) == 255)
				write_output(name, tmp->name, "[KO]");
			else if (WIFSIGNALED(status))
			{
				if (WTERMSIG(status) == SIGSEGV)
					write_output(name, tmp->name, "[SIGSEGV]");
				else if (WTERMSIG(status) == SIGBUS)
					write_output(name, tmp->name, "[SIGBUS]");
			}
		}
		tmp = tmp->next;
	}
	write_result(passed, total);
	if (passed == total)
		return (0);
	return (1);
}
