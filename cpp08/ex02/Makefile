
CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror -g3 -O0
SRC_DIR = src
INC_DIR = include
INC = -I$(INC_DIR)
OBJ_DIR = obj
SRC = main.cpp
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))
NAME = stack

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INC) -c $< -o $@

.PHONY: all clean fclean re

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all
