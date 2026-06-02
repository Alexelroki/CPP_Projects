NAME = bsp
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

HEADERS = Fixed.hpp  Point.hpp
SRCS = bsp.cpp  Fixed.cpp  main.cpp  Point.cpp
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
