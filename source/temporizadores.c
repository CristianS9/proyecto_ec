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
#include "tactil.h"
#include "enemigos.h"


void barraVida();

// Rutina de atención a la interrupción del temporizador
void IntTemp() {
	static int tic=0;
	vidasManager++;
	if(vidasManager==181){
		if(ViVi==5){
			ViVi=0;
		}else{
			ViVi++;
		}
		if(ViAnt==5){
			ViAnt=0;
		}else{
			ViAnt++;
		}
		vidasManager=0;
	}
	if(enemCounter>0){
		enemCounter++;
		if(enemCounter==30){
			spawn++;
		}
	}
	if(restavida>0){
		restavida++;
		if(restavida==3){
			vida -=25;
			restavida=0;
		}
	}
	/*if(sumaV>0){
		sumaV++;
		if(sumaV==3){
			vida +=25;
			sumaV=0;
		}
	}*/
	if(tempK>0){
		tempK++;
		if(tempK==5){
			tempK=0;
			killer=1;
		}
	}
	enemMov();
	if(tic==20){
		if(vida>0){
      			over1();
		}else{
			over1Muerte();
		}
  	} else if(tic == 40){
		if(vida>0){
      			over2();
		}else{
			over2Muerte();
		}
	} else if(tic ==60){
		if(vida>0){
      			over3();
		}else{
			over3Muerte();
		}
		barraVida();
		if(vida>0){
		iprintf("\x1b[01;17H vida: %d ",vida);
			vida--;
		}else{
		iprintf("\x1b[01;17H vida: 0   ");
		}
		iprintf("\x1b[01;00H puntuacion: %d ",puntuacion);
		if(vida>0){
			puntuacion += 10;
		}
       		tic = 0;
	}
	/*if(ESTADO==SALTO){
		seg++;

	}*/

	tic++;
}

void barraVida(){
	if(vida>=96){
		iprintf("\x1b[02;00H   -------------------------");
	}else if(vida>=92 && vida<96){
		iprintf("\x1b[02;00H   ------------------------ ");
	}else if(vida>=88 && vida<92){
		iprintf("\x1b[02;00H   -----------------------  ");
	}else if(vida>=84 && vida<88){
		iprintf("\x1b[02;00H   ----------------------   ");
	}else if(vida>=80 && vida<84){
		iprintf("\x1b[02;00H   ---------------------    ");
	}else if(vida>=76 && vida<80){
		iprintf("\x1b[02;00H   --------------------     ");
	}else if(vida>=72 && vida<76){
		iprintf("\x1b[02;00H   -------------------      ");
	}else if(vida>=68 && vida<72){
		iprintf("\x1b[02;00H   ------------------       ");
	}else if(vida>=64 && vida<68){
		iprintf("\x1b[02;00H   -----------------        ");
	}else if(vida>=60 && vida<64){
		iprintf("\x1b[02;00H   ----------------         ");
	}else if(vida>=56 && vida<60){
		iprintf("\x1b[02;00H   ---------------          ");
	}else if(vida>=52 && vida<56){
		iprintf("\x1b[02;00H   --------------           ");
	}else if(vida>=48 && vida<52){
		iprintf("\x1b[02;00H   -------------            ");
	}else if(vida>=44 && vida<48){
		iprintf("\x1b[02;00H   ------------             ");
	}else if(vida>=40 && vida<44){
		iprintf("\x1b[02;00H   -----------              ");
	}else if(vida>=36 && vida<40){
		iprintf("\x1b[02;00H   ----------               ");
	}else if(vida>=32 && vida<36){
		iprintf("\x1b[02;00H   ---------                ");
	}else if(vida>=28 && vida<32){
		iprintf("\x1b[02;00H   --------                 ");
	}else if(vida>=24 && vida<28){
		iprintf("\x1b[02;00H   -------                  ");
	}else if(vida>=20 && vida<24){
		iprintf("\x1b[02;00H   ------                   ");
	}else if(vida>=16 && vida<20){
		iprintf("\x1b[02;00H   -----                    ");
	}else if(vida>=12 && vida<16){
		iprintf("\x1b[02;00H   ----                     ");
	}else if(vida>=8 && vida<12){
		iprintf("\x1b[02;00H   ---                      ");
	}else if(vida>=4 && vida<8){
		iprintf("\x1b[02;00H   --                       ");
	}else if(vida>0 && vida<4){
		iprintf("\x1b[02;00H   -                        ");
	}else{
		iprintf("\x1b[02;00H                            ");
	}
}




