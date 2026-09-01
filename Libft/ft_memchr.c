/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhannsil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 13:17:08 by jhannsil          #+#    #+#             */
/*   Updated: 2026/06/12 13:17:09 by jhannsil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	p1;
	unsigned char	*p;
	size_t			i;

	i = 0;
	p1 = (unsigned char)c;
	p = (unsigned char *)s;
	while (i < n)
	{
		if (p[i] == p1)
			return ((void *)&p[i]);
		i++;
	}
	return (0);
}
