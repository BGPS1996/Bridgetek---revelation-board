/*
 * Conf_Widget.c
 *
 *  Created on: Nov 30, 2023
 *      Author: BGPS
 */
#include "platform.h"
#include "App_Common.h"
#include "stdio.h"
#include "Conf_Widget.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////   local definitions   ////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// Setting buttons in first screen
// Comentario: Para seleccionar la posicion del boton, hay que tener en cuenta la coordenada es para el vertice superior izquierdo
// B1
#define buttonX  0																									// Coordenada x
#define buttonY  0																									// Coordenada y

#define buttonWidth 100																								// Ancho
#define buttonHeight 150																							// Alto


// B2
#define buttonX2 0																									// Coordenada x
#define buttonY2 150																								// Coordenada y

#define buttonWidth2 100																							// Ancho
#define buttonHeight2 150																							// Alto

// B3
#define buttonX3 0																									// Coordenada x
#define buttonY3 300																								// Coordenada y

#define buttonWidth3 100																							// Ancho
#define buttonHeight3 150																							// Alto

// B4
#define buttonX4 0																									// Coordenada x
#define buttonY4 450																								// Coordenada y

#define buttonWidth4 100																							// Ancho
#define buttonHeight4 150																							// Alto

// Numero 1
#define	Number_posX1 150 //100 + 50;																				// Coordenada x
#define	Number_posY1 20																								// Coordenada y
#define Tam_num1 29																									// Tamanio de fuente

// Numero 2
#define Number_posX2 406 //256+150;																					// Coordenada x
#define Number_posY2 10																								// Coordenada y
#define Tam_num2 28																									// Tamanio de fuente

// Numero 3
#define Number_posX3  662 //256+150+256;																			// Coordenada x
#define Number_posY3  10																							// Coordenada y
#define Tam_num3  27																								// Tamanio de fuente

// Numero 4
#define Number_posX4 918 //256+150+256+256;																			// Coordenada x
#define Number_posY4 10																								// Coordenada y
#define Tam_num4 26																									// Tamanio de fuente

// Configuracion Gouge

#define x1 200																										// Coordenada x
#define y1 300																										// Coordenada y

#define r 100																										// Radio
#define major 5
#define minor 4
#define range 100
#define val 0

#define cuadricula 10 																								// 5 min valor de cuadricula
#define grosor_linea 7																								// 7 Min valor

//Dimensiones
#define alto_cuadricula 170
#define ancho_cuadricula 1000
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////   function implementation   /////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int screen1_IdButton(int x, int y)
{

    if (x >= buttonX && x <= buttonX + buttonWidth && y >= buttonY && y <= buttonY + buttonHeight) {
        return 1;  																									// Botón 1

    } else if (x >= buttonX2 && x <= buttonX2 + buttonWidth2 && y >= buttonY2 && y <= buttonY2 + buttonHeight2) {
        return 2;  																									// Botón 2

    } else if (x >= buttonX3 && x <= buttonX3 + buttonWidth3 && y >= buttonY3 && y <= buttonY3 + buttonHeight3) {
        return 3;  																									// Botón 3

    } else if (x >= buttonX4 && x <= buttonX4 + buttonWidth4 && y >= buttonY4 && y <= buttonY4 + buttonHeight4) {
        return 4;  																									// Botón 4

    } else {
        return 0;  																									// No se presionó ningún botón
    }
}


