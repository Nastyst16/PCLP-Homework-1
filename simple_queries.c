// Nastase Cristian-Gabriel 315CA
#include <stdio.h>
#include "function_2.h"
#define NMAX 123

int main(void)
{
	int vf[NMAX] = {0}, vf2[NMAX] = {0};
	unsigned char n;
	int *f, *u_a, frecventa = 0, ultima_alerta = 0, stop = 0;
	f = &frecventa;
	u_a = &ultima_alerta;

	do {
		scanf("%c", &n);
		if (n == '\n')
			scanf("%c", &n);

		switch (n) {
		case 'Q':

		numarul_de_aparitii(vf);
			break;

		case 'T':

		topul_literelor(vf, vf2);
			break;

		case 'E':

		eliminare_litera(vf, f);
			break;

		case 'X':
			n = '.';

		break;

		default:
			//monitorizam frecventa, timpul de cand ultima alerta
			//a fost afisata.
			vf[n]++; frecventa++; ultima_alerta++;
			alerta(f, u_a, vf);
		}
		//aveam aceste conditii negate in while, doar ca nu am voie
		//sa am mai mult de 80 de caractere pe aceeasi linie,
		//asa ca am impartit conditia in doua if-uri, pentru a
		//scapa de warning;
		if (n < 'a' || n > 'z')
			if (n != 'Q' && n != 'T' && n != 'E' && n != 'X')
				stop = 1;
	} while (!stop);

	return 0;
}
