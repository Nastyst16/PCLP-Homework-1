// Nastase Cristian-Gabriel 315CA
#include <stdio.h>
#include "function_1.h"
#include <math.h>

int main(void)
{
	long long n, ps;
	unsigned long long a, b, maxa, maxb, a_max, b_max;
	double n_a, n_b;
	ps = 0, n_a = 0, n_b = 0;

	scanf("%lld", &n);
	if (n != 0)
		scanf("%lld%lld", &a, &b);

	a = baza8_baza10(a);
	b = baza8_baza10(b);

	n_a = n_a + a * a;
	n_b = n_b + b * b;

	int a1_ok = 0, b1_ok = 0, b2_ok = 0, a2_ok = 0;

	maxa = a;
	maxb = b;
	ps = ps + a * b;

	for (int i = 0; i < n - 1; i++) {
		scanf("%lld%lld", &a, &b);

		a = baza8_baza10(a);
		b = baza8_baza10(b);

		ps = ps + a * b;
		//urmatoarele if-uri ma ajuta sa determin al doilea max
		if (a < maxa && a2_ok == 0)
			maxa = a;

		a2_ok = 1;

		if (b < maxb && b2_ok == 0)
			maxb = b;

		b2_ok = 1;

		if (maxa < a) {
			a_max = maxa;
			maxa = a;
			a1_ok = 1;
		}

		if (maxb < b) {
			b_max = maxb;
			maxb = b;
			b1_ok = 1;
		}

		if (maxa > a && a_max < a)
			a_max = a;

		if (maxb > b && b_max < b)
			b_max = b;

		n_a = n_a + a * a;
		n_b = n_b + b * b;
	}

	if (n == 0) {
		ps = 0;
		n_a = 0;
		n_b = 0;
	}

	printf("%lld\n", ps);
	if (a1_ok)
		printf("%lld ", a_max);
	else
		printf("-1 ");
	if (b1_ok)
		printf("%lld\n", b_max);
	else
		printf("-1\n");
	printf("%.7f %.7f\n", sqrt(n_a), sqrt(n_b));

	return 0;
}
