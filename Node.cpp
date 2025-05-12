#include "Node.h"

Node::Node()
{
	this->x = 0;
	this->y = 0;
	this->id = 0;
}

Node::Node(const int x, const int y, const int id, const int sub, const int c)
{
	this->x = x;
	this->y = y;
	this->id = id;
	this->cluster[sub] = c;
}

Node::~Node()
{

}

int Node::getX()const
{
	return this->x;
}

int Node::getY()const
{
	return this->y;
}

int Node::getId()const
{
	return this->id;
}

int Node::getCluster(int sub) const
{
	return this->cluster[sub];
}

void Node::setX(int x)
{
	this->x = x;
}

void Node::setY(int y)
{
	this->y = y;
}

void Node::setId(int id)
{
	this->id = id;
}

void Node::setCluster(int sub, int c)
{
	this->cluster[sub] = c;
}
