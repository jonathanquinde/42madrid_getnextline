NAME = main
SRC = get_next_line.c \
		get_next_line_utils.c main.c
OBJ = $(SRC:.c=.o)
CC = cc
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJ) libft.a 
	$(CC) $(FLAGS) $(OBJ) libft.a -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re: fclean clean

$(OBJ): get_next_line.h

.PHONY: all clean fclean re