#include "Cubic.h"

int Cubic::getVertex(float*& ver)
{
	ver = vertexs;
	return 24;
}

int Cubic::getIncides(int*& inci)
{
	inci = incides;
	return 36;
}
