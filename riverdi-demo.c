#include "platform.h"
#include "App_Common.h"

#define DISP_WIDTH 1024	//px
#define DISP_HEIGHT 600	//px

#include "Conf_Widget.h"
/*********pruebas************/
#include <math.h>
#define NUM_PUNTOS 91
#define AMPLITUD 100.0
#define FRECUENCIA 0.1
/*Prototipos*/

void setup(); // configuraciones iniciales
void widget(int size);	// objetos pantalla

void banners(int ancho_Sup, int ancho_Inf, int ancho_Der, int ancho_Izq, int ancho_Sep);
void parametros(int,int,int,int);
void botones();


#include "App_Common.h"
Gpu_Hal_Context_t host, *phost;

int main() {

	setup();
	int valor = 0;

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

		Gpu_CoCmd_Dlstart(phost); //Inicio de pantalla

		widget(valor);

	    App_WrCoCmd_Buffer(phost, LINE_WIDTH(1 * 16)); // Tamaño del punto
	    App_WrCoCmd_Buffer(phost, BEGIN(LINES)); // Iniciar el dibujo de puntos
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

	    App_WrCoCmd_Buffer(phost, DISPLAY()); // Muestra en pantalla
	    Gpu_CoCmd_Swap(phost); // Intercambia los buffers
	    k++;
	    valor++;
	}

    // Cerrar contexto común de la aplicación
    App_Common_Close(&host);

    return 0;
}

// ancho_sup = 50 =ancho_der ancho_Izq=250 ancho_Inf=25
void banners(int ancho_Sup, int ancho_Inf, int ancho_Der, int ancho_Izq, int ancho_Sep)
{
	// Superior

	App_WrCoCmd_Buffer(phost, LINE_WIDTH(ancho_Sup*16));
    App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
    App_WrCoCmd_Buffer(phost, COLOR_RGB(161, 142, 142));

    App_WrCoCmd_Buffer(phost, VERTEX2F(0*16,0*16));
    App_WrCoCmd_Buffer(phost, VERTEX2F(1000*16,0*16));

    // Derecho

    App_WrCoCmd_Buffer(phost, LINE_WIDTH(ancho_Der*16));
    App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
    App_WrCoCmd_Buffer(phost, COLOR_RGB(161, 142, 142));

    App_WrCoCmd_Buffer(phost, VERTEX2F(1000*16,0*16));
    App_WrCoCmd_Buffer(phost, VERTEX2F(1000*16,1000*16));

    // Izquierdo

    App_WrCoCmd_Buffer(phost, LINE_WIDTH(ancho_Izq*16));
    App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
    App_WrCoCmd_Buffer(phost, COLOR_RGB(161, 142, 142));

    App_WrCoCmd_Buffer(phost, VERTEX2F(0*16,0*16));
    App_WrCoCmd_Buffer(phost, VERTEX2F(0*16,1000*16));

    // Inferior

    App_WrCoCmd_Buffer(phost, LINE_WIDTH(ancho_Inf*16));
    App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
    App_WrCoCmd_Buffer(phost, COLOR_RGB(161, 142, 142));

    App_WrCoCmd_Buffer(phost, VERTEX2F(0*16,600*16));
    App_WrCoCmd_Buffer(phost, VERTEX2F(1000*16,600*16));

    // Separadores

    App_WrCoCmd_Buffer(phost, LINE_WIDTH(ancho_Sep*16));
    App_WrCoCmd_Buffer(phost, BEGIN(RECTS));
    App_WrCoCmd_Buffer(phost, COLOR_RGB(161, 142, 142));


    App_WrCoCmd_Buffer(phost, VERTEX2F(0*16, (170+ancho_Sup)*16));
    App_WrCoCmd_Buffer(phost, VERTEX2F(1000*16, (170+ancho_Sup)*16));

    App_WrCoCmd_Buffer(phost, VERTEX2F(0*16, (170+ancho_Sup + 170)*16));
    App_WrCoCmd_Buffer(phost, VERTEX2F(1000*16, (170+ancho_Sup + 170)*16));

    App_WrCoCmd_Buffer(phost, END());

    /************ Ejes *************/

    //EJE 1 :

    	    int offset_x = 10;

    	    // coordenadas y tamaño
    	    int inicio_x = ancho_Sup ;	// coordenada de inicio en eje y
    	    int inicio_y = ancho_Izq + offset_x;	// coordenada de inicio en eje x

    	    int limite_y = alto_cuadricula + inicio_x;	// altura de cuadricula (150)
    	    int limite_x = ancho_cuadricula - offset_x - ancho_Der;	// ancho de cuadricula

    	    App_WrCoCmd_Buffer(phost, END()); // Finaliza la figura

    	    // eje X
    	    App_WrCoCmd_Buffer(phost, LINE_WIDTH(grosor_linea + 4));
    	    App_WrCoCmd_Buffer(phost, BEGIN(LINES));
    	    App_WrCoCmd_Buffer(phost, COLOR_RGB(255, 247, 1));
    	    App_WrCoCmd_Buffer(phost, VERTEX2F(inicio_y * 16, (5+inicio_x + alto_cuadricula/2) * 16));
    	    App_WrCoCmd_Buffer(phost, VERTEX2F(limite_x * 16, (5+inicio_x + alto_cuadricula/2) * 16));

    	    App_WrCoCmd_Buffer(phost, END()); // Finaliza la figura

    // EJE 2:

    	    inicio_x = ancho_Sup + alto_cuadricula;	// coordenada de inicio en eje x

    	    limite_y = alto_cuadricula + inicio_x;	// altura de cuadricula (170+10,)
    	    limite_x = ancho_cuadricula - offset_x - ancho_Der;	// ancho de cuadricula


    	    App_WrCoCmd_Buffer(phost, END()); // Finaliza la figura
    	    App_WrCoCmd_Buffer(phost, LINE_WIDTH(grosor_linea + 4));
    	    App_WrCoCmd_Buffer(phost, BEGIN(LINES));
    	    App_WrCoCmd_Buffer(phost, COLOR_RGB(217, 136, 128));
    	    App_WrCoCmd_Buffer(phost, VERTEX2F(inicio_y * 16, (5+inicio_x + alto_cuadricula/2) * 16));
    	    App_WrCoCmd_Buffer(phost, VERTEX2F(limite_x * 16, (5+inicio_x + alto_cuadricula/2) * 16));

    	    App_WrCoCmd_Buffer(phost, END()); // Finaliza la figura

    // EJE 3:

    	  inicio_x = ancho_Sup + alto_cuadricula + alto_cuadricula;	// coordenada de inicio en eje x

    	  limite_y = alto_cuadricula + inicio_x;	// altura de cuadricula (180)
    	  limite_x = ancho_cuadricula - offset_x - ancho_Der;	// ancho de cuadricula


    	  App_WrCoCmd_Buffer(phost, END()); // Finaliza la figura
    	  App_WrCoCmd_Buffer(phost, LINE_WIDTH(grosor_linea + 4));
    	  App_WrCoCmd_Buffer(phost, BEGIN(LINES));
    	  App_WrCoCmd_Buffer(phost, COLOR_RGB(212, 172, 13));
    	  App_WrCoCmd_Buffer(phost, VERTEX2F(inicio_y * 16, (5+inicio_x + alto_cuadricula/2) * 16));
    	  App_WrCoCmd_Buffer(phost, VERTEX2F(limite_x * 16, (5+inicio_x + alto_cuadricula/2) * 16));

    	  App_WrCoCmd_Buffer(phost, END()); // Finaliza la figura

}

