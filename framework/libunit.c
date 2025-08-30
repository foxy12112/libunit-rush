/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:48:53 by ldick             #+#    #+#             */
/*   Updated: 2025/08/30 14:50:25 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int launch_tests(char *name, t_unit_test **list)
{
	int total;
	int passed;
	int pid;
	int status;
	t_unit_test *tmp;
	
	tmp = *list;
	total = 0;
	passed = 0;
	while(tmp)
	{
		total++;
		pid = fork();
		if (pid == 0)
		{
			
		}
	}
}