SRCS = ft_printf.c ft_prt_number.c \
       ft_prt_unsigend.c \
       ft_prt_pointer.c ft_prt_hex.c

OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
AR	= ar rcs
CC = cc  
RM = rm -f 
CFLAGS = -Wall -Wextra -Werror

all:${NAME}

${NAME}:${OBJS}
	${AR} ${NAME} ${OBJS}

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS}

fclean:clean
	${RM} ${NAME}

re:fclean all
