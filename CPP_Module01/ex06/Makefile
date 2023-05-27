NAME     = harlFilter
CXX      = c++
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
	@echo "--------------------------------------------";
	@echo "[TEST1: ./harlFilter]\n";
	-@./$(NAME)
	@echo "--------------------------------------------";
	@echo "[TEST2: ./harlFilter NoSuchCommand]\n";
	-@./$(NAME) NoSuchCommand;
	@echo "--------------------------------------------";
	@echo "[TEST3: ./harlFilter DEBUG]\n";
	-@./$(NAME) DEBUG;
	@echo "--------------------------------------------";
	@echo "[TEST4: ./harlFilter INFO]\n";
	-@./$(NAME) INFO;
	@echo "--------------------------------------------";
	@echo "[TEST5: ./harlFilter WARNING]\n";
	-@./$(NAME) WARNING;
	@echo "--------------------------------------------";
	@echo "[TEST5: ./harlFilter ERROR]\n";
	-@./$(NAME) ERROR;
	@make fclean;

.PHONY: all clean fclean re test
