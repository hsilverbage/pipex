/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 06:09:50 by henrik            #+#    #+#             */
/*   Updated: 2022/12/27 10:14:24 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

int	ft_print_address(void *address)
{
	unsigned long int	address_cast;
	int					i;
	char				str[17];
	char				*base;
	int					len;

	address_cast = (unsigned long int) address;
	i = 0;
	base = "0123456789abcdef";
	if (!address)
		return (ft_putstr("0x0"));
	while (address_cast)
	{
		str[i] = base[address_cast % 16];
		address_cast /= 16;
		i++;
	}
	i--;
	len = ft_putstr("0x");
	while (i >= 0)
		len += ft_putchar(str[i--]);
	return (len);
}

int	ft_format(va_list args, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (c == 'd')
		len += ft_putnbr(va_arg(args, int));
	else if (c == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		len += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (c == 'p')
		len += ft_print_address(va_arg(args, void *));
	else if (c == 'x')
		len += ft_putnbr_hexa("0123456789abcdef", va_arg(args, unsigned int));
	else if (c == 'X')
		len += ft_putnbr_hexa("0123456789ABCDEF", va_arg(args, unsigned int));
	else
		len += ft_putchar(c);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		i;

	va_start(args, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_format(args, str[i]);
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	return (len);
}
