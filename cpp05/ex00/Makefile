
CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror -g3 -O0
SRC_DIR = src
INC_DIR = include
INC = -I$(INC_DIR)
SRC = main.cpp Bureaucrat.cpp
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJ = $(SRCS:.cpp=.o)
NAME = bureaucrat

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(FLAGS) $(INC) -c $< -o $@

.PHONY: all clean fclean re

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
