#include <winbgim.h> 
const int H= 700;
const int W=1360;
int MID[1350][680];
// khong duoc xoa neu doc gia da co muon
// chi tiet 
void khoitaoID()
{
	for(int i=10;i<1350;i++)
	{
		for(int j=10;j<680;j++)
		MID[i][j]=0;
	}
}
void taoID(int x1,int y1,int x2,int y2, int ID)
{
	for(int i=x1;i<x2;i++)
	{
		for(int j=y1;j<y2;j++)
		MID[i][j]=ID;
	}
}
const int ENTER = 13;
const int BACKSPACE = 8;

void ScannerString(char s[],int max, int px ,int py,int ID,int &IDnext)
{
	setcolor(0);
	setbkcolor(15);
	settextstyle(1,0,1);
	int mx=-1;
	int my=-1;
	unsigned int l = strlen(s);
		s[l] ='|';
	outtextxy(px,py,s);
	while(1)
	{
		getmouseclick(WM_LBUTTONDOWN,mx,my);
		clearmouseclick(WM_LBUTTONDOWN);
		delay(1);
		if  (!(((mx==-1)&&(my==-1))||(MID[my][mx]== ID))) {
			s[l] = ' ';
			outtextxy(px,py,s);
			s[l]= '\0';	
			break;
		}
		if(kbhit())
		{			
		char c = getch();
			if(l<max)
			{
				if((l==0||s[l-1]==' '))
				{
					if(c<='z'&&c>='a')
					c=c+'A'-'a';
					else
					c=c;
					
				}
				else if(c<='Z'&&c>='A')
				c=c-'A'+'a';
				if(c=='_')
				{
					s[l] = c;
					l++;
				}
				if(c>='a' && c<='z')
				{
					s[l] = c;
					l++;
				}
				if(c>='A' && c<='Z')
				{
				s[l] = c;
					l++;
				}
				if(c>='0' && c<='9')
				{
					s[l] = c;
					l++;
				}
				if(l>0) if(s[l-1]!=' ' && c == ' ')
				{
					s[l] = c;
					l++;
				}
				if((l==0||s[l-1]==' ')&&(s[l]>='a'||s[l]<='z'))
				s[l]=s[l]+'A'-'a';
				
				outtextxy(px,py,s);	
			}
			if(c == ENTER) {
				s[l] = ' ';
				outtextxy(px,py,s);
				s[l]= '\0';
				break;
			}
			if(c == BACKSPACE&&l>0)
			{
				s[l]=' ';
				outtextxy(px,py,s);	
				s[l-1] =' ';
				l--;
			}
			s[l] = '|';
			outtextxy(px,py,s);	
			if(s[l]==' ') s[l]=0;
		
		}
	}
	if((mx!=-1)&&(my!=-1)) {
	IDnext=MID[mx][my];
	}
}

void ScannerName(char s[],int max, int px ,int py,int ID, int &IDnext)
{
	setcolor(0);
	setbkcolor(15);
	settextstyle(1,0,1);
	int mx=-1;
	int my=-1;
	unsigned int l = strlen(s);
		s[l] ='|';
	outtextxy(px,py,s);
	while(1)
	{
		getmouseclick(WM_LBUTTONDOWN,mx,my);
		clearmouseclick(WM_LBUTTONDOWN);
		delay(1);
		if  (!(((mx==-1)&&(my==-1))||(MID[my][mx]== ID))) {
			s[l] = ' ';
			outtextxy(px,py,s);
			s[l]= '\0';	
			break;
		}
		if(kbhit())
		{			
		char c = getch();
			if(l<max)
			{

				if((l==0||s[l-1]==' '))
				{
					if(c<='z'&&c>='a')
					c=c+'A'-'a';
					else
					c=c;
					
				}
				else if(c<='Z'&&c>='A')
				c=c-'A'+'a';

				if(c>='a' && c<='z')
				{
					s[l] = c;
					l++;
				}
				if(c>='A' && c<='Z')
				{
				s[l] = c;
					l++;
				}
				
				if(l>0) if(s[l-1]!=' ' && c == ' ')
				{
					s[l] = c;
					l++;
				}
				
			}
			if(c == ENTER) {
				s[l] = ' ';
				outtextxy(px,py,s);
				s[l]= '\0';
				break;
			}
			if(c == BACKSPACE&&l>0)
			{
				s[l]=' ';
				outtextxy(px,py,s);
				s[l-1] =' ';
				l--;
			}
			s[l] = '|';
			outtextxy(px,py,s);	
			if(s[l]==' ') s[l]='\0';
		
		}
	}
	if((mx!=-1)&&(my!=-1)) {
	IDnext=MID[mx][my];
	}
}

