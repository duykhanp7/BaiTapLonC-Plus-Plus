#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<istream>
#include<ostream>
#include<iomanip>
#include<conio.h>
#include<ctime>
#include<windows.h>
#include<chrono>
#include<stdlib.h>
#include<cctype>
#include<sstream>
#include<algorithm>
#pragma warning(disable:4996)

using namespace std;

class Time // tạo class Time 
{
private:
    int gio;
    int phut;
    int giay;
public:
    Time(int g=0, int p=0,int gi=0){this->gio=g;this->phut=p;this->giay = gi;}// hàm tạo Time có tham số mặc định
    void display()                                                             // hàm hiển thị thời gian
    {
        cout<<this->gio<<":"<<this->phut<<":"<<this->giay;
    }
    int getGio(){return this->gio;} // trả về giờ
    int getPhut(){return this->phut;}// trả về phút
    int getGiay(){return this->giay;}// trả về giây
    void setGio(int a){this->gio =a;}// gán giờ cho đối tượng
    void setPhut(int a){this->phut = a;}// gán phút cho đối tượng
    void setGiay(int a){this->giay = a;}// gán giây cho đối tượng
    Time operator-(Time c) //  quá tải toán tử - để trừ hai mốc thời gian cho nhau và trả về 1 mốc thời gian khác
    {
        Time k;
        k.gio = this->gio - c.gio;
        k.phut = this->phut - c.phut;
        k.giay = this->giay - c.giay;
        return k;
    }
};


class Question // Tạo class Question để lưu các thông tin về 1 câu hỏi.
{
private:
//Các thuộc tính của câu hỏi.
    string cauHoi;// câu hỏi
    string dapAnA;// đáp án A
    string dapAnB;// đáp án B
    string dapAnC;// đáp án C
    string dapAnD;// đáp án D
    char cauTraLoiCuaBan;// câu trả lời của thí sinh
    string dapAnDung;// đáp án đúng của câu hỏi
public:
    // Hàm tạo mặc định và có tham số với các đáp án A,B,C,D, câu trả lời, đáp án mặc định là rỗng.
    Question(string cauhoi = "",string dapA = "",string dapB = "",string dapC = "",string dapD = "",char cautraloi=' ',string ketqua = "")
    {
        this->cauHoi = cauhoi;
        this->dapAnA = dapA;
        this->dapAnB = dapB;
        this->dapAnC = dapC;
        this->dapAnD = dapD;
        this->cauTraLoiCuaBan = cautraloi;
        this->dapAnDung = ketqua;
    }

    void setCauHoi(string a){this->cauHoi = a;} // tạo nội dung câu hỏi
    void setDapAnA(string A){this->dapAnA = A;} // tạo đáp án A
    void setDapAnB(string B){this->dapAnB = B;} // tạo đáp án B
    void setDapAnC(string C){this->dapAnC = C;} // tạo đáp án C
    void setDapAnD(string D){this->dapAnD = D;} // tạo đáp án D
    void setCauTraLoi(char traloi){this->cauTraLoiCuaBan = traloi;} // tạo câu trả lời của thí sinh cho câu hỏi
    void setDapAnDung(string E){this->dapAnDung = E;} // tạo đáp án đúng

    string getCauHoi(){return this->cauHoi;} //trả về nội dung câu hỏi
    string getDapAnA(){return this->dapAnA;} // trả về nội dung đáp án A.
    string getDapAnB(){return this->dapAnB;} // trả về nội dung đáp án B.
    string getDapAnC(){return this->dapAnC;} // trả về nội dung đáp án C.
    string getDapAnD(){return this->dapAnD;} // trả về nội dung đáp án D.
    char getCauTraLoi(){return this->cauTraLoiCuaBan;} // trả về câu trả lười
    string getDapAnDung(){return this->dapAnDung;} // trả về đáp án đúng

    friend ostream& operator<<(ostream&,const Question&); // quá tải toán tử xuất để xuất các thuộc tính của câu hỏi(code ở dòng 98)

    void display()// xuất thuộc tính của câu hỏi và dáp án đúng
    {
        cout<<(*this);
        cout<<"Dan an cua ban la :"<<this->cauTraLoiCuaBan<<"\n";
        cout<<"Dap an dung : "<<this->dapAnDung<<"\n\n";
    }
};

ostream& operator<<(ostream& out,const Question& ques)// quá tải toán tử xuất để xuất các thuộc tính của câu hỏi
{
    out<<setw(63+ques.cauHoi.size())<<ques.cauHoi<<"\n";
    out<<setw(75)<<"A : "<<ques.dapAnA<<"\n";
    out<<setw(75)<<"B : "<<ques.dapAnB<<"\n";
    out<<setw(75)<<"C : "<<ques.dapAnC<<"\n";
    out<<setw(75)<<"D : "<<ques.dapAnD<<"\n";
    return out;
}


