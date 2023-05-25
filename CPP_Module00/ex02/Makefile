NAME = account
CXX = c++
#CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXXFLAGS = -std=c++98

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

origin: CXXFLAGS += -D ORIGIN=1
origin: re
	./Account > test.log

test: origin
	diff 19920104_091532.log test.log; make fclean; rm test.log

.PHONY: all clean fclean re origin test
