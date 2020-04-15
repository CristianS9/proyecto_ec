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
	if(TeclaPulsada()==A){
		if(tic==20){
      			over1();
  		} else if(tic == 40){
			over2();
    		} else if(tic ==60){
        		over3();
        		tic = 0;
    		}
	}else if(TeclaPulsada()==B){
		if(tic==20){
      			over1Muerte();
  		} else if(tic == 40){
			over2Muerte();
    		} else if(tic ==60){
        		over3Muerte();
        		tic = 0;
    		}
	}else if(TeclaPulsada()==SELECT){
		if(tic==20){
      			cielo1();
  		} else if(tic == 40){
			cielo2();
    		} else if(tic ==60){
        		cielo3();
        		tic = 0;
    		}
	}else if(TeclaPulsada()==START){
		if(tic==20){
      			cielo1Muerte();
  		} else if(tic == 40){
			cielo2Muerte();
    		} else if(tic ==60){
        		cielo3Muerte();
        		tic = 0;
    		}
	}else if(TeclaPulsada()==ARRIBA){
		if(tic==20){
      			nether1();
  		} else if(tic == 40){
			nether2();
    		} else if(tic ==60){
        		nether3();
        		tic = 0;
    		}
	}else{
		if(tic==20){
      			nether1Muerte();
  		} else if(tic == 40){
			nether2Muerte();
    		} else if(tic ==60){
        		nether3Muerte();
        		tic = 0;
    		}
	}

	tic++;
}





