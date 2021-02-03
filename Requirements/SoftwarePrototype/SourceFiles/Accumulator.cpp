#include "Accumulator.h"

Accumulator::Accumulator(Memory* mem)
	:mMemory(mem)
{
}

Accumulator::~Accumulator()
{
}

void Accumulator::RunProgram()
{
	cout << "*** Program execution begins ***" << endl;
	
	while (mOperationCode != 43)
	{
		LoadInstruction();
		switch (mOperationCode)
		{
		case 10:
			ReadToMemory();
			break;
		case 11:
			WriteToScreen();
			break;
		case 20:
			LoadFromMemoryToReg();
			break;
		case 21:
			StoreToMemory();
			break;
		case 30:
			Add();
			break;
		case 31:
			Subtract();
			break;
		case 32:
			Divide();
			break;
		case 33:
			Multiply();
			break;
		case 40:
			Branch();
			break;
		case 41:
			BranchNeg();
			break;
		case 42:
			BranchZero();
			break;
		default:
			cout << "ERROR: Reached default on switch statement in RunProgram() in Accumulator class." << endl;
		}
	};

	return;
}

void Accumulator::LoadInstruction()
{
	// Gets word from memory, store into seperate variable so it doesn't accidentally get changed below
	int num = mMemory->LoadFromMemory(mInstructionMemoryAddress);

	// Stores the number into Accumulator class
	mInstructionRegister = num;

	// Seperates the number into two parts, the first half and second half
	unsigned int divisor = 10;

	while (num / divisor > divisor)
		divisor *= 10;

	// First two numbers
	mOperationCode = num / divisor;
	// Last two numbers
	mOperand = num % divisor;

	return;
}

void Accumulator::ReadToMemory()
{
	int input;
	cout << "Enter an integer: ";
	cin >> input;
	cout << endl;
	mMemory->StoreValue(mOperand, input);

	return;
}

void Accumulator::WriteToScreen()
{
	int num = mMemory->LoadFromMemory(mOperand);

	cout << "Contents of " << mOperand << " is " << num << endl;

	return;
}

void Accumulator::LoadFromMemoryToReg()
{
	mRegister = mMemory->LoadFromMemory(mOperand);

	return;
}

void Accumulator::StoreToMemory()
{
	mMemory->StoreValue(mOperand, mRegister);

	return;
}

void Accumulator::Add()
{
	mRegister += mMemory->LoadFromMemory(mOperand);
	mIntructionCounter++;
	
	return;
}

void Accumulator::Subtract()
{
	mRegister -= mMemory->LoadFromMemory(mOperand);
	mInstructionCounter++;
	
	return;
}

void Accumulator::Divide()
{
	mRegister /= mMemory->LoadFromMemory(mOperand);
	mInstructionCounter++;
	
	return;
}

void Accumulator::Multiply()
{
	mRegister *= mMemory->LoadFromMemory(mOperand);
	mInsturctionCounter++;
	
	return;
}

void Accumulator::Branch()
{
	 
}

void Accumulator::BranchNeg()
{
	if (mRegister < 0) {
		
	}
}

void Accumulator::BranchZero()
{
	if (mRegister == 0) {
		
	}
}

void Accumulator::DisplayAccumulator()
{
	cout << "REGISTER: " << endl;
	cout << "Accumulator:        \t";
	if (mRegister < 10) {
		cout << "000";
	}
	else if (mRegister < 100 && mRegister > 9) {
		cout << "00";
	}
	else if (mRegister <= 999 & mRegister > 99) {
		cout << "0";
	}
	cout << mRegister << endl;
	
	cout << "InsturctionCounter:  \t";
	if (mInstructionCounter < 10) {
		cout << "0";
	}
	cout << mInsturctionCounter << endl;
	
	cout << "InstructionRegister:\t"; 
	if (mInsturctionRegister < 10) {
		cout << "000";
	}
	else if (mInstructionRegister < 100 && mInstructionRegister > 9) {
		cout << "00";
	}
	else if (mInstructionRegister <= 999 && mInsturctionRegister > 99) {
		cout << "0";
	}
	cout << mInsturctionRegister << endl;
	
	cout << "OperationCode: \t";
	if (mOperationCode < 10) {
		cout << "0";
	}
	cout << mOperationCode << endl;
	
	cout << "Operand:  \t";
	if (mOperand < 10) {
		cout << "0";
	}
	cout << mOperand << endl;
}

