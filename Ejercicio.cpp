#include <cstdlib>
#include <iostream>

using namespace std;

struct Nodo
{
    int dato;
    Nodo *sig;
};

class Pila
{
  private:
    Nodo *cabecera;

  public:

    Nodo* crearNodo(int valor)
    {
        Nodo *n = new Nodo;
        n->dato = valor;
        n->sig = nullptr;
        return n;
    }

    void push(int valor)
    {
        Nodo *n = crearNodo(valor);
        n->sig = cabecera;
        cabecera = n;
    }

    void pop()
    {
        Nodo *temp = cabecera;
        cabecera = cabecera->sig;
        free(temp);
    }

    void mostrarPila()
    {
       Nodo *temp = cabecera;
       if(!cabecera){
           cout<<"Pila vacia"<<endl;
       }else{
           while(temp){
               cout<<temp->dato<<", ";
               temp = temp->sig;
           }
       }
    }

    int length()
    {
        Nodo *temp = cabecera;
        int cont=0;

        while(temp){
          cont++;
          temp = temp->sig;
        }

        return cont;
    }

    Pila()
    {
        cabecera = nullptr;
    }
};

int main(int argc, char** argv) {
  int dato;
  Pila numerosImpares = Pila(), numerosPares = Pila();

  cout <<  "Ingrese los numeros a guardar, y 0 para terminar"<<endl;
  cin >> dato;

  while(dato > 0)
  {
    if(dato!=-1 && dato % 2 == 0)
        numerosPares.push(dato);
    else
        numerosImpares.push(dato);

    cin >> dato;

  }

  if(numerosPares.length()==numerosImpares.length())
  {
    cout<<"ingreso la misma cantidad de numeros pares e impares"<<endl;
  }
  else if(numerosPares.length() < numerosImpares.length())
  {
    cout<<"Ingreso mas numero impares que pares"<<endl;
  }
  else
  {
    cout<<"Ingreso mas numero pares que impares"<<endl;
  }

  cout<<"Total de numeros impares: "<< numerosImpares.length()<<endl;
  cout<<"Total de numeros pares: "<< numerosPares.length()<<endl;

  return 0;
}
