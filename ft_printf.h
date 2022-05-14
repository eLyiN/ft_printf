/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:53:26 by aarribas          #+#    #+#             */
/*   Updated: 2022/05/14 23:00:22 by aarribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define SYMBOLALLOW "cspdiuxX%"
# include "../libft/libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

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
}		t_print;

int		ft_print_pointer(t_print *tab);
int		ft_print_hex(t_print *tab, char format);
int		ft_print_procent(t_print *tab);
void	ft_format_hex(unsigned int nb, char format);
int		ft_lenght_hex(unsigned int nb);
int		ft_print_u_integer(t_print *tab);
int		ft_print_s_integer(t_print *tab);
int		ft_print_string(t_print *tab);
int		ft_print_char(t_print *tab);
char	*ft_uitoa(unsigned int n);
int		ft_unbrcount(unsigned int c);
int		ft_eval_format(t_print *tab, const char *format, int pos);
int		ft_printf(const char *format, ...);
int		ft_ptr_len(uintptr_t num);
void	ft_put_ptr(uintptr_t num);

#endif