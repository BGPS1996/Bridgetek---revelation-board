/*
 * Conf_Widget.h
 *
 *  Created on: Dic 12, 2023
 *      Author: BGPS
 *
 *   Comentarios: Se van a implementar por cada pantalla un TAD, las funciones desarrolladas son identicas para cada pantalla
 *   la difencia esta en la ubicacion entre los "objetos" y la accion. ademas es importante diferenciar cada TAD
 *   en versiones anteriores se optara por usar un prefijo: view1_ para las funciones de la primer pantalla.
 */
#include "platform.h"
#include "App_Common.h"
#include "stdio.h"


#ifndef APP_LAYER_CONF_WIDGET_H_
#define APP_LAYER_CONF_WIDGET_H_
// Global Define

#define DISP_WIDTH 1024	//px
#define DISP_HEIGHT 600	//px
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////   Prototypes   /////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void screen1_Widget(Gpu_Hal_Context_t *, int ,int, int, int);					// Objetos pantalla

void screen1_Banners(Gpu_Hal_Context_t *, int, int, int, int, int);				// Muestra en pantalla como dibujar

void screen1_Parameters(Gpu_Hal_Context_t *, int, int, int, int);				// Muestra en pantallas numero, que sirven para debug

void screen1_Buttons(Gpu_Hal_Context_t *);										// Muestra en pantalla los botones

void screen1_View(Gpu_Hal_Context_t*);											// Acople de toda las funciones

void screen1_SwitchScreen(Gpu_Hal_Context_t *, int);							// Selector de pantalla, accion dependiendo de cual boton toque

int screen1_IdButton(int, int);													// Identificador de boton

#endif /* APP_LAYER_CONF_WIDGET_H_ */
