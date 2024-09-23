#include<iostream>
#include<string>
#include<stdio.h>
#include<iomanip>
#include <fstream>
using namespace std;
struct sinhvien {
	int  stt;
	string hoten, mssv, gt, lop, x, sdt;
	float bt, gk, ck, tb;
};
// kiem tra mssv
void kt(sinhvien sv[], int n, int id){
	int a;
	while (a==0) {	
		a=1;
		//kt tu 0 -> id
	    for (int i = 0; i < id; i++){ 
	    	if (sv[i].mssv == sv[id].mssv) {
		    	cout << "MA SO SINH VIEN DA TON TAI HAY NHAP LAI: ";
		    	cin >> sv[id].mssv;
	        	a=0;
	   	    }
        }	
        //kt tu id -> n
        for (int i=id+1; i < n; i++){
    	    if (sv[i].mssv == sv[id].mssv) {
			cout << "MA SO SINH VIEN DA TON TAI HAY NHAP LAI: ";
			cin >> sv[id].mssv;
	    	a=0;
	     	}
        }
    }	
}

void nhap(sinhvien sv[], int n, int id) {
	    sv[id].stt=id+1;
		cin.ignore();
		cout << "\n\t  NHAP THONG TIN SINH VIEN \n\n";
		cout <<"\n";
		cout << "HO TEN: ";
		fflush(stdin);
		getline(cin, sv[id].hoten);
		cout<<"\n";	
		cout << "MA SO SINH VIEN: ";
		cin >>sv[id]. mssv;
		kt(sv, n, id);
		cout <<"\n";
		cout << "GIOI TINH: ";
	    fflush(stdin);
	    getline(cin,sv[id].gt);
		cout<<"\n";
		cout << "LOP: ";
		getline(cin, sv[id].lop);
		cout<<"\n";
		cout << "SO DIEN THOAI: ";
	    getline(cin, sv[id].sdt);
		cout<<"\n";
		cout << "DIEM BAI TAP: ";
		cin >>sv[id]. bt;
		cout<<"\n";
		cout << "DIEM GIUA KI: ";
		cin >> sv[id].gk;
		cout<<"\n";
		cout << "DIEM CUOI KI: ";
		cin >> sv[id].ck;
		cout << "\n\n" << endl;
		system("cls");
	
}

void suasv(sinhvien sv[],int n){
	string msvn;
	cout<<"NHAP MA SINH VIEN DE SUA THONG TIN ";
    cin>>msvn;
	for(int i=0;i<n;i++){
		if(msvn == sv[i].mssv){
			nhap(sv, n, i);
		}
	}	
}

void xuat(sinhvien sv[], int n) {

	cout << setw(49) << "DANH SACH SINH VIEN" << endl;
	cout <<left<<setw(5)<<"STT"<<"\t"<<left<<setw(25)<< "HO TEN" <<"\t"<< left << setw(15) << "MA SINH VIEN"<<"\t"<< left << setw(15) << "GIOI TINH "<<"\t"<<left<<setw(10)<<"LOP" <<"\t"<< left << setw(18) << "SO DIEN THOAI"<< "\t"<<left << setw(13) << "DIEM BT"  <<left << setw(13) << "DIEM GK"  <<left << setw(13) << "DIEM CK"  << left << setw(13) << "DIEM TB" << endl;
	for (int i = 0; i < n; i++) {
		
		for (int j = 0; j < sv[i].hoten.size(); j++) {
			if (sv[i].hoten.at(j) == '_') {
				sv[i].hoten.at(j) = ' ';
			}
		}
		
	    cout << left <<setw(5)<<sv[i].stt<<"\t";
		cout << left <<setw(25)<< sv[i].hoten<<"\t";
		cout << left << setw(15) << sv[i].mssv << "\t";
		cout << left <<setw(15) << sv[i].gt<<"\t";
		cout << left << setw(10) << sv[i].lop << "\t";
		cout << left << setw(18) <<sv[i].sdt << "\t";
		cout << left << setw(13) <<  sv[i].bt;
		cout << left << setw(13) << sv[i].gk;
		cout << left << setw(13) << sv[i].ck ;
		sv[i].tb = sv[i].bt * 0.2 + sv[i].gk * 0.3 + sv[i].ck * 0.5;
		cout << left << setw(13) << sv[i].tb;
		cout <<"\n\n";
	
}
	
	cout<<"\n\n";

}

void docfile(sinhvien sv[], int& n) { 
	ifstream docfile;
	docfile.open("sv.txt", ios::in);
	int a = 1;
	for (int i = 0; i < a; i++) {
		docfile >> sv[i].stt; 
		docfile >> sv[i].hoten;
		//chuyen "_" -> " "
    	for (int j = 0; j < sv[i].hoten.size(); j++) {
			if (sv[i].hoten.at(j) == '_') {
				sv[i].hoten.at(j) = ' ';
			}
		}
		docfile>>sv[i].mssv;
		docfile>>sv[i].gt;
		docfile>>sv[i].lop;
		docfile>>sv[i].sdt;
		docfile >> sv[i].bt;
		docfile >> sv[i].gk;
		docfile >> sv[i].ck;
	
		a++;
		if (sv[i].stt == 0) {
			n = a - 2;
			a = 0;
		}
		}
	}

