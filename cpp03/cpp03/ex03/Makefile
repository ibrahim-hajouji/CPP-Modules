NAME = DiamondTrap

SRCS = main.cpp FragTrap.cpp ScavTrap.cpp ClapTrap.cpp DiamondTrap.cpp

OBJS = $(SRCS:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS) FragTrap.hpp ScavTrap.hpp ClapTrap.hpp DiamondTrap.hpp
	c++ $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp FragTrap.hpp ScavTrap.hpp ClapTrap.hpp DiamondTrap.hpp
	c++ $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re