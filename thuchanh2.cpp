#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include<string.h>
using namespace std;
struct thuVien
{
    char maSach[100];
    char tenSach[100];
    char tacGia[100];
    int soLuong;
};
typedef thuVien TV;
void nhapSach(TV a[100], int &n)
{
    do
    {
        cout << "Nhap vao so sach :";
        cin >> n;

    } while (n > 50);

    for (int i = 1; i <= n; i++)
    {

        cout << "Nhap vao thong tin sach thu: " << i << "\n";
    NhapLai:
        cout << "Ma sach:\n";
        fflush(stdin);
        while (cin.getline(a[i].maSach, 30))
        {
            int count = 0;
            for (int j = 0; j < i; j++)
            {
                if (strcmp(a[i].maSach, a[j].maSach) == 0)
                {
                    count++;
                }
            }
            if (count == 0)
            {
                break;
            }
            else
            {
                cout << "\nMa sach da ton tai! \n";
                goto NhapLai;
            }
        }
        cout << " Nhap Ten sach:\n";
        fflush(stdin);
        gets(a[i].tenSach);
        cout << " Nhap Tac gia: \n";
        fflush(stdin);
        gets(a[i].tacGia);
        cout << "Nhap So Luong";
        cin >> a[i].soLuong;
    }
}
void xuatSach(TV a[], int n)
{
    cout << "\n ----------------THONG TIN SACH:-------------- \n";
    cout << "Ma sach : \t \t Ten sach :\t \t Tac gia : \t \t So luong: \t";
    for (int i = 1; i <= n; i++)
    {
        cout << setw(10) << a[i].maSach;
        cout << setw(20) << a[i].tenSach;
        cout << setw(20) << a[i].tacGia;
        cout << setw(20) << a[i].soLuong << endl;
    }
}

void SapXepTangDan(TV a[], int n)
{
    TV temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(a[i].maSach, a[j].maSach) == 1)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main(int argc, char **argv)
{
    TV A[100];
    int n;
    nhapSach(A, n);
    SapXepTangDan(A, n);
    xuatSach(A, n);
}
