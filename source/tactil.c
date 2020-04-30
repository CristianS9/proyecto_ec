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
    elemento = elementos[elemento_en_pos(pos.px,pos.py,11,14)][0];
    switch (elemento){
        case 11:
            pausa();
            break;
        case 12:
            reiniciar();
            break;
        case 13:
	    nivel();
            break;
        case 14:
            apagar();
            break;

    }


}
 void pausa(){

    int elemento_pausa = -1;
     panPausa();
     InhibirInterrupciones();
     pos.px= 0;
     pos.py = 0;
     BorrarRombo(1,personaje_pos_x,personaje_pos_y);

     while(elemento_pausa != 15){
        touchRead(&pos);
        elemento_pausa = elementos[elemento_en_pos(pos.px,pos.py,15,15)][0];
	
    }
     MostrarRombo(1,personaje_pos_x,personaje_pos_y);
     HabilitarInterrupciones();

}
void apagar(){
	off();
	iprintf("\x1b[01;00H                            ");
	iprintf("\x1b[02;00H                            ");
	apag=1;
}

void reiniciar(){
    vida = 100;
    puntuacion = 0;
    personaje_pos_x = 0;
    personaje_pos_y = 145;

}

void nivel(){
	iprintf("\x1b[10;00H   No hay mas niveles aun");
}

