#include <iostream>
#include<cstdlib>
using namespace std;
int contador=0;

struct nodo{
	int dato;
	struct nodo *sig;
};

void menu();
nodo *crearNodo();
void insertarNodo(nodo *&nuevo, nodo *&nini);
void mostrarLista(nodo *inicio);
void validacion(nodo *inicio);
void quitarNodoLista(nodo *&inicio, int valor);
void quitarXPosLista(nodo *&inicio, int posicion, int contador);
void quitarEntreNodos(nodo *&inicio, int li, int lf);
void insertarEntreNodos(nodo *&inicio, int li, int lf, nodo *&nuevo);
void ActualizarNodo(nodo *&inicio, int dato, int nuevodato);


int main(){
	nodo *inicio=NULL;
	int opcion;
	nodo *aux=NULL;

	do{
		menu();
		cout << "ingrese opcion: ";
		cin >> opcion;
		switch(opcion){
			case 0:		cout << "saliendo del programa... :D" << endl;
						break;
			case 1:		aux=crearNodo();
			 			insertarNodo(aux,inicio);
						aux=NULL;
						break;
			case 2:		mostrarLista(inicio);
						cout<<"NULL"<<endl;
						break;
			case 3:		cout<<"Lista Actual: "<<endl;
						mostrarLista(inicio);
						cout<<"NULL"<<endl;
						int elemento;
						cout<<"Ingrese el elemento que eliminara en toda la lista: ";
						cin>>elemento;
						quitarNodoLista(inicio,elemento);
						break;
			case 4:		cout<<"Lista Actual: "<<endl;
						mostrarLista(inicio);
						cout<<"NULL"<<endl;
						int pos;
						cout<<"Ingrese la posicion a elminar (empieza en 0): ";
						cin>>pos;
						quitarXPosLista(inicio,pos,0);
						break;
		case 5:			cout<<"Lista Actual: "<<endl;
						mostrarLista(inicio);
						cout<<"NULL"<<endl;
						int li, lf;
						cout<<"Ingrese nodo izquierdo: ";
						cin>>li;
						cout<<"Ingrese el nodo derecho: ";
						cin>>lf;
						validacion(inicio);
						if(contador>2){
							quitarEntreNodos(inicio,li,lf);
						}else{
							cout<<"No se poseen los nodos suficientes ";
						}
						contador=0;
						break;
		case 6:			cout<<"Lista Actual: "<<endl;
						mostrarLista(inicio);
						cout<<"NULL"<<endl;
						int li2, lf2;
						cout<<"Ingrese el nodo izquierdo: ";
						cin>>li2;
						cout<<"Ingrese el nodo derecho: ";
						cin>>lf2;
						aux=crearNodo();
						insertarEntreNodos(inicio,li2,lf2,aux);
						aux=NULL;
						break;
		case 7:			cout<<"Lista Actual: "<<endl;
						mostrarLista(inicio);
						cout<<"NULL"<<endl;
						int oldvalue, nuevodato;
						cout<<"Ingrese el valor a buscar: ";
						cin>>oldvalue;
						cout<<"Ingrese el valor a cambiar: ";
						cin>>nuevodato;
						ActualizarNodo(inicio,oldvalue,nuevodato);

						break;
			default:	cout << "opcion invalida...."  << endl;
						break;
		}
	}while(opcion != 0);


	return 0;
}

void menu(){
	cout << "*************** MENU ***************" << endl;
	cout << "\t0 - salir" << endl;
	cout << "\t1 - agregar nodo a la lista" << endl;
	cout << "\t2 - mostrar lista" << endl;
	cout << "\t3 - quitar el elemento que ingrese de toda la lista" << endl;
	cout << "\t4 - quitar x posicion de la lista" << endl;
	cout << "\t5 - quitar un nodo que esta entre 2 nodos" << endl;
	cout << "\t6 - insertar nodo entre 2 nodos" << endl;
	cout << "\t7 - Actualizar Nodos" << endl;
	cout << "*************** MENU ***************" << endl;
}

nodo *crearNodo(){
	nodo *nuevo_nodo = new nodo();
	cout<<"Ingrese el dato: ";
	cin>>nuevo_nodo->dato;
	nuevo_nodo->sig=NULL;
	return nuevo_nodo;
}
void mostrarLista(nodo *inicio){
	if(inicio!=NULL){
		cout<<inicio->dato;
		cout<<"->";
		mostrarLista(inicio->sig);
	}

}
//valida que la lista tenga por lo menos 3 nodos para eliminar entre nodos
void validacion(nodo *inicio){
	if(inicio!=NULL){
		contador+=1;
		validacion(inicio->sig);
	}
}