void parametros(int a, int b, int c, int d)
{

    App_WrCoCmd_Buffer(phost, COLOR_RGB(255, 255, 255));	// fondo de pantalla inferior

	// Numero a
    Gpu_CoCmd_Number(phost,Number_posX1,Number_posY1, Tam_num1, 0 , a);

    // Numero b
    Gpu_CoCmd_Number(phost,Number_posX2,Number_posY2, Tam_num2, 0 , b);

    // Numero c
    Gpu_CoCmd_Number(phost,Number_posX3,Number_posY3, Tam_num3, 0 , c);

    // Numero d
    Gpu_CoCmd_Number(phost,Number_posX4,Number_posY4, Tam_num4, 0 , d);

}

void botones()
{
    // Dibuja el botón 1
    Gpu_CoCmd_FgColor(phost,COLOR_RGB(199,176,32));
    Gpu_CoCmd_Button(phost, 0,0, buttonWidth, buttonHeight, 31, 0, "B1");

    // Dibuja el botón 2
    Gpu_CoCmd_FgColor(phost,COLOR_RGB(241, 196, 15));
    Gpu_CoCmd_Button(phost, 0, 150, buttonWidth2, buttonHeight2, 31, 0, "B2");

    // Dibuja el botón 3
    Gpu_CoCmd_FgColor(phost,COLOR_RGB(235, 152, 78));
    Gpu_CoCmd_Button(phost, 0, 300, buttonWidth3, buttonHeight3, 31, 0, "B3");

    // Dibuja el botón 4
    Gpu_CoCmd_FgColor(phost,COLOR_RGB(40, 116, 166));
    Gpu_CoCmd_Button(phost, 0, 450, buttonWidth4, buttonHeight4, 31, 0, "B4");

}

void widget(int numero)
{
		//Gpu_CoCmd_Dlstart(phost);// Inicio de pantalla

		App_WrCoCmd_Buffer(phost, CLEAR_COLOR_RGB(0,0,0)); // fondo de pantalla superior
	   	App_WrCoCmd_Buffer(phost, COLOR_RGB(255, 255, 255));	// fondo de pantalla inferior
	    App_WrCoCmd_Buffer(phost, CLEAR(1,0,1));	// limpieza de cada capa

/***************** BANNERS ****************************************************/
	    // ancho_sup = 50 =ancho_der ancho_Izq=250 ancho_Inf=25
	    banners(50,25,30,250,5);

/****************************-NUMERO SUPERIOR-**************************************/
	    parametros(numero,numero,numero,numero);

/*************************-BOTONES IZQ-***************************************/
	    //botones();


/*********************************- GRID -********************************************************- GRID -****************************************************/

	    //Ejemplos de uso de Widgets
	    //Gpu_CoCmd_FgColor(phost,COLOR_RGB(60,247,216));
	    //Gpu_CoCmd_Toggle(phost, buttonX2, buttonY2, buttonWidth2, buttonHeight2, 31, 0, "No");

	    //Gpu_CoCmd_Gauge(phost, x, y, r, 0, major, minor, numero, range);

	    //Gpu_CoCmd_FgColor(phost,COLOR_RGB(221,25,156));
	    //Gpu_CoCmd_Toggle(phost, 160, 120, 50, 27, 0, 0, "No"  "\xff" "Si");

	    //App_WrCoCmd_Buffer(phost, DISPLAY());
	   	//Gpu_CoCmd_Swap(phost);

}

void setup()
{
	phost = &host;
	App_Common_Init(&host);
	//App_Show_Logo(phost);
}
