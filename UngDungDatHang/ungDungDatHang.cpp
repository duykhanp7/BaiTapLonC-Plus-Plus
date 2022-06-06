#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
#include<ctime>
#include<vector>
#include<ostream>
#include<istream>
#include<windows.h>
#include<iomanip>
#include<stdlib.h>
#include<map>
#include<fstream>
#include <ctype.h>
#include<conio.h>
#pragma warning(disable:4996)
using namespace std;


//CLASS NGAY
class Ngay{
    private: 
        //NGÀY THÁNG NĂM
        string ngay,thang,nam;
    public:
    Ngay(){
        //LẤY THỜI GIAN THỰC CỦA HỆ THỐNG
        time_t now = time(0);
        tm *ltm = localtime(&now);
        this->ngay = to_string(ltm->tm_mday);
        this->thang = to_string(1 + ltm->tm_mon);
        this->nam = to_string(1900 + ltm->tm_year);
    }
    //HÀM GETTER
    //TRẢ VỀ NGÀY
    string getNgay(){return this->ngay;}
    //TRẢ VỀ THÁNG
    string getThang(){return this->thang;}
    //TRẢ VỀ NĂM
    string getNam(){return this->nam;}
    //TRẢ VỀ NGÀY THÁNG NĂM;
    string getNgayThangNam(){
        return this->ngay+"/"+this->thang+"/"+this->nam;
    }
    //HÀM SETTER
    //SET NGÀY
    void setNgay(string a){this->ngay = a;}
    //SET THÁNG
    void setThang(string a){this->ngay = a;}
    //SET NĂM
    void setNam(string a){this->nam = a;}
    
};

//CLASS SẢN PHẨM
//MỘT SẢN PHẨM GỒM HAI THUỘC TÍNH : TÊN SẢN PHẦM, VÀ GIÁ THÀNH
class SanPham{
    private:
        string idSanPham;//ID SẢN PHẨM
        string tenSanPham;//TÊN SẢN PHẨM
        int giaSanPham;//GIÁ SẢN PHẨM
        int soLuong;
    public:
        //HÀM KHỞI TẠO CÓ THAM SỐ : TÊN SẢN PHẨM VÀ GIÁ SẢN PHẨM
        SanPham(){
            this->soLuong = 0;
        }
        SanPham(string id,string ten, int gia, int soLuong){
            this->idSanPham = id;
            this->tenSanPham = ten;
            this->giaSanPham = gia;
            this->soLuong = soLuong;
        }
        //HÀM GETTER
        //TRẢ VỀ ID SẢN PHẦM
        string getID(){return this->idSanPham;}
        //TRẢ VỀ TÊN SẢN PHẨM
        string getTenSanPham(){return this->tenSanPham;}
        //TRẢ VỀ GIÁ SẢN PHẨM
        int getGiaSanPham(){return this->giaSanPham;}
        //TRẢ VỀ SỐ LƯỢNG SẢN PHẨM
        int getSoLuong(){return this->soLuong;}
        //TRẢ VỀ TỔNG TIỀN CỦA SẢN PHẨM
        int getTongTienSanPham(){
            return (int) (this->soLuong*this->giaSanPham);
        }
        //HIỂN THỊ THÔNG TIN SẢN PHẨM
        void hienThiThongTin(){
            cout<<"Ten San Pham : "<<this->tenSanPham<<" -- "<<"Gia San Pham : "<<this->giaSanPham<<" -- "<<"So Luong San Pham : "<<this->soLuong<<" -- "<<"Thanh Tien : "<<this->getTongTienSanPham()<<"\n";
        }

