#pragma once
class AList//abstrakcyjna lista
{
private:
protected:
	unsigned int size;
public:
	virtual bool empty() = 0;
};