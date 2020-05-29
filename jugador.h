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
  Jugador(int, string, int, int, int); //constructor
  virtual void muestra_atributos(); //funcion virtual que
  virtual void usar_ataque(int danio); //polimorfismo, pues un objeto de tipo de las clases hijas usará este metodo de manera diferente
  //void cambiar_nombre(string nombre);
  void grito_de_guerra();
  //string to_string(int); para poder imprimir las id como string

};

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

void Jugador::usar_ataque(int danio){
    //Vida_zombie=Vida_zombie-danio;
    num_ataques=num_ataques-1;
}

void Jugador::grito_de_guerra(){
    cout<< "Hola!"<<endl;
}

///////////////////////////////////////////////////////////////////////////////

//herencia Jugador a Guerrero
class Guerrero : public Jugador{
private:
  int danioswing=20; //daño del swing de la espada
  int daniospin=30; //danio del spin de la espada
public:
    //constructor 1 con herencia de jugador
    Guerrero(int _id, string _username, int _nivel, int _vida, int _num_ataques,
    int _danioswing, int _daniospin):Jugador(_id, _username, _nivel, _vida, _num_ataques){
    danioswing = _danioswing;
    daniospin = _daniospin;
  }
    int get_danioswing(){return danioswing;};
    void grito_de_guerra();
    void muestra_atributos(); //polimorfismo
    void usar_ataque();//polimorfismo
};
void Guerrero::muestra_atributos(){ //esta funcion polimorfica tiene propiedades difetentes a muestra_atributos de Jugador.
    Jugador::muestra_atributos(); //sin embargo la manda a llamar para imprimir eso y además algo propio (polimorfismo)
    cout << "Ataques: Swing, Spin" << endl;
}
void Guerrero::usar_ataque(){
    Jugador::usar_ataque(danioswing);
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
  Arquero(int _id, string _username, int _nivel, int _vida, int _num_ataques,
    int _danioflecha, int _danioflechafuego):Jugador(_id, _username, _nivel, _vida, _num_ataques){
    danioflecha = _danioflecha;
    danioflechafuego = _danioflechafuego;
  }
  void grito_de_guerra();
  void muestra_atributos();
  void usar_ataque();//polimorfismo
};

void Arquero::muestra_atributos(){
    Jugador::muestra_atributos();
    cout << "Ataques: Flecha, Flecha de Fuego" << endl;
}
void Arquero::usar_ataque(){
    Jugador::usar_ataque(danioflecha);
}

void Arquero::grito_de_guerra(){
    cout<< "Que lluevan flechas!!"<<endl;
}
#endif
