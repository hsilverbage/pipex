/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:23:02 by hsilverb          #+#    #+#             */
/*   Updated: 2023/01/06 19:07:57 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*s1;

	if (count == 0 || size == 0)
		return (malloc(0));
	if ((INT_MAX / count) < size)
		return (NULL);
	s1 = malloc(count * size);
	if (!s1)
		return (NULL);
	ft_bzero(s1, size * count);
	return (s1);
}
