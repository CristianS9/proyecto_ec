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
#include "gravedad.h"
#include "elementos.h"



//-----------------------------------------------------
// Variables globales
//-----------------------------------------------------

int antp;
int TactilTocada();//no esta en defines aun
//extern int segs;
void moverRombo();
void tactil();


//double aceleracion = 0.0;


int vida=100;
int puntuacion=0;
int apag=0;


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

	iprintf("\x1b[01;17H vida: %d ",vida);
	iprintf("\x1b[01;00H puntuacion: %d ",puntuacion);
	iprintf("\x1b[02;00H   -------------------------");
	iprintf("\x1b[03;00H   -------------------------");
	iprintf("\x1b[04;00H   ------PROYECTO EC--------");
	iprintf("\x1b[05;00H   IKER P, JON M, CRISTIAN S");
	iprintf("\x1b[06;00H   -------------------------");
	iprintf("\x1b[07;00H   -----SLIME HERO GAME-----");
	iprintf("\x1b[08;00H   -------------------------");





	MostrarRombo(1,personaje_pos_x,personaje_pos_y);



	interrupciones();



	while(apag==0){
		if(vida>0){
		    	movimientoPersonaje();
	  	      	gravedad();
		}else{
			BorrarRombo(1,(int)personaje_pos_x,(int)personaje_pos_y);
		}
		tactil();
        	//MostrarRombo(1,(int) personaje_pos_x, (int) personaje_pos_y);

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

