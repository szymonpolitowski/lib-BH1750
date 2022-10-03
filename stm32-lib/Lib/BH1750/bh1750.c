/*
 * bh1750.c
 *
 *  Created on: Oct 3, 2022
 *      Author: Szymon
 */
#include "bh1750.h"
#include <stdbool.h>

/* PRIVATE */

inline bool _BH1750_IsSleepMode(BH1750_t* bh) {
	return (bh->mode == BH1750_Mode_Sleep) ? true : false;
}

inline bool _BH1750_IsNormalMode(BH1750_t* bh) {
	return (bh->mode == BH1750_Mode_Normal) ? true : false;
}

inline void _BH1750_SetNewMode(BH1750_t* bh, BH1750_Mode_t new_mode) {
	bh->mode = new_mode;
}


/* PUBLIC */

void BH1750_InitDevice(BH1750_t* bh) {

	_BH1750_SetNewMode(bh, BH1750_Mode_Sleep);

}


void BH1750_SetModeSleep(BH1750_t* bh) {

	if(!_BH1750_IsSleepMode(bh)) {

		//TODO wyslij komende wlaczenia uspienia


		_BH1750_SetNewMode(bh, BH1750_Mode_Sleep);
	}
}

void BH1750_SetModeNormal(BH1750_t* bh) {

	if(!_BH1750_IsNormalMode(bh)) {

		//TODO wyslij komende wlaczenia trybu normalnej pracy


		_BH1750_SetNewMode(bh, BH1750_Mode_Normal);
	}
}

void BH1750_ResetDataRegisterValue(BH1750_t* bh) {

	if(_BH1750_IsNormalMode(bh)) {
		//TODO wyslij komende resetu
	}
}


