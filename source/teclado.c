/*-------------------------------------
 teclado.c
-------------------------------------*/

// Añadir los includes que sean necesarios
#include <nds.h>
#include <stdio.h>
#include "defines.h"
#include "sprites.h"


// Esta funcion tiene que devolver el valor de la tecla pulsada
int  TeclaPulsada() {
   // Devuelve el valor asociado a la tecla pulsada: 
   // A=0; B=1; Select=2; Start=3; Der=4; Izq=5;
   // Arriba=6; Abajo=7; R=8; L=9;
   // -1 en otros casos

    int res = -1;
    int dato = TECLAS_DAT;

    if(( dato & 0x0001) == 0){ res = 0;};
    if((dato & 0x0002) == 0){ res = 1;};
    if((dato & 0x0004) == 0){ res = 2;};
    if((dato & 0x0008) == 0){ res = 3;};
    if((dato & 0x0010) == 0){ res = 4;};
    if((dato & 0x0020) == 0){ res = 5;};
    if((dato & 0x0040) == 0){ res = 6;};
    if((dato & 0x0080) == 0){ res = 7;};
    if((dato & 0x0100) == 0){ res = 8;};
    if((dato & 0x0200) == 0){ res = 9;};

    /*
     switch (dato){
        case 0x3fe:
            res = 0;
            break;
        case 0x3fd:
            res = 1;
            break;
        case 0x3fb:
            res = 2;
            break;
        case 0x3f7:
            res = 3;
            break;
        case 0x3ef:
            res = 4;
            break;
        case 0x3df:
            res = 5;
            break;
        case 0x3bf:
            res = 6;
            break;
        case 0x37f:
            res = 7;
            break;
        case 0x2ff:
            res = 8;
            break;
        case 0x1ff:
            res = 9;
            break;
        default:
            res = -1;
    }
    */

    return res;
}


// Rutina de atencion a la interrupcion del teclado
void IntTec() {
    int tecla = TeclaPulsada();
    iprintf("\x1b[10;0H %d",tecla);
}



