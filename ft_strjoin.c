/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcasas-g <gcasas-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:48:16 by gcasas-g          #+#    #+#             */
/*   Updated: 2025/05/06 10:34:27 by gcasas-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final;
	int		i;
	int		j;
	int		l;

	i = 0;
	j = 0;
	l = 0;
	final = (char *) malloc((ft_strlen (s1) + ft_strlen(s2) + 1)
			* sizeof(char));
	if (!final)
		return (NULL);
	while (s1[i])
	{
		final[l++] = s1[i++];
	}
	while (s2[j])
	{
		final[l++] = s2[j++];
	}
	final[l] = 0;
	return (final);
}
