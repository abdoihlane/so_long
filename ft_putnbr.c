/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabibi- <ahabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 23:26:03 by ahabibi-          #+#    #+#             */
/*   Updated: 2025/02/27 23:42:51 by ahabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		i = 11;
		return (i);
	}
	else if (n < 0)
	{
		i += ft_putchar('-');
		n = -n;
		i += ft_putnbr(n);
	}
	else if (n > 9)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	else
		i += ft_putchar(n % 10 + '0');
	return (i);
}
