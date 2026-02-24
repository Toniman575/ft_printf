NAME =  libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP -I..
SRCS =  ft_printf.c ft_printf_util.c ft_printf_workers.c
OBJS =  $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)

print_objs:
	@echo $(addprefix $(shell pwd)/, $(OBJS))