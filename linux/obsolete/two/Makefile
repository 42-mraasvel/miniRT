# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mraasvel <mraasvel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/12/16 21:55:59 by mraasvel      #+#    #+#                  #
#    Updated: 2020/12/29 09:48:18 by mraasvel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# filename vars
NAME = a.out
SRC = $(shell find $(SRCDIR) -name "*.c" -exec basename {} \;)
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
HEADERS = $(shell find $(IDIR) -name "*.h")

# compilation
CC = gcc
# CFLAGS = -Wall -Werror -Wextra
DFLAGS = -O0 -g -fsanitize=address -fsanitize=leak
IFLAGS = -I $(IDIR) -I$(MLXDIR) -I $(LIBFTDIR)

# MLX
MLXDIR = ../minilibx_linux
MLXFIND = -L$(MLXDIR)
# LIBFLAGS = -lmlx -lXext -lX11 -lz -lm -lft
LIBFLAGS = -lmlx -lXext -lX11 -L$(LIBFTDIR) -lft
MLXFLAGS = $(MLXFIND) $(LIBFLAGS)

# dirs
OBJDIR = obj
SRCDIR = src
IDIR = include
LIBFTDIR = libft

# colors
RED = '\033[031;1m'
GREEN = '\033[032;1m'
YELLOW = '\033[033;1m'
BLUE = '\033[034;1m'
CLEAR = '\033[0;0m'
ECHO = @echo -en

all: $(NAME)
.PHONY: all re fclean clean

$(NAME): $(OBJ) Makefile
	$(ECHO) $(GREEN)
	$(CC) -o $@ $(OBJ) $(MLXFLAGS) $(DFLAGS)
	$(ECHO) $(CLEAR)
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS) | $(OBJDIR)
	$(ECHO) $(YELLOW)
	$(CC) -c -o $@ $< $(CFLAGS) $(IFLAGS)
	$(ECHO) $(CLEAR)

$(OBJDIR):
	@mkdir -p $@

clean:
	$(ECHO) $(RED)
	rm -f $(OBJ)
	$(ECHO) $(CLEAR)
fclean: clean
	$(ECHO) $(BLUE)
	rm -f $(NAME)
	$(ECHO) $(CLEAR)
re: fclean all
