/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:05:06 by hsilverb          #+#    #+#             */
/*   Updated: 2022/12/27 11:04:34 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*cast_s1;
	unsigned char	*cast_s2;

	cast_s1 = (unsigned char *)s1;
	cast_s2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((s1 || s2) && i + 1 < n)
	{
		if (cast_s1[i] == cast_s2[i])
			i++;
		else
			return (cast_s1[i] - cast_s2[i]);
	}
	return (cast_s1[i] - cast_s2[i]);
}
