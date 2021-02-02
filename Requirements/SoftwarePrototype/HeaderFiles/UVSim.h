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
	
	
	//Some generic functions to parse an integer from the string
        //credit to stack overflow help
	template<typename T>
	std::string ToString(const T& v)
	{
		std::ostringstream ss;
		ss << v;
		return ss.str();
	}

	template<typename T>
	T FromString(const std::string& str)
	{
		std::istringstream ss(str);
		T ret;
		ss >> ret;
		return ret;
	}

};


//#ifndef CONSUMER_H
//#define CONSUMER_H
//#include"prodcons.h"
//void* consumer(void* pc);
//#endif
