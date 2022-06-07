#include <conio.h> ///Funciones básicas de entrada y salida de constola ( I/O)
#include <locale.h> ///Biblioteca con propósitos de localización, la uso para configurar la entrada de caracteres y que admita acentos y la letra Ñ entre otros
#include <wchar.h>
#include <iostream> ///Funciones básicas de entrada y salida (cin /// cout /// )
#include <cstdlib> ///Contiene los prototipos de funciones de C para gestión de memoria dinámica, control de procesos y otras, utilizo srand y rand para los números aleatorios
#include <ctime>///Biblioteca con la función time, la utilizo para crear un delay entre los dados lanzados y para inicializar la función de números aleatorios
#include <cctype> ///Biblioteca que contiene la función toupper() que sirve para cambiar un caracter a mayúsculas
#include <windows.h> //biblioteca para compatibilidad con Windows, tuve un problema al querer mostrar carácteres alojados en un vector, cambiar la versión de la consola me solucionó el problema
#include <stdio.h>///Biblioteca que contiene la función NULL, la utilizo para generar números aleatorios
using namespace std;
#include "Funciones.h" //incluyo el archivo de cabecera "Funciones" para tener las funciones definidas por separado

///////////////////////////////////////////FUNCIONES////////////////////////////////////////

//Pausar Juego
void pausa(){
system ("pause");
borrar_pantalla();
}


// Menú de Estadísticas
void estadisticas (){
    borrar_pantalla();
    cout <<"estas en estadisticas"<<endl;
    system ("pause");
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


//Lanzar  y mostrar por pantalla un dado
 int dado (){
    int  numero;
    numero = rand()% 6 + 1;
   switch (numero){
     case 1:
             cout<<"+-------+"<<endl<<"|       |"<<endl<<"|   x   |"<<endl<<"|       |"<<endl<<"+-------+"<<endl;
             break;


    case 2:
             cout<<"+-------+"<<endl<<"| x     |"<<endl<<"|       |"<<endl<<"|     x |"<<endl<<"+-------+"<<endl;
            break;


    case 3:
             cout<<"+-------+"<<endl<<"| x 	|"<<endl<<"|   x   |"<<endl<<"|     x |"<<endl<<"+-------+"<<endl;
            break;


    case 4:
             cout<<"+-------+"<<endl<<"| x   x |"<<endl<<"|       |"<<endl<<"| x   x |"<<endl<<"+-------+"<<endl;
            break;

    case 5:
            cout<<"+-------+"<<endl<<"| x   x |"<<endl<<"|   x   |"<<endl<<"| x   x |"<<endl<<"+-------+"<<endl;
            break;

    case 6:
             cout<<"+-------+"<<endl<<"| x   x |"<<endl<<"| x   x |"<<endl<<"| x   x |"<<endl<<"+-------+"<<endl;
            break;

    }
    return numero;
    }


//Funciones para guardar nombres en el MENÚ PRINCIPAL, utilicé el puntero ya que apunto a una variable (*) y no a una dirección en memoria (&),
//En este caso son variables de tipo Vector y con nombrarlas es suficiente
void pedir_nombre (char nombre1[]){
        borrar_pantalla();
cout <<endl<<"introduzca el nombre del Jugador N°1"<<endl;
cin >>nombre1;
}
void pedir_nombre2 (char nombre2[]){
        borrar_pantalla();
cout <<endl<<"introduzca el nombre del Jugador N°2"<<endl;
cin >>nombre2;
}


//Lanzamiento por Turnos para definir el primer jugador en lanzar (lanzamiento y decisión)
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
        cout <<endl<<"Veamos quién empieza!"<<endl<<endl;
        cout <<"Es el turno de "<<nombre1<<"!"<<endl;
        cout <<"Tirar Dados? S/N"<<endl;
        cin >>respuesta;
       respuesta = toupper(respuesta);
        borrar_pantalla();
        if (respuesta == 'S'){
            for (i = 0; i <2; i++){
            delay (1);
            punt_j1_j2 [i]  = dado();
        }
            punt_j1 = punt_j1_j2 [0] + punt_j1_j2 [1];
            cout <<nombre1<<" ha lanzado un "<<punt_j1 <<"!"<<endl;
            bandera_turno ++;
            pausa();
            break;
    }
        else{
            break;
            }
case 1:
        borrar_pantalla();
        cout <<endl<<"Es el turno de "<<nombre2<<"!"<<endl;
        cout <<"Tirar Dados? S/N"<<endl;
        cin >>respuesta;
       respuesta =  toupper(respuesta);
        borrar_pantalla();
            if (respuesta == 'S'){
                for (i = 2; i <4; i++){
                        delay (1);
                        punt_j1_j2 [i]  = dado();
                        }
            punt_j2 = punt_j1_j2 [2] +punt_j1_j2 [3];
            cout <<nombre2<< " hizo "<<punt_j2<<" puntos!"<<endl;
            bandera_turno ++;
            pausa();
            break;
    }
            else{
                break;
                }
case 2:
        //Pregunto si el puntaje del Jugador 1 es el mayor
        if (punt_j1 >punt_j2){
            cout <<endl<<nombre1<< " ha sacado el mayor puntaje con "<<punt_j1<<" puntos!"<<endl<<endl<<"Será el primer jugador en lanzar"<<endl<<endl;
            primer_jugador = 0;
            bandera_turno = 3;
            pausa();
            break;

        }
        // Pregunto si el puntaje del Jugador 2 es el mayor
        else if(punt_j1<punt_j2) {
            cout <<endl<<nombre2<< " ha sacado el mayor puntaje con "<<punt_j2<<" puntos!"<<endl<<endl<<"Será el primer jugador en lanzar"<<endl<<endl;
            primer_jugador = 1;
            bandera_turno = 3;
            pausa();
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

                //For para evaluar si el dado más grande tiene un dado igual en el vector
                //la condición " z!=y " hace referencia a que las posiciones en las que voy a buscar son distintas a la dirección donde se encuentra el puntaje máximo
                for (z = 0; z <4 && z!=y; z++){
                    //Pregunto si el dado más grande está repetido en el vector
                    if (punt_j1_j2 [y] == punt_j1_j2[z]){
                    /// Si hay un dado repetido (y es el máximo junto a otro dado mas) pueden pasar 2 cosas:
                    ///Los dados son iguales de a pares (porque tienen el mismo puntaje)
                    ///Todos los dados son iguales entre sí
                    ///en cualquiera de los 2 casos es empate, es decir
                    cout <<endl<<"Empataron todos los dados! Tiran ambos devuelta"<<endl<<endl;
                    bandera_turno = 0;
                    break;
                    }
                else{
//Si el dado mas grande no está repetido, este IF pregunta la posición del dado más grande y cambia el valor de la variable local "primer_jugador" dependiendo de quién lo tenga;
//(La variable primer_jugador va a definir quién empieza el juego)
        if (y == 1 ||  y == 0){
                        cout <<endl<<"Empataron! pero "<<nombre1<<" sacó el dado mas alto!"<<endl<<endl;
                        cout <<"Será el primero en jugar..."<<endl;
                        primer_jugador = 0;
                        break;
                    }
        else if (y == 2 || y == 3){
        cout<<endl<< "Empataron! pero "<<nombre2<< " sacó el dado mas alto!"<<endl<<endl;
        cout <<"Será el primero en jugar..."<<endl;
        primer_jugador = 1;
        break;

                }

                }
                }
                }
        bandera_turno ++;
        pausa();
        break;
}
}
while (bandera_turno != 3);
}


