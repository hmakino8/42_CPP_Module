NAME     = program
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:%.cpp=%.o)

$(NAME) : $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) *.o *.replace

fclean: clean
	$(RM) $(NAME)

test: re
	man printf > manfile;
	./$(NAME) manfile "printf" "42TOKYO";
	-@diff manfile manfile.replace;
	rm manfile;
	make fclean;

re: fclean all

.PHONY: all clean fclean test re
