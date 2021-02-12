#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK64F12.h"
#include "fsl_debug_console.h"

void vfnClearLeds(void)
{
	SIM->SCGC5 = 0;
	return;
}

void vfnSetBlueLed(void)
{
	SIM->SCGC5 |= 0x400;
	PORTB->PCR[21] |= 0x100;
	PTB->PDDR |= 0x200000;
	PTB->PDOR &= ~0x200000;
	return;
}

void vfnSetRedLed(void)
{
	SIM->SCGC5 |= 0x400;
	PORTB->PCR[22] |= 0x100;
	PTB->PDDR |= 0x400000;
	PTB->PDOR &= ~0x400000;
	return;
}

void vfnSetGreenLed(void)
{
	SIM->SCGC5 |= 0x2000;
	PORTE->PCR[26] |= 0x100;
	PTE->PDDR |= 0x4000000;
	PTE->PDOR &= ~0x4000000;
	return;
}

void vfnSetYellowLed(void)
{
	SIM->SCGC5 |= 0x2000;
	PORTE->PCR[26] |= 0x100;
	PTE->PDDR |= 0x4000000;
	PTE->PDOR &= ~0x4000000;
	SIM->SCGC5 |= 0x400;
	PORTB->PCR[22] |= 0x100;
	PTB->PDDR |= 0x400000;
	PTB->PDOR &= ~0x400000;

	/*SIM->SCGC5 |= 2400;
	PORTB->PCR[22] = 0x100;
	PORTE->PCR[26] = 0x100;
	PTB->PDDR |= 0x400000;
	PTE->PDDR |= 0x4000000;
	PTB->PDOR &= ~0x400000;
	PTE->PDOR &= ~0x4000000;*/
	return;
}

void vfnSetCyanLed(void)
{
	SIM->SCGC5 |= 0x400;
	PORTB->PCR[21] |= 0x100;
	PTB->PDDR |= 0x200000;
	PTB->PDOR &= ~0x200000;
	SIM->SCGC5 |= 0x2000;
	PORTE->PCR[26] |= 0x100;
	PTE->PDDR |= 0x4000000;
	PTE->PDOR &= ~0x4000000;

	/*
	SIM->SCGC5 |= 2400;
	PORTB->PCR[21] |= 0x100;
	PORTE->PCR[26] |= 0x100;
	PTB->PDDR |= 0x200000;
	PTE->PDDR |= 0x4000000;
	PTB->PDOR &= ~0x200000;
	PTE->PDOR &= ~0x4000000;*/
	return;
}

void vfnSetPurpleLed(void)
{
	SIM->SCGC5 |= 0x400;
	PORTB->PCR[21] |= 0x100;
	PTB->PDDR |= 0x200000;
	PTB->PDOR &= ~0x200000;
	SIM->SCGC5 |= 0x400;
	PORTB->PCR[22] |= 0x100;
	PTB->PDDR |= 0x400000;
	PTB->PDOR &= ~0x400000;
	return;
}

void vfnSwitchInit(void)
{
	SIM->SCGC5 |= 0x200;
	PORTA->PCR[4] = 0x100;		//Pin as GPIO
	PTA->PDDR &= ~0x10;			//Pin 4 as input
	PORTA->PCR[4] = 0xA0000;	//Interrupt when falling edge
	PORTA->ISFR = 59;
	return;
}

