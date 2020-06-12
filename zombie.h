/*
* Proyecto RPG clase Zombie
* José Pablo Miranda Berumen
* A01706702
* 12/06/2020
*
* Esta clase define objetos tipo Zombie
* Se encarga de hacer y recibir daño del jugador
*/

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
using namespace std;

class Zombie{

//variables del objeto
private:
  int vida;
  int danioz;

//funciones
public:
  Zombie(int, int); //constructor
  int get_vidaZombie();
  void set_vidaZombie(int);
  int get_danioz(){return danioz;}
  void set_danioz(int dan){danioz=dan;}
};

//constructor
Zombie::Zombie(int vid=100,int dan=10){
    vida=vid;
    danioz=dan;
}

//devuelve la vida del zombie
int Zombie::get_vidaZombie(){
    return vida;
}

//le da un nuevo valor a la vida del zombie
void Zombie::set_vidaZombie(int vid){
    vida=vid;
}

#endif
