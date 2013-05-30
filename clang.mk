### This Makefile was written for GNU Make. ###
MAKE        ?= make
MAKEFILE     = clang.mk
TARGET_DIR1  = 20130516
TARGET_DIR2  = 20130523
TARGET_DIR3  = 20130530


.PHONY : all
all :
	$(MAKE) -C $(TARGET_DIR1) -f $(MAKEFILE)
	$(MAKE) -C $(TARGET_DIR2) -f $(MAKEFILE)
	$(MAKE) -C $(TARGET_DIR3) -f $(MAKEFILE)


.PHONY : clean
clean :
	$(MAKE) -C $(TARGET_DIR1) -f $(MAKEFILE) clean
	$(MAKE) -C $(TARGET_DIR2) -f $(MAKEFILE) clean
	$(MAKE) -C $(TARGET_DIR3) -f $(MAKEFILE) clean
.PHONY : objclean
objclean :
	$(MAKE) -C $(TARGET_DIR1) -f $(MAKEFILE) objclean
	$(MAKE) -C $(TARGET_DIR2) -f $(MAKEFILE) objclean
	$(MAKE) -C $(TARGET_DIR3) -f $(MAKEFILE) objclean
