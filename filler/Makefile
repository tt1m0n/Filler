# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/12 12:20:55 by omakovsk          #+#    #+#              #
#    Updated: 2018/01/12 12:20:56 by omakovsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra -c

SRC = filler.c check_map.c wrt_coord.c mem_for_fg.c free.c alghoritm.c\
	  alg_down.c alg_up.c

OBJ	= $(SRC:.c=.o)

all: $(addprefix ../objects/,$(OBJ))

../objects/%.o: %.c
	gcc $(FLAGS) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean

re: fclean all


.PHONY: clean fclean all re
