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
    if(true){
        if(personaje_pos_y<=150){
            aceleracion += 0.000003;
            nueva_posicion = personaje_pos_y + 16 + aceleracion;
            elemento = elemento_en_pos((int)(personaje_pos_x),(int)(nueva_posicion));
            if(elemento == -1){
                elemento = elemento_en_pos((int)(personaje_pos_x + 16),(int)(nueva_posicion));
            }
            if( elemento!= -1){
                aceleracion = 0.0;
                g_personaje = false;
            } else {
                personaje_pos_y += aceleracion;
            }

            MostrarRombo(1,(int) personaje_pos_x, (int) personaje_pos_y);
        }
        if(personaje_pos_y >= 150){
            aceleracion = 0.0;
            g_personaje = false;
        }
    }
}