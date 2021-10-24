/*
다항식 덧셈1
: 최고차항을 이용(0)
*/

#include <stdio.h>
#define MAX(a,b) ( ((a)>(b)) ? (a) : (b)) // 둘 중 큰 값 리턴
#define MAX_DEGREE 101

typedef struct {
	int degree; //최고차수
	float coef[MAX_DEGREE]; //계수
}polynomial;

polynomial poly_add1(polynomial A, polynomial B) {
	polynomial C;
	int Apos = 0, Bpos = 0, Cpos = 0;
	int degree_a = A.degree;
	int degree_b = B.degree;

	C.degree = MAX(A.degree, B.degree); //둘 중 큰 차수를 C의 차수로 선택, 헤더 참고

	while (Apos <= A.degree && Bpos <= B.degree) { // A 인덱스가 A 최고차수보다 작고, B 인덱스가 B 최고차수보다 작을 때 반복
		if (degree_a > degree_b) { //A의 차수가 B의 차수보다 크다면
			C.coef[Cpos++] = A.coef[Apos++]; //A의 계수를 C의 계수에 대입
			degree_a--;
		}
		else if (degree_a == degree_b) { //A차수와 B차수가 같다면
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--; degree_b--;
		}
		else {
			C.coef[Cpos++] == B.coef[Bpos++];
			degree_b--;
		}
	}
	return C;
}

void main() {
	polynomial a = { 5,{3,6,0,0,0,10} };
	polynomial b = { 4,{7,0,5,0,1} };
	polynomial c;
	c = poly_add1(a, b);
	
	printf("polynomial c= ");
	for (int i = 0; i <= c.degree; i++) {
		printf("%.2fx^%d", c.coef[i], c.degree - i);
		if (i < c.degree)
			printf("+ ");
	}
	printf("\n");
}