#include <iostream>//Librerías
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Nodo{//Estructura Nodo
	int dato;
	Nodo *der;
	Nodo *izq;
	Nodo *padre;
};

//Prototipos de las funciones
void menu();//Función para crear un menú
Nodo *crearNodo(int, Nodo *);//Función crearNodo
void insertarNodo(Nodo *&, int, Nodo *);//Funcion parar insertar los nodos en el arbol
void mostrarArbol(Nodo *, int);//Funcion para mostrar el árbol
bool busqueda(Nodo *, int);//Función de tipo booleana para buscar un nodo
void preOrden(Nodo *);//Función para recorrido en preOrden
void inOrden(Nodo *);//Función para el recorrido en inorden
void postOrden(Nodo *);//Función para el recorrido en postOrden
void eliminar(Nodo *, int);//Función para eliminar un nodo de tipo enteero
void eliminarNodo(Nodo *); //Funcion para eliminar un nodo
Nodo *minimo(Nodo *);//Función de tipo nodo 
void reemplazar(Nodo *, Nodo *);//Función para reemplazar 
void destruirNodo(Nodo *);//Función para destruir un nodo

Nodo *arbol=NULL;//Creación del árbol iniciandolo con un valor nulo

int main() {//Función principal
	menu();
	
	getch();
	return 0;
}

//Función del menu
void menu(){
	int dato, opcion, contador=0;
	do{	
		cout<<"\t .:MENU:."<<endl;
		cout<<"1. Insertar un Nodo"<<endl;
		cout<<"2. Mostrar arbol completo"<<endl;
		cout<<"3. Buscar un nodo en el arbol"<<endl;
		cout<<"4. Recorrido en preOrden "<<endl;
		cout<<"5. Recorrido en inOrden"<<endl;
		cout<<"6. Recorrido en postOrden"<<endl;
		cout<<"7. Eliminar un nodo del arbol"<<endl;
		cout<<"8. Salir"<<endl;
		cout<<"Digite la opcion que desea: ";
		cin>>opcion;
		
		switch(opcion){
			case 1: cout<<"\nIntroduzca el nodo: ";
					cin>>dato;
					insertarNodo(arbol, dato, NULL);
					cout<<"\n";
					break;
			case 2:	
					cout<<"\nMostrando el arbol completo: \n\n";
					if(arbol==NULL){
						cout<<"El arbol esta vacio \n";
					}else{
						mostrarArbol(arbol, contador);
					}
					cout<<"\n";
					break;
			case 3: 
					cout <<"\nIntroduzca el nodo que desea buscar: ";
					cin>>dato;
					if(busqueda(arbol, dato)==true){
						cout<<"El nodo "<<dato <<" ha sido encontrado en el arbol\n";
					}else{
							cout<<"\nNodo no encontrado\n";
					}
					cout<<"\n";
					break;
			case 4: 
					if(arbol==NULL){
						cout<<"El arbol esta vacio \n";
					}else{
						cout<<"\nRecorrido en PreOrden: ";
						preOrden(arbol);
					}
					cout<<"\n\n";
					break;
			case 5: if(arbol==NULL){
						cout<<"El arbol esta vacio \n";
					}else{
						cout<<"\nRecorrido en InOrden: ";
						inOrden(arbol);
					}
					cout<<"\n\n";
					break;
			case 6: if(arbol==NULL){
						cout<<"El arbol esta vacio \n";
					}else{
						cout<<"\nRecorrido en postOrden: ";
						postOrden(arbol);
					}
					cout<<"\n\n";
					break;
			case 7: cout<<"\nIntroduzca el nodo que desea eliminar (excepto la raiz): ";
					cin>>dato;
					if(busqueda(arbol, dato)==true){
						eliminar(arbol, dato);
						cout<<"El nodo "<<dato <<" ha sido eliminado del arbol\n";
					}else{
						cout<<"\nNodo no encontrado\n";
					}
					cout<<"\n";
					break;
				
		}
	}while(opcion!=8);
}

