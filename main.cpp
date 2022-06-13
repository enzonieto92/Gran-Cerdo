#include <iostream> ///Funciones b�sicas de entrada y salida (cin /// cout /// )
#include <conio.h> ///Funciones b�sicas de entrada y salida de constola ( I/O)
#include <cstdlib> ///Contiene los prototipos de funciones de C para gesti�n de memoria din�mica, control de procesos y otras, utilizo srand y rand para los n�meros aleatorios
#include <ctime>///Biblioteca con la funci�n time, la utilizo para crear un delay entre los dados lanzados y para inicializar la funci�n de n�meros aleatorios
#include <cctype> ///Biblioteca que contiene la funci�n toupper() que sirve para cambiar un caracter a may�sculas
#include <windows.h>// biblioteca con funciones necesarias para cambiar la posici�n del cursor
#include <stdio.h>///Biblioteca que contiene la funci�n NULL, la utilizo para generar n�meros aleatorios
#include <string.h>
using namespace std;
#include "Funciones.h"//incluyo el archivo de cabecera "Funciones" para tener las funciones definidas por separado
#include "rlutil.h"
///////////////////////////////////////////////////////////////////////////////MEN� PRINCIPAL////////////////////////////////////////////////////////////////////
int main(){

    //////////////////Funciones de Bibliotecas//////////


    //Funci�n para generar un n�mero aleatorio, lo uso para que los dados se tiren al azar//Se encuentra en la biblioteca de funciones "ctime" ( time ) y "cstdlib" ( srand y rand )
srand (time(NULL));
    //Funci�n para que el Programa acepte letras con s�mbolos (acentos, la letra �, etc..)//Se encuentra en la biblioteca de funciones "windows.h"
SetConsoleCP(1252); // Cambiar STDIN -  Para m�quinas Windows
SetConsoleOutputCP(1252); // Cambiar STDOUT - Para m�quinas Windows
      /////////////////////////VARIABLES LOCALES//////////////////////////////


int seleccion;
bool primer_jugador;
char respuesta = 'g';
char nombre1[10];
char nombre2[10];
char n_puntajemax [10] = {};
int puntajemax = 0;
int ganador [2] = {0, 0};
int trufas_acumuladas = 0, trufas_acumuladas2 = 0, mejor_lanzamiento1 = 0, mejor_lanzamiento2 = 0;
int oinks1 = 0, oinks2 = 0;
int pv_1 = 0, pv_2 = 0;
rlutil::hidecursor();
    do {
            borrar_pantalla();
            rlutil::setColor(rlutil::WHITE);
            rlutil::locate (40, 5);
            cout <<"GRAN CERDO";
            rlutil::locate (40, 6);
            cout <<"---------------------";
            rlutil::locate (40, 7);
            cout <<"1 - JUGAR";
            rlutil::locate (40, 8);
            cout <<"2 - ESTAD�STICAS";
            rlutil::locate (40, 9);
            cout <<"3 - CERDITOS";
            rlutil::locate (40, 10);
            cout <<"---------------------";
            rlutil::locate (40, 11);
            cout <<"0 - SALIR";
            rlutil::locate (40, 12);
seleccion = rlutil::getkey();
    switch (seleccion) {

//////Llamado de funciones seg�n la opci�n que se elija////////////

//Empezar a jugar, requiere 2 nombres, 4 dados que se tiren al azar y una funci�n que
//determine qui�n va a empezar el primer turno
case 49:    pedir_nombres (nombre1, nombre2);
            borrar_pantalla();
            pregunta(nombre1, nombre2, primer_jugador);
            comienzo_del_juego(nombre1, nombre2, primer_jugador, trufas_acumuladas, trufas_acumuladas2, mejor_lanzamiento1, mejor_lanzamiento2, oinks1, oinks2);
            pantalla_puntaje(nombre1, nombre2, trufas_acumuladas, trufas_acumuladas2, mejor_lanzamiento1, mejor_lanzamiento2, oinks1, oinks2, pv_1, pv_2, ganador);
            if (puntajemax < ganador [1]){
                guardar_ganador (n_puntajemax, puntajemax, ganador, nombre1, nombre2);
            }
            break;

//Mostrar estad�sticas, en �ste men� voy a mostrar  una lista de los jugadores que ganaron y ordenados por cantidad de puntos de victoria,
//el jugador con la mayor cantidad de trufas acumuladas en una ronda,
//el jugador con m�s oinks en una ronda
case 50: estadisticas(n_puntajemax, puntajemax);
            break;

//Mostrar los cr�ditos//

case 51: cerditos();
            break;
case 48:
    rlutil::locate (35, 14);
    cout<<"est� seguro que desea salir?...S/N: ";
    cin >>respuesta;
    respuesta = toupper(respuesta);
            if (respuesta == 'S'){
                return 0;
            }
        else if (respuesta == 'N') {
        seleccion = 4;
        break;
}
default: break;
}
}
    while (seleccion!= 0);

}





