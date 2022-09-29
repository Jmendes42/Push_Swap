CC	= gcc
FLAGS	= -Wall -Wextra -Werror 
RM	= rm -f

NAME	= push_swap
HEADER	= push_swap.h

SRC = $(wildcard ./src/*.c)

OBJ	= $(SRC:.c=.o)

all:	$(NAME) 

$(NAME) :
	gcc $(SRC) $(FLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME) 

re: fclean all

.PHONY:	all clean fclean re
