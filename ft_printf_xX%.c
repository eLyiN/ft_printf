/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xX%.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:50:14 by aarribas          #+#    #+#             */
/*   Updated: 2022/05/14 23:29:31 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lenght_hex(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

void	ft_format_hex(unsigned int nb, char format)
{
	if (nb >= 16)
	{
		ft_format_hex(nb / 16, format);
		ft_format_hex(nb % 16, format);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((nb - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((nb - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hex(t_print *tab, char format)
{
	unsigned int	nb;

	nb = va_arg(tab->args, unsigned int);
	if (nb == 0)
	{
		tab->tl += write(1, "0", 1);
		return (1);
	}
	else
		ft_format_hex(nb, format);
	tab->tl += ft_lenght_hex(nb);
	return (1);
}

int	ft_print_procent(t_print *tab)
{
	tab->tl += write(1, "%", 1);
	return (1);
}
