NAME = megaphone
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:%.cpp=%.o)

$(NAME) : $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) *.o
fclean: clean
	$(RM) $(NAME)
re: fclean all

test: re
	@echo "\n[test1]"
	./megaphone "shhhhh... I think the students are asleep..." | cat -e
	@echo "\n[test2]"
	./megaphone Damnit " ! " "Sorry students, I thought this thing was off." | cat -e
	@echo "\n[test3]"
	./megaphone | cat -e

.PHONY: all clean fclean re test
