#include <conio.h> ///Funciones básicas de entrada y salida de constola ( I/O)
#include <iostream> ///Funciones básicas de entrada y salida (cin /// cout /// )
#include <cstdlib> ///Contiene los prototipos de funciones de C para gestión de memoria dinámica, control de procesos y otras, utilizo srand y rand para los números aleatorios
#include <ctime>///Biblioteca con la función time, la utilizo para crear un delay entre los dados lanzados y para inicializar la función de números aleatorios
#include <cctype> ///Biblioteca que contiene la función toupper() que sirve para cambiar un caracter a mayúsculas
#include <windows.h> //biblioteca para compatibilidad con Windows, tuve un problema al querer mostrar carácteres alojados en un vector, cambiar la versión de la consola me solucionó el problema
#include <stdio.h>///Biblioteca que contiene la función NULL, la utilizo para generar números aleatorios
using namespace std;
#include "Funciones.h" //incluyo el archivo de cabecera "Funciones" para tener las funciones definidas por separado
#include "rlutil.h"
#include <string.h>
///////////////////////////////////////////FUNCIONES////////////////////////////////////////



// Menú de Estadísticas
void estadisticas (char n_puntajemax[], int& puntajemax){
    borrar_pantalla();
    rlutil::locate (30, 6);
    cout <<"el ganador con mas puntos de victoria es: ";
    rlutil::locate (49, 8);
    cout <<n_puntajemax;
    rlutil::locate (38, 10);
    cout <<"con un total de "<<puntajemax<<" puntos!";
    rlutil::getkey();
}

//Menú de Créditos
void cerditos (){
    borrar_pantalla();
    cout <<"Los Cerditos creadores de éste juego son: " <<endl<<endl;
    cout <<"Enzo Matías Nieto"<<endl<<endl;
    cout <<"Claudia Fiszman"<<endl<<endl;
    cout <<"Ludmila Boffo"<<endl<<endl;
    cout <<"Pablo Barros"<<endl<<endl;
    cout <<"Juan Pablo Benitez"<<endl<<endl;
    system ("pause");
}


