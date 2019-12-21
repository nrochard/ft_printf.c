NAME	=	libftprintf.a

SRCS	=	libft/ft_atoi.c			\
			libft/ft_itoa.c			\
			libft/ft_putchar_fd.c	\
			libft/ft_putnbr_fd.c	\
			libft/ft_putstr_fd.c	\
			libft/ft_strdup.c		\
			libft/ft_strlen.c		\
			libft/ft_putnbr_base.c	\
			srcs/ft_printf.c 		\
			srcs/ft_printf_utils.c	\
			srcs/manage_z_m.c		\
			srcs/put.c 				\
			srcs/manage_u.c			\
			srcs/putstr.c 			\
			srcs/manage_flag.c		\
			srcs/display_letter.c	\
			srcs/manage_type.c		\
			srcs/display_flag1.c	\
			srcs/display_flag2.c	\
			srcs/display_flag3.c	\
			srcs/manage_list.c		\
			srcs/search_flag1.c		\
			srcs/search_flag2.c		\
			srcs/search_flag3.c		\
			srcs/search_type.c		\

OBJS	=	$(SRCS:%.c=%.o)

CFLAGS	=	-Wall -Wextra -Werror

CC		=	gcc

RM		=	rm -f

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I./includes

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