NAME = phonebook

SRCS = PhoneBook.cpp \
		Contact.cpp \
		main.cpp

CFLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) Phonebook.hpp Contact.hpp
	c++ $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Phonebook.hpp Contact.hpp
	c++ $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
