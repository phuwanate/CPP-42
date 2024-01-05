NAME = Intern

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp\
		Bureaucrat.cpp\
		Form.cpp\
		ShrubberyCreationForm.cpp\
		RobotomyRequestForm.cpp\
		PresidentialPardonForm.cpp\
		Intern.cpp

HEADERS =	Bureaucrat.hpp\
			Form.hpp\
			ShrubberyCreationForm.hpp\
			RobotomyRequestForm.hpp\
			PresidentialPardonForm.hpp\
			Intern.hpp

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