/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/22 09:10:07 by rpicot        #+#    #+#                 */
/*   Updated: 2022/03/24 01:36:37 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/pipex.h"

void	ft_putstr(char *string)
{
	int	i;

	i = 0;
	write(1, "----", 1);
	while (string[i])
	{
		write(1, &string[i], 1);
		i++;
	}
	write(1, "----", 1);
}
