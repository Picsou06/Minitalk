NAME_CLIENT = client
NAME_SERVER = server

CFLAGS = -Wall -Werror -Wextra -I include

SRC_CLIENT = ./src/client.c
SRC_SERVER = ./src/server.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

YELLOW = \033[1;33m
GREEN = \033[1;32m
RESET = \033[0m

all : $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT) : $(OBJ_CLIENT)
			@echo "$(YELLOW)Compiling my libft...$(RESET)"
			@make -s -C libft
			@clang -o $(NAME_CLIENT) $(OBJ_CLIENT) $(CFLAGS) -L libft -lft
			@echo "$(GREEN)Client compilation finished.$(RESET)"

$(NAME_SERVER) : $(OBJ_SERVER)
			@echo "$(YELLOW)Compiling my libft...$(RESET)"
			@make -s -C libft
			@clang -o $(NAME_SERVER) $(OBJ_SERVER) $(CFLAGS) -L libft -lft
			@echo "$(GREEN)Server compilation finished.$(RESET)"

./src/%.o: ./src/%.c
			@clang $(CFLAGS) -c $< -o $@

clean :
			@echo "$(YELLOW)Cleaning object files...$(RESET)"
			@rm -rf $(OBJ_CLIENT) $(OBJ_SERVER)
			@echo "$(GREEN)Cleaning complete.$(RESET)"
			@make -s clean -C libft

fclean : clean
			@echo "$(YELLOW)Cleaning executables...$(RESET)"
			@rm -rf $(NAME_CLIENT) $(NAME_SERVER)
			@echo "$(GREEN)Full cleaning complete.$(RESET)"
			@make -s fclean -C libft

re : fclean all

.PHONY : all clean fclean re