/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:21:16 by ldick             #+#    #+#             */
/*   Updated: 2025/08/30 17:29:40 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework/libunit.h"

int	strlen_launcher(void);

int	main(void)
{
	int	result;

	result = strlen_launcher();
	return (result);
}
