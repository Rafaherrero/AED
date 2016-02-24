//Practica 4 de AED
//Rafael Herrero Alvarez
//rafael.herrero.13@ull.edu.es
#include "dll_t.hpp"
#include "dll_node_t.hpp"
#include "dll_char_node_t.hpp"
#include "stack_char_t.hpp"
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>

using namespace std;

int main (void){

	int opcion=0;
	char cadena[] = "En un lugar de la Mancha de cuyo nombre no quiero acordarme";
	//char balanceo[] = "(((1+2)))*3}-[4/5]))";
	char balanceo[] = "((112 + 4224)*{(234 + 4345))/([10] + 3)}";
	bool balanceo_correcto=true;
	char aux;
	AED::stack_char_t inverse_stack;
	AED::stack_char_t bracket_stack;

	cout << "Bienvenido al programa que le permitirá trabajar con pilas." << endl << "Por Rafael Herrero." << "v1.2.5" << endl << endl;
	cout << "Seleccione una opción:" << endl;
	cout << "1. Utilizar una pila normal." << endl;
	cout << "2. Utilizar un balanceador de símbolos de cierre con una pila." << endl;
	cout << "3. Abandonar este fantástico programa." << endl;
	cout << endl << "Introduzca una opción: ";
	cin >> opcion;

	switch (opcion){
		case 1:
		cout << endl << "La cadena a introducir en la pila es: " << cadena << endl << endl;
		
		for (int i = 0; i < sizeof(cadena)-1; i++)
			inverse_stack.push(cadena[i]);
		
		cout << "La cadena tras pasar por la pila sería: ";

		while (!inverse_stack.empty())
			cout << inverse_stack.pop();
		
		cout << endl;
		break;

		case 2:
		cout << endl << "La operación sometida a estudio es: " << balanceo << endl << endl;

		for (int i = 0; i < sizeof(balanceo)-1 && balanceo_correcto; i++){
			if (balanceo[i]=='('||balanceo[i]==')'||balanceo[i]=='['||balanceo[i]==']'||balanceo[i]=='{'||balanceo[i]=='}'){
				if (balanceo[i]=='('||balanceo[i]=='['||balanceo[i]=='{'){
					bracket_stack.push(balanceo[i]);
				}
				else{
					if (bracket_stack.empty()){
						balanceo_correcto=false;
						cout << "Se esperaba el símbolo que abre '" << balanceo[i] << "'." << endl;
					}
					else{
						aux = bracket_stack.pop();
						if ((!(balanceo[i]==')'&&aux=='('))&&(!(balanceo[i]==']'&&aux=='['))&&(!(balanceo[i]=='}'&&aux=='{'))){
							balanceo_correcto=false;
							cout << "Se esperaba el símbolo que cierra '" << aux << "'." << endl;
						}
					}
				}
			}
		}

		if (!bracket_stack.empty())
			balanceo_correcto=false;

		if (balanceo_correcto)
			cout << "La operación está correctamente balanceada." << endl;
		else
			cout << "La operación NO está correctamente balanceada." << endl;
		break;

		case 3:
		system ("clear");
		cout << "¡Gracias por utilizar este programa!" << endl;
		sleep (2);
		exit (0);

		default: 
		cout << "Opción errónea! " << endl;
	}
}