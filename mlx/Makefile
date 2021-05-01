# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mraasvel <mraasvel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/02/17 12:13:15 by mraasvel      #+#    #+#                  #
#    Updated: 2021/02/17 14:13:59 by mraasvel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = a.out
SRC = $(shell find $(SRCDIR) -name "*.c" -type f -exec basename {} \;)
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
HEADERS = $(shell find $(IDIR) -name "*.h" -type f)

#DIRS
OBJDIR = obj
SRCDIR = src
IDIR = includes
vpath %.c $(SRCDIR)
vpath %.o $(OBJDIR)
vpath %.h $(IDIR)

#COMP
CC = gcc
DEPENDENCIES = $(HEADERS) Makefile
CFLAGS =
DFLAGS = -O0 -g -fsanitize=address
OFLAGS = -O3
IFLAGS = -I $(IDIR) -I $(MLXDIR)
LIBFLAGS = -L. -lft


#MLX
MLXDIR = mlx
# MLXLIB = -L$(MLXDIR)
MLXLIB = -L.
MLXFLAGSWSL = -lmlx -lXext -lX11
MLXFLAGSLINUX = -lmlx -lXext -lX11
# For mac, you will get a .dylib, which must be in the same directory as the executable
MLXFLAGSMAC = -lmlx -framework OpenGL -framework AppKit

#OS dependencies (change library inclusion based on operating system)
OS_NAME := $(shell uname -s | tr A-Z a-z)
ifeq ($(OS_NAME), linux)
	MLXLIB += $(MLXFLAGSLINUX)
else
	MLXLIB += $(MLXFLAGSMAC)
endif
LIBFLAGS += $(MLXLIB)

CFLAGS += $(DFLAGS)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $(OBJ) $(CFLAGS) $(LIBFLAGS)
$(OBJDIR)/%.o: %.c $(DEPENDENCIES) | $(OBJDIR)
	$(CC) -o $@ -c $< $(CFLAGS) $(IFLAGS)

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -f $(OBJ)
fclean:
	$(MAKE) clean
	rm -f $(NAME)
re:
	$(MAKE) fclean
	$(MAKE) all
