#include <conio.h> ///Funciones b�sicas de entrada y salida de constola ( I/O)
#include <iostream> ///Funciones b�sicas de entrada y salida (cin /// cout /// )
#include <cstdlib> ///Contiene los prototipos de funciones de C para gesti�n de memoria din�mica, control de procesos y otras, utilizo srand y rand para los n�meros aleatorios
#include <ctime>///Biblioteca con la funci�n time, la utilizo para crear un delay entre los dados lanzados y para inicializar la funci�n de n�meros aleatorios
#include <cctype> ///Biblioteca que contiene la funci�n toupper() que sirve para cambiar un caracter a may�sculas
#include <windows.h> //biblioteca para compatibilidad con Windows, tuve un problema al querer mostrar car�cteres alojados en un vector, cambiar la versi�n de la consola me solucion� el problema
#include <stdio.h>///Biblioteca que contiene la funci�n NULL, la utilizo para generar n�meros aleatorios
using namespace std;
#include "Funciones.h" //incluyo el archivo de cabecera "Funciones" para tener las funciones definidas por separado

///////////////////////////////////////////FUNCIONES////////////////////////////////////////

//Pausar Juego
void pausa(){
system ("pause");
borrar_pantalla();
}


// Men� de Estad�sticas
void estadisticas (){
    borrar_pantalla();
    cout <<"estas en estadisticas"<<endl;
    system ("pause");
}


//Men� de Cr�ditos
void cerditos (){
    borrar_pantalla();
    cout <<"Los Cerditos creadores de �ste juego son: " <<endl<<endl;
    cout <<"Enzo Mat�as Nieto"<<endl<<endl;
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


//Funciones para guardar nombres en el MEN� PRINCIPAL, utilic� el puntero ya que apunto a una variable (*) y no a una direcci�n en memoria (&),
//En este caso son variables de tipo Vector y con nombrarlas es suficiente
void pedir_nombre (char nombre1[]){
        borrar_pantalla();
cout <<endl<<"introduzca el nombre del Jugador N�1"<<endl;
cin >>nombre1;
}
void pedir_nombre2 (char nombre2[]){
        borrar_pantalla();
cout <<endl<<"introduzca el nombre del Jugador N�2"<<endl;
cin >>nombre2;
}


//Lanzamiento por Turnos para definir el primer jugador en lanzar (lanzamiento y decisi�n)
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
        cout <<endl<<"Veamos qui�n empieza!"<<endl<<endl;
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
            cout <<endl<<nombre1<< " ha sacado el mayor puntaje con "<<punt_j1<<" puntos!"<<endl<<endl<<"Ser� el primer jugador en lanzar"<<endl<<endl;
            primer_jugador = 0;
            bandera_turno = 3;
            pausa();
            break;

        }
        // Pregunto si el puntaje del Jugador 2 es el mayor
        else if(punt_j1<punt_j2) {
            cout <<endl<<nombre2<< " ha sacado el mayor puntaje con "<<punt_j2<<" puntos!"<<endl<<endl<<"Ser� el primer jugador en lanzar"<<endl<<endl;
            primer_jugador = 1;
            bandera_turno = 3;
            pausa();
            break;
        }
       //si ning�n puntaje es el mayor, tenemos que buscar el dado m�s grande y qui�n lo tir�
       //Asumimos que la �nica alternativa es que los puntajes sean iguales, y eval�o el vector para buscar el dado m�s grande

        else if (punt_j1 == punt_j2) {

        // For para buscar el m�ximo de los dados y alojar su direcci�n de memoria en la variable "y"
                for (x = 0; x<4; x++){

                    if (punt_j1_j2 [x] > punt_max){
                        punt_max = punt_j1_j2 [x];
                        y = x;
                    }
                }

                //For para evaluar si el dado m�s grande tiene un dado igual en el vector
                //la condici�n " z!=y " hace referencia a que las posiciones en las que voy a buscar son distintas a la direcci�n donde se encuentra el puntaje m�ximo
                for (z = 0;z<4  &&  z!=y; z++){
                    //Pregunto si el dado m�s grande est� repetido en el vector
                    if (punt_j1_j2 [y] == punt_j1_j2[z]){
                    /// Si hay un dado repetido (y es el m�ximo junto a otro dado mas) pueden pasar 2 cosas:
                    ///Los dados son iguales de a pares (porque tienen el mismo puntaje)
                    ///Todos los dados son iguales entre s�
                    ///en cualquiera de los 2 casos es empate, es decir
                    cout <<endl<<"Empataron todos los dados! Tiran ambos devuelta"<<endl<<endl;
                    pausa();
                    bandera_turno = 0;
                    break;
                    }
                }
        }
        else{
//Si el dado mas grande no est� repetido, este IF pregunta la posici�n del dado m�s grande y cambia el valor de la variable local "primer_jugador" dependiendo de qui�n lo tenga;
//(La variable primer_jugador va a definir qui�n empieza el juego)
        if (y == 1 ||  y == 0){
            cout <<endl<<"Empataron! pero "<<nombre1<<" sac� el dado mas alto!"<<endl<<endl;
            cout <<"Ser� el primero en jugar..."<<endl;
            primer_jugador = 0;
            break;
        }
        else if (y == 2 || y == 3){
            cout<<endl<< "Empataron! pero "<<nombre2<< " sac� el dado mas alto!"<<endl<<endl;
            cout <<"Ser� el primero en jugar..."<<endl;
            primer_jugador = 1;
            break;

        }

            }


                }//final switch bandera
        }// final del DO