class Person // tạo class Person để lưu thông tin của thí sinh, điểm và thời gian làm bài.
{
private:
    string hoTen; // họ tên
    int namSinh; // năm sinh
    string gioiTinh; // giới tính
    string sdt; // số điện thoại
    double diemKq; // điểm thi
    Time thoiGianBatDau; //  thời gian bắt đầu làm bài
    Time thoiGianKetThuc;// thời gian kết thúc bài thi
    int thoigianlambai;// tổng thời gian làm bài
public:
    // hàm tạo mặc định có tham số, đều là rỗng(NUll) và bằng 0.
    Person(string hoten="", int namsinh=0, string gioitinh="", string sdt="", double diem=0,int thoigian = 0)
    {
        this->hoTen = hoten;
        this->namSinh = namsinh;
        this->gioiTinh = gioitinh;
        this->sdt = sdt;
        this->diemKq = diem;
        this->thoiGianBatDau.setGio(0);
        this->thoiGianBatDau.setPhut(0);
        this->thoiGianBatDau.setGiay(0);
        this->thoigianlambai = thoigian;
    }
    
    string getHoTen(){return this->hoTen;}// trả về tên của thí sinh
    int getNamSinh(){return this->namSinh;}// trả về năm sinh của thí sinh
    string getGioiTinh(){return this->gioiTinh;}// trả về giới tính thí sinh
    string getSdt(){return this->sdt;}// trả về số điện thoại thí sinh
    double getDiem(){return this->diemKq;}// trả về điểm thí sinh đã đạt được
    Time getThoiGianBD(){return this->thoiGianBatDau;}// trả về thời gian bắt đầu làm bài
    Time getThoiGianKT(){return this->thoiGianKetThuc;}// trả về thời gian kết thúc bài thi
    int getTongThoiGianLam(){return this->thoigianlambai;}// trả về tổng thời gian thí sinh đã làm

    void setHoten(string ten){this->hoTen = ten;} // gán tên cho đối tượng.
    void setNamSinh(int namsinh){this->namSinh = namsinh;}// gán năm sinh cho đối tượng
    void setGioiTinh(string gioitinh){this->gioiTinh = gioitinh;}// gán giới tính cho đối tượng
    void setSdt(string sdt_){this->sdt = sdt_;}// gán số điện thoại cho đối tượng
    void setDiem(double diem){this->diemKq = diem;}// gán điểm cho đối tượng
    void setThoiGianBatDau(Time tg){this->thoiGianBatDau = tg;}// gán thời gian bắt đầu làm bài cho đối tượng
    // gán thời gian bắt đầu làm bài cho đối tượng
    void setThoiGianBatDau(int a, int b, int c){this->thoiGianBatDau.setGio(a);this->thoiGianBatDau.setPhut(b);this->thoiGianBatDau.setGiay(c);}
    void setThoiGianKetThuc(Time tg){this->thoiGianKetThuc = tg;}// gán thời gian kết thúc làm bài cho đối tượng
    // gán thời gian kết thúc làm bài cho đối tượng
    void setThoiGianKetThuc(int a, int b, int c){this->thoiGianKetThuc.setGio(a);this->thoiGianKetThuc.setPhut(b);this->thoiGianKetThuc.setGiay(c);}
    void settongThoiGianLamBai(int a){this->thoigianlambai = a;}// gán tổng thời gian làm bài của thí sinh
    int tongThoiGianLamBaiT()// tính tổng thời gian làm bài của thí sinh
    {
       int giayBD = ((this->thoiGianBatDau.getGio()*60*60)+(this->thoiGianBatDau.getPhut()*60)+this->thoiGianBatDau.getGiay());
       int giayKT = ((this->thoiGianKetThuc.getGio()*60*60) + (this->thoiGianKetThuc.getPhut()*60) + this->thoiGianKetThuc.getGiay());
       this->thoigianlambai = giayKT - giayBD;
       return (giayKT - giayBD);
    }


    friend ostream& operator<<(ostream& out,const Person); // quá tải toán tử xuất << để hiện thị thông tin thí sinh(code ở dòng 191)
    friend istream& operator>>(istream& in,Person&);// quá tải toán tử nhập >> để nhập thông tin thí sinh(code ở dòng 200)
    friend bool operator>(const Person& a, const Person& b); // quá tải toán tử lớn hơn để so sánh hai sinh viên theo điểm cao đến thấp(code ở dòng 170)
    friend bool operator<(const Person& a, const Person& b);// quá tải toán tử lớn hơn để so sánh hai sinh viên theo điểm thấp đến cao(code ở dòng 176)
    void display()                                          // hàm display để hiển thị thông tin thí sinh cùng với điểm, thời gian làm bài
    {
        cout<<(*this);
        cout<<setw(76)<<"Diem : "<<this->getDiem()<<"\n";
        cout<<setw(89)<<"Thoi gian bat dau : ";
        this->getThoiGianBD().display();
        cout<<"\n";
        cout<<setw(94)<<"Tong thoi gian lam bai : "<<this->tongThoiGianLamBaiT()<<" giay\n";
    }
};

bool operator>(const Person& a, const Person& b)// quá tải toán tử lớn hơn để so sánh hai sinh viên theo điểm cao đến thấp
{
    return a.diemKq > b.diemKq;
}


bool operator<(const Person& a, const Person& b)// quá tải toán tử lớn hơn để so sánh hai sinh viên theo điểm thấp đến cao
{
    return a.diemKq < b.diemKq;
}



