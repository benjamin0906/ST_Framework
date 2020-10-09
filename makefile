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
else
ifeq ($(MCU_TYPE),F410)
CFLAGS += -DMCU_F410
endif
endif

ifeq ($(SILENT_BUILD),1)
CFLAGS += -DSILENT
endif

CFLAGS += -g

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
INCLUDES += -I$(SRC_DIR)/Pwr
INCLUDES += -I$(SRC_DIR)/NVIC
INCLUDES += -I$(SRC_DIR)/BasicTIM

##############################
# Module test folders
##############################
RCC_TEST = $(TEST_CASES_DIR)/RCC_Test
BASIC_TIM_TEST = $(TEST_CASES_DIR)/BasicTIM_Test

##############################
# RCC module test
##############################
ifeq ($(MCU_TYPE),G070)
RCC_MODULE_TEST += $(RCC_TEST)/RCC_Test_G070.c
else 
ifeq ($(MCU_TYPE),F410)
RCC_MODULE_TEST += $(RCC_TEST)/RCC_Test_F410.c
endif
endif

##############################
# BASIC TIM module test
##############################
ifeq ($(MCU_TYPE),G070)
#BASIC_TIM_MODULE_TEST += $(BASIC_TIM_TEST)/BasicTIM_Test_G070.c
else 
ifeq ($(MCU_TYPE),F410)
BASIC_TIM_MODULE_TEST += $(BASIC_TIM_TEST)/BasicTIM_Test_F410.c
endif
endif

##############################
# Modules
##############################
MODULES += $(SRC_DIR)/RCC/RCC.c
MODULES += $(SRC_DIR)/Flash/Flash.c
MODULES += $(SRC_DIR)/Pwr/Pwr.c
MODULES += $(SRC_DIR)/NVIC/NVIC.c
MODULES += $(SRC_DIR)/BasicTIM/BasicTIM.c

##############################
# Test cases
##############################
TEST_CASE += $(RCC_MODULE_TEST)
TEST_CASE += $(BASIC_TIM_MODULE_TEST)


##############################
# Concatenate the sources
##############################
SRC_FILES += $(MODULES)
SRC_FILES += $(TEST_CASE)
SRC_FILES += $(TEST_DIR)/TestEnv/TestEnv.c
	
make all: 
	$(CC) -o Test $(TEST_DIR)/main.c $(SRC_FILES)  $(INCLUDES) $(CFLAGS)
	
endif