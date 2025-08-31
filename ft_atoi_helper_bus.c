/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_helper_bus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:03:42 by ldick             #+#    #+#             */
/*   Updated: 2025/08/31 15:38:50 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "real-tests/libft_tests.h"

#if defined(__i386__)
# undef FLAG
# define FLAG 0
#elif defined(__x86_64__)
# undef FLAG
# define FLAG 1
#endif

char	*helper(void)
{
	char	arr[4];
	int		*ptr;

	if (FLAG == 1)
		asm("pushf\norl $0x40000,(%rsp)\npopf");
	else
		asm("pushf\norl $0x40000,(%esp)\npopf");
	ptr = (int *)(arr + 1);
	*ptr = 42;
	return ((char *)ptr);
}
