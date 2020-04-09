/*-------------------------------------
 temporizadores.c
-------------------------------------*/
// Añadir los includes que sean necesarios
#include "defines.h"
#include "sprites.h"
#include <nds.h>
#include <stdio.h>


// Rutina de atención a la interrupción del temporizador
int dat = 0;

void IntTemp() {
    dat ++;
    iprintf("\x1b[15;1H %d",dat);


}





