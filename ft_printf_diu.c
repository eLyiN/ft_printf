/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_diu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:49:37 by aarribas          #+#    #+#             */
/*   Updated: 2022/05/14 23:33:44 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s_integer(t_print *tab) //d & i
{
	int nb;
	char *str;
	int i;

	nb = va_arg(tab->args, int);
	str = ft_itoa(nb);
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	tab->tl += i;
	free(str);
	return (1);
}
int	ft_print_u_integer(t_print *tab)
{
	unsigned int	nb;
	char			*str;
	int				i;

	nb = va_arg(tab->args, unsigned int);
	str = ft_uitoa(nb);
	i = 0;
	if (str == NULL)
	{
		tab->tl += write(1, "0", 1);
		return (1);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	tab->tl += i;
	free(str);
	return (1);
}
