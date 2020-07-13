#pragma once
#include "SinhVienDangKi.h"
#include <winbgim.h> 
struct LopTinChi{
	int MALOPTC;
	char MAMH[10];
	char NienKhoa[10];
	int HocKi;
	int Nhom;
	int minSV;
	int maxSV;
	DanhSachSinhVienDK dssvDangKi;
	
	int daDangKi=0;
};

struct NodeLopTinChi{
	LopTinChi lopTinChi;
	NodeLopTinChi *left;
	NodeLopTinChi *right;
};

struct CayLopTinChi{
	NodeLopTinChi *root=NULL;
	int soluong=0;
};

LopTinChi TaoLopTinChi(char MAMH[], int NienKhoa, int HocKi, int Nhom, int minSV, int maxSV);
NodeLopTinChi *TaoNodeLopTinChi(LopTinChi lopTinChiMoi);
void ThemNodeVaoCay(CayLopTinChi cayLopTinChi, NodeLopTinChi *nodeLopTinChiMoi);
NodeLopTinChi *TimNodeTheoMaLopTinChi(CayLopTinChi cayLopTinChi, int MALOPTC);
void CapNhatThongTinLopTinChi(NodeLopTinChi *nodeCanSua, int minSV, int maxSV);
NodeLopTinChi *NodeNhoNhatLonHon(NodeLopTinChi *nodeRoot, NodeLopTinChi *nodeChaKetQua);
void XoaLopTinChi(CayLopTinChi &cayLopTinChi, int MALOPTC);
void DangKiLopTinChi(CayLopTinChi &CayLopTinChi, int MALOPTC, char MASV[]);

LopTinChi TaoLopTinChi(char MAMH[], char NienKhoa[], int HocKi, int Nhom, int minSV, int maxSV){
	LopTinChi lopTinChiMoi;
	
	strcpy(lopTinChiMoi.MAMH, MAMH);
	strcpy(lopTinChiMoi.NienKhoa, NienKhoa);
	lopTinChiMoi.HocKi = HocKi;
	lopTinChiMoi.Nhom = Nhom;
	lopTinChiMoi.minSV = minSV;
	lopTinChiMoi.maxSV = maxSV;
	
	return lopTinChiMoi;
}

NodeLopTinChi *TaoNodeLopTinChi(LopTinChi lopTinChiMoi){
	NodeLopTinChi *nodeLopTinChiMoi = new NodeLopTinChi;
	
	nodeLopTinChiMoi->lopTinChi = lopTinChiMoi;
	nodeLopTinChiMoi->left=NULL;
	nodeLopTinChiMoi->right=NULL;
	
	return nodeLopTinChiMoi;
}

void ThemNodeVaoCay(CayLopTinChi &cayLopTinChi, NodeLopTinChi *nodeLopTinChiMoi){
	if(cayLopTinChi.root==NULL){
		cayLopTinChi.root = nodeLopTinChiMoi;
	}
	else{
		NodeLopTinChi *viTriCanThem = cayLopTinChi.root;
		NodeLopTinChi *truocViTriCanThem = cayLopTinChi.root;
		
		while(viTriCanThem!=NULL){
			truocViTriCanThem = viTriCanThem;
			if(nodeLopTinChiMoi->lopTinChi.MALOPTC<viTriCanThem->lopTinChi.MALOPTC){
				viTriCanThem = viTriCanThem->left;
			}
			else if(nodeLopTinChiMoi->lopTinChi.MALOPTC>viTriCanThem->lopTinChi.MALOPTC){
				viTriCanThem = viTriCanThem->right;
			}
		}
		
		if(nodeLopTinChiMoi->lopTinChi.MALOPTC<truocViTriCanThem->lopTinChi.MALOPTC){
			truocViTriCanThem->left = nodeLopTinChiMoi;
		}
		else if(nodeLopTinChiMoi->lopTinChi.MALOPTC>truocViTriCanThem->lopTinChi.MALOPTC){
			truocViTriCanThem->right = nodeLopTinChiMoi;
		}
	}
	cayLopTinChi.soluong++;
}

NodeLopTinChi *TimNodeTheoMaLopTinChi(CayLopTinChi cayLopTinChi, int MALOPTC){
	NodeLopTinChi *nodeCanTim = cayLopTinChi.root;
	
	while(nodeCanTim!=NULL){
		if(MALOPTC<nodeCanTim->lopTinChi.MALOPTC){
			nodeCanTim = nodeCanTim->left;
		}
		else if(MALOPTC>nodeCanTim->lopTinChi.MALOPTC){
			nodeCanTim = nodeCanTim->right;
		}
		else{
			return nodeCanTim;
		}
	}
}

