/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_object.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 06:05:09 by rpicot        #+#    #+#                 */
/*   Updated: 2022/04/02 00:33:57 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/pipex.h"

void	fill_object(struct s_input *input, char **argv, char **paths)
{
	int	i;

	i = 0;
	fill_fd(&input->fd_data[1], input->mode);
	fill_fd(&input->fd_data[0], input->mode);
	while (i < 2)
	{
		format_arguments(&input->cmd[i], argv[i + 2]);
		fill_path(&input->cmd[i], paths);
		i++;
	}
}
