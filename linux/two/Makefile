# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mraasvel <mraasvel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/12/16 21:55:59 by mraasvel      #+#    #+#                  #
#    Updated: 2020/12/16 22:00:33 by mraasvel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = a.out
SRC = $(shell find $(SRCDIR) -name "*.c" -exec basename {} \;)
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
HEADERS = $(shell find $(IDIR) -name "*.h")

# compilation
CC = gcc
CFLAGS = -Wall -Werror -Wextra
DFLAGS = -O0 -g -fsanitize=address
IFLAGS = -I $(IDIR)

# dirs
OBJDIR = obj
SRCDIR = src
IDIR = include

all: $(NAME)
.PHONY: all re fclean clean

$(NAME): $(OBJ) Makefile
	$(CC) -o $@ $(OBJ) $(DFLAGS)
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS) | $(OBJDIR)
	$(CC) -o $@ $< $(CFLAGS) $(IFLAGS)

$(OBJDIR):
	mkdir -p $@

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
