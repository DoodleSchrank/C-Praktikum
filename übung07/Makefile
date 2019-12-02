RM = rm -rf
CC = gcc
CFLAGS = -Wpedantic -Wall -Wextra -ggdb -Og
INCLUDES =
LFLAGS =
LIBS =

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

.PHONY: clean cleanall

clean:
	$(RM) $(OBJS)

cleanall: clean
	$(RM) $(MAIN)
