CC	= gcc
FLAGS	= -Wall -Wextra -Werror -fsanitize=address
RM	= rm -f

NAME	= push_swap
HEADER	= push_swap.h

SRCS	= push_swap.c\
		push_swap1.c\
	  utils.c\
	  functions.c\
	  functions1.c\
	  mainFunctions.c\
	  mainFunctions1.c\
#LIBFT	=./libft/libft.a

OBJS	= $(SRCS:.c=.o)

all:	$(NAME) #$(NAME_C)

#$(NAME_C) :
#	$(MAKE) bonus -C libft
#	gcc $(FLAGS) $(LIBFT) -o $(NAME_C)


$(NAME) :
	gcc $(SRCS) $(FLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME) 

re: fclean all

.PHONY:	all clean fclean re
