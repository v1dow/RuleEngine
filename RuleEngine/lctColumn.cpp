#include "lctColumn.h"

lctColumn::lctColumn()
{
	attr = 0;
	column = new COLUMN();
}

lctColumn::lctColumn(int attr)
{
	this->attr = attr;
	column = new COLUMN();
}

lctColumn::~lctColumn()
{
	delete column;
}

COLUMN* lctColumn::GetColumn()
{
	return this->column;
}

int lctColumn::GetAttr()
{
	return this->attr;
}