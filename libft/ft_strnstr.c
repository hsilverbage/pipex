/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:15:57 by hsilverb          #+#    #+#             */
/*   Updated: 2022/11/29 16:02:49 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	k = 0;
	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while ((haystack[i] && needle[i]) && (len != 0))
	{
		while (haystack[i] == needle[i] && len != 0)
		{
			i++;
			k++;
			len--;
			if (needle[i] == '\0')
				return ((char *)haystack);
			if (haystack[i] != needle[i])
				len += i;
		}
		haystack++;
		i = 0;
		len--;
	}
	return (NULL);
}
