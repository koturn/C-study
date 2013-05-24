### This Makefile was written for nmake. ###
CC      = cl
CFLAGS  = /O2 /Wall
LDFLAGS = /O2
RM      = del /F
TARGET1 = problem01.exe
TARGET2 = problem02.exe
TARGET3 = problem03.exe
TARGET4 = advance01.exe
TARGET5 = advance02.exe
TARGET6 = advance03.exe
OBJ1    = $(TARGET1:.exe=.obj)
OBJ2    = $(TARGET2:.exe=.obj)
OBJ3    = $(TARGET3:.exe=.obj)
OBJ4    = $(TARGET4:.exe=.obj)
OBJ5    = $(TARGET5:.exe=.obj)
OBJ6    = $(TARGET6:.exe=.obj)
SRC1    = $(TARGET1:.exe=.c)
SRC2    = $(TARGET2:.exe=.c)
SRC3    = $(TARGET3:.exe=.c)
SRC4    = $(TARGET4:.exe=.c)
SRC5    = $(TARGET5:.exe=.c)
SRC6    = $(TARGET6:.exe=.c)


all : $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) $(TARGET6)

$(TARGET1) : $(SRC1)

$(TARGET2) : $(SRC2)

$(TARGET3) : $(SRC3)

$(TARGET4) : $(SRC4)

$(TARGET5) : $(SRC5)

$(TARGET6) : $(SRC6)


clean :
	$(RM) $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) $(TARGET6) \
		$(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) $(OBJ6)
objclean :
	$(RM) $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) $(OBJ6)
