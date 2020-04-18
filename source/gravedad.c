//
// Created by cristian on 15/4/20.
//

#include "gravedad.h"
#include "elementos.h"
#include "sprites.h"

void gravedadPersonaje();

double aceleracion = 0.0;
bool g_personaje = true;


void gravedad(){
    gravedadPersonaje();


}
int elemento,nueva_posicion;

void gravedadPersonaje(){
    if(g_personaje && ESTADO!=SALTO){
        nueva_posicion = personaje_pos_y + 16 + 0.007001/inversor;
    } else if( ESTADO == SALTO){
        if(seg<=15){
            nueva_posicion = personaje_pos_y - 0.007001;

        }else{
            nueva_posicion  = personaje_pos_y + 0.007001/inversor;

        }
        /*
        else if(correc<5){
            correc++;
            inversor=1;
        }

         else{
            seg=0;
            //correc=0;
            ESTADO=NORMAL;
        }
         */
    }
    /*
    else if(pos_y>150){//correción de posición
        nueva_posicion = personaje_pos_y + 0.000001;
        inversor=1;
    }
     */


    elemento = elemento_en_pos((int)(personaje_pos_x),(int)(nueva_posicion));
    if(elemento == -1){
        elemento = elemento_en_pos((int)(personaje_pos_x + 16),(int)(nueva_posicion));
    }


    if( elemento! = -1){
        seg=0;
        ESTADO=NORMAL;
        inversor=1;
        g_personaje = false;

    } else {
        personaje_pos_y += nueva_posicion;
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