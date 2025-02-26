CC = cc

CFLAGS=-Wall -Wextra -Werror

SRCS = ft_fused.c ft_printf.c ft_print_hex.c

NAME = libftprintf.a

OBJECT=$(SRCS:.c=.o)


%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all : $(NAME)

$(NAME) : $(OBJECT) 
	ar rcs $(NAME) $(OBJECT)

fclean : clean
	@rm -f $(NAME)

clean :
	@rm -f $(OBJECT)

re: fclean all

.PHONY : all fclean clean re

.SECONDARY: $(OBJECT)