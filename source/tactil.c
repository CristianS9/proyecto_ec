//
// Created by cristian on 26/4/20.
//

#include "../include/tactil.h"
#include <nds.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "rutserv.h"
#include "fondos.h"
#include "elementos.h"
#include "defines.h"


touchPosition pos;
int elemento;
void apagar();
void pausa();
void reiniciar();
void nivel();

void tactil(){
    touchRead(&pos);
    elemento = elementos[elemento_en_pos(pos.px,pos.py)][0];
    switch (elemento){
        case 11:
            pausa();
            break;
        case 12:
            reiniciar();
            break;
        case 13:

            break;
        case 14:
            apagar();
            break;

    }


}
 void pausa(){

    int elemento_pausa = -1;
    nether2();
     InhibirInterrupciones();
     pos.px= 0;
     pos.py = 0;

     while(elemento_pausa != 11){
        touchRead(&pos);
        elemento_pausa = elementos[elemento_en_pos(pos.px,pos.py)][0];

    }
     HabilitarInterrupciones();

}

void reiniciar(){
    vida = 100;
    puntuacion = 0;
    personaje_pos_x = 0;
    personaje_pos_y = 145;

}

void nivel(){

}

void apagar(){
    iprintf("\x1b[05;11H vida: apagado ");
}