void CapNhatThongTinLopTinChi(NodeLopTinChi *nodeCanSua, int minSV, int maxSV){
	nodeCanSua->lopTinChi.minSV = minSV;
	nodeCanSua->lopTinChi.maxSV = maxSV;
}

NodeLopTinChi *NodeNhoNhatLonHon(NodeLopTinChi *nodeRoot, NodeLopTinChi *nodeChaKetQua){
	NodeLopTinChi *nodeCanTim = nodeRoot->right;
	nodeChaKetQua = nodeRoot;
	
	while(nodeCanTim->left!=NULL){
		nodeChaKetQua = nodeCanTim;
		nodeCanTim = nodeCanTim->left;
	}
	
	return nodeCanTim;
}

void XoaLopTinChi(CayLopTinChi &cayLopTinChi, int MALOPTC){
	NodeLopTinChi *nodeCanXoa = cayLopTinChi.root;
	NodeLopTinChi *truocNodeCanXoa = cayLopTinChi.root;
	
	while(nodeCanXoa->lopTinChi.MALOPTC!=MALOPTC && nodeCanXoa!=NULL){
		truocNodeCanXoa = nodeCanXoa;
		if(MALOPTC<nodeCanXoa->lopTinChi.MALOPTC){
			nodeCanXoa = nodeCanXoa->left;
		}
		else if(MALOPTC>nodeCanXoa->lopTinChi.MALOPTC){
			nodeCanXoa = nodeCanXoa->right;
		}
	}
	
	if(nodeCanXoa!=NULL){
		//Khong co con
		if(nodeCanXoa->left==NULL && nodeCanXoa->right==NULL){
			if(nodeCanXoa->lopTinChi.MALOPTC<truocNodeCanXoa->lopTinChi.MALOPTC){
				truocNodeCanXoa->left=NULL;
			}
			else if(nodeCanXoa->lopTinChi.MALOPTC>truocNodeCanXoa->lopTinChi.MALOPTC){
				truocNodeCanXoa->right=NULL;
			}
			delete nodeCanXoa;
		}
		//Co con phai
		else if(nodeCanXoa->left==NULL){
			if(nodeCanXoa->lopTinChi.MALOPTC<truocNodeCanXoa->lopTinChi.MALOPTC){
				truocNodeCanXoa->left=nodeCanXoa->right;
			}
			else if(nodeCanXoa->lopTinChi.MALOPTC>truocNodeCanXoa->lopTinChi.MALOPTC){
				truocNodeCanXoa->right=nodeCanXoa->right;
			}
			delete nodeCanXoa;
		}
		//Co con trai
		else if(nodeCanXoa->right==NULL){
			if(nodeCanXoa->lopTinChi.MALOPTC<truocNodeCanXoa->lopTinChi.MALOPTC){
				truocNodeCanXoa->left=nodeCanXoa->left;
			}
			else if(nodeCanXoa->lopTinChi.MALOPTC>truocNodeCanXoa->lopTinChi.MALOPTC){
				truocNodeCanXoa->right=nodeCanXoa->left;
			}
			delete nodeCanXoa;
		}
		//Co du hai con
		else{
			NodeLopTinChi *truocNodeThayThe;
			NodeLopTinChi *nodeThayThe = NodeNhoNhatLonHon(nodeCanXoa, truocNodeThayThe);
			
			nodeCanXoa->lopTinChi = nodeThayThe->lopTinChi;
			
			if(nodeThayThe->lopTinChi.MALOPTC<truocNodeThayThe->lopTinChi.MALOPTC){
				if(nodeThayThe->right!=NULL) truocNodeThayThe->left=nodeThayThe->right;
				else truocNodeThayThe->left=NULL;
			}
			else if(nodeThayThe->lopTinChi.MALOPTC>truocNodeCanXoa->lopTinChi.MALOPTC){
				if(nodeThayThe->right!=NULL) truocNodeThayThe->right=nodeThayThe->right;
				else truocNodeThayThe->right=NULL;
			}
			delete nodeThayThe;
		}
		cayLopTinChi.soluong--;
	}
}

void DangKiLopTinChi(CayLopTinChi &cayLopTinChi, int MALOPTC, char MASV[]){
	NodeLopTinChi *lopTinChiCanThem = TimNodeTheoMaLopTinChi(cayLopTinChi, MALOPTC);
	
	ThemSinhVienDKVaoCuoi(lopTinChiCanThem->lopTinChi.dssvDangKi, TaoNodeSinhVienDK(TaoSinhVienDK(MASV, 0)));
	lopTinChiCanThem->lopTinChi.daDangKi++;
}
