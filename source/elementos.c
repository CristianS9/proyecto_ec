//
// Created by cristian on 18/4/20.
//

#include <nds.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// valores de los elementos : tipo,visible,colision,anchura,altura,pos_x,pos_y
// las posiciones: pos_x e pos_y son la localizacion del bit situado abojo a la izquierda del elemento



/*
 * 1 -- plataformas
 * 11 -- boton pausa
 * 12 -- boton reinicio
 * 13 -- boton nivel
 * 14 -- boton apagar
 *
 */

// suelo base 167

int elementos_array[9][7] = {
         {1,1,1,255,1,0,167} // Suelo
        ,{1,1,1,80,1,150,128} // primera plataforma desde abajo
        ,{1,1,1,75,1,15,112} // segunda plataforma desde abajo
        ,{1,1,1,75,1,145,70} // tercer plataforma desde abajo
        ,{1,1,1,100,1,80,25} // cuarta plataforma desde abajo

        ,{11,1,0,40,16,8,188} // Boton pausa
        ,{12,1,0,40,16,68,188} // Boton reinicio
        ,{13,1,0,40,16,134,188} // Boton nivel
        ,{14,1,0,40,16,207,188} // Boton apagar



};
int num_elementos = sizeof(elementos_array) / sizeof(elementos_array[0]);

int (*elementos)[7] = elementos_array;




int elemento_en_pos(int x, int y){
    if(x<1){
        x= 1;
    }

    int res = -1;
    for (int i = 0; i < num_elementos; ++i) {
        if(
                ( x >= elementos_array[i][5] && x <= (elementos_array[i][5] +  elementos_array[i][3]) )
                && ( y >= (elementos_array[i][6] - elementos_array[i][4])  && y <= elementos_array[i][6] )
        ){
            res = i;

        }
    }

    return res;
}
