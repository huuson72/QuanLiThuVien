#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
using namespace std;
struct SACH{
	char MaSach[30];
	char TenSach[30];
	char TacGia[30];
	int SoLuong;
};

void NhapN(SACH a[], int n){
	for(int i=0;i<n;i++){
		cout<<"\nNhap thong tin sach thu "<<i+1<<" :\n";
		InputAgain:
		cout<<"Nhap ma sach: ";
		fflush(stdin);
		while(cin.getline(a[i].MaSach, 30)){
			int count=0;
			for(int j=0;j<i;j++){
				if(strcmp(a[j].MaSach,a[i].MaSach)==0){
					count++;
				}
			}
			if(count==0){
				break;
			}else{
				cout<<"\nMa sach da ton tai!!\n";
				goto InputAgain;
			}
		}
		cout<<"Nhap ten sach: ";
		fflush(stdin);
		cin.getline(a[i].TenSach, 30);
		cout<<"Nhap tac gia: ";
		fflush(stdin);
		cin.getline(a[i].TacGia, 30);
		cout<<"Nhap so luong: ";
		cin>>a[i].SoLuong;	
	}
}

void InThongTin(SACH a[], int n){
	cout<<"\n\nTHONG TIN SACH\n";
	for(int i=0;i<n;i++){
		cout<<setw(15)<<a[i].MaSach;
		cout<<setw(20)<<a[i].TenSach;
		cout<<setw(20)<<a[i].TacGia;
		cout<<setw(5)<<a[i].SoLuong<<endl;
	}
}

int compare(char *st1, char *st2){
	if(strcmp(st1, st2)==0){
		return 0;
	}else if(strcmp(st1, st2)>0){
		return 1;
	}else{
		return -1;
	}
}
void SapXepTangDan(SACH a[], int n){
	SACH temp;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(compare(a[i].MaSach, a[j].MaSach)==1){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
void GhiVaoFile(SACH a[], int n){
	ofstream file;
	file.open("text.txt", ios::out);
	int res=a[n].SoLuong;
	for(int i=n;i>=0;i++){
		if(a[i].SoLuong==res){
			file<<setw(15)<<a[i].MaSach;
			file<<setw(20)<<a[i].TenSach;
			file<<setw(20)<<a[i].TacGia;
			file<<setw(5)<<a[i].SoLuong<<endl;	
		}
	}
	file.close();
}
int main(int argc, char** argv) {
	int n;
	cout<<"Nhap so luong sach: ";cin>>n;
	SACH a[n];
	NhapN(a, n);
	SapXepTangDan(a, n);
	InThongTin(a, n);
	return 0;
}
