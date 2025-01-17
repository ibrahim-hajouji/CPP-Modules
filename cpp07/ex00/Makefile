NAME = main.cpp

OBJS = $(NAME:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(OBJS) ./whatever.hpp
	c++ $(CFLAGS) $(OBJS) -o NAME

%.o: %.cpp ./whatever.hpp
	c++ $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f NAME

re: fclean all

.PHONY: all clean fclean re