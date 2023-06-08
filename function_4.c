// Nastase Cristian-Gabriel 315CA
#include <stdio.h>
#define NMAX 401

void posibilitati_linie(int v[], int a[][NMAX], int N)
{
	int X;
	//initializam un vector cu 1
	for (int i = 1; i <= N * N; i++)
		v[i] = 1;

	scanf("%d", &X);
	//daca gasim valoarea "x" de a lungul liniei
	//v[x] = 0
	for (int j = 0; j < N * N; j++)
		if (a[X - 1][j] != 0)
			v[a[X - 1][j]] = 0;

	for (int i = 1; i <= N * N; i++)
		printf("%d ", v[i]);

	printf("\n");
}

//explicatia este aceeasi
void posibilitati_coloana(int v[], int a[][NMAX], int N)
{
	for (int i = 1; i <= N * N; i++)
		v[i] = 1;

	int Y;
	scanf("%d", &Y);
	for (int i = 0; i < N * N; i++)
		if (a[i][Y - 1] != 0)
			v[a[i][Y - 1]] = 0;

	for (int i = 1; i <= N * N; i++)
		printf("%d ", v[i]);

	printf("\n");
}

//explicatia este aceeasi
void posibilitati_careu(int v[], int a[][NMAX], int N)
{
	for (int i = 1; i <= N * N; i++)
		v[i] = 1;

	int Z, cnt = 0;
	scanf("%d", &Z);
	while (Z > N) {
		cnt += 3;
		Z -= N;
	}

	Z = (Z - 1) * N;
	for (int i = cnt; i < cnt + N; i++)
		for (int j = Z; j < Z + N; j++)
			if (a[i][j] != 0)
				v[a[i][j]] = 0;

	for (int i = 1; i <= N * N; i++)
		printf("%d ", v[i]);

	printf("\n");
}

int posibilitati_coordonate(int v[], int a[][NMAX], int N)
{
	int X, Y, i_cadran, j_cadran;
	scanf("%d%d", &X, &Y);
	X--;
	Y--;

	//daca patratul este deja ocupat afisam N*N zerouri
	if (a[X][Y] != 0) {
		for (int i = 1; i <= N * N; i++) {
			v[i] = 0;
			printf("%d ", v[i]);
		}
		printf("\n");
		return 0;
	}

	for (int i = 1; i <= N * N; i++)
		v[i] = 1;

	for (int l = 0; l < N * N; l++)
		if (a[X][l] != 0 && Y != l && a[X][Y] == 0)
			v[a[X][l]] = 0;

	for (int c = 0; c < N * N; c++)
		if (a[c][Y] != 0 && X != c && a[X][Y] == 0)
			v[a[c][Y]] = 0;

	i_cadran = X; j_cadran = Y;

	//calculam cadranul in care ne aflam
	//si cautam coordonatele de pe pozitia stanga-sus
	//a careului/cadranului
	while (i_cadran % N != 0)
		i_cadran--;
	while (j_cadran % N != 0)
		j_cadran--;

	//parcurgem careul in care ne aflam
	for (int u = i_cadran; u < i_cadran + N; u++)
		for (int w = j_cadran; w < j_cadran + N; w++)
			if (a[X][Y] == 0 && a[u][w] != 0 && X != u && Y != w)
				v[a[u][w]] = 0;

	for (int i = 1; i <= N * N; i++)
		printf("%d ", v[i]);

	printf("\n");
	return 0;
}

void adaugare_numar(int a[][NMAX])
{
	int X, Y, C;
	scanf("%d%d%d", &X, &Y, &C);
	if (a[X - 1][Y - 1] == 0)
		a[X - 1][Y - 1] = C;
}

void stare_curenta(int v[], int a[][NMAX], int N)
{
	int ok_1 = 0, ok_2 = 1;
	//urmeaza sa parcurgem fiecare linie/coloana/careu in parte
	//facem un vector de frecventa, iar daca gasim aceeasi
	//valoare pe o linie/coloana/careu care se repeta de doua ori
	//inseamna ca jocul este invalid;
	//parcurgem fiecare careu in parte cu ajutorul acestor for-uri
	//mergem din N in N si pe linie si pe coloana si asfel stim
	//pozitia din stanga-sus a careului;
	for (int i_cadran = 0; i_cadran < N * N; i_cadran = i_cadran + N) {
		for (int j_cadran = 0; j_cadran < N * N; j_cadran = j_cadran + N) {
			for (int i = 1; i <= N * N; i++)
				v[i] = 0;

			for (int k = i_cadran; k < i_cadran + N; k++) {
				for (int l = j_cadran; l < j_cadran + N; l++) {
					if (a[k][l] == 0)
						ok_1 = 1;
					if (a[k][l] != 0)
						v[a[k][l]]++;

					if (v[a[k][l]] >= 2) {
						ok_2 = 0;
						break;
					}
				}
			}
			if (ok_2 == 0)
				break;
		}
		if (ok_2 == 0)
			break;
	}
	//reinitializam vectorul de frecventa cu 0;
	for (int i = 1; i <= N * N; i++)
		v[i] = 0;
	//linii
	for (int i = 0; i < N * N; i++) {
		for (int j = 0; j < N * N; j++) {
			if (a[i][j] == 0)
				ok_1 = 1;

			if (v[a[i][j]] != 0 && a[i][j] != 0)
				v[a[i][j]]++;

			if (v[a[i][j]] >= 2)
				ok_2 = 0;

			if (ok_2 == 0)
				break;
		}
		if (ok_2 == 0)
			break;
	}

	for (int i = 1; i <= N * N; i++)
		v[i] = 0;
	//coloane
	for (int j = 0; j < N * N; j++) {
		for (int i = 0; i < N * N; i++) {
			if (v[a[i][j]] != 0 && a[i][j] != 0)
				v[a[i][j]]++;

			if (v[a[i][j]] >= 2) {
				ok_2 = 0;
				break;
			}
		}
		if (ok_2 == 0)
			break;
	}
	if (ok_2 == 0)
		printf("1\n");
	else	if (ok_1 == 1)
		printf("0\n");
	else
		printf("2\n");
}

void citire_sudoku(int a[][NMAX], int N)
{
	for (int i = 0; i < N * N; i++)
		for (int j = 0; j < N * N; j++)
			scanf("%d", &a[i][j]);
}
