#include <conio.h> ///Funciones b�sicas de entrada y salida de constola ( I/O)
#include <locale.h> ///Biblioteca con prop�sitos de localizaci�n, la uso para configurar la entrada de caracteres y que admita acentos y la letra � entre otros
#include <iostream> ///Funciones b�sicas de entrada y salida (cin /// cout /// )
#include <cstdlib> ///Contiene los prototipos de funciones de C para gesti�n de memoria din�mica, control de procesos y otras, utilizo srand y rand para los n�meros aleatorios
#include <ctime>///Biblioteca con la funci�n time, la utilizo para crear un delay entre los dados lanzados y para inicializar la funci�n de n�meros aleatorios
#include <cctype> ///Biblioteca que contiene la funci�n toupper() que sirve para cambiar un caracter a may�sculas
#include <stdio.h>///Biblioteca que contiene la funci�n NULL, la utilizo para generar n�meros aleatorios
using namespace std;
#include "Funciones.h"//incluyo el archivo de cabecera "Funciones" para tener las funciones definidas por separado

///////////////////////////////////////////////////////////////////////////////MEN� PRINCIPAL////////////////////////////////////////////////////////////////////
int main(){

    //////////////////Funciones de Bibliotecas//////////

    //Funci�n para generar un n�mero aleatorio, lo uso para que los dados se tiren al azar//Se encuentra en la biblioteca de funciones "ctime" ( time ) y "cstdlib" ( srand y rand )
srand (time(NULL));
    //Funci�n para que el Programa acepte letras con s�mbolos (acentos, la letra �, etc..)//Se encuentra en la biblioteca de funciones "locale.h"
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
            cout <<"2 - ESTAD�STICAS"<<endl<<"3 - CERDITOS"<<endl<<"---------------------"<<endl;
            cout <<"0 - SALIR"<<endl<<endl<<"Seleccione una opci�n:  ";;
            cin >>seleccion;
    switch (seleccion) {

//////Llamado de funciones seg�n la opci�n que se elija////////////

//Empezar a jugar, requiere 2 nombres, 4 dados que se tiren al azar y una funci�n que
//determine qui�n va a empezar el primer turno
case 1:     pedir_nombre (nombre1);
            pedir_nombre2(nombre2);
            borrar_pantalla();
            pregunta(nombre1, nombre2, primer_jugador);
            comienzo_del_juego(nombre1, nombre2, primer_jugador, trufas_acumuladas, trufas_acumuladas2, mejor_lanzamiento1, mejor_lanzamiento2);

            break;

//Mostrar estad�sticas, en �ste men� voy a mostrar  una lista de los jugadores que ganaron y ordenados por cantidad de puntos de victoria,
//el jugador con la mayor cantidad de trufas acumuladas en una ronda,
//el jugador con m�s oinks en una ronda
case 2: estadisticas();
            break;

//Mostrar los cr�ditos//

case 3: cerditos();
            break;
}
}
    while (seleccion!= 0);

return 0;
}





