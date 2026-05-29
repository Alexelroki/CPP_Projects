NAME = sed_is_for_losers 
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

HEADERS = FileReplacer.hpp
SRCS = FileReplacer.cpp  main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
