NAME	= Intern

CXX		= c++

CXXFLAGS	= -Werror -Wall -Wextra -std=c++98 -g3 -Wno-unused-command-line-argument

PATH_SRCS = srcs/
PATH_INCLUDES = includes/
PATH_OBJS = objs/

SRCS		= main.cpp \
			Bureaucrat.cpp \
			AForm.cpp \
			Intern.cpp \
			PresidentialPardonForm.cpp \
			RobotomyRequestForm.cpp \
			ShrubberyCreationForm.cpp \

OBJS		= $(SRCS:%.cpp=$(PATH_OBJS)%.o)

INCLUDES	= Colors.hpp \
			Bureaucrat.hpp \
			AForm.hpp \
			Intern.hpp \
			PresidentialPardonForm.hpp \
			RobotomyRequestForm.hpp \
			ShrubberyCreationForm.hpp \

all: $(NAME)

$(NAME): $(PATH_OBJS) $(OBJS) $(addprefix $(PATH_INCLUDES), $(INCLUDES))
	@$(CXX)  $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo Compilation Complete!

$(OBJS): $(PATH_OBJS)%.o: $(PATH_SRCS)%.cpp $(addprefix $(PATH_INCLUDES), $(INCLUDES))
	@$(CXX) $(CXXFLAGS) -I$(PATH_INCLUDES) -c $< -o $@

$(PATH_OBJS):
	@mkdir -p $(PATH_OBJS)

clean:
	@rm -rf $(OBJS) $(PATH_OBJS) ./ShrubForm1_shrubbery ./ShrubForm1_shrubbery_bonus

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