ostream& operator<<(ostream &out,const Person per)// quá tải toán tử xuất << để hiện thị thông tin thí sinh
{
    out<<setw(78)<<"Ho ten : "<<per.hoTen<<"\n";
    out<<setw(80)<<"Nam sinh : "<<per.namSinh<<"\n";
    out<<setw(81)<<"Gioi tinh : "<<per.gioiTinh<<"\n";
    out<<setw(85)<<"So dien thoai : "<<per.sdt<<"\n";
    return out;
}

istream& operator>>(istream& in, Person& per)// quá tải toán tử nhập >> để nhập thông tin thí sinh
{
    string arr;
    int namsinh;
    in.ignore();
    cout<<"\n"<<setw(80)<<"Nhap ho ten : ";
    getline(in,arr);
    per.setHoten(arr);
    cout<<setw(82)<<"Nhap nam sinh : ";
    in>>namsinh;
    per.setNamSinh(namsinh);
    in.ignore();
    cout<<setw(83)<<"Nhap gioi tinh : ";
    getline(in,arr);
    per.setGioiTinh(arr);
    cout<<setw(87)<<"Nhap so dien thoai : ";
    getline(in,arr);
    per.setSdt(arr);
    return in;
}

void readFile(vector<Question> &vec1) // đọc dữ liệu từ file .txt và đưa vào vector chứa câu hỏi(vector<Question>)
{
    Question q; // tạo 1 đối tượng có kiểu dữ liệu là Question
    string arr; // biến tạm để lưu dữ liệu xuất ra từ file.
    ifstream filein;// tạo đối tượng để mở file
    filein.open("data.txt",ios::in); // mở file .txt
    while (!filein.eof())   // nếu file khác rỗng thì bắt đầu load dữ liệu
    {
        getline(filein,arr,'\n');// gán nội dung câu hỏi từ file vào biến arr
        q.setCauHoi(arr);         // gán nội dung câu hỏi cho đối tượng q
        getline(filein,arr,'\n'); // gán nội dung câu hỏi từ file vào biến arr
        q.setDapAnA(arr);        // gán nội dung đáp án A cho đối tượng q
        getline(filein,arr,'\n'); // gán nội dung câu hỏi từ file vào biến arr       
        q.setDapAnB(arr);        // gán nội dung đáp án B cho đối tượng q
        getline(filein,arr,'\n');// gán nội dung câu hỏi từ file vào biến arr
        q.setDapAnC(arr);        // gán nội dung đáp án C cho đối tượng q
        getline(filein,arr,'\n'); // gán nội dung câu hỏi từ file vào biến arr
        q.setDapAnD(arr);         // gán nội dung đáp án D cho đối tượng q
        getline(filein,arr,'\n');// gán nội dung câu hỏi từ file vào biến arr
        q.setDapAnDung(arr);    // gán nội dung đáp án đúng của câu hỏi này cho đối tượng q
        vec1.push_back(q);// sau khi load đủ thông tin về câu hỏi(nội dung câu hỏi, đáp án :ABCD và đáp án đúng)
                          // ta sẽ đẩy câu hỏi này vào vector, vector này sẽ chứa danh sách các câu hỏi để hiển thị
    }   
    filein.close();// đóng file sau khi hoàn tất việc đọc file.
}


void Menu()// danh sách các lựa chọn
{
    //setw(n) : tạo độ dài khoảng trắng nằm ngang -- giống như tab trong word
    // cout<<"\n\n\n\n\n\n";
    cout<<setw(120)<<"==================================================================\n";
    cout<<setw(85)<<"==                   1. BAT DAU."<<setw(35)<<"==\n";
    cout<<setw(87)<<"==                   2. HUONG DAN."<<setw(33)<<"==\n";
    cout<<setw(94)<<"==                   3. LAN THI GAN NHAT."<<setw(26)<<"==\n";
    cout<<setw(94)<<"==                   4. HIEN THI DAP DAN."<<setw(26)<<"==\n";
    cout<<setw(112)<<"==                   5. HIEN THI DANH SACH THI SINH DA THI."<<setw(8)<<" ==\n";
    cout<<setw(83)<<"==                   6. THOAT."<<setw(37)<<"==\n";
    cout<<setw(120)<<"==================================================================\n";
}

bool checkEndQuiz(int x,vector<Question> m)// hàm kiểm tra bài thi đã kết thúc chưa
{                                          // nếu bài thi đã hết thì trả về true, chưa hết thì trả về false
    if (x == m.size()){return true;}       // ở đây biến x là stt của câu hỏi hiện tại, m.size() là số lượng câu hỏi
    return false;                           // nếu stt câu hỏi hiện tại bằng m.size() thì bài thi kết thúc
}

// int batSuKienPhim(char nhanPhim)// hàm bắt sự kiện bàn phím SPACE để bỏ qua câu hỏi hiện tại
// {                               // phím TAB để quay về câu hỏi phía trước
//     int ascii_Phim = nhanPhim; // hàm này trả về mã ascii của phím được nhập vào từ bàn phím người sử dụng
//     return ascii_Phim;      // trả về mã ASCII của phím được nhập.
// }

