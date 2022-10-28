/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_paths.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 06:05:19 by rpicot        #+#    #+#                 */
/*   Updated: 2022/04/02 00:02:47 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/pipex.h"

char	**init_paths(char **envp)
{
	char	**paths;
	char	*temp;

	while (*envp)
	{
		if (!ft_strncmp("PATH", *envp, 4))
		{
			paths = ft_split(*envp, ':');
			if (!paths)
				error_display(1, "");
			temp = paths[0];
			paths[0] = ft_strtrim(paths[0], "PATH=");
			free(temp);
			if (!paths[0])
				error_display(1, "");
			return (paths);
		}
		envp++;
	}
	error_display(2, "");
	return (NULL);
}
