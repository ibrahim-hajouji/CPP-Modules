NAME = PmergeMe

SRCS = PmergeMe.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS) PmergeMe.hpp
	c++ $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp PmergeMe.hpp
	c++ $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re