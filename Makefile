CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =	./src/core/ft_printf.c ./src/helpers/ft_atoi.c			\
		./src/helpers/ft_itohex.c ./src/helpers/ft_itoa.c		\
		./src/helpers/ft_itoa_u.c ./src/helpers/ft_strlen.c		\
		./src/helpers/ft_strrchr.c ./src/helpers/ft_isdigit.c	\
		./src/helpers/ft_strjoin.c ./src/helpers/ft_substr.c	\
		./src/helpers/ft_chartostr.c ./src/helpers/ft_strdup.c

SRCS_BONUS = ./src_bonus/core/ft_printf_bonus.c	./src_bonus/helpers/ft_atoi_bonus.c	\
			./src_bonus/helpers/ft_itohex_bonus.c ./src_bonus/helpers/ft_itoa_bonus.c \
			./src_bonus/helpers/ft_itoa_u_bonus.c ./src_bonus/helpers/ft_strlen_bonus.c	\
			./src_bonus/helpers/ft_strrchr_bonus.c ./src_bonus/helpers/ft_isdigit_bonus.c \
			./src_bonus/helpers/ft_strjoin_bonus.c ./src_bonus/helpers/ft_substr_bonus.c \
			./src_bonus/helpers/ft_chartostr_bonus.c ./src_bonus/helpers/ft_memset_bonus.c	\
			./src_bonus/helpers/ft_memmove_bonus.c ./src_bonus/core/handlers/hash_handler_bonus.c	\
			./src_bonus/core/handlers/plus_handler_bonus.c ./src_bonus/core/handlers/precision_handler_bonus.c \
			./src_bonus/core/handlers/space_handler_bonus.c ./src_bonus/core/handlers/width_handler_bonus.c	\
			./src_bonus/core/utils/get_width_bonus.c ./src_bonus/helpers/ft_strdup_bonus.c \
			./src_bonus/core/utils/get_length_bonus.c  ./src_bonus/core/utils/applay_flags_bonus.c \
			./src_bonus/core/utils/get_specification_bonus.c ./src_bonus/core/utils/get_string_bonus.c \
			./src_bonus/core/utils/process_str_bonus.c

NAME = libftprintf.a
OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}
.c.o: 
	${CC} ${CFLAGS} -c $< -o $@
	ar rc ${NAME} $@

all: ${NAME}

${NAME}: ${OBJS}

bonus: ${OBJS_BONUS}
clean :
	rm -f ${OBJS} ${OBJS_BONUS}
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: clean fclean all re  bonus
