//
// Created by cristian on 26/3/20.
//

#include <nds.h>

#include "../include/tactil.h"

bool tactilPulsado(){
    bool res = false;

    // Estructura para intercutuar con la pantalla tactil
    touchPosition pos_pantalla;

    // Funcion para leer la pantalla tactil
    touchRead(&pos_pantalla);
    if(pos_pantalla.px!=0 || pos_pantalla.py!=0){
        pos_pantalla.px = 0;
        pos_pantalla.py = 0;
        res = true;
    }

    return res;
}

bool esperarTactilPulsado(){

    touchPosition pos_pantalla;

    touchRead(&pos_pantalla);

    while(pos_pantalla.px==0 && pos_pantalla.py==0){
        touchRead(&pos_pantalla);
    }

    pos_pantalla.px = 0;
    pos_pantalla.py = 0;

    return  true;
}