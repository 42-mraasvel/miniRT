# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mraasvel <mraasvel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/02/03 09:28:45 by mraasvel      #+#    #+#                  #
#    Updated: 2021/02/03 10:16:01 by mraasvel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = a.out
SRC = main.c
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

# compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBS = -L $(MLXDIR) -lmlx -framework OpenGL -framework AppKit -lm
IFLAGS = -I$(MLXDIR)
DFLAGS = -g -fsanitize=address
SPDFLAGS = -O0

MLXDIR = minilibx_opengl_20191021
OBJDIR = obj

.PHONY: all
all: MLX $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBS) $(DFLAGS)
$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) -c $< -o $@$(CFLAGS) $(IFLAGS) $(SPDFLAGS)

$(OBJDIR):
	mkdir -p $(OBJDIR)

.PHONY: MLX
MLX:
	$(MAKE) -C $(MLXDIR)

.PHONY: clean fclean re
clean:
	rm -f $(OBJ)
fclean:
	$(MAKE) clean
	rm -f $(NAME)
re:
	$(MAKE) fclean
	$(MAKE) all
