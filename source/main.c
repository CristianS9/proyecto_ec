/*---------------------------------------------------------------------------------
Este código se ha implementado basándose en el ejemplo "Simple sprite demo" de 
dovoto y otro de Jaeden Amero
---------------------------------------------------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>       	// time 

#include "fondos.h"
#include "sprites.h"
#include "defines.h"
#include "rutserv.h"
#include "teclado.h"
#include "temporizadores.h"

//-----------------------------------------------------
// Variables globales
//-----------------------------------------------------


int TactilTocada();//no esta en defines aun
//extern int segs;
void moverRombo();


double pos_x = 8;
double pos_y = 110;
//double aceleracion = 0.0;
int ESTADO;
int seg=0;
int inversor=1;
int vida=100;
int puntuacion=0;

int main() {
	

	// Variables del main


	//  Poner en marcha el motor gráfico 2D.
    	powerOn(POWER_ALL_2D);

     	// Establecer la pantalla inferior como principal, inicializar el sistema gráfico
     	// y configurar el sistema de fondos.
    	lcdMainOnBottom();
    	initVideo();
    	initFondos();

    	// Mostrar fondos en pantalla. 
   // 	MostrarPuerta();

	// Inicializar memoria de sprites y guardar en ella los sprites 
	initSpriteMem();
	guardarSpritesEnMemoria();

	// Establecer las paletas para los sprites 
	establecerPaletaPrincipal();

	// Para poder imprimir en pantalla (hacer trazas) 
	consoleDemoInit();
	
 	// Para inicializar el generador de números aleatorios en función de una semilla,
	// en este caso time(NULL). 
	// srand() sólo se suele activar una vez por ejecución y no devuelve ningún valor 
	srand (time(NULL));
	
	ESTADO=NORMAL;
	
	iprintf("\x1b[01;17H vida: %d ",vida);
	iprintf("\x1b[01;00H puntuacion: %d ",puntuacion);
	iprintf("\x1b[02;00H   -------------------------");

    	void moverRombo(int * teclas_pulsadas){
        if(teclas_pulsadas[IZDA] == 1 && vida>0){
            pos_x -= 0.006;
        }
        if(teclas_pulsadas[DCHA] == 1 && vida>0){
            pos_x += 0.006;
        }

        if(teclas_pulsadas[ARRIBA] == 1 && vida>0){
            //aceleracion = 0;
            pos_y -= 0.03;
            MostrarRombo(1,(int) pos_x, (int) pos_y);
        }
        /*
        if(teclas_pulsadas[ABAJO] == 1){
            pos_y += 0.01;
        }
         



        /*switch (tecla){
            case IZDA:
                pos_x -= 0.01;
                break;
            case DCHA:
                pos_x += 0.01;
                break;
        }*/
        //MostrarRombo(1,(int) pos_x, (int) pos_y);
    	}


	MostrarRombo(1,pos_x,pos_y);

    //fondo1();

	interrupciones();




    void gravedad(int * teclas_pulsadas){
	int correc=0;
        if(pos_y<=150 && ESTADO!=SALTO){

            //aceleracion += 0.000003;
		
            pos_y += 0.007001/inversor;
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
        

	MostrarRombo(1,(int) pos_x, (int) pos_y);
    }
	while(1){
	    int * teclas_pulsadas = teclasPulsadas();
        gravedad(teclas_pulsadas);



          		moverRombo(teclas_pulsadas);
        	
	}
 }

/*
TactilTocada(){
	int r=0;
	touchPosition p_pan;
	touchRead(&p_pan);
	if(p_pan.px!=0 || p_pan.py!=0){
		r=1;	
	}
	return r;
}
 */

