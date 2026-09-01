/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhannsil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 13:19:52 by jhannsil          #+#    #+#             */
/*   Updated: 2026/06/12 13:19:54 by jhannsil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	s3_len;

	if (!s1 || !s2)
		return (NULL);
	s3_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	s3 = (char *)ft_calloc(s3_len, sizeof(char));
	if (!s3)
		return (NULL);
	ft_strlcpy(s3, s1, s3_len);
	ft_strlcat(s3, s2, s3_len);
	return (s3);
}
