#include <conio.h> ///Funciones básicas de entrada y salida de constola ( I/O)
#include <locale.h> ///Biblioteca con propósitos de localización, la uso para configurar la entrada de caracteres y que admita acentos y la letra Ñ entre otros
#include <iostream> ///Funciones básicas de entrada y salida (cin /// cout /// )
#include <cstdlib> ///Contiene los prototipos de funciones de C para gestión de memoria dinámica, control de procesos y otras, utilizo srand y rand para los números aleatorios
#include <ctime>///Biblioteca con la función time, la utilizo para crear un delay entre los dados lanzados y para inicializar la función de números aleatorios
#include <cctype> ///Biblioteca que contiene la función toupper() que sirve para cambiar un caracter a mayúsculas
#include <stdio.h>///Biblioteca que contiene la función NULL, la utilizo para generar números aleatorios
using namespace std;
#include "Funciones.h"//incluyo el archivo de cabecera "Funciones" para tener las funciones definidas por separado

///////////////////////////////////////////////////////////////////////////////MENÚ PRINCIPAL////////////////////////////////////////////////////////////////////
int main(){

    //////////////////Funciones de Bibliotecas//////////

    //Función para generar un número aleatorio, lo uso para que los dados se tiren al azar//Se encuentra en la biblioteca de funciones "ctime" ( time ) y "cstdlib" ( srand y rand )
srand (time(NULL));
    //Función para que el Programa acepte letras con símbolos (acentos, la letra Ñ, etc..)//Se encuentra en la biblioteca de funciones "locale.h"
setlocale(LC_ALL, "spanish");

      /////////////////////////VARIABLES//////////////////////////////

    //Declaro un Booleano que me va a decir que jugador empieza la partida
    //Declaro 2 vectores de tipo CHAR con 10 espacios para poner los nombres
   //Declaro 2  variables de tipo entero para acumular los puntajes de los jugadores y las inicializo en cero

int seleccion;
bool primer_jugador;
char nombre1[10] = "pepe";
char nombre2 [10] = "pepa";
int trufas_acumuladas = 0, trufas_acumuladas2 = 0, mejor_lanzamiento1 = 0, mejor_lanzamiento2 = 0;
    do {
            borrar_pantalla();
            cout <<"GRAN CERDO"<<endl<<"---------------------"<<endl<<"1 - JUGAR"<<endl;
            cout <<"2 - ESTADÍSTICAS"<<endl<<"3 - CERDITOS"<<endl<<"---------------------"<<endl;
            cout <<"0 - SALIR"<<endl<<endl<<"Seleccione una opción:  ";;
            cin >>seleccion;
    switch (seleccion) {

//////Llamado de funciones según la opción que se elija////////////

//Empezar a jugar, requiere 2 nombres, 4 dados que se tiren al azar y una función que
//determine quién va a empezar el primer turno
case 1:     pedir_nombre (nombre1);
            pedir_nombre2(nombre2);
            borrar_pantalla();
            pregunta(nombre1, nombre2, primer_jugador);
            comienzo_del_juego(nombre1, nombre2, primer_jugador, trufas_acumuladas, trufas_acumuladas2, mejor_lanzamiento1, mejor_lanzamiento2);

            break;

//Mostrar estadísticas, en éste menú voy a mostrar  una lista de los jugadores que ganaron y ordenados por cantidad de puntos de victoria,
//el jugador con la mayor cantidad de trufas acumuladas en una ronda,
//el jugador con más oinks en una ronda
case 2: estadisticas();
            break;

//Mostrar los créditos//

case 3: cerditos();
            break;
}
}
    while (seleccion!= 0);

return 0;
}





