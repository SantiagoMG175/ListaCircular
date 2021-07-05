#include <iostream>
#include <cstdlib>


using namespace std;

struct nodo{
    int dato;    // Se crea la variable de tipo entero.
    struct nodo *enlace; // Se crea el nodo apuntando a un enlace.
};
struct nodo;//Se define al nodo como una variable.

nodo *ultimo;// Se crea el puntero *ultimo que ira al final.
nodo *cabeza;// Se crea el puntero *cabeza que ira al inicio.

void menu1();       //se declara el menu.
void insertar();    // se declara la opcion para insertar datos.
void mostrar(int);  // se declara la opcion para mostrar datos que recibe un entero.

int main(void)
{
    cabeza = NULL;
    int op;    // se crea la variable "op" para la creacion de un switch.

    do           // se  coloca un do para una sentencia de repeticion.
    {
        menu1();      //se pone el menu con la opcion que creamos para el switch.
        cin>>op;

        switch(op)         //Se crea el switch con 3 opciones
        {
        case 1:
            insertar();     //Opcion 1 se delclara la opcion para insertar datos.
            break;
        case 2:
            {
            int veces = 1;                      //Opcion 2 se declara una variable tipo entero donde veces = 1.
            cout << "\n\nCircular List \n\n";
            cout << "Enter the times you want to print: ";
            cin >> veces;                        //Se imprime las veces que se desee imprimir.
            mostrar(veces);                     //Se muestra el numero de veces.
            }
            break;
        case 3:
            cout << "Thanks for using our program" << endl;        //Caso 3 al salir del programa muestra un texto.
            break;
        default: cout << "Please enter a valid option...";             //Opcion default donde aparece un texto.
            break;
        }

        cout<<endl<<endl;       //Doble salto de linea.

    }while(op!=3);            //Un while para decir que la opcion es diferente de 3.

    return 0;
}

void menu1()              //Declaracion de la funcion menu1().
{
    cout << "\n\t\tCIRCULAR LINKED LIST\n\n";
    cout << "1.INSERT NODE" << endl;
    cout << "2.PRINT CIRCULAR LIST" << endl;          //Todo lo que mostrara el menu.
    cout << "3.EXIT\n" << endl;
    cout << "ENTER AN OPTION: ";
}

void insertar()         //Declaracion de la funcion insertar().
{
    nodo *nuevo;        //se crea un puntero *nuevo a traves de un nodo.
    nuevo = new struct nodo;       //decimos que nuevo = new struct nodo que sirve para crear otro nodo.


    cout << "\nEnter the data: ";
    cin >> nuevo->dato;  //Se imprime el nuevo que apunta al dato.
     cout << endl;
    cout << "The  " << nuevo->dato << " has been installed correctly";
    nuevo->enlace = NULL;           //Nuevo que apunta a enlace es igual a nulo.

    if(cabeza==NULL)           //Se crea un if donde cabeza es igual a nulo.
    {
        cabeza = nuevo;          //Cabeza sera igual a nuevo.
        cabeza->enlace = cabeza;       //Cabeza que apunta a enlace sera igual a cabeza
        ultimo = nuevo;               //Ultimo sera igual a nuevo.
    }
    else
    {
        nuevo->enlace = cabeza;    //se crea un else donde nuevo que apunta a enalce es igual a cabeza.
        cabeza = nuevo;            //cabeza es igual a nuevo.
        ultimo->enlace = cabeza;   //ultimo que apunta a enlace sera igual a cabeza.
    }

}

void mostrar(int veces)            //Se declara la funcion mostrar que recibe una variable llamada veces que es entera.
{   nodo *aux;                      // se crea un puntero *aux a traves de un nodo
    aux = cabeza;                   //el puntero creado sera igual a cabeza.
    int i=1;                         //variable entera donde i sera igual a 1.

    if(cabeza!=NULL)             //se crea un if donde cabeza sera diferente de nulo.
    {
        do                        //se crea una sentencia de repeticion do.
        {
            cout << "  " << aux->dato;          //se imprime el auxiliar que apunta al dato.
            aux = aux->enlace;                  // auxiliar sera igual a auxiliar que apunta al enlace.
            i++;                              // se ira sumando la variable i
        }while(i<veces);                       //se crea un while donde i sera menor que las veces que se repite.

    }
    else                                        // se declara un else para indicar que la lista se encuentra vacia.
        cout<<"\n\n\tEmpty list...!"<<endl;
}

