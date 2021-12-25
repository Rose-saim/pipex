MANDA_NAMES = 	pipex.c utils.c process.c split.c \
				gnl/get_next_line.c	gnl/get_next_line_utils.c \
				error.c

MANDA_OBJS =	 $(MANDA_NAMES:.c=.o)

NAME = pipex

CC = clang
CFLAGS = -Wall -Wextra -Werror

AR = ar rc

RM = rm -f

RL = ranlib

$(NAME):	$(MANDA_OBJS)
			$(CC) $(CFLAGS) $(MANDA_OBJS) -o $(NAME)

all:		$(NAME)

clean:	
			$(RM) $(MANDA_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re