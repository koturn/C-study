### This Makefile was written for nmake. ###
MAKE        = nmake
MAKEFILE    = MSVC.mk
TARGET_DIR1 = 20130516
TARGET_DIR2 = 20130523
TARGET_DIR3 = 20130530


all :
	cd $(TARGET_DIR1)  &  $(MAKE) /f $(MAKEFILE)  &  cd ..
	cd $(TARGET_DIR2)  &  $(MAKE) /f $(MAKEFILE)  &  cd ..
	cd $(TARGET_DIR3)  &  $(MAKE) /f $(MAKEFILE)  &  cd ..


clean :
	cd $(TARGET_DIR1)  &  $(MAKE) /f $(MAKEFILE) clean  &  cd ..
	cd $(TARGET_DIR2)  &  $(MAKE) /f $(MAKEFILE) clean  &  cd ..
	cd $(TARGET_DIR3)  &  $(MAKE) /f $(MAKEFILE) clean  &  cd ..
objclean :
	cd $(TARGET_DIR1)  &  $(MAKE) /f $(MAKEFILE) objclean  &  cd ..
	cd $(TARGET_DIR2)  &  $(MAKE) /f $(MAKEFILE) objclean  &  cd ..
	cd $(TARGET_DIR3)  &  $(MAKE) /f $(MAKEFILE) objclean  &  cd ..
