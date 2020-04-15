//
// Created by cristian on 15/4/20.
//

#include "../../include/funciones/gravedad.h"

double aceleracion = 0.0;
bool gravedad_personaje = false;

void gravedad(){

    gravedad_personaje();


}

void gravedad_personaje(){
    if(gravedad_personaje){

        if(pos_y<=150){
            aceleracion += 0.000003;
            pos_y += aceleracion;

            MostrarRombo(1,(int) pos_x, (int) pos_y);
        }
        if(pos_y >= 150){
            aceleracion = 0.0;
        }
    }
}