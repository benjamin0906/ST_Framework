/*
 * FieldHelper.h
 *
 *  Created on: 2022. okt. 29.
 *      Author: Benjamin
 */

#ifndef INC_FIELDHELPER_H_
#define INC_FIELDHELPER_H_

#define BITFIELD_END    0

/* This macro helps creating bitfields for low level drivers */
#define FIELD_CREATOR(prefix, name, next_name) \
    uint32 name :prefix##_##name##_WIDTH;\
    uint32      :prefix##_##name##_PLACE-prefix##_##next_name##_PLACE+1;

#define REGISTER_MASK(width)  2^width-1

#endif /* INC_FIELDHELPER_H_ */
