# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 15:33:13 by aarribas          #+#    #+#              #
#    Updated: 2022/07/11 11:53:12 by aarribas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf_csp.c ft_printf_diu.c ft_printf_ptr.c ft_printf_utils.c \
			ft_printf_xX%.c ft_printf.c


RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
OBJS			= $(SRCS:.c=.o)
NAME			= libftprintf.a
LIBFT			= libft/
CC				= gcc

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME):		$(OBJS)
				@make -C $(LIBFT)
				@cp libft/libft.a .
				@mv libft.a $(NAME)
				ar rcs $(NAME) $(OBJS)

clean:
				$(MAKE) clean -C ./libft
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(MAKE) fclean -C ./libft
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re