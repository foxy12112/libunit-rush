/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:17:38 by ldick             #+#    #+#             */
/*   Updated: 2025/08/30 17:58:49 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define YELLOW	"\033[33m"
# define RESET	"\033[0m"

typedef struct s_unit_test
{
	char				*name;
	int					(*test_func)(void);
	struct s_unit_test	*next;
}				t_unit_test;

void	load_test(t_unit_test **list, char *name, int (*test_func)(void));
int		launch_tests(char *name, t_unit_test **list);

#endif