        void hienThi(){
            cout<<"Ten San Pham : "<<this->tenSanPham<<" -- "<<"Gia San Pham : "<<this->giaSanPham<<"\n";
        }
        //TRẢ VỀ THÔNG TIN SẢN PHẨM
        string getThongTinSanPham(){
            string text = "Ten San Pham : ";
            return text.append(this->tenSanPham).append(" -- Gia San Pham : ").append(to_string(this->giaSanPham)).append(" -- So Luong San Pham : ").append(to_string(this->soLuong)).append(" -- Thanh Tien : ").append(to_string(this->getTongTienSanPham())).append("\n");
        }

        //HÀM SETTER
        //SET ID SẢN PHẦM
        void setID(string id){this->idSanPham = id;}
        //SET TÊN CHO SẢN PHẨM
        void setTenSanPham(string ten){this->tenSanPham = ten;}
        //SET GIÁ CHO SẢN PHẦM
        void setGiaSanPham(int gia){this->giaSanPham = gia;}
        //SET SỐ LƯỢNG SẢN PHẨM
        void setSoLuong(int a){this->soLuong = a;}
        //THÊM SỐ LƯỢNG
        void them(int i){
            this->soLuong+=i;
        }
        //QUÁ TẢI TOÁN TỬ XUẤT ĐỂ HIỆN THÔNG TIN SẢN PHẨM
        friend ostream& operator<<(ostream&,const SanPham&);
};

//QUÁ TẢI TOÁN TỬ XUẤT CHO CLASS SẢN PHẨM
ostream& operator<<(ostream& out,const SanPham& sp)
{
    out<<"Ten San Pham : "<<sp.tenSanPham<<" -- "<<"Gia San Pham : "<<sp.giaSanPham<<" -- "<<"So Luong San Pham : "<<sp.soLuong<<"\n";
    return out;
}


//CLASS GIỎ HÀNG
//GIỎ HÀNG GỒM CÁC THÔNG TIN CƠ BẢN SAU : 
        //+NGÀY ĐẶT HÀNG, ĐỊA CHỈ GIAO HÀNG, NGÀY DỰ ĐỊNH GIAO HÀNG
        //+PHÍ VẬN CHUYỂN, TỔNG TIỀN CẦN THANH TOÁN
        //+CÁC SẢN PHẨM KHÁCH HÀNG ĐÃ CHỌN MUA
class GioHang{
    private:
        //NGÀY ĐẶT HÀNG VÀ DỰ ĐỊNH GIAO HÀN
        Ngay ngayDatHang, ngayDuDinhGiaoHang;
        //ĐỊA CHỈ GIAO HÀNG
        string diaChiGiaoHang;
        //PHÍ VẬN CHUYỂN VÀ TỔNG TIỀN THANH TOÁN
        int phiVanChuyen, tongTienCanThanhToan;
        //DANH SÁCH CÁC SẢN PHẨM ĐÃ MUA
        vector<SanPham> cacSanPhamDaChon;
    public:
        GioHang(){
            //MẶC ĐỊNH PHÍ VẬN CHUYỂN LÀ 50.000đ
            this->phiVanChuyen = 50000;
        }
        //HÀM GETTER
        Ngay getNgayDatHang(){return this->ngayDatHang;}
        string getDiaChiGiaoHang(){return this->diaChiGiaoHang;}
        Ngay getNgayDuDinhGiaoHang(){return this->ngayDuDinhGiaoHang;}
        int getChiPhiVanChuyen(){return this->phiVanChuyen;}
        int getTongTienCanThanhToan(){return this->tongTienCanThanhToan;}
        vector<SanPham> getDanhSachCacSanPhamDaChon(){return this->cacSanPhamDaChon;}
        //HÀM SETTER
        void setNgayDatHang(Ngay ngay){this->ngayDatHang = ngay;}
        void setNgayDuDinhGiaoHang(Ngay ngay){this->ngayDuDinhGiaoHang = ngay;}
        void setDiaChiGiaoHang(string diaChi){this->diaChiGiaoHang = diaChi;}
        void setChiPhiVanChuyen(int phi){this->phiVanChuyen = phi;}
        void setTongTienCanThanhToan(int tongTien){this->tongTienCanThanhToan = tongTien;}
        void setCacSanPhamDaChon(vector<SanPham> dsSanPham){this->cacSanPhamDaChon = dsSanPham;}

