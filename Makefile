NAME	=	libftprintf.a

SRCS	=	libft/ft_atoi.c			\
			libft/ft_itoa.c			\
			libft/ft_putchar_fd.c	\
			libft/ft_putnbr_fd.c	\
			libft/ft_putstr_fd.c	\
			libft/ft_strdup.c		\
			libft/ft_strlen.c		\
			libft/ft_putnbr_base.c	\
			ft_printf.c 			\
			ft_printf_utils.c		\
			ft_manage.c

OBJS	=	$(SRCS:%.c=%.o)

CFLAGS	=	-Wall -Wextra -Werror

CC		=	gcc

RM		=	rm -f

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I./

$(NAME):	$(OBJS)
			ar rc ${NAME} ${OBJS} 
			ranlib ${NAME}

all:		$(NAME)

bonus:		$(OBJS) $(B_OBJS)
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME) 

re:			fclean all

.PHONY:		re all clean fclean