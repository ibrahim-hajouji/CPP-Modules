NAME = animals

WRONGNAME = WrongAnimals

SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp

WRONGSRCS = wrongmain.cpp WrongAnimal.cpp WrongCat.cpp

OBJS = $(SRCS:.cpp=.o)

WRONGOBJS = $(WRONGSRCS:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS) Animal.hpp Dog.hpp Cat.hpp
	c++ $(CFLAGS) $(OBJS) -o $(NAME)

$(WRONGNAME): $(WRONGOBJS) WrongAnimal.hpp WrongCat.hpp
	c++ $(CFLAGS) $(WRONGOBJS) -o $(WRONGNAME)

%.o: %.cpp Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp
	c++ $(CFLAGS) -c $< -o $@

wrong : $(WRONGNAME)

clean:
	rm -f $(OBJS) $(WRONGOBJS)

fclean: clean
	rm -f $(NAME) $(WRONGNAME)

re: fclean all

.PHONY: all clean fclean re