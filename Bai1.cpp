#include<bits/stdc++.h>

using namespace std;

class MOBILE{
  private:
    int id;
    string manufacture;
    string phoneName;
    float price;
    int batterryCapacity;
    int internalMemory;
  public:
    friend istream&operator>>(istream &is,MOBILE &phone){
      cout <<"Nhap ma dien thoai : ";
      is >> phone.id;
      is.ignore();
      cout <<"Nhap ten dien thoai : ";
      getline(is,phone.phoneName);
      cout <<"Nhap hang san xuat : ";
      getline(is,phone.manufacture);
      cout <<"Nhap gia dien thoai : ";
      is >>phone.price;
      cout <<"Nhap dung luong pin : ";
      is >>phone.batterryCapacity;
      cout <<"Nhap bo nho trong : ";
      is >>phone.internalMemory;
      return is;
    }
    friend ostream& operator<<(ostream &os, MOBILE &phone) {
      os << "| " << setw(10) << left << phone.id
          << "| " << setw(18) << left << phone.phoneName
          << "| " << setw(16) << left << phone.manufacture
          << "| " << setw(16) << left << fixed << setprecision(2) << phone.price
          << "| " << setw(16) << left << phone.batterryCapacity
          << "| " << setw(16) << left << phone.internalMemory << " |" << endl;

      os << "----------------------------------------------------------------------------------------------------------" << endl;
      return os;
    }
    //chi dinh nghia sap xep theo tieu chi gia trong toan tu lon hon nho hon
    bool operator>(const MOBILE &phone){
      return this->price > phone.price;
    }
    bool operator<(const MOBILE &phone){
      return this->price < phone.price;
    }
    bool operator==(const MOBILE &phone){
      return this->price == phone.price;
    }
   
    int getId(){
      return id;
    }
    float getPrice(){
      return this->price;
    }
    int getInternalMemory(){
      return this->internalMemory;
    }
    int getBatterryCapacity(){
      return this->batterryCapacity;
    }
    string getPhoneName(){
      return this->phoneName;
    }
    string getManufacture(){
      return this->manufacture;
    }
    void setNamePhone(string name){
      this->phoneName = name;
    }
    void setprice(float price){
      this->price = price;
    }
    void setBatterryCapacity(int batterryCapacity){
      this->batterryCapacity = batterryCapacity;
    }
    void setManufacture(string manufacture){
      this->manufacture = manufacture;
    }
    void setInternalMemory(int internalMemory){
      this->internalMemory = internalMemory;
    }
    //xay dung ham tao co doi de test cac thong tin
    MOBILE(int id, string phoneName, string manufacture, float price, int batterryCapacity, int internalMemory){
      this->id = id;
      this->phoneName = phoneName;
      this->manufacture = manufacture;
      this->price = price;
      this->batterryCapacity = batterryCapacity;
      this->internalMemory  = internalMemory;
    }
    MOBILE(){

    }   
};
//sap xep sinh vien theo gia tang dan
bool cmpInternalIncrease(MOBILE &p1,MOBILE &p2){
    return p1.getInternalMemory() <= p2.getInternalMemory();
}
bool cmpInternalReduce(MOBILE &p1,MOBILE &p2){
  return p1.getInternalMemory() > p2.getInternalMemory();
}

