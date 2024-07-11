#include "mylib.h"

struct MonHoc {
	char MaMH[11]; char TenMH[51];
	int STCLT, STCTH;
};
struct nodeMonHoc {
	MonHoc mh;
	struct nodeMonHoc *left;
	struct nodeMonHoc *right;
};
typedef nodeMonHoc *PTRMH;
// dang ki LTC - lk don
struct DangKy {
	char MaSV[16];
	int TrangThai = 1;
	float Diem;
};
struct nodeDangKy {
	DangKy dk;
	nodeDangKy *next;
};
typedef nodeDangKy *PTRDK;
// Danh sach LTC - danh sach tuyen tinh
struct LopTinChi {
	int MaLopTC;
	char MaMH[11];
	char NienKhoa[10];
	int HocKy, Nhom, SoSVMin, SoSVMax;
	int TrangThaiLTC = 1;
	PTRDK FirstDK = NULL;
};
const int MaxLTC = 10000;
struct DSLTC {
	LopTinChi *nodes[MaxLTC];
	int n = 0;
};
// Danh sach SV - danh sach tuyen tinh
struct SinhVien {
	char MaSV[16];
	char Ho[51];
	char Ten[11];
	char Phai[4];
	char SoDT[15];
	char MaLop[16];
};
const int MaxSV = 5000;
struct DSSV 
{
	SinhVien nodes[MaxSV];
	int n = 0;
};
// int main () {
// 	PTRMH tree_mh = NULL;
// 	DSLTC dsltc;
// 	DSSV dssv;
// }

