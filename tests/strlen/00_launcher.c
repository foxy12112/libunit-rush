/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:47:01 by ldick             #+#    #+#             */
/*   Updated: 2025/08/30 17:33:58 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../framework/libunit.h"

int	basic_test(void);
int	null_test(void);
int	very_long_line_test(void);
int	not_null_terminated_test(void);

int	strlen_launcher(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	load_test(&testlist, "Basic test", &basic_test);
	load_test(&testlist, "NULL test", &null_test);
	load_test(&testlist, "very long line test", &very_long_line_test);
	load_test(&testlist, "not null terminated test", &not_null_terminated_test);
	launch_tests("STRLEN", &testlist);
	return (1);
}
