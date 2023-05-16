CC = gcc
CFLAGS = -Wall -Wextra -Werror


SRCS = gen_tab.c occurences.c tri.c main.c
TEST_SRCS = gen_tab.c occurences.c tri.c test.c main_test.c


OBJS = $(SRCS:.c=.o)
TEST_OBJS = $(TEST_SRCS:.c=.o)


TARGET = projet


TEST_CFLAGS = -DENABLE_TESTS

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TEST_OBJS)
	$(CC) $(CFLAGS) $(TEST_CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS) $(TEST_OBJS) $(TARGET) test