// interpretacion: ancho_sup = 50 = ancho_der ancho_Izq = 250 ancho_Inf = 25
void screen1_Banners(Gpu_Hal_Context_t *phost, int ancho_Sup, int ancho_Inf, int ancho_Der, int ancho_Izq, int ancho_Sep)
{
    // SUPERIOR

    App_WrCoCmd_Buffer(phost, LINE_WIDTH(ancho_Sup*16));
    App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
    App_WrCoCmd_Buffer(phost, COLOR_RGB(161, 142, 142));

    App_WrCoCmd_Buffer(phost, VERTEX2F(0*16,0*16));
    App_WrCoCmd_Buffer(phost, VERTEX2F(1000*16,0*16));

    // DERECHO

    App_WrCoCmd_Buffer(phost, LINE_WIDTH(ancho_Der*16));
    App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
    App_WrCoCmd_Buffer(phost, COLOR_RGB(161, 142, 142));

    App_WrCoCmd_Buffer(phost, VERTEX2F(1000*16,0*16));
    App_WrCoCmd_Buffer(phost, VERTEX2F(1000*16,1000*16));

    // IZQUIERDO

    App_WrCoCmd_Buffer(phost, LINE_WIDTH(ancho_Izq*16));
    App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
    App_WrCoCmd_Buffer(phost, COLOR_RGB(161, 142, 142));

    App_WrCoCmd_Buffer(phost, VERTEX2F(0*16,0*16));
    App_WrCoCmd_Buffer(phost, VERTEX2F(0*16,1000*16));

    // INFERIOR

    App_WrCoCmd_Buffer(phost, LINE_WIDTH(ancho_Inf*16));
    App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
    App_WrCoCmd_Buffer(phost, COLOR_RGB(161, 142, 142));

    App_WrCoCmd_Buffer(phost, VERTEX2F(0*16,600*16));
    App_WrCoCmd_Buffer(phost, VERTEX2F(1000*16,600*16));

    // SEPARADORES

    App_WrCoCmd_Buffer(phost, LINE_WIDTH(ancho_Sep*16));
    App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
    App_WrCoCmd_Buffer(phost, COLOR_RGB(161, 142, 142));


    App_WrCoCmd_Buffer(phost, VERTEX2F(0*16, (170+ancho_Sup)*16));
    App_WrCoCmd_Buffer(phost, VERTEX2F(1000*16, (170+ancho_Sup)*16));

    App_WrCoCmd_Buffer(phost, VERTEX2F(0*16, (170+ancho_Sup + 170)*16));
    App_WrCoCmd_Buffer(phost, VERTEX2F(1000*16, (170+ancho_Sup + 170)*16));

    App_WrCoCmd_Buffer(phost, END());

    //EJE 1 :

    int offset_x = 10;

   // CORDENADA Y TAMANIO
    int inicio_x = ancho_Sup ;																				// Coordenada de inicio en eje y
    int inicio_y = ancho_Izq + offset_x;																	// Coordenada de inicio en eje x
    int limite_y = alto_cuadricula + inicio_x;																// Altura de cuadricula (150)
    int limite_x = ancho_cuadricula - offset_x - ancho_Der;													// Ancho de cuadricula

    App_WrCoCmd_Buffer(phost, END()); 																		// Finaliza la figura

    // EJE X
    App_WrCoCmd_Buffer(phost, LINE_WIDTH(grosor_linea + 4));
    App_WrCoCmd_Buffer(phost, BEGIN(LINES));
    App_WrCoCmd_Buffer(phost, COLOR_RGB(255, 247, 1));
    App_WrCoCmd_Buffer(phost, VERTEX2F(inicio_y * 16, (5+inicio_x + alto_cuadricula/2) * 16));
    App_WrCoCmd_Buffer(phost, VERTEX2F(limite_x * 16, (5+inicio_x + alto_cuadricula/2) * 16));

    App_WrCoCmd_Buffer(phost, END()); 																		// Finaliza la figura

    // EJE 2:

    inicio_x = ancho_Sup + alto_cuadricula;																	// Coordenada de inicio en eje x
    limite_y = alto_cuadricula + inicio_x;																	// Altura de cuadricula (170+10,)
    limite_x = ancho_cuadricula - offset_x - ancho_Der;														// Ancho de cuadricula


    App_WrCoCmd_Buffer(phost, END()); 																		// Finaliza la figura
    App_WrCoCmd_Buffer(phost, LINE_WIDTH(grosor_linea + 4));
    App_WrCoCmd_Buffer(phost, BEGIN(LINES));
    App_WrCoCmd_Buffer(phost, COLOR_RGB(217, 136, 128));
    App_WrCoCmd_Buffer(phost, VERTEX2F(inicio_y * 16, (5+inicio_x + alto_cuadricula/2) * 16));
    App_WrCoCmd_Buffer(phost, VERTEX2F(limite_x * 16, (5+inicio_x + alto_cuadricula/2) * 16));

    App_WrCoCmd_Buffer(phost, END()); 																		// Finaliza la figura

    // EJE 3:

    inicio_x = ancho_Sup + alto_cuadricula + alto_cuadricula;												// Coordenada de inicio en eje x

    limite_y = alto_cuadricula + inicio_x;																	// Altura de cuadricula (180)
    limite_x = ancho_cuadricula - offset_x - ancho_Der;														// Ancho de cuadricula


    App_WrCoCmd_Buffer(phost, END()); 																		// Finaliza la figura
    App_WrCoCmd_Buffer(phost, LINE_WIDTH(grosor_linea + 4));
    App_WrCoCmd_Buffer(phost, BEGIN(LINES));
    App_WrCoCmd_Buffer(phost, COLOR_RGB(212, 172, 13));
    App_WrCoCmd_Buffer(phost, VERTEX2F(inicio_y * 16, (5+inicio_x + alto_cuadricula/2) * 16));
    App_WrCoCmd_Buffer(phost, VERTEX2F(limite_x * 16, (5+inicio_x + alto_cuadricula/2) * 16));

    App_WrCoCmd_Buffer(phost, END()); 																		// Finaliza la figura

}

