CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS =  srcs/ft_printf.c \
	srcs/ft_printf_utils.c \
	srcs/ft_putstr.c \
	srcs/ft_putchar.c \
	srcs/ft_putnbr.c \
	srcs/ft_strlen.c \
	srcs/ft_hexa_conversion.c \
	srcs/ft_numlen.c
INCLUDES = includes
OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

$(NAME) : $(OBJS)
	ar -rc $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
