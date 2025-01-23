LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I ./

SRC =       .c \

OBJS = ${SRC:%.c=obj/%.o}

all: ${NAME}
${NAME}: ${OBJS} $(LIBFT)
	@$(CC) $(CFLAGS) ${OBJS} -o $(NAME) $(LIBFT) -I ./libft

$(LIBFT):
	@make -s -C $(LIBFT_DIR)
	@make -s -C $(LIBFT_DIR) bonus
	@echo "compilating $@"

obj/%.o: src/%.c push_swap.h
	@mkdir -p obj
	@${CC} ${CFLAGS} -c $< -o $@ -I ./libft

clean:
	@make -s -C $(LIBFT_DIR) clean
	@rm -rf obj

fclean: clean
	@make -s -C $(LIBFT_DIR) fclean
	@rm -f ${NAME}

re: fclean all