while (bandera_turno != 3);
}


//Funci�n para cambiar el men� una vez que se defina el primero en lanzar los dados
void comienzo_del_juego (char nombre1[], char nombre2[], bool& primer_jugador, int& trufas_acumuladas, int& trufas_acumuladas2, int & mejor_lanzamiento1, int& mejor_lanzamiento2){
            char respuesta = 'S';
            bool bandera_turno = primer_jugador;
            int rondas = 1;
            int trufas_ronda = 0;
            int cont_turnos = 0;
            int cont_lanzamientos =0, cont_lanzamientos2 = 0;
    do{
            borrar_pantalla();
            if (cont_turnos/2 == rondas){
                            rondas ++;
                        }
            cout <<"GRAN CERDO"<<endl;
            cout<<"------------------------------------------------------------------------"<<endl;
            cout <<nombre1<<": "<<trufas_acumuladas<<" trufas acumuladas"<<"     "<<nombre2<<": "<<trufas_acumuladas2<<" trufas acumuladas"<<endl<<endl<<endl;
            cout <<"el mejor lanzamiento de "<<nombre1<<" fu� de "<<mejor_lanzamiento1<<endl;
            cout <<"el mejor lanzamiento de "<<nombre2<<" fu� de "<<mejor_lanzamiento2<<endl;
                        //Si es el turno del jugador1, y el jugador 1 gan� la primer tirada entonces muestro sus datos por pantalla, y pregunto si desea seguir lanzando
                    switch (bandera_turno){
                        case 0:
                                cout <<"TURNO DE "<<nombre1<<"!"<<endl;
                                cout <<"+-------------------------+"<<endl;
                                cout <<"| RONDA #"<<rondas<<"                |"<<endl;
                                cout <<"| TRUFAS DE LA RONDA: "<<trufas_ronda<<"   |"<<endl;
                                cout <<"| LANZAMIENTOS: "<<cont_lanzamientos<<"         |"<<endl;
                                cout <<"+-------------------------+"<<endl<<endl;
                                cout <<"LANZAMIENTO # "<<cont_lanzamientos+1<<endl<<endl;
                                cout <<"Tirar Dados?  S/N"<<endl;
                                cin >>respuesta;
                               respuesta = toupper(respuesta);
                                    if(respuesta == 'S'){
                                        empezar_lanzamiento(trufas_acumuladas, trufas_acumuladas2, bandera_turno, trufas_ronda, cont_lanzamientos, cont_turnos);
                                        cont_lanzamientos ++;
                                        borrar_pantalla();
                                        break;
                                }
                                    else if (respuesta == 'N'){
                                        cout <<"est� seguro?...se acumular�n las trufas de la ronda actual:  S/N "<<endl;
                                        cin >>respuesta;
                                        respuesta = toupper(respuesta);
                                        if (respuesta == 'S'){
                                            trufas_acumuladas += trufas_ronda;
                                            trufas_ronda = 0;
                                            bandera_turno = true;
                                            if (cont_lanzamientos > mejor_lanzamiento1){
                                                mejor_lanzamiento1 = cont_lanzamientos + 1;
                                            }

                                            cont_lanzamientos = 0;
                                            cont_turnos ++;
                                            borrar_pantalla();
                                        }
                                    }
                        break;
                        case 1:
                                cout <<"TURNO DE "<<nombre2<<"!"<<endl;
                                cout <<"+-------------------------+"<<endl;
                                cout <<"| RONDA #"<<rondas<<"                |"<<endl;
                                cout <<"| TRUFAS DE LA RONDA: "<<trufas_ronda<<"   |"<<endl;
                                cout <<"| LANZAMIENTOS: "<<cont_lanzamientos2<<"         |"<<endl;
                                cout <<"+-------------------------+"<<endl;
                                cout <<"LANZAMIENTO # "<<cont_lanzamientos2+1<<endl<<endl;
                                cout <<"Tirar Dados?  S/N"<<endl;
                                cin >>respuesta;
                                toupper(respuesta);
                                    if (respuesta =='S'){
                                        empezar_lanzamiento(trufas_acumuladas, trufas_acumuladas2, bandera_turno, trufas_ronda, cont_lanzamientos2, cont_turnos);
                                        cont_lanzamientos2 ++;
                                        borrar_pantalla();
                                }
                                    else if (respuesta == 'N'){
                                        cout <<"est� seguro? Se acumular�n las trufas de la ronda S/N"<<endl;
                                        cin >>respuesta;
                                        respuesta = toupper(respuesta);
                                        if (respuesta == 'S'){
                                            trufas_acumuladas2 += trufas_ronda;
                                            trufas_ronda = 0;
                                            bandera_turno = false;
                                            if (cont_lanzamientos2 > mejor_lanzamiento2){
                                                mejor_lanzamiento2 = cont_lanzamientos + 1;
                                            }
                                            cont_lanzamientos = 0;
                                            cont_turnos ++;
                                            borrar_pantalla();
                                        }
                                }

                        break;
                    }//switch corchete final
        }//DO corchete final
    while (rondas <6);
    }

