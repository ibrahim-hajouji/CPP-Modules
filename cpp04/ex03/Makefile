NAME = Interface

SRCS = main.cpp \
		AMateria.cpp \
		Character.cpp \
		Cure.cpp \
		Ice.cpp \
		MateriaSource.cpp

OBJS = $(SRCS:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS) AMateria.hpp Cure.hpp Ice.hpp MateriaSource.hpp Character.hpp
	c++ $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp AMateria.hpp Cure.hpp Ice.hpp MateriaSource.hpp Character.hpp
	c++ $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re