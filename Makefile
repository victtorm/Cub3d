# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/19 15:13:19 by vbritto-          #+#    #+#              #
#    Updated: 2024/12/28 13:31:17 by vbritto-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET	= \033[0m
BLACK 	= \033[1;30m
RED 	= \033[1;31m
GREEN 	= \033[1;32m
YELLOW 	= \033[1;33m
BLUE	= \033[1;34m
PURPLE 	= \033[1;35m
CYAN 	= \033[1;36m
WHITE 	= \033[1;37m

#_______________________________COMPILATION____________________________________#

NAME 		= cub3D

CC			= cc
CFLAGS		= -Wall -Werror -Wextra
MK_FLAG		= --no-print-directory
LFLAGS 		= -L ./libft -lft 
RM			= rm -rf

LIBFT		= libft/libft.a

MINILIBXD 	= ./minilibx-linux
MINILIBX 	= ./minilibx-linux/libmlx.a

OBJS_DIR 	= objs

FILES 		= main utils parse parse_texture parse_color map_plan clean\
			check_map_plan cub3d_init cub3d_events cub3d_img\
			check_move raycasting\
			check_rotate init_dir draw_wall move

SRC 		= $(addsuffix .c, $(FILES))
OBJ 		= $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(FILES)))

#__________________________________RULES_______________________________________#

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJ) $(LIBFT) ${MINILIBX}
		@$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -lmlx_Linux -L ${MINILIBXD} -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
		@echo "[$(GREEN)$(NAME) created$(RESET)]"

$(OBJS_DIR)/%.o : %.c
		@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
		@mkdir -p $(OBJS_DIR)
		@echo "[$(GREEN)objs dir created$(RESET)]"

$(LIBFT):
		@echo "... compiling libft ................"
		@make $(MK_FLAG) -C ./libft > /dev/null

${MINILIBX}:	
		@echo "... compiling minilibx ................"
		@make $(MK_FLAG) -sC ${MINILIBXD} > /dev/null 2>&1

clean:
		@$(RM) $(OBJS_DIR)
		@make $(MK_FLAG) -C ./libft clean > /dev/null
		@make $(MK_FLAG) -C ${MINILIBXD} clean > /dev/null
		@echo "[$(RED)objs removed$(RESET)]"

fclean: clean
		@$(RM) $(NAME)
		@echo "[$(RED)executables removed$(RESET)]"

re: fclean all

norm: 
		@echo "[$(CYAN)running norminette...$(RESET)]"
		norminette $(SRC) cub3d.h

.PHONY: all clean fclean re norm