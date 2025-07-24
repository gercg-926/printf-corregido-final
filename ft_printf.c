/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:27:27 by marvin            #+#    #+#             */
/*   Updated: 2025/06/03 12:27:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int	process_format_specifier(const char *f, int *i, va_list args);
int	process_conversion(const char *f, int *i, va_list args);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		printed;

	va_start(args, format);
	i = 0;
	printed = 0;
	while (format[i])
		printed += process_conversion(format, &i, args);
	va_end(args);
	return (printed);
}

int	process_conversion(const char *f, int *i, va_list args)
{
	if (f[*i] == '%')
		return (process_format_specifier(f, i, args));
	return (write(1, &f[(*i)++], 1));
}

int	process_format_specifier(const char *f, int *i, va_list args)
{
	if (f[*i + 1] == 's')
		return (*i += 2, handle_s(args));
	if (f[*i + 1] == 'c')
		return (*i += 2, handle_c(args));
	if (f[*i + 1] == 'd' || f[*i + 1] == 'i')
		return (*i += 2, handle_d(args));
	if (f[*i + 1] == 'u')
		return (*i += 2, handle_u(args));
	if (f[*i + 1] == 'x')
		return (*i += 2, handle_x(args));
	if (f[*i + 1] == 'X')
		return (*i += 2, handle_x_upper(args));
	if (f[*i + 1] == 'p')
		return (*i += 2, handle_p(args));
	if (f[*i + 1] == '%')
		return (*i += 2, handle_percent());
	return (write(1, &f[(*i)++], 1));
}
