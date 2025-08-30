/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_very_long_line_test.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldick <ldick@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:07:44 by ldick             #+#    #+#             */
/*   Updated: 2025/08/30 17:49:58 by ldick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str);

int	very_long_line_test(void)
{
	if (ft_strlen("Lorem ipsum dolor sit amet, consectetur adipiscing elit,\
			sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,\
			quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute\
			irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. \
			Excepteur sint occaecat cupidatat non proident,\
			sunt in culpa qui officia deserunt mollit anim id est laborum. Sed ut perspiciatis unde omnis\
			iste natus error sit voluptatem accusantium doloremque laudantium,\
			totam rem aperiam,\
			eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt\
			explicabo. Nemo enim ipsam voluptatem quia voluptas sit aspernatur aut odit aut fugit,\
			sed quia consequuntur magni dolores eos qui ratione voluptatem sequi nesciunt. Neque porro quisquam est,\
			qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit,\
			sed quia non numquam eius modi tempora incidunt ut labore et dolore magnam aliquam quaerat\
					voluptatem.") == 1042)
		return (0);
	else
		return (-1);
}
