/*José Pablo Miranda Berumen
A01706702
POO
La clase jugador hereda a Guerrero y Arquero, por lo que es abstracta,
nunca habrá un objeto tipo jugador,sino objetos tipo arquero y tipo Guerrero. ambas clases hijas tienen sus constructores, y como heredan todos los atributos de la padre, ese constructor debe hacer uso de ellos. Los únicos métodos que se usan por ahora sonn muestra_atributos y grito_de_guerra, y va en la clase padre porque siempre va a hacer la misma función sin importar el tipo de jugador. en cambio para el método usar_ataque() se emplea polimorfismo porque cambiará para cada tipo de jugador y de ahi depende el daño que haga el ataque elegido.
en cada clase se utilizaronn constructores, y la funcion grito de guerra demuestra sobreescritura, usar_ataque aun no está lista y se implementará en próximas entregas.
*/

#ifndef JUGADOR_H
#define JUGADOR_H
#include <iostream>
#include "zombie.h"
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
  Jugador(); //constructor
  Jugador(int _id, string _username, int _nivel, int _vida, int _num_ataques); //sobrecarga constructor
  virtual void muestra_atributos(); //polimorfismo, pues un objeto de tipo de las clases hijas usará este metodo de manera diferente
  //void cambiar_nombre(string nombre);
  virtual int usar_ataque(int) = 0;//funcion virtual pura (clase abstracta) será sobreescrita
  void grito_de_guerra();

};

Jugador::Jugador(){
    id=0;
    username="";
    nivel=0;
    vida=0;
    num_ataques=0;
}
//constructor
Jugador::Jugador(int _id, string _username, int _nivel, int _vida, int _num_ataques){
  id=_id;
  username=_username;
  nivel=_nivel;
  vida=_vida;
  num_ataques=_num_ataques;
}

//TODO: metodos desarrollo
void Jugador::muestra_atributos(){
  cout << "Username: " << username << "\n";
  cout << "ID: " << id << "\n";
  cout << "Nivel: " << nivel<< "\n";
  cout << "Vida: " << vida << endl;
}

void Jugador::grito_de_guerra(){
    cout<< "Hola!"<<endl;
}

///////////////////////////////////////////////////////////////////////////////

//herencia Jugador a Guerrero
class Guerrero : public Jugador{
private:
  int danioswing; //daño del swing de la espada
  int daniospin; //danio del spin de la espada
public:
    //Guerrero();
    //constructor 1 con herencia de jugador
    Guerrero(int _id, string _username, int _nivel, int _vida, int _num_ataques,
    int _danioswing, int _daniospin):Jugador(_id, _username, _nivel, _vida, _num_ataques){
    danioswing = _danioswing;
    daniospin = _daniospin;
  }
    void grito_de_guerra();
    void muestra_atributos(); //polimorfismo
    int usar_ataque(int);
};
void Guerrero::muestra_atributos(){ //esta funcion polimorfica tiene propiedades difetentes a muestra_atributos de Jugador.
    Jugador::muestra_atributos(); //sin embargo la manda a llamar para imprimir eso y además algo propio (polimorfismo)
    cout << "Ataques:" << endl;
    cout << "-Swing danio: "<< danioswing << endl;
    cout << "-Spin danio: " << daniospin << endl;
}
int Guerrero::usar_ataque(int dani){
    if (dani==20){
        dani=danioswing;
    }
    else if (dani==30){
        dani=daniospin;
    }
    Zombie *zomb1 = new Zombie(100, 10);
    int vidaZombie;
    vidaZombie=(zomb1->get_vidaZombie())-dani;
    cout << "vida zombie: " << vidaZombie<<endl;
    cout << "SE USO EL ATAQUE!! \n";
    return(vidaZombie);
    //falta cambiar la vida anterior por la vida nueva
    //num_ataques=num_ataques-1;
    delete zomb1;
}

void Guerrero::grito_de_guerra(){
    cout<< "Por Narniaaaaaaaaa!!!!"<<endl;
}
///////////////////////////////////////////////////////////////////////////////

//herencia jugador a arquero
class Arquero : public Jugador{
private:
  int danioflecha; //danio de felchazo normal
  int danioflechafuego; //danio de flechazo de fuego
public:
  //Arquero();
  Arquero(int _id, string _username, int _nivel, int _vida, int _num_ataques,
    int _danioflecha, int _danioflechafuego):Jugador(_id, _username, _nivel, _vida, _num_ataques){
    danioflecha = _danioflecha;
    danioflechafuego = _danioflechafuego;
  }
  void grito_de_guerra();
  void muestra_atributos();
  int usar_ataque(int);//polimorfismo
};

void Arquero::muestra_atributos(){
    Jugador::muestra_atributos();
    cout << "Ataques:" << endl;
    cout << "-Flecha (normal) danio: "<< danioflecha << endl;
    cout << "-Flecha de Fuego danio: " << danioflechafuego << endl;
}
int Arquero::usar_ataque(int dani){
    if (dani==15){
        dani=danioflecha;
    }
    else if (dani==25){
        dani=danioflechafuego;
    }
    Zombie *zomb2 = new Zombie(100, 10);
    int vidaZombie;
    vidaZombie=(zomb2->get_vidaZombie())-dani;
    cout << "vida zombie: " << vidaZombie<<endl;
    cout << "SE USO EL ATAQUE!! \n";
    return(vidaZombie);
    //num_ataques=num_ataques-1;
    delete zomb2; }

void Arquero::grito_de_guerra(){
    cout<< "Que lluevan flechas!!"<<endl;
}

#endif