void screen1_Parameters(Gpu_Hal_Context_t *phost, int a, int b, int c, int d)
{

    App_WrCoCmd_Buffer(phost, COLOR_RGB(255, 255, 255));													// fondo de pantalla inferior

    																										// Numero a
    Gpu_CoCmd_Number(phost, Number_posX1, Number_posY1, Tam_num1, 0 , a);
    																										// Numero b
    Gpu_CoCmd_Number(phost, Number_posX2, Number_posY2, Tam_num2, 0 , b);
    																										// Numero c
    Gpu_CoCmd_Number(phost, Number_posX3, Number_posY3, Tam_num3, 0 , c);
    																										// Numero d
    Gpu_CoCmd_Number(phost,Number_posX4,Number_posY4, Tam_num4, 0 , d);

}

void screen1_Buttons(Gpu_Hal_Context_t *phost)
{
    // Dibuja el botón 1
    Gpu_CoCmd_FgColor(phost, COLOR_RGB(199,176,32));
    Gpu_CoCmd_Button(phost, 0, 0, buttonWidth, buttonHeight, 31, 0, "B1");

    // Dibuja el botón 2
    Gpu_CoCmd_FgColor(phost,COLOR_RGB(241, 196, 15));
    Gpu_CoCmd_Button(phost, 0, 150, buttonWidth2, buttonHeight2, 31, 0, "B2");

    // Dibuja el botón 3
    Gpu_CoCmd_FgColor(phost, COLOR_RGB(235, 152, 78));
    Gpu_CoCmd_Button(phost, 0, 300, buttonWidth3, buttonHeight3, 31, 0, "B3");

    // Dibuja el botón 4
    Gpu_CoCmd_FgColor(phost, COLOR_RGB(40, 116, 166));
    Gpu_CoCmd_Button(phost, 0, 450, buttonWidth4, buttonHeight4, 31, 0, "B4");

}

void screen1_Widget(Gpu_Hal_Context_t *phost, int numero, int a, int b, int tag)
{

        App_WrCoCmd_Buffer(phost, CLEAR_COLOR_RGB(0,0,0)); 													// fondo de pantalla superior
       	App_WrCoCmd_Buffer(phost, COLOR_RGB(255, 255, 255));												// fondo de pantalla inferior
        App_WrCoCmd_Buffer(phost, CLEAR(1,0,1));															// limpieza de cada capa

// -BANNERS-
        // ancho_sup = 50 =ancho_der ancho_Izq=250 ancho_Inf=25
        screen1_Banners(phost, 50, 25, 30, 250, 5);

// -NUMERO SUPERIOR-
        screen1_Parameters(phost, numero, tag, a, b);

// -BOTONES IZQ-
        screen1_Buttons(phost);

        //Ejemplos de uso de Widgets
        //Gpu_CoCmd_FgColor(phost,COLOR_RGB(60,247,216));
        //Gpu_CoCmd_Toggle(phost, buttonX2, buttonY2, buttonWidth2, buttonHeight2, 31, 0, "No");

        //Gpu_CoCmd_Gauge(phost, x, y, r, 0, major, minor, numero, range);

        //Gpu_CoCmd_FgColor(phost,COLOR_RGB(221,25,156));
        //Gpu_CoCmd_Toggle(phost, 160, 120, 50, 27, 0, 0, "No"  "\xff" "Si");

        //App_WrCoCmd_Buffer(phost, DISPLAY());
       	//Gpu_CoCmd_Swap(phost);

}


#define NUM_PUNTOS 91

