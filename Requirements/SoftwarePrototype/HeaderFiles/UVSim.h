#pragma once
#include <iostream>
#include <iomanip>
#include "Memory.h"
#include "Accumulator.h"
#include <string>
class UVSim
{
public:
	UVSim();
	void StartProgram();
protected:
	int currentAdress = 0;

	Memory mem;
	Accumulator acmltr;

};


//#ifndef CONSUMER_H
//#define CONSUMER_H
//#include"prodcons.h"
//void* consumer(void* pc);
//#endif