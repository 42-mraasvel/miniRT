# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mraasvel <mraasvel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/12/26 09:42:23 by mraasvel      #+#    #+#                  #
#    Updated: 2020/12/30 12:05:07 by mraasvel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = a.out
SRC = $(shell find $(SRCDIR) -name "*.c" -exec basename {} \;)
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
HEADERS = $(shell find $(IDIR) -name "*.h")
DEPENDENCIES = Makefile $(HEADERS)

# DIRS

SRCDIR = src
OBJDIR = obj
IDIR = include
LIBDIR = libs

# Compilation

DFLAGS = -O0 -g -fsanitize=address -fsanitize=leak
CC = gcc
# CFLAGS = -Wall -Werror -Wextra
CFLAGS = -Wall -Wextra
IFLAGS = -I $(IDIR) -I $(MLXDIR)
LIBFLAGS = -L$(LIBDIR) -lft -lvect -lftprintf -lm

# MLX FLAGS

MLXDIR = ../minilibx_linux
MLXLIB = -L$(MLXDIR) -lmlx -lXext -lX11

# PATHS
VPATH = $(shell find $(SRCDIR) -type d | tr '\n' ':' | sed -r 's/(.*):/\1/')

all: $(NAME)
.PHONY: all clean fclean re

$(NAME): $(OBJ) Makefile
	$(CC) -o $@ $(OBJ) $(MLXLIB) $(LIBFLAGS) $(DFLAGS)
$(OBJDIR)/%.o: %.c $(HEADERS) | $(OBJDIR)
	$(CC) -c -o $@ $< $(IFLAGS) $(CFLAGS)

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all
