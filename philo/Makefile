# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 10:21:00 by rgohrig           #+#    #+#              #
#    Updated: 2025/09/02 17:23:50 by rgohrig          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----------------------------- GENERAL ----------------------------------------

NAME :=			philo
CC :=			cc

# DEBUG_FLAGS := -g -fsanitize=address,undefined,pointer-compare,pointer-subtract
# DEBUG_FLAGS := -g #-pg -fsanitize=thread #-g3 -o0
CFLAGS :=		-Wall -Werror -Wextra $(DEBUG_FLAGS)

HEADERS :=		-I ./include

# ----------------------------- NORMAL -----------------------------------------

DIR_SRC :=		src
SRC :=			ft_memcpy.c ft_strlen.c ft_calloc.c init.c main.c \
				monitor.c mutexes.c print_log.c single.c threads.c \
				time.c use_forks.c parsing.c

DIR_OBJ :=		obj
OBJ :=			$(SRC:%.c=$(DIR_OBJ)/%.o)

# ----------------------------- NORMAL -----------------------------------------

all: $(NAME)

$(DIR_OBJ):
	mkdir $(DIR_OBJ)

$(DIR_OBJ)/%.o : $(DIR_SRC)/%.c | $(DIR_OBJ)
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<
	@echo 🍽 $@

# executable
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "\n🍝🍝🍝 $@   ($(CFLAGS))\n"

# ----------------------------- Clean ------------------------------------------

clean:
	@rm -f $(OBJ)
	@echo 🧹 cleaned all objects

fclean: clean
	@rm -f $(NAME)
	@echo 🧹🧹🧹 cleaned $(NAME)

re: fclean all

.PHONY: all clean fclean re reb
