// 202313750 권소영
#include <stdio.h>

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101
typedef struct { // 다항식 구조체 타입 선언
	int degree;// 다항식의 차수
	float coef[MAX_DEGREE];// 다항식의 계수
} polynomial;

polynomial poly_sub1(polynomial A, polynomial B)
{// C = A+B 여기서 A와 B는 다항식이다. 구조체가 반환된다. 
	polynomial C;// 결과 다항식
	int Apos = 0, Bpos = 0, Cpos = 0;// 배열 인덱스 변수
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree); // 결과 다항식 차수
	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_a > degree_b) { // A항 > B항
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) { // A항 == B항
			C.coef[Cpos++] = A.coef[Apos++] - B.coef[Bpos++];
			degree_a--;
			degree_b--;
		}
		else {// B항 > A항
			C.coef[Cpos++] = -B.coef[Bpos++];
			degree_b--;
		}
	}
	return C;
}

void print_poly(polynomial p)
{
	for (int i = p.degree; i > 0; i--) {
		if (i != p.degree && p.coef[p.degree - i] >= 0) {
			printf(" + ");
			printf("%3.1fx^%d", p.coef[p.degree - i], i);
		}
		else if (i != p.degree && p.coef[p.degree - i] < 0) {
			printf(" - ");
			printf("%3.1fx^%d", -p.coef[p.degree - i], i);
		}
		else
			printf("%3.1fx^%d", p.coef[p.degree - i], i);
	}
	if (p.coef[p.degree] >= 0) {
		printf(" + %3.1f \n", p.coef[p.degree]);
	}
	else {
		printf(" - %3.1f \n", -p.coef[p.degree]);
	}
}

int main(void)
{
	polynomial a = { 5,{ 3, 6, 0, 0, 0, 10 } };
	polynomial b = { 4,{ 7, 0, 5, 0, 1 } };
	polynomial c;
	print_poly(a);
	print_poly(b);
	c = poly_sub1(a, b);
	printf("-----------------------------------------------------------------------------\n");
	print_poly(c);
	return 0;
}