bool kiemTraDapAnHopLe(char dapAn) // kiểm tra xem câu trả lời của người dùng có hợp lệ không
{                                   // A B C D a b c d là các đáp án hợp lệ
                                    // nếu hợp lệ trả về true, không hợp lệ trả về false
    if (dapAn=='A' || dapAn=='a' || dapAn=='B' || dapAn=='b' ||dapAn=='C' ||dapAn=='c' ||dapAn=='D' ||dapAn=='d')
    {return true;}
    return false;
}

Time thoiGianHeThong() // hàm này lấy thời gian hiện tại của hệ thống và trả về 1 đối tượng có kiểu dữ liệu là Time
{
    Time t;
    time_t curr;
    curr = time(NULL);
    tm* time_curr = localtime(&curr);
    t.setGio(time_curr->tm_hour);    // lấy giờ
    t.setPhut(time_curr->tm_min);    // lấy phút
    t.setGiay(time_curr->tm_sec);    // lấy giây
    return t;
}

void tinhDiem(Person &p,vector<Question> v) //tính điểm mà thí sinh đã đạt được
{
    int diem = 0,i=0;
    string temp;
    for (int i = 0; i < v.size(); i++)
    {
        temp = v[i].getDapAnDung();                 // vòng lặp so sánh đáp án của thí sinh với đáp án đúng của câu hỏi
        if (v[i].getCauTraLoi() == temp[0]){diem++;}// nếu câu trả lời đúng thì sẽ được cộng 1 điểm, sai thì không sao
    }
    Time t = thoiGianHeThong(); // gọi hàm thoiGianHeThong() là để lấy thời gian lúc kết thúc bài thi
    p.setDiem(diem);            // gán điểm thí sinh đã đạt được
    p.setThoiGianKetThuc(t);    // gán thời gian kết thúc cho thí sinh
    p.display();                // hiển thị thông tin thí sinh, điểm thi, thời gian bắt đầu, tổng thời gian làm bài
    cout<<setw(83)<<"Tong so cau : "<<v.size()<<"\n";
    cout<<setw(83)<<"So cau dung : "<<diem<<"\n";
}

bool kiemTraDaTraLoiHetChua(vector<Question> vec) // kiểm tra xem thí sinh đã trả lời hết câu hỏi chưa
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i].getCauTraLoi() == ' '){return false;} // nếu câu trả lời rỗng thì đã làm rồi và trả về false
    }
    return true;                                            // nếu câu trả lời khác rỗng thì đã làm rồi và trả về true
}

