/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/23 16:26:26 by rpicot        #+#    #+#                 */
/*   Updated: 2022/03/11 18:17:26 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/pipex.h"

int	ft_strlen(const char *s)
{
	char	*str;

	str = (char *)s;
	while (*s)
		s++;
	return (s - str);
}
