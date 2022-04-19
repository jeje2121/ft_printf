/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adressp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awora <awora@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:29:26 by awora             #+#    #+#             */
/*   Updated: 2022/04/19 15:31:25 by awora            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	lowerthan16(int *valeur, char *hexanum, char base, int *j)
{
	hexanum[*j++] = base;
	*valeur += ft_putchar(hexanum[0]);
	return (*valeur + 2);
}

int	ft_adressp(unsigned long long quotient, char *base)
{
	int					j;
	unsigned long long	remainder;
	char				hexanum[100];
	int					valeur;

	valeur = 0;
	j = 0;
	write(1, "0x", 2);
	if (quotient < 16)
		return (lowerthan16(&valeur, hexanum, base[quotient], &j));
	while (quotient >= 16)
	{
		remainder = quotient % 16;
		hexanum[j++] = base[remainder];
		quotient = quotient / 16;
	}
	if (quotient < 16)
		hexanum[j++] = base[quotient];
	j = j - 1;
	while (j >= 0)
	{
		valeur += ft_putchar(hexanum[j]);
		j--;
	}
	return (valeur + 2);
}
