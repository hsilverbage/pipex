/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:37:42 by hsilverb          #+#    #+#             */
/*   Updated: 2022/12/27 11:03:33 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*char_dest;
	unsigned char	*char_src;

	char_dest = (unsigned char *) dest;
	char_src = (unsigned char *) src;
	if (!dest && !src)
		return (0);
	if (char_src < char_dest)
	{
		while (len--)
		{
			char_dest[len] = char_src[len];
		}
	}
	else
		ft_memcpy(dest, src, len);
	return (dest);
}