bool cmpPhoneName(MOBILE &p1,MOBILE &p2){
  return p1.getPhoneName() < p2.getPhoneName();
}
class PHONEMANAGEMENT{
  private:
    vector<MOBILE> ListPhone;
  public:
    //displayheader
    void header(){
      cout << "----------------------------------------------------------------------------------------------------------" << endl;
      cout << "| " << setw(10) << left << "ID" 
          << "| " << setw(18) << left << "Phone Name"
          << "| " << setw(16) << left << "Manufacturer"
          << "| " << setw(16) << left << "Price(trieu)"
          << "| " << setw(16) << left << "Battery(mA)"
          << "| " << setw(16) << left << "Memory (GB)" << " |" << endl;
      cout << "----------------------------------------------------------------------------------------------------------" << endl;
    }
    //ham hien thi danh sach dien thoai hien co trong vector
    void display(){
      if(ListPhone.empty()){
        cout <<"Danh sach dien thoai rong\n";
        return;
      }
      header();
      for (int i= 0; i<ListPhone.size(); i++){
        cout << ListPhone[i];
      }
    }
    //them dien thoai vao vector,dua ra yeu cau nguoi dung con nhap khong
    void addPhone(){
      char choice;
      do{
        cout <<"Nhap thong tin dien thoai can them : \n";
        MOBILE a;
        cin >> a;
        ListPhone.push_back(a);
        cout <<"Da them thanh cong !!\n";
        cout <<"Ban con muon them dien thoai khac vao danh sach khong?(c:co,k:khong) : ";
        cin >> choice;
      }while(choice == 'c' || choice == 'C');
      cout <<"Danh sach dien thoai trong cua hang la : \n";
      display();
    }
    //xoa di 1 dien thoai theo ma
    void erase(){
      if(ListPhone.empty()){
        cout <<"Danh sach rong\n";
        return;
      }
      int id;
      cout <<"Nhap ma dien thoai can xoa : ";
      cin >> id;
      for (vector<MOBILE>::iterator it = ListPhone.begin(); it != ListPhone.end(); it++){
        if(it->getId() == id){
          ListPhone.erase(it);
          cout <<"Da xoa dien thoai co ma " <<id <<endl;
          return;
        }
      }
      cout <<"Khong tim thay dien thoai co ma " <<id <<endl;
    }
    //sua doi thong tin cua mot dien thoai bat ki trong danh sach khong lam thay doi id
    void updatePhone(){
      if(ListPhone.empty()){
        cout <<"Danh sach rong\n";
      }
      int id;
      cout <<"Nhap ma dien thoai can thay doi thong tin : ";
      cin >> id;
      int k = -1;
      for (int i = 0; i<ListPhone.size(); i++){
        if(ListPhone[i].getId() == id){
          k = i;
          break;
        }
      }
      if(k == -1){
        cout <<"khong tim thay dien thoai can sua\n";
        return;
      }
      int choice;
      string newName;
      string newManufacture;
      float newPrice;
      int newBatterryCapacity;
      int newInternalMemory;
      do {
        cout <<"Nhap thong tin can sua \n";
        cout <<"1.Ten dien thoai\n";
        cout <<"2.Hang san xuat\n";
        cout <<"3.Gia dien thoai\n";
        cout <<"4.Dung luong pin\n";
        cout <<"5.Bo nho trong\n";
        cout <<"6.Sua tat ca\n";
        cout <<"0.Thoat\n";
        cout <<"Nhap lua chon : ";
        cin >> choice;
        cin.ignore();
        if(choice == 1){
          cout <<"Nhap ten dien thoai moi : ";
          getline(cin,newName);
          ListPhone[k].setNamePhone(newName);
        }
        else if(choice == 2){
          cout <<"Nhap hang san xuat moi : ";
          getline(cin,newManufacture);
          ListPhone[k].setManufacture(newManufacture);
        }
        else if(choice == 3){
          cout <<"Nhap gia moi : ";
          cin >> newPrice;
          ListPhone[k].setprice(newPrice);
        }
        else if(choice == 4){
          cout <<"Nhap dung luong pin moi : ";
          cin >> newBatterryCapacity;
          ListPhone[k].setBatterryCapacity(newBatterryCapacity);
        }
        else if(choice == 5){
          cout <<"Nhap bo nho trong moi : ";
          cin >> newInternalMemory;
          ListPhone[k].setInternalMemory(newInternalMemory);
        }
        else if(choice == 6){
          cout <<"Nhap ten dien thoai moi : ";
          getline(cin,newName);
          ListPhone[k].setNamePhone(newName);
          cout <<"Nhap hang san xuat moi : ";
          getline(cin,newManufacture);
          ListPhone[k].setManufacture(newManufacture);
          cout <<"Nhap gia moi : ";
          cin >> newPrice;
          ListPhone[k].setprice(newPrice);
          cout <<"Nhap dung luong pin moi : ";
          cin >> newBatterryCapacity;
          ListPhone[k].setBatterryCapacity(newBatterryCapacity);
          cout <<"Nhap bo nho trong moi : ";
          cin >> newInternalMemory;
          ListPhone[k].setInternalMemory(newInternalMemory);
        }
        else if(choice == 0){
          break;
        }
        else{
          cout <<"Lua chon khong hop le, vui long nhap lai \n";
        }
      } while(1);
      cout <<"DA CAP NHAP THONG TIN THANH CONG\n";
    }
    //sap xep danh sach theo gia tang dan 
    void sortPriceIncrease(){
      sort(ListPhone.begin(),ListPhone.end());
    }
    //sap xep danh sach theo gia giam dan
    void sortPriceReduce(){
      sort(ListPhone.begin(),ListPhone.end(),greater<>());
    }
    // sap xep theo bo nho trong tang dan 
    void sortMemoryIncrease(){
      sort(ListPhone.begin(),ListPhone.end(),cmpInternalIncrease);
    }
    //sap xep theo bo nho trong giam dan
    void sortMemoryReduce(){
      sort(ListPhone.begin(),ListPhone.end(),cmpInternalReduce);
    }
    // tim kiem theo ten dien thoai bang thuat toan tim kiem nhi phan
    void SearchName() {
      if(ListPhone.empty()){
        cout <<"Danh sach rong\n";
        return;
      }
      cin.ignore();//xoa ki tu newline cua choi trong menu
      string name;
      cout <<"Nhap ten dien thoai can tim : ";
      getline(cin,name);
      int l = 0;
      int found = -1;
      sort(ListPhone.begin(), ListPhone.end(), cmpPhoneName);
      int r = ListPhone.size() - 1;
      while (l <= r) {
        int m = (l + r) / 2;
        if (ListPhone[m].getPhoneName() == name) {
            found = m;  
            break; 
        }
        else if (ListPhone[m].getPhoneName() < name) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
      }
      if (found == -1) {
          cout << "Khong tim thay dien thoai can tim\n";
      } 
      else {
        cout << "Da tim thay\n";
        cout << "Danh sach dien thoai hien co ten nhu vay :\n";
        // Duyệt các phần tử trước `found` để in ra các tên trùng
        int i = found;
        while (i >= 0 && ListPhone[i].getPhoneName() == name) {
          cout << ListPhone[i] << endl;
          i--;
        }
        // Duyệt các phần tử sau `found` để in ra các tên trùng
        i = found + 1;
        while (i < ListPhone.size() && ListPhone[i].getPhoneName() == name) {
          cout << ListPhone[i] << endl;
          i++;
        }
      }
    }
    //tim dien thoai co dung luong pin cao nhat
    void maxBaterryCapacity(){
      if(ListPhone.empty()){
        cout <<"Danh sach dien thoai rong\n";
        return;
      }
      long long maxBaterry = -1e9;
      for(int i= 0; i<ListPhone.size(); i++){
        if(ListPhone[i].getBatterryCapacity() > maxBaterry){
          maxBaterry = ListPhone[i].getBatterryCapacity();
        }
      }
      cout <<"Dung luong pin max : ";
      cout <<maxBaterry <<endl;
      cout <<"Danh sach dien thoai co dung luong pin cao nhat la : \n";
      header();
      for (int i= 0; i<ListPhone.size(); i++){
        if(ListPhone[i].getBatterryCapacity() == maxBaterry){
          cout << ListPhone[i];
        }
      }
    }
    //tim dien thoai co gia thap nhat
    void minPrice(){
      if(ListPhone.empty()){
        cout <<"Danh sach dien thoai rong\n";
        return;
      }
      float minG = ListPhone[0].getPrice();
      for (int i= 0; i<ListPhone.size(); i++){
        if(ListPhone[i].getPrice() < minG){
          minG = ListPhone[i].getPrice();
        }
      }
      cout <<"Gia dien thoai thap nhat : ";
      cout << minG <<endl;
      cout <<"Danh sach dien thoai co gia thap nhat la : " <<endl;
      header();
      for (auto x : ListPhone){
        if(x.getPrice() == minG){
          cout <<x;
        }
      }
    }
    //tong tong so luong dien thoai da ton kho theo hang san xuat
    void SumPhone(){
      if(ListPhone.empty()){
        cout <<"Danh sach dien thoai rong\n";
        return ;
      }
      map<string,int> phoneCount;
      map<string,vector<MOBILE>> phoneByManufacture;
      for(auto phone : ListPhone){
        phoneCount[phone.getManufacture()]++;
        phoneByManufacture[phone.getManufacture()].push_back(phone);
      }
      cout <<"Tong so dien thoai theo hang san xuat :\n";
      for (auto x : phoneCount){
        cout <<x.first <<": " <<x.second <<" dien thoai\n";
        cout <<"Danh sach dien thoai cua hang " <<x.first <<" :\n";
        header();
        for (auto y : phoneByManufacture[x.first]){
          cout << y;
        }
        cout << endl;
      }

    }
    void addSamplePhones() {
    // Thêm điện thoại với tên và hãng giống nhau nhưng khác các thông số khác
      ListPhone.push_back(MOBILE(1,"Iphone 14", "Apple", 999.99, 3500, 128));
      ListPhone.push_back(MOBILE(2,"Iphone 14", "Apple", 1099.99, 4000, 256));  // Tên giống nhưng giá và các thông số khác khác
      ListPhone.push_back(MOBILE(3,"Iphone 14", "Apple", 899.99, 3000, 64));   // Tên giống nhưng các thông số khác khác
      ListPhone.push_back(MOBILE(4,"Galaxy S23", "Samsung", 799.99, 4000, 256));
      ListPhone.push_back(MOBILE(5,"Galaxy S23", "Samsung", 850.00, 4200, 128)); // Thêm sản phẩm có cùng tên nhưng khác giá, dung lượng
      ListPhone.push_back(MOBILE(7,"Pixel 8", "Google", 699.99, 4600, 128));
      ListPhone.push_back(MOBILE(8,"Pixel 8", "Google", 749.99, 4700, 256));  // Thêm với thông số khác
      ListPhone.push_back(MOBILE(12,"OnePlus 11", "OnePlus", 899.99, 5000, 256));
      ListPhone.push_back(MOBILE(11,"OnePlus 11", "OnePlus", 950.00, 4800, 128)); // Tên và hãng giống nhưng thông số khác
      ListPhone.push_back(MOBILE(10,"Xiaomi 13", "Xiaomi", 649.99, 4200, 128));
      ListPhone.push_back(MOBILE(111,"Xiaomi 13", "Xiaomi", 699.99, 4300, 256)); // Tên giống nhưng thông số khác

      cout << "Danh sach dien thoai mau da duoc them vao!\n";
    }
    void menu() {
      int choice;
      do {
        cout << "\n--- MENU QUAN LY DIEN THOAI ---\n";
        cout << "1. Them dien thoai\n";
        cout << "2. Xoa dien thoai\n";
        cout << "3. Cap nhat thong tin dien thoai\n";
        cout << "4. Sap xep theo gia\n";
        cout << "5. Sap xep theo bo nho\n";
        cout << "6. Tim dien thoai theo ten\n";
        cout << "7. Tim dien thoai co dung luong pin cao nhat\n";
        cout << "8. Tim dien thoai co gia thap nhat\n";
        cout << "9. Tinh tong so luong dien thoai theo hang san xuat\n";
        cout << "10. Hien thi danh sach dien thoai\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;    
        switch(choice) {
          case 1:
            addPhone();
            break;
          case 2:
            erase();
            break;
          case 3:
            updatePhone();
            break;
          case 4:{
            cout <<"Ban muon sap xep theo gia tang hay giam(1:Tang,2:Giam) : ";
            int choi;
            cin >> choi;
            if(choi == 1){
              sortPriceIncrease();
              cout <<"Danh sach dien thoai sau khi sap xep theo gia tang : \n";
            }
            else{
              sortPriceReduce();
              cout <<"Danh sach dien thoai sau khi sap xep theo gia giam : \n";
            }
            display();
            break;
          }
          case 5:{
            cout <<"Ban muon sap xep theo bo nho tang hay giam(1:Tang,2:Giam) : ";
            int choi;
            cin >> choi;
            if(choi == 1){
              sortMemoryIncrease();
              cout <<"Danh sach dien thoai sau khi sap xep theo gia tang : \n";
            }
            else{
              sortMemoryReduce();
              cout <<"Danh sach dien thoai sau khi sap xep theo gia giam : \n";
            }
            display();
            break;
          } 
          case 6: {
            SearchName();
            break;
          }
          case 7:
            maxBaterryCapacity();
            break;
          case 8:
            minPrice();
            break;
          case 9:
            SumPhone();
            break;
          case 10:
            display();
            break;
          case 0:
            cout << "Thoat chuong trinh.\n";
            break;
          default:
            cout << "Lua chon khong hop le! Vui long chon lai.\n";
        }
      } while (choice != 0);  // Lặp lại menu cho đến khi người dùng chọn 0 để thoát
    }
};
int main(){
  PHONEMANAGEMENT management;
  management.addSamplePhones();
  management.menu();  
  return 0;
}