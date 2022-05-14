/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:45:58 by aarribas          #+#    #+#             */
/*   Updated: 2022/05/13 21:55:26 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unbrcount(int c)
{
	int	i;

	i = 0;
	if (c == 0 || c < 0)
	{
		return (1);
	}
	while (c < 0)
	{
		c = c / 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa(int n)
{
	char	*fresh_str;
	int		i;

	i = ft_unbrcount(n);
	fresh_str = (char *)malloc(sizeof(char) * (i + 1));
	if (!fresh_str)
		return (NULL);
	if (n == 0)
	{
		fresh_str[0] = '0';
		fresh_str[1] = '\0';
		return (fresh_str);
	}
	fresh_str[i--] = '\0';
	while (n > 0)
	{
		fresh_str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (fresh_str);
}
