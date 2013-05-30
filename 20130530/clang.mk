### This Makefile was written for GNU Make. ###
CC      = clang
CFLAGS  = -O3 -pipe -Wall -Wextra
LDFLAGS = -O3 -s
TARGET1 = problem01-1
TARGET2 = problem01-2
TARGET3 = problem02
TARGET4 = problem03-1
TARGET5 = problem03-2
TARGET6 = problem03-3
OBJ1    = $(addsuffix .o, $(basename $(TARGET1)))
OBJ2    = $(addsuffix .o, $(basename $(TARGET2)))
OBJ3    = $(addsuffix .o, $(basename $(TARGET3)))
OBJ4    = $(addsuffix .o, $(basename $(TARGET4)))
OBJ5    = $(addsuffix .o, $(basename $(TARGET5)))
OBJ6    = $(addsuffix .o, $(basename $(TARGET6)))

ifeq ($(OS),Windows_NT)
    TARGET1 := $(addsuffix .exe, $(TARGET1))
    TARGET2 := $(addsuffix .exe, $(TARGET2))
    TARGET3 := $(addsuffix .exe, $(TARGET3))
    TARGET4 := $(addsuffix .exe, $(TARGET4))
    TARGET5 := $(addsuffix .exe, $(TARGET5))
    TARGET6 := $(addsuffix .exe, $(TARGET6))
    CFLAGS  += -finput-charset=utf-8 -fexec-charset=cp932
endif

%.exe :
	$(CC) $(LDFLAGS) $(filter %.c %.o, $^) $(LDLIBS) -o $@


.PHONY : all
all : $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) $(TARGET6)

$(TARGET1) : $(OBJ1)

$(TARGET2) : $(OBJ2)

$(TARGET3) : $(OBJ3)

$(TARGET4) : $(OBJ4)

$(TARGET5) : $(OBJ5)

$(TARGET6) : $(OBJ6)


.PHONY : clean
clean :
	$(RM) $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) $(TARGET6) \
		$(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) $(OBJ6)
.PHONY : objclean
objclean :
	$(RM) $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) $(OBJ6)
