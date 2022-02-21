NAME = push_swap

SRCS = 	 push_swap.c operations.c operations2.c ft_split.c /
			sort1.c

INCLUDE	=	push_swap.h

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -I$(INCLUDE)

all		:	$(NAME)

 %.o : %.c	$(INCLUDE)
			$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(NAME)	:	$(OBJS) $(INCLUDE)
			$(CC) $(CFLAGS) $(SRCS) -I ./include -o $(NAME)

clean	:
		@rm -rf $(OBJS)

fclean	:	clean
		@rm -rf $(NAME)

re		:	fclean all

.PHONY: clean fclean re all
