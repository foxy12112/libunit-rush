/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tests.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 12:41:35 by ldick             #+#    #+#             */
/*   Updated: 2025/08/31 15:42:13 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TESTS_H
# define LIBFT_TESTS_H

# include "../framework/libunit.h"
# include "../functions/libft/libft.h"

int	atoi_launcher(void);
int	basic_test(void);
int	over_max_int(void);
int	under_min_int(void);
int	not_number(void);
int	str_is_null(void);
int	bus_error_test(void);
int	negative_number(void);
int	numbers_and_chars(void);
int	whitespaces(void);
int	hex(void);
int	empty_str(void);
int	int_max(void);
int	int_min(void);
int	invalid_sequence(void);
int	only_whitespace(void);
int	space_between_sign_and_digit(void);

#endif