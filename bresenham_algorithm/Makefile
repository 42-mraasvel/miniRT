# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mraasvel <mraasvel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/29 19:38:00 by mraasvel      #+#    #+#                  #
#    Updated: 2020/11/29 19:56:04 by mraasvel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = a.out
SRC = $(shell find $(SRCDIR) -name "*.c" -exec basename {} \;)
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
DEPS = $(MLXDIR)/libmlx.a Makefile

# Compilation
CC = gcc
CFLAGS = -Wall -Werror -Wextra
DEBUGFLAG = -O0 -g -fsanitize=address -fsanitize=leak
IFLAG = -I $(IDIR) -I $(MLXDIR)
LIBFLAG = -L$(LIBDIR) -lm -lbsd
MLXFLAG = -L$(MLXDIR) -lmlx -lXext -lX11

# DIRS
OBJDIR = obj
SRCDIR = src
IDIR = include
LIBDIR = /usr/lib
MLXDIR = ../minilibx_linux

# all: $(OBJDIR) $(NAME)
all: $(OBJDIR) debug
.PHONY: all clean fclean re debug

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): $(DEPS) $(OBJ)
	$(CC) -o $@ $(OBJ) $(LIBFLAG) $(MLXFLAG)
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -o $@ -c $< $(IFLAG)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

debug: $(DEPS) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBFLAG) $(MLXFLAG) $(DEBUGFLAG)
