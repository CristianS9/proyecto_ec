/*---------------------------------------------------------------------------------
Este código se ha implementado basándose en el ejemplo "Simple sprite demo" de 
dovoto y otro de Jaeden Amero
---------------------------------------------------------------------------------*/

#include <nds.h>			//librería desarrollada para la nds
#include <stdio.h>			//librería estandar de c que define las funciones estandar de entrada y salida
#include <stdlib.h>			//librería estandar de c para hacer reservas de memoria y conversión de números
#include <unistd.h>			//librería para asegurar la compatibilidad entre sistemas operativos
#include "sprites.h"
#include "defines.h"

u16* gfxRombo;

u16* gfxEnem;

u16* gfxOvida;

u16* gfxParachute;

double personaje_pos_x = 0.0;
double personaje_pos_y = 145.0;
double personaje_movimeinto_i = 0.035;
double personaje_movimeinto_d = 0.035;


/* Inicializar la memoria de Sprites. */
void initSpriteMem() {

	//int i;
	oamInit(&oamMain, SpriteMapping_1D_32, false);
	oamInit(&oamSub, SpriteMapping_1D_32, false);

	gfxRombo =    oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	
	gfxEnem = oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);

	gfxOvida = oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);

	gfxParachute = oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
}



/* Dentro de esta función hay que definir el color con el que se mostrará cada uno de los 256 
 * colores posibles en la pantalla principal. El 0 es transparente y los no definidos son negros.
 */
void establecerPaletaPrincipal() {
                                         // 0: TRANSPARENTE
   SPRITE_PALETTE[1]  = RGB15(31,0,0);   // ROJO:           RGB24={FF,00,00} los pixels con valor 1 aparecen en rojo
   SPRITE_PALETTE[2]  = RGB15(31,31,0);  // AMARILLO:       RGB24={FF,FF,00}
   SPRITE_PALETTE[3]  = RGB15(31,31,31); // BLANCO:         RGB24={FF,FF,FF}
   SPRITE_PALETTE[4]  = RGB15(0,31,0);   // VERDE:          RGB24={00,FF,00}
   SPRITE_PALETTE[5]  = RGB15(0,0,31);   // AZUL:           RGB24={00,00,FF}
   SPRITE_PALETTE[6]  = RGB15(0,0,0);    // NEGRO:          RGB24={00,00,00}
   SPRITE_PALETTE[7]  = RGB15(0,31,31);  // CYAN:           RGB24={00,FF,FF}
   SPRITE_PALETTE[8]  = RGB15(31,0,31);  // MAGENTA:        RGB24={FF,00,FF}
   SPRITE_PALETTE[9]  = RGB15(16,16,16); // GRIS:           RGB24={80,80,80}
   SPRITE_PALETTE[10] = RGB15(25,25,25); // GRIS CLARO:     RGB24={D0,D0,D0}
   SPRITE_PALETTE[11] = RGB15(8,8,8);    // GRIS OSCURO:    RGB24={40,40,40}
   SPRITE_PALETTE[12] = RGB15(31,19,0);  // NARANJA:        RGB24={FF,99,00}
   SPRITE_PALETTE[13] = RGB15(19,0,4);   // GRANATE:        RGB24={99,00,21}
   SPRITE_PALETTE[14] = RGB15(25,0,0);   // MARRON:         RGB24={66,00,00}
   SPRITE_PALETTE[15] = RGB15(16,0,16);  // MORADO:         RGB24={80,00,80}
   SPRITE_PALETTE[16] = RGB15(25,19,31); // LILA:           RGB24={CC,99,FF}
   SPRITE_PALETTE[17] = RGB15(31,19,25); // ROSA:           RGB24={FF,99,CC}
   SPRITE_PALETTE[18] = RGB15(23,21,21); // AZUL CLARO:     RGB24={BB,FF,FF}
   SPRITE_PALETTE[19] = RGB15(0,0,16);   // AZUL MARINO:    RGB24={00,00,80}
   SPRITE_PALETTE[20] = RGB15(0,16,16);  // VERDE AZULADO:  RGB24={00,80,80}
   SPRITE_PALETTE[21] = RGB15(0,12,0);   // VERDE OSCURO:   RGB24={00,66,00}
   SPRITE_PALETTE[22] = RGB15(16,16,0);  // VERDE OLIVA:    RGB24={80,80,00}
   SPRITE_PALETTE[23] = RGB15(19,31,19); // VERDE CLARO:    RGB24={99,FF,99}
   SPRITE_PALETTE[24] = RGB15(31,31,19); // AMARILLO CLARO: RGB24={FF,FF,99}

   SPRITE_PALETTE[25] = RGB15(2,11,4); // Slime verde oscuro
   SPRITE_PALETTE[26] = RGB15(6,21,5); // Slime verde medio oscuro
   SPRITE_PALETTE[27] = RGB15(16,26,10); // Slime verde base
   SPRITE_PALETTE[28] = RGB15(23,29,17); // Slime verde claro
   
   SPRITE_PALETTE[29] = RGB15(10,0,0); //Slime rojo oscuro
   SPRITE_PALETTE[30] = RGB15(24,3,3); //Slime rojo medio oscuro
   SPRITE_PALETTE[31] = RGB15(30,1,1); //Slime rojo base
   SPRITE_PALETTE[32] = RGB15(30,10,10); //Slime rojo claro

}


