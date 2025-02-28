/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabibi- <ahabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:28:27 by ahabibi-          #+#    #+#             */
/*   Updated: 2025/02/27 23:42:48 by ahabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	format_inout(va_list args, char sa)
{
	int				rasa;

	rasa = 0;
	if (sa == 'c')
		rasa += ft_putchar(va_arg(args, int));
	else if (sa == 's')
		rasa += ft_putstr(va_arg(args, char *));
	else if (sa == 'd' || sa == 'i')
		rasa += ft_putnbr(va_arg(args, int));
	return (rasa);
}

int	ft_printf(const char *sa, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, sa);
	if (!sa)
		return (-1);
	while (*sa)
	{
		if (*sa == '%')
		{
			sa++;
			if (*sa)
				count += format_inout(args, *sa);
			else
				return (va_end(args), -1);
		}
		else
			count += ft_putchar(*sa);
		sa++;
	}
	va_end(args);
	return (count);
}
