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
int numEnem=5;
//[0]x,[1]y,[2]gira,[3]visible,[4]anch,[5]alt,[6]dcha,[7]izda
int eList[5][8]={
		{239,150,1,1,16,10,239,0},
		{150,110,0,1,16,10,214,150},
		{15,94,0,1,16,10,74,15},
		{140,52,0,0,16,10,214,140},
		{80,6,0,0,16,10,170,70}
};



void enemMov(){
	int i;
	for(i=0;i<numEnem;i++){
		//izda o dcha
		if(eList[i][3]==1){
			if(eList[i][2]==0){
				eList[i][0]=eList[i][0]+1;
			}else{
				eList[i][0]=eList[i][0]-1;
			}
		}
		//giro check
		if(eList[i][0]<=eList[i][7]){
			eList[i][2]=0;
		}else if(eList[i][0]>=eList[i][6]){
			eList[i][2]=1;
		}
		if(vida>0 && eList[i][3]==1){	
			MostrarEnemigo(i+2,eList[i][0],eList[i][1]);
		}else if(eList[i][3]==0 || vida<=0){
			BorrarEnemigo(i+2,eList[i][0],eList[i][1]);
		}
	}

}

void updateLife(){
	if(rein==1){
		eList[0][3]=1;
		eList[1][3]=1;
		eList[2][3]=1;
		eList[3][3]=0;
		eList[4][3]=0;
		eList[0][0]=239;
		eList[1][0]=150;
		eList[2][0]=15;
		rein=0;
	}
	int i;
	for(i=0;i<numEnem;i++){
		if((eList[i][0]-16)<=personaje_pos_x 
		   && personaje_pos_x<=(eList[i][0]+16)
		   && personaje_pos_y<=(eList[i][1]+16)
		   && personaje_pos_y>=(eList[i][1]-16)
		   && eList[i][3]==1){
			if((aceleracion!=0 || paracaidas) && killer==1){
				paracaidas=false;
				enemCounter=1;
				eList[i][3]=0;
				puntuacion +=20;
			}else if(ESTADO==SALTO){
				ESTADO=NORMAL;
				killer=0;
				tempK=1;
				restavida=1;
			}else if((eList[i][0]+8)>=personaje_pos_x){
				Ecolision=G_IZDA;
				restavida=1;
				dif=personaje_pos_x;	
			}else if((eList[i][0]+8)<=personaje_pos_x){
				Ecolision=G_DCHA;
				restavida=1;
				dif=personaje_pos_x;
			}
		}
		
	}
	if(spawn==5){spawn=0;}
	if(enemCounter==31){
		if(eList[spawn][3]==1){
			enemCounter=1;
		}else{
			eList[spawn][3]=1;
			enemCounter=0;
		}
	}
}
	

	
