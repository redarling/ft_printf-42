SRCS            =	ft_itoa.c \
			ft_words.c \
			ft_numbers.c \
			ft_hexadecimal.c \
			ft_printf.c

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

AR		= ar rcs

RM		= rm -f

CC		= cc

CFLAGS		= -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c -I.  $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		${AR} ${NAME} ${OBJS}

all:		${NAME}

clean:
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:		fclean all

.PHONY:		all fclean clean re