///*////////////////////////////////////////////Funci�n para tirar los dados  al comienzo de la primer ronda//////////////////////////////////////////////////
//En �sta funci�n hago un lanzamiento individual, que puede ser de 2 o 3 dados
//dependiendo de las situaciones que se vayan dando en el juego
void  empezar_lanzamiento(int& puntaje1, int& puntaje2, bool& jugador, int& trufas_ronda, int& cont_lanzamientos, int& cont_turnos){
int i, z, suma;
int cantidad_dados = 2;
int dados_jugador[cantidad_dados];
bool bandera_3dados = false;

//En �sta parte pregunto si las trufas acumuladas son menores a 50,
//esto condiciona la cantidad de dados que se van a utilizar
if (puntaje1 >= 50 || puntaje2 >= 50){
    bandera_3dados = true;
}
////////////////Lanzamiento de dados ///////////////////////////

// Eval�o la bandera para ver cuantos dados se tiran y sumo el resultado
            if (bandera_3dados == false){
                cantidad_dados = 2;
                for (i = 0; i < 2; i ++){
                delay (1);
                dados_jugador [i]  = dado();
                }
                suma = dados_jugador [0] + dados_jugador [1];
            }
            else{
                cantidad_dados = 3;
                for (z = 0; i < 3; i ++){
                delay (1);
                dados_jugador [i]  = dado();
                }
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

                                    cout << "El cerdito se ha hundido en el barro! pierde todas  las trufas acumuladas y cede su turno (T-T)"<<endl;
                                    pausa();
                                    puntaje1 = 0;
                                    cont_turnos ++;
                                    jugador = 1;
                                    bandera_3dados = true;
                                    cont_lanzamientos = 0;
                                    break;
                                 }
                                else if (dados_jugador [0] == 1 || dados_jugador [1] == 1){

                                    cout << "Ha salido un AS! Pierde todas las trufas de la ronda actual y cede su turno =C"<<endl;
                                    pausa();
                                    cont_turnos ++;
                                    trufas_ronda = 0;
                                    jugador = 1;
                                    cont_lanzamientos = 0;
                                    break;

                                 }
                                else if (dados_jugador [0] == dados_jugador [1]){
                                    cout <<"hiciste un OINK! duplica y tira nuevamente"<<endl;
                                    trufas_ronda += suma*2;
                                    cout <<"van "<<trufas_ronda<<" puntos"<<endl;
                                    pausa();
                                    empezar_lanzamiento(puntaje1, puntaje2, jugador, trufas_ronda, cont_lanzamientos, cont_turnos);
                                }
                                else if (dados_jugador [0] != dados_jugador [1]){

                                    cout << "Hiciste "<<suma<< " trufas!"<<endl;
                                    trufas_ronda += suma;
                                    pausa();
                                    break;
                                }
                                break;
//////////////////////////////////////////////////             TRES DADOS           //////////////////////////////////////////////////
                            case 1:
                                     if (dados_jugador [0] == 1 || dados_jugador [1] == 1 || dados_jugador [2] == 1){

                                    cout << "Ha salido un AS! Pierde todas las trufas de la ronda actual y  cede su turno =C"<<endl;
                                    pausa();
                                    cont_turnos++;
                                    jugador = 1;
                                    trufas_ronda = 0;
                                    cont_lanzamientos = 0;
                                    break;
                                 }
                                else if (dados_jugador [0] == 1 && dados_jugador [1] == 1 || dados_jugador [2] == 1){

                                    cout << "El cerdito se ha hundido en el barro! pierde todas las trufas de todas las rondas y cede su turno (T-T)"<<endl;
                                    pausa();
                                    cont_turnos++;
                                    puntaje2 = 0;
                                    jugador = 1;
                                    cont_lanzamientos = 0;
                                    bandera_3dados = true;
                                    break;

                                }
                                else if (dados_jugador [0] == 1 && dados_jugador [1] == 1 && dados_jugador [2] == 1){

                                    cout << "OH NO! 3 ASES!  CEDE todas sus trufas y su turno (T-T)"<<endl;
                                    pausa();
                                    cont_turnos ++;
                                   puntaje2 += trufas_ronda;
                                   puntaje2 += puntaje1;
                                   puntaje1 = 0;
                                   trufas_ronda = 0;
                                   cont_lanzamientos = 0;
                                    jugador = 1;
                                    bandera_3dados = true;
                                    break;
                                 }
                                else if (dados_jugador [0] != (dados_jugador [2] || dados_jugador [3])){
                                    cout << "Hiciste "<<suma<< "trufas!"<<endl;
                                    pausa();
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

                                    cout << "El cerdito se ha hundido en el barro! pierde todas  las trufas de todas las rondas y cede su turno (T-T)"<<endl;
                                    pausa();
                                    cont_turnos ++;
                                    trufas_ronda = 0;
                                    puntaje2 = 0;
                                    jugador = 0;
                                    cont_lanzamientos = 0;
                                    bandera_3dados = true;
                                    break;
                                 }
                                else if (dados_jugador [0] == 1 || dados_jugador [1] == 1){

                                    cout << "Ha salido un AS! Pierde todas las trufas de la ronda actual y cede su turno =C"<<endl;
                                    pausa();
                                    cont_turnos++;
                                    trufas_ronda = 0;
                                    cont_lanzamientos = 0;
                                    jugador = 0;
                                    break;

                                 }
                                else if (dados_jugador [0] == dados_jugador [1]){
                                    cout <<"hizo un OINK! duplica y tira nuevamente"<<endl;
                                    trufas_ronda += (suma*2);
                                    pausa();
                                    empezar_lanzamiento(puntaje1, puntaje2, jugador, trufas_ronda, cont_lanzamientos, cont_turnos);
                                }
                                else if (dados_jugador [0] != dados_jugador [1]){

                                    cout <<endl<< "Hiciste "<<suma<< " trufas!"<<endl;
                                    trufas_ronda += suma;
                                    pausa();
                                    break;
                                }
                                break;
//////////////////////////////////////////////////             TRES DADOS           //////////////////////////////////////////////////
                            case 1:
                                     if (dados_jugador [0] == 1 || dados_jugador [1] == 1 || dados_jugador [2] == 1){

                                    cout << "Ha salido un AS! Pierde todas las trufas de la ronda actual y  cede su turno =C"<<endl;
                                    pausa();
                                    cont_turnos++;
                                    jugador = 0;
                                    cont_lanzamientos = 0;
                                    trufas_ronda = 0;
                                    break;
                                 }
                                else if (dados_jugador [0] == 1 && dados_jugador [1] == 1 || dados_jugador [2] == 1){

                                    cout << "El cerdito se ha hundido en el barro! pierde todas  las trufas de todas las rondas y cede su turno (T-T)"<<endl;
                                    pausa();
                                    cont_turnos++;
                                    trufas_ronda = 0;
                                    puntaje2 = 0;
                                    jugador = 0;
                                    cont_lanzamientos = 0;
                                    bandera_3dados = true;
                                    break;

                                 }
                                else if (dados_jugador [0] == 1 && dados_jugador [1] == 1 && dados_jugador [2] == 1){

                                    cout << "OH NO! 3 ASES!  CEDE su turno y todas sus trufas (T-T)"<<endl;
                                    pausa();
                                    cont_turnos++;
                                   puntaje1 += trufas_ronda;
                                   puntaje1 += puntaje2;
                                   puntaje2 = 0;
                                   trufas_ronda = 0;
                                    jugador = 0;
                                    cont_lanzamientos = 0;
                                    bandera_3dados = true;
                                    break;
                                 }
                                else if (dados_jugador [0] != (dados_jugador [2] || dados_jugador [3])){
                                    cout << "Hiciste "<<suma<< "trufas!"<<endl;
                                    trufas_ronda += suma;
                                    pausa();
                                    break;
                                }
                                break;

                        }  //switch bandera
            break;

                }   //switch jugador

}//Fin de la funci�n
