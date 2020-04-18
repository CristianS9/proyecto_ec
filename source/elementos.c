//
// Created by cristian on 18/4/20.
//

#include <nds.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// valores de los elementos : tipo,visible,colision,anchura,altura,pos_x,pos_y
// las posiciones: pos_x e pos_y son la localizacion del bit situado abojo a la izquierda del elemento

int elementos_array[1][7] = {{1,1,1,77,36,145,156}};
int num_elementos = sizeof(elementos_array);

int (*elementos)[7] = elementos_array;





int elemento_en_pos(int x, int y){

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
