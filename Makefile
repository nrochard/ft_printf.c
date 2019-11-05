NAME	=	libftprintf.a

SRCS	=	libft/ft_atoi.c			\
			libft/ft_bzero.c		\
			libft/ft_calloc.c		\
			libft/ft_isalnum.c		\
			libft/ft_isalpha.c		\
			libft/ft_isascii.c		\
			libft/ft_isdigit.c		\
			libft/ft_isprint.c		\
			libft/ft_itoa.c			\
			libft/ft_memccpy.c		\
			libft/ft_memchr.c		\
			libft/ft_memcmp.c		\
			libft/ft_memcpy.c		\
			libft/ft_memmove.c		\
			libft/ft_memset.c		\
			libft/ft_putchar_fd.c	\
			libft/ft_putendl_fd.c	\
			libft/ft_putnbr_fd.c	\
			libft/ft_putstr_fd.c	\
			libft/ft_split.c		\
			libft/ft_strchr.c		\
			libft/ft_strdup.c		\
			libft/ft_strjoin.c		\
			libft/ft_strlcat.c		\
			libft/ft_strlcpy.c		\
			libft/ft_strlen.c		\
			libft/ft_strmapi.c		\
			libft/ft_strncmp.c		\
			libft/ft_strnstr.c		\
			libft/ft_strrchr.c		\
			libft/ft_strtrim.c		\
			libft/ft_substr.c		\
			libft/ft_tolower.c		\
			libft/ft_toupper.c		\
			./ft_printf.c 			\

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