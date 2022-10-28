/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   close_pipeline.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 06:05:41 by rpicot        #+#    #+#                 */
/*   Updated: 2022/03/13 06:10:06 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/pipex.h"

void	closing_loop(int *to_close)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		close(to_close[i]);
		i++;
	}
}
