#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#define sl 100

// khai báo thời gian
typedef struct Date date;
struct Date
{
    int day;
    int month;
    int year;
};

// khai báo nhân viên
typedef struct NhanVien nhanVien;
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

// khai báo danh sách nhân viên
typedef struct DanhSach danhSach;
struct DanhSach
{
    nhanVien a[sl];
    int n;
};

// method nhập ngày tháng
void nhapNgayThang(date ntn)
{
}

// method nhập một nhân viên
void nhapMotNhanVien(nhanVien nv)
{
    printf("\nMoi ban nhap ma so nhan vien: ");
    scanf("%d", &nv.msnv);
    printf("\nMoi ban nhap ho nhan vien: ");
    scanf("%s", &nv.ho);
    printf("\nMoi ban nhap ten nhan vien: ");
    scanf("%s", &nv.ten);
    printf("\nMoi ban nhap nam sinh nhan vien: ");
    scanf("%d%d%d", &nv.namSinh.day, &nv.namSinh.month, &nv.namSinh.year);
    printf("\nMoi ban nhap noi sinh nhan vien: ");
    scanf("%s", &nv.noiSinh);
    printf("\nMoi ban nhap dia chi nhan vien: ");
    scanf("%s", &nv.diaChi);
    printf("\nMoi ban nhap luong nhan vien: ");
    scanf("%f", &nv.luong);
    printf("\nMoi ban nhap ngay vao lam nhan vien: ");
    scanf("%d%d%d", &nv.ngayVao.day, &nv.ngayVao.month, &nv.ngayVao.year);
}

// method xuất một nhân viên
void xuatMotNhanVien(nhanVien nv)
{
    printf("Ma so nhan vien la: %d\n", nv.msnv);
    printf("Ho ten nhan vien la: %s %s\n", nv.ho, nv.ten);
    printf("Ngay thang nam sinh cua nhan vien la: %02d %02d %02d\n", nv.namSinh.day, nv.namSinh.month, nv.namSinh.year);
    printf("Noi sinh nhan vien la: %s\n", nv.noiSinh);
    printf("Dia chi nhan vien la: %s\n", nv.diaChi);
    printf("Luong cua nhan vien la: %f\n", nv.luong);
    printf("Ngay vao lam cua nhan vien la: %02d %02d %02d\n", nv.ngayVao.day, nv.ngayVao.month, nv.ngayVao.year);
}

// method nhập một danh sách nhân viên
void nhapDanhSach(danhSach ds)
{
}

// method xuất một danh sách nhân viên
void xuatDanhSach(danhSach ds)
{
}

// method tìm kiếm nhân viên
int timTen(danhSach ds, char *c)
{
}

// method thêm nhân viên
void themNV(danhSach ds, nhanVien x, int k)
{
}

// method tìm mã số nhân viên
int timMSNV(danhSach ds, int d)
{
}

// method xóa nhân viên
void xoanv(danhSach ds, int d)
{
}

// method sắp xếp nhân viên
void sapXep(danhSach ds)
{
}

// khai báo menu
void menu()
{
    do
    {
        int ch;
        int d, k;
        nhanVien nv;
        printf("\n\t\t================MENU================");
        printf("\n\t1. Them Vao Mot Nhan Vien");
        printf("\n\t2. Xuat mot nhan vien");
        printf("\n\t3.Tim nhan vien theo ten ");
        printf("\n\t4.bang luong cua nhan vien giam sat");
        printf("\n\t5.xoa mot nhan vien");
        printf("\n ****************************************");
        printf("\n\t Chon 1 trong cac chuc nang tren: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n\tBan da lua chon chuc nang 1\n");
            nhapMotNhanVien(nv);
            break;
        case 2:
            printf("\n\tBan da lua chon chuc nang 2\n");
            xuatMotNhanVien(nv);
            break;
        case 3:
            printf("\n\tBan da lua chon chuc nang 3\n");
            break;
        case 4:
            printf("\n\tBan da lua chon chuc nang 4\n");
            break;
        case 5:
            printf("\n\tBan da lua chon chuc nang 5\n");
            break;
        case 0:
            printf("\nHen Gap Lai ban lan sau \n");
            return;
        default:
            printf("Ban chua lua chon chuong trinh\n");
            break;
        }
    } while (1);
}

int main()
{
    menu();
}