void screen1_View(Gpu_Hal_Context_t *phost)
{
	 int valor = 0;

	  uint16_t x = 0, y = 0;
	  uint8_t currTag = 0;

	  int mostrarX=0,mostrarY=0, id_button=0;
	  uint8_t mostrarTAG = 0;

    double puntos[NUM_PUNTOS];

    puntos[0]=	 0;		puntos[19]= -17;	puntos[37]=	 17;	puntos[55]= -17;	puntos[73]=	 17;
    puntos[1]=	 17;	puntos[20]= -34;	puntos[38]=	 34;	puntos[56]= -34;	puntos[74]=	 34;
    puntos[2]=	 34;	puntos[21]= -50;	puntos[39]=	 50;	puntos[57]= -50;	puntos[75]=	 50;
    puntos[3]=	 50;	puntos[22]= -64;	puntos[40]=	 64;	puntos[58]= -64;	puntos[76]=	 64;
    puntos[4]=	 64;	puntos[23]= -77;	puntos[41]=	 77;	puntos[59]= -77;	puntos[77]=	 77;
    puntos[5]=	 77;	puntos[24]= -87;	puntos[42]=	 87;	puntos[60]= -87;	puntos[78]=	 87;
    puntos[6]=	 87;	puntos[25]= -94;	puntos[43]=	 94;	puntos[61]= -94;	puntos[79]=	 94;
    puntos[7]=	 94;	puntos[26]= -98;	puntos[44]=	 98;	puntos[62]= -98;	puntos[80]=	 98;
    puntos[8]=	 98;	puntos[27]= -100;	puntos[45]=	 100;	puntos[63]= -100;	puntos[81]=	 100;
    puntos[9]=	 100;	puntos[28]= -98;	puntos[46]=	 98;	puntos[64]= -98;	puntos[82]=	 98;
    puntos[10]=	 98;	puntos[29]= -94;	puntos[47]=	 94;	puntos[65]= -94;	puntos[83]=	 94;
    puntos[11]=	 94;	puntos[30]= -87;	puntos[48]=	 87;	puntos[66]= -87;	puntos[84]=	 87;
    puntos[12]=	 87;	puntos[31]= -77;	puntos[49]=	 77;	puntos[67]= -77;	puntos[85]=	 77;
    puntos[13]=	 77;	puntos[32]= -64;	puntos[50]=	 64;	puntos[68]= -64;	puntos[86]=	 64;
    puntos[14]=	 64;	puntos[33]= -50;	puntos[51]=	 50;	puntos[69]= -50;	puntos[87]=	 50;
    puntos[15]=	 50;	puntos[34]= -34;	puntos[52]=	 34;	puntos[70]= -34;	puntos[88]=	 34;
    puntos[16]=	 34;	puntos[35]= -17;	puntos[53]=	 17;	puntos[71]= -17;	puntos[89]=	 17;
    puntos[17]=	 17;	puntos[36]=	 0;		puntos[54]=	 0;		puntos[72]=	 0;		puntos[90]=	 0;
    puntos[18]=	 0;

	int k = 0;

	    while (k < NUM_PUNTOS)
	    {

	        Gpu_CoCmd_Dlstart(phost); 																		//Inicio de pantalla

	        screen1_Widget(phost, id_button, mostrarX, mostrarY, (int)mostrarTAG);

	        App_WrCoCmd_Buffer(phost, LINE_WIDTH(1 * 16)); 													// Tamaño del punto
	        App_WrCoCmd_Buffer(phost, BEGIN(LINES)); 														// Iniciar el dibujo de puntos
	        App_WrCoCmd_Buffer(phost, COLOR_RGB(255, 247, 1));

	        for(int act = 0; act < k; act++)
	        {
	        	if(act == 0) // punto
	        	{
	        		App_WrCoCmd_Buffer(phost, VERTEX2F((0 + 250+10) * 16, (300 + (int)puntos[act]) * 16));
	        		App_WrCoCmd_Buffer(phost, VERTEX2F((0 + 250+10) * 16, (300 + (int)puntos[act]) * 16));
	        	}else{

	        		App_WrCoCmd_Buffer(phost, VERTEX2F(((act-1) + 250+10) * 16, (300 + (int)puntos[act-1]) * 16));
	        		App_WrCoCmd_Buffer(phost, VERTEX2F((act + 250+10) * 16    , (300 + (int)puntos[act]) * 16));
	        	}
	        }

	        if(k == 0)
	        {
	            App_WrCoCmd_Buffer(phost, VERTEX2F((valor + 250+10) * 16, (300 + (int)puntos[k]) * 16));
	            App_WrCoCmd_Buffer(phost, VERTEX2F((valor + 250+10) * 16, (300 + (int)puntos[k]) * 16));

	        }else{
	        	App_WrCoCmd_Buffer(phost, VERTEX2F(((valor-1) + 250+10) * 16, (300 + (int)puntos[k-1]) * 16));
	        	App_WrCoCmd_Buffer(phost, VERTEX2F((valor + 250+10) * 16    , (300 + (int)puntos[k]) * 16));
	        }

	        App_WrCoCmd_Buffer(phost, DISPLAY()); 															// Muestra en pantalla
	        Gpu_CoCmd_Swap(phost); 																			// Intercambia los buffers

	        k++;

	        valor++;

	        if(k >= NUM_PUNTOS)
	        {
	        	k = 0;
	        	valor = 0;
	        }

	        mostrarTAG = App_Touch_Update(phost, &currTag, &x, &y); 											// Detecto los toques, y los almaceno
	        mostrarX = (int)x;
	        mostrarY = (int)y;


	        screen1_SwitchScreen(phost, screen1_IdButton(x,y));												// seleccion de ventanaas

	        App_WrCoCmd_Buffer(phost, DISPLAY()); 															// Muestra en pantalla
	        Gpu_CoCmd_Swap(phost); 																			// Intercambia los buffers

	    }
}

