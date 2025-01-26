NAME = harlFilter

SRCS = Harl.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS) Harl.hpp
	c++ $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Harl.hpp
	c++ $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all