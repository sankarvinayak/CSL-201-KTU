#include<stdio.h>
#include<stdlib.h>

struct Polynomial
{
	int coeff;
	int pow;
	struct Polynomial* next;
};

void readPolynomial(struct Polynomial** poly)
{
	int coeff, exp, cont;
	struct Polynomial* temp = (struct Polynomial*)malloc(sizeof(struct Polynomial));
	*poly = temp;
	do{
		printf("\nCoefficient: ");
		scanf("%d", &coeff);
		printf("Exponent: ");
		scanf("%d", &exp);
		temp->coeff = coeff;
		temp->pow = exp;
		temp-> next = NULL;
		printf("Have more terms? 1 for y and 0 for no: ");
		scanf("%d", &cont);
		if(cont)
		{
			temp->next = (struct Polynomial*)malloc(sizeof(struct Polynomial));
			temp = temp->next;
			temp->next = NULL;
		}
	}while(cont);
}

void displayPolynomial(struct Polynomial* poly)
{
	while(poly != NULL)
	{
		printf("%dx^%d ", poly->coeff, poly->pow);
		poly = poly->next;
		if(poly != NULL)
			printf("+ ");
	}
}

void addPolynomials(struct Polynomial** result, struct Polynomial* first, struct Polynomial* second)
{
 	struct Polynomial* temp = (struct Polynomial*)malloc(sizeof(struct Polynomial));
 	temp->next = NULL;
 	*result = temp;
 	while(first && second)
 	{
 		if(first->pow > second->pow)
 		{
 			temp->coeff = first->coeff;
 			temp->pow = first->pow;
 			first = first->next;
 		}
 		else if(first->pow < second->pow)
 		{
 			temp->coeff = second->coeff;
 			temp->pow = second->pow;
 			second = second->next;
 		}
 		else
 		{
 			temp->coeff = first->coeff + second->coeff;
 			temp->pow = first->pow;
 			first = first->next;
 			second = second->next;
 		}

 		if(first && second)
 		{
 			temp->next = (struct Polynomial*)malloc(sizeof(struct Polynomial));
 			temp = temp->next;
 			temp->next = NULL;
 		}
 	}
 	while(first || second)
 	{
 		temp->next = (struct Polynomial*)malloc(sizeof(struct Polynomial));
 		temp = temp->next;
 		temp->next = NULL;

 		if(first)
 		{
 			temp->coeff = first->coeff;
 			temp->pow = first->pow;
 			first = first->next;
 		}

 		else if(second)
 		{
 			temp->coeff = second->coeff;
 			temp->pow = second->pow;
 			second = second->next;
 		}
 	}
}

int main()
{

	struct Polynomial* first = NULL;
	struct Polynomial* second = NULL;
	struct Polynomial* result = NULL;

	printf("\nEnter the corresponding data:-\n");
	printf("\nFirst polynomial:\n");
	readPolynomial(&first);
	printf("\n The First polynomial is: \n");
	displayPolynomial(first);
	printf("\nSecond polynomial:\n");
	readPolynomial(&second);
	printf("\nThe Second polynomial is:\n");
	displayPolynomial(second);
	addPolynomials(&result, first, second);
	printf("\n\nThe sum of polynomials is:\n");
	displayPolynomial(result);
	return 0;
}