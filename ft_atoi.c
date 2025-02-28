/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabibi- <ahabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:40:49 by ahabibi-          #+#    #+#             */
/*   Updated: 2025/02/27 23:42:44 by ahabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_overflow(unsigned long long r, int s)
{
	if (r > 9223372036854775807 && s == 1)
		return (-1);
	if (r > 9223372036854775807 && s == -1)
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					s;
	unsigned long int	r;

	i = 0;
	s = 1;
	r = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -s;
		i++;
		if (str[i] == '-' || str[i] == '+')
			return (0);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		check_overflow(r, s);
		i++;
	}
	return (r * s);
}
