/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_csp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:50:44 by aarribas          #+#    #+#             */
/*   Updated: 2022/05/13 00:40:17 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(t_print *tab)
{
	char	c;

	c = va_arg(tab->args, int);
	tab->tl += write(1, &c, 1);
	return (1);
}
int	ft_print_string(t_print *tab)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(tab->args, int);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i++])
		write(1, &str[i], 1);
	tab->tl += i;
	return (1);
}
int	ft_print_pointer(t_print *tab)
{
	char *str;

	str = va_arg(tab->args, int);
	write(1, &str, 1);
}