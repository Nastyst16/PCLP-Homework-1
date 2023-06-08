// Nastase Cristian-Gabriel 315CA
#include <stdio.h>
#include "function_3.h"
#define NMAX 1001

int main(void)
{
	long long n, a[NMAX][NMAX], distanta = 0;
	scanf("%lld", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%lld", &a[i][j]);
	int x_coord = 0, y_coord = 0;

	while (1) {
		if ((x_coord + y_coord) % 2 == 0) {//inseamna ca e pe alb;
			distanta = distanta + absolut(a[x_coord][y_coord]);

			while (a[x_coord][y_coord] >= n)
				a[x_coord][y_coord] = a[x_coord][y_coord] - n;

			while (a[x_coord][y_coord] < 0)
				a[x_coord][y_coord] = n + a[x_coord][y_coord];

			int aux = a[x_coord][y_coord];
			a[x_coord][y_coord] = 0;

			y_coord = y_coord + aux;
			if (y_coord >= n)
				y_coord = y_coord - n;
		}
		if ((x_coord + y_coord) % 2 == 1) {//inseamna ca e pe negru;
			distanta = distanta + absolut(a[x_coord][y_coord]);

			while (a[x_coord][y_coord] >= n)
				a[x_coord][y_coord] = a[x_coord][y_coord] - n;

			while (a[x_coord][y_coord] < 0)
				a[x_coord][y_coord] = a[x_coord][y_coord] + n;

			int aux = a[x_coord][y_coord];
			a[x_coord][y_coord] = 0;

			x_coord = x_coord + aux;
			if (x_coord >= n)
				x_coord -= n;
		}
		if ((x_coord == 0 && y_coord == 0) || a[x_coord][y_coord] == 0)
			break;
	}

	char sute = 'A' - 1, zeci = 'A' - 1;
	int ok_s = 0, ok_z = 0;

	while (y_coord > 26 * 26) {
		y_coord -= 26 * 26;
		ok_s = 1;
		sute++;
	}
	while (y_coord >= 26) {
		y_coord = y_coord - 26;
		zeci++;
		ok_z = 1;
	}
	printf("%lld\n%lld ", distanta, n - x_coord);

	if (ok_s)
		printf("%c%c%c\n", sute, zeci, 'A' + y_coord);
	if (ok_z)
		printf("%c%c\n", zeci, 'A' + y_coord);
	else
		printf("%c\n", 'A' + y_coord);

	return 0;
}
