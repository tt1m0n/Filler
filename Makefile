# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/12 12:20:39 by omakovsk          #+#    #+#              #
#    Updated: 2018/01/16 17:22:31 by omakovsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = omakovsk.filler
OBJ =  objects/*.o
LIBNAME = objects/libftfiller.a
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): objectdir
	@make -C libft
	@make -C filler
	@ar rc $(LIBNAME) $(OBJ)
	@gcc $(FLAGS) $(LIBNAME) -o $(NAME) 
	@echo "\033[35m ---------omakovsk.filler ready to fight------------\033[0m"

objectdir:
	@mkdir -p objects

clean:
	@make clean -C libft
	@make clean -C filler
	@rm -rf objects

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31m --------------omakovsk.filler deleted--------------\033[0m"

re: fclean all

.PHONY: clean all fclean re
