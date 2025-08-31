/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_bus_error_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 13:28:23 by ldick             #+#    #+#             */
/*   Updated: 2025/08/31 15:41:49 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_tests.h"
#include <stdint.h>

char	*helper(void);

int	bus_error_test(void)
{
	if (ft_atoi(helper()))
		return (0);
	else
		return (-1);
}
