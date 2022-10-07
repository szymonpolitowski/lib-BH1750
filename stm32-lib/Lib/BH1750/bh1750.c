/*
 * bh1750.c
 *
 *  Created on: Oct 3, 2022
 *      Author: Szymon
 */
#include "bh1750.h"
#include <stdbool.h>
#include "log.h"

const char * TAG = "bh1750";

/* PRIVATE */


bool _BH1750_IsSleepMode(BH1750_t* bh) {
	return (bh->mode == BH1750_Mode_Sleep) ? true : false;
}

bool _BH1750_IsNormalMode(BH1750_t* bh) {
	return (bh->mode == BH1750_Mode_Normal) ? true : false;
}

void _BH1750_SetNewMode(BH1750_t* bh, BH1750_Mode_t new_mode) {
	bh->mode = new_mode;
}


/* PUBLIC */

void BH1750_InitDevice(BH1750_t* bh) {

	Log_Info(TAG, "Init. Entering Sleep Mode");
	_BH1750_SetNewMode(bh, BH1750_Mode_Sleep);

}


void BH1750_SetModeSleep(BH1750_t* bh) {

	if(!_BH1750_IsSleepMode(bh)) {
		Log_Info(TAG, "Set Mode Sleep");
		//TODO wyslij komende wlaczenia uspienia


		_BH1750_SetNewMode(bh, BH1750_Mode_Sleep);

	} else {

		Log_Warning(TAG, "Already in Sleep Mode.");
	}
}

void BH1750_SetModeNormal(BH1750_t* bh) {

	if(!_BH1750_IsNormalMode(bh)) {
		Log_Info(TAG, "Set Mode Normal");
		//TODO wyslij komende wlaczenia trybu normalnej pracy


		_BH1750_SetNewMode(bh, BH1750_Mode_Normal);

	} else {

		Log_Warning(TAG, "Already in Sleep Mode.");
	}
}

void BH1750_ResetDataRegisterValue(BH1750_t* bh) {

	if(_BH1750_IsNormalMode(bh)) {
		Log_Info(TAG, "Reseting Data Register Value");
		//TODO wyslij komende resetu

	} else {

		Log_Error(TAG, "Cannot reset data register while sensor is in sleep mode.");
	}
}



/* TEST */

void BH1750_Test(void) {

	BH1750_t bh;

	BH1750_InitDevice(&bh);
	BH1750_SetModeSleep(&bh);
	BH1750_SetModeNormal(&bh);
	BH1750_ResetDataRegisterValue(&bh);
	BH1750_SetModeNormal(&bh);
	BH1750_SetModeSleep(&bh);
	BH1750_ResetDataRegisterValue(&bh);
}


