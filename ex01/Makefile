NAME = Serializer
CPP= c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

SRCS = main.cpp Serializer.cpp Data.cpp
INCS = Serializer.hpp Data.hpp

$(NAME): $(SRCS) $(INCS) Makefile
	$(CPP) $(CFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re : clean all

.PHONY: all clean fclean re