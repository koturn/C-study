### This Makefile was written for nmake. ###
CPP      = cl
CPPFLAGS = /O2 /Wall
LDFLAGS  = /O2
RM       = del /F
TARGET1  = problem01.exe
TARGET2  = problem02.exe
TARGET3  = problem03.exe
OBJ1     = $(TARGET1:.exe=.obj)
OBJ2     = $(TARGET2:.exe=.obj)
OBJ3     = $(TARGET3:.exe=.obj)
SRC1     = $(TARGET1:.exe=.cpp)
SRC2     = $(TARGET2:.exe=.cpp)
SRC3     = $(TARGET3:.exe=.cpp)


all : $(TARGET1) $(TARGET2) $(TARGET3)

$(TARGET1) : $(SRC1)

$(TARGET2) : $(SRC2)

$(TARGET3) : $(SRC3)


clean :
	$(RM) $(TARGET1) $(TARGET2) $(TARGET3) $(OBJ1) $(OBJ2) $(OBJ3)
objclean :
	$(RM) $(OBJ1) $(OBJ2) $(OBJ3)
