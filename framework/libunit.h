/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdhal <sdhal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:17:38 by ldick             #+#    #+#             */
/*   Updated: 2025/08/30 19:02:05 by sdhal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define RESET "\033[0m"

typedef struct s_unit_test
{
	char				*name;
	int					(*test_func)(void);
	struct s_unit_test	*next;
}						t_unit_test;

void					load_test(t_unit_test **list, char *name,
							int (*test_func)(void));
int						launch_tests(char *name, t_unit_test **list);
void					write_number(int number);
void					write_result(int passed, int total);
void					write_output(char *str1, char *str2, char *str3);

#endif