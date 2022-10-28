/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_fd.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 06:05:32 by rpicot        #+#    #+#                 */
/*   Updated: 2022/03/23 16:01:39 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/pipex.h"

void	fill_fd(struct s_fd_data *fd_data, mode_t mode)
{
	fd_data->fd = open(fd_data->file, fd_data->open_code, mode);
	if (fd_data->fd < 0)
		error_display(4, fd_data->file);
}
