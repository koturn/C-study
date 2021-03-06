### This Makefile was written for nmake. ###
CC      = cl
CFLAGS  = /O2 /Wall
LDFLAGS = /O2
RM      = del /F
TARGET1 = problem01.exe
TARGET2 = problem02-1.exe
TARGET3 = problem02-2.exe
TARGET4 = problem03.exe
OBJ1    = $(TARGET1:.exe=.obj)
OBJ2    = $(TARGET2:.exe=.obj)
OBJ3    = $(TARGET3:.exe=.obj)
OBJ4    = $(TARGET4:.exe=.obj)
SRC1    = $(TARGET1:.exe=.c)
SRC2    = $(TARGET2:.exe=.c)
SRC3    = $(TARGET3:.exe=.c)
SRC4    = $(TARGET4:.exe=.c)


all : $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4)

$(TARGET1) : $(SRC1)

$(TARGET2) : $(SRC2)

$(TARGET3) : $(SRC3)

$(TARGET4) : $(SRC4) $(SRC4:.c=.h)


clean :
	$(RM) $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4)
objclean :
	$(RM) $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4)
