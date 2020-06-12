# Entrega Final
- TC1030
- Proyecto RPG
- José Pablo Miranda Berumen
- A01706702
- 12/junio/2020
## Descripción:
Este proyecto consta de un pequeño juego RPG utilizando clases y objetos para lograr una interfaz donde el usuario pueda jugar siplemente con texto y utilizando entradas fáciles, teniendo que hacer decisiones para sus ataques.
El usiario decidirá si ser un arquero o un guerrero, dependiendo de cuál eliga, será los ataques que tenga. Tanto los Guerreros como los arqueros tratarán de derrotar a los zombies. Una vez que eliges al tipo de jugador puedes iniciar el juego.  Aparecerán zombies y deberás usar ataques para matarlos. Los zombies solo podrán atacar si el jugador se queda sin ataques, el número de ataques será dado por un ciclo dentro de la funcion principal y cada vez que te quedes sin ataques, el zombie te atacará a ti y te hará daño. Para ganar mata a  todos los zombies que aparezcan.
La idea es usar la consola, no una interfaz gráfica, sino mediante opciones que introduce el usuario elegir los ataques y las características como el nombre del personaje. 
## Dinámica
Solo puedes elegir un tipo de jugador:
Guerrero o Arquero

Consta de un menu con las opciones iniciales y corre sobre consola.
## Funciones y temas implementados
Clase abstracta y herencia:
- **Jugador** es clase abstracta, pues tiene funciones virtuales puras que se desarrollan en sus clases hijas

Polimorfismo y apuntadores:
- El método _muestra_atributos_ es un ejemplo de polimorfismo

Sobreescritura:
- El método _grito_de_guerra_ se sobreescribe en las clases hijas (Lineas 54 y 63 de main.cpp)

_usar_ataque_:
- Este método se encarga de quitarle vida al zombie cada vez que se mande a llamar, además cuando se usa un ataque se resta uno al número de ataques que tiene el jugador
_recibe_danio_:
- Este método no es virtual, por lo que se crea en la clase Jugador y no se sobreescribe. Le quita vida al jugador una vez que se queda sin ataques y le suma uno como bonus.
## Consideraciones
El programa solo corre en la consola y esta hecho con c++ standard por lo que corre en todos los sistemas operativo
Se puede compilar con g++ y "a.exe" en windows y en linux "/a.out"
