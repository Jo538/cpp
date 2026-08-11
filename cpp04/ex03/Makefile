
CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror -g3 -O0
SRC = main.cpp AMateria.cpp Ice.cpp Cure.cpp
OBJ = $(SRC:.cpp=.o)
NAME = ameteria

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

.PHONY: all clean fclean re

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