//Función para crear un  nuevo nodo
Nodo *crearNodo(int n, Nodo *padre){
	Nodo *nuevo_nodo=new Nodo();
	
	nuevo_nodo->dato=n;
	nuevo_nodo->der=NULL;
	nuevo_nodo->izq=NULL;
	nuevo_nodo->padre=padre; 
	
	return nuevo_nodo;//Retorna el nuevo_nodo creado.
}

//Función para insertar nodos en el arbol
void insertarNodo(Nodo *&arbol, int n, Nodo *padre){
	if (arbol==NULL){
		Nodo *nuevo_nodo=crearNodo(n, padre);
		arbol=nuevo_nodo;
	}else{
		int valorRaiz=arbol->dato;
		if(n<valorRaiz){
			insertarNodo(arbol->izq, n, arbol);
		}else{
			insertarNodo(arbol->der, n, arbol);
		}
	}
}

//Función para mostrar el árbol completo
void mostrarArbol(Nodo *arbol, int cont){
	if(arbol==NULL){
		return;
	}else{
		mostrarArbol(arbol->der, cont+1);
		for(int i=0; i<cont; i++){
			cout<<"   ";
		}
		cout <<arbol->dato<<endl;
		mostrarArbol(arbol->izq, cont+1);
	}
}


//Función para buscar un elemento en el árbol
bool busqueda(Nodo *arbol, int n){
	if(arbol==NULL){
		return false;
	}else if(arbol->dato==n){
		return true;
	}else if(n<arbol->dato){
		return busqueda(arbol->izq, n);
	}else{
		return busqueda(arbol->der, n);
	}
}

//Funcion para el recorrido en preorden
void preOrden(Nodo *arbol){
	if(arbol==NULL){
		return;
	}else{
		cout<<arbol->dato<<" - ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}


//Función para recorrer el árbol en inOrden
void inOrden(Nodo *arbol){
	if (arbol==NULL){
		return;
	}else{
		inOrden(arbol->izq);
		cout<<arbol->dato<<" - ";
		inOrden(arbol->der);
	}
}


//Función para recorrer el árbol en postOrden
void postOrden(Nodo *arbol){
	if(arbol==NULL){
		return;
	}else{
		postOrden(arbol->izq);
		postOrden(arbol->der);
		cout<<arbol->dato<<" - ";
	}
}

//Función para eliminar un nodo del árbol
void eliminar(Nodo *arbol, int n){
	if (arbol==NULL){
		return;
	}else if(n<arbol->dato){
		eliminar(arbol->izq, n);
	}else if(n>arbol->dato){
		eliminar(arbol->der, n);
	}
	else{
		eliminarNodo(arbol);
	}
}

Nodo *minimo(Nodo *arbol){//Función para determinar el nodo más izquierdo posible
	if(arbol==NULL){
		return NULL;
	}
	if(arbol->izq){
		return minimo(arbol->izq);
	}else{
		return arbol;
	}
}

//Función para reemplazar un nodo por el otro
void reemplazar(Nodo *arbol, Nodo *nuevoNodo){
	if(arbol->padre){
		if(arbol->dato==arbol->padre->izq->dato){
			arbol->padre->izq=nuevoNodo;
		}else if(arbol->dato==arbol->padre->der->dato){
			arbol->padre->der=nuevoNodo;
		}
		
	}
	if(nuevoNodo){
		nuevoNodo->padre=arbol->padre;
	}
}

//Función para destruir un nodo
void destruirNodo(Nodo *nodo){
	nodo->izq=NULL;
	nodo->der=NULL;
	
	delete nodo;
}

//Función para eliminar el nodo encontrado
void eliminarNodo(Nodo *nodoEliminar){
	if(nodoEliminar->izq && nodoEliminar->der){
		Nodo *menor=minimo(nodoEliminar->der);
		nodoEliminar->dato=menor->dato;
		eliminarNodo(menor);
	}else if(nodoEliminar->izq){
		reemplazar(nodoEliminar, nodoEliminar->izq );
		destruirNodo(nodoEliminar); 
	}
	else if(nodoEliminar->der){
		reemplazar(nodoEliminar, nodoEliminar->der);
		destruirNodo(nodoEliminar);
	}
	else{
		reemplazar(nodoEliminar, NULL);
		destruirNodo(nodoEliminar);
	}
}