/* Dibujado de un Sprite de 16x16 pixels */

/* Debido al funcionamiento de los bancos de memoria, las primeras cuatro filas 
 * forman el cuadrante superior izquiero, las siguientes, el cuadrante superior 
 * derecho, las siguientes el cuadrante inferior izquierdo y las últimas cuatro
 * filas, el cuadrante inferior derecho, como se muestra al lado.
 */


u8 Rombo[256] = 
{

		0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,25,25,0, 0, 0, 0,25,26,27,27,

        0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0,
        25,25, 0, 0, 0, 0, 0, 0,27,27,26,25, 0, 0, 0, 0,

        0, 0, 0,25,27,28,28,28,0, 0,25,27,28,28,28,28,
        0, 0,26,27,27,27,28,28,0,25,27,27,27,27,27,27,
        0,25,27,27,27,27,27,27,0,25,26,27,27,27,27,27,
        0,25,25,26,26,27,27,27,0, 0,25,25,25,25,25,25,

        28,28,28,27,25, 0, 0, 0,28,25,28,25,27,25, 0, 0,
        28,26,28,26,27,26, 0, 0,27,26,27,26,27,27,25, 0,
        27,27,27,27,27,27,25, 0,27,27,27,27,27,26,25, 0,
        27,27,27,27,26,25,25, 0,25,25,25,25,25,25, 0, 0,


};
u8 Parachute[256] = 
{

	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 19, 19, 29, 29, 29, 0, 0, 19, 19, 19, 29, 29, 29, 
0, 0, 19, 19, 0, 0, 0, 0, 0, 19, 19, 0, 6, 0, 0, 0, 
0, 19, 0, 0, 0, 6, 25, 25, 0, 0, 0, 0, 25, 27, 28, 28, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
29, 29, 29, 19, 19, 0, 0, 0, 29, 29, 29, 19, 19, 19, 0, 0, 
0, 0, 0, 0, 19, 19, 0, 0, 0, 0, 0, 6, 0, 19, 19, 0, 
25, 25, 6, 0, 0, 0, 19, 0, 28, 28, 27, 27, 0, 0, 0, 0, 
0, 0, 0, 6, 28, 28, 28, 28, 0, 0, 25, 28, 6, 28, 28, 28, 
0, 0, 27, 28, 6, 28, 28, 28, 0, 25, 28, 28, 6, 28, 28, 28, 
0, 25, 28, 28, 6, 28, 28, 28, 0, 25, 27, 28, 6, 28, 28, 28, 
0, 25, 6, 6, 27, 28, 28, 28, 0, 0, 25, 25, 25, 25, 25, 25, 
28, 28, 28, 28, 26, 0, 0, 0, 28, 25, 28, 25, 28, 6, 0, 0, 
28, 27, 28, 27, 28, 6, 0, 0, 28, 27, 28, 27, 6, 28, 25, 0, 
28, 28, 28, 28, 6, 28, 25, 0, 28, 28, 28, 28, 28, 6, 25, 0, 
28, 28, 28, 28, 27, 6, 25, 0, 25, 25, 25, 25, 25, 25, 0, 0, 


};
u8 Ovida[256] = 
{

0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 25, 25, 0, 0, 0, 0, 0, 25, 27, 27, 
0, 0, 0, 0, 25, 27, 27, 27, 0, 0, 0, 0, 25, 27, 27, 27, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
25, 25, 0, 0, 0, 0, 0, 0, 27, 27, 25, 0, 0, 0, 0, 0, 
28, 27, 27, 25, 0, 0, 0, 0, 27, 28, 27, 25, 0, 0, 0, 0, 
0, 0, 0, 0, 25, 27, 27, 27, 0, 0, 0, 0, 25, 27, 27, 27, 
0, 0, 0, 0, 0, 25, 27, 27, 0, 0, 0, 0, 0, 0, 25, 25, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
27, 27, 27, 25, 0, 0, 0, 0, 27, 27, 27, 25, 0, 0, 0, 0, 
27, 27, 25, 0, 0, 0, 0, 0, 25, 25, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 


};
u8 Enem[256] = 
{


        0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,29,29,0, 0, 0, 0,29,30,31,31,

        0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0,
        29,29, 0, 0, 0, 0, 0, 0,31,31,30,29, 0, 0, 0, 0,

        0, 0, 0,29,31,32,32,32,0, 0,29,31,32,32,32,32,
        0, 0,30,31,31,31,32,32,0,29,31,31,31,31,31,31,
        0,29,31,31,31,31,31,31,0,29,30,31,31,31,31,31,
        0,29,29,30,30,31,31,31,0, 0,29,29,29,29,29,29,

        32,32,32,31,29, 0, 0, 0,32,29,32,29,31,29, 0, 0,
        28,30,32,30,31,30, 0, 0,31,30,31,30,31,31,29, 0,
        31,31,31,31,31,31,29, 0,31,31,31,31,31,30,29, 0,
        31,31,31,31,30,29,29, 0,29,29,29,29,29,29, 0, 0,


};

