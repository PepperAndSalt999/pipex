/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_path.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 06:05:28 by rpicot        #+#    #+#                 */
/*   Updated: 2022/04/02 01:35:13 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/pipex.h"

void	fill_path(struct s_cmd *cmd, char **paths)
{
	char	*to_free;
	char	*temp;

	while (*paths)
	{
		to_free = ft_strjoin(*paths, "/");
		temp = ft_strjoin(to_free, cmd->path);
		free(to_free);
		if (!temp)
			error_display(1, "");
		if (access(temp, X_OK) == 0)
		{
			free(cmd->path);
			cmd->path = temp;
			break ;
		}
		free(temp);
		paths++;
	}
	if (!*paths)
		error_display(5, cmd->path);
}
