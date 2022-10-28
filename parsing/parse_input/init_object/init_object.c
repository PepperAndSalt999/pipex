/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_object.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 06:05:15 by rpicot        #+#    #+#                 */
/*   Updated: 2022/03/13 09:54:45 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/pipex.h"

void	init_object(struct s_input *input, char **argv)
{
	input->fd_data[0].open_code = O_RDONLY;
	input->fd_data[1].open_code = O_RDWR | O_CREAT | O_TRUNC;
	input->mode = 0644;
	input->fd_data[0].file = argv[1];
	input->fd_data[1].file = argv[4];
}