void hienThiCauHoi(vector<Question>& vecc) // hiển thị câu hỏi 
{
    // trong quá trình trả lời câu hỏi thì thí sinh có thể nhấn phím ESC để thoát bài thi và bài thi sẽ không được tính điểm
    int i = 0,ascii;                        // ascii để lấy mã của phím nhập từ bàn phím
    char cauTraLoi;                         // câu trả lời của thí sinh
    cout<<setw(90)<<"--Bai Thi Co "<<vecc.size()<<" Cau Hoi--\n";
    cout<<setw(83)<<">>Ban Co "<<vecc.size()+1<<" Phut Tra Loi Cau Hoi<<\n";
    cout<<setw(107)<<"-> Moi Cau Dung Se Duoc 1 Diem <-\n";
    system("pause>nul");
    system("cls");
    while (!vecc.empty() && i < vecc.size()&& i>=0) // điều kiện để chạy vòng lặp là danh sách câu hỏi phảo rỗng(vec)
    {                                               // chỉ số i của câu hỏi hiện tại phải lớn hơn = 0 và bé hơn tổng số câu hỏi
        cout<<vecc[i];
        cout<<setw(72)<<"Dap An : ";
        cauTraLoi = getch();                        // bắt câu trả lời từ bàn phím người dùng
        cout<<cauTraLoi;                            
        ascii = cauTraLoi;                          
        if (ascii != 27 && ascii != 32 && ascii != 9)
        {
            system("pause>nul");
        }
        if (ascii == 27) // nhấn phím ESC để thoát phần khỏi bài thi
        {
            if (!kiemTraDaTraLoiHetChua(vecc)) // nếu thoát trong khi chưa hoàn thành bài thi
            {                                   // thì nó sẽ thông báo dòng chữ phía dưới
                system("cls");
                cout<<setw(108)<<">> Bai Kiem Tra Chua Duoc Hoan Thanh <<\n";// dòng thông báo này sẽ được hiển thị
                cout<<setw(87)<<"Thoat(ESC)      "<<"Tiep tuc(ENTER)\n";    // nếu là phím ENTER thì thí sinh sẽ tiếp tục làm bài thi
                while (true)                                                // nếu là phím ESC thì sẽ thoát bài thi và không tính điểm
                {
                    cauTraLoi = getch();
                    ascii = cauTraLoi;
                    if (ascii == 13){system("cls");break;}// phím ENTER
                    if (ascii == 27){system("cls");exit(0);} //phím ESC
                }
                continue;// sau đó nó ENTER được nhấn nó sẽ tiếp tục lại vòng lặp này để thí sinh tiếp tục bài thi
            }
        }

        if (ascii == 9)// nhấn phím Tab để trở về câu hỏi phía trước.
        {
            --i;
            if (i<=0){i=0;}    // nếu đang ở câu hỏi đầu tiên thì nó trong thể trở về câu hỏi phía trước nữa
            system("cls");      // và khi nhấn phím TAB thì nó sẽ luôn ở vị trí câu hỏi thứ nhất
            continue;
        }

        if (ascii == 32) // nhấn phím SPACE để bỏ qua câu hỏi
        {
            ++i;            // tăng chỉ số i lên 1 đơn vị
            // if (i > vecc.size()){i = 0;}
            system("cls");
            continue;// tiếp tục vòng lặp để hiển thị câu hỏi tiếp theo sau khi i được tăng lên 1 đơn vị
        }
        while (!kiemTraDapAnHopLe(cauTraLoi)) // kiểm tra xem đáp án thí sinh trả lời có hợp lệ hay không
        {                                     // nếu hợp lệ thì bỏ qua bước này và tiến đến câu hỏi tiếp theo
            if(!kiemTraDapAnHopLe(cauTraLoi))// nếu không hợp lệ thì yêu cầu thí sinh phải nhập lại câu trả lời
            {
                system("cls");
                cout<<"\n"<<setw(100)<<"Dap An Khong Hop Le! Hay Nhap Lai.\n";
                cout<<vecc[i];
                cout<<setw(72)<<"Dap An : ";
                cauTraLoi = getch();        // nhận câu trả lời của thí sinh
                cout<<cauTraLoi;
                ascii = cauTraLoi;
                if (ascii != 27 && ascii != 9 && ascii != 32) // nếu các phím ESC,TAB và SPACE thì lặp lại vòng lặp này
                {
                    system("pause>nul");
                }
                
                if (ascii == 27) // nhấn phím ESC để thoát phần thi
                {
                    if (!kiemTraDaTraLoiHetChua(vecc)) // kiểm tra nếu chưa hoàn thành bài thi thì sẽ hiển thị thông báo phía dưới
                    {
                        system("cls");
                        cout<<setw(108)<<">> Bai Kiem Tra Chua Duoc Hoan Thanh <<\n";
                        cout<<setw(87)<<"Thoat(ESC)      "<<"Tiep tuc(ENTER)\n";        // ESC để thoát, ENTER để tiếp tục
                        while (true)
                        {
                            cauTraLoi = getch();
                            ascii = cauTraLoi;
                            if (ascii == 13){break;}   // ENTER và tiếp tục bài thi
                            if (ascii == 27){system("cls");exit(0);} // ESC thoát bài thi
                        }
                    }
                }
                if (ascii == 32) // nhấn phím SPACE để bỏ qua câu hỏi
                {
                    ++i;        // tăng i lên thì sẽ qua câu hỏi tiếp theo
                    --i;        // giảm i để trờ về câu hỏi hiện tại
                    system("cls");
                    break;      // sau đó thoát vòng lặp này để tiếp tục vòng lặp phía bên ngoài tiếp tục xuất câu hỏi tiếp theo
                }
                if (ascii == 9)// nhấn phím Tab để trở về câu hỏi phía trước
                {
                    --i;        // giảm i để trờ về câu hỏi phía trước
                    if (i<=0){i=0;}    
                    --i;
                    system("cls");
                    break;      // sau đó thoát vòng lặp này để tiếp tục vòng lặp phía bên ngoài để trở về câu hỏi phía trước
                }
                system("cls");
            }
            continue; // nếu đáp thí sinh nhập hợp lệ thì nó thoát vòng lặp này và tiếp tục chương trình phía sau
        }
        vecc[i].setCauTraLoi(toupper(cauTraLoi));// câu trả lời hợp lệ sẽ được đưa và câu trả lời của thí sinh
        i++;
        system("cls");      // xóa màn hình
        if (i == vecc.size()) // nếu chỉ số i bằng tổng câu hỏi thì bài thi kết thúc và tính điểm
        {
            // dòng này để hỏi xem thí sinh có muốn thay đổi đáp án cho tất cả câu hỏi hay không
            // nếu đồng ỳ thay đổi nhấn phím số 0, nó sẽ đưa chỉ số i = 0 và tiếp tục vòng lặp để thay đổi đáp án mỗi câu hỏi
            // không đồng ý nhấn phím 1 và hệ thống sẽ tính điểm bài thi này 
            cout<<setw(100)<<"Bai Thi Cua Ban Da Het !\n"<<setw(101)<<"Ban Co Muon Thay Doi Dap An\n"<<setw(113)<<"->Nhan Phim So 0 Chinh Sua, Phim So 1 De Ket Thuc <-\n";
            cauTraLoi = getch();
            ascii = cauTraLoi;
            cout<<setw(80)<<"=> Lua Chon : "<<cauTraLoi;
            system("pause>nul");
            while (ascii != 48 && ascii != 49) // nếu lựa chọn của thí sinh không phải là 1 hoặc 0 thì yêu cầu nhập lại
            {
                if (ascii != 48 && ascii != 49)
                {
                    system("cls");
                    cout<<setw(100)<<"Loi, lua chon chua dung !!!\n";
                    cout<<setw(100)<<"Ban Co Muon Thay Doi Dap An\n"<<setw(113)<<"-> Nhan Phim So 0 Chinh Sua, Phim So 1 De Ket Thuc <-\n";
                    cauTraLoi = getch();
                    ascii = cauTraLoi;
                    cout<<setw(90)<<"-> Lua Chon : "<<cauTraLoi;
                    system("pause>nul");
                    if ( ascii == 48){break;} // nếu nhấn phím 0 thì mã ascii sẽ bằng 48 và thoát vòng lặp để chỉnh sửa câu trả lời
                    if (ascii == 49){break;}// nếu nhấn phím 1 thì mã ascii sẽ bằng 48 và thoát vòng lặp để thoát bài thi
                    if (ascii == 27){break;}// thoát chương trình
                }
                else{break;}
            }
            system("cls");
            if ( ascii == 48){i =0;continue;} // nếu là phím 0 thì bắt đầu chỉnh sửa
            if (ascii == 49){break;}    // phím 1 thì kết thúc bài thi và tính điểm
            if (ascii == 27){break;} // thoát chương trình
        }
    }

    // vòng lặp phía dưới sẽ hiển thị câu hỏi và đáp án của thí sinh
    for (int i = 0; i < vecc.size(); i++)
    {
        cout<<vecc[i];
		cout<<setw(83)<<"Dap an cua ban la : "<<vecc[i].getCauTraLoi()<<"\n\n";
    }
    system("pause>nul");
    system("cls");
}

