NAME = iter

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(OBJS) iter.hpp
	c++ $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp iter.hpp
	c++ $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re