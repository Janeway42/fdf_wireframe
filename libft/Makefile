# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: janeway <janeway@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2021/07/04 14:52:18 by janeway       #+#    #+#                  #
#    Updated: 2021/10/12 15:12:11 by cpopa         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS	=	-Wall -Werror -Wextra -fsanitize=address
HEADER_FILES = ../includes/libft.h

OBJS_FILES	=	$(SRC:.c=.o)
SRC =	ft_atoi.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_isdigit.c\
		ft_lstadd_back.c\
		ft_lstlast.c\
		ft_lstnew.c\
		ft_lstsize.c\
		ft_putstr_fd.c\
		ft_split.c\
		ft_strcmp.c\
		ft_strjoin.c\
		ft_strlen.c

all: $(NAME)

$(NAME): $(OBJS_FILES)
	ar -rcs $@ $^

%.o: %.c $(HEADER_FILES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_FILES)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
