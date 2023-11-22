#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
using namespace std;

char *ingreso(char*);

char *ingreso(char* msj){
    char datos[10];
    char c;
    int i=0;
    
    system("cls");
    cout<<msj<<endl;
    
    while ((c=getch())!=13){ //getch sin eco, la tecla que presiono no me va a mostrar
        if (c>='0'&&c<='9'){
            printf("%c",c);
            datos[i++]=c;
        }
        
    } 
    datos[i]='\0';
    return datos;
}

int main(int argc, char** argv) {
	char datos[10];//corchetes es sinonimo de unidimensional y asi
	int valor;
	strcpy(datos,ingreso("ingrese el valor numerico")); //lo que tiene en ingresos dejar en datos
	//se usa para hacer datos=ingreso("ingrese el valor numerico");
	valor = atoi(datos);	
	cout<<"\n"<<datos;
	return 0;
}
