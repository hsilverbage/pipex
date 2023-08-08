.PHONY: 		clean fclean re norm

NAME = pipex

CC = cc -g3
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I ./includes

# COLORS
RED=\033[0;31m
BLUE=\033[0;34m
GREEN=\033[0;32m
YELLOW=\033[0;33m
END=\033[0m

SRC_DIR = ./sources
BONUS_DIR = ./bonus
U_DIR = ./utils
OBJ_DIR = .obj

LIBFT = libft/libft.a

SRC =	$(SRC_DIR)/main.c		\
		$(SRC_DIR)/free.c		\
		$(SRC_DIR)/exec_cmd.c

BONUS_SRC = $(BONUS_DIR)/main_bonus.c		\
			$(BONUS_DIR)/free_bonus.c		\
			$(BONUS_DIR)/exec_cmd_bonus.c	\
			$(BONUS_DIR)/heredoc.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_BONUS = $(BONUS_SRC:$(BONUS_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): lib $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)Compilation succeded ! ✔️$(END)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/sources
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: lib $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(INCLUDES) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)Bonus compilation succeeded! ✔️$(END)"

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/bonus
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

lib:
	@make -sC libft

norm:
	@norminette ./libft ./sources ./includes ./bonus | grep "Error" && echo "$(RED)Norminette KO!$(END)" || echo "$(GREEN)Norminette OK!$(END)"

clean:
	@echo "$(YELLOW)All .o files deleted 🗑 $(END)"
		@make clean -sC libft
		@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(YELLOW)The final program is deleted 🗑 $(END)"
	@make fclean -sC libft
	@rm -f $(NAME)

re: fclean norm all