int ScannerNum(char s[], int max, int px ,int py,int ID, int &IDnext)
{
	setcolor(0);
	setbkcolor(15);
	settextstyle(1,0,1);

	int mx=-1;
	int my=-1;
	unsigned int l = strlen(s);
	s[l] ='|';
	outtextxy(px,py,s);
	while(1)
	{
		getmouseclick(WM_LBUTTONDOWN,mx,my);
		clearmouseclick(WM_LBUTTONDOWN);
		delay(1);
		if  (!(((mx==-1)&&(my==-1))||(MID[my][mx]== ID))) {
			
			s[l] = ' ';
			outtextxy(px,py,s);
			s[l]= '\0';	
			break;
		}
		if(kbhit())
		{
				
			char c = getch();
			
			if(l<max)
			{
				
				if(c>='0' && c<='9')
				{
					s[l] = c;
				 outtextxy(px,py,s);
					l++;
				}
			}
			if(c == ENTER) {
				s[l] = ' ';
				outtextxy(px,py,s);
				s[l]= '\0';
				break;
			}
			if(c == BACKSPACE&&l>0){
				s[l]=' ';
				outtextxy(px,py,s);
				s[l-1] =' ';
			
				l--;
			}
			s[l] = '|';
			outtextxy(px,py,s);	
			if(s[l]==' ') s[l]='\0';
		}
	}
	if((mx!=-1)&&(my!=-1)) 
	IDnext=MID[mx][my];
}
void mancanhbao()
{
    setfillstyle(1,11);	
	bar(20,465,300,675);
	setbkcolor(11);
	setcolor(12);
	settextstyle(0,0,2);
	outtextxy(100,470,"CANH BAO");
	
}
void khungChinh()
{
	setfillstyle(1,11);// man
	bar(0,0,1360,700);
	setcolor(0);
    rectangle(2,2,1353,693);
    rectangle(4,4,273,270);
    rectangle(4,275,273,690);
    rectangle(280,4,1350,220);
    rectangle(280,225,1350,690);

	setbkcolor(11);
	setcolor(12);
	settextstyle(0,0,2);
	outtextxy(90,285,"CANH BAO");	
    
}

