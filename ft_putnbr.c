/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awora <awora@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:55:33 by awora             #+#    #+#             */
/*   Updated: 2022/04/15 15:57:15 by awora            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, int *value)
{
	if (nb == -2147483648)
	{
		*value += ft_putchar('-');
		*value += ft_putchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		*value += ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, value);
		nb = nb % 10;
	}
	if (nb < 10)
	{
		*value += ft_putchar(nb + 48);
	}	
}