//dung cho chinh sua, xoa xong luu lai
void luufile(sinhvien sv[], int n) {
	fstream      file;
	file.open("sv.txt", ios::out);

	for (int i = 0; i < n; i++) {
		// ma hoa " " -> "_"
		for (int j = 0; j < sv[i].hoten.size(); j++) {
			if (sv[i].hoten.at(j) == ' ') {
				sv[i].hoten.at(j) = '_';
			}
		}
		file<< sv[i].stt<<endl;
		file<< sv[i].hoten << endl;	
		file<< sv[i].mssv<<endl;
	    file<< sv[i].gt<<endl;
		file<< sv[i].lop<<endl;
		file<< sv[i].sdt<<endl;
		file<< sv[i].bt<<endl;
		file<< sv[i].gk<<endl;
		file<< sv[i].ck<<endl;
	} 
	file<<0;
	file.close();
}

void luufilecsv(sinhvien sv[], int n) {
	fstream      exe;
	exe.open("sv.csv", ios::out);
	exe << "stt," <<"ho ten," <<  "mssv, gioi tinh, lop, sdt," << "bt," << "gk," << "ck," << "tb," << endl;
	for (int i = 0; i < n; i++) {
		exe << sv[i].stt<<","<<sv[i].hoten<<"," << sv[i].mssv<< ","<<sv[i].gt<<","<<sv[i].lop<<","<<sv[i].sdt<<"," << sv[i].bt<<"," << sv[i].gk<<"," << sv[i].ck<< "," << sv[i].tb<<endl;
	}
	exe.close();
}

void timkiemsv(sinhvien sv[],int n){
	docfile(sv, n); // sua loi _ sv moi nhap
	int dem=0;
	float diem;
	cout<<"NHAP SO DIEM TB CAN TIM KIEM:";
    cin>>diem;
	cout<<"\n\n\t\t THONG TIN SINH VIEN CAN TIM KIEM "<<endl;
	cout <<left<<setw(5)<<"STT"<<"\t"<<left<<setw(25)<< "HO TEN" <<"\t"<< left << setw(15) << "MA SINH VIEN"<<"\t"<< left << setw(15) << "GIOI TINH "<<"\t"<<left<<setw(10)<<"LOP" <<"\t"<< left << setw(18) << "SO DIEN THOAI"<< "\t"<<left << setw(13) << "DIEM BT"  <<left << setw(13) << "DIEM GK"  <<left << setw(13) << "DIEM CK"  << left << setw(13) << "DIEM TB" << endl;
	for (int i=0;i<n;i++){
		dem++;
        if(sv[i].tb==diem){
        cout << left << setw(5)  << sv[i].stt<<"\t";
		cout << left << setw(25) << sv[i].hoten<<"\t";
		cout << left << setw(15) << sv[i].mssv << "\t";
		cout << left << setw(15) << sv[i].gt<<"\t";
		cout << left << setw(10) << sv[i].lop << "\t";
		cout << left << setw(18) << sv[i].sdt << "\t";
		cout << left << setw(13) << sv[i].bt;
		cout << left << setw(13) << sv[i].gk;
		cout << left << setw(13) << sv[i].ck ;
		sv[i].tb = sv[i].bt * 0.2 + sv[i].gk * 0.3 + sv[i].ck * 0.5;
		cout << left << setw(13) << sv[i].tb;
		cout <<"\n\n";

}

	}
	if(dem==0){
		 cout<<"KHONG CO SINH VIEN THOA MAN "<<endl;
	}

}
void timkiemtheoten(sinhvien sv[],int n){
	docfile(sv, n); // sua loi ko tim dc sv moi nhap
	string ht;
	cout<<"NHAP HO TEN CAN TIM KIEM: ";
	fflush(stdin);
	getline(cin,ht);
	cout<<"\n\n\t\t THONG TIN SINH VIEN CAN TIM KIEM "<<endl;
	cout <<left<<setw(5)<<"STT"<<"\t"<<left<<setw(25)<< "HO TEN" <<"\t"<< left << setw(15) << "MA SINH VIEN"<<"\t"<< left << setw(15) << "GIOI TINH "<<"\t"<<left<<setw(10)<<"LOP" <<"\t"<< left << setw(18) << "SO DIEN THOAI"<< "\t"<<left << setw(13) << "DIEM BT"  <<left << setw(13) << "DIEM GK"  <<left << setw(13) << "DIEM CK"  << left << setw(13) << "DIEM TB" << endl;	
	int dem =0;
      for(int i=0;i<n;i++){
       	dem++;
       	if(sv[i].hoten==ht){
       	cout << left <<setw(5)   <<sv[i].stt<<"\t";
		cout << left <<setw(25)  << sv[i].hoten<<"\t";
		cout << left << setw(15) << sv[i].mssv << "\t";
		cout << left <<setw(15)  << sv[i].gt<<"\t";
		cout << left << setw(10) << sv[i].lop << "\t";
		cout << left << setw(18) << sv[i].sdt << "\t";
		cout << left << setw(13) << sv[i].bt;
		cout << left << setw(13) << sv[i].gk;
		cout << left << setw(13) << sv[i].ck ;
		sv[i].tb = sv[i].bt * 0.2 + sv[i].gk * 0.3 + sv[i].ck * 0.5;
		cout << left << setw(13) << sv[i].tb;
		cout <<"\n\n";
     	}
     } 
	 if(dem=0){
		 cout<<"KHONG CO SINH VIEN THOA MAN "<<endl;
	 }
}

