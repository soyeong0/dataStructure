#include <stdio.h>
#include <stdlib.h>

int main()
{
	double* p1;

	p1 = (double*)malloc(sizeof(double));
	if (p1 == NULL) {
		fprintf(stderr, "�޸𸮰� �����ؼ� �Ҵ��� �� �����ϴ�.\n");
		exit(1);
	}

	*p1 = 23.92;

	free(p1);
	return 0;
}