void huongDan() // danh sách hướng dẫn thí sinh để làm bài
{
    cout<<setw(93)<<">> HUONG DAN <<\n";
    cout<<setw(125)<<"-> Tra loi cau hoi bang cach nhap cac dap an A(a), B(b), C(c) hoac D(d).\n"; // trả lời câu hỏi bằng cách nhập các đáp án A B C D
    cout<<setw(110)<<"-> Thoi gian tra loi bat dau khi cau hoi xuat hien.\n";           // thời gian bắt đầu làm bài khi câu hỏi xuất hiện
    cout<<setw(120)<<"-> De chuyen sang cau hoi tiep theo nhan phim -> SPACE <-.\n";          // nhấn phím SPACE để chuyển sang câu hỏi tiếp theo, bỏ qua câu hỏi hiện tại
    cout<<setw(120)<<"-> De tro ve cau hoi phia truoc nhan phim so -> TAB <-.\n";             // nhấn phím TAB để quay lại câu hỏi phía trước
    cout<<setw(115)<<"-> De thoat khoi bai thi nhan phim -> ESC <-.\n\n";                     // để thoát khỏi bài thi thì nhấn phím ESC
}

bool kiemTraDaLamBai(vector<Person> v,string ten) // kiểm tra thí sinh đã làm bài thi lần nào chưa
{
    for (int i = 0; i < v.size(); i++)
    {
        if (ten == v[i].getHoTen())                // nếu tên được nhập từ bàn phím bằng với tên của phần tử thứ i
        {                                          // thì trả về true, ngược lại sẽ không tìm thấy và trả về false
            return true;
        }
    }
    return false;
}

void hienThiCacLanThiGanNhat( vector<Person> v) // hàm này sẽ hiển thị các lần thi gần nhất của 1 thí sinh nào đó
{
    string ten;
    cout<<"\n"<<setw(85)<<"Nhap Ten : ";   // nhập tên thí sinh để kiểm tra xem thí sinh đã làm bài chưa
    cin.ignore();
    getline(cin,ten);
    int i =0;
    if (kiemTraDaLamBai(v,ten))             // hàm kiểm tra thí sinh đã làm bài chưa kiemTraDaLamBai()
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (ten == v[i].getHoTen())       // nếu tên phù hợp và đã làm bài rồi thì ở đây sẽ hiển thị
            {                                 // thông tin thí sinh và điểm thi, thời gian làm bài
                v[i].display();
                cout<<"\n";
            }
        }    
    }
    else                //nếu chưa kiểm tra lần nào thì dòng thông báo phía dưới sẽ xuất hiện
    {cout<<"\n"<<setw(110)<<"-> Ban Chua Thuc Hien Bai Thi Nao Gan Day <-\n";}

}

