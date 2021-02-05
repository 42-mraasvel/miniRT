# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mraasvel <mraasvel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/02/02 17:17:00 by mraasvel      #+#    #+#                  #
#    Updated: 2021/02/05 20:51:13 by mraasvel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = a.out
SRC = $(shell find $(SRCDIR) -name "*.c" -exec basename {} \;)
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
HEADERS = $(shell find $(IDIR) -name "*.h")
DEPENDENCIES = Makefile $(HEADERS)
LIBS = $(LIBDIR)/libft.a

# DIRS

SRCDIR = src
OBJDIR = obj
IDIR = include
LIBDIR = libft

# Compilation

ifdef DEBUG
DFLAGS = -O0 -g -fsanitize=address
else
SPEEDFLAG = -O3
endif
CC = gcc
CFLAGS = -Wall -Werror -Wextra
# CFLAGS = -Wall -Wextra
IFLAGS = -I $(IDIR) -I $(MLXDIR)
LIBFLAGS = -L$(LIBDIR) -lft -lm -pthread

# MLX FLAGS

MLXDIR = ../minilibx_linux
MLXLIB = -L$(MLXDIR) -lmlx -lXext -lX11

# PATHS
VPATH = $(shell find $(SRCDIR) -type d | tr '\n' ':' | sed -r 's/(.*):/\1/')

all: compile_libs $(NAME)
.PHONY: all clean fclean re compile_libs debug

$(NAME): $(OBJ) $(LIBS) Makefile
	$(CC) -o $@ $(OBJ) $(MLXLIB) $(LIBFLAGS) $(DFLAGS)
$(OBJDIR)/%.o: %.c $(HEADERS) | $(OBJDIR)
	$(CC) -c -o $@ $< $(IFLAGS) $(CFLAGS) $(SPEEDFLAG) $(DFLAGS)

$(OBJDIR):
	mkdir -p $(OBJDIR)
compile_libs:
	$(MAKE) -C $(LIBDIR)

clean:
	rm -rf $(OBJ)
	$(MAKE) clean -C $(LIBDIR)
fclean: clean
	$(MAKE) fclean -C $(LIBDIR)
	rm -rf $(NAME)
re:
	$(MAKE) fclean
	$(MAKE) all
debug:
	$(MAKE) re DEBUG=1
