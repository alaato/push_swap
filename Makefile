NAME		= push_swap

GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

CC 			= cc

SRC = src/main.c src/operations.c src/operations_utils.c src/find_median.c src/sort.c \
		src/fill_stack.c src/sort_utils.c src/init.c src/sort3.c src/check_args.c src/error.c src/print.c
OBJS := $(SRC:%.c=%.o)


FLAGS 		= -Wall -Werror -Wextra

REMOVE 		= rm -f

LIBFT 			= ./Libft/libft.a

$(NAME): $(OBJS)
	@ cc -g $(SRC) $(LIBFT) -o $(NAME)
OBJS: 
	@ cc -c $(SRC)
clean:
	@rm -f $(OBJS)

fclean: clean
	@make clean
	@rm -f $(NAME)