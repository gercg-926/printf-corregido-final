/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:45:08 by marvin            #+#    #+#             */
/*   Updated: 2025/06/03 13:45:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"
#include "libft.h"
#include <stdlib.h>

char		*ft_xtoa_ulong(unsigned long n);
char		*ft_xtoa(unsigned int n, int uppercase);
char		*ft_utoa(unsigned int n);
static int	ft_uintlen(unsigned int n);

int	handle_s(va_list args)
{
	char	*str;
	int		count;

	str = va_arg(args, char *);
	if (!str)
		return (write(1, "(null)", 6));
	count = write(1, str, ft_strlen(str));
	return (count);
}

int	handle_c(va_list	args)
{
	char	c;

	c = (char)va_arg(args, int);
	return (write(1, &c, 1));
}

int	handle_d(va_list args)
{
	int		n;
	char	*str;
	int		count;

	n = va_arg(args, int);
	str = ft_itoa(n);
	if (!str)
		return (0);
	count = write(1, str, ft_strlen(str));
	free(str);
	return (count);
}

int	handle_u(va_list arg)
{
	unsigned int	n;
	char			*str;
	int				count;

	n = va_arg(args, unsigned int);
	str = ft_utoa(n);
	if (!str)
		return (0);
	count = write(1, str, ft_strlen(str));
	free(str);
	return (count);
}

int	handle_x(va_list args)
{
	unsigned int	n;
	char			*hex_str;
	int				count;

	n = va_arg(args, unsigned int);
	hex_str = ft_xtoa(n, 0);
	if (!hex_str)
		return (0);
	count = write(1, hex_str, ft_strlen(hex_str));
	free(hex_str);
	return (count);
}

int	handle_x_upper(va_list args)
{
	unsigned int	n;
	char			*hex_str;
	int				count;

	n = va_arg(args, unsigned int);
	hex_str = ft_xtoa(n, 1);
	if (!hex_str)
		return (0);
	count = write(1, hex_str, ft_strlen(hex_str));
	free(hex_str);
	return (count);
}

int	handle_p(va_list	args)
{
	void			*ptr;
	unsigned long	addr;
	char			*hex_str;
	int				count;

	ptr = va_arg(args, void *);
	if (!ptr)
		return (write(1, "(nil)", 5));
	addr = (unsigned long)ptr;
	hex_str = ft_xtoa_ulong(addr);
	if (!hex_str)
		return (0);
	count = write(1, "0x", 2);
	count += write(1, hex_str, ft_strlen(hex_str));
	free(hex_str);
	return (count);
}

int	handle_percent(void)
{
	return (write(1, "%", 1));
}
