#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct PolyInfo {
	int coeff;
	int expo;
	struct PolyInfo *next;
};

typedef struct PolyInfo *Poly;
typedef struct PolyInfo *Position;

Poly create() {
	Position header = (Position)malloc(sizeof(struct PolyInfo));
	header->next = NULL;
	header->expo = INT_MAX;
	return header;
}

void insert(Poly pL, int coeff, int expo) {
	while (pL->next != NULL && pL->next->expo >= expo)
		pL = pL->next;
	if (pL->expo == expo)
		pL->coeff += coeff;
	else {
		Position newNode = (Position)malloc(sizeof(struct PolyInfo));
		newNode->coeff = coeff;
		newNode->expo = expo;
		newNode->next = pL->next;
		pL->next = newNode;		
	}
}

Poly add(Poly pL1, Poly pL2) {
	Poly SUM = create();
	pL1 = pL1->next;
	pL2 = pL2->next;
	
	while (pL1 != NULL) {
		insert(SUM, pL1->coeff, pL1->expo);
		pL1 = pL1->next;
	}
	
	while (pL2 != NULL) {
		insert(SUM, pL2->coeff, pL2->expo);
		pL2 = pL2->next;
	}
	return SUM;
}

Poly multiply(Poly pL1, Poly pL2) {
	Poly MULTI = create();
	pL1 = pL1->next;
	pL2 = pL2->next;
	while (pL1 != NULL) {
		Position temp;
		temp = pL2;
		while (pL2 != NULL) {
			insert(MULTI, pL1->coeff * pL2->coeff, pL1->expo + pL2->expo);
			pL2 = pL2->next;
		}
		pL2 = temp;
		pL1 = pL1->next;		
	}
	return MULTI;
}

void show_poly(Poly pL) {
	pL = pL->next;
	while (pL != NULL) {
		printf("%dx^%d ", pL->coeff, pL->expo);
		pL = pL->next;
	}
	printf("\n");
}

int main() {	
	Poly P1, P2, SUM, MULTI;
	P1 = create();
	P2 = create();
	insert(P1, 10, 3); insert(P1, 4, 2); insert(P1, 7, 0);
	insert(P2, 5, 1); insert(P2, -3, 0); 
	show_poly(P1);
	show_poly(P2);
	SUM = add(P1, P2);
	printf("SUM = ");
	show_poly(SUM);
	MULTI = multiply(P1, P2);
	printf("MULTIPLY = ");
	show_poly(MULTI);
	
	return 0;
}