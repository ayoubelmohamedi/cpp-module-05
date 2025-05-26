CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = Bureaucrat.cpp main.cpp Form.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = forms

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean