FILES		= 	*bonus*.c main.c

FLAGS		=	-fsanitize=address -Wall -Wextra -Werror

OBJS		= ${FILES:.c=.o}

DEBUG_FILES =	main.c

EXECUTABLE	:= main

clean:
				rm -f ${OBJS} ${OBJS_BONUS} ${LIBFT_OBJS}

fclean : clean

alldebug:	bin/$(EXECUTABLE)

run: cleandebug alldebug
	clear
	./bin/$(EXECUTABLE)

bin/$(EXECUTABLE): ${FILES}
	gcc -ggdb ${FLAGS} $^ -o $@ 

cleandebug:
	-rm bin/*
