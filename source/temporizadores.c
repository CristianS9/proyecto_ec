/*-------------------------------------
 temporizadores.c
-------------------------------------*/
// Añadir los includes que sean necesarios
#include "defines.h"
#include "sprites.h"
#include <nds.h>
#include <stdio.h>
#include "fondos.h"
#include "teclado.h"



// Rutina de atención a la interrupción del temporizador
void IntTemp() {
	static int tic=0;
	if(tic==20){
      		over1();
  	} else if(tic == 40){
		over2();
	} else if(tic ==60){
       		over3();
       		tic = 0;
	}
	if(ESTADO==SALTO){
		seg++;

	}

	tic++;
}