        //KIỂM TRA XEM PHẦN TỬ ĐÃ CÓ TỒN TẠI TRONG DANH SÁCH MUA CHƯA
        //NẾU CHƯA TRẢ VỀ FALSE, ĐÃ TỒN TẠI TRẢ VỀ TRUE
        int kiemTraSanPhamDaTonTai(SanPham a){
            for (int i = 0; i < this->cacSanPhamDaChon.size(); i++)
            {
                if(a.getID().compare(this->cacSanPhamDaChon.at(i).getID()) == 0){
                    return i;
                }
            }
            return -1;
        }
        //THÊM SẢN PHẨM VÀO GIỎ HÀNG
        void themSanPham(SanPham a){
            // cacSanPhamDaChon.push_back(a);
            //NẾU SẢN PHẨM CHƯA TỒN TẠI THÌ THÊM MỚI
            int pos = kiemTraSanPhamDaTonTai(a);
            if(pos == -1){
                a.them(1);
                this->cacSanPhamDaChon.push_back(a);
            }
            //NẾU ĐÃ TỒN TẠI THÌ CẬP NHẬT LẠI SỐ LƯỢNG
            else{
                this->cacSanPhamDaChon[pos].them(1);
            }
        }
        //XEM GIỎ HÀNG
        void xemGioHang(){
            cout<<setw(80)<<"=>CAC SAN PHAM<=\n";
            for(SanPham a : cacSanPhamDaChon){
                cout<<setw(85)<<a;
            }
        }
        //HIỂN THỊ THÔNG TIN GIỎ HÀNG
        void hienThiThongTinGioHang(){
            this->ngayDuDinhGiaoHang.setNgay(to_string(stoi(this->ngayDatHang.getNgay())+7));
            int tongTien = 0;
            cout<<" =>THONG TIN GIO HANG<=\n";
            cout<<setw(80)<<"-> NGAY DAT HANG : "<<this->ngayDatHang.getNgayThangNam()<<"\n";
            cout<<setw(84)<<"-> DIA CHI GIAO HANG : "<<this->getDiaChiGiaoHang()<<"\n";
            cout<<setw(81)<<"-> NGAY GIAO HANG : "<<this->ngayDuDinhGiaoHang.getNgayThangNam()<<"\n";
            cout<<setw(87)<<"-> CAC SAN PHAM DA CHON : "<<"\n";
            for(SanPham a : cacSanPhamDaChon){
                cout<<setw(55)<<"    + ";
                a.hienThiThongTin();
                tongTien+=a.getTongTienSanPham();
            }
            this->tongTienCanThanhToan = tongTien;
            cout<<setw(82)<<"-> PHI VAN CHUYEN : "<<this->getChiPhiVanChuyen()<<"\n";
            cout<<setw(103)<<"->TONG TIEN CAN THANH TOAN(BAO GOM PHI) : "<<tongTien+this->phiVanChuyen<<"\n";
        }

        int getTinhTongTienCanThanhToan(){
            int sum = 0;
            for(SanPham a : cacSanPhamDaChon){
                sum+=a.getTongTienSanPham();
            }
            return sum+this->phiVanChuyen;
        }

        //TRẢ VỀ THÔNG TIN GIỎ HÀNG
        string getThongTinGioHang(){
            string text = "";
            for(auto a : cacSanPhamDaChon){
                text.append(a.getThongTinSanPham());
            }
            this->ngayDuDinhGiaoHang.setNgay(to_string(stoi(this->ngayDatHang.getNgay())+7));
            text.append("NGAY DAT HANG : "+this->ngayDatHang.getNgayThangNam()+"\n");
            text.append("DIA CHI GIAO HANG : "+this->diaChiGiaoHang+"\n");
            text.append("NGAY GIAO HANG : "+this->ngayDuDinhGiaoHang.getNgayThangNam()+"\n");
            text.append("PHI VAN CHUYEN : "+to_string(this->phiVanChuyen)+"\n");
            text.append("TONG TIEN THANH TOAN : "+to_string(this->getTinhTongTienCanThanhToan())+"\n");
            return text;
        }
};


