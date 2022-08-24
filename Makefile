NAME1	= push_swap

NAME2	= checker

FLAGS 	= -Wall -Wextra -Werror

SRC 	= push_swap.c q_sort.c sort_b.c operations_1.c \
		  operations_2.c operations_3.c funcs_1.c funcs_2.c \
		  funcs_3.c sort_help.c last_work.c

SRC_BONUS 	= check_bonus.c operations_1_bonus.c operations_2_bonus.c operations_3_bonus.c \
		  q_sort_bonus.c funcs_1_bonus.c funcs_2_bonus.c funcs_3_bonus.c check_help_bonus.c\

OBJS1 	= $(patsubst %.c,%.o,$(SRC))

OBJS2 	= $(patsubst %.c,%.o,$(SRC_BONUS))

HDR 		= push_swap.h

HDR_BONUS 	= push_swap_bonus.h

LIBFT_HDR 	= -I./libft

LIB_BINARY	= -L./libft -lft

LIBFT		= ./libft/libft.a

.PHONY : all clean fclean re bonus

all: $(LIBFT) $(NAME1)

FORCE:		;

$(LIBFT):	FORCE
			make -C ./libft

%.o : %.c push_swap.h push_swap_bonus.h
	CC $(FLAGS) -o $@ -c $<

$(NAME1): $(OBJS1) $(LIBFT) push_swap.h
	CC $(FLAGS) $(OBJS1) $(LIB_BINARY) -o $@

$(NAME2): $(OBJS2) $(LIBFT) push_swap_bonus.h
	CC $(FLAGS) $(OBJS2) $(LIB_BINARY) -o $@

bonus: $(LIBFT) ./libft/libft.a $(NAME2)

clean:
	rm -f $(OBJS1)
	rm -f $(OBJS2)

fclean: clean
	rm -f $(NAME1)
	rm -f $(NAME2)

re: fclean all