void ghiVaoFileText(Person p,vector<Question> v)    // ghi danh sách các thí sinh đã thi gồm thông tin và kết quả thi
{
    ofstream ghiFile;       // tạo đối tượng ghiFile kiểu ofstream để ghi dữ liệu vào file data.txt
    ghiFile.open("result.txt",ios::out | ios::app);   // ghi file ở chế độ nối liền vào cuối file hiện có
    ghiFile<<p.getHoTen()<<"\n";        // ghi họ tên vào file
    ghiFile<<p.getNamSinh()<<"\n";      // ghi năm sinh vào file
    ghiFile<<p.getGioiTinh()<<"\n";     // ghi giới tính vào file
    ghiFile<<p.getSdt()<<"\n";          // ghi sdt vào file
    ghiFile<<p.getDiem()<<"\n";         // ghi điểm vào file
    ghiFile<<v.size()<<"\n"; // số lượng câu hỏi
    ghiFile<<p.getThoiGianBD().getGio()<<":"<<p.getThoiGianBD().getPhut()<<":"<<p.getThoiGianBD().getGiay()<<"\n"; // ghi thời gian bắt đầu làm bài vào file
    ghiFile<<p.getThoiGianKT().getGio()<<":"<<p.getThoiGianKT().getPhut()<<":"<<p.getThoiGianKT().getGiay()<<"\n";// ghi thời gian kết thúc bài thi vào file
    ghiFile<<p.getTongThoiGianLam()<<"\n";  //ghi tổng thời gian thí sinh đã làm bài vào file
    ghiFile.close();        // đóng file.
}


void hienThiDapAn(vector<Person> v,vector<Question> ques)// hiển thị toàn bộ câu hỏi và đáp án đúng
{
    int i = 0;
    string ten;
    cin.ignore();
    cout<<"\n"<<setw(86)<<"Nhap Ten: ";     // nhập tên thí sinh
    getline(cin,ten);
    if (kiemTraDaLamBai(v,ten))             // dùng hàm kiemTraDaLamBai kiểm tra thí sinh đã làm bài chưa
    {                                       // nếu làm trả về true và hiển thị câu hỏi và đáp án đúng
        for(int i = 0; i< ques.size();i++)
        {
            cout<<ques[i];
            cout<<setw(77)<<"Dap An Dung : "<<ques[i].getDapAnDung()<<"\n\n";
        }
    }
    else
    {                                       // nếu chưa làm bài thì dòng thông báo phía dưới sẽ hiển thị.
        cout<<"\n"<<setw(105)<<"-> Hay Lam Bai Thi Truoc Khi Xem Dap An <-\n";
    }
    system("pause>nul");
    system("cls");
}


void sapXep(vector<Person>& per)//sắp xếp sinh viên theo thứ tự điểm cao đến thấp.
{

    // dùng hàm sort trong thư viện algorithm để sắp xếp thứ tự sinh viên theo tứ tự điểm cao đến thấp
    // hàm này truyền vào 3 tham số : tham số 1:phần tử bắt đầu của vector
                                    //tham số 2: phần tử cuối của vector
                                    // tham số 3 : biểu thức lamda truyền vào hai tham số là Person a và Person b và dùng quá tải toán tử > để so sánh
    sort(per.begin(),per.end(),[](Person& a,Person& b){return a.getDiem() > b.getDiem();});
}

void thiSinhDiemCaoNhat(vector<Person> per) // sau khi sắp xếp thí sinh từ cao đến thấp thì thí sinh đầu tiên là người có điểm cao nhất
{
    cout<<per[0]<<"\n";
}

void thiSinhDiemThapNhat(vector<Person> per)//sau khi sắp xếp thí sinh từ cao đến thấp thì thí sinh cuối cùng là người có điểm thấp nhất
{
    cout<<per[per.size()-1]<<"\n";
}


void hienThiDanhSachThiSinhDaThi(vector<Person> per) // hàm này sẽ hiển thị danh sách các thí sinh đã thi từ lúc chương trình bắt đầu
{
    sapXep(per);    // hàm sắp xếp thí sinh (code ở dòng 555)
    for_each(per.begin(),per.end(),[](const Person& a){cout<<setw(100)<<a<<"\n";});  // cho vòng lặp chạy từ đầu đến cuối và dùng biểu thức lamda để hiển thị
}

void clearQuestionVec(vector<Question> &v) // xóa đáp án của mỗi câu hỏi sau mỗi lượt thí sinh trả lời
{                                           // tránh trường hợp thí sinh không trả lời nhưng vẫn có đáp án
    for (int i = 0; i < v.size(); i++)
    {
        v[i].setCauTraLoi(' ');
    }
}


