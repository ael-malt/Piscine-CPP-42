NAME	= megaphone

CPP		= c++

FLAGS	= -Werror -Wall -Wextra -std=c++98 -g3

SRCS		= megaphone.cpp

OBJS		= $(SRCS:.cpp=.o)

all:	$(NAME)

%.o: %.cpp
		$(CPP) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CPP) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "Compilation Complete"

clean	:
		@rm -rf $(OBJS)

fclean	: clean
		@rm -rf $(NAME)

re:		fclean all

.PHONY: all clean fclean re
