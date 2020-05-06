/*-------------------------------------
 enemigos.c
-------------------------------------*/

// Añadir los includes que sean necesarios
#include <nds.h>
#include <stdio.h>
#include "defines.h"
#include "sprites.h"
#include "fondos.h"
#include "elementos.h"
#include "gravedad.h"

//int hbox=16;
int numVida=6;
//[0]x,[1]y,[2]visible
int vList[6][3]={
		{180,6,0},
		{163,110,0},
		{32,94,0},
		{160,52,0},
		{80,6,0},
		{90,90,0,}
};



void updateObjects(){
	if(rein2==1){
		vList[0][2]=0;
		vList[1][2]=0;
		vList[2][2]=0;
		vList[3][2]=0;
		vList[4][2]=0;
		vList[5][2]=0;
		rein2=0;
	}
	int i;
	for(i=0;i<numVida;i++){
		if((vList[i][0]-16)<=personaje_pos_x 
		   && personaje_pos_x<=(vList[i][0]+16)
		   && personaje_pos_y<=(vList[i][1]+16)
		   && personaje_pos_y>=(vList[i][1]-16)
		   && vList[i][2]==1){
			//sumaV=1;
			if(vida>=75){
				vida=100;
			}else{
				vida +=25;
			}
			vList[i][2]=0;
		}
		if(vList[i][2]==1 && vida>0){
			MostrarVida(i+7,vList[i][0],vList[i][1]);
		}else if(vList[i][2]==0 || vida<=0){
			BorrarVida(i+7,vList[i][0],vList[i][1]);
		}	
	}
	if(vidasManager==180){
		vList[ViVi][2]=1;
		vList[ViAnt][2]=0;
	}
	
}
	

	