//CLASS KHÁCH HÀNG
//GỒM NHỮNG THÔNG TIN CƠ BẢN SAU : HỌ TÊN, SỐ ĐIỆN THOẠI, GIỎ HÀNG
class KhachHang{
    private:
        string tenKhachHang, soDienThoai;
        GioHang gioHang;
    public:
        KhachHang(){};
        //HÀM GETTER
        string getTenKhachHang(){return this->tenKhachHang;}
        string getSoDienThoai(){return this->soDienThoai;}
        GioHang getGioHang(){return this->gioHang;}
        //HÀM SETTER
        void setTen(string ten){this->tenKhachHang = ten;}
        void setSoDienThoai(string sdt){this->soDienThoai = sdt;}
        void setGioHang(GioHang a){this->gioHang = a;}

        //QUÁ TẢI TOÁN TỬ XUẤT, NHẬP
        friend ostream& operator<<(ostream& out,const KhachHang);
        friend istream& operator>>(istream& in, KhachHang&);

        //HÀM ĐẶT HÀNG
        void datHang(){
            cin>>(*this);//NHẬP THÔNG TIN KHÁCH HÀNG
            cout<<(*this);//HIỂN THỊ THÔNG TIN KHÁCH HÀNG VÀ ĐƠN HÀNG
            cout<<setw(60)<<"";
            this->getGioHang().hienThiThongTinGioHang();
        }

        //HÀM TRẢ VỀ THÔNG TIN VÀ ĐƠN HÀN ĐỂ TIỆN GHI VÀO FILE TEXT
        string getThongTinVaDonHang(){
            string text = "";
            text.append("HO TEN : "+this->tenKhachHang+"\n");
            text.append("SO DIEN THOAI : "+this->soDienThoai+"\n");
            text.append(this->gioHang.getThongTinGioHang());
            return text;
        }
        //CHỨC NĂNG BỔ SUNG (NGOÀI CHẮC NĂNG YÊU CẦU CƠ BẢN CỦA BÀI)
        void ghiThongTinKhachHangVaDonHangVaoFileText(){
            ofstream ghiFile;       // tạo đối tượng ghiFile kiểu ofstream để ghi dữ liệu vào file data.txt
            ghiFile.open("khachHang.txt",ios::out | ios::app);   // ghi file ở chế độ nối liền vào cuối file hiện có
            // ghiFile<<a.getThongTinVaDonHang();
            ghiFile<<this->getThongTinVaDonHang();
            ghiFile<<"\n";
            ghiFile.close(); // đóng file.
        }
};
//QUÁ TẢI TOÁN TỬ XUẤT
ostream& operator<<(ostream &out,const KhachHang khachHang)
{
    out<<"\n"<<setw(75)<<"=> DON HANG : \n";
    out<<setw(70)<<"HO TEN : "<<khachHang.tenKhachHang<<"\n";
    out<<setw(77)<<"SO DIEN THOAI : "<<khachHang.soDienThoai<<"\n";

    return out;
}
//QUÁ TẢI TOÁN TỬ NHẬP
istream& operator>>(istream& in, KhachHang& khachHang)
{
    string ten,sdt,diaChi;
    in.ignore();
    cout<<"\n"<<setw(80)<<"NHAP HO TEN : ";
    getline(in,ten);
    khachHang.setTen(ten);
    cout<<setw(80)<<"NHAP SO DIEN THOAI : ";
    getline(in,sdt);
    khachHang.setSoDienThoai(sdt);
    cout<<setw(80)<<"NHAP DIA CHI GIAO HANG : ";
    getline(in,diaChi);
    khachHang.gioHang.setDiaChiGiaoHang(diaChi);
    return in;
}

