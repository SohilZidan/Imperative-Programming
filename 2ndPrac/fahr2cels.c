#include <stdio.h>

double fahr2cels(double);
double cels2fahr(double);

int main()
{
	int fahr;
	double cels;
	for(fahr = -100; fahr <= 400; fahr = fahr + 20)
	{
		cels = fahr2cels(fahr);
		printf("Fahr = %.2f, Cels = %.2f\n", cels2fahr(cels), cels);
	}
	return 0;
}

double fahr2cels(double f)
{
return 5./9.*(f-32);
}

double cels2fahr(double f)
{
return (9./5.*f)+32;
}
