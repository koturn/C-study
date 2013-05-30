### This Makefile was written for GNU Make. ###
MAKE        ?= make
TARGET_DIR1  = 20130516
TARGET_DIR2  = 20130523
TARGET_DIR3  = 20130530


.PHONY : all
all :
	$(MAKE) -C $(TARGET_DIR1)
	$(MAKE) -C $(TARGET_DIR2)
	$(MAKE) -C $(TARGET_DIR3)


.PHONY : clean
clean :
	$(MAKE) -C $(TARGET_DIR1) clean
	$(MAKE) -C $(TARGET_DIR2) clean
	$(MAKE) -C $(TARGET_DIR3) clean
.PHONY : objclean
objclean :
	$(MAKE) -C $(TARGET_DIR1) objclean
	$(MAKE) -C $(TARGET_DIR2) objclean
	$(MAKE) -C $(TARGET_DIR3) objclean