//ĐỌC DANH SÁCH CÁC SẢN PHẨM CÓ TRONG FILE TXT
void docFileSanPham(vector<SanPham>& dsSanPham){
    int id = 0;
    ifstream filein;// tạo đối tượng để mở file
    filein.open("sanPham.txt",ios::in); // mở file .txt
    while (!filein.eof())   // nếu file khác rỗng thì bắt đầu load dữ liệu
    {
        ++id;
        SanPham sanPham;
        //SET ID CHO SẢN PHẨM
        sanPham.setID(to_string(id));
        string tenSanPham, giaSanPham;
        getline(filein,tenSanPham,'\n');//GET TÊN SẢN PHẦM
        sanPham.setTenSanPham(tenSanPham);
        getline(filein,giaSanPham,'\n');//GET GIÁ SẢN PHẨM
        sanPham.setGiaSanPham(stoi(giaSanPham));
        dsSanPham.push_back(sanPham);
    }   
    filein.close();// đóng file sau khi hoàn tất việc đọc file.
}



//MENU 
void MENU(){
    cout<<setw(100)<<"==========================================\n";
    cout<<setw(100)<<"=                1. MUA HANG.            =\n";
    cout<<setw(100)<<"=                2. THOAT.               =\n";
    cout<<setw(100)<<"==========================================\n";
}

//HIỂN THỊ DANH SÁCH CÁCH SẢN PHẨM
void hienThiSanPham(vector<SanPham> dsSanPham){
    cout<<"\n";
    int i = 0;
    for(SanPham a : dsSanPham){
        cout<<setw(55)<<++i<<" => ";
        a.hienThi();
    }
}

//KIỂM TRA SẢN PHẨM MÀ NGƯỜI DÙNG CHỌN HỢP LỆ HAY KHÔNG
bool kiemTraLuaChonSanPhamHopLe(string input, int size){
    for(char ch : input){
        if(isdigit(ch) == 0){
            return false;
        }
    }
    if(stoi(input) < 0 || stoi(input) > size ){
        return false;
    }
    return true;
}


