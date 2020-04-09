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
#include "rutservs.h"
#include "teclado.h"
#include "temporizadores.h"
#include "tactil.h"

//-----------------------------------------------------
// Variables globales
//-----------------------------------------------------

int estado;

volatile int i_tecla = 0;

void tec() {
    i_tecla = TeclaPulsada();
    iprintf("\x1b[10;0H %d",i_tecla);

}

int main() {

	// Variables del main
	touchPosition pos_pantalla;

	//  Poner en marcha el motor gráfico 2D.
    	powerOn(POWER_ALL_2D);

     	// Establecer la pantalla inferior como principal, inicializar el sistema gráfico
     	// y configurar el sistema de fondos.
    	lcdMainOnBottom();
    	initVideo();
    	initFondos();

    	// Mostrar fondos en pantalla. 
    	MostrarPuerta();

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

    
    
// ...
	MostrarRombo(1,8,8);



    TECLAS_CNT =  0x4003;
    TIMER0_CNT = 0xC3;
    TIMER0_DAT = 32768;


    irqSet(IRQ_KEYS,IntTec);
    irqEnable(IRQ_KEYS);

    irqSet(IRQ_TIMER0,IntTemp);
    irqEnable(IRQ_TIMER0);



    while(1){




    }
} 


