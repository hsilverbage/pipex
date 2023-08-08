/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:48:20 by hsilverb          #+#    #+#             */
/*   Updated: 2022/11/30 16:05:14 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	c = (char) c;
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		else
			i++;
	}
	if (str[i] == '\0' && c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}
