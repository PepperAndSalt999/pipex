/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   use_pipeline.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 06:05:37 by rpicot        #+#    #+#                 */
/*   Updated: 2022/03/24 01:30:47 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/pipex.h"

void	use_pipeline(struct s_input *input)
{
	pid_t	id;
	int		status;

	id = fork();
	if (id < 0)
		process_error(0, "");
	else if (id == 0)
		piping_details(&input->fd_data[0].pipeline, &input->cmd[0]);
	else
	{
		waitpid(-1, &status, 0);
		if (!WIFEXITED(status))
			process_error(3, "");
		piping_details(&input->fd_data[1].pipeline, &input->cmd[1]);
	}
}

void	piping_details(struct s_pipe_config *pipeline, struct s_cmd *cmd)
{
	if (dup2(pipeline->read_from, STDIN_FILENO) == -1
		|| dup2(pipeline->write_to, STDOUT_FILENO) == -1)
		process_error(4, "");
	closing_loop(pipeline->to_close);
	execve(cmd->path, cmd->arguments, NULL);
	process_error(1, ft_strjoin(cmd->path, cmd->arguments[1]));
}
