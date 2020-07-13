#include<iostream>
#include<fstream>
#include<ctime>
#include<string.h>
#include <winbgim.h> 
#include "LopTinChi.h"
#include "MonHoc.h"
#include "SinhVien.h"
//#include "SinhVienDangKi.h"
#include "DoHoa.h"
using namespace std;
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
