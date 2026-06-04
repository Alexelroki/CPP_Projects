NAME = scavtrap
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

HEADERS = ClapTrap.cpp  main.cpp  ScavTrap.cpp
SRCS = ClapTrap.cpp  main.cpp  ScavTrap.cpp
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
