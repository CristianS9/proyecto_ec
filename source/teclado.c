/*-------------------------------------
 teclado.c
-------------------------------------*/

// Añadir los includes que sean necesarios
#include <nds.h>
#include <stdio.h>
#include "defines.h"
#include "sprites.h"
#include "fondos.h"
#include "elementos.h"
#include "gravedad.h"



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

// Array que indica que teclas estan pulsadas
int teclas_pulsadas[10] = {0};

int * teclasPulsadas(){

    for (int i = 0; i < 10; ++i) {
        teclas_pulsadas[i] = 0;
    }

    if((TECLAS_DAT & 0X0001)==0){ teclas_pulsadas[A] = 1; };
    if((TECLAS_DAT & 0X0002)==0){ teclas_pulsadas[B] = 1; };
    if((TECLAS_DAT & 0X0004)==0){ teclas_pulsadas[SELECT] = 1; };
    if((TECLAS_DAT & 0X0008)==0){ teclas_pulsadas[START] = 1; };
    if((TECLAS_DAT & 0X0010)==0){ teclas_pulsadas[DCHA] = 1; };
    if((TECLAS_DAT & 0X0020)==0){ teclas_pulsadas[IZDA] = 1; };
    if((TECLAS_DAT & 0X0040)==0){ teclas_pulsadas[ARRIBA] = 1; };
    if((TECLAS_DAT & 0X0080)==0){ teclas_pulsadas[ABAJO] = 1; };
    if((TECLAS_DAT & 0X0100)==0){ teclas_pulsadas[R] = 1; };
    if((TECLAS_DAT & 0X0200)==0){ teclas_pulsadas[L] = 1; };

    return  teclas_pulsadas;
}

int colisiona;

void movimientoPersonaje(){
    int * teclas_pulsadas = teclasPulsadas();
    /*
    if (teclas_pulsadas[DCHA] == 1){
       colisiona = elemento_en_pos((int) personaje_pos_x +16 + 0.01, personaje_pos_y);
        //iprintf("\x1b[01;00H           %d     ",colisiona);


        if( colisiona != -1){
            teclas_pulsadas[DCHA] = 0;

        }

        movimientoPersonaje(teclas_pulsadas);
    }
    */



    if(teclas_pulsadas[IZDA] == 1  || teclas_pulsadas[DCHA] == 1 || teclas_pulsadas[ARRIBA] == 1 || teclas_pulsadas[ABAJO] == 1 ){
            if(teclas_pulsadas[DCHA] == 1 && elemento_en_pos((int)(personaje_pos_x +16 + 0.01),(int)personaje_pos_y) != -1){
                teclas_pulsadas[DCHA] = 0;
            }



        moverPersonaje(teclas_pulsadas);
    }


}

// Rutina de atencion a la interrupcion del teclado
void IntTec() {
    personaje_pos_y -= 30;
    MostrarRombo(1,(int) personaje_pos_x, (int) personaje_pos_y);
    g_personaje = true;
}



