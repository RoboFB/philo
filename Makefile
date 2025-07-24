# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgohrig <rgohrig@student.42heilbronn.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 10:21:00 by rgohrig           #+#    #+#              #
#    Updated: 2025/07/24 11:23:54 by rgohrig          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----------------------------- GENERAL ----------------------------------------

NAME :=			philo
CC :=			cc
CFLAGS :=		-Wall -Werror -Wextra# standard flags
# CFLAGS :=		-Wall -Werror -Wextra -g -fsanitize=address,undefined# debug
export CFLAGS # set also for the libft

HEADERS :=		-I ./include

# ----------------------------- NORMAL -----------------------------------------

DIR_SRC :=		src
SRC :=			$(notdir $(wildcard src/*.c))

DIR_OBJ :=		obj
OBJ :=			$(SRC:%.c=$(DIR_OBJ)/%.o)

# ----------------------------- NORMAL -----------------------------------------

all: $(LIBFT)/libft.a $(NAME)

$(LIBFT)/libft.a:
	@$(MAKE) -C $(LIBFT)

$(DIR_OBJ):
	mkdir $(DIR_OBJ)

$(DIR_OBJ)/%.o : $(DIR_SRC)/%.c | $(DIR_OBJ)
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<
	@echo 🖇 $@

# executable
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBS)
	@echo "\n🖇🖇🖇 $@   ($(CFLAGS))\n"

# ----------------------------- lazy ------------------------------------------

# temporary Rule to update the header file
lazy:
	@awk '/ auto/ { exit } { print }' include/$(NAME).h > tmp-auto-header.h
	@echo '// auto' >> tmp-auto-header.h
	@awk '/^[a-zA-Z_][a-zA-Z0-9_ \*\t]*\([^\)]*\)[ \t]*$$/ { \
		last=$$0; \
		getline; \
		if ($$0 ~ /^\s*\{/) { \
			split(last, a, /[ \t]+/); \
			if (a[1] == "int") sub(/[ \t]+/, "\t\t\t", last); \
			else sub(/[ \t]+/, "\t\t", last); \
			print last ";"; \
		} \
	}' src/*.c | grep -v static >> tmp-auto-header.h
	@echo "\n#endif" >> tmp-auto-header.h
	@cmp -s tmp-auto-header.h include/$(NAME).h || mv tmp-auto-header.h include/$(NAME).h
	@rm -f tmp-auto-header.h


# ----------------------------- Clean ------------------------------------------

clean:
	@rm -f $(OBJ)
	@echo 🧹 cleaned all objects
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	@rm -f $(NAME)
	@echo 🧹🧹🧹 cleaned $(NAME)
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re reb
