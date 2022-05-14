/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_csp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:50:44 by aarribas          #+#    #+#             */
/*   Updated: 2022/05/14 16:34:21 by aarribas         ###   ########.fr       */
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
	char *str;
	int i;

	i = 0;
	str = va_arg(tab->args, char *);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		tab->tl += 6;
		return (1);
	}
	while (str[i])
		write(1, &str[i++], 1);
	tab->tl += i;
	return (1);
}