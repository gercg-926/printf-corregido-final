/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:45:45 by marvin            #+#    #+#             */
/*   Updated: 2025/06/03 13:45:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

int		ft_printf(const char *format, ...);
int		handle_c(va_list args);
int		handle_s(va_list args);
int		handle_d(va_list args);
int		handle_u(va_list args);
int		handle_x(va_list args);
int		handle_x_upper(va_list args);
int		handle_p(va_list args);
int		handle_percent(void);
int		process_conversion(const char *f, int *i, va_list args);
int		process_format_specifier(const char *f, int *i, va_list args);

char	*ft_utoa(unsigned int n);
char	*ft_xtoa(unsigned int n, int uppercase);
char	*ft_xtoa_ulong(unsigned long n);

#endif