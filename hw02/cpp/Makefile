LIBSO = 0

OS := $(shell uname)

EXEC = kl
OBJDIR = ./obj/
SRCDIR = ./src/

ifeq ($(LIBSO), 1)
LIBNAMESO = kl.so
endif

CC = g++ -std=c++11
OPTS = -O2 -fno-finite-math-only
CFLAGS = -Wall -Wfatal-errors -Wno-unused-result -Wno-unknown-pragmas -fPIC

CFLAGS += $(OPTS)
LDFLAGS = -lm

all: $(OBJDIR) backup $(EXEC) $(LIBNAMESO)

ifeq ($(LIBSO), 1)
CFLAGS+= -fPIC

$(LIBNAMESO): $(OBJDIR) $(OBJS)
	$(CC) -shared -std=c++11 -fvisibility=hidden $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

endif

SOURCES = $(wildcard $(SRCDIR)*.cpp)
OBJS = $(patsubst $(SRCDIR)%.cpp, $(OBJDIR)%.o, $(SOURCES))
DEPS = $(wildcard $(SRCDIR)*.hpp)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(OBJDIR)%.o: $(SRCDIR)%.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)
backup:
	mkdir -p backup

.PHONY: clean

clean:
	rm -rf $(OBJS) $(EXEC)