// el "nodo *&inicio" se refiera a que modificaremos al puntero por referencia
//es decir exactamente al valor que apunta esa direccion y no a una copia de este
void quitarNodoLista(nodo *&inicio, int valor){
	nodo *aux=NULL;
	if(inicio!=NULL){
		if(inicio->dato==valor){
			//si el valor del nodo actual es igual al que queremos borrar
			//guardamos al nodo siguiente en el que estamos
			//por ejemplo: la lista 1->2->3->NULL
			//queremos eliminar 2, y actualemte inicio apunta a 2
			//entonces para no perder su siguiente guardamos inicio->sig que es el 3
			aux=inicio->sig;
			//borramos lo que tenga el nodo actual en la memoria
			delete(inicio);
			//lo que guardamos que tenia el nodo siguiente se lo asignamos al actual
			inicio=aux;
			//hacemos la llamada recursiva si queremos eliminar todos los numeros que
			//sean iguales a valor
			//de lo contrario solo eliminara el primero que encuentre que
			//concuerde con valor
			//enviamos inicio y no inicio->sig ya que al eliminar el nodo y hacer inicio=aux ya estamos en inicio->sig
			quitarNodoLista(inicio,valor);
		}else{
			//unicamente pasamos al nodo siguiente recursivamente
			quitarNodoLista(inicio->sig,valor);
		}
	}
}

void quitarXPosLista(nodo *&inicio, int posicion, int contador){
	nodo *aux=NULL;
	if(inicio!=NULL){
		if(contador==posicion){
			//si el valor del nodo actual es igual al que queremos borrar
			//guardamos al nodo siguiente en el que estamos
			aux=inicio->sig;
			//borramos lo que tenga el nodo actual en la memoria
			delete(inicio);
			//lo que guardamos que tenia el nodo siguiente se lo asignamos al actual
			inicio=aux;
		}else{
			//unicamente pasamos al nodo siguiente recursivamente
			contador=contador+1;
			quitarXPosLista(inicio->sig,posicion,contador);
		}
	}
}


void ActualizarNodo(nodo *&inicio, int dato, int nuevodato){
	if(inicio!=NULL){
		if(inicio->dato==dato){
			inicio->dato=nuevodato;
			//ActualizarNodo(inicio->sig,dato,nuevodato);
		}else{
			ActualizarNodo(inicio->sig,dato,nuevodato);
		}
	}
}

void quitarEntreNodos(nodo *&inicio, int li, int lf){
	nodo *aux=NULL;
	if(inicio!=NULL){
		if(inicio->dato==li && inicio->sig->sig->dato==lf){
			//si el valor del nodo actual es igual al que queremos borrar
			//guardamos al nodo siguiente en el que estamos
			aux=inicio->sig->sig;
			//borramos lo que tenga el nodo actual en la memoria
			delete(inicio->sig);
			//lo que guardamos que tenia el nodo siguiente se lo asignamos al actual
			inicio->sig=aux;


		}else{
			//unicamente pasamos al nodo siguiente recursivamente

			quitarEntreNodos(inicio->sig,li,lf);
		}
	}else{
		cout<<"tanto el nodo izquierdo como derecho no existen consecutivamente";
	}
}

void insertarEntreNodos(nodo *&inicio, int li, int lf, nodo *&nuevo){
	nodo *aux=NULL;
	if(inicio!=NULL){
		if(inicio->dato==li && inicio->sig->dato==lf){
			aux=inicio->sig;
			inicio->sig=nuevo;
			nuevo->sig=aux;
		}else{
			//unicamente pasamos al nodo siguiente recursivamente

			insertarEntreNodos(inicio->sig,li,lf,nuevo);
		}
	}else{
		cout<<"tanto el nodo izquierdo como derecho no existen consecutivamente";
	}
}


void insertarNodo(nodo *&nuevo, nodo *&ini){

	if(ini==NULL){//el primer nodo
		ini=nuevo;
	}else{//en caso de ser cualquier otro nodo
		insertarNodo(nuevo,ini->sig);
	}
}