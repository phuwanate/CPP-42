NAME = human

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

HEADERS = HumanA.hpp Weapon.hpp HumanA.hpp HumanB.hpp

SRCS =	main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(HEADERS)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re