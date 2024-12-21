NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT_DIR =  libft

LIBFT_LIB = $(LIBFT_DIR)/libft.a

IFLAGS = -I$(LIBFT_DIR)

SRC_FILES = $(wildcard utils/*.c ./*.c)

OBJ_FILES = $(SRC_FILES:.c=.o)

#target:	prerequisite
all:		$(LIBFT_DIR) $(NAME)

$(NAME):	$(LIBFT_DIR) $(OBJ_FILES)	
			@$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT_LIB) -o $(NAME)
			@echo "Done building push_swap"

%.o:		%.c
			@echo $< $@
			$(CC) $(CFLAGS) $(IFLAGS) -c $? -o $@

vg:			all
			valgrind --leak-check=full --show-leak-kinds=all ./push_swap

libft:
			@make -C $(LIBFT_DIR)
			@echo "build libft success"

clean:
			@make clean -C $(LIBFT_DIR)
			@${RM} ${OBJ_FILES}
			@echo "clean success"

fclean:		clean
			@make fclean -C $(LIBFT_DIR)
			$(RM) $(NAME)
			@echo "fclean Success"

re:			fclean all

.PHONY:		libft clean fclean re vg