// Nastase Cristian-Gabriel 315CA
#include <stdio.h>
#include "function_4.h"
#define NMAX 401

int main(void)
{
	int N, M, a[NMAX][NMAX], caz, v[NMAX], q = 0;

	scanf("%d%d", &N, &M);
	citire_sudoku(a, N);

	do {
		scanf("%d", &caz);
		q++;

		switch (caz) {
		case 1:

			posibilitati_linie(v, a, N);
				break;
		case 2:

			posibilitati_coloana(v, a, N);
				break;
		case 3:

			posibilitati_careu(v, a, N);
				break;
		case 4:

			posibilitati_coordonate(v, a, N);
				break;

		case 5:

			adaugare_numar(a);
				break;

		case 6:

			stare_curenta(v, a, N);
				break;

		default:
			break;
		}

	} while (q != M);

	return 0;
}
