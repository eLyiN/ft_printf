# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 15:33:13 by aarribas          #+#    #+#              #
#    Updated: 2022/05/13 21:59:16 by aarribas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf_csp.c ft_printf_ndiu.c ft_printf_ptr.c ft_printf_utils.c \
			ft_printf_xX%.c ft_printf.c


RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
OBJS			= $(SRCS:.c=.o)
NAME			= libftprintf.a
LIBFT			= libft/
CC				= gcc

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

$(NAME):		$(OBJS)
				@make all -C $(LIBFT)
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
bonus:			$(BONUS_OBJS)
				ar rcs $(NAME) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus