/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_display.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 06:05:51 by rpicot        #+#    #+#                 */
/*   Updated: 2022/04/02 01:47:46 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/pipex.h"

static void	init_error_lookup(char **lookup)
{
	lookup[0] = "wrong number of arguments";
	lookup[1] = "problem with malloc-ing the paths";
	lookup[2] = "couldn't find he paths in the environement variable";
	lookup[3] = "the pipe was not created properly";
	lookup[4] = "couldn't open the file";
	lookup[5] = "couldn't find the command";
	lookup[6] = "one of the commands field is empty";
	lookup[9] = 0;
}

void	error_display(int code, char *string)
{
	char	*lookup[10];

	init_error_lookup(lookup);
	ft_putstr(lookup[code]);
	ft_putstr(string);
	exit(EXIT_FAILURE);
}

void	process_error(int code, char *string)
{
	if (code == 1)
		perror(ft_strjoin("following cmd execution failed ", string));
	else if (code == 0)
		perror("the fork failed");
	else if (code == 4)
		perror("piping process failed");
	exit(EXIT_FAILURE);
}