void button(int x1, int y1, int x2, int y2, int ID, char* s,int cochu, int clbar, int clw)
{
	setfillstyle(1,clbar);
	bar(x1,y1,x2,y2);
	setcolor(clw);
	setbkcolor(clbar);
	settextstyle(0,0,cochu);
	outtextxy(x1+10,y1+10,s);	
	taoID(x1,y1,x2,y2,ID);
}
void taoo(int x1,int y1,int x2, int y2, int ID,int mau, int mauvien)
{
	setfillstyle(1,mau);
	bar(x1,y1,x2,y2);
	setcolor(mauvien);
	rectangle(x1,y1,x2,y2);
	taoID(x1,y1,x2,y2,ID);
}
void taodong(int x1,int y1, int docao,int Mangdodai[], int mau, int mauvien,int ID , int socot)
{
	int y2= y1+docao;
	int	x2;
	
	for(int i=0;i<socot;i++)
	{
	    x2=x1+Mangdodai[i];
		taoo(x1,y1,x2,y2,ID,mau,mauvien);
		x1=x2;
	
	}
}
void taobang(int x1,int y1, int docao,int socot,int Mangdodai[], int mau, int mauvien,int soluong, int ID, int trang,char td[][50] )
{
	setcolor(0);
	setbkcolor(mau);
	settextstyle(0,0,2);
	int y=y1;
	for(int i=1;i<=soluong;i++)
	{
		taodong(x1,y1,docao,Mangdodai,mau, mauvien,ID+i,socot);
		if(i!=1)
		{
			char temp[4];
			itoa((i-1)+10*(trang-1),temp,10);
			outtextxy(x1+5,y1+5,temp);
		}
		y1=y1+docao;
		
	}
	for(int i=0;i<socot;i++)
	{
		outtextxy(x1+5,y+5,td[i]);
		x1=x1+Mangdodai[i];
	}	
}
void taobang1(int x1,int y1, int docao,int socot,int Mangdodai[], int mau, int mauvien,int soluong, int ID, int trang,char td[][50] )
{
	setcolor(0);
	setbkcolor(mau);
	settextstyle(0,0,2);
	int y=y1;
	for(int i=1;i<=soluong;i++)
	{
		taodong(x1,y1,docao,Mangdodai,mau, mauvien,ID+i,socot);
		y1=y1+docao;
		
	}
	for(int i=0;i<socot;i++)
	{
		outtextxy(x1+5,y+5,td[i]);
		x1=x1+Mangdodai[i];
	}	
}
void danhdau(int vt)
{
	setcolor(12);
	setbkcolor(15);
	settextstyle(0,0,2);
	int y1=245+35;
	for(int i=1;i<=10;i++)
	{
		
	    outtextxy(1300,y1," ");
		y1=y1+32;
		
		
	}
	outtextxy(1300,245+35+(vt-1)*32,"v");
		
}
void giaodiendau()
{
	khungChinh();
	button(6,30,270,90,1,"QUAN LY LOP HOC", 2,1,15);
	button(6,100,270,160,2,"QUAN LY LOP TC", 2,1,15);
	button(6,170,270,230,3,"QUAN LY MON HOC", 2,1,15);
	
}
void giaodiennhapthongtinqllh()
{
	button(6,30,270,90,1,"QUAN LY LOP HOC", 2,1,12);
	button(280,4,420,36,11,"Lop Hoc",2,1,12);
	button(425,4,590,36,12,"Sinh Vien",2,1,15);
	button(595,4,695,36,13,"Diem",2,1,15);
	
	button(285,40,425,72,111,"Ma Lop:",2,9,15);
	taoo(425,40,675,72,111,15,0);
	button(690,40,840,72,112,"Ten Lop:",2,9,15);
	taoo(840,40,1340,72,112,15,0);
	button(285,80,500,112,113,"Nam Nhap Hoc:",2,9,15);
	taoo(500,80,675,112,113,15,0);
    
    button(600,185,700,220,1110,"SAVE",2,2,0);
	button(710,185,810,220,1111," HUY",2,2,0);
	button(820,185,920,220,1112," NEW",2,2,0);
	button(925,185,1095,220,1113," CHI TIET",2,2,0);
	
	button(325,635,400,670,1114,"pver",2,1,3);
	button(1255,635,1330,670,1115,"next",2,1,3); 
}
void bangthongtinqllh(int trang)
{
	int m[]={100,220,450,280};
	char td[][50]={"STT","MA LOP","TEN LOP"," NAM NHAP HOC"};
	taobang(290,245,32,4,m,15,0,11,1100,trang,td);
}
void giaodiennhapthongtinqllh_SV()
{
	button(6,30,270,90,1,"QUAN LY LOP HOC", 2,1,12);
	button(280,4,420,36,11,"Lop Hoc",2,1,15);
	button(425,4,590,36,12,"Sinh Vien",2,1,12);
	button(595,4,695,36,13,"Diem",2,1,15);
	
	button(285,40,425,72,122,"Ma Lop:",2,9,15);
	taoo(425,40,675,72,122,15,0);
	
	button(690,40,840,72,122,"MSSV:",2,9,15);
	taoo(840,40,1100,72,122,15,0);
	
	button(285,80,345,112,123,"HO:",2,9,15);
	taoo(345,80,675,112,123,15,0);
	
	button(690,80,840,112,124,"TEN:",2,9,15);
	taoo(840,80,1100,112,124,15,0);
	
	button(1110,80,1220,112,125," NAM",2,9,15);
	button(1220,80,1320,112,126,"  NU",2,9,15);
	
    button(285,120,345,152,127,"SDT:",2,9,15);
	taoo(345,120,675,152,127,15,0);
	
	button(690,120,900,152,128,"NAM NHAP HOC:",2,9,15);
	taoo(900,120,1100,152,128,15,0);
    
    button(600,185,700,220,1110,"SAVE",2,2,0);
	button(710,185,810,220,1111," HUY",2,2,0);
	button(820,185,920,220,1112," NEW",2,2,0);
	button(925,185,1095,220,1113," CHI TIET",2,2,0);
	
	button(325,635,400,670,1114,"pver",2,1,3);
	button(1255,635,1330,670,1115,"next",2,1,3); 
}
void bangthongqllh_SV(int trang)
{
	int m[]={65,200,200,300,200,100};
	char td[][50]={"STT","MA LOP","MSSV","HO TEN","SDT","NNH"};
	taobang(280,245,32,6,m,15,0,11,1100,trang,td);// chua sua ID

}
void giaodienthongtinqllh_Diem()
{
		button(6,30,270,90,1,"QUAN LY LOP HOC", 2,1,12);
	button(280,4,420,36,11,"Lop Hoc",2,1,15);
	button(425,4,590,36,12,"Sinh Vien",2,1,15);
	button(595,4,695,36,13,"Diem",2,1,12);
	
	button(285,40,425,72,122,"Ma Lop:",2,9,15);
	taoo(425,40,675,72,122,15,0);
	
	button(690,40,840,72,122,"MSSV:",2,9,15);
	taoo(840,40,1100,72,122,15,0);
	
	button(285,80,345,112,123,"HO:",2,9,15);
	taoo(345,80,675,112,123,15,0);
	
	button(690,80,840,112,124,"TEN:",2,9,15);
	taoo(840,80,1100,112,124,15,0);
	
	button(1110,80,1220,112,125," NAM",2,9,15);
	button(1220,80,1320,112,126,"  NU",2,9,15);
	
    button(285,120,345,152,127,"SDT:",2,9,15);
	taoo(345,120,675,152,127,15,0);
	
	button(690,120,900,152,128,"NAM NHAP HOC:",2,9,15);
	taoo(900,120,1100,152,128,15,0);
    
//    button(600,185,700,220,1110,"SAVE",2,2,0);
//	button(710,185,810,220,1111," HUY",2,2,0);
//	button(820,185,920,220,1112," NEW",2,2,0);
//	button(925,185,1095,220,1113," CHI TIET",2,2,0);
	
	button(325,635,400,670,1114,"pver",2,1,3);
	button(1255,635,1330,670,1115,"next",2,1,3); 
}
void bangthongtinqllh_Diem(int trang)
{
	int m[]={100,220,250,290,190};
	char td[][50]={"STT","MA SINH VIEN","HO","TEN","DIEM TB"};
	taobang(290,245,32,5,m,15,0,11,1100,trang,td);
}
void giaodiennhapthongtinqlltc_loptc()
{
	giaodiendau();
	button(6,100,270,160,2,"QUAN LY LOP TC", 2,1,12);
	
	button(280,4,420,36,22,"Lop TC",2,1,12);
	button(425,4,590,36,22,"SV DK TC",2,1,15);
	button(595,4,755,36,23,"Diem LTC",2,1,15);
	button(760,4,930,36,24,"Sinh Vien",2,1,15);
	
	button(285,40,425,72,222,"Ma LTC:",2,9,15);
	taoo(425,40,675,72,222,15,0);
	
	button(690,40,840,72,222,"MA MH:",2,9,15);
	taoo(840,40,1100,72,222,15,0);
	
	button(285,80,455,112,223,"NIEN KHOA:",2,9,15);
	taoo(455,80,675,112,223,15,0);
	
	button(690,80,840,112,224,"HOC KY:",2,9,15);
	taoo(840,80,1100,112,224,15,0);
	
	button(1110,80,1220,112,225,"NHOM",2,9,15);
	taoo(1220,80,1340,112,225,15,0);

	
    button(285,120,425,152,226,"SV MAX:",2,9,15);
	taoo(425,120,675,152,226,15,0);
	
	button(690,120,840,152,227,"SV MIN:",2,9,15);
	taoo(840,120,1100,152,227,15,0);
    
   button(600,185,700,220,1110,"SAVE",2,2,0);
	button(710,185,810,220,1111," HUY",2,2,0);
	button(820,185,920,220,1112," NEW",2,2,0);
	button(925,185,1095,220,1113," CHI TIET",2,2,0);
	
	button(325,635,400,670,1114,"pver",2,1,3);
	button(1255,635,1330,670,1115,"next",2,1,3); 	
}
void bangthongtinqltc_loptc(int trang)
{
	int m[]={70,185,185,160,150,150,150};
	char td[][50]={"STT","  MLTC","  MMH","NIEN KHOA","HOC KY"," NHOM"," SL SV"};
	taobang(290,245,32,7,m,15,0,11,2200,trang,td);
}
void giaodiennhapthongtinqlltc_Sinhviendk()
{
	giaodiendau();
	button(6,100,270,160,2,"QUAN LY LOP TC", 2,1,12);
	
	button(280,4,420,36,21,"Lop TC",2,1,15);
	button(425,4,590,36,22,"SV DK TC",2,1,12);
	button(595,4,755,36,23,"Diem LTC",2,1,15);
	button(760,4,930,36,24,"Sinh Vien",2,1,15);
	
	button(285,40,425,72,222,"Ma LOP:",2,9,15);
	taoo(425,40,675,72,222,15,0);
	
	button(690,40,840,72,222,"LOP:",2,9,15);
	taoo(840,40,1100,72,222,15,0);
	
	button(285,80,455,112,223,"NIEN KHOA:",2,9,15);
	taoo(455,80,675,112,223,15,0);
	
	button(690,80,840,112,224,"HOC KY:",2,9,15);
	taoo(840,80,1100,112,224,15,0);
	
	button(1110,80,1220,112,225,"NHOM",2,9,15);
	taoo(1220,80,1340,112,225,15,0);

	
    button(285,120,425,152,226,"MSSV:",2,9,15);
	taoo(425,120,675,152,226,15,0);
	
	button(690,120,840,152,227,"TEN:",2,9,15);
	taoo(840,120,1100,152,227,15,0);
    
    button(600,185,700,220,1110,"SAVE",2,2,0);
	button(710,185,810,220,1111," HUY",2,2,0);
	button(820,185,920,220,1112," NEW",2,2,0);
	button(925,185,1095,220,1113," CHI TIET",2,2,0);
	
	button(325,635,400,670,1114,"pver",2,1,3);
	button(1255,635,1330,670,1115,"next",2,1,3); 	
}
void bangthongtinqltc_Sinhviendk(int trang)
{
	int m[]={70,185,185,160,150,150,150};
	char td[][50]={"STT","  MLTC","  MMH","NIEN KHOA","HOC KY"," NHOM"," SL SV"};
	taobang(290,245,32,7,m,15,0,11,2200,trang,td);
}
void giaodienqltc_Diem()
{
	giaodiendau();
	button(6,100,270,160,2,"QUAN LY LOP TC", 2,1,12);
	
	button(280,4,420,36,21,"Lop TC",2,1,15);
	button(425,4,590,36,22,"SV DK TC",2,1,15);
	button(595,4,755,36,23,"Diem LTC",2,1,12);
	button(760,4,930,36,24,"Sinh Vien",2,1,15);
	
	button(285,40,425,72,232,"MA LTC:",2,9,15);
	taoo(425,40,675,72,232,15,0);
	
	button(690,40,840,72,232,"MA MH:",2,9,15);
	taoo(840,40,1100,72,232,15,0);
	
	button(285,80,455,112,233,"NIEN KHOA:",2,9,15);
	taoo(455,80,675,112,233,15,0);
	
	button(690,80,840,112,234,"HOC KY:",2,9,15);
	taoo(840,80,1100,112,234,15,0);
	
	button(1110,80,1220,112,235,"NHOM",2,9,15);
	taoo(1220,80,1340,112,235,15,0);

    button(600,185,700,220,1110,"SAVE",2,2,0);
//	button(710,185,810,220,1111," HUY",2,2,0);
//	button(820,185,920,220,1112," NEW",2,2,0);
//	button(925,185,1095,220,1113," CHI TIET",2,2,0);
	
	button(325,635,400,670,1114,"pver",2,1,3);
	button(1255,635,1330,670,1115,"next",2,1,3); 	
}
void bangthongtinqltc_diem(int trang)
{
	int m[]={100,220,250,290,190};
	char td[][50]={"STT","MA SINH VIEN","HO","TEN","DIEM"};
	taobang(290,245,32,5,m,15,0,11,2300,trang,td);
}

