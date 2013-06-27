### This Makefile was written for GNU Make. ###
CC      = gcc
CFLAGS  = -O3 -pipe -Wall -Wextra $(if $(STD), $(addprefix -std=, $(STD)),)
LDFLAGS = -O3 -s
TARGET1 = problem01
TARGET2 = problem02
TARGET3 = problem03
OBJ1    = $(addsuffix .o, $(basename $(TARGET1)))
OBJ2    = $(addsuffix .o, $(basename $(TARGET2)))
OBJ3    = $(addsuffix .o, $(basename $(TARGET3)))

ifeq ($(OS),Windows_NT)
    TARGET1 := $(addsuffix .exe, $(TARGET1))
    TARGET2 := $(addsuffix .exe, $(TARGET2))
    TARGET3 := $(addsuffix .exe, $(TARGET3))
    CFLAGS  += -finput-charset=utf-8 -fexec-charset=cp932
endif


%.exe :
	$(CC) $(LDFLAGS) $(filter %.c %.o, $^) $(LDLIBS) -o $@


.PHONY : all
all : $(TARGET1) $(TARGET2) $(TARGET3)

$(TARGET1) : $(OBJ1)

$(TARGET2) : $(OBJ2)

$(TARGET3) : $(OBJ3)


.PHONY : clean
clean :
	$(RM) $(TARGET1) $(TARGET2) $(TARGET3) $(OBJ1) $(OBJ2) $(OBJ3)
.PHONY : objclean
objclean :
	$(RM) $(OBJ1) $(OBJ2) $(OBJ3)
