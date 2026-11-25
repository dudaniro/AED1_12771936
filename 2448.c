#include <stdio.h>
#include <stdlib.h>

#define MAX 45100

static long casas[MAX];

static long busca(const long *v, long tam, long chave)
{
	long low = 1, hi = tam;

	while (low <= hi) {
		long mid = low + (hi - low) / 2;

		if (chave < v[mid])
			hi = mid - 1;
		else if (chave > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

int main(void)
{
	long n, m, i;
	long pos = 1, tempo = 0;

	if (scanf("%ld %ld", &n, &m) != 2)
		return 1;

	for (i = 1; i <= n; ++i)
		scanf("%ld", &casas[i]);

	for (i = 1; i <= m; ++i) {
		long carta;
		scanf("%ld", &carta);

		long x = busca(casas, n, carta);
		tempo += labs(x - pos);
		pos = x;
	}

	printf("%ld\n", tempo);
	return 0;
}
