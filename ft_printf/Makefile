NAME = ftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

SRC = ft_printf.c \
	ft_putchar_pf.c \
	ft_putnbr_hex_pf.c \
	ft_putnbr_pf.c \
	ft_putnbr_u_pf.c \
	ft_putstr_pf.c \



all: ${NAME}

OBJ = ${SRC:.c=.o} # Les fichiers objets générés à partir des fichiers sources


# Générer l'exécutable
${NAME}: ${OBJ}
	ar rcs ${NAME} ${OBJ}


# Générer un fichier objet (.o) à partir d'un fichier source (.c)
%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@


# Nettoyer les fichiers temporaires générés
clean:
	rm -f ${OBJ} ${OBJ_BONUS}

fclean: clean
	rm -f ${NAME}

re: fclean all
