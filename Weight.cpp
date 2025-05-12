#include "Weight.h"

Weight::Weight()
{
	this->length = 0;
	this->carNum = rand() % (MaxCapacity + 10);
	srand((unsigned)time(NULL));
	this->carCapacity = rand() % (MaxCapacity - MinCapacity + 1) + MinCapacity;
}

Weight::Weight(double l, int cn)
{
	this->length = l;
	this->carNum = cn;
	srand((unsigned)time(NULL));
	this->carCapacity = rand() % (MaxCapacity - MinCapacity + 1) + MinCapacity;
}

double Weight::getLength()const
{
	return this->length;
}

void Weight::setLength(double l)
{
	this->length = l;
}

double Weight::getCarNum()const
{
	return this->carNum;
}

void Weight::setCarNum(double cn)
{
	this->carNum = cn;
}

double Weight::getCarCapacity()const
{
	return this->carCapacity;
}

void Weight::setCarCapacity(double cc)
{
	this->carCapacity = cc;
}