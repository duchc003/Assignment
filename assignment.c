#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#define sl 100

struct Date
{
    int day;
    int month;
    int year;
};
typedef struct Date date;
struct NhanVien
{
    int msnv;
    char ho[20];
    char ten[20];
    date namSinh;
    char noiSinh[100];
    char diaChi[200];
    float luong;
    date ngayVao;
};
typedef struct NhanVien nhanVien;
struct DanhSach
{
    nhanVien a[sl];
    int n;
};
typedef struct DanhSach danhSach;

void nhapNgayThang(date ntn)
{
}
void nhapMotNhanVien(nhanVien nv)
{
    // printf("Vui long nhap nhan vien:")
    // for (int i = 0; i < count; i++)
    // {
    //     /* code */
    // }
}
void xuatMotNhanVien(nhanVien nv)
{
}

void nhapDanhSach(danhSach ds)
{
}
void xuatDanhSach(danhSach ds)
{
}
int timTen(danhSach ds, char *c)
{
}
void themNV(danhSach ds, nhanVien x, int k)
{
}
int timMSNV(danhSach ds, int d)
{
}
void xoanv(danhSach ds, int d)
{
}
void sapXep(danhSach ds)
{
}
void menu()
{
    int ch;
    int d, k;
    // danhSach ds;
    // nhanVien nv;
    // nhapDanhSach(ds);
    // xuatDanhSach(ds);
    printf("\n\t\t================MENU================");
    printf("\n\t1. Thêm vào một nhân viên");
    printf("\n\t2.TÌm nhân viên thoe mã số");
    printf("\n\t3.Tìm nhân viên theo tên");
    printf("\n\t4.Bảng lương của nhân viên giám sát");
    printf("\n\t5.Xóa 1 nhân viên");
    printf("\n ****************************************");
    printf("\n\t chọn 1 trong chức năng trên: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        break;

    default:
        break;
    }
}

int main()
{
    menu();
}