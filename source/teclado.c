/*-------------------------------------
 teclado.c
-------------------------------------*/

// Añadir los includes que sean necesarios
#include <nds.h>
#include <stdio.h>
#include "defines.h"
#include "sprites.h"
#include "fondos.h"

extern int estado;
// Esta funcion tiene que devolver el valor de la tecla pulsada
int  TeclaPulsada() {
    if((TECLAS_DAT & 0X0001)==0){
        return A;
    }else if((TECLAS_DAT & 0X0002)==0){
        return B;
    }else if((TECLAS_DAT & 0X0004)==0){
        return SELECT;
    }else if((TECLAS_DAT & 0X0008)==0){
        return START;
    }else if((TECLAS_DAT & 0X0010)==0){
        return DCHA;
    }else if((TECLAS_DAT & 0X0020)==0){
        return IZDA;
    }else if((TECLAS_DAT & 0X0040)==0){
        return ARRIBA;
    }else if((TECLAS_DAT & 0X0080)==0){
        return ABAJO;
    }else if((TECLAS_DAT & 0X0100)==0){
        return R;
    }else if((TECLAS_DAT & 0X0200)==0){
        return L;
	}else{
        return -1;
	}
	
   // Devuelve el valor asociado a la tecla pulsada: 
   // A=0; B=1; Select=2; Start=3; Der=4; Izq=5;
   // Arriba=6; Abajo=7; R=8; L=9;
   // -1 en otros casos

}


// Rutina de atencion a la interrupcion del teclado
void IntTec() {

    int i= 0;
    if (i==0){
        i++;
    }
		

}