void batDau() // bắt đầu chương trình
{
    Time t ;            // tạo ra đối tượng t kiểu Time để lưu thời gian
    Question ques;      // tạo ra đối tượng vec kiểu Question
    vector<Question> vec;   // tạo 1 vector dùng đế chứa danh sách các câu hỏi(sẽ dùng để load câu hỏi từ file data.txt và truyền vào vector này)
    vector<Person> vecPer; // dùng cho đưa thí sinh , là 1 vector sẽ dùng để chưa danh sách các thí sinh
    int luaChon,num = 0;
    readFile(vec);      // đọc file, load toàn bộ câu hỏi vào cho vector vec đã khai báo ở trên(dòng 594)
    while (true)        // bắt đầu vòng lặp
    {
        Person man;     // tạo ra 1 đối tượng man kiểu Person để lưu thông tin thí sinh
        system("cls");
        string str,str1;
        stringstream ss,ss1;    // tạo luồng stringstream để gán đầu vào cho luaChon để tránh trường hợp không thể nhập 1 kí tự chữ vào trong luaChon(vì lựa chọn là kiểu int)
        Menu();                 // gọi menu để hiển thị danh sách lựa chọn
        cout<<setw(88)<<"Lua chon : ";
        cin>>str;               // gán đầu vào cho biến str
        str1 = str;             // gán str1 = str
        ss.str(str);            // gán str cho luồng ss
        ss1.str(str1);          // gán str1 cho luồng ss1
        ss>>luaChon;            // gán đầu vào từ luồng ss cho luaChon
        while (true)
        {
            //nếu lựa chọn của người dùng không nằm trong danh sách của menu thì các đoạn mã trong if sẽ được thực thi
            // sẽ yêu cầu người dùng nhập lại lựa chọn của họ đến khi hợp lệ
            if (luaChon !=1 && luaChon !=2 && luaChon !=3 && luaChon!=4 && luaChon!=5 && luaChon!=6)
            {
                system("cls");
                string str,str1;
                char c;
                stringstream ss,ss1;
                cout<<"\n"<<setw(105)<<"Lua chon khong hop le ! Hay chon lai .\n\n";
                Menu();
                cout<<setw(88)<<"Lua chon : ";
                cin>>str;
                str1 = str;
                ss.str(str);
                ss1.str(str1);
                ss>>luaChon;
                ss1>>c;
            }
            else{break;}
        }
        switch (luaChon) // dùng switch để phân ra các lựa chọn phù hợp của người dùng để thực thi các đoạn mã phù hợp
        {
            case 1:     // nếu là trường hợp 1 thì thí sinh sẽ bắt đầu điền thông tin và bắt đầu bài thi
                cin>>man;               // nhập thông tin người dùng (dùng quá tải toán tử >>)
                system("cls");
                t = thoiGianHeThong();  // lấy mốc thời gian bắt đầu bài thi của thí sinh
                man.setThoiGianBatDau(t);   // gán mốc thời gian bắt đầu cho thuộc tính thowigianbatdau của thí sinh
                hienThiCauHoi(vec);         // bắt đầu hiển thị các câu hỏi cho thí sinh để trả lời
                tinhDiem(man,vec);          // tính điểm cho thí sinh sau khi hoàn thành bài thi, trong hàm này sẽ lấy cả thời gian kết thúc/
                man.settongThoiGianLamBai(man.tongThoiGianLamBaiT()); // gán tổng thời gian làm bài cho thuộc tính tongthoigianlambai cua thí sinh, man.tongThoiGianLamBaiT sẽ trả về thời gian làm bài (đơn vị giây)
                vecPer.push_back(man); // đẩy thí sinh vừa thi xong vào danh sách thí sinh đã thi
                ghiVaoFileText(man,vec);    // ghi thông tin, kết quả thi của thí sinh vào file text
                system("pause>nul");
                system("cls");
                clearQuestionVec(vec); // xóa đáp án trả lời cho mỗi câu hỏi sau mỗi lượt thi
                break;
            case 2:     // trường hợp 2 : thì sẽ hiển thị bản hướng dẫn cho thí sinh
                system("cls");
                huongDan();
                cout<<setw(105)<<"=> Nhan phim bat ky de tiep tuc.";
                system("pause>nul");
                system("cls");
                break;
            case 3: // trường hợp 3: hiển thị danh sach lần thi của thí sinh có tên A
                hienThiCacLanThiGanNhat(vecPer); // hiển thị lần thi gần nhất của thí sinh A
                system("pause>nul");
                system("cls");
                break;
            case 4://trường hợp 4 : hiển thị toàn bộ câu hỏi và đáp án đúng
                hienThiDapAn(vecPer,vec); // hiển thị câu hỏi và đáp án đúng
                system("cls");
                break;
            case 5: // trường hợp 5 sẽ hiển thị danh sách các thí sinh đã thi
                if (vecPer.empty()) // nếu vector vecPer(chứa danh sách thí sinh) rỗng tức là chưa có thí sinh nào làm bài gần đây
                {
                    cout<<setw(105)<<"-> DANH SACH THI SINH DA THI RONG.<-\n";
                }
                if (!vecPer.empty()) // còn khác rỗng thì sẽ hiển thị danh sách thí sinh đã thi gần đây
                {
                    hienThiDanhSachThiSinhDaThi(vecPer); // hiển thị danh sách thí sinh đã thi
                } 
                system("pause>nul");
                system("cls");
                break;
            case 6: // trường hợp 6 :thoát khỏi chương trình.
                int asci;
                char key_press;
                cout<<"\n"<<setw(108)<<">> Neu thoat ban se mat diem bai thi nay ! <<\n\n";
                cout<<setw(87)<<"Thoat(ESC)          "<<"Tiep tuc(Enter)\n";                
                while(true)
                {
                    key_press = getch(); // nhận phím nhấn từ bàn phím
                    asci = key_press;   // chuyển phím vừa nhấn sang mã ASCII
                    if (asci == 13){break;} // nếu là ENTER thì tiếp tục chương trình.
                    if (asci == 27){system("cls");exit(0);} //nếu là ESC thì thoát chương trình.
                }
                system("cls");
                break;
            default:
                break;
        }
    }
}

int main() // bắt đầu chương trình.
{
    batDau();
    return 0;
}
