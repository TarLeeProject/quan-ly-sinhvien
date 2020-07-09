#include<iostream>
#include<string.h>
using namespace std;
struct SinhVien{
	char MASV[12];
	char HO[30];
	char TEN[30];
	char PHAI[5];
	char SDT[13];
	char MALOP[15];
	
};
struct NodeDSSV
{
    SinhVien data;
    NodeDSSV *pNext;
};

struct DSSinhVien{
	NodeDSSV *pHead;
	NodeDSSV *pTail;
};
void init_DSSV(DSSinhVien &ds)
{
	ds.pHead=ds.pTail=NULL;
}
SinhVien newdataSV(char MSV[],char Ho[], char Ten[], char Phai[],char SDT[], char MaLop[])
{
	SinhVien temp;
	strcpy(temp.MALOP,MaLop);
	strcpy(temp.MASV,MSV);
	strcpy(temp.HO,Ho);
	strcpy(temp.TEN,Ten);
	strcpy(temp.SDT,SDT);
	strcpy(temp.PHAI,Phai);
	return temp;
}
NodeDSSV *newNodeSV(SinhVien data)
{
	NodeDSSV *temp=new NodeDSSV;
	temp->data=data;
	temp->pNext=NULL;
	return temp;
}
void insert_SV(DSSinhVien &ds, SinhVien data)
{
	NodeDSSV *p;
	p=newNodeSV(data);
	if(ds.pHead==NULL)
	{
		ds.pHead=p;
		return;
	}
	else
	{
		NodeDSSV *f=NULL, *f1=NULL;
		
		for(NodeDSSV *k= ds.pHead; k!=NULL;k=k->pNext)
		{
			if(strcmp(k->data.MALOP,data.MALOP)==0)
			{
				
				if(strcmp(k->data.MASV,data.MASV)<0)
				{
					f1=k;
				}
			}
			else if(strcmp(k->data.MALOP,data.MALOP)<0)
			{
			f=k;	
			}
		}
		if(f==NULL&&f1==NULL)
		{
			p->pNext=ds.pHead;
			ds.pHead=p;
			return;
		}
		else if(f!=NULL&&f1==NULL)
		{
			p->pNext=f->pNext;
			f->pNext=p;
			return;
		}
		else if(f1!=NULL)
		{
			p->pNext=f1->pNext;
			f1->pNext=p;
			return;
		}
		
	}
}
void del_SV(DSSinhVien &ds, char MSV[])
{
	for(NodeDSSV *k= ds.pHead; k!=NULL;k=k->pNext)
		{
			if(strncmp(k->pNext->data.MASV,MSV,strlen(MSV))==0)
			{
				if(k->pNext->pNext==NULL)
				{
					NodeDSSV *t=k->pNext;
					k->pNext=NULL;
					delete t;
					return;
					
				}
			}
			if(strncmp(k->data.MASV,MSV,strlen(MSV))==0)
			{

				NodeDSSV *t=k->pNext;
				k->data=k->pNext->data;
				k->pNext=k->pNext->pNext;
				delete t;
				return;
			}
		}
}
void sua_SV(DSSinhVien &ds, SinhVien data, char Masv[])
{
	for(NodeDSSV *k= ds.pHead; k!=NULL;k=k->pNext)
		{
			if(strcmp(k->data.MASV,Masv)==0)
			{
				k->data=data;
				return;
			}
		}
	
}
void Print_SV(DSSinhVien ds)
{
		while(ds.pHead!=NULL)
	{
		cout<<"\n"<<ds.pHead->data.MALOP<<"  "<<ds.pHead->data.MASV;
		ds.pHead=ds.pHead->pNext;
	}
}

