/* Q1 Implement Complex numbers using structures. 
Write functions to add, multiply, subtract two complex numbers 
using pointers to structures and dynamic memory management functions*/

#include<stdio.h>
#include<stdlib.h>

typedef struct{
	double x;
	double y;
}Complex;
	
void read(Complex *a)
{
	printf("Real part : ");
	scanf("%lf", &a->x);
	printf("Imaginary part : ");
	scanf("%lf", &a->y);
	printf("The comlpex number is %lf + i %lf\n", a->x, a->y);
}

Complex Add(Complex a, Complex b)
{
	Complex c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return c;
}

Complex Subtract(Complex a, Complex b)
{
	Complex c;
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	return c;
}

//(x + iy) (c + id) = (xc - yd) + i(xd + yc).
Complex Multiply(Complex a, Complex b)
{
	Complex c;
	c.x = a.x*b.x - a.y*b.y;
	c.y = a.x*b.y + a.y*b.x;
	return c;
}

int main()
{
	Complex *c;
	c = calloc(2,sizeof(Complex));
	for (int i=0; i<2; i++)
	{
		printf("Complex number %d\n",i+1);
		read(c+i);
	}

	Complex sum = Add(c[0], c[1]);
	printf("Sum is %lf + i %lf \n", sum.x, sum.y);

	Complex diff = Subtract(c[0], c[1]);
	printf("Difference is %lf + i %lf \n", diff.x, diff.y);

	Complex product = Multiply(c[0], c[1]);
	printf("Product is %lf + i %lf \n", product.x, product.y);
}
