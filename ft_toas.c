/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:24:03 by marvin            #+#    #+#             */
/*   Updated: 2025/06/16 14:24:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"
#include "libft.h"
#include <stdlib.h>

char	*ft_xtoa_ulong(unsigned long n)
{
	char			*hexbase;
	char			*str;
	unsigned long	tmp;
	int				len;

	hexbase = "0123456789abcdef";
	tmp = n;
	len = 1;
	while (tmp /= 16)
		len++;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = hexbase[n % 16];
		n /= 16;
	}
	return (str);
}

char	*ft_xtoa(unsigned int n, int uppercase)
{
	char			*hexbase;
	char			*str;
	unsigned int	tmp;
	int				len;

	if (uppercase)
		hexbase = "0123456789ABCDEF";
	else
		hexbase = "0123456789abcdef";
	tmp = n;
	len = 1;
	while (tmp /= 16)
		len++;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	while (len--)
	{
		str[len] = hexbase[n % 16];
		n /= 16;
	}
	return (str);
}

char	*ft_utoa(unsigned int n)
{
	char	*str;
	int		len;

	len = ft_uintlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

static int	ft_uintlen(unsigned int n)
{
	int	len;

	len = 1;
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}
