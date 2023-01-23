FILES		= 	get_next_line.c get_next_line_utils.c main.c

FILES_BONUS	= get_next_line_bonus.c get_next_line_utils_bonus.c main.c

FLAGS		=	-fsanitize=address -Wall -Wextra -Werror

OBJS		= ${FILES:.c=.o}

OBJS_BONUS	= ${FILES_BONUS:.c=.o}

DEBUG_FILES =	main.c

EXECUTABLE	:= main

EXECUTABLE_BONUS	:= main_bonus


clean:
				rm -f ${OBJS}

fclean : clean

debug:	bin/$(EXECUTABLE)

debug_bonus:	bin/$(EXECUTABLE_BONUS)

run: cleandebug debug
	clear
	./bin/$(EXECUTABLE)

run_bonus: cleandebug debug_bonus
	clear
	./bin/$(EXECUTABLE_BONUS)

bin/$(EXECUTABLE): ${FILES}
	gcc -ggdb ${FLAGS} $^ -o $@ 

bin/$(EXECUTABLE_BONUS): ${FILES_BONUS}
	gcc -ggdb ${FLAGS} $^ -o $@ 

cleandebug:
	-rm bin/*
