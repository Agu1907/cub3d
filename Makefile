CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = cub3d

SRC = main.c utils/utils.c utils/error_utils.c utils/ft_split.c utils/list_utils.c \
	read_file.c  get_next_line/get_next_line.c get_next_line/get_next_line_utils.c handle_map.c map_algorithm.c map_utils.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re