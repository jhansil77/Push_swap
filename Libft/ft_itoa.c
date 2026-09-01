/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhannsil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 13:14:37 by jhannsil          #+#    #+#             */
/*   Updated: 2026/06/12 13:14:38 by jhannsil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_int(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		len;
	long	new_nb;

	new_nb = n;
	len = ft_len_int(new_nb);
	number = ft_calloc((len + 1), sizeof(char));
	if (number == 0)
		return (0);
	number[len] = '\0';
	if (new_nb == 0)
		number[0] = '0';
	if (new_nb < 0)
	{
		number[0] = '-';
		new_nb = -new_nb;
	}
	while (new_nb > 0)
	{
		len--;
		number[len] = (new_nb % 10) + '0';
		new_nb = new_nb / 10;
	}
	return (number);
}
