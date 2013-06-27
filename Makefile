### This Makefile was written for GNU Make. ###
MAKE        ?= make
TARGET_DIR1  = 20130516
TARGET_DIR2  = 20130523
TARGET_DIR3  = 20130530
TARGET_DIR4  = 20130613
TARGET_DIR5  = 20130620
TARGET_DIR6  = 20130627
DIR_LIST     = $(TARGET_DIR1) $(TARGET_DIR2) $(TARGET_DIR3) $(TARGET_DIR4) \
               $(TARGET_DIR5) $(TARGET_DIR6)


.PHONY : all
all :
	@for dir in $(DIR_LIST); do  \
	    $(MAKE) -C $$dir;        \
	done


.PHONY : clean
clean :
	@for dir in $(DIR_LIST); do  \
	    $(MAKE) -C $$dir clean;  \
	done

.PHONY : objclean
objclean :
	@for dir in $(DIR_LIST); do     \
	    $(MAKE) -C $$dir objclean;  \
	done
