CC=gcc
SRC_DIR 		= ./Src
SRC_INC_DIR 	= ./Inc
TEST_DIR		= ./Test
TEST_CASES_DIR	= $(TEST_DIR)/TestCases
TEST_CASE 		= 
MODULES 		=
CFLAGS 			=

ifeq ($(MODULE_TEST),1)
CFLAGS += -DMODULE_TEST
ifeq ($(MCU_TYPE),G070)
CFLAGS += -DMCU_G070
CFLAGS += -g
endif

##############################
# Test includes
##############################
INCLUDES = -I$(TEST_DIR)/TestEnv
INCLUDES += -I$(SRC_INC_DIR)

##############################
# Module includes
##############################
INCLUDES += -I$(SRC_INC_DIR)
INCLUDES += -I$(SRC_DIR)/RCC
INCLUDES += -I$(SRC_DIR)/Flash

##############################
# Module test folders
##############################
RCC_TEST = $(TEST_CASES_DIR)/RCC_Test

##############################
# RCC module test
##############################
RCC_MODULE_TEST += $(RCC_TEST)/RCC_TestCase_1.c

##############################
# Modules
##############################
MODULES += $(SRC_DIR)/RCC/RCC.c
MODULES += $(SRC_DIR)/Flash/Flash.c

##############################
# Test cases
##############################
TEST_CASE += $(RCC_MODULE_TEST)


##############################
# Concatenate the sources
##############################
SRC_FILES += $(MODULES)
SRC_FILES += $(TEST_CASE)
SRC_FILES += $(TEST_DIR)/TestEnv/TestEnv.c


make all: 
	$(CC) -o MakeTest $(TEST_DIR)/main.c $(SRC_FILES)  $(INCLUDES) $(CFLAGS)
endif