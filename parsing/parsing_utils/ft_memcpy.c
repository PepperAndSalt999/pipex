/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/23 16:25:17 by rpicot        #+#    #+#                 */
/*   Updated: 2022/03/11 18:17:43 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/pipex.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*sourc;
	int				i;

	i = 0;
	dest = (unsigned char *)dst;
	sourc = (unsigned char *)src;
	if (!dest && !sourc)
		return (NULL);
	while (n)
	{
		dest[i] = sourc[i];
		n--;
		i++;
	}
	return (dst);
}
