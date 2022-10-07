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

typedef enum {
	BH1750_CMD_SetSleepMode = 0x00,
	BH1750_CMD_SetNormalMode = 0x01,
	BH1750_CMD_ResetDataRegister = 0x07,
	BH1750_CMD_StartContinouslyHresolutionMode = 0x10,
	BH1750_CMD_StartContinouslyHresolutionMode2 = 0x11,
	BH1750_CMD_StartContinouslyLresolutionMode = 0x13,
	BH1750_CMD_StartOneTimeHresolutionMode = 0x20,
	BH1750_CMD_StartOneTimeHresolutionMode2 = 0x21,
	BH1750_CMD_StartOneTimeLresolutionMode = 0x23,
}BH1750_I2C_CMD_t;


//#define	BH1750_IS_CHANGE_MEAS_TIME_H_BITS

//#define	BH1750_IS_CHANGE_MEAS_TIME_L_BITS



#endif /* BH1750_BH1750_INSTRUCTION_SET_H_ */
