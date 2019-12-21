RM = rm -rf
CC = gcc
CFLAGS = -Wpedantic -Wall -Wextra -ggdb -Og
INCLUDES =
LFLAGS =
LIBS = -lm

SRCS := $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
MAIN = $(SRCS:.c=)

all: $(MAIN)
	@echo  Build ${MAIN}

$(MAIN):%: %.o
	@echo Building $@
	$(CC) $(CFLAGS) $(INCLUDES) $(LFLAGS) $(LIBS) -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $<

.PHONY: clean

clean:
	$(RM) $(OBJS)
	$(RM) $(MAIN)
