NAME	= Form

CXX		= c++

CXXFLAGS	= -Werror -Wall -Wextra -std=c++98 -g3

PATH_SRCS = srcs/
PATH_INCLUDES = includes/
PATH_OBJS = objs/

SRCS		= main.cpp \
			Bureaucrat.cpp \
			Form.cpp \

OBJS		= $(SRCS:%.cpp=$(PATH_OBJS)%.o)

INCLUDES	= Colors.hpp \
			Bureaucrat.hpp \
			Form.hpp \

all: $(NAME)

$(NAME): $(PATH_OBJS) $(OBJS) $(addprefix $(PATH_INCLUDES), $(INCLUDES))
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo Compilation Complete!

$(OBJS): $(PATH_OBJS)%.o: $(PATH_SRCS)%.cpp $(addprefix $(PATH_INCLUDES), $(INCLUDES))
	@$(CXX) $(CXXFLAGS) -I$(PATH_INCLUDES) -c $< -o $@

$(PATH_OBJS):
	@mkdir -p $(PATH_OBJS)

clean:
	@rm -rf $(OBJS) $(PATH_OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
