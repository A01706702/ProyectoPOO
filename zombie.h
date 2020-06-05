
#include <iostream>
using namespace std;

class Zombie{
private:
  int vida;
  int danio;
public:
  Zombie(int, int); //constructor
  void ataca_jugador();
  int get_vidaZombie();
  //void set_vidaZombie(int);
};

Zombie::Zombie(int vid,int dan){
    vida=vid;
    danio=dan;
}
int Zombie::get_vidaZombie(){
    return vida;
}
// void Zombie::set_vidaZombie(int vid){
//     vida=vid;
// }
