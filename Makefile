NAME1 = server
NAME2 = client
SRC1 = utils.c server.c
SRC2 = utils.c client.c
OBJS1 = ${SRC1:.c=.o}
OBJS2 = ${SRC2:.c=.o}

all: ${NAME1} ${NAME2}

${NAME1} : ${OBJS1}
	gcc ${SRC1} -o ${NAME1} 

${NAME2} : ${OBJS2}
	gcc ${SRC2} -o ${NAME2} 

clean:
	rm -rf ${OBJS1} ${OBJS2}

fclean: clean
	rm -rf ${NAME1} ${NAME2}

re: fclean all

.PHONY: all clean fclean re