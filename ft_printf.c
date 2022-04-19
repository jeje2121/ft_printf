/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awora <awora@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:20:51 by awora             #+#    #+#             */
/*   Updated: 2022/04/19 15:25:20 by awora            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include "libft.h"

int	read_after_percent(char s, va_list list)
{
	int	valeur;

	valeur = 0;
	if (s == 's')
		valeur += ft_putstr(va_arg(list, char *));
	else if (s == 'c')
		valeur += ft_putchar(va_arg(list, int));
	else if (s == 'x')
		valeur += ft_puthexa(va_arg(list, unsigned int), "0123456789abcdef");
	else if (s == 'd' || s == 'i')
		ft_putnbr(va_arg(list, int), &valeur);
	else if (s == 'X')
		valeur += ft_puthexa(va_arg(list, unsigned int), "0123456789ABCDEF");
	else if (s == 'u')
		ft_usignnbr(va_arg(list, unsigned int), &valeur);
	else if (s == 'p')
		valeur += ft_adressp(va_arg(list, unsigned long long), \
				"0123456789abcdef");
	else if (s == '%')
		valeur += ft_putchar('%');
	return (valeur);
}

int	ft_printf(const char *str, ...)
{
	int		valeur;
	int		i;
	va_list	list;

	valeur = 0;
	va_start(list, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			valeur += read_after_percent(str[i], list);
		}
		else
			valeur += write(1, &str[i], 1);
		i++;
	}
	return (valeur);
}
