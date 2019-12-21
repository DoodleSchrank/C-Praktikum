RM = rm -rf
CC = gcc
CFLAGS = -Wpedantic -Wall -Wextra -ggdb -Og
INCLUDES =
LFLAGS =
LIBS = -lm

SRCS := exercise05-1.c exercise05-2.1.c exercise05-2.2.c exercise05-3.c exercise05-4.c
OBJS = $(SRCS:.c=.o)
MAIN = $(SRCS:.c=.x)

all: $(MAIN)
	@echo  Build ${MAIN}

$(MAIN):%.x: %.o
	@echo Building $@
	$(CC) $(CFLAGS) $(INCLUDES) $(LFLAGS) $(LIBS) -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $<

.PHONY: clean cleanall

clean:
	$(RM) $(OBJS)
	$(RM) $(MAIN)
