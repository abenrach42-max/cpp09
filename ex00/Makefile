NAME = btc

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
       BitcoinExchange.cpp

HEADERS = BitcoinExchange.hpp

OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
