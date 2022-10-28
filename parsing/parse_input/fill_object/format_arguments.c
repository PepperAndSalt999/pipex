/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format_arguments.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 06:06:08 by rpicot        #+#    #+#                 */
/*   Updated: 2022/04/02 01:51:51 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/pipex.h"

void	format_arguments(struct s_cmd *cmd, char *texte)
{
	char	**split_result;
	char	*temp;

	if (!texte)
		error_display(6, "");
	split_result = ft_split(texte, ' ');
	if (!split_result)
		error_display(1, "");
	cmd->path = split_result[0];
	if (split_result[1])
	{
		temp = split_result[1];
		split_result[1] = ft_strtrim(temp, "'");
		free(temp);
	}
	if (!(cmd->path))
		error_display(1, "");
	cmd->arguments = split_result;
	if (!split_result[1])
		cmd->arguments[1] = NULL;
}