//Función para cambiar el menú una vez que se defina el primero en lanzar los dados
void comienzo_del_juego (char nombre1[], char nombre2[], bool& primer_jugador, int& trufas_acumuladas, int& trufas_acumuladas2, int & mejor_lanzamiento1, int& mejor_lanzamiento2){
            char respuesta = 'S';
            bool bandera_turno = primer_jugador;
            int rondas = 1;
            int cont_turnos = 0;
            int cont_lanzamientos =0, cont_lanzamientos2 = 0;
    do{
            borrar_pantalla();
            if (cont_turnos/2 == rondas){
                            rondas ++;
                        }
            cout <<"GRAN CERDO"<<endl;
            cout<<"------------------------------------------------------------------------"<<endl;
            cout <<nombre1<<": "<<trufas_acumuladas<<" trufas acumuladas        "<<nombre2<<": "<<trufas_acumuladas2<<" trufas acumuladas"<<endl<<endl<<endl;
                        //Si es el turno del jugador1, y el jugador 1 ganó la primer tirada entonces muestro sus datos por pantalla, y pregunto si desea seguir lanzando
                    switch (bandera_turno){
                        case 0:
                                cout <<"TURNO DE "<<nombre1<<"!"<<endl;
                                cout <<"+-------------------------+"<<endl;
                                cout <<"| RONDA #"<<rondas<<"                |"<<endl;
                                cout <<"| TRUFAS DE LA RONDA: "<<trufas_acumuladas<<"   |"<<endl;
                                cout <<"| LANZAMIENTOS: "<<cont_lanzamientos<<"         |"<<endl;
                                cout <<"+-------------------------+"<<endl<<endl;
                                cout <<"LANZAMIENTO # "<<cont_lanzamientos+1<<endl<<endl;
                                cout <<"Tirar Dados?  S/N"<<endl;
                                cin >>respuesta;
                               respuesta = toupper(respuesta);
                                    if(respuesta == 'S'){
                                        empezar_lanzamiento(trufas_acumuladas, trufas_acumuladas2, bandera_turno);
                                        cont_lanzamientos ++;
                                        borrar_pantalla();
                                        break;
                                }
                                    else if (respuesta == 'N'){
                                     cout <<"está seguro?...  S/N "<<endl;
                                     cin >>respuesta;
                                   respuesta = toupper(respuesta);
                                        if (respuesta == 'S'){
                                            bandera_turno = true;
                                            cont_turnos ++;
                                            borrar_pantalla();
                                            break;
                                        }
                                }
                        case 1:
                                cout <<"TURNO DE "<<nombre2<<"!"<<endl;
                                cout <<"+-------------------------+"<<endl;
                                cout <<"| RONDA #"<<rondas<<"                |"<<endl;
                                cout <<"| TRUFAS DE LA RONDA: "<<trufas_acumuladas2<<"   |"<<endl;
                                cout <<"| LANZAMIENTOS: "<<cont_lanzamientos2<<"         |"<<endl;
                                cout <<"+-------------------------+"<<endl;
                                cout <<"LANZAMIENTO # "<<cont_lanzamientos2+1<<endl<<endl;
                                cout <<"Tirar Dados?  S/N"<<endl;
                                cin >>respuesta;
                                toupper(respuesta);
                                    if (respuesta =='S'){
                                        empezar_lanzamiento(trufas_acumuladas, trufas_acumuladas2, bandera_turno);
                                        cont_lanzamientos2 ++;
                                        borrar_pantalla();
                                }
                                    else if (respuesta == 'N'){
                                        cout <<"está seguro?..."<<endl;
                                        cin >>respuesta;
                                        toupper(respuesta);
                                             if (respuesta == 'S'){
                                                bandera_turno = false;
                                                cont_turnos ++;
                                                borrar_pantalla();
                                                break;
                                        }
                                }

                    }//switch corchete final

        }//DO corchete final
    while (rondas <6);
    }