/* Dibujado de un Sprite de 32x32 pixels */



/* Para cada Sprite que se quiera llevar a pantalla hay que hacer una de estas funciones. */

void BorrarRombo(int indice, int x, int y) {
oamSet(&oamMain, //main graphics engine context
	indice,  //oam index (0 to 127)  
	x, y,    //x and y pixle location of the sprite
	0,       //priority, lower renders last (on top)
	0,       //this is the palette index if multiple palettes or the alpha value if bmp sprite	
	SpriteSize_16x16,     
	SpriteColorFormat_256Color, 
	gfxRombo,//+16*16/2, 	//pointer to the loaded graphics
	-1,                  	//sprite rotation data  
	false,               	//double the size when rotating?
	true,			//hide the sprite?
	false, false, 		//vflip, hflip
	false			//apply mosaic
	); 
oamUpdate(&oamMain); 
}
void BorrarEnemigo(int indice, int x, int y) {
oamSet(&oamMain, //main graphics engine context
	indice,  //oam index (0 to 127)  
	x, y,    //x and y pixle location of the sprite
	0,       //priority, lower renders last (on top)
	0,       //this is the palette index if multiple palettes or the alpha value if bmp sprite	
	SpriteSize_16x16,     
	SpriteColorFormat_256Color, 
	gfxEnem,//+16*16/2, 	//pointer to the loaded graphics
	-1,                  	//sprite rotation data  
	false,               	//double the size when rotating?
	true,			//hide the sprite?
	false, false, 		//vflip, hflip
	false			//apply mosaic
	); 
oamUpdate(&oamMain); 
}

void BorrarVida(int indice, int x, int y) {
oamSet(&oamMain, //main graphics engine context
	indice,  //oam index (0 to 127)  
	x, y,    //x and y pixle location of the sprite
	0,       //priority, lower renders last (on top)
	0,       //this is the palette index if multiple palettes or the alpha value if bmp sprite	
	SpriteSize_16x16,     
	SpriteColorFormat_256Color, 
	gfxOvida,//+16*16/2, 	//pointer to the loaded graphics
	-1,                  	//sprite rotation data  
	false,               	//double the size when rotating?
	true,			//hide the sprite?
	false, false, 		//vflip, hflip
	false			//apply mosaic
	); 
oamUpdate(&oamMain); 
}
void BorrarParachute(int indice, int x, int y) {
oamSet(&oamMain, //main graphics engine context
	indice,  //oam index (0 to 127)  
	x, y,    //x and y pixle location of the sprite
	0,       //priority, lower renders last (on top)
	0,       //this is the palette index if multiple palettes or the alpha value if bmp sprite	
	SpriteSize_16x16,     
	SpriteColorFormat_256Color, 
	gfxParachute,//+16*16/2, 	//pointer to the loaded graphics
	-1,                  	//sprite rotation data  
	false,               	//double the size when rotating?
	true,			//hide the sprite?
	false, false, 		//vflip, hflip
	false			//apply mosaic
	); 
oamUpdate(&oamMain); 
}

