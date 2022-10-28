/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_pipeline.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 06:04:54 by rpicot        #+#    #+#                 */
/*   Updated: 2022/03/23 15:30:49 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/pipex.h"

void	init_pipeline(struct s_fd_data *infile, struct s_fd_data *outfile)
{
	int	pipeline[2];

	if (pipe(pipeline) == -1)
		error_display(3, "");
	infile->pipeline.to_close[0] = pipeline[0];
	infile->pipeline.to_close[1] = infile->fd;
	infile->pipeline.read_from = infile->fd;
	infile->pipeline.write_to = pipeline[1];
	outfile->pipeline.to_close[0] = pipeline[1];
	outfile->pipeline.to_close[1] = outfile->fd;
	outfile->pipeline.read_from = pipeline[0];
	outfile->pipeline.write_to = outfile->fd;
}
