# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: janeway <janeway@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2021/07/15 14:05:35 by janeway       #+#    #+#                  #
#    Updated: 2021/10/15 19:34:10 by janeway       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CFLAGS	= -Wall -Werror -Wextra -g -fsanitize=address

S_SRC	=	main.c\
			parse.c \
			projection.c\
			center.c\
			render.c\
			draw.c
S_PATH	=	src/
S_OBJ	=	$(S_SRC:%.c=$(S_PATH)%.o)

UTILS		=	error_free_exit.c\
				utils.c
UTILS_PATH	=	utils/
UTILS_OBJ	=	$(UTILS:%.c=$(UTILS_PATH)%.o)

GNL			=	get_next_line.c\
				get_next_line_utils.c
GNL_PATH	=	get_next_line/
GNL_OBJ		=	$(GNL:%.c=$(GNL_PATH)%.o)

OBJ_FILES = $(S_OBJ) $(UTILS_OBJ) $(GNL_OBJ)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	make -C libft
	make -C mlx
	$(CC) $(OBJ_FILES) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz libft/libft.a $(CFLAGS) -o $@
	
%.o: %.c $(HEADER_FILES)
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< $(CFLAGS) -o $@

clean:
	make clean -C libft
	$(RM) libft/libft.a
	make clean -C mlx
	$(RM) $(OBJ_FILES)

fclean: clean
	make clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re