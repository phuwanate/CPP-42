NAME = Formup

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp\
		Bureaucrat.cpp\
		AForm.cpp\
		ShrubberyCreationForm.cpp\
		RobotomyRequestForm.cpp\
		PresidentialPardonForm.cpp

HEADERS =	Bureaucrat.hpp\
			AForm.hpp\
			ShrubberyCreationForm.hpp\
			RobotomyRequestForm.hpp\
			PresidentialPardonForm.hpp

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