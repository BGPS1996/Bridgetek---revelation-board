#include "platform.h"
#include "App_Common.h"

#define DISP_WIDTH 1024	//px
#define DISP_HEIGHT 600	//px

#include "Conf_Widget.h"


#include "App_Common.h"
Gpu_Hal_Context_t host, *phost;


int main() {

    phost = &host;

    App_Common_Init(&host);

    screen1_View(phost);	// principal pantalla


    App_Common_Close(&host);

    return 0;
}