void giaodiennhapthongtinqlltc_Sinhvien()
{
	giaodiendau();
	button(6,100,270,160,2,"QUAN LY LOP TC", 2,1,12);
	
	button(280,4,420,36,21,"Lop TC",2,1,15);
	button(425,4,590,36,22,"SV DK TC",2,1,15);
	button(595,4,755,36,23,"Diem LTC",2,1,15);
	button(760,4,930,36,24,"Sinh Vien",2,1,12);
	
	button(285,40,425,72,241,"MA LTC:",2,9,15);
	taoo(425,40,675,72,241,15,0);
	
	button(690,40,840,72,242,"MA MH:",2,9,15);
	taoo(840,40,1100,72,242,15,0);
	
	button(285,80,455,112,243,"NIEN KHOA:",2,9,15);
	taoo(455,80,675,112,243,15,0);
	
	button(690,80,840,112,244,"HOC KY:",2,9,15);
	taoo(840,80,1100,112,244,15,0);
	
	button(1110,80,1220,112,245,"NHOM",2,9,15);
	taoo(1220,80,1340,112,245,15,0);
		
	button(325,635,400,670,1114,"pver",2,1,3);
	button(1255,635,1330,670,1115,"next",2,1,3); 	
}
// coi lai*@@*

void bangthongtinqltc_Sinhvien(int trang)
{
    int m[]={100,220,250,290,190};
	char td[][50]={"STT","MA SINH VIEN","HO","TEN","DIEM"};
	taobang(290,245,32,5,m,15,0,11,2400,trang,td);
}
 void giaodienqlmh_qlmonhoc()
 {
 		giaodiendau();
 	button(6,170,270,230,3,"QUAN LY MON HOC", 2,1,12);
	button(280,4,420,36,31,"Mon Hoc",2,1,12);
	button(425,4,590,36,32,"Diem",2,1,15);

	button(285,40,425,72,311,"MA MH:",2,9,15);
	taoo(425,40,675,72,311,15,0);
	
	button(690,40,840,72,312,"TEN MH:",2,9,15);
	taoo(840,40,1100,72,312,15,0);
	
	button(285,80,455,112,313,"NIEN KHOA:",2,9,15);
	taoo(455,80,675,112,313,15,0);
	
	button(690,80,840,112,314,"HOC KY:",2,9,15);
	taoo(840,80,1100,112,314,15,0);
	
	button(600,185,700,220,1110,"SAVE",2,2,0);
	button(710,185,810,220,1111," HUY",2,2,0);
	button(820,185,920,220,1112," NEW",2,2,0);
//	button(925,185,1095,220,1113," CHI TIET",2,2,0);
	button(325,635,400,670,1114,"pver",2,1,3);
	button(1255,635,1330,670,1115,"next",2,1,3); 	
 }
 void bangthongtinqlmh_qlmonhoc(int trang)
 {
 	 int m[]={100,220,350,260,120};
	char td[][50]={"STT","MA MON HOC","TEN MH","NIEN KHOA","HOC KY"};
	taobang(290,245,32,5,m,15,0,11,3100,trang,td);
 }
 void giaodienqlmh_qldiem()
 {
 	giaodiendau();
 	button(6,170,270,230,3,"QUAN LY MON HOC", 2,1,12);
	button(280,4,420,36,31,"Mon Hoc",2,1,15);
	button(425,4,590,36,32,"Diem",2,1,12);

	button(285,40,425,72,321,"MA MH:",2,9,15);
	taoo(425,40,675,72,321,15,0);
	
	button(690,40,840,72,322,"TEN MH:",2,9,15);
	taoo(840,40,1100,72,322,15,0);
	
	button(285,80,455,112,323,"NIEN KHOA:",2,9,15);
	taoo(455,80,675,112,323,15,0);
	
	button(690,80,840,112,324,"HOC KY:",2,9,15);
	taoo(840,80,1100,112,324,15,0);
	
//	button(600,185,700,220,1110,"SAVE",2,2,0);
//	button(710,185,810,220,1111," HUY",2,2,0);
//	button(820,185,920,220,1112," NEW",2,2,0);
//	button(925,185,1095,220,1113," CHI TIET",2,2,0);
	button(325,635,400,670,1114,"pver",2,1,3);
	button(1255,635,1330,670,1115,"next",2,1,3); 	
 }
 void bangthongtinqlmh_qldiem(int trang)
 {
 	 int m[]={100,220,250,290,190};
	char td[][50]={"STT","MA SINH VIEN","HO","TEN","DIEM"};
	taobang(290,245,32,5,m,15,0,11,3200,trang,td);
 }
void Home(){
	setbkcolor(11);
	setcolor(COLOR(247,145,31));                   
    settextstyle(4,0,5);
    outtextxy(500,100,"LIBRARY MANAGER");
 	settextstyle(4,0,3);
 	settextjustify(0,0);  
 	outtextxy(670,325,"Tac gia:");
 	outtextxy(695,370,"PTIT HCM ");
 	outtextxy(695,420,"Ho Va ten - MaSinhVien");
 	setlinestyle(1,2,5);
 	line(555, 312, 660, 312);
 	line(807, 312, 1200, 312);
 	line(695, 450, 1300, 450);
 	setcolor(COLOR(255,0,0)); 
 	setbkcolor(11);
	setcolor(12);
	settextjustify(0,2);
	settextstyle(0,0,2);
	setlinestyle(0,1,1);
}

