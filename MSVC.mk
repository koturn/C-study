### This Makefile was written for nmake. ###
MAKE        = nmake
MAKEFILE    = MSVC.mk
TARGET_DIR1 = 20130516
TARGET_DIR2 = 20130523
TARGET_DIR3 = 20130530
TARGET_DIR4 = 20130613
TARGET_DIR5 = 20130620
DIR_LIST    = $(TARGET_DIR1) $(TARGET_DIR2) $(TARGET_DIR3) $(TARGET_DIR4) $(TARGET_DIR5)


all :
	@for %d in ($(DIR_LIST)) do                     \
	    cd %d  &  $(MAKE) /f $(MAKEFILE)  &  cd ..  \

clean :
	@for %d in ($(DIR_LIST)) do                           \
	    cd %d  &  $(MAKE) /f $(MAKEFILE) clean  &  cd ..  \

objclean :
	@for %d in ($(DIR_LIST)) do                              \
	    cd %d  &  $(MAKE) /f $(MAKEFILE) objclean  &  cd ..  \
