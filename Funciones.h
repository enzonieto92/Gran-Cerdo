#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


////////////////////////////////////////////////////////////////FUNCIONES DECLARADAS////////////////////////////////////////////////////////////////////////////
int cantidad_dados(int);
void pedir_nombre (char nombre1[]);
void pedir_nombre2 (char nombre2[]);
void borrar_pantalla ();
void estadisticas ();
void cerditos ();
void pausa();
int dado();
void delay(int);
void pregunta (char[], char[], bool&);
void comienzo_del_juego(char[], char[], bool&, int&, int&, int&, int&);
void empezar_lanzamiento(int&, int&, bool&);


#endif // FUNCIONES_H_INCLUDED