void MostrarRombo (int indice, int x, int y){ 
oamSet(&oamMain, //main graphics engine context
	indice,  //oam index (0 to 127)  
	x, y,    //x and y pixle location of the sprite
	0,       //priority, lower renders last (on top)
	0,       //this is the palette index if multiple palettes or the alpha value if bmp sprite	
	SpriteSize_16x16,     
	SpriteColorFormat_256Color, 
	gfxRombo,//+16*16/2, 	//pointer to the loaded graphics
	-1,                  	//sprite rotation data  
	false,               	//double the size when rotating?
	false,			//hide the sprite?
	false, false, 		//vflip, hflip
	false			//apply mosaic
	); 
oamUpdate(&oamMain);  
}
void MostrarEnemigo (int indice, int x, int y){ 
oamSet(&oamMain, //main graphics engine context
	indice,  //oam index (0 to 127)  
	x, y,    //x and y pixle location of the sprite
	0,       //priority, lower renders last (on top)
	0,       //this is the palette index if multiple palettes or the alpha value if bmp sprite	
	SpriteSize_16x16,     
	SpriteColorFormat_256Color, 
	gfxEnem,//+16*16/2, 	//pointer to the loaded graphics
	-1,                  	//sprite rotation data  
	false,               	//double the size when rotating?
	false,			//hide the sprite?
	false, false, 		//vflip, hflip
	false			//apply mosaic
	); 
oamUpdate(&oamMain);  
}
void MostrarVida (int indice, int x, int y){ 
oamSet(&oamMain, //main graphics engine context
	indice,  //oam index (0 to 127)  
	x, y,    //x and y pixle location of the sprite
	0,       //priority, lower renders last (on top)
	0,       //this is the palette index if multiple palettes or the alpha value if bmp sprite	
	SpriteSize_16x16,     
	SpriteColorFormat_256Color, 
	gfxOvida,//+16*16/2, 	//pointer to the loaded graphics
	-1,                  	//sprite rotation data  
	false,               	//double the size when rotating?
	false,			//hide the sprite?
	false, false, 		//vflip, hflip
	false			//apply mosaic
	); 
oamUpdate(&oamMain);  
}
void MostrarParachute (int indice, int x, int y){ 
oamSet(&oamMain, //main graphics engine context
	indice,  //oam index (0 to 127)  
	x, y,    //x and y pixle location of the sprite
	0,       //priority, lower renders last (on top)
	0,       //this is the palette index if multiple palettes or the alpha value if bmp sprite	
	SpriteSize_16x16,     
	SpriteColorFormat_256Color, 
	gfxParachute,//+16*16/2, 	//pointer to the loaded graphics
	-1,                  	//sprite rotation data  
	false,               	//double the size when rotating?
	false,			//hide the sprite?
	false, false, 		//vflip, hflip
	false			//apply mosaic
	); 
oamUpdate(&oamMain);  
}



void guardarSpritesEnMemoria(){ 
	
int i;
	//para sprites de 16*16
	for(i = 0; i < 16 * 16 / 2; i++) 
	{	
		gfxRombo[i] = Rombo[i*2] | (Rombo[(i*2)+1]<<8);	
		gfxEnem[i] = Enem[i*2] | (Enem[(i*2)+1]<<8);
		gfxOvida[i] = Ovida[i*2] | (Ovida[(i*2)+1]<<8);
		gfxParachute[i] = Parachute[i*2] | (Parachute[(i*2)+1]<<8);	
			
	}
	
	
}



void moverPersonaje(int * teclas_pulsadas){
    static double bitch;
    if(Ecolision==NORMAL){
    	if(teclas_pulsadas[IZDA] == 1){
        	double nueva_pos = personaje_pos_x - personaje_movimeinto_i;
        	if(nueva_pos <= -18.00){
        		nueva_pos = 239.00;
        	}
        	personaje_pos_x = nueva_pos;
    	}
   	if(teclas_pulsadas[DCHA] == 1){
   	     	double nueva_pos = personaje_pos_x + personaje_movimeinto_d;
   	     	if (nueva_pos >= 247.00) {
             		nueva_pos = 0.00;
    		}
        	personaje_pos_x = nueva_pos;
    	}
    }else if(Ecolision==G_IZDA){
	double nueva_pos=personaje_pos_x - 0.05;
	bitch +=0.03;
	if(bitch>=70){
		bitch=0;
		Ecolision=NORMAL;
	}
	if(nueva_pos <= -18.00){
        	nueva_pos = 239.00;
        }
	personaje_pos_x = nueva_pos;
    }else if(Ecolision==G_DCHA){
	double nueva_pos = personaje_pos_x + 0.05;
	bitch +=0.03;
	if(bitch>=70){
		bitch=0;
		Ecolision=NORMAL;
	}
   	if (nueva_pos >= 250.00) {
        	nueva_pos = 0.00;
    	}
        personaje_pos_x = nueva_pos;
    }
//MostrarRombo(1,(int) personaje_pos_x, (int) personaje_pos_y);
}



