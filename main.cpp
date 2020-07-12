#include <winbgim.h> 

#include "LopTinChi.h"
#include "DoHoa.h"

int main(int argc, char *argv[])
{
	// now, you can run project
	initwindow(1365, 770);			// init window graphics
	setbkcolor(1);					// set background
   	cleardevice();
	setcolor(14);					// set text color
	outtextxy(50,100,"Graphics in Dev-C++");// print text in window graphics
//	khungChinh();
	giaodiendau();
	giaodiennhapthongtinqllh();
	while(!kbhit()) delay(1);		// pause screen	
	return 0;
}
