#include <iostream>


int main(int argc, char** argv) {
	int a = 20;
	int *p, **q, *t;
	printf("\nEl valor de a = %d", a);
	p=&a;
	printf("\nLa direccion de a = %d", &a);
	printf("\nLa direccion de a por medio de p = %p", p);
	printf("\nEl valor de a por medio de p = %d", *p);	
	printf("\nLa direccion de p = %p", &p);
	q=&p;
	printf("\nLa direccion de a por medio de q = %p", *q);	
	printf("\nLa direccion de p por medio de q = %p", q);	
	printf("\nEl valor de a por medio de q = %d", **q);	
	printf("\nEl valor de a en octal = %o", a);
	
	printf("\nDireccion de t = %p", &t);
	t=t+1;
	printf("\nDireccion de t = %p", &t);
	
	return 0;
}
