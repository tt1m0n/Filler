# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/12 12:20:39 by omakovsk          #+#    #+#              #
#    Updated: 2018/01/13 16:45:19 by omakovsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = resources/players/omakovsk.filler
OBJ =  objects/*.o
LIBNAME = objects/libftfiller.a
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): objectdir
	@make -C libft
	@make -C filler
	ar rc $(LIBNAME) $(OBJ)
	gcc $(FLAGS) $(LIBNAME) -o $(NAME) 

objectdir:
	@mkdir -p objects

clean:
	@make clean -C libft
	@make clean -C filler
	@rm -rf objects

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean all fclean re
