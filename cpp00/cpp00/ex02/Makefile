NAME = GlobalBanksters

SRCS = Account.cpp \
		tests.cpp

CFLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) Account.hpp
	c++ $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Account.hpp
	c++ $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
