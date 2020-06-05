    /*José Pablo Miranda Berumen
A01706702
POO
El objetivo del main es hcer una pequena interfaz  que pregunte las opciones
para iniciar el juego y hacer los diferentes tipos de ataques que hay.

Avance #4  del proyecto:
Para esta entrega se cambió el esquema del programa, se quitó la clase mundo y zombie se agregará a jugador.h para poder utilizar la funcion usar ataque que le resta vida al zombie. y se manda a llamar desde el objeto creado en el main
*/

#include <iostream>
#include "jugador.h"
using namespace std;

int main() {

  /*
  Se construyen los objetos de tipo guerrero y arquero:
  constructor 1: recibe id, username, nivel, vida, num ataques y los atributos
  de cada clase dependiendo (guerrero o arquero)

  Se crean objetos con id, nombre, nivel, vida, numero de ataques, daño de primer ataque y daño de segundo ataque.
*/

  //Interfaz de bienvenida al juego:
//
  int opcion;
  string username;
  int id;
  int clase;

  cout << "===== Bienvenido =====" << endl;
  cout << "-Jugar(1)" << endl;
  cout << "-Salir(2)" << endl;
  cout<< "-->";
  cin >> opcion;

  while(opcion!=1 and opcion!=2){
    cout<<"Por favor ingrese 1 o 2: ";
    cin >> opcion;
  }
  if (opcion==1){
    cout<<"Ingrese Username: ";
    cin>>username;
    cout<<"Ingrese ID: ";
    cin>>id;
    cout<<"Elija su tipo de jugador \n-Guerrero(1) \n-Arquero(2)\n";
    cout<<"-->";
    cin>>clase;
    cout<<"\n";
    cout<<"========================\n";

    while(clase!=1 and clase!=2){
        cout<<"Por favor ingrese 1 o 2: ";
        cin >> clase;
    }

    if (clase==1){

        //jugador 2 usando polimorfismo con el metodo muestra_atributos() y se manda a llamar a la funcion no virtual grito de grito_de_guerra de la clase jugador
        Jugador *guerr2 =  new Guerrero(id, username, 3, 100, 3, 20, 30); //
        cout << "Tu Personaje:\n" << endl;
        guerr2->muestra_atributos(); // imprime todos los atributos y los tipos de ataque de clase guerrero (virtual) polimorfismo
        guerr2->grito_de_guerra(); // "Hola!" tipo jugador (non virtual) como es un objeto tipo jugador, y esta funcion no es virtual, no se sobreescribe.
        cout<< "\n";

        //JUGADOR Default
        //se crea un objeto de tipo Jugador que apunta a los métodos de Jugador, como muestra_atributos es virtual, o polimórfica, significa que imprimirá lo que se desarrolle en  la clase guerrero

        /*
        Jugador *guerr1 =  new Guerrero(2222, "Baldur", 1, 100, 3, 20, 30); //
        cout << "Jugador (Guerrero) default:" << endl;
        guerr1->muestra_atributos(); // imprime todos los atributos y los tipos de ataque de clase guerrero (virtual)
        guerr1->grito_de_guerra(); // "Hola!" tipo jugador (non virtual) como es un objeto tipo jugador, y esta funcion no es virtual, no se sobreescribe.
        */

        cout<<"========== Empieza el juego! =========="<<endl;
        cout<<"== Aparecieron Zombies! Destrúyelos ==\n"<<endl;
        cout<<username<<", es tu turno, elige un ataque \n-Swing(1) \n-Spin(2)\n";
        cout<<"-->";
        int ataque;
        cin>>ataque;
        /*
        while (vidaZombie>=0){
            if (ataque==1){
                cout<<username<<" used Swing!"<<endl;
                guerr2->usar_ataque(20);//cambiar para que reciba swing o spin en vez de numerito
            }
            else if (ataque==2){
                cout<<username<<" used Spin!"<<endl;
                cout<<"Now that's a lot of damage..."<<endl;
                guerr2->usar_ataque(30);
            } //esto es lo que se planea hacer pero aun no estan listas las funciones
            */

        if (ataque==1){
            cout << username << " usó Swing!" << endl;
            guerr2->usar_ataque(20);//cambiar para que reciba swing o spin en vez de numerito
        }
        else if (ataque==2){
            cout<<username<<" used Spin!"<<endl;
            cout<<"Fue un golpe fuerte..."<<endl;
            guerr2->usar_ataque(30);
        }
    }

    else if (clase==2){
        //JUGADOR 3
          Jugador *arq1 =  new Arquero(id, username, 2, 100, 3, 15, 25); //
          cout << "Tu Personaje:\n" << endl;
          arq1->muestra_atributos();//polimorfismo
          arq1->grito_de_guerra(); // "Hola!" tipo jugador (non virtual)
          cout<< "\n";

        //JUGADOR Default
        //se crea un objeto tipo arquero, por lo que apuntará a los métodos de arquero, y aquí si se sobreescribe grito_de_guerra(), pues la llamas desde la clase arquero.
          /*
          Arquero* arq2 = new Arquero(4444, "Legolas", 3, 100, 3, 15, 25);
          cout << "Jugador (Arquero) default:" << endl;
          arq2->muestra_atributos();
          arq2->grito_de_guerra();
          //arq1->usar_ataque(15);
          cout<< "\n";
          */

          cout<<"========== Empieza el juego! =========="<<endl;
          cout<<"== Aparecieron Zombies! Destrúyelos ==\n"<<endl;
          cout<<username<<"'s turn, choose an atack: \n-Flecha Normal(1) \n-Flecha Fuego(2)\n";
          cout<<"-->";
          int ataque;
          cin>>ataque;
          if (ataque==1){
              cout << username << " used Flecha Normal!" << endl;
              arq1->usar_ataque(15);//cambiar para que reciba swing o spin en vez de numerito
          }
          else if (ataque==2){
              cout<<username<<" used Flecha Fuego!"<<endl;
              cout<<"Now that's a lot of damage..."<<endl;
              arq1->usar_ataque(25);
          }
    }
  }
  else if (opcion==2){
    void exit();
  }

//switch
  return 0;
}
