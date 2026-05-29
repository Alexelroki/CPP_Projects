NAME = unnecessaryviolence
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

HEADERS = HumanA.hpp HumanB.hpp Weapon.hpp
SRCS = main.cpp HumanA.cpp  HumanB.cpp  Weapon.cpp
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
