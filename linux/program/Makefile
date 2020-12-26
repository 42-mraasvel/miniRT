# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mraasvel <mraasvel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/12/26 09:42:23 by mraasvel      #+#    #+#                  #
#    Updated: 2020/12/26 10:24:40 by mraasvel      ########   odam.nl          #
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

DFLAGS = -O0 -g -fsanitize=address
CC = gcc
# CFLAGS = -Wall -Werror -Wextra
IFLAGS = -I $(IDIR) -I $(MLXDIR)
LIBFLAGS = -L$(LIBDIR) -lft -lvect -lftprintf

# MLX FLAGS

MLXDIR = ../minilibx_linux
MLXLIB = -L$(MLXDIR) -lmlx -lXext -lX11

all: $(NAME)
.PHONY: all clean fclean re

$(NAME): $(OBJ)
	$(CC) -o $@ $(OBJ) $(MLXLIB) $(LIBFLAGS) $(DFLAGS)
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS) | $(OBJDIR)
	$(CC) -c -o $@ $< $(IFLAGS) $(CFLAGS)

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all
