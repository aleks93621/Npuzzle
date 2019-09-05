NAME     := npuzzle

SRCS     := Node.cpp createFinalGrid.cpp checkOption.cpp checkHeuristic.cpp createFirstGrid.cpp createHash.cpp displayGrid.cpp expand.cpp heuristics.cpp main.cpp parser.cpp solvableTest.cpp utils.cpp
OBJS     := $(SRCS:.cpp=.o)

CXX      := clang++
CXXFLAGS := -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(OBJS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@echo "[INFO] Objects removed!"

fclean: clean
	@rm -f $(NAME)
	@echo "[INFO] $(NAME) removed!"

re:     fclean all

.PHONY: all clean fclean format re