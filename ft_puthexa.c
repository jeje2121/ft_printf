/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awora <awora@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:50:36 by awora             #+#    #+#             */
/*   Updated: 2022/04/15 18:41:44 by awora            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	lower16(int *valeur, char base, char *hexanum, int *j)
{
	hexanum[*j++] = base;
	*valeur += ft_putchar(hexanum[0]);
	return (*valeur);
}

int	ft_puthexa(unsigned int quotient, char *base)
{
	int				j;
	unsigned int	remainder;
	char			hexanum[100];
	int				valeur;

	valeur = 0;
	j = 0;
	if (quotient < 16)
		return (lower16(&valeur, base[quotient], hexanum, &j));
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
	return (valeur);
}
