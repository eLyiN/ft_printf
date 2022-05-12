/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:53:26 by aarribas          #+#    #+#             */
/*   Updated: 2022/05/12 00:33:19 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define SYMBOLALLOW "cspdiuxX%"
# include <stdarg.h>
# include <stdio.h>

typedef struct s_print
{
	va_list args; //# arg to print out
	int wdt;      //# width
	int prc;      //# precision
	int zero;     //# zero padding
	int pnt;      //# .
	int dash;     //# -
	int tl;       //# total_length (return value)
	int sign;     //# pos or neg number
	int is_zero;  //# is number zero
	int perc;     //# %
	int sp;       //# space flag ' '
}	t_print;
#endif