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
void nhapNgayThang(date *ntn)
{
    printf("Nhap ngay: ");
    scanf("%d", &ntn->day);
    fflush(stdin);
    printf("Nhap thang: ");
    scanf("%d", &ntn->month);
    fflush(stdin);
    printf("Nhap nam: ");
    scanf("%d", &ntn->year);
    fflush(stdin);
}

void xuatngaythang(date ntn)
{
    printf("%d/%d/%d\n", ntn.day, ntn.month, ntn.year);
}

// method nhập một nhân viên
void nhapMotNhanVien(nhanVien *nv)
{
    printf("\nMoi ban nhap ma so nhan vien: ");
    scanf("%d", &nv->msnv);
    // Xóa bộ đệm đầu vào trước khi đến dòng nhập tiếp theo
    fflush(stdin);
    printf("\nMoi ban nhap ho nhan vien: ");
    scanf("%s", &nv->ho);
    fflush(stdin);
    printf("\nMoi ban nhap ten nhan vien: ");
    scanf("%s", &nv->ten);
    fflush(stdin);
    nhapNgayThang(&nv->namSinh);
    printf("\nMoi ban nhap noi sinh nhan vien: ");
    scanf("%s", &nv->noiSinh);
    fflush(stdin);
    printf("\nMoi ban nhap dia chi nhan vien: ");
    scanf("%s", &nv->diaChi);
    fflush(stdin);
    printf("\nMoi ban nhap luong nhan vien: ");
    scanf("%f", &nv->luong);
    fflush(stdin);
    nhapNgayThang(&nv->ngayVao);
}

void themNhanVien(danhSach *ds, int viTriThem, nhanVien giaTriThem)
{
    if (ds->n >= sl)
    {
        printf("\nDanh sach da day, khong the them nhan vien!");
        return;
    }
    if (viTriThem < 0 || viTriThem > ds->n)
    {
        printf("Vi tri them khong hop le!");
        return;
    }
    if (viTriThem < ds->n)
    {
        for (int i = ds->n; i > viTriThem; i--)
        {
            ds->a[i] = ds->a[i - 1];
        }
    }
    ds->a[viTriThem] = giaTriThem;
    ds->n++;
}

// method xuất một nhân viên
void xuatMotNhanVien(nhanVien nv)
{
    printf("Ma so nhan vien la: %d\n", nv.msnv);
    printf("Ho ten nhan vien la: %s %s\n", nv.ho, nv.ten);
    printf("Ngay sinh:");
    xuatngaythang(nv.namSinh);
    printf("Noi sinh nhan vien la: %s\n", nv.noiSinh);
    printf("Dia chi nhan vien la: %s\n", nv.diaChi);
    printf("Luong cua nhan vien la: %f\n", nv.luong);
    printf("Ngay vao:");
    xuatngaythang(nv.ngayVao);
}

// method nhập một danh sách nhân viên
void nhapDanhSach(danhSach *ds)
{
    printf("Nhap so luong nhan vien: ");
    scanf("%d", &ds->n);

    for (int i = 0; i < ds->n; i++)
    {
        printf("\nNhap thong tin cho nhan vien thu %d:\n", i + 1);
        nhapMotNhanVien(&ds->a[i]);
    }
}

// method xuất một danh sách nhân viên
void xuatDanhSach(danhSach ds)
{
    printf("Danh Sach Nhan Vien:\n");
    for (int i = 0; i < ds.n; i++)
    {
        xuatMotNhanVien(ds.a[i]);
    }
}

// method tìm kiếm nhân viên
int timTen(danhSach ds)
{
    char tenCanTim[20];
    printf("Vui long nhap ten can tim: ");
    scanf("%s", tenCanTim);
    fflush(stdin);
    for (int i = 0; i < ds.n; i++)
    {
        if (strcasecmp(ds.a[i].ten, tenCanTim) == 0)
        {
            xuatMotNhanVien(ds.a[i]);
        }
    }
    return 0;
}

// method thêm nhân viên

// method tìm mã số nhân viên
int timMSNV(danhSach ds, int d)
{
    for (int i = 0; i < ds.n; i++)
    {
        if (ds.a[i].msnv == d)
        {
            return i;
        }
        return -1;
    }
}

// method xóa nhân viên
void xoanv(danhSach ds, int d)
{
    for (int i = 0; i < ds.n; i++)
    {
        if (ds.a[i].msnv == d)
        {
            for (int j = 0; i < ds.n - 1; i++)
            {
                ds.a[j] = ds.a[j + 1];
            }
            ds.n--;
            printf("Da xoa nhan vien co ma so %d", d);
            return;
        }
    }
}

// method sắp xếp nhân viên
void sapXep(danhSach ds)
{
    nhanVien temp;
    for (int i = 0; i < ds.n - 1; i++)
    {
        for (int j = 0; j < ds.n - i - 1; j++)
        {
            if (ds.a[j].luong < ds.a[j + 1].luong)
            {
                temp = ds.a[j];
                ds.a[j] = ds.a[j + 1];
                ds.a[j + 1] = temp;
            }
        }
    }
}

// khai báo menu
void menu()
{
    do
    {
        int ch;
        int d, k;
        nhanVien nv;
        danhSach ds;
        printf("\n\t\t================MENU================");
        printf("\n\t1. Them Vao Mot Nhan Vien");
        printf("\n\t2. Tim nhan vien theo ma so");
        printf("\n\t3.Tim nhan vien theo ten ");
        printf("\n\t4.bang luong cua nhan vien giam dan");
        printf("\n\t5.xoa mot nhan vien");
        printf("\n ****************************************");
        printf("\n\t Chon 1 trong cac chuc nang tren: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n\tBan da lua chon chuc nang 1\n");
            nhapDanhSach(&ds);
            // printf("Moi ban nhap vi tri them:");
            // scanf("%d", &k);
            // themNhanVien(&ds, k, nv);
            xuatDanhSach(ds);
            break;
        case 2:
            printf("\n\tBan da lua chon chuc nang 2\n");
            scanf("%d", &d);
            k = timMSNV(ds, d);
            if (k == -1)
            {
                printf("\n khong tim thay nhan vien co ma la %d", d);
            }
            else
            {
                xuatMotNhanVien(ds.a[k]);
            }

            break;
        case 3:
            printf("\n\tBan da lua chon chuc nang 3\n");
            timTen(ds);
            break;
        case 4:
            printf("\n\tBan da lua chon chuc nang 4\n");
            sapXep(ds);
            xuatDanhSach(ds);
            break;
        case 5:
            printf("\n\tBan da lua chon chuc nang 5\n");
            printf("Moi ban nhap nhan vien can xoa:");
            scanf("%d", &d);
            xoanv(ds, d);
            xuatDanhSach(ds);
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