NAME = push_swap

SRCS = 	 push_swap.c ft_split.c check_argc.c \
        operations.c operations2.c sort1.c libft.c \
		sort2.c stack_work.c push_w.c cleaning.c

INCLUDE	=	push_swap.h

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -g -I$(INCLUDE)

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