void screen1_SwitchScreen(Gpu_Hal_Context_t *phost,int select)
{

    switch(select) {
    	case 0:																								// No hacer nada
    		break;
        case 1:																								// Principal
        	int k = 0;
        	while(k < 100)
        	{
        		Gpu_CoCmd_Dlstart(phost); 																	// Inicio de pantalla
                App_WrCoCmd_Buffer(phost, CLEAR_COLOR_RGB(0,0,0)); 											// Fondo de pantalla superior
               	App_WrCoCmd_Buffer(phost, COLOR_RGB(255, 255, 255));										// Fondo de pantalla inferior
                App_WrCoCmd_Buffer(phost, CLEAR(1,0,1));													// Limpieza de cada capa

        	    // Dibuja el botón 1

        	    Gpu_CoCmd_FgColor(phost,COLOR_RGB(199,176,32));
        	    Gpu_CoCmd_Button(phost, 0, 0, buttonWidth, buttonHeight, 31, 0, "B1");

        	    // Dibuja el botón 2

        	    Gpu_CoCmd_FgColor(phost,COLOR_RGB(241, 196, 15));
        	    Gpu_CoCmd_Button(phost, 0, 150, buttonWidth2, buttonHeight2, 31, 0, "B2");
        		k++;

    	        App_WrCoCmd_Buffer(phost, DISPLAY()); 														// Muestra en pantalla
    	        Gpu_CoCmd_Swap(phost); 																		// Intercambia los buffers
        	}

            break;
        case 2:																								// Secundario
        	int k4 = 0;
        	int bandera = 1;
        	uint8_t currTag = 0;
        	uint16_t x,y;
        	while(bandera)
        	{
        		Gpu_CoCmd_Dlstart(phost); 																	// Inicio de pantalla
                App_WrCoCmd_Buffer(phost, CLEAR_COLOR_RGB(0,0,0)); 											// Fondo de pantalla superior
               	App_WrCoCmd_Buffer(phost, COLOR_RGB(255, 255, 255));										// Fondo de pantalla inferior
                App_WrCoCmd_Buffer(phost, CLEAR(1,0,1));													// Limpieza de cada capa

        	    // Dibuja el botón 1

        	    Gpu_CoCmd_FgColor(phost, COLOR_RGB(199,176,32));
        	    Gpu_CoCmd_Button(phost, 100, 0, buttonWidth, buttonHeight, 31, 0, "cero");

        	    // Dibuja el botón 2

        	    Gpu_CoCmd_FgColor(phost, COLOR_RGB(241, 196, 15));
        	    Gpu_CoCmd_Button(phost, 100, 150, buttonWidth2, buttonHeight2, 31, 0, "exit");
        		k4++;


        		App_Touch_Update(phost, &currTag, &x, &y); 													// Detecto los toques, y los almaceno

        		if(x >= 100 && x <= 100 + buttonWidth2 && y >= 150 && y <= 150 + buttonHeight2)
        		{
        			bandera = 0;
        		}
        		if(x >= 100 && x <= 100 + buttonWidth && y >= buttonY && y <= buttonY + buttonHeight)
        		{
        			k4 = 0;
        		}
        		Gpu_CoCmd_Number(phost, Number_posX4, Number_posY4, 31, 0 , k4);
        		App_WrCoCmd_Buffer(phost, DISPLAY()); 														// Muestra en pantalla
    	        Gpu_CoCmd_Swap(phost);																		// Intercambia los buffers

        	}
            break;
        case 3:																								// Tercero

            break;
        case 4:																								// Cuarto

            break;
        default:
            																								//error
    }
}

