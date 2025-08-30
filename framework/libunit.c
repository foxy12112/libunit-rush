/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdhal <sdhal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:48:53 by ldick             #+#    #+#             */
/*   Updated: 2025/08/30 18:54:00 by sdhal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

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

int	run_test(t_unit_test *test)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		if (test->test_func() == 0)
			exit(0);
		exit(255);
	}
	return (pid);
}

void	handle_status(int status, char *name, char *test_name)
{
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 0)
			write_output(name, test_name, "[OK]");
		else
			write_output(name, test_name, "[KO]");
	}
	else if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGSEGV)
			write_output(name, test_name, "[SIGSEGV]");
		else if (WTERMSIG(status) == SIGBUS)
			write_output(name, test_name, "[SIGBUS]");
	}
}

int	launch_tests(char *name, t_unit_test **list)
{
	int			total;
	int			passed;
	int			status;
	t_unit_test	*tmp;

	total = 0;
	passed = 0;
	tmp = *list;
	while (tmp)
	{
		total++;
		status = 0;
		run_test(tmp);
		wait(&status);
		handle_status(status, name, tmp->name);
		if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
			passed++;
		tmp = tmp->next;
	}
	write_result(passed, total);
	if (passed == total)
		return (0);
	return (1);
}
