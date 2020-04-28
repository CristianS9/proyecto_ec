/*---------------------------------------------------------------------------------
Este código se ha implementado basándose en el ejemplo "Simple sprite demo" de 
dovoto y otro de Jaeden Amero
---------------------------------------------------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "fondos.h"

/* añadir aquí los includes para cada fondo. */

#include "fondos.h"
#include "fondo1.h"
#include "fondo2.h"
#include "fondo3.h"
#include "fondoMuerte.h"
#include "fondo2Muerte.h"
#include "fondo3Muerte.h"
#include "Cielo.h"
#include "Cielo2.h"
#include "Cielo3.h"
#include "Cielomuerte.h"
#include "Cielo2muerte.h"
#include "cielo3muerte.h"
#include "nether.h"
#include "nether2.h"
#include "nether3.h"
#include "nethermuerte.h"
#include "nether2muerte.h"
#include "nether3muerte.h"
#include "off.h"
#include "panPausa.h"



/* Seleccionar un canal DMA para copiar a memoria las imágenes */
static const int DMA_CHANNEL = 3;

/* Procedimiento para configurar el sistema de fondos. */
void initFondos() {
    /*  Establecer la afinidad del fondo 3 de la pantalla principal con color de 16 bits. */
    REG_BG3CNT = BG_BMP16_256x256 |
                 BG_BMP_BASE(0) | // La dirección inicial de memoria
                 BG_PRIORITY(3); // Baja prioridad

    /*  Establecer la matriz de transformación afin del fondo 3 de la pantalla principal
        a la matriz de identidad. */
    REG_BG3PA = 1 << 8;
    REG_BG3PB = 0;
    REG_BG3PC = 0;
    REG_BG3PD = 1 << 8;

/*******************************************************************************************/
    /*  Definir la situación del fondo 3 de la pantalla principal. */
    /*  Esto deberá cambiar según la posición en la que se quiera poner el gráfico */
    REG_BG3X = 0;
    REG_BG3Y = 0;
/*******************************************************************************************/

    /*  Establecer la afinidad del fondo 2 de la pantalla principal con color de 16 bits. */
    REG_BG2CNT = BG_BMP16_128x128 |
                 BG_BMP_BASE(8) | // La dirección inicial de memoria
                 BG_PRIORITY(2);  // Baja prioridad

    /*  Establecer la matriz de transformación afin del fondo 2 de la pantalla principal 
        a la matriz de identidad. */
    REG_BG2PA = 1 << 8;
    REG_BG2PB = 0;
    REG_BG2PC = 0;
    REG_BG2PD = 1 << 8;

/*******************************************************************************************/
    /*  Definir la situación del fondo 2 de la pantalla principal. */
    /*  Esto deberá cambiar según la posición en la que se quiera poner el gráfico */
    REG_BG2X = -(SCREEN_WIDTH / 2 - 32) << 8;
    REG_BG2Y = -32 << 8;
/*******************************************************************************************/

    /*  Establecer la afinidad del fondo 3 de la pantalla secundaria con color de 16 bits. */
    REG_BG3CNT_SUB = BG_BMP16_256x256 |
                     BG_BMP_BASE(0) | // La dirección inicial de memoria
                     BG_PRIORITY(3); // Baja prioridad

    /*  Establecer la matriz de transformación afin del fondo 3 de la pantalla secundaria
        a la matriz de identidad. */
    REG_BG3PA_SUB = 1 << 8;
    REG_BG3PB_SUB = 0;
    REG_BG3PC_SUB = 0;
    REG_BG3PD_SUB = 1 << 8;

/*******************************************************************************************/
    /*  Definir la situación del fondo 3 de la pantalla secundaria. */
    /*  Esto deberá cambiar según la posición en la que se quiera poner el gráfico */
    REG_BG3X_SUB = 0;
    REG_BG3Y_SUB = 0;
/*******************************************************************************************/
}

/* Para cada imagen que se quiera llevar a pantalla hay que hacer una de estas funciones. */


void over1() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     fondo1Bitmap, // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0), // Dirección del fondo 3 principal
                     fondo1BitmapLen); // Longitud (en bytes) generada automáticamente



}void over2() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     fondo2Bitmap, // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0), // Dirección del fondo 3 principal
                     fondo2BitmapLen); // Longitud (en bytes) generada automáticamente



}void over3() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     fondo3Bitmap, // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0), // Dirección del fondo 3 principal
                     fondo3BitmapLen); // Longitud (en bytes) generada automáticamente



}void over1Muerte() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     fondoMuerteBitmap, // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0), // Dirección del fondo 3 principal
                     fondoMuerteBitmapLen); // Longitud (en bytes) generada automáticamente



}void over2Muerte() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     fondo2MuerteBitmap, // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0), // Dirección del fondo 3 principal
                     fondo2MuerteBitmapLen); // Longitud (en bytes) generada automáticamente



}void over3Muerte() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     fondo3MuerteBitmap, // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0), // Dirección del fondo 3 principal
                     fondo3MuerteBitmapLen); // Longitud (en bytes) generada automáticamente




}void cielo1() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     CieloBitmap, // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0), // Dirección del fondo 3 principal
                     CieloBitmapLen); // Longitud (en bytes) generada automáticamente



}void cielo2() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     Cielo2Bitmap, // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0), // Dirección del fondo 3 principal
                     Cielo2BitmapLen); // Longitud (en bytes) generada automáticamente



}void cielo3() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     Cielo3Bitmap, // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0), // Dirección del fondo 3 principal
                     Cielo3BitmapLen); // Longitud (en bytes) generada automáticamente



}void cielo1Muerte() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     CielomuerteBitmap, // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0), // Dirección del fondo 3 principal
                     CielomuerteBitmapLen); // Longitud (en bytes) generada automáticamente



}void cielo2Muerte() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     Cielo2muerteBitmap, // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0), // Dirección del fondo 3 principal
                     Cielo2muerteBitmapLen); // Longitud (en bytes) generada automáticamente



}void cielo3Muerte() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     cielo3muerteBitmap, // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0), // Dirección del fondo 3 principal
                     cielo3muerteBitmapLen); // Longitud (en bytes) generada automáticamente




}void nether1() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     netherBitmap, // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0), // Dirección del fondo 3 principal
                     netherBitmapLen); // Longitud (en bytes) generada automáticamente



}void nether2() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     nether2Bitmap, // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0), // Dirección del fondo 3 principal
                     nether2BitmapLen); // Longitud (en bytes) generada automáticamente



}void nether3() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     nether3Bitmap, // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0), // Dirección del fondo 3 principal
                     nether3BitmapLen); // Longitud (en bytes) generada automáticamente



}void nether1Muerte() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     nethermuerteBitmap, // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0), // Dirección del fondo 3 principal
                     nethermuerteBitmapLen); // Longitud (en bytes) generada automáticamente



}void nether2Muerte() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     nether2muerteBitmap, // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0), // Dirección del fondo 3 principal
                     nether2muerteBitmapLen); // Longitud (en bytes) generada automáticamente



}void nether3Muerte() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     nether3muerteBitmap, // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0), // Dirección del fondo 3 principal
                     nether3muerteBitmapLen); // Longitud (en bytes) generada automáticamente
}void off() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     offBitmap, // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0), // Dirección del fondo 3 principal
                     offBitmapLen); // Longitud (en bytes) generada automáticamente

}void panPausa() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     panPausaBitmap, // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0), // Dirección del fondo 3 principal
                     panPausaBitmapLen); // Longitud (en bytes) generada automáticamente

}



