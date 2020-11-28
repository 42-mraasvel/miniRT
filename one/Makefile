# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mraasvel <mraasvel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/28 22:34:16 by mraasvel      #+#    #+#                  #
#    Updated: 2020/11/28 22:42:26 by mraasvel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = a.out
SRC = $(shell find . -name "*.c" -exec basename {} \;)
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

# compilation
CC = gcc
IFLAG = -I ../mlx_linux
CFLAGS = -Wall -Wextra -Werror
LIBFLAG = -L../mlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

# directories
OBJDIR = obj

all: dep $(NAME)
.PHONY: all clean fclean re dep

dep:
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJ)
	$(CC) $(LIBFLAG) -o $(NAME) $(OBJ)
$(OBJDIR)/%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $< $(IFLAG)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
