/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 13:39:21 by ldick             #+#    #+#             */
/*   Updated: 2025/08/31 15:41:53 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"

int	atoi_launcher(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	load_test(&testlist, "basic_test", &basic_test);
	load_test(&testlist, "over_max_int", &over_max_int);
	load_test(&testlist, "under_min_int", &under_min_int);
	load_test(&testlist, "not_number", &not_number);
	load_test(&testlist, "str_is_null", &str_is_null);
	load_test(&testlist, "bus_error_test", &bus_error_test);
	load_test(&testlist, "negative_number", &negative_number);
	load_test(&testlist, "numbers_and_chars", &numbers_and_chars);
	load_test(&testlist, "whitespaces", &whitespaces);
	load_test(&testlist, "hex", &hex);
	load_test(&testlist, "empty_str", &empty_str);
	load_test(&testlist, "int_max", &int_max);
	load_test(&testlist, "int_min", &int_min);
	load_test(&testlist, "inavlid_sequence", &invalid_sequence);
	load_test(&testlist, "only_whitespace", &only_whitespace);
	load_test(&testlist, "space_between_sign_and_digit",
		&space_between_sign_and_digit);
	launch_tests("ATOI", &testlist);
	return (0);
}
