/*
* Proyecto RPG main
* José Pablo Miranda Berumen
* A01706702
* 12/06/2020
*
* Este es un proyecto para la clase TC1030 Programación Orientado a
* Objetos. Es un Juego tipo RPG que corre sobre consola y que se trata de que
* el jugador elija sus ataques para derrotar a los zombies que se le aparezcan.
* El objetivo del main es hcer una pequena interfaz  que pregunte las opciones
* para iniciar el juego y hacer los diferentes tipos de ataques que hay.
* Por ahora es imposible perder
*/

#include <iostream> //biblioteca para cin/cout
#include "jugador.h" //clase jugador en biblioteca .h
using namespace std;

int main() {
  int opcion;
  string username;
  int id;
  int clase;
  Zombie *zomb1 = new Zombie();

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
    while(clase!=1 and clase!=2){
        cout<<"Por favor ingrese 1 o 2: ";
        cin >> clase;
    }
    cout<<"========================\n";

    Jugador* jug1; //se declara un obj tipo jugador pero  no se instancia
    if (clase==1){
        jug1=new Guerrero(id, username, 1);//no es necesario pasarle todos los atributos pq ya tienen valor desde el constructor
        /* //EJEMPLO OBJ TIPO GUERRERO
        Guerrero* guerr1=new Guerrero(0001,"KRATOS",100);
        cout<<"Guerrero Para demostrar sobreescritura:\n";
        guerr1->grito_de_guerra();
        cout<<"\n";
        */
    }
    else if (clase==2){
        jug1=new Arquero(id, username, 1);
        /* //EJEMPLO OBJ TIPO Arquero
        Arquero* arq1=new Arquero(0002,"LEGOLAS",100);
        cout<<"Arquero Para demostrar sobreescritura:\n";
        arq1->grito_de_guerra();
        cout<<"\n";
        */
    }

    jug1->muestra_atributos(); // polimorfismo
    jug1->grito_de_guerra(); // no es virtual, no se sobreescribe.
    cout<< "\n";

    cout<<"========== Empieza el juego! =========="<<endl;
    cout<<"== Aparecieron Zombies! Destruyelos =="<<endl;

    while ((zomb1->get_vidaZombie())>0 && (jug1->get_num_ataques())>0){
        cout << jug1->ataques(username);
        cout<<"-->";
        int ataque;
        cin>>ataque;
        while(ataque!=1 and ataque!=2){
          cout<<"Por favor ingrese 1 o 2: ";
          cin >> ataque;
        }
        cout<<"\n";
        jug1->usar_ataque(ataque,zomb1,username);
        while ((jug1->get_num_ataques())==0 && (zomb1->get_vidaZombie())>0){
            jug1->recibe_danio(zomb1);
        }
    }

    cout<<"\nHas eliminado a los zombies! Bien hecho!"<<"\n";

  }
  else if (opcion==2){
    void exit();
  }
  return 0;
}
