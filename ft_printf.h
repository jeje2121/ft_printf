/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awora <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:33:26 by awora             #+#    #+#             */
/*   Updated: 2022/04/19 15:44:43 by awora            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
void	ft_putnbr(int nb, int *value);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_puthexa(unsigned int nbr, char *base);
int		ft_adressp(unsigned long long quotient, char *base);
void	ft_usignnbr(unsigned int nb, int *valeur);

#endif