//Esperar segundos
void delay(int secs) {
for(int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
}


//Borrar Pantalla
void borrar_pantalla(){
system ("cls");
}


//Lanzar dado aleatorio y devolver el resultado
 int dado (){
    int  numero;
    numero = rand()% 6 + 1;
    return numero;
    }

//mostrar dado por pantalla recibiendo coordenadas (lugar) y el dado que se muestra (número)
void dado_d (int x, int y, int numero){
   switch (numero){
     case 1:
            rlutil::locate (x, y);
            cout <<"+-------+";
            rlutil::locate (x, y+1);
            cout <<"|       |";
            rlutil::locate (x, y+2);
            cout <<"|   x   |";
            rlutil::locate (x, y+3);
            cout <<"|       |";
            rlutil::locate (x, y+4);
            cout <<"+-------+";
             break;

    case 2:
            rlutil::locate (x, y);
            cout <<"+-------+";
            rlutil::locate (x, y+1);
            cout <<"| x     |";
            rlutil::locate (x, y+2);
            cout <<"|       |";
            rlutil::locate (x, y+3);
            cout <<"|     x |";
            rlutil::locate (x, y+4);
            cout <<"+-------+";
             break;


    case 3:
            rlutil::locate (x, y);
            cout <<"+-------+";
            rlutil::locate (x, y+1);
            cout <<"| x     |";
            rlutil::locate (x, y+2);
            cout <<"|   x   |";
            rlutil::locate (x, y+3);
            cout <<"|     x |";
            rlutil::locate (x, y+4);
            cout <<"+-------+";
             break;


    case 4:
            rlutil::locate (x, y);
            cout <<"+-------+";
            rlutil::locate (x, y+1);
            cout <<"| x   x |";
            rlutil::locate (x, y+2);
            cout <<"|       |";
            rlutil::locate (x, y+3);
            cout <<"| x   x |";
            rlutil::locate (x, y+4);
            cout <<"+-------+";
             break;
    case 5:
            rlutil::locate (x, y);
            cout <<"+-------+";
            rlutil::locate (x, y+1);
            cout <<"| x   x |";
            rlutil::locate (x, y+2);
            cout <<"|   x   |";
            rlutil::locate (x, y+3);
            cout <<"| x   x |";
            rlutil::locate (x, y+4);
            cout <<"+-------+";
             break;
    case 6:
            rlutil::locate (x, y);
            cout <<"+-------+";
            rlutil::locate (x, y+1);
            cout <<"| x   x |";
            rlutil::locate (x, y+2);
            cout <<"| x   x |";
            rlutil::locate (x, y+3);
            cout <<"| x   x |";
            rlutil::locate (x, y+4);
            cout <<"+-------+";
             break;

    }

}


void borrar_dados(){
    rlutil::locate(33, 15);
    cout <<"                              ";
    rlutil::locate(33, 16);
    cout <<"                              ";
    rlutil::locate(33, 17);
    cout <<"                              ";
    rlutil::locate(33, 18);
    cout <<"                              ";
    rlutil::locate(33, 19);
    cout <<"                              ";

}

//Funciones para guardar nombres antes de comenzar el juego
void pedir_nombres (char nombre1[], char nombre2[]){

    borrar_pantalla();

    rlutil::showcursor();
    rlutil::locate (30, 5);
    cout <<"Jugador N°1: ";
    rlutil::locate (60, 5);
    cout <<"Jugador N°2: ";
    rlutil::locate (33, 7);
    cin >>nombre1;
    rlutil::locate (63, 7);
    cin >>nombre2;


}


//Lanzamiento por Turnos para definir el primer jugador en lanzar
void pregunta (char nombre1[], char nombre2[], bool& primer_jugador){
borrar_pantalla();
char respuesta = 'S';
int punt_j1_j2 [4] = {0, 0, 0, 0};
int punt_j1, punt_j2, punt_max = 0, i, x, y, z;
int  bandera_turno = 0;
do{
switch (bandera_turno){
case 0:
        borrar_pantalla();
        rlutil::locate (35, 4);
        cout <<"Veamos quién empieza!";
        rlutil::locate (35, 6);
        cout <<"Es el turno de "<<nombre1<<"!";
        rlutil::locate (35, 7);
        cout <<"Tirar Dados? S/N? ";
        rlutil::locate (42, 9);
        cin >>respuesta;
        rlutil::hidecursor();
        respuesta = toupper(respuesta);
        if (respuesta == 'S'){
            for (i = 0; i <2; i++){
                    delay (1);
                    punt_j1_j2 [i]  = dado();
                    dado_d(35 + (i*9), 10, punt_j1_j2[i]);
            }
            punt_j1 = punt_j1_j2 [0] + punt_j1_j2 [1];
            rlutil::locate (35, 17);
            cout <<nombre1<<" ha lanzado un "<<punt_j1 <<"!"<<endl;
            bandera_turno ++;
            rlutil::getkey();
            break;
        }
        else{
            break;
            }
case 1:
        borrar_pantalla();
        rlutil::locate (35, 4);
        cout <<"Veamos quién empieza!";
        rlutil::locate (35, 6);
        cout <<"Es el turno de "<<nombre2<<"!";
        rlutil::locate (35, 7);
        cout <<"Tirar Dados? S/N"<<endl;
        rlutil::locate (42, 9);
        cin >>respuesta;
        rlutil::hidecursor();
        respuesta =  toupper(respuesta);
            if (respuesta == 'S'){
                for (i = 2; i <4; i++){
                        delay (1);
                        punt_j1_j2 [i]  = dado();
                        dado_d(17 + (i*9), 10, punt_j1_j2[i]);
                }
                punt_j2 = punt_j1_j2 [2] +punt_j1_j2 [3];
                rlutil::locate (35, 17);
                cout <<nombre2<< " hizo "<<punt_j2<<" puntos!"<<endl;
                bandera_turno ++;
                rlutil::getkey();
            break;
    }
            else{
                break;
                }
case 2:
        //Pregunto si el puntaje del Jugador 1 es el mayor
        if (punt_j1 >punt_j2){
            rlutil::locate (28, 20);
            cout <<nombre1<< " ha sacado el mayor puntaje con "<<punt_j1<<" puntos!";
            rlutil::locate (28, 22);
            cout <<"Será el primer jugador en lanzar";
            primer_jugador = 0;
            bandera_turno = 3;
            rlutil::getkey();
            break;

        }
        // Pregunto si el puntaje del Jugador 2 es el mayor
        else if(punt_j1<punt_j2) {
            rlutil::locate (28, 20);
            cout <<nombre2<< " ha sacado el mayor puntaje con "<<punt_j2<<" puntos!";
            rlutil::locate (28, 22);
            cout <<"Será el primer jugador en lanzar";
            primer_jugador = 1;
            bandera_turno = 3;
            rlutil::getkey();
            break;
        }
       //si ningún puntaje es el mayor, tenemos que buscar el dado más grande y quién lo tiró
       //Asumimos que la única alternativa es que los puntajes sean iguales, y evalúo el vector para buscar el dado más grande

        else if (punt_j1 == punt_j2) {

        // For para buscar el máximo de los dados y alojar su dirección de memoria en la variable "y"
                for (x = 0; x<4; x++){

                    if (punt_j1_j2 [x] > punt_max){
                        punt_max = punt_j1_j2 [x];
                        y = x;
                    }
                }
                    for (z = 0; z<4 && z!= y; z++){
                        if (punt_j1_j2 [y] == punt_j1_j2[z]){
                                    rlutil::locate(28, 20);
                                    cout <<"Empataron todos los dados! Tiran ambos devuelta";
                                    rlutil::getkey();
                                    bandera_turno = 0;
                                    break;
                        }
                    }
                        if (y == 1 ||  y == 0){
                                    rlutil::locate(28, 20);
                                    cout <<"Empataron! pero "<<nombre1<<" sacó el dado mas alto!";
                                    rlutil::locate(28, 21);
                                    cout <<"Será el primero en jugar..."<<endl;
                                    primer_jugador = 0;
                                    bandera_turno =3;
                                    rlutil::getkey();
                                    break;
                        }
                        else if (y == 2 || y == 3){
                                    rlutil::locate(28, 20);
                                    cout<< "Empataron! pero "<<nombre2<< " sacó el dado mas alto!";
                                   rlutil::locate(28, 21);
                                    cout <<"Será el primero en jugar...";
                                    primer_jugador = 1;
                                    bandera_turno = 3;
                                    rlutil::getkey();
                                    break;
                        }

                        //Si el dado mas grande no está repetido, este IF pregunta la posición del dado más grande y cambia el valor de la variable local "primer_jugador" dependiendo de quién lo tenga;
                        //(La variable primer_jugador va a definir quién empieza el juego)

        }


                }//final switch bandera
        }// final del DO
while (bandera_turno != 3);
}


//Función para cambiar el menú una vez que se defina el primero en lanzar los dados
void comienzo_del_juego (char nombre1[], char nombre2[], bool& primer_jugador, int& trufas_acumuladas, int& trufas_acumuladas2, int & mejor_lanzamiento1, int& mejor_lanzamiento2, int& oinks1, int& oinks2){
            char respuesta = 'S';
            bool bandera_turno = primer_jugador;
            bool bandera_3dados = false;
            int rondas = 1;
            int trufas_ronda = 0;
            int cont_turnos = 0;
            int cont_lanzamientos =0, cont_lanzamientos2 = 0;
            trufas_acumuladas  = 0;
            trufas_acumuladas2 = 0;
    do{
            borrar_pantalla();
            rlutil::locate(40, 1);
            cout <<"GRAN CERDO";
            rlutil::locate (10, 2);
            cout<<"------------------------------------------------------------------------";
            rlutil::locate (18, 3);
            cout <<nombre1<<": "<<trufas_acumuladas<<" trufas acumuladas"<<"     "<<nombre2<<": "<<trufas_acumuladas2<<" trufas acumuladas";

                        //Si es el turno del jugador1, y el jugador 1 ganó la primer tirada entonces muestro sus datos por pantalla, y pregunto si desea seguir lanzando
                    switch (bandera_turno){
                        case 0:
                                rlutil::locate(30, 5);
                                cout <<"TURNO DE "<<nombre1<<"!";
                                rlutil::locate(30, 6);
                                cout <<"+-------------------------+";
                                rlutil::locate(30, 7);
                                cout <<"| RONDA #"<<rondas;
                                rlutil::locate(30, 8);
                                cout <<"| TRUFAS DE LA RONDA: "<<trufas_ronda;
                                rlutil::locate(30, 9);
                                cout <<"| LANZAMIENTOS: "<<cont_lanzamientos;
                                rlutil::locate(30, 10);
                                cout <<"+-------------------------+";
                                rlutil::locate (56, 7);
                                cout <<"|";
                                rlutil::locate (56, 8);
                                cout <<"|";
                                rlutil::locate (56, 9);
                                cout <<"|";
                                rlutil::locate  (35, 12);
                                cout <<"LANZAMIENTO # "<<cont_lanzamientos+1;
                                rlutil::locate(35, 13);
                                cout <<"Tirar Dados?  S/N";
                                rlutil::locate (10, 25);
                                cout<<"------------------------------------------------------------------------";
                                rlutil::locate (59, 26);
                                cout <<"Responda 'Q' para salir";
                                rlutil::locate (54, 13);
                                cin >>respuesta;
                               respuesta = toupper(respuesta);
                                    if(respuesta == 'S'){
                                        empezar_lanzamiento(trufas_acumuladas, trufas_acumuladas2, bandera_turno, bandera_3dados, trufas_ronda, cont_lanzamientos, cont_lanzamientos2, cont_turnos, oinks1, oinks2);
                                        borrar_pantalla();
                                        break;
                                }
                                    else if (respuesta == 'N'){
                                        rlutil::locate ( 10, 15);
                                        cout <<"está seguro?...se acumularán las trufas de la ronda :  S/N ";
                                        cin >>respuesta;
                                        respuesta = toupper(respuesta);
                                        if (respuesta == 'S'){
                                            trufas_acumuladas += trufas_ronda;
                                            trufas_ronda = 0;
                                            bandera_turno = true;
                                            if (cont_lanzamientos > mejor_lanzamiento1){
                                                mejor_lanzamiento1 = cont_lanzamientos ;
                                            }

                                            cont_lanzamientos = 0;
                                            cont_turnos ++;
                                            borrar_pantalla();
                                        }
                                    }
                                    else if (respuesta == 'Q'){
                                        return;
                                    }
                        break;
                        case 1:
                                rlutil::locate(30, 5);
                                cout <<"TURNO DE "<<nombre2<<"!";
                                rlutil::locate(30, 6);
                                cout <<"+-------------------------+";
                                rlutil::locate(30, 7);
                                cout <<"| RONDA #"<<rondas;
                                rlutil::locate(30, 8);
                                cout <<"| TRUFAS DE LA RONDA: "<<trufas_ronda;
                                rlutil::locate(30, 9);
                                cout <<"| LANZAMIENTOS: "<<cont_lanzamientos2;
                                rlutil::locate(30, 10);
                                cout <<"+-------------------------+";
                                rlutil::locate (56, 7);
                                cout <<"|";
                                rlutil::locate (56, 8);
                                cout <<"|";
                                rlutil::locate (56, 9);
                                cout <<"|";
                                rlutil::locate  (35, 12);
                                cout <<"LANZAMIENTO # "<<cont_lanzamientos2+1;
                                rlutil::locate(35, 13);
                                cout <<"Tirar Dados?  S/N";
                                rlutil::locate (10, 25);
                                cout<<"------------------------------------------------------------------------";
                                rlutil::locate (59, 26);
                                cout <<"Responda 'Q' para salir";
                                rlutil::locate (54, 13);
                                rlutil::locate (54, 13);
                                cin >>respuesta;
                               respuesta = toupper(respuesta);
                                    if (respuesta =='S'){
                                        empezar_lanzamiento(trufas_acumuladas, trufas_acumuladas2, bandera_turno, bandera_3dados, trufas_ronda, cont_lanzamientos, cont_lanzamientos2, cont_turnos, oinks1, oinks2);
                                        borrar_pantalla();
                                }
                                    else if (respuesta == 'N'){
                                        rlutil::locate ( 10, 15);
                                        cout <<"está seguro? Se acumularán las trufas de la ronda : S/N";
                                        cin >>respuesta;
                                        respuesta = toupper(respuesta);
                                        if (respuesta == 'S'){
                                            trufas_acumuladas2 += trufas_ronda;
                                            trufas_ronda = 0;
                                            bandera_turno = false;
                                            if (cont_lanzamientos2 > mejor_lanzamiento2){
                                                mejor_lanzamiento2 = cont_lanzamientos2;
                                            }
                                            cont_lanzamientos2 = 0;
                                            cont_turnos ++;
                                            borrar_pantalla();
                                        }
                                    }
                                    else if (respuesta == 'Q'){
                                        return;
                                    }

                        break;
                    }//switch corchete final
             if (cont_turnos/2 == rondas){
                            rondas ++;
            }
        }//DO corchete final
    while (rondas <6 );
    }
///*////////////////////////////////////////////Función para tirar los dados  al comienzo de la primer ronda//////////////////////////////////////////////////
//En ésta función hago un lanzamiento individual, que puede ser de 2 o 3 dados
//dependiendo de las situaciones que se vayan dando en el juego
void  empezar_lanzamiento(int& puntaje1, int& puntaje2, bool& jugador, bool&bandera_3dados, int& trufas_ronda, int& cont_lanzamientos, int&cont_lanzamientos2, int& cont_turnos, int& oinks1, int& oinks2){
int i, z, suma;
int dados_jugador[3] = {};

//En ésta parte pregunto si las trufas acumuladas son menores a 50,
//esto condiciona la cantidad de dados que se van a utilizar
if (puntaje1 >= 50 || puntaje2 >= 50){
    bandera_3dados = true;
}
////////////////Lanzamiento de dados ///////////////////////////

// Evalúo la bandera para ver cuantos dados se tiran y sumo el resultado
            if (bandera_3dados == false){
                for (i = 0; i < 2; i ++){
                delay (1);
                dados_jugador [i]  = dado();
                }
                dado_d (33, 15, dados_jugador [0]);
                delay(1);
                dado_d (43, 15, dados_jugador [1]);
                suma = dados_jugador [0] + dados_jugador [1];
            }
            else{
                for (z = 0; z < 3; z ++){
                dados_jugador [z]  = dado();
                }
                delay(1);
                dado_d (33, 15, dados_jugador [0]);
                delay(1);
                dado_d (43, 15, dados_jugador [1]);
                delay(1);
                dado_d (53, 15, dados_jugador [2]);
                suma = dados_jugador [0] + dados_jugador [1] + dados_jugador [2];
            }

////////////////////////////////////////////////////////////////


        switch (jugador){

////////////////////////////////////////////////            ///*   JUGADOR 1        *///        //////////////////////////////////////////////////
            case 0:

                        switch (bandera_3dados){
//////////////////////////////////////////////////               DOS DADOS               //////////////////////////////////////////////////
                            case 0:
                                      if (dados_jugador[0] == 1 &&  dados_jugador [1] == 1){
                                    rlutil::locate (10, 21);
                                    cout << "Se ha hundido en el barro! pierde todas  las trufas acumuladas y cede su turno";
                                    puntaje1 = 0;
                                    cont_turnos ++;
                                    jugador = 1;
                                    bandera_3dados = true;
                                    cont_lanzamientos = 0;
                                    rlutil::getkey();
                                    break;
                                 }
                                else if (dados_jugador [0] == 1 || dados_jugador [1] == 1){
                                    rlutil::locate (10, 21);
                                    cout << "Ha salido un AS! Pierde las trufas acumuladas y cede su turno";
                                    cont_lanzamientos = 0;
                                    cont_turnos ++;
                                    trufas_ronda = 0;
                                    jugador = 1;
                                    rlutil::getkey();
                                    break;

                                 }
                                else if (dados_jugador [0] == dados_jugador [1]){
                                    rlutil::locate (24, 21);
                                    cout <<"hiciste un OINK! duplica y tira nuevamente";
                                    trufas_ronda += suma*2;
                                    cont_lanzamientos ++;
                                    oinks1 ++;
                                    rlutil::getkey();
                                    borrar_dados();
                                    empezar_lanzamiento(puntaje1, puntaje2, jugador, bandera_3dados, trufas_ronda, cont_lanzamientos, cont_lanzamientos2, cont_turnos, oinks1, oinks2);
                                }
                                else if (dados_jugador [0] != dados_jugador [1]){
                                    rlutil::locate (34, 21);
                                    cout << "Hiciste "<<suma<< " trufas!";
                                    trufas_ronda += suma;
                                    cont_lanzamientos++;
                                    rlutil::getkey();
                                    break;
                                }
                            break;
//////////////////////////////////////////////////             TRES DADOS           //////////////////////////////////////////////////
                            case 1:
                                     if (dados_jugador [0] == 1 && dados_jugador [1] == 1 && dados_jugador [2] == 1){

                                    rlutil::locate (17, 21);
                                    cout << "OH NO! 3 ASES!  CEDE todas sus trufas y su turno";
                                    cont_turnos ++;
                                   puntaje2 += trufas_ronda;
                                   puntaje2 += puntaje1;
                                   puntaje1 = 0;
                                   trufas_ronda = 0;
                                   cont_lanzamientos = 0;
                                    jugador = 1;
                                    bandera_3dados = 1;
                                    rlutil::getkey();
                                    break;
                                 }
                                else if (dados_jugador [0] == 1 &&(dados_jugador [1] == 1 || dados_jugador [2] == 1)){

                                    rlutil::locate (10, 21);
                                    cout << "Se ha hundido en el barro! pierde las trufas acumuladas y cede su turno";
                                    cont_turnos++;
                                    puntaje1 = 0;
                                    jugador = 1;
                                    cont_lanzamientos = 0;
                                    bandera_3dados = 1;
                                    rlutil::getkey();
                                    break;

                                }
                                else if (dados_jugador [0] == 1 || dados_jugador [1] == 1 || dados_jugador [2] == 1){
                                    rlutil::locate (10, 21);
                                    cout << "Ha salido un AS! Pierde las trufas acumuladas y  cede su turno";
                                    cont_turnos++;
                                    jugador = 1;
                                    trufas_ronda = 0;
                                    cont_lanzamientos = 0;
                                    rlutil::getkey();
                                    break;
                                 }
                                else if (dados_jugador [0] == dados_jugador [1] && dados_jugador [0] == dados_jugador [2]){
                                    rlutil::locate (10, 21);
                                    cout <<"Hiciste un OINK! Duplica los dados y lanza nuevamente!";
                                    trufas_ronda += suma*2;
                                    cont_lanzamientos ++;
                                    oinks1++;
                                    rlutil::getkey();
                                    borrar_dados();
                                    empezar_lanzamiento(puntaje1, puntaje2, jugador, bandera_3dados, trufas_ronda, cont_lanzamientos, cont_lanzamientos2, cont_turnos, oinks1, oinks2);
                                }
                                else if (dados_jugador [0] != dados_jugador [1] || dados_jugador [0] != dados_jugador [2]){
                                    rlutil::locate (34, 21);
                                    cout << "Hiciste "<<suma<< " trufas!";
                                    cont_lanzamientos++;
                                    rlutil::getkey();
                                    trufas_ronda += suma;
                                    break;
                                }
                            break;
                        }
            break;
////////////////////////////////////////////////           ///*     JUGADOR 2    *///        //////////////////////////////////////////////////

            case 1:

                        switch (bandera_3dados){
//////////////////////////////////////////////////               DOS DADOS               //////////////////////////////////////////////////
                            case 0:
                                     if (dados_jugador [0] == 1 &&  dados_jugador [1] == 1){

                                    rlutil::locate (10, 21);
                                    cout << "Se ha hundido en el barro! pierde las trufas acumuladas y cede su turno (T-T)";
                                    cont_turnos ++;
                                    trufas_ronda = 0;
                                    puntaje2 = 0;
                                    jugador = 0;
                                    cont_lanzamientos2 = 0;
                                    bandera_3dados = 1;
                                    rlutil::getkey();
                                    break;
                                 }
                                else if (dados_jugador [0] == 1 || dados_jugador [1] == 1){

                                    rlutil::locate (10, 21);
                                    cout << "Ha salido un AS! Pierde las trufas de la ronda y cede su turno =C";
                                    cont_turnos++;
                                    trufas_ronda = 0;
                                    cont_lanzamientos2 = 0;
                                    jugador = 0;
                                    rlutil::getkey();
                                    break;

                                 }
                                else if (dados_jugador [0] == dados_jugador [1]){
                                    rlutil::locate (24, 21);
                                    cout <<"hizo un OINK! duplica y tira nuevamente";
                                    trufas_ronda += (suma*2);
                                    cont_lanzamientos2++;
                                    oinks2++;
                                    rlutil::getkey();
                                    borrar_dados();
                                    empezar_lanzamiento(puntaje1, puntaje2, jugador, bandera_3dados, trufas_ronda, cont_lanzamientos,cont_lanzamientos2, cont_turnos, oinks1, oinks2);
                                }
                                else if (dados_jugador [0] != dados_jugador [1]){

                                    rlutil::locate (34, 21);
                                    cout << "Hiciste "<<suma<< " trufas!";
                                    cont_lanzamientos2++;
                                    trufas_ronda += suma;
                                    rlutil::getkey();
                                    break;
                                }
                            break;
//////////////////////////////////////////////////             TRES DADOS           //////////////////////////////////////////////////
                            case 1:
                                     if (dados_jugador [0] == 1 && dados_jugador [1] == 1 && dados_jugador [2] == 1){

                                    rlutil::locate (17, 21);
                                    cout << "OH NO! 3 ASES! CEDE su turno y todas sus trufas ";
                                    cont_turnos++;
                                   puntaje1 += trufas_ronda;
                                   puntaje1 += puntaje2;
                                   puntaje2 = 0;
                                   trufas_ronda = 0;
                                    jugador = 0;
                                    cont_lanzamientos2 = 0;
                                    bandera_3dados = 1;
                                    rlutil::getkey();
                                    break;
                                 }
                                else if (dados_jugador [0] == 1 &&(dados_jugador [1] == 1 || dados_jugador [2] == 1)){

                                    rlutil::locate (10, 21);
                                    cout << "Se ha hundido en el barro! pierde las trufas de acumuladas y cede su turno";
                                    cont_turnos++;
                                    trufas_ronda = 0;
                                    puntaje2 = 0;
                                    jugador = 0;
                                    cont_lanzamientos2 = 0;
                                    bandera_3dados = 1;
                                    rlutil::getkey();
                                    break;

                                 }
                                else if (dados_jugador [0] == 1 || dados_jugador [1] == 1 || dados_jugador [2] == 1){

                                    rlutil::locate (10, 21);
                                    cout << "Ha salido un AS! Pierde las trufas de la ronda y cede su turno";
                                    cont_turnos++;
                                    jugador = 0;
                                    cont_lanzamientos2 = 0;
                                    trufas_ronda = 0;
                                    rlutil::getkey();
                                    break;
                                 }
                                else if (dados_jugador [0] == dados_jugador [1] && dados_jugador [0] == dados_jugador [2]){
                                    rlutil::locate (14, 21);
                                    cout <<"Hiciste un OINK! Duplica los dados y lanza nuevamente!";
                                    trufas_ronda += suma*2;
                                    cont_lanzamientos2 ++;
                                    oinks2++;
                                    rlutil::getkey();
                                    borrar_dados();
                                    empezar_lanzamiento(puntaje1, puntaje2, jugador, bandera_3dados, trufas_ronda, cont_lanzamientos, cont_lanzamientos2, cont_turnos, oinks1, oinks2);

                                }
                                else if (dados_jugador [0] != dados_jugador [1] || dados_jugador [0] == dados_jugador [2]){
                                    rlutil::locate (34, 21);
                                    cout << "Hiciste "<<suma<< " trufas!";
                                    trufas_ronda += suma;
                                    cont_lanzamientos2++;
                                    rlutil::getkey();
                                    break;
                                }
                            break;
                        }  //switch bandera
            break;
                }  //switch jugador

}//Fin de la función



/////////////////////////////////////////////    PANTALLA DE PUNTAJE FINAL      //////////////////////////////////////////////
void pantalla_puntaje (char nombre1[], char nombre2[], int& trufas_acumuladas, int& trufas_acumuladas2, int& mejor_lanzamiento1, int& mejor_lanzamiento2, int& oinks1, int& oinks2, int& pv_1, int& pv_2, int ganador[]){
int puntos_matriz [2][4]{};
string respuesta;
if (trufas_acumuladas> trufas_acumuladas2){
        pv_1 += 5;
        puntos_matriz [0][0] = 5;
}
else if(trufas_acumuladas2> trufas_acumuladas){
    pv_2 += 5;
    puntos_matriz [1][0] = 5;
}
else if(trufas_acumuladas == trufas_acumuladas2){
    pv_1 += 5;
    puntos_matriz [0][0] = 5;
    pv_2 += 5;
    puntos_matriz [1][0] = 5;

}

pv_1 += (trufas_acumuladas/50);
puntos_matriz [0][1] = (trufas_acumuladas/50);
pv_2 += (trufas_acumuladas2/50);
puntos_matriz [1][1] = (trufas_acumuladas2/50);
pv_1 += (oinks1*2);
pv_2 += (oinks2*2);

puntos_matriz [0][2] = (oinks1*2);
puntos_matriz [1][2] = (oinks2*2);


if (mejor_lanzamiento1> mejor_lanzamiento2){
    pv_1 += 2;
    puntos_matriz [0][3] = 2;

}
else if (mejor_lanzamiento2> mejor_lanzamiento1){
    pv_2 += 2;
    puntos_matriz [1][3] = 2;
}
else if (mejor_lanzamiento1 == mejor_lanzamiento2){
    pv_1 += 2;
    puntos_matriz [0][3] = 2;
    pv_2 += 2;
    puntos_matriz [1][3] = 2;
}


do{
borrar_pantalla();
cout <<"GRAN CERDO "<<endl;
cout <<"------------------------------------------------------------------------"<<endl;
cout << "HITO                   "<<nombre1<<"                     "<<nombre2<<endl;
cout <<"------------------------------------------------------------------------"<<endl;
cout <<"Más trufas en total    "<<puntos_matriz[0][0]<<" PDV ("<<trufas_acumuladas<<" trufas)"<<endl;
cout <<"Cada 50 trufas         "<<puntos_matriz[0][1]<<" PDV ("<<trufas_acumuladas<<" trufas)"<<endl;
cout <<"Oinks                  "<<puntos_matriz[0][2]<<" PDV ("<<oinks1<<" Oinks)"<<endl;
cout <<"Cerdo codicioso        "<<puntos_matriz[0][3]<<" PDV ("<<mejor_lanzamiento1<<" lanzamientos)"<<endl;
cout <<"------------------------------------------------------------------------"<<endl;
rlutil::locate  (50, 5);
cout <<puntos_matriz[1][0]<<" PDV ("<<trufas_acumuladas2<<" trufas)";
rlutil::locate  (50, 6);
cout <<puntos_matriz[1][1]<<" PDV ("<<trufas_acumuladas2<<" trufas)";
rlutil::locate  (50, 7);
cout <<puntos_matriz[1][2]<<" PDV ("<<oinks2<<" Oinks)";
rlutil::locate  (50, 8);
cout <<puntos_matriz[1][3]<<" PDV ("<<mejor_lanzamiento2<<" lanzamientos)";
rlutil::locate  (1, 14);
cout <<"          TOTAL        "<<pv_1<<" PDV                    "<<pv_2<<" PDV";
if (pv_1>pv_2){
rlutil::locate  (1, 16);
cout <<"GANADOR   "<<nombre1<<" con "<<pv_1<<" puntos de victoria.";
ganador [0] = 1;
ganador [1] = pv_1;

}
else if(pv_2> pv_1){
rlutil::locate  (1, 16);
cout <<"GANADOR   "<<nombre2<<" con "<<pv_2<<" puntos de victoria.";
ganador [0] = 2;
ganador [1] = pv_2;
}
else if (pv_1 == pv_2){
rlutil::locate  (1, 16);
cout <<" ES UN EMPATE! ";
}

rlutil::locate  (1, 18);
cout <<"Ingrese un Oink para continuar :";
cin >>respuesta;
respuesta = aMayuscula(respuesta);
}
while (respuesta != "OINK");
return;
}

////////////////////////////////////////////////

void guardar_ganador(char n_puntajemax [], int& puntajemax, int ganador [], char nombre1[], char nombre2[]){
   int  gana = 0, i;
   gana = ganador[0];
    if (gana == 1){
        for (i = 0; i<10; i++){
            n_puntajemax[i] = nombre1 [i];
        }
        puntajemax = ganador [1];
    }
    else{
        for (i = 0; i<10; i++){
            n_puntajemax[i] = nombre2 [i];
        }
        puntajemax = ganador [1];
    }
rlutil::getkey();
}


string aMayuscula(string cadena) {
  int i;
  for (i = 0; i < 5; i++) {
        cadena[i] = toupper(cadena[i]);
        }
  return cadena;
}


