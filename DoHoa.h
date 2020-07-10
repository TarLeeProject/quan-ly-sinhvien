#pragma once
//abc
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
