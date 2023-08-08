/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 05:42:03 by henrik            #+#    #+#             */
/*   Updated: 2022/12/27 10:14:24 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_hexa(char *base, unsigned int nbr)
{
	if (nbr < 16)
		return (ft_putchar(base[nbr % 16]));
	else
		return (ft_putnbr_hexa(base, (nbr / 16)) + ft_putchar(base[nbr % 16]));
}

int	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
		return (ft_putstr("-2147483648"));
	else if (nbr < 0)
		return (ft_putchar('-') + ft_putnbr(nbr * -1));
	else if (nbr >= 0 && nbr <= 9)
		return (ft_putchar(nbr + '0'));
	else
		return (ft_putnbr(nbr / 10) + ft_putchar(nbr % 10 + '0'));
}

int	ft_putnbr_unsigned(unsigned int nbr)
{
	if (nbr <= 9)
		return (ft_putchar(nbr + '0'));
	else
		return (ft_putnbr(nbr / 10) + ft_putchar(nbr % 10 + '0'));
}
