    /*José Pablo Miranda Berumen
A01706702
POO
El objetivo del main es hcer una pequena interfaz  que pregunte las opciones
para iniciar el juego y hacer los diferentes tipos de ataques que hay.

Avance #3  del proyecto:
Para esta entrega y demostrar el manejo de herencia, se utilizan la clase Jugador que hereda a Guerrero y a Arquero en la librería Jugador.h
(mundo.h no está listo y no demuestra herencia por lo que se incluirá más adelante)
los objetos por ahora son simplemente creados en el main y posteriormente se irá
avanzando y se crearan en base a los datos personalizados que ingrese el usuario.
Por ahora no se utilizarán todos los métodos, solamente se demostrará herencia,
modificadores de acceso, sobreescritura y polimorfismo en las clases de este proyecto. Posteriormente se demostrará sobrecarga de métodos, ya con los métodos desarrollados.
*/

#include <iostream>
#include "jugador.h"
// #include "mundo.h"
using namespace std;

int main() {

  /*
  Se construyen los objetos de tipo guerrero y arquero:
  constructor 1: recibe id, username, nivel, vida, num ataques y los atributos
  de cada clase dependiendo (guerrero o arquero)

  Se crean objetos con id, nombre, nivel, vida, numero de ataques, daño de primer ataque y daño de segundo ataque.
*/

  //Interfaz de bienvenida al juego:

  int opcion;
  string username;
  int id;
  int clase;

  cout << "Bienvenido" << endl;
  cout << "-Jugar(1)" << endl;
  cout << "-Salir(2)" << endl;
  cin >> opcion;

  while(opcion!=1 and opcion!=2){
    cout<<"por favor ingrese 1 o 2: ";
    cin >> opcion;
  }
  if (opcion==1){
    cout<<"Ingrese Username: ";
    cin>>username;
    cout<<"Ingrese ID: ";
    cin>>id;
    cout<<"Eliga Tipo de jugador (1=guerrero, 2=arquero): ";
    cin>>clase;
    cout<<"\n";

    while(clase!=1 and clase!=2){
        cout<<"por favor ingrese 1 o 2: ";
        cin >> clase;
    }

    if (clase==1){
        //JUGADOR 1
        //es un objeto de tipo guerrero que recibe los parámetros que el usuario ingresa, y los que ya están establecidos, se usa la sintaxis del punto para mandar a llamar a sus funciones
        Guerrero guerr0(id, username, 0, 100, 3, 20, 30);
        cout << "Jugador (Guerrero) Personalizado:" << endl;
        guerr0.muestra_atributos();//manda a llamar funcion virtual, por lo que imprimirá lo que esté desarrollado en Guerrero
        guerr0.grito_de_guerra(); //objeto tipo guerrero, por lo tanto  sobreescritura de grito_de_guerra original
        cout<< "\n";

        //JUGADOR 2
        //se crea un objeto de tipo Jugador que apunta a los métodos de Jugador, como muestra_atributos es virtual, o polimórfica, significa que imprimirá lo que se desarrolle en  la clase guerrero
        Jugador *guerr1 =  new Guerrero(2222, "Baldur", 1, 100, 3, 20, 30); //
        cout << "Jugador (Guerrero) default:" << endl;
        guerr1->muestra_atributos(); // imprime todos los atributos y los tipos de ataque de clase guerrero (virtual)
        guerr1->grito_de_guerra(); // "Hola!" tipo jugador (non virtual) como es un objeto tipo jugador, y esta funcion no es virtual, no se sobreescribe.
        cout<< "\n";
    }
    else if (clase==2){
        //JUGADOR 3
          Jugador *arq1 =  new Arquero(id, username, 2, 100, 3, 15, 25); //
          cout << "Jugador (Arquero) Personalizado:" << endl;
          arq1->muestra_atributos();
          arq1->grito_de_guerra(); // "Hola!" tipo jugador (non virtual)
          cout<< "\n";
        //JUGADOR 4
        //se crea un objeto tipo arquero, por lo que apuntará a los métodos de arquero, y aquí si se sobreescribe grito_de_guerra(), pues la llamas desde la clase arquero.
          Arquero* arq2 = new Arquero(4444, "Legolas", 3, 100, 3, 15, 25);
          cout << "Jugador (Arquero) default:" << endl;
          arq2->muestra_atributos();
          arq2->grito_de_guerra();
          cout<< "\n";
    }
    cout<<"Empieza el juego!";

  }
  else if (opcion==2){
    void exit();
  }

//switch
  return 0;
}
