/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:32:58 by afrangio          #+#    #+#             */
/*   Updated: 2020/05/12 03:56:56 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_itoa_null(intmax_t n)
{
	uint8_t	sign;
	char	*ptr;
	char	tmp[33];

	ptr = tmp;
	ptr += sizeof(tmp);
	sign = (n < 0);
	*--ptr = 0;
	if (!n)
	{
		*--ptr = '0';
		return (strdup(ptr));
	}
	n = n * (n > 0) - n * (n < 0);
	while (n)
	{
		*--ptr="0123456789"[n % 10];
		n /= 10;
	}
	if (sign)
		*--ptr = '-';
	return (strdup(ptr));
}

char			*ft_itoa(intmax_t n, size_t size, char *r)
{
	uint8_t	sign;

	sign = (n < 0);
	if(!r)
		return ft_itoa_null(n);
	r += size - 1;
	*--r = 0;
	if (!n)
	{
		*--r = '0';
		return (r);
	}
	n = n * (n > 0) - n * (n < 0);
	while (n)
	{
		*--r="0123456789"[n % 10];
		n /= 10;
	}
	if (sign)
		*--r = '-';
	return (r);
}
