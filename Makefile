NAME 		= libftprintf.a
CFLAGS		= -Wall -Wextra -Werror
CC			= gcc
OBJS	 	= ${SRCS:.c=.o}
LIBFT_OBJS	= ${LIBFT:.c=.o}
INCLUDE 	= ./includes/ft_printf.h \
			./libft/libft.h
SRCS 		= ft_printf.c ./src/ft_do_type.c \
			./src/ft_parse.c ./src/ft_type_d.c \
			./src/ft_zero_struct.c ./src/ft_write_sz.c \
			./src/ft_putstr_pf.c ./src/ft_type_u.c \
			./src/ft_type_p.c ./src/ft_putchr_pf.c \
			./src/ft_type_x.c ./src/ft_type_c.c \
			./src/ft_type_s.c ./src/ft_type_percent.c
LIBFT		= ./libft/ft_itoa.c ./libft/ft_strlen.c \
			./libft/ft_strdup.c

.c.o:
	@${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS} $(LIBFT_OBJS) ${INCLUDE}
	@ar rcs ${NAME} $(LIBFT_OBJS) $?

norm:
	norminette .

test_lib: all clean
	@$(CC) $(CFLAGS) main.c $(NAME) $(LIBFT) && ./a.out

test_c:
	@$(CC) test3.c $(LIBFT) $(SRCS) -I $(INCLUDE) && ./a.out | cat -e

clean:
	@/bin/rm -f ${OBJS}
	@/bin/rm -f ${LIBFT_OBJS}
	@/bin/rm -f a.out

fclean: clean
	@/bin/rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
