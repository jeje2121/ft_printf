/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usignnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awora <awora@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:26:43 by awora             #+#    #+#             */
/*   Updated: 2022/04/15 15:57:52 by awora            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_usignnbr(unsigned int nb, int *valeur)
{
	if (nb < 0)
		nb = (4294967295 - nb) + 1;
	if (nb > 9)
	{
		ft_usignnbr(nb / 10, valeur);
		nb = nb % 10;
	}
	if (nb < 10)
	{
		*valeur += ft_putchar(48 + nb);
	}
}
