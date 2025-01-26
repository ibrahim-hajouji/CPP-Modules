NAME = ClapTrap

SRCS = main.cpp ClapTrap.cpp

OBJ = $(SRCS:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ) ClapTrap.hpp
	c++ $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp ClapTrap.hpp
	c++ $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
