// Nastase Cristian-Gabriel 315CA
#include <stdio.h>

//functii pentru problema "simple_queries"

void numarul_de_aparitii(int vf[])
{
	unsigned char L;
	scanf("%c", &L);
	if (L == '\n' || L == ' ')
		scanf("%c", &L);

	printf("%c %d\n", L, vf[L]);
}

void topul_literelor(int vf[], int vf2[])
{
	int K, ok = 0;

	//vf2 reprezinta copia vectorului vf. lucram cu copia,
	//deoarece nu dorim sa modificam vectorul nostru de frecventa
	for (int i = 'a'; i <= 'z'; i++)
		vf2[i] = vf[i];

	scanf("%d", &K);

	//parcurgem un for de K ori (K == cate litere dorim sa afisam);
	for (int s = 1; s <= K; s++) {
		int max = -1;
		//stabilim care este maximul;
		for (unsigned char i = 'a'; i <= 'z'; i++) {
			if (max < vf2[i])
				max = vf2[i];
		}
		//parcurgem vectorul si afisam literele care apar
		//de cele mai multe ori. iar apoi indexam cu -2 acea litera,
		//deoarece nu dorim sa afisam aceeasi litera de mai multe ori;
		for (unsigned char j = 'a'; j <= 'z'; j++) {
			if (max == vf2[j]) {
				if (ok == 0) {
					printf("%c", j);
					ok = 1;
				} else {
					printf(" %c", j);
				}

				vf2[j] = -2;
				break;
			}
		}
	}
	printf("\n");
}

void eliminare_litera(int vf[], int *f)
{
	unsigned char L;
	scanf("%c", &L);

	if (L == '\n' || L == ' ')
		scanf("%c", &L);
	*f = *f - vf[L];

	vf[L] = 0;
}

//cel mai mare divizor comun;
int cmmdc(int a, int b)
{
	// if (a > b)
	// return cmmdc(a - b, b);
	// else if (a < b)
	// cmmdc(a, b - a);
	// else
	// return a;

	// -Wall nu ma lasa sa compilez varianta recursiva
	// fara sa mi dea erooare;
	while (a != b)
		if (a > b)
			a -= b;
		else if (a < b)
			b -= a;

	return a;
}

// if-ul respecta toate conditiile impuse de cerinta pentru a se afisa alerta
void alerta(int *f, int *u_a, int vf[])
{
	for (unsigned char i = 'a'; i <= 'z'; i++)
		if (2 * vf[i] >= *f && *u_a >= 5 && vf[i] != *f) {
			*u_a = 0;
			int divizor;
			divizor = cmmdc(vf[i], *f);
			printf("%c %d/%d\n", i, vf[i] / divizor, *f / divizor);
		}
}
