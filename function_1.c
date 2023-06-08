// Nastase Cristian-Gabriel 315CA
#include <stdio.h>

//functii pentru problema "infinite_product"

long long baza8_baza10(long long x)
{
	long long p = 1, y = 0;
	while (x) {
		y = y + x % 10 * p;
		x /= 10;
		p *= 8;
	}
	return y;
}