void xoa(sinhvien sv[], int& n) {
	docfile(sv, n);
	int id;
	cout << "Hay nhap vi tri(stt) muon xoa: ";
	cin >> id;
	if (id < 1 || id > n)
	{
		cout << "Vi tri khong hop le!\n";
		return;
	}
   // lui sinh vien len
	for (int i = id; i <= n; i++) {
	sv[i - 1].hoten=sv[i].hoten;
	sv[i - 1].gt = sv[i].gt;
	sv[i - 1].lop = sv[i].lop;
	sv[i - 1].mssv = sv[i].mssv;
	sv[i - 1].sdt = sv[i].sdt;
	sv[i - 1].bt = sv[i].bt;
	sv[i - 1].gk = sv[i].gk;
	sv[i - 1].ck = sv[i].ck;
	sv[i - 1].tb = sv[i].tb;
	
	}
	cout << "***DA XOA***" << endl;
	n--;
}

void sapxeptheodtbc(sinhvien sv[],int n){

	for (int i = 0; i < n; i++)
	{
		for (int j=i+1;j<n;j++)
		{
			if (sv[i].tb>sv[j].tb)
			{
			  sinhvien	c = sv[i];
				sv[i] = sv[j];
				sv[j] = c;
			}
		}	
	}
	//chay lai stt
	for (int i = 0; i < n; i++) {
		sv[i].stt = i + 1;
	}
	xuat(sv, n);
	luufile(sv, n);


}

int main() {
	sinhvien sv[1000];
	int n = 0;
	int sl,c;
	docfile(sv,n);
	cout << "DANH SACH SINH VIEN HIEN CO:" << endl;
	xuat(sv, n);
	fflush(stdin);
	while (true) {
		cout << " _____________________________________" << endl;
		cout << "| CHON                                |" << endl;
		cout << "| 1: DE THEM SINH VIEN                |" << endl;
		cout << "| 2: XEM DANH SANH SINH VIEN          |" << endl;
		cout << "| 3: CHINH SUA                        |" << endl;
		cout << "| 4: XOA 1 SINH VIEN                  |" << endl;
		cout << "| 5: TIM KIEM SINH VIEN THEO TEN      |" << endl;
		cout << "| 6: TIM KIEM SINH VIEN THEO DIEM TB  |" << endl;
		cout << "| 7: SAP XEP THEO DIEM TB             |" << endl; 
		cout << "| 8: LUU VAO FILE CSV                 |" << endl; 		
		cout << "| 9: XOA TOAN BO DU LIEU              |" << endl;
		cout << "| 0: THOAT CHUONG TRINH               |" << endl;
		cout << "|_____________________________________|" << endl;
		cin >> c;
    	switch (c) {
	    case 1:
	    	{
			 system("cls");
			 cout<<"NHAP SO LUONG SINH VIEN BAN MUON THEM :";
			 cin>>sl; 
			 system("cls");
				for (int i = 0; i < sl; i++)
				{
				cout << "SINH VIEN THU " << i +1 << endl;
                nhap(sv, n, n);
			   	n++;
			}
			luufile(sv, n);
			cout<<"**********DA NHAP**********";
                break;
	    }
		case 2:
		{
			system("cls");
			xuat(sv, n);
			break;
		}
		case 3: {
			system("cls");
			xuat(sv, n);
		    suasv(sv, n);
		    luufile(sv, n);	
			xuat(sv, n);
			break;
		}
		case 4: {
			system("cls");
			xuat(sv, n);
			xoa(sv, n);
			luufile(sv, n);
		
			break;
		}
		case 5: {
			system("cls");
			timkiemtheoten(sv,n);
			cout<<"\n\n";
			break;
		}
		case 6:{
			system("cls");
			timkiemsv(sv,n);
			break;
		}	
		case 7: {
			system("cls");
			
			sapxeptheodtbc(sv, n);
		
			break;
		}
		case 8:{
			luufilecsv(sv, n);
			cout<< "*******da luu*******"<<endl;
			break;
		}	
		case 9: {
			n = 0;
			luufile(sv, n);
			cout << "*******da xoa*******"<<endl;
			break;
		}
		default:
			break;
		}
		system("pause");
		system("cls");
		if (c == 0) break;
	}
	cout << "----------end-----------" << endl;
	return 0;
}



