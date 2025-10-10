
#include <stdio.h>
//CONCEPT DU BITSHIFTING
int main()
{
	int a = 21; //10101 en binaire

	a = a << 1; //deviens 101010 en binaire
	printf("%d\n", a);

	a = a << 1; //deviens 1010100 en binaire
	printf("%d\n", a);


	int b = 100; //1100100 en binaire

	b = b >> 1;  //deviens 110010
	printf("%d\n", b);

	b = b >> 1; //deviens 11001
	printf("%d\n", b);

	// b = b >> 1; //deviens 1100
	// printf("%d\n", b);

	if (b & (1 == 1))
		printf("1");
	else
		printf("0");
}