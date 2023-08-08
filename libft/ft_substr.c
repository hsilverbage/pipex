/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:10:55 by hsilverb          #+#    #+#             */
/*   Updated: 2022/12/27 17:37:10 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_string;
	size_t	size;

	size = ft_strlen(s);
	if (start >= size)
		return (ft_strdup(""));
	s += start;
	if (size - start < len)
		len = size - start;
	new_string = malloc(sizeof(char) * (len + 1));
	if (new_string == NULL)
		return (NULL);
	ft_strlcpy(new_string, s, len + 1);
	return (new_string);
}
