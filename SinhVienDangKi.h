#include <winbgim.h> 
#include <string.h> 
struct SinhVienDK{
	char MASV[12];
	float DIEM;
};

struct NodeSinhVienDK{
	SinhVienDK sinhVienDK;
	NodeSinhVienDK *next;
};

struct DanhSachSinhVienDK{
	NodeSinhVienDK *first=NULL;
	int soluong=0;
};

SinhVienDK TaoSinhVienDK(char MASV[], float DIEM);
NodeSinhVienDK *TaoNodeSinhVienDK(SinhVienDK sinhVienDKMoi);
void ThemSinhVienDKVaoCuoi(DanhSachSinhVienDK &dsSinhVienDK, NodeSinhVienDK *nodeSinhVienDKMoi);

SinhVienDK TaoSinhVienDK(char MASV[], float DIEM){
	SinhVienDK sinhVienDKMoi;
	
	strcpy(sinhVienDKMoi.MASV, MASV);
	sinhVienDKMoi.DIEM = DIEM;
	
	return sinhVienDKMoi;
}

NodeSinhVienDK *TaoNodeSinhVienDK(SinhVienDK sinhVienDKMoi){
	NodeSinhVienDK *nodeSinhVienDKMoi = new NodeSinhVienDK;
	
	nodeSinhVienDKMoi->sinhVienDK = sinhVienDKMoi;
	nodeSinhVienDKMoi->next = NULL;
	
	return nodeSinhVienDKMoi;
}

void ThemSinhVienDKVaoCuoi(DanhSachSinhVienDK &dsSinhVienDK, NodeSinhVienDK *nodeSinhVienDKMoi){
	if(dsSinhVienDK.first==NULL){
		dsSinhVienDK.first=nodeSinhVienDKMoi;
	}
	else{
		NodeSinhVienDK *viTriCanThem = dsSinhVienDK.first;
		
		while (viTriCanThem->next!=NULL){
			viTriCanThem = viTriCanThem->next;
		}
		
		viTriCanThem->next = nodeSinhVienDKMoi;
	}
	dsSinhVienDK.soluong++;
}
