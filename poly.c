#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101

typedef struct{
	int degree;
	float coef[MAX_DEGREE];
} polynomial;

// C = A+B, where A and B are polynomails.
polynomial poly_add1(polynomial A, polynomial B){
	polynomial C;
	int Apos=0, Bpos=0, Cpos=0;
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree); // degree of a polynomial C

	while(Apos<=A.degree && Bpos<=B.degree){
		if(degree_a > degree_b){
			C.coef[Cpos++]=A.coef[Apos++];
			degree_a--;
		}
		else if(degree_a==degree_b){
			C.coef[Cpos++]=A.coef[Apos++]+B.coef[Bpos++];
			degree_a--; degree_b--;
		}
		else{
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	}
	return C;
}
void main(){
	polynomial A = {4,{3,0,12,0,7}};
	polynomial B = {2,{11,7,9}};
	polynomial C;
	C = poly_add1(A,B);

	for(int i=0; i<=C.degree; i++){
		printf("%.0lf ", *(C.coef+i));
	}
}
