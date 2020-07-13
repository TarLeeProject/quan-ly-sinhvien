#pragma once
#include<iostream>
#include<string.h>
#include <winbgim.h> 
const int MAXDS =300;
using namespace std;
struct MonHoc{
	char MAMH[10];
	char TENMH[30];
	int STCLT;
	int STCTH;
};
struct DSMonHoc{
	int num=0;
	MonHoc *DSMH[MAXDS];
};
void init_DSMH(DSMonHoc &ds)
{
	ds.num=0;
	for(int i=0;i<MAXDS;i++)
	{
		ds.DSMH[i]=NULL;
	}
}
MonHoc newdataMonHoc(char MaMH[], char TenMH[],int STCLT, int STCTH)
{
	MonHoc temp;
	strcpy(temp.MAMH,MaMH);
	strcpy(temp.TENMH,TenMH);
	temp.STCLT=STCLT;
	temp.STCTH=STCTH;
	return temp;
}
void insert_MH(MonHoc data, DSMonHoc &ds)
{
	ds.DSMH[ds.num]=new MonHoc;
	*ds.DSMH[ds.num]=data;
	ds.num++;
}
// check dk mh co the sua

void sua_MH(DSMonHoc &ds,int vt,MonHoc data)
{
	*ds.DSMH[vt]=data;
}
// check ddk de xoa
void del_MH(DSMonHoc &ds,int vt)
{
	if(vt==-1)
	return;
	else
	{
		for(int i=vt;i<ds.num-1;i++)
		{
			ds.DSMH[i]=ds.DSMH[i+1];
		}
		delete ds.DSMH[ds.num-1];
		ds.num--;
	}
}

