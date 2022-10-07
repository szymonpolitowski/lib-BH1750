/*
 * bh1750.c
 *
 *  Created on: Oct 3, 2022
 *      Author: Szymon
 */
#include "bh1750.h"
#include <stdbool.h>
#include "log.h"
#include "main.h"

const char *TAG = "bh1750";

#define BH1750_I2C_ADDR (bh->addr << 1)

/* PRIVATE */

void _BH1750_TxCommand(uint8_t addr, BH1750_I2C_CMD_t cmd) {
	uint8_t data = cmd;
	HAL_I2C_Master_Transmit(&hi2c1, addr, &data, 1, 5);
}

bool _BH1750_IsSleepMode(BH1750_t* bh) {
	return (bh->mode == BH1750_Mode_Sleep) ? true : false;
}

bool _BH1750_IsNormalMode(BH1750_t* bh) {
	return (bh->mode == BH1750_Mode_Normal) ? true : false;
}

void _BH1750_SetNewMode(BH1750_t* bh, BH1750_Mode_t new_mode) {

	switch(new_mode) {
	case BH1750_Mode_Sleep:
		_BH1750_TxCommand(BH1750_I2C_ADDR, BH1750_CMD_SetSleepMode);
		break;
	case BH1750_Mode_Normal:
		_BH1750_TxCommand(BH1750_I2C_ADDR, BH1750_CMD_SetNormalMode);
		break;
	default:
		Log_Error(TAG, "Set New Mode: FATAL ERROR");
		while(1);
		break;
	}
	bh->mode = new_mode;
}

void _BH1750_SetI2CAddress(BH1750_t* bh, uint8_t addr) {
	bh->addr = addr;
	Log_Info(TAG, "Device address is: 0x%X", addr);
}


/* PUBLIC */

void BH1750_InitDevice(BH1750_t* bh, uint8_t addr) {

	Log_Info(TAG, "Init. Entering Sleep Mode");
	_BH1750_SetI2CAddress(bh, addr);
	_BH1750_SetNewMode(bh, BH1750_Mode_Sleep);

}


void BH1750_SetModeSleep(BH1750_t* bh) {

	if(!_BH1750_IsSleepMode(bh)) {

		Log_Info(TAG, "Set Mode Sleep");
		_BH1750_SetNewMode(bh, BH1750_Mode_Sleep);

	} else {

		Log_Warning(TAG, "Already in Sleep Mode");
	}
}

void BH1750_SetModeNormal(BH1750_t* bh) {

	if(!_BH1750_IsNormalMode(bh)) {

		Log_Info(TAG, "Set Mode Normal");
		_BH1750_SetNewMode(bh, BH1750_Mode_Normal);

	} else {

		Log_Warning(TAG, "Already in Normal Mode");
	}
}

void BH1750_ResetDataRegisterValue(BH1750_t* bh) {

	if(_BH1750_IsNormalMode(bh)) {

		Log_Info(TAG, "Reseting Data Register Value");
		_BH1750_TxCommand(BH1750_I2C_ADDR, BH1750_CMD_ResetDataRegister);

	} else {

		Log_Error(TAG, "Cannot reset data register while sensor is in sleep mode");
	}
}



/* TEST */

void BH1750_Test(void) {

	BH1750_t bh;

	BH1750_InitDevice(&bh, BH1750_I2C_ADDRESS_PIN_STATE_DEFAULT);
	BH1750_SetModeSleep(&bh);
	BH1750_SetModeNormal(&bh);
	BH1750_ResetDataRegisterValue(&bh);
	BH1750_SetModeNormal(&bh);
	BH1750_SetModeSleep(&bh);
	BH1750_ResetDataRegisterValue(&bh);
}


