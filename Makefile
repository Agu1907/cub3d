CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -I./includes

NAME = cub3d

SRC = main.c utils/error_utils.c utils/ft_split.c utils/list_utils.c utils/utils.c utils/utils2.c \
	parser/get_next_line/get_next_line_utils.c parser/get_next_line/get_next_line.c parser/handle_map.c parser/map_algorithm.c \
	parser/map_utils.c parser/read_file.c parser/texture_parsing.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS)  $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re