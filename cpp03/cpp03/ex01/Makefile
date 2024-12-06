NAME = ScavTrap

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp

CFLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) ScavTrap.hpp ClapTrap.hpp
	c++ $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp ScavTrap.hpp ClapTrap.hpp
	c++ $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re