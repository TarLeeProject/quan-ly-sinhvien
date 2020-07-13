#include <winbgim.h> 

#include "Run.h"


int main(int argc, char *argv[])
{
	// now, you can run project
	initwindow(1365, 770);			// init window graphics
	setbkcolor(1);					// set background
   	cleardevice();
	setcolor(14);					// set text color
	outtextxy(50,100,"Graphics in Dev-C++");// print text in window graphics
	giaodiendau();
//	giaodiennhapthongtinqllh();
//	bangthongtinqllh(1);
//	giaodiennhapthongtinqllh_SV();
//	bangthongqllh_SV(1);
//giaodienthongtinqllh_Diem();
// bangthongtinqllh_Diem(1);
//	giaodiennhapthongtinqlltc_loptc();
//	bangthongtinqltc_loptc(1);
//giaodiennhapthongtinqlltc_Sinhviendk();
//bangthongtinqltc_Sinhviendk(1);
//giaodienqltc_Diem();
//bangthongtinqltc_diem(1);
//giaodiennhapthongtinqlltc_Sinhvien();
//bangthongtinqltc_Sinhvien(1);
//giaodienqlmh_qlmonhoc();
//bangthongtinqlmh_qlmonhoc(1);
//giaodienqlmh_qldiem();
//bangthongtinqlmh_qldiem(1);

	while(!kbhit()) delay(1);		// pause screen	
	return 0;
}
