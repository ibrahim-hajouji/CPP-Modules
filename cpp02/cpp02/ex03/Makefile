NAME = BSP

SRCS = main.cpp bsp.cpp Fixed.cpp Point.cpp

OBJS = $(SRCS:.cpp=.o)

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS) ./Fixed.hpp ./Point.hpp
	c++ $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Fixed.hpp Point.hpp
	c++ $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
