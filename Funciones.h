#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


////////////////////////////////////////////////////////////////FUNCIONES DECLARADAS////////////////////////////////////////////////////////////////////////////


void borrar_pantalla ();
void estadisticas (char[], int&);
void cerditos ();
void pausa();
void posicion(int, int);
int dado();
void delay(int);
void pedir_nombres (char[], char[]);
void pregunta (char[], char[], bool&);
void comienzo_del_juego(char[], char[], bool&, int&, int&, int&, int&, int&, int&);
void empezar_lanzamiento(int&, int&, bool&, bool&, int&, int&, int&, int&, int&, int&);
void pantalla_puntaje (char[], char[], int&, int&, int&, int&, int&, int&, int&, int&, int []);
void guardar_ganador (char[], int&, int[], char[], char[]);
string aMayuscula(string);
#endif // FUNCIONES_H_INCLUDED
