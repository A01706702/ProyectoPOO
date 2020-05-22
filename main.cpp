/*José Pablo Miranda Berumen
A01706702
POO
El objetivo del main es hcer una pequena interfaz  que pregunte las opciones
para iniciar el juego y hacer los num_ataques

Avance #2  del proyecto:
Para esta entrega y demostrar el manejo de herencia, se utilizan la clase Jugador
que hereda a Guerrero y a Arquero en la librería Jugador.h
(mundo.h no está listo y no demuestra herencia por lo que se incluirá más adelante)
los objetos por ahora son simplemente creados en el main y posteriormente se irá
avanzando y se crearan en base a los datos personalizados que ingrese el usuario.
Por ahora no se utilizarán todos los métodos, solamente se demostrará herencia,
modificadores de acceso, sobrecaga y sobreescritura con algunos.
*/

#include <iostream>
#include "jugador.h"
// #include "mundo.h"
using namespace std;

int main() {

  /*se construyen los objetos de tipo guerrero y arquero:
  constructor 1: recibe id y username y los atributos de cada clase dependiendo
  (guerrero o arquero)
  constructor 2: recibe id, username, nivel, vida, num ataques y los atributos
  de cada clase dependiendo (guerrero o arquero)
  */

  /* Se crean objetos con id, nombre, daño de primer  ataque, daño de segundo ataque
  Y despues objetos con id, nombre, nivel, vida, numero de ataques, daño de primer ataque y daño de segundo ataque.*/
  Guerrero guerr1(2468, "Kratos", 30, 40);
  Guerrero guerr2(12345, "Baldur", 1, 100, 3, 10, 20);
  guerr1.muestra_nombre_id();
  guerr2.muestra_nombre_id();

  Arquero arq1(36912, "Apollo", 15, 25);
  Arquero arq2(12345, "Skadi", 1, 100, 3, 10, 20);
  arq1.muestra_nombre_id();
  arq2.muestra_nombre_id();

/*
  prueba de bienvenida al juego:

  int opcion;
  string username;
  int id;

  int clase;

  cout << "Bienvenido" << endl;
  cout << "-Jugar(1)" << endl;
  cout << "-Salir(2)" << endl;
  cin >> opcion;

  while(opcion!=1 and opcion!=2){
    cout<<"por favor ingrese 1 o 2";
    cin >> opcion;
  }
  if (opcion==1){
    cout<<"Ingrese Username: ";
    cin>>username;
    cout<<"Ingrese ID: ";
    cin>>id;
    cout<<"Eliga Tipo de jugador (1=guerrero, 2=arquero): ";
    cin>>clase;
    if (clase==1){

    }
    else if (clase==2){

    }
    cout<<"Empieza el juego!";

  }
  else if (opcion==2){
    void exit();
  }
*/

  return 0;
}
