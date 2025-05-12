#include "Edge.h"
#include "stdio.h"

Edge::Edge()
{

}

Edge::~Edge()
{

}

int Edge::count = 1;

Edge::Edge(Node s, Node e, Weight w)
{
	start = s;
	end = e;
	weight = w;
}

Node Edge::getStart()const
{
	return start;
}

Node Edge::getEnd()const
{
	return end;
}

Weight Edge::getWeight()const
{
	return weight;

}

int GetFactorial(int n)
{
	if (n == 0)
		return 1;
	else
	{
		int i, j = 1;
		for (i = 1; i <= n; i++)
			j *= i;
		return j;
	}
}

double getE()
{
	double sum = 0, j = 0;
	int i = 0, k = 0;
	for (i = 0; i < 10; i++)
	{
		k = GetFactorial(i);
		j = 1.0 / k;
		sum += j;
	}
	return sum;
}

double Edge::getCarFuncValue()
{
	double x = weight.getCarNum() / weight.getCarCapacity();
	double n = 0;
	if (x <= CFunc)
	{
		n = (1 * CFront * weight.getLength());
	}
	else
	{
		n = ((1 + getE() * x) * CFront * weight.getLength());
	}
	return n;
}

double Edge::getCarStream()
{
	double sum = 0;
	sum = (double)weight.getCarNum() / this->getCarFuncValue();
	return sum;
}

void Edge::setStart(Node s)
{
	this->start = s;
	return;
}

void Edge::setEnd(Node e)
{
	this->end = e;
	return;
}

void Edge::setWeight(Weight w)
{
	this->weight = w;
	return;
}

void Edge::print()
{
	cout <<count++<< " 新边的信息为：" << start.getId() << "(" << start.getX() << "," << start.getY() << ")->" << end.getId() << "(" << end.getX() << "," << end.getY() << ")" << "  长度为" << setiosflags(ios::fixed) << setprecision(3) << weight.getLength() << endl;
}