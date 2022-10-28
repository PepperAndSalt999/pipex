/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 06:04:40 by rpicot        #+#    #+#                 */
/*   Updated: 2022/04/02 01:47:38 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	struct s_input		input;
	char				**paths;

	if (argc == 5)
	{
		paths = init_paths(envp);
		init_object(&input, argv);
		fill_object(&input, argv, paths);
		init_pipeline(&input.fd_data[0], &input.fd_data[1]);
		use_pipeline(&input);
	}
	else
		error_display(0, "");
	return (0);
}
