/*
 * I2C_reg.h
 *
 *  Created on: Apr 18, 2025
 *      Author: Benjamin
 */

#ifndef INC_REGDEFS_I2C_REG_H_
#define INC_REGDEFS_I2C_REG_H_

#include "I2C_regdef.h"

#if defined(STM32U0)
#define MODULE_I2C_1    ((dtI2C*)0x40005400)
#define MODULE_I2C_2    ((dtI2C*)0x40005800)
#define MODULE_I2C_3    ((dtI2C*)0x40008800)

#elif defined(STM32L4)
#define MODULE_I2C_1    ((dtI2C*)0x40005400)
#define MODULE_I2C_2    ((dtI2C*)0x40005800)
#define MODULE_I2C_3    ((dtI2C*)0x40005C00)

#endif
#endif /* INC_REGDEFS_I2C_REG_H_ */
