/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:40:49 by hsilverb          #+#    #+#             */
/*   Updated: 2022/12/13 12:20:45 by henrik           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	len = ft_strlen(s);
	if (!s)
		return (NULL);
	str = malloc(sizeof(char) * (len +1));
	if (!str)
		return (NULL);
	while (len--)
	{
		str[i] = (f(i, s[i]));
		i++;
	}
	str[i] = '\0';
	return (str);
}
