//Practica 1 AED
//Multiplicacion matrices
//Rafael Herrero Álvarez
//matriz_t_.cpp

#include "matriz_t.hpp"

//Metodo que nos devuelve la posicion de un elemento en el vector
vector_inx_t matrix_t::pos(matrix_inx_t i,matrix_inx_t j)
{
	if ((i<1)||(i>m_)||(j<1)||(j>n_)){
		std::cerr << "Error accediendo a matriz"<< std::endl;
		return 0;
        }
	return (i-1)*n_+j-1;
}

//Metodo que crea un nuevo vector double segun el tamaño pasado
void matrix_t::crearMatriz(void) 
{
	M_= new matrix_item_t [m_*n_];	// Crea un vector de mxn elementos. 
	
	if (M_==NULL)  		// Si ha fallado la reserva de memoria. 
		std::cerr << "Error creando matriz." << std::endl;
}		

//Metodo que nos limpia la memoria
void matrix_t::destruirMatriz(void)
{
	if (M_!=NULL){
		delete [] M_;		// Libera la memoria previamente reservada para la matriz.
		M_=NULL;		// Asigna NULL al puntero.
	}
	m_=0;
	n_=0;
}

//Metodo que redimensiona nuestra matriz y la cambia de tamaño, destruyendo
//la original y creando una nueva
void matrix_t::redimensiona(matrix_inx_t m,matrix_inx_t n)
{
	destruirMatriz();
	m_=m;
	n_=n;
	crearMatriz();
}

//Constructor al que se le pasa el tamaño de la matriz
matrix_t::matrix_t(matrix_inx_t m,matrix_inx_t n):
M_(NULL),
m_(m),
n_(n)
{
	crearMatriz();
	rellenaMatriz();
}	

//Constructor por defecto, de tamaño 0
matrix_t::matrix_t(void):
M_(NULL),
m_(0),
n_(0)
{}		

//Metodo que nos rellena matriz de manera aleatoria
void matrix_t::rellenaMatriz(void)
{
	for(int i = 1; i <= get_m(); i++){
		for (int j=1; j <= get_n();j++){
			double k=rand() % 100 + 1;
			set_matrix_item (i,j,k);
		}
	}
}

//Destructor de la matriz
matrix_t::~matrix_t(void)
{
	destruirMatriz();
}

//Metodo que saca por pantalla la matriz que se pida
void  matrix_t::mostrarMatriz(void)
{
	char aux[80];
	for(int i=1;i<=m_;i++){
		std::cout << "|";	
		for(int j=1;j<=n_;j++){
			sprintf(aux," %10.6lf ",get_matrix_item(i,j));
			cout << aux;
		}
		std::cout << " |";
		cout << endl;
	}
	cout << endl;	
}

//Metodo que devuelve un elemento de la matriz, segun su fila y columna
matrix_item_t matrix_t::get_matrix_item(matrix_inx_t i,matrix_inx_t j)
{
	return M_[pos(i,j)];
}

//Metodo que reemplaza el valor de un elemento de la matriz
void matrix_t::set_matrix_item(matrix_inx_t i,matrix_inx_t j,matrix_item_t it)
{
	M_[pos(i,j)]=it;
}

//Metodo que devuelve el numero de filas de una matriz
matrix_inx_t matrix_t::get_m(void)
{
	return m_;
}

//Metodo que devuelve el numero de columnas de una matriz
matrix_inx_t matrix_t::get_n(void)
{
	return n_;
}

//Metodo que nos permite saber si una matriz es cuadrada o no 
bool matrix_t::cuadrado(void){
if (get_m()==get_n())
	return true;
else
	return false;
}

//Metodo que nos permite saber si unas matrices son multiplicables o no
bool matrix_t::multiplicables(matrix_t& M1, matrix_t& M2){
if (M1.get_n()==M2.get_m())
	return true;
else
	return false;
}

//Metodo que multiplica dos matrices, almacenando el resultado en la matriz llamante
//Para ello creamos una matriz auxiliar, multiplicamos las matrices que les pasamos
//desde el main, y posteriormente copiamos el resultado en la matriz que llama. De
//esta manera, una de las matrices que multiplica puede ser la que llama.
matrix_t& matrix_t::multiplicacion (matrix_t& M1, matrix_t& M2){

if (multiplicables(M1,M2)){

 matrix_t aux (M1.get_m(), M2.get_n());
 	
 	for(int i =1;i<=M1.get_m();i++){
 		for(int j=1;j<=M2.get_n();j++){
 			int auxilio=0;
 		
 			for(int k=1;k<=M1.get_n();k++){
 				auxilio+=M1.get_matrix_item(i,k)*M2.get_matrix_item(k,j);
 			}
 			aux.set_matrix_item(i,j,auxilio);
 		}
 	}
 	aux.mostrarMatriz();
 	redimensiona (aux.get_m(), aux.get_n());
 	
 	for (int i=1; i <= aux.get_m(); i++){
 		for (int j=1; j <= aux.get_n(); j++){
 		set_matrix_item (i,j, aux.get_matrix_item (i,j));
 		}
 	}
 	
 	m_=aux.get_m();
 	n_=aux.get_n();
 	
}

else{

	std::cout << "Estas matrices no son multiplicables" << std::endl;
	
}
	return M1;
}

//Metodo que te permite sumar una columna seleccionada de una matriz
matrix_inx_t matrix_t::sumacolumna (matrix_inx_t j){

int suma = 0;

if (j > get_n()){
	std::cout << "Ha seleccionado un numero mayor de columnas mayor que el disponible" << std::endl;
}

else{
	
	for (int i = 1; i <= get_m(); i++)
		suma += get_matrix_item (i, j);
		
}

return suma;

}

//Metodo que te permite sumar la diagonal de una matriz dada
matrix_inx_t matrix_t::sumadiagonal (void){

int suma = 0;

if (cuadrado()){
	for (int i = 1; i <= get_m(); i++)
		suma += get_matrix_item (i,i);
}

else{

	std::cout << "No se puede sumar la diagonal al no ser cuadrada la matriz" << std::endl;

}
	return suma;
}

// //Metodo que nos permite introducir los valores de la matriz manualmente
// istream& matrix_t::read(istream& is)
// {
// 	int m,n;
// 	is >> m >> n;
// 
// 	redimensiona(m,n);
// 
// 	const int sz=m*n;
// 
// 	for(int i=0;i<sz;i++)
// 		is >> M_[i];
// 	
// }
// 
// //Metodo que nos permite sacar por pantalla los valores de la matriz
// ostream& matrix_t::write(ostream& os)
// {
// 	char aux[80];
// 
// 	sprintf(aux, " %10d  %10d ",m_,n_);
// 	os << aux<<endl;
// 
// 	for(int i=1;i<=m_;i++){
// 		for(int j=1;j<=n_;j++){
// 			sprintf(aux," %10.6lf ",get_matrix_item(i,j));
// 			os << aux;
// 		}
// 		os << endl;
// 	}
// }


