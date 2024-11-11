NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = 	main_parse.c  \
		join_atoi.c\
		split.c \
		free_exit.c \
		create_list.c \
		check_list.c \
		sort_a_to_b.c \
		sort_3.c \
		b_to_a.c \
		get_number.c \
		count_send.c \
		moves.c \
		moves_2.c \
		moves_3.c 

OBJ = ${SRC:.c=.o}

all : ${NAME}

$(NAME) : ${OBJ} Makefile push_swap.h
	${CC} ${CFLAGS} ${SRC} -o push_swap;	

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

# malloc_test: $(OBJ)
# 	$(CC) $(CFLAGS) -fsanitize=undefined -rdynamic -o $@ ${OBJ} -L. -lmallocator

clean :
	rm -f ${OBJ}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re
