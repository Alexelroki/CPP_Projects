NAME = diamondtrap
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

HEADERS = ClapTrap.hpp  DiamondTrap.hpp  FragTrap.hpp  ScavTrap.hpp
SRCS = ClapTrap.cpp  DiamondTrap.cpp  FragTrap.cpp  main.cpp  ScavTrap.cpp
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
