/*
 * regdef_helper.h
 *
 *  Created on: Feb 26, 2025
 *      Author: Benjamin
 */

#ifndef INC_REGDEFS_REGDEF_HELPER_H_
#define INC_REGDEFS_REGDEF_HELPER_H_

#define REGDEF(Domain, RegName) \
	typedef union u##Domain##_##RegName \
	{ \
        uint32 U; \
        int32 I; \
        dt##Domain##_##RegName##_Bits B; \
	} dt##Domain##_##RegName;

#endif /* INC_REGDEFS_REGDEF_HELPER_H_ */
