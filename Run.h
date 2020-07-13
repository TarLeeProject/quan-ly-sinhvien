#include "XuLy.h"
void run()
{
	int x,y;
	int key;
	bool trangthailuu=false;// luu khi sua// true luu khi them
	while(1)
	{
		delay(1);
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN,x,y);
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if(x==-1&&y==-1) continue;
		int key=MID[x][y];
	    trolai:
		switch(key)
		{
			case 1:
			{
			    while(1)
				{
					delay(1);
					if(ismouseclick(WM_LBUTTONDOWN))
					{
						getmouseclick(WM_LBUTTONDOWN,x,y);
						clearmouseclick(WM_LBUTTONDOWN);
					}
					if(x==-1&&y==-1) continue;
					int key=MID[x][y];
					//swich
//	    trolai:
				}
				break;
			}
			case 2:
			{
				
				break;
			}
			case 3:
			{
				
				break;
			}
		}
	}
	
	
}