//BẮT ĐẦU CHƯƠNG TRÌNH CHÍNH CHO KHÁCH HÀNG LỰA CHỌN DỰA THEO MENU
void batDauChuongTrinh(vector<SanPham> danhSachSanPham){

    system("cls");//CLEAN MÀN HÌNG
    while (true)
    {
        KhachHang khachHang;
        GioHang gioHang;
        int luaChonInt;
        string luaChonStr;
        stringstream ss;
        MENU();
        cout<<"\n"<<setw(80)<<"LUA CHON => ";
        cin>>luaChonStr;
        ss.str(luaChonStr);
        ss>>luaChonInt;   
        while (true)
        {
            if (luaChonInt != 1 && luaChonInt != 2)
            {
                stringstream ss;
                system("cls");
                cout<<"\n"<<setw(100)<<"LUA CHON KHONG HOP LE ! HAY CHON LAI \n\n";
                MENU();
                cout<<"\n"<<setw(80)<<"LUA CHON => ";
                cin>>luaChonStr;
                ss.str(luaChonStr);
                ss>>luaChonInt;
            }
            else{break;}
        }

    
        //SWITCH CÁC TRƯỜNG HỢP LỰA CHỌN
        switch (luaChonInt) // dùng switch để phân ra các lựa chọn phù hợp của người dùng để thực thi các đoạn mã phù hợp
        {
            case 1:
                hienThiSanPham(danhSachSanPham);
                //MUA HÀNG
                int luaChonModeInt;
                while (true)
                {
                    string luaChonModeStr;
                    stringstream ssMode;
                    cout<<"\n"<<setw(80)<<"LUA CHON SAN PHAM => ";
                    cin>>luaChonModeStr;
                    ssMode.str(luaChonModeStr);
                    ssMode>>luaChonModeInt;

                    while (true)
                    {
                        //NẾU LỰA CHỌN KHÁC CÁC LỰA CHỌN TRONG MENU THÌ THÔNG BÁO SAI
                        if (!kiemTraLuaChonSanPhamHopLe(luaChonModeStr,danhSachSanPham.size()))
                        {
                            stringstream ssMode;
                            cout<<"\n"<<setw(115)<<"LUA CHON SAN PHAM KHONG HOP LE ! HAY CHON LAI .\n\n";
                            cout<<"\n"<<setw(95)<<"LUA CHON SAN PHAM => ";
                            cin>>luaChonModeStr;
                            ssMode.str(luaChonModeStr);
                            ssMode>>luaChonModeInt;
                        }
                        else{
                            break;
                        }
                    }
                    //LẤY RA SẢN PHẨM ĐƯỢC CHỌN
                    SanPham sanpham = danhSachSanPham.at(luaChonModeInt-1);

                    //SET SỐ LƯỢNG MUA LÀ 1
                    gioHang.themSanPham(sanpham);

                    cout<<"\n"<<setw(110)<<"TIEP TUC MUA(1)         XEM GIO HANG(2)          DAT HANG(3)\n";
                    int ASCII;
                    char ch;
                    ch = getch();
                    ASCII = ch;
                    while (true)
                    {
                        //MÃ ASCII CỦA 1 LÀ 49, 2 LÀ 50, 3 LÀ 51
                        if(ASCII != 49 && ASCII != 50 && ASCII != 51){
                            cout<<setw(80)<<"CHON SAI, VUI LONG CHON LAI !\n";
                            ch = getch();
                            ASCII = ch;
                        }
                        else{
                            break;
                        }
                    }
                    //SWITCH 3 LỰA CHỌN TIẾP TỤC MUA, XEM GIỎ HÀNG, ĐẶT HÀNG.
                    switch (ASCII)
                    {
                        //PHÍM 1
                        case 49:
                            continue;
                            break;
                        //PHÍM 2
                        case 50:
                            gioHang.xemGioHang();
                            // khachHang.getGioHang().xemGioHang();
                            system("pause>nul");
                            break;
                        //PHÍM 3    
                        case 51:
                            khachHang.setGioHang(gioHang);
                            khachHang.datHang();
                            khachHang.ghiThongTinKhachHangVaDonHangVaoFileText();
                            system("pause>nul");
                            system("cls");
                            break;    
                        default:
                            break;
                    }
                    //NẾU ĐÃ THANH TOÁN THÌ NHẢY RA NGOÀI VÀ BẮT CHO KHÁCH HÀNG MỚI MUA HÀNG
                    if(ASCII == 51){
                        break;
                    }
                }
                system("cls");
                break;
            case 2:
            //THOÁT
                int maAscii;
                char key_press;
                cout<<"\n"<<setw(101)<<">> BAN CO CHAC MUON THOAT CHUONG TRINH ? <<\n\n";
                cout<<setw(80)<<"THOAT(ESC)          "<<"TIEP TUC(ENTER)\n";                
                while(true)
                {
                    key_press = getch();
                    maAscii = key_press;   // CHUYỂN PHÍM VỪA NHẤN SANG MÃ ASCII
                    if (maAscii == 13){break;} // NẾU NHẤN ENTER THÌ TIẾP TỤC CHƯƠNG TRÌNH
                    if (maAscii == 27){system("cls");exit(0);} //NẾU NHẤN ESC LÀ THOÁT CHƯƠNG TRÌNH
                }
                system("cls");
                break;
            default:
                break;
        }

    }
    
}

int main(){
    vector<SanPham> danhSachSanPham;
    docFileSanPham(danhSachSanPham);
    batDauChuongTrinh(danhSachSanPham);
    system("pause>nul");
    return 0;
}