/*
 * bh1750-instruction-set.h
 *
 *  Created on: Oct 3, 2022
 *      Author: Szymon
 */

#ifndef BH1750_BH1750_INSTRUCTION_SET_H_
#define BH1750_BH1750_INSTRUCTION_SET_H_

typedef enum {
	BH1750_Mode_Sleep = 0,
	BH1750_Mode_Normal
}BH1750_Mode_t;

#define	BH1750_IS_POWER_DOWN			0x00

#define	BH1750_IS_POWER_ON				0x01

#define	BH1750_IS_RESET					0x07

#define	BH1750_IS_CONT_H_RES_MODE		0x10

#define	BH1750_IS_CONT_H_RES_MODE_2		0x11

#define	BH1750_IS_CONT_L_RES_MODE		0x13

#define	BH1750_IS_ONE_TIME_H_RES_MOD	0x20

#define	BH1750_IS_ONE_TIME_H_RES_MOD_2	0x21

#define	BH1750_IS_ONE_TIME_L_RES_MOD	0x23

//#define	BH1750_IS_CHANGE_MEAS_TIME_H_BITS

//#define	BH1750_IS_CHANGE_MEAS_TIME_L_BITS






#endif /* BH1750_BH1750_INSTRUCTION_SET_H_ */
