NAME = animals

SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp

OBJS = $(SRCS:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS) Animal.hpp Dog.hpp Cat.hpp Brain.hpp
	c++ $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Animal.hpp Dog.hpp Cat.hpp
	c++ $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(WRONGOBJS)

fclean: clean
	rm -f $(NAME) $(WRONGNAME)

re: fclean all

.PHONY: all clean fclean re