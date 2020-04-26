//
// Created by cristian on 15/4/20.
//

#include "gravedad.h"
#include "elementos.h"
#include "sprites.h"
#include "defines.h"

void gravedadPersonaje();

double aceleracion = 0.0;
bool g_personaje = false;
int ESTADO = NORMAL;
int elemento;
double nueva_posicion;
int seg = 0;

void gravedad(){
    gravedadPersonaje();
}


void gravedadPersonaje(){

    nueva_posicion = personaje_pos_y;

    if(g_personaje && personaje_pos_y <= 150 && ESTADO == NORMAL){
        nueva_posicion += 0.007001/inversor;

    } else if(ESTADO == SALTO){
        if(seg<=30){
            nueva_posicion -= 0.007001;
            personaje_pos_y = nueva_posicion;
        }else{
            seg = 0;
            ESTADO = NORMAL;
        }

    }

    elemento = elemento_en_pos((int)(personaje_pos_x),(int)(nueva_posicion + 16));
    if(elemento == -1){
        elemento = elemento_en_pos((int)(personaje_pos_x + 16),(int)(nueva_posicion + 16));
    }

    if(ESTADO == NORMAL){
        if( elemento != -1){
            inversor=1;
            g_personaje = false;
        } else {
            if(!g_personaje && personaje_pos_y <= 150){
                g_personaje = true;
            }
            personaje_pos_y = nueva_posicion;

        }
    }

    MostrarRombo(1,(int) personaje_pos_x, (int) personaje_pos_y);

}




/*
void gravedad(){
    int correc=0;
    if(pos_y<=150 && ){


    }
    else if( ESTADO==SALTO){
        if(seg<=15){
            pos_y -=0.007;
        }
        else if( pos_y<=150){
            pos_y += 0.007001/inversor;


        }else if(correc<5){
            correc++;
            ESTADO=NORMAL;
            seg=0;
            inversor=1;
        }else{
            correc=0;
        }
    }else if(pos_y>150){//correción de posición
        pos_y -=0.000001;
        inversor=1;
    }

    MostrarRombo(1,(int) personaje_pos_x, (int) personaje_pos_y);
}
 */