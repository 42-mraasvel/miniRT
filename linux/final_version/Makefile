# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mraasvel <mraasvel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/02/06 10:21:18 by mraasvel      #+#    #+#                  #
#    Updated: 2021/02/10 23:04:51 by mraasvel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# COMPILE NORMALLY: make
# COMPILE BONUS: make bonus
# COMPILE WITH DEBUG FLAGS: make debug

# EXECUTABLE
NAME = miniRT

# All files explicitly named in Makefile
SRC = src/bmp/bmp.c \
src/bmp/create_bmp_file.c \
src/exit_program/exit_program.c \
src/exit_program/initialize_scene.c \
src/main.c \
src/render/compute_color.c \
src/render/compute_lights.c \
src/render/ray.c \
src/render/trace.c \
src/parsing/parse_triangle.c \
src/parsing/parse_sphere.c \
src/parsing/parse_square.c \
src/parsing/parse_checks.c \
src/parsing/parse_resolution.c \
src/parsing/parse_plane.c \
src/parsing/parse_camera.c \
src/parsing/parse_light.c \
src/parsing/parse_utils.c \
src/parsing/parse_file.c \
src/parsing/parse_cylinder.c \
src/parsing/check_arguments.c \
src/parsing/parse_ambient.c \
src/errors.c \
src/intersections/compute_normals.c \
src/intersections/intersect_plane.c \
src/intersections/intersect_square.c \
src/intersections/intersect_triangle.c \
src/intersections/intersect_sphere.c \
src/intersections/intersect_cylinder.c \
src/utils/vector_operations1.c \
src/utils/wrappers.c \
src/utils/math_utils.c \
src/utils/color_utils.c \
src/utils/vector_operations3.c \
src/utils/vector_operations2.c \
src/utils/vect.c \
src/utils/vectvp.c \
src/utils/matrix_operations.c \
src/mlx_management/initialize_images.c \
src/mlx_management/mlx_wrappers.c \
src/mlx_management/hooks.c \
src/mlx_management/initialize_mlx.c \
src/mlx_management/transform_camera.c

# Headers for dependencies
HEADERS = include/prototypes.h \
include/libvect.h \
include/minirt.h \
include/ft_enum.h \
include/parsing.h \
include/scene.h \
include/color.h \
include/objects.h \
include/bmp.h \
include/ft_double.h \
include/mlx_management.h \
include/raytracing.h \
include/lighting.h \
include/render.h \
include/libft.h \
include/vectors.h \
include/ft_error.h

ifdef BONUS
BONUS_SRC = src/render/multithreading_bonus.c
LIBFLAGS += -pthread
BONUS_DEPS = src/bmp/bmp.c src/main.c src/mlx_management/hooks.c
HEADERS += include/multithreading.h
else
BONUS_SRC = src/render/render_frame.c
endif

SRC += $(BONUS_SRC)
OBJ = $(addprefix $(OBJDIR)/, $(shell basename -a $(SRC:.c=.o)))

#Directories to find files in
OBJDIR = obj
SRCDIR = src
IDIR = include
MLXDIR = mlx
LFTDIR = libft

# Setting up vpath so Makefile can find .c files
SRC_SUBDIRS = bmp exit_program intersections mlx_management parsing render utils
SRCDIRS = $(addprefix $(SRCDIR)/, $(SRC_SUBDIRS))
SRCDIRS += $(SRCDIR)
vpath %.c $(SRCDIRS)

# For compilation
CC = gcc

ifdef DEBUG
DFLAGS = -O0 -g -fsanitize=address
else
DFLAGS = -O3
endif

CFLAGS = $(DFLAGS) -Wall -Werror -Wextra
IFLAGS = -I $(IDIR) -I $(MLXDIR)
LIBFLAGS += $(MLXLIB) $(LFTLIB) -lm

# All object files will have this as a dependency
LFTNAME = $(LFTDIR)/libft.a
DEPS = Makefile $(HEADERS)

#libraries
LFTLIB = -L$(LFTDIR) -lft
MLXLIB = -L$(MLXDIR) -lmlx -lXext -lX11
MLXNAME = $(MLXDIR)/libmlx.a


.PHONY: all libft
all:
	$(MAKE) libft
	$(MAKE) $(MLXNAME)
	$(MAKE) $(NAME) BONUS=1

libft:
	$(MAKE) -C $(LFTDIR)
$(MLXNAME):
	$(MAKE) -C $(MLXDIR)


$(NAME): $(OBJ) $(LFTNAME) $(MLXNAME)
	$(CC) -o $@ $(CFLAGS) $(OBJ) $(LIBFLAGS)
$(OBJDIR)/%.o:%.c $(DEPS) | $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS) $(IFLAGS)


$(OBJDIR):
	mkdir -p $(OBJDIR)

.PHONY: bonus debug clean fclean re
bonus:
	$(MAKE) BONUS=1
debug:
	$(MAKE) re DEBUG=1
clean:
	rm -f $(OBJ)
	rm -f $(OBJDIR)/multithreading_bonus.o
	$(MAKE) -C $(LFTDIR) clean
	$(MAKE) -C $(MLXDIR) clean
fclean:
	$(MAKE) clean
	$(MAKE) -C $(LFTDIR) fclean
	rm -f $(NAME)
re:
	$(MAKE) fclean
	$(MAKE) all
