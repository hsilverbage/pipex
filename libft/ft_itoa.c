/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:41:52 by hsilverb          #+#    #+#             */
/*   Updated: 2023/01/06 19:19:49 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len_n(int n)
{
	size_t	i;

	i = 0;
	if (n == -2147483648)
		i = 11;
	else if (n < 0)
	{
		n *= -1;
		i++;
	}
	if (n == 0)
		i++;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

char	*ft_int_min(char *res)
{
	int	i;
	int	k;

	i = 11;
	k = 147483648;
	res[1] = '2';
	res[i] = '\0';
	i--;
	while (k > 0)
	{
		res[i] = ((k % 10) + 48);
		k = k / 10;
		i--;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		temp;

	i = ft_len_n(n);
	temp = n;
	res = malloc(sizeof(char) * (i));
	if (!res)
		return (NULL);
	if (n == -2147483648)
		res = ft_int_min(res);
	res[--i] = '\0';
	i--;
	if (n < 0)
		n *= -1;
	while (i >= 0 && temp != -2147483648)
	{
		res[i] = ((n % 10) + 48);
		n = n / 10;
		i--;
	}
	if (temp < 0)
		res[0] = '-';
	return (res);
}
