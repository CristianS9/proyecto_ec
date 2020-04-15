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
#include "funciones/gravedad.h"

//-----------------------------------------------------
// Variables globales
//-----------------------------------------------------


int TactilTocada();//no esta en defines aun
//extern int segs;
void moverRombo();






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
	






	MostrarRombo(1,pos_x,pos_y);

    //fondo1();

	interrupciones();





	while(1){
	    movimientoPersonaje();
       // gravedad(teclas_pulsadas);
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

