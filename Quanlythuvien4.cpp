#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
using namespace std;
class Sach{
	protected:
		string Masach;
		string Tensach;
		string Chude;
		string Tacgia;
		string Nhaxb;
		int Ngayxb,Thangxb,Namxb;
		int Sotrang;
		int Sobanluuthuvien;
	public:
		int Thudulieu(Sach *&ds,int &sl);
		void print();
		void print(Sach *ds,int sl);
		void Thongke(Sach *ds,int sl);
		void Timkiem(Sach *ds,int sl);
		void save(Sach *ds,int sl);
};
//Lop muonve
class Muonve:private Sach{
	private:
		int Ngaymuon,Thangmuon,Nammuon;
		int Ngaytra,Thangtra,Namtra;
	public:
		int Thudulieu(Muonve *&ds,int &sl);
		void print();
		void print(Muonve *ds,int sl);
		void Thongke(Muonve *ds,int sl);
		void Timkiem(Muonve *ds,int sl);
		void save(Muonve *ds,int sl);
};
//Lop muondoc
class Muondoc:private Sach{
	private:
		int Giomuon,Giotra;
		int Phutmuon,Phuttra;
	public:
		int Thudulieu(Muondoc *&ds,int &sl);
		void print();
		void print(Muondoc *ds,int sl);
		void Thongke(Muondoc *ds,int sl);
		void Timkiem(Muondoc *ds,int sl);
		void save(Muondoc *ds,int sl);
};
int check(int ngay,int thang,int nam);
int check(int nam);
int check(int ngay1,int thang1,int nam1,int ngay2,int thang2,int nam2);
int check(int Gio1,int Phut1,int Gio2,int Phut2);
int check(int Gio,int Phut);
void MENU();
int main(){
	system("color f0");
	int sl1=0,sl2=0,sl3=0;
	Sach *ds1=new Sach[sl1];
	Muonve *ds2=new Muonve[sl2];
	Muondoc *ds3=new Muondoc[sl3];
	int i=0;
	int chucnang;
	while(!i){
		MENU();
		cout<<setw(5)<<""<<"Nhap chuc nang ban muon: "; cin>>chucnang;
		system("cls");
		switch(chucnang)
		{
			case 1:
				ds1->Thudulieu(ds1,sl1);
				cout<<"\n\n\n\n";
				cout<<setw(5)<<"";
				system("pause");
	            system("cls");
				break;
			case 2:
				ds2->Thudulieu(ds2,sl2);
				cout<<"\n\n\n\n";
				cout<<setw(5)<<"";
				system("pause");
	            system("cls");
				break;
			case 3:
				ds3->Thudulieu(ds3,sl3);
				cout<<"\n\n\n\n";
				cout<<setw(5)<<"";
				system("pause");
	            system("cls");
				break;
			case 4:
				ds1->print(ds1,sl1);
				break;
			case 5:
				ds2->print(ds2,sl2);
				break;
			case 6:
				ds3->print(ds3,sl3);
				break;
			case 7:
				ds1->Thongke(ds1,sl1);
				break;
			case 8:
				ds2->Thongke(ds2,sl2);
				break;
			case 9:
				ds3->Thongke(ds3,sl3);
				break;
			case 10:
				ds1->Timkiem(ds1,sl1);
				break;
			case 11:
				ds2->Timkiem(ds2,sl2);
				break;
			case 12:
				ds3->Timkiem(ds3,sl3);
				break;
			case 13:
				ds1->save(ds1,sl1);
				break;
			case 14:
				ds2->save(ds2,sl2);
				break;
			case 15:
				ds3->save(ds3,sl3);
				break;
			case 0:
				i=1;
				break;
			default:
				cout<<setw(5)<<""<<"Chuc nang khong co trong menu!"<<endl;
				cout<<"\n\n\n\n";
				cout<<setw(5)<<"";
				system("pause");
	            system("cls");
		}
	}
}
int check(int ngay,int thang,int nam){
	int i=0;
	if(ngay>31||ngay<1||thang>12||thang<1||nam<0)
	 return 0;
	else{
		if(thang==1||thang==3||thang==5||thang==7||thang==8||thang==10||thang==12)
		 if(ngay<=31)
		  i++;
		if(thang==4||thang==6||thang==9||thang==11)
		 if(ngay<=30)
		  i++;
		if(thang==2){
			if(nam%4==0&&check(nam)==0)
		     if(ngay<=29)
		      i++;
		    if(nam%4!=0||check(nam)==1)
		     if(ngay<=28)
		      i++;
		}
	}
	if(i==1)
	 return 1;
	else
	 return 0;
}
int check(int nam){
	if(nam%100==0&&nam%400!=0)
	 return 1;
	else
	 return 0;
}
int check(int ngay1,int thang1,int nam1,int ngay2,int thang2,int nam2){
	if(nam1>nam2)
	 return 0;
	if(nam1==nam2&&thang1>thang2)
	 return 0;
	if(nam1==nam2&&thang1==thang2&&ngay1>ngay2)
	 return 0;
	return 1;
}
int check(int Gio1,int Phut1,int Gio2,int Phut2){
	if(Gio1>Gio2)
	 return 0;
	if(Gio1==Gio2&&Phut1>Phut2)
	 return 0;
	return 1;
}
int check(int Gio,int Phut){
	if(Gio>=0&&Gio<=23&&Phut>=0&&Phut<=59)
	 return 1;
	return 0;
}
//Doc thong tin sach trong thu vien tu file 
int Sach::Thudulieu(Sach *&ds,int &sl){
	string st;
	int i=0;
	fstream file;
	file.open("E:\\Sach1.txt",ios::in);
	if(!file){
		cout<<setw(5)<<""<<"Khong mo duoc tep!"<<endl;
		return 0;
	}
	delete[] ds;
	ds=new Sach[50];
	while(!file.eof()){
		getline(file,st);
		ds[i].Masach=st;
		getline(file,st);
		ds[i].Tensach=st;
		getline(file,st);
		ds[i].Chude=st;
		getline(file,st);
		ds[i].Tacgia=st;
		getline(file,st);
		ds[i].Nhaxb=st;
		getline(file,st);
		ds[i].Ngayxb=atoi(st.c_str());
		getline(file,st);
		ds[i].Thangxb=atoi(st.c_str());
		getline(file,st);
		ds[i].Namxb=atoi(st.c_str());
		getline(file,st);
		ds[i].Sotrang=atoi(st.c_str());
		getline(file,st);
		ds[i].Sobanluuthuvien=atoi(st.c_str());
		i++;
	}
	int j=i;
	int n=0;
	Sach *p=new Sach[j];
	for(int i=0;i<j;i++){
		if(ds[i].Masach.length()<=30&&ds[i].Tensach.length()<=30&&ds[i].Chude.length()<=30&&ds[i].Tacgia.length()<=30&&ds[i].Nhaxb.length()<=30)
		 if(check(ds[i].Ngayxb,ds[i].Thangxb,ds[i].Namxb))
		  p[n++]=ds[i];
	}
	sl=n;
	delete[] ds;
	ds=new Sach[sl];
	for(int i=0;i<sl;i++)
	 ds[i]=p[i];
	delete[] p;
	file.close();
	cout<<setw(5)<<""<<"Mo tep va doc thanh cong!"<<endl;
}
//Doc thong tin sach muon ve
int Muonve::Thudulieu(Muonve *&ds,int &sl){
	string st;
	int i=0;
	fstream file;
	file.open("E:\\Sach2.txt",ios::in);
	if(!file){
		cout<<setw(5)<<""<<"Khong mo duoc tep!"<<endl;
		return 0;
	}
	delete[] ds;
	ds=new Muonve[50];
	while(!file.eof()){
		getline(file,st);
		ds[i].Masach=st;
		getline(file,st);
		ds[i].Tensach=st;
		getline(file,st);
		ds[i].Chude=st;
		getline(file,st);
		ds[i].Tacgia=st;
		getline(file,st);
		ds[i].Nhaxb=st;
		getline(file,st);
		ds[i].Ngayxb=atoi(st.c_str());
		getline(file,st);
		ds[i].Thangxb=atoi(st.c_str());
		getline(file,st);
		ds[i].Namxb=atoi(st.c_str());
		getline(file,st);
		ds[i].Sotrang=atoi(st.c_str());
		getline(file,st);
		ds[i].Sobanluuthuvien=atoi(st.c_str());
		getline(file,st);
		ds[i].Ngaymuon=atoi(st.c_str());
		getline(file,st);
		ds[i].Thangmuon=atoi(st.c_str());
		getline(file,st);
		ds[i].Nammuon=atoi(st.c_str());
		getline(file,st);
		ds[i].Ngaytra=atoi(st.c_str());
		getline(file,st);
		ds[i].Thangtra=atoi(st.c_str());
		getline(file,st);
		ds[i].Namtra=atoi(st.c_str());
		i++;
	}
	int j=i;
	int n=0;
	Muonve *p=new Muonve[j];
	for(int i=0;i<j;i++){
		if(ds[i].Masach.length()<=30&&ds[i].Tensach.length()<=30&&ds[i].Chude.length()<=30&&ds[i].Tacgia.length()<=30&&ds[i].Nhaxb.length()<=30)
		 if(check(ds[i].Ngayxb,ds[i].Thangxb,ds[i].Namxb))
		  if(check(ds[i].Ngaymuon,ds[i].Thangmuon,ds[i].Nammuon))
		   if(check(ds[i].Ngaytra,ds[i].Thangtra,ds[i].Namtra))
		    if(check(ds[i].Ngayxb,ds[i].Thangxb,ds[i].Namxb,ds[i].Ngaymuon,ds[i].Thangmuon,ds[i].Nammuon))
		     if(check(ds[i].Ngaymuon,ds[i].Thangmuon,ds[i].Nammuon,ds[i].Ngaytra,ds[i].Thangtra,ds[i].Namtra))
		      p[n++]=ds[i];
	}
	sl=n;
	delete[] ds;
	ds=new Muonve[sl];
	for(int i=0;i<sl;i++)
	 ds[i]=p[i];
	delete[] p;
	file.close();
	cout<<setw(5)<<""<<"Mo tep va doc thanh cong!"<<endl;
}
//Doc thong tin sach muon doc
int Muondoc::Thudulieu(Muondoc *&ds,int &sl){
	string st;
	int i=0;
	fstream file;
	file.open("E:\\Sach3.txt",ios::in);
	if(!file){
		cout<<setw(5)<<""<<"Khong mo duoc tep!"<<endl;
		return 0;
	}
	delete[] ds;
	ds=new Muondoc[50];
	while(!file.eof()){
		getline(file,st);
		ds[i].Masach=st;
		getline(file,st);
		ds[i].Tensach=st;
		getline(file,st);
		ds[i].Chude=st;
		getline(file,st);
		ds[i].Tacgia=st;
		getline(file,st);
		ds[i].Nhaxb=st;
		getline(file,st);
		ds[i].Ngayxb=atoi(st.c_str());
		getline(file,st);
		ds[i].Thangxb=atoi(st.c_str());
		getline(file,st);
		ds[i].Namxb=atoi(st.c_str());
		getline(file,st);
		ds[i].Sotrang=atoi(st.c_str());
		getline(file,st);
		ds[i].Sobanluuthuvien=atoi(st.c_str());
		getline(file,st);
		ds[i].Giomuon=atoi(st.c_str());
		getline(file,st);
		ds[i].Phutmuon=atoi(st.c_str());
		getline(file,st);
		ds[i].Giotra=atoi(st.c_str());
		getline(file,st);
		ds[i].Phuttra=atoi(st.c_str());
		getline(file,st);
		i++;
	}
	int j=i;
	int n=0;
	Muondoc *p=new Muondoc[j];
	for(int i=0;i<j;i++){
		if(ds[i].Masach.length()<=30&&ds[i].Tensach.length()<=30&&ds[i].Chude.length()<=30&&ds[i].Tacgia.length()<=30&&ds[i].Nhaxb.length()<=30)
		 if(check(ds[i].Ngayxb,ds[i].Thangxb,ds[i].Namxb))
		  if(check(ds[i].Giomuon,ds[i].Phutmuon,ds[i].Giotra,ds[i].Phuttra))
		   if(check(ds[i].Giomuon,ds[i].Phutmuon))
		    if(check(ds[i].Giotra,ds[i].Phuttra))
		     p[n++]=ds[i];
	}
	sl=n;
	delete[] ds;
	ds=new Muondoc[sl];
	for(int i=0;i<sl;i++)
	 ds[i]=p[i];
	delete[] p;
	file.close();
	cout<<setw(5)<<""<<"Mo tep va doc thanh cong!"<<endl;
}
//Doc thong tin sach
void Sach::print(){
	cout<<setw(5)<<""<<setfill('_')<<setw(83)<<""<<setfill(' ')<<endl;
	cout<<setw(5)<<""<<"|"<<setw(31)<<""<<"THONG TIN CUON SACH"<<setw(31)<<""<<"|"<<endl;
	cout<<setw(5)<<""<<setfill('_')<<"|"<<setw(81)<<""<<"|"<<setfill(' ')<<endl;
	cout<<setw(5)<<""<<"|"<<setw(40)<<left<<"1,  Ma so sach"<<"|"<<setw(40)<<right<<Masach<<"|"<<endl;
	cout<<setw(5)<<""<<"|"<<setw(40)<<left<<"2,  Ten sach"<<"|"<<setw(40)<<right<<Tensach<<"|"<<endl;
	cout<<setw(5)<<""<<"|"<<setw(40)<<left<<"3,  Chu de"<<"|"<<setw(40)<<right<<Chude<<"|"<<endl;
	cout<<setw(5)<<""<<setfill('_')<<"|"<<setw(40)<<""<<"|"<<setw(40)<<""<<"|"<<setfill(' ')<<endl;
	cout<<setw(5)<<""<<"|"<<setw(40)<<left<<"4,  Tac gia"<<"|"<<setw(40)<<right<<Tacgia<<"|"<<endl;
	cout<<setw(5)<<""<<"|"<<setw(40)<<left<<"5,  Nha xuat ban"<<"|"<<setw(40)<<right<<Nhaxb<<"|"<<endl;
	cout<<setw(5)<<""<<"|"<<setw(40)<<left<<"6,  Ngay xb"<<"|"<<setw(30)<<""<<setw(2)<<right<<Ngayxb<<"/"<<setw(2)<<right<<Thangxb<<"/"<<setw(4)<<right<<Namxb<<"|"<<endl;
	cout<<setw(5)<<""<<setfill('_')<<"|"<<setw(40)<<""<<"|"<<setw(40)<<""<<"|"<<setfill(' ')<<endl;
	cout<<setw(5)<<""<<"|"<<setw(40)<<left<<"7,  So trang"<<"|"<<setw(40)<<right<<Sotrang<<"|"<<endl;
	cout<<setw(5)<<""<<"|"<<setw(40)<<left<<"8,  So ban luu thu vien"<<"|"<<setw(40)<<right<<Sobanluuthuvien<<"|"<<endl;
	cout<<setw(5)<<""<<setfill('_')<<"|"<<setw(40)<<""<<"|"<<setw(40)<<""<<"|"<<setfill(' ')<<endl;
}
//Doc thong tin Sach muon ve
void Muonve::print(){
	Sach::print();
	cout<<setw(5)<<""<<"|"<<setw(40)<<left<<"9,  Ngay muon"<<"|"<<setw(30)<<""<<setw(2)<<right<<Ngaymuon<<"/"<<setw(2)<<right<<Thangmuon<<"/"<<setw(4)<<right<<Nammuon<<"|"<<endl;
	cout<<setw(5)<<""<<"|"<<setw(40)<<left<<"10, Ngay tra"<<"|"<<setw(30)<<""<<setw(2)<<right<<Ngaytra<<"/"<<setw(2)<<right<<Thangtra<<"/"<<setw(4)<<right<<Namtra<<"|"<<endl;
	cout<<setw(5)<<""<<setfill('_')<<"|"<<setw(40)<<""<<"|"<<setw(40)<<""<<"|"<<setfill(' ')<<endl;
}
//Doc thong tin Sach muon doc
void Muondoc::print(){
	Sach::print();
	cout<<setw(5)<<""<<"|"<<setw(40)<<left<<"9,  Gio muon"<<"|"<<setw(34)<<""<<setw(2)<<right<<Giomuon<<"h"<<setw(2)<<right<<Phutmuon<<"'"<<"|"<<endl;
	cout<<setw(5)<<""<<"|"<<setw(40)<<left<<"10, Gio tra"<<"|"<<setw(34)<<""<<setw(2)<<right<<Giotra<<"h"<<setw(2)<<right<<Phuttra<<"'"<<"|"<<endl;
	cout<<setw(5)<<""<<setfill('_')<<"|"<<setw(40)<<""<<"|"<<setw(40)<<""<<"|"<<setfill(' ')<<endl;
}
//Xuat cac cuon sach trong thu vien
void Sach::print(Sach *ds,int sl){
	for(int i=0;i<sl;i++){
		cout<<setw(5)<<""<<"Sach thu "<<i+1<<":"<<endl;
		ds[i].print();
	}
	if(!sl)
	 cout<<setw(5)<<""<<"Chua co sach!"<<endl;
	cout<<"\n\n\n\n";
	cout<<setw(5)<<"";
	system("pause");
	system("cls");
}
//Hien thong tin sach muon ve
void Muonve::print(Muonve *ds,int sl){
	for(int i=0;i<sl;i++){
		cout<<setw(5)<<""<<"Sach thu "<<i+1<<":"<<endl;
		ds[i].print();
	}
	if(!sl)
	 cout<<setw(5)<<""<<"Chua co sach!"<<endl;
	cout<<"\n\n\n\n";
	cout<<setw(5)<<"";
	system("pause");
	system("cls");
}
//Hien thong tin sach muon doc
void Muondoc::print(Muondoc *ds,int sl){
	for(int i=0;i<sl;i++){
		cout<<setw(5)<<""<<"Sach thu "<<i+1<<":"<<endl;
		ds[i].print();
	}
	if(!sl)
	 cout<<setw(5)<<""<<"Chua co sach!"<<endl;
	cout<<"\n\n\n\n";
	cout<<setw(5)<<"";
	system("pause");
	system("cls");
}
//Bang thong ke cac cuon sach trong thu vien
void Sach::Thongke(Sach *ds,int sl){
	if(sl){
		cout<<setw(5)<<""<<setfill('_')<<setw(126)<<""<<setfill(' ')<<endl;
		cout<<setw(5)<<""<<"|"<<setw(41)<<""<<"BANG THONG KE CAC CUON SACH TRONG THU VIEN"<<setw(41)<<""<<"|"<<endl;
		cout<<setw(5)<<""<<setfill('_')<<"|"<<setw(124)<<""<<"|"<<setfill(' ')<<endl;
		cout<<setw(5)<<""<<"|"<<setw(10)<<left<<"SO THU TU"<<"|"<<setw(30)<<right<<"TEN SACH"<<"|"<<setw(30)<<right<<"MA SO SACH"<<"|"<<setw(30)<<right<<"NHA XUAT BAN"<<"|"<<setw(20)<<right<<"NGAY XUAT BAN"<<"|"<<endl;
		cout<<setw(5)<<""<<setfill('_')<<"|"<<setw(10)<<""<<"|"<<setw(30)<<""<<"|"<<setw(30)<<""<<"|"<<setw(30)<<""<<"|"<<setw(20)<<""<<"|"<<setfill(' ')<<endl;
		for(int i=0;i<sl;i++){
			cout<<setw(5)<<""<<"|"<<setw(10)<<left<<i+1<<"|"<<setw(30)<<right<<ds[i].Tensach<<"|"<<setw(30)<<right<<ds[i].Masach<<"|"<<setw(30)<<right<<ds[i].Nhaxb<<"|"<<setw(10)<<""<<setw(2)<<right<<ds[i].Ngayxb<<"/"<<setw(2)<<right<<ds[i].Thangxb<<"/"<<setw(4)<<right<<ds[i].Namxb<<"|"<<endl;
			cout<<setw(5)<<""<<setfill('_')<<"|"<<setw(10)<<""<<"|"<<setw(30)<<""<<"|"<<setw(30)<<""<<"|"<<setw(30)<<""<<"|"<<setw(20)<<""<<"|"<<setfill(' ')<<endl;
		}
	}
	else
	 cout<<setw(5)<<""<<"Chua co sach!"<<endl;
	cout<<"\n\n\n\n";
	cout<<setw(5)<<"";
	system("pause");
	system("cls");
}
//Bang thong ke sach muon ve
void Muonve::Thongke(Muonve *ds,int sl){
	if(sl){
		cout<<setw(5)<<""<<setfill('_')<<setw(147)<<""<<setfill(' ')<<endl;
		cout<<setw(5)<<""<<"|"<<setw(55)<<""<<"BANG THONG KE CAC CUON SACH MUON VE"<<setw(55)<<""<<"|"<<endl;
		cout<<setw(5)<<""<<setfill('_')<<"|"<<setw(145)<<""<<"|"<<setfill(' ')<<endl;
		cout<<setw(5)<<""<<"|"<<setw(10)<<left<<"SO THU TU"<<"|"<<setw(30)<<right<<"TEN SACH"<<"|"<<setw(30)<<right<<"MA SO SACH"<<"|"<<setw(30)<<right<<"NHA XUAT BAN"<<"|"<<setw(20)<<right<<"NGAY MUON"<<"|"<<setw(20)<<right<<"NGAY TRA"<<"|"<<endl;
		cout<<setw(5)<<""<<setfill('_')<<"|"<<setw(10)<<""<<"|"<<setw(30)<<""<<"|"<<setw(30)<<""<<"|"<<setw(30)<<""<<"|"<<setw(20)<<""<<"|"<<setw(20)<<""<<"|"<<setfill(' ')<<endl;
		for(int i=0;i<sl;i++){
			cout<<setw(5)<<""<<"|"<<setw(10)<<left<<i+1<<"|"<<setw(30)<<right<<ds[i].Tensach<<"|"<<setw(30)<<right<<ds[i].Masach<<"|"<<setw(30)<<right<<ds[i].Nhaxb<<"|"<<setw(10)<<""<<setw(2)<<right<<ds[i].Ngaymuon<<"/"<<setw(2)<<right<<ds[i].Thangmuon<<"/"<<setw(4)<<right<<ds[i].Nammuon<<"|"<<setw(10)<<""<<setw(2)<<right<<ds[i].Ngaytra<<"/"<<setw(2)<<right<<ds[i].Thangtra<<"/"<<setw(4)<<right<<ds[i].Namtra<<"|"<<endl;
			cout<<setw(5)<<""<<setfill('_')<<"|"<<setw(10)<<""<<"|"<<setw(30)<<""<<"|"<<setw(30)<<""<<"|"<<setw(30)<<""<<"|"<<setw(20)<<""<<"|"<<setw(20)<<""<<"|"<<setfill(' ')<<endl;
		}
	}
	else
	 cout<<setw(5)<<""<<"Chua co sach!"<<endl;
	cout<<"\n\n\n\n";
	cout<<setw(5)<<"";
	system("pause");
	system("cls");
}
//Bang thong ke sach muon doc
void Muondoc::Thongke(Muondoc *ds,int sl){
	if(sl){
		cout<<setw(5)<<""<<setfill('_')<<setw(147)<<""<<setfill(' ')<<endl;
		cout<<setw(5)<<""<<"|"<<setw(54)<<""<<"BANG THONG KE CAC CUON SACH MUON DOC"<<setw(55)<<""<<"|"<<endl;
		cout<<setw(5)<<""<<setfill('_')<<"|"<<setw(145)<<""<<"|"<<setfill(' ')<<endl;
		cout<<setw(5)<<""<<"|"<<setw(10)<<left<<"SO THU TU"<<"|"<<setw(30)<<right<<"TEN SACH"<<"|"<<setw(30)<<right<<"MA SO SACH"<<"|"<<setw(30)<<right<<"NHA XUAT BAN"<<"|"<<setw(20)<<right<<"GIO MUON"<<"|"<<setw(20)<<right<<"GIO TRA"<<"|"<<endl;
		cout<<setw(5)<<""<<setfill('_')<<"|"<<setw(10)<<""<<"|"<<setw(30)<<""<<"|"<<setw(30)<<""<<"|"<<setw(30)<<""<<"|"<<setw(20)<<""<<"|"<<setw(20)<<""<<"|"<<setfill(' ')<<endl;
		for(int i=0;i<sl;i++){
			cout<<setw(5)<<""<<"|"<<setw(10)<<left<<i+1<<"|"<<setw(30)<<right<<ds[i].Tensach<<"|"<<setw(30)<<right<<ds[i].Masach<<"|"<<setw(30)<<right<<ds[i].Nhaxb<<"|"<<setw(14)<<""<<setw(2)<<right<<ds[i].Giomuon<<"h"<<setw(2)<<right<<ds[i].Phutmuon<<"'"<<"|"<<setw(14)<<""<<setw(2)<<right<<ds[i].Giotra<<"h"<<setw(2)<<right<<ds[i].Phuttra<<"'"<<"|"<<endl;
			cout<<setw(5)<<""<<setfill('_')<<"|"<<setw(10)<<""<<"|"<<setw(30)<<""<<"|"<<setw(30)<<""<<"|"<<setw(30)<<""<<"|"<<setw(20)<<""<<"|"<<setw(20)<<""<<"|"<<setfill(' ')<<endl;
		}
	}
	else
	 cout<<setw(5)<<""<<"Chua co sach!"<<endl;
	cout<<"\n\n\n\n";
	cout<<setw(5)<<"";
	system("pause");
	system("cls");
}
//Tim kiem sach trong thu vien
void Sach::Timkiem(Sach *ds,int sl){
	int n;
	string bookname;
	cin.ignore();
	cout<<setw(5)<<""<<"Nhap ten cuon sach can tim: "; getline(cin,bookname);
	for(int i=0;i<sl;i++){
		if(bookname==ds[i].Tensach){
			ds[i].print();
			n++;
		}
	}
	if(!n)
	 cout<<setw(5)<<""<<"Khong tim thay sach!"<<endl;
	cout<<"\n\n\n\n";
	cout<<setw(5)<<"";
	system("pause");
	system("cls");
}
//Tim kiem sach muon ve
void Muonve::Timkiem(Muonve *ds,int sl){
	int n;
	string bookname;
	cin.ignore();
	cout<<setw(5)<<""<<"Nhap ten cuon sach can tim: "; getline(cin,bookname);
	for(int i=0;i<sl;i++){
		if(bookname==ds[i].Tensach){
			ds[i].print();
			n++;
		}
	}
	if(!n)
	 cout<<setw(5)<<""<<"Khong tim thay sach!"<<endl;
	cout<<"\n\n\n\n";
	cout<<setw(5)<<"";
	system("pause");
	system("cls");
}
//Tim kiem sach muon doc
void Muondoc::Timkiem(Muondoc *ds,int sl){
	int n;
	string bookname;
	cin.ignore();
	cout<<setw(5)<<""<<"Nhap ten cuon sach can tim: "; getline(cin,bookname);
	for(int i=0;i<sl;i++){
		if(bookname==ds[i].Tensach){
			ds[i].print();
			n++;
		}
	}
	if(!n)
	 cout<<setw(5)<<""<<"Khong tim thay sach!"<<endl;
	cout<<"\n\n\n\n";
	cout<<setw(5)<<"";
	system("pause");
	system("cls");
}
//Luu thong tin sach
void Sach::save(Sach *ds,int sl){
	fstream file;
	file.open("E:\\kq1.txt",ios::out|ios::trunc);
	for(int i=0;i<sl;i++){
		file<<setw(5)<<""<<"Sach "<<i+1<<":"<<endl;
		file<<setw(5)<<""<<setfill('_')<<setw(83)<<""<<setfill(' ')<<endl;
		file<<setw(5)<<""<<"|"<<setw(31)<<""<<"THONG TIN CUON SACH"<<setw(31)<<""<<"|"<<endl;
		file<<setw(5)<<""<<setfill('_')<<"|"<<setw(81)<<""<<"|"<<setfill(' ')<<endl;
		file<<setw(5)<<""<<"|"<<setw(40)<<left<<"1,  Ma so sach"<<"|"<<setw(40)<<right<<ds[i].Masach<<"|"<<endl;
		file<<setw(5)<<""<<"|"<<setw(40)<<left<<"2,  Ten sach"<<"|"<<setw(40)<<right<<ds[i].Tensach<<"|"<<endl;
		file<<setw(5)<<""<<"|"<<setw(40)<<left<<"3,  Chu de"<<"|"<<setw(40)<<right<<ds[i].Chude<<"|"<<endl;
		file<<setw(5)<<""<<setfill('_')<<"|"<<setw(40)<<""<<"|"<<setw(40)<<""<<"|"<<setfill(' ')<<endl;
		file<<setw(5)<<""<<"|"<<setw(40)<<left<<"4,  Tac gia"<<"|"<<setw(40)<<right<<ds[i].Tacgia<<"|"<<endl;
		file<<setw(5)<<""<<"|"<<setw(40)<<left<<"5,  Nha xuat ban"<<"|"<<setw(40)<<right<<ds[i].Nhaxb<<"|"<<endl;
		file<<setw(5)<<""<<"|"<<setw(40)<<left<<"6,  Ngay xb"<<"|"<<setw(30)<<""<<setw(2)<<right<<ds[i].Ngayxb<<"/"<<setw(2)<<right<<ds[i].Thangxb<<"/"<<setw(4)<<right<<ds[i].Namxb<<"|"<<endl;
		file<<setw(5)<<""<<setfill('_')<<"|"<<setw(40)<<""<<"|"<<setw(40)<<""<<"|"<<setfill(' ')<<endl;
		file<<setw(5)<<""<<"|"<<setw(40)<<left<<"7,  So trang"<<"|"<<setw(40)<<right<<ds[i].Sotrang<<"|"<<endl;
		file<<setw(5)<<""<<"|"<<setw(40)<<left<<"8,  So ban luu thu vien"<<"|"<<setw(40)<<right<<ds[i].Sobanluuthuvien<<"|"<<endl;
		file<<setw(5)<<""<<setfill('_')<<"|"<<setw(40)<<""<<"|"<<setw(40)<<""<<"|"<<setfill(' ')<<endl;
	}
	file.close();
	cout<<setw(5)<<""<<"Da luu!"<<endl;
	cout<<"\n\n\n\n";
	cout<<setw(5)<<"";
	system("pause");
	system("cls");
}
//Luu thong tin sach muon ve
void Muonve::save(Muonve *ds,int sl){
	fstream file;
	file.open("E:\\kq2.txt",ios::out|ios::trunc);
	for(int i=0;i<sl;i++){
		file<<setw(5)<<""<<"Sach "<<i+1<<":"<<endl;
		file<<setw(5)<<""<<setfill('_')<<setw(83)<<""<<setfill(' ')<<endl;
		file<<setw(5)<<""<<"|"<<setw(31)<<""<<"THONG TIN CUON SACH"<<setw(31)<<""<<"|"<<endl;
		file<<setw(5)<<""<<setfill('_')<<"|"<<setw(81)<<""<<"|"<<setfill(' ')<<endl;
		file<<setw(5)<<""<<"|"<<setw(40)<<left<<"1,  Ma so sach"<<"|"<<setw(40)<<right<<ds[i].Masach<<"|"<<endl;
		file<<setw(5)<<""<<"|"<<setw(40)<<left<<"2,  Ten sach"<<"|"<<setw(40)<<right<<ds[i].Tensach<<"|"<<endl;
		file<<setw(5)<<""<<"|"<<setw(40)<<left<<"3,  Chu de"<<"|"<<setw(40)<<right<<ds[i].Chude<<"|"<<endl;
		file<<setw(5)<<""<<setfill('_')<<"|"<<setw(40)<<""<<"|"<<setw(40)<<""<<"|"<<setfill(' ')<<endl;
		file<<setw(5)<<""<<"|"<<setw(40)<<left<<"4,  Tac gia"<<"|"<<setw(40)<<right<<ds[i].Tacgia<<"|"<<endl;
		file<<setw(5)<<""<<"|"<<setw(40)<<left<<"5,  Nha xuat ban"<<"|"<<setw(40)<<right<<ds[i].Nhaxb<<"|"<<endl;
		file<<setw(5)<<""<<"|"<<setw(40)<<left<<"6,  Ngay xb"<<"|"<<setw(30)<<""<<setw(2)<<right<<ds[i].Ngayxb<<"/"<<setw(2)<<right<<ds[i].Thangxb<<"/"<<setw(4)<<right<<ds[i].Namxb<<"|"<<endl;
		file<<setw(5)<<""<<setfill('_')<<"|"<<setw(40)<<""<<"|"<<setw(40)<<""<<"|"<<setfill(' ')<<endl;
		file<<setw(5)<<""<<"|"<<setw(40)<<left<<"7,  So trang"<<"|"<<setw(40)<<right<<ds[i].Sotrang<<"|"<<endl;
		file<<setw(5)<<""<<"|"<<setw(40)<<left<<"8,  So ban luu thu vien"<<"|"<<setw(40)<<right<<ds[i].Sobanluuthuvien<<"|"<<endl;
		file<<setw(5)<<""<<setfill('_')<<"|"<<setw(40)<<""<<"|"<<setw(40)<<""<<"|"<<setfill(' ')<<endl;
		file<<setw(5)<<""<<"|"<<setw(40)<<left<<"9,  Ngay muon"<<"|"<<setw(30)<<""<<setw(2)<<right<<ds[i].Ngaymuon<<"/"<<setw(2)<<right<<ds[i].Thangmuon<<"/"<<setw(4)<<right<<ds[i].Nammuon<<"|"<<endl;
		file<<setw(5)<<""<<"|"<<setw(40)<<left<<"10, Ngay tra"<<"|"<<setw(30)<<""<<setw(2)<<right<<ds[i].Ngaytra<<"/"<<setw(2)<<right<<ds[i].Thangtra<<"/"<<setw(4)<<right<<ds[i].Namtra<<"|"<<endl;
		file<<setw(5)<<""<<setfill('_')<<"|"<<setw(40)<<""<<"|"<<setw(40)<<""<<"|"<<setfill(' ')<<endl;
	}
	file.close();
	cout<<setw(5)<<""<<"Da luu!"<<endl;
	cout<<"\n\n\n\n";
	cout<<setw(5)<<"";
	system("pause");
	system("cls");
}
//Luu thong tin sach muon doc
void Muondoc::save(Muondoc *ds,int sl){
	fstream file;
	file.open("E:\\kq3.txt",ios::out|ios::trunc);
	for(int i=0;i<sl;i++){
		file<<setw(5)<<""<<"Sach "<<i+1<<":"<<endl;
		file<<setw(5)<<""<<setfill('_')<<setw(83)<<""<<setfill(' ')<<endl;
		file<<setw(5)<<""<<"|"<<setw(31)<<""<<"THONG TIN CUON SACH"<<setw(31)<<""<<"|"<<endl;
		file<<setw(5)<<""<<setfill('_')<<"|"<<setw(81)<<""<<"|"<<setfill(' ')<<endl;
		file<<setw(5)<<""<<"|"<<setw(40)<<left<<"1,  Ma so sach"<<"|"<<setw(40)<<right<<ds[i].Masach<<"|"<<endl;
		file<<setw(5)<<""<<"|"<<setw(40)<<left<<"2,  Ten sach"<<"|"<<setw(40)<<right<<ds[i].Tensach<<"|"<<endl;
		file<<setw(5)<<""<<"|"<<setw(40)<<left<<"3,  Chu de"<<"|"<<setw(40)<<right<<ds[i].Chude<<"|"<<endl;
		file<<setw(5)<<""<<setfill('_')<<"|"<<setw(40)<<""<<"|"<<setw(40)<<""<<"|"<<setfill(' ')<<endl;
		file<<setw(5)<<""<<"|"<<setw(40)<<left<<"4,  Tac gia"<<"|"<<setw(40)<<right<<ds[i].Tacgia<<"|"<<endl;
		file<<setw(5)<<""<<"|"<<setw(40)<<left<<"5,  Nha xuat ban"<<"|"<<setw(40)<<right<<ds[i].Nhaxb<<"|"<<endl;
		file<<setw(5)<<""<<"|"<<setw(40)<<left<<"6,  Ngay xb"<<"|"<<setw(30)<<""<<setw(2)<<right<<ds[i].Ngayxb<<"/"<<setw(2)<<right<<ds[i].Thangxb<<"/"<<setw(4)<<right<<ds[i].Namxb<<"|"<<endl;
		file<<setw(5)<<""<<setfill('_')<<"|"<<setw(40)<<""<<"|"<<setw(40)<<""<<"|"<<setfill(' ')<<endl;
		file<<setw(5)<<""<<"|"<<setw(40)<<left<<"7,  So trang"<<"|"<<setw(40)<<right<<ds[i].Sotrang<<"|"<<endl;
		file<<setw(5)<<""<<"|"<<setw(40)<<left<<"8,  So ban luu thu vien"<<"|"<<setw(40)<<right<<ds[i].Sobanluuthuvien<<"|"<<endl;
		file<<setw(5)<<""<<setfill('_')<<"|"<<setw(40)<<""<<"|"<<setw(40)<<""<<"|"<<setfill(' ')<<endl;
		file<<setw(5)<<""<<"|"<<setw(40)<<left<<"9,  Gio muon"<<"|"<<setw(34)<<""<<setw(2)<<right<<ds[i].Giomuon<<"h"<<setw(2)<<right<<ds[i].Phutmuon<<"'"<<"|"<<endl;
		file<<setw(5)<<""<<"|"<<setw(40)<<left<<"10, Gio tra"<<"|"<<setw(34)<<""<<setw(2)<<right<<ds[i].Giotra<<"h"<<setw(2)<<right<<ds[i].Phuttra<<"'"<<"|"<<endl;
		file<<setw(5)<<""<<setfill('_')<<"|"<<setw(40)<<""<<"|"<<setw(40)<<""<<"|"<<setfill(' ')<<endl;
	}
	file.close();
	cout<<setw(5)<<""<<"Da luu!"<<endl;
	cout<<"\n\n\n\n";
	cout<<setw(5)<<"";
	system("pause");
	system("cls");
}
//Bang menu Console
void MENU(){
	cout<<setw(5)<<""<<setfill('_')<<setw(82)<<""<<setfill(' ')<<endl;
	cout<<setw(5)<<""<<"|"<<setw(80)<<""<<"|"<<setfill(' ')<<endl;
	cout<<setw(5)<<""<<"|"<<setw(23)<<""<<"CHUONG TRINH QUAN LY THU VIEN"<<setw(28)<<""<<"|"<<endl;
	cout<<setw(5)<<""<<setfill('_')<<"|"<<setw(80)<<""<<"|"<<setfill(' ')<<endl;
	cout<<setw(5)<<""<<"|"<<setw(80)<<left<<"             Nhap (1) de doc du lieu cac cuon sach trong thu vien"<<"|"<<endl;
	cout<<setw(5)<<""<<"|"<<setw(80)<<left<<"             Nhap (2) de doc du lieu cac cuon sach muon ve"<<"|"<<endl;
	cout<<setw(5)<<""<<"|"<<setw(80)<<left<<"             Nhap (3) de doc du lieu cac cuon sach muon doc"<<"|"<<endl;
	cout<<setw(5)<<""<<setfill('_')<<"|"<<setw(80)<<""<<"|"<<setfill(' ')<<endl;
	cout<<setw(5)<<""<<"|"<<setw(80)<<left<<"             Nhap (4) de xuat danh sach cac cuon sach"<<"|"<<endl;
	cout<<setw(5)<<""<<"|"<<setw(80)<<left<<"             Nhap (5) de xuat danh sach cac cuon sach muon ve"<<"|"<<endl;
	cout<<setw(5)<<""<<"|"<<setw(80)<<left<<"             Nhap (6) de xuat danh sach cac cuon sach muon doc"<<"|"<<endl;
	cout<<setw(5)<<""<<setfill('_')<<"|"<<setw(80)<<""<<"|"<<setfill(' ')<<endl;
	cout<<setw(5)<<""<<"|"<<setw(80)<<left<<"             Nhap (7) de thong ke cac cuon sach"<<"|"<<endl;
	cout<<setw(5)<<""<<"|"<<setw(80)<<left<<"             Nhap (8) de thong ke cac cuon sach muon ve"<<"|"<<endl;
	cout<<setw(5)<<""<<"|"<<setw(80)<<left<<"             Nhap (9) de thong ke cuon sach muon doc"<<"|"<<endl;
	cout<<setw(5)<<""<<setfill('_')<<"|"<<setw(80)<<""<<"|"<<setfill(' ')<<endl;
	cout<<setw(5)<<""<<"|"<<setw(80)<<left<<"             Nhap (10) de tim kiem cac cuon sach"<<"|"<<endl;
	cout<<setw(5)<<""<<"|"<<setw(80)<<left<<"             Nhap (11) de tim kiem cac cuon sach muon ve"<<"|"<<endl;
	cout<<setw(5)<<""<<"|"<<setw(80)<<left<<"             Nhap (12) de tim kiem cuon sach muon doc"<<"|"<<endl;
	cout<<setw(5)<<""<<setfill('_')<<"|"<<setw(80)<<""<<"|"<<setfill(' ')<<endl;
	cout<<setw(5)<<""<<"|"<<setw(80)<<left<<"             Nhap (13) de luu cac cuon sach vao tep"<<"|"<<endl;
	cout<<setw(5)<<""<<"|"<<setw(80)<<left<<"             Nhap (14) de luu cac cuon sach muon ve"<<"|"<<endl;
	cout<<setw(5)<<""<<"|"<<setw(80)<<left<<"             Nhap (15) de luu cuon sach muon doc"<<"|"<<endl;
	cout<<setw(5)<<""<<setfill('=')<<"|"<<setw(80)<<""<<"|"<<setfill(' ')<<endl;
	cout<<setw(5)<<""<<"|"<<setw(80)<<""<<"|"<<setfill(' ')<<endl;
	cout<<setw(5)<<""<<"|"<<setw(80)<<left<<"             Nhap (0) de thoat menu va dung chuong trinh"<<"|"<<endl;
	cout<<setw(5)<<""<<setfill('_')<<"|"<<setw(80)<<""<<"|"<<setfill(' ')<<endl;
}
//Doc file 
//Sach trong thu vien Sach1.txt
//Sach muon Sach2.txt
//Sach muon doc Sach3.txt
//Can tao cac file tren trong o de ghi va doc du lieu (vi tri tao file phai duoc gan trong chuong trinh
