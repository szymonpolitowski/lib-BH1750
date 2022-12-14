/*
 * bh1750.h
 *
 *	BH1750 datasheet:
 *	https://www.mouser.com/datasheet/2/348/bh1750fvi-e-186247.pdf
 *
 *  Created on: Oct 3, 2022
 *      Author: Szymon
 */

#ifndef BH1750_BH1750_H_
#define BH1750_BH1750_H_

#include "bh1750-instruction-set.h"
#include <stdint.h>

#define BH1750_I2C_ADDRESS_PIN_STATE_LOW	0x23
#define BH1750_I2C_ADDRESS_PIN_STATE_HIGH	0x5C

#define BH1750_I2C_ADDRESS_PIN_STATE_DEFAULT	BH1750_I2C_ADDRESS_PIN_STATE_LOW


typedef struct {

	uint8_t addr;
	BH1750_Mode_t mode;

}BH1750_t;

void BH1750_InitDevice(BH1750_t*, uint8_t);

void BH1750_SetModeSleep(BH1750_t*);

void BH1750_SetModeNormal(BH1750_t*);

void BH1750_ResetDataRegisterValue(BH1750_t*);


void BH1750_Test(void);

#endif /* BH1750_BH1750_H_ */
