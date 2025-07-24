/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcasas-g <gcasas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:26:11 by gcasas-g          #+#    #+#             */
/*   Updated: 2025/04/25 11:22:20 by gcasas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*temp_dst;
	char	*temp_src;

	if (!dst && !src && n > 0)
		return (NULL);
	temp_dst = (char *) dst;
	temp_src = (char *) src;
	if (dst > src)
	{
		while (n-- > 0)
		{
			temp_dst[n] = temp_src[n];
		}
	}
	else
	{
		ft_memcpy(dst, src, n);
	}
	return (dst);
}
