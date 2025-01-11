NAME = convert

SRCS = main.cpp ScalarConverter.cpp

CFLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) ./ScalarConverter.hpp
	c++ $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp ./ScalarConverter.hpp
	c++ $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all