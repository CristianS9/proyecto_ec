/*-------------------------------------
teclado.h
-------------------------------------*/

extern int tecla; // variable para guardar el valor de la tecla pulsada

//Esta funci�n tiene que devolver el valor de la tecla pulsada
extern int TeclaPulsada();
extern int * teclasPulsadas();

//Rutina de atenci�n a la interrupci�n del teclado
extern void IntTec();

