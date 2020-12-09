# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mraasvel <mraasvel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/28 22:34:16 by mraasvel      #+#    #+#                  #
#    Updated: 2020/11/30 21:33:40 by mraasvel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = a.out
SRC = $(shell find $(SRCDIR) -name "*.c" -exec basename {} \;)
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
DEPS = $(MLXDIR)/libmlx.a Makefile

# compilation
CC = gcc
IFLAG = -I$(MLXDIR) -I$(IDIR)
# CFLAGS = -Wall -Wextra -Werror
LIBFLAG = -L$(LIBDIR) -lm -lbsd
MLXFLAGS = -L$(MLXDIR) -lmlx -lXext -lX11

# Debug flags, "make debug" to compile with fsanitize
DEBUG = -O0 -g -fsanitize=address -fsanitize=leak

# directories
OBJDIR = obj
IDIR = include
MLXDIR = ../minilibx_linux
LIBDIR = /usr/lib
SRCDIR = src

# vpath so makefile knows where to find .c files
vpath %.c src

all: $(OBJDIR) $(NAME)
.PHONY: all clean fclean re dep

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME): $(DEPS) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBFLAG) $(MLXFLAGS) $(DEBUG)
# $(NAME): $(DEPS) $(OBJ)
# 	$(CC) -o $(NAME) $(OBJ) $(MLXFLAGS)
$(OBJDIR)/%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $< $(IFLAG)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

debug: $(DEPS) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(MLXFLAGS) $(DEBUG)
