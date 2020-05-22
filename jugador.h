/*José Pablo Miranda Berumen
A01706702
POO
La clase jugador hereda a Guerrero y Arquero, por lo que es abstracta,
nunca habrá un objeto tipo jugador,sino objetos tipo arquero y tipo Guerrero. ambas clases hijas tienen sus constructores, y como heredan todos los atributos de la padre, ese constructor debe hacer uso de ellos. El único método que se usa por ahora es el de mostrar id y username, y va en la clase padre porque siempre va a hacer la misma función sin importar el tipo de jugador. en cambio para el método usar_ataque() se emplea sobreescritura porque cambiará para cada tipo de jugador y de ahi depende el daño que haga el ataque elegido.
en cada clase se utilizaronn dos constructores, para crear objetos que no requieran de todos lo atributos de la clase padre.
*/

#ifndef JUGADOR_H
#define JUGADOR_H
#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////

class Jugador{
protected: //porque de esta forma se pueden utilizar sin necesidad de sets y gets en las clases hijas
  int id;
  string username;
  int nivel;
  int vida;
  int num_ataques;
public:
  Jugador(int,string);//constructor general
  Jugador(int,string, int, int, int); //sobrecarga de constructor
  void muestra_nombre_id();
  void usar_ataque();
  void cambiar_nombre(string nombre);
};

//constructor desarrollo
Jugador::Jugador(int _id, string _username){
  id=_id;
  username=_username;
}
//constructor 2 (sobrecarga)
Jugador::Jugador(int _id, string _username, int _nivel, int _vida, int _num_ataques){
  id=_id;
  username=_username;
  nivel=_nivel;
  vida=_vida;
  num_ataques=_num_ataques;
}

//TODO: metodos desarrollo
void Jugador::muestra_nombre_id(){
  cout << "Username: " << username;
  cout << " ID: " << id << endl;
}

///////////////////////////////////////////////////////////////////////////////

//herencia Jugador a Guerrero
class Guerrero : public Jugador{
private:
  int danioswing; //daño del swing de la espada
  int daniospin; //danio del spin de la espada
public:
    //constructor 1 con herencia de jugador
    Guerrero(int _id, string _username, int _danioswing,
    int _daniospin):Jugador(_id, _username){
    danioswing = _danioswing;
    daniospin = _daniospin;
  }
  //comstructor 2 con herencia de jugador
  Guerrero(int _id, string _username, int _nivel, int _vida, int _num_ataques,
    int _danioswing, int _daniospin):Jugador(_id, _username, _nivel, _vida, _num_ataques){
    danioswing = _danioswing;
    daniospin = _daniospin;
  }
  void usar_ataque();//sobreescritura
};

//TODO: sobreescritura desarrolladndo....
void Guerrero::usar_ataque(){

}

///////////////////////////////////////////////////////////////////////////////

//herencia jugador a arquero
class Arquero : public Jugador{
private:
  int danioflecha; //danio de felchazo normal
  int danioflechafuego; //danio de flechazo de fuego
public:
  Arquero(int _id, string _username, int _danioflecha, int _danioflechafuego):Jugador(_id, _username){
    danioflecha = _danioflecha;
    danioflechafuego = _danioflechafuego;
  }
  Arquero(int _id, string _username, int _nivel, int _vida, int _num_ataques,
    int _danioflecha, int _danioflechafuego):Jugador(_id, _username, _nivel, _vida, _num_ataques){
    danioflecha = _danioflecha;
    danioflechafuego = _danioflechafuego;
  }
  void usar_ataque();//sobreescritura
};

//sobreescritura desarrolladndo....
void Arquero::usar_ataque(){

}

#endif
