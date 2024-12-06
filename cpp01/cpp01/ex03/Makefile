NAME = weapon

SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

OBJS = $(SRCS:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS) Weapon.hpp HumanA.hpp HumanB.hpp
	c++ $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Weapon.hpp HumanA.hpp HumanB.hpp
	c++ $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re