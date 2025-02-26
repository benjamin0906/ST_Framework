/*
 * regdef_helper.h
 *
 *  Created on: Feb 26, 2025
 *      Author: Benjamin
 */

#ifndef INC_REGDEFS_REGDEF_HELPER_H_
#define INC_REGDEFS_REGDEF_HELPER_H_

#define LEN_CHECK_GREATER_THAN(var, length) ((sizeof(var) > length) ? -1 : 1)
#define LEN_CHECK_NOT_EQUAL(var, length) ((sizeof(var) != length) ? -1 : 1)
#define LEN_CHECK_LESS_THAN(var, length) ((sizeof(var) < length) ? -1 : 1)

#define LEN_CHECK(var, size) \
	struct LengthCheck_##var \
	{ \
	uint32 var :LEN_CHECK_NOT_EQUAL(var, size); \
	};

#define REGDEF(Domain, RegName) \
	LEN_CHECK(dt##Domain##_##RegName##_Bits, 4) \
	typedef union u##Domain##_##RegName \
	{ \
        uint32 U; \
        int32 I; \
        dt##Domain##_##RegName##_Bits B; \
	} dt##Domain##_##RegName;

#endif /* INC_REGDEFS_REGDEF_HELPER_H_ */
