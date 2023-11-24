NAME = Minitalk.a

C_SRC = client.c
S_SRC = server.c
SRC = outils.c
HADER_FILE = minitalk.h


OBJS = ${SRC:.c=.o}


CC		= cc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): client server

client : $(C_SRC) $(HADER_FILE)
	$(CC) $(CFLAGS) $(C_SRC) $(SRC) -o client

server : $(S_SRC) $(HADER_FILE)
	$(CC) $(CFLAGS) $(S_SRC) $(SRC) -o server

all:	${NAME}

clean:
		${RM} ${OBJS} ${OBJSBONUS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all