///*////////////////////////////////////////////Función para tirar los dados  al comienzo de la primer ronda//////////////////////////////////////////////////
//En ésta función hago un lanzamiento individual, que puede ser de 2 o 3 dados
//dependiendo de las situaciones que se vayan dando en el juego
void  empezar_lanzamiento(int& puntaje1, int& puntaje2, bool& jugador){
int i, z, cantidad_dados;
int dados_jugador[cantidad_dados];
int puntaje_x_turno1 = 0, puntaje_x_turno2 = 0;
//En ésta parte pregunto si las trufas acumuladas son menores a 50,
//esto condiciona la cantidad de dados que se van a utilizar
        if (puntaje1 < 50 || puntaje2 < 50){
            cantidad_dados = 2;
        }
        else{
            cantidad_dados = 3;
        }

            for (i = 0; i < cantidad_dados; i ++){
            delay (1);
            dados_jugador [i]  = dado();
        }
            for (z = 0; z < cantidad_dados; z ++){
                if (dados_jugador [z]  == 1){
                        jugador = 1;
                        cout <<"Ha salido un as! pierde las trufas de la ronda actual y cede el turno"<<endl<<endl;

                        pausa();
                        break;
            }

            }

    }


    /*            switch (jugador){

                    case 0:
                        if (dados_jugador [0] != dados_jugador [1]){
                            vec1 = dados_jugador [0] + dados_jugador [1];
                            puntaje1 += vec1;

                            cout <<endl<<"sumaste "<<vec1<<" trufas!"<<endl<<endl;
                            pausa();
                            break;
                        }
                        else if (dados_jugador [0] == dados_jugador[1] && dados_jugador [0] != 1){
                            vec1 = dados_jugador [0]*2 + dados_jugador [1]*2;
                            puntaje1 += vec1;
                            cout <<endl<<"el cerdito hizo un OINK y duplica los dados! Suma "<<vec1<<" puntos y tira devuelta! "<<endl<<endl;
                            delay(1);
                            empezar_lanzamiento (puntaje1, puntaje2, jugador);
                            break;

                        }
                        else if (dados_jugador [0] == 1 && dados_jugador[1] == 1){
                            puntaje1 = 0;
                            jugador = 1;
                            cout <<"El cerdito se undió en el barro! pierde todas sus trufas =C"<<endl<<endl;
                            pausa();
                            break;

                        }
                    case 1:
                        if (dados_jugador [0] != dados_jugador [1]){
                             vec2 = dados_jugador [0] + dados_jugador [1];
                            puntaje2 += vec2;
                            cout <<"sumaste "<<vec2<<" trufas!"<<endl<<endl;
                            pausa();
                            break;
                        }
                        else if (dados_jugador [0] == dados_jugador[1] && dados_jugador [0] != 1){
                            vec2 =dados_jugador[0]*2 + dados_jugador [1]*2;
                            puntaje2 += vec2;
                            cout <<endl<<"el cerdito hizo un OINK y duplica los dados! Suma "<<vec2<<" puntos y tira devuelta! "<<endl<<endl;
                            delay(1);
                            empezar_lanzamiento (puntaje1, puntaje2, jugador);
                            break;

                        }
                        else if (dados_jugador [0] == 1 && dados_jugador[1] == 1){
                            puntaje2 = 0;
                            jugador = 0;
                            cout <<"El cerdito se undió en el barro! pierde el turno y todas sus trufas =C"<<endl<<endl;
                            pausa();
                            break;

                        }
            } */
