### This Makefile was written for GNU Make. ###
CC      = gcc
CFLAGS  = -O3 -pipe -Wall -Wextra $(if $(STD), $(addprefix -std=, $(STD)),)
LDFLAGS = -O3 -s
TARGET1 = problem01
TARGET2 = problem02-1
TARGET3 = problem02-2
TARGET4 = problem03
OBJ1    = $(addsuffix .o, $(basename $(TARGET1)))
OBJ2    = $(addsuffix .o, $(basename $(TARGET2)))
OBJ3    = $(addsuffix .o, $(basename $(TARGET3)))
OBJ4    = $(addsuffix .o, $(basename $(TARGET4)))

ifeq ($(OS),Windows_NT)
    TARGET1 := $(addsuffix .exe, $(TARGET1))
    TARGET2 := $(addsuffix .exe, $(TARGET2))
    TARGET3 := $(addsuffix .exe, $(TARGET3))
    TARGET4 := $(addsuffix .exe, $(TARGET4))
    CFLAGS  += -finput-charset=utf-8 -fexec-charset=cp932
endif


%.exe :
	$(CC) $(LDFLAGS) $(filter %.c %.o, $^) $(LDLIBS) -o $@


.PHONY : all
all : $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4)

$(TARGET1) : $(OBJ1)
	$(CC) $(LDFLAGS) $(filter %.c %.o, $^) -lm -o $@

$(TARGET2) : $(OBJ2)

$(TARGET3) : $(OBJ3)

$(TARGET4) : $(OBJ4) $(OBJ4:%.o=%.h)


.PHONY : clean
clean :
	$(RM) $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4)
.PHONY : objclean
objclean :
	$(RM) $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4)
