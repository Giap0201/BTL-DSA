#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MOBILE {
  private:
    int id;
    string manufacture;
    string phoneName;
    long long price;
    int batteryCapacity;
    int internalMemory;

  public:
    MOBILE(int id, string phoneName, string manufacture, long long price, int batteryCapacity, int internalMemory)
        : id(id), phoneName(phoneName), manufacture(manufacture), price(price), batteryCapacity(batteryCapacity), internalMemory(internalMemory) {}

    string getPhoneName() const { return phoneName; }
    
    friend ostream& operator<<(ostream &os, const MOBILE &phone) {
        os << phone.id << " | " << phone.phoneName << " | " << phone.manufacture << " | "
           << phone.price << " | " << phone.batteryCapacity << " | " << phone.internalMemory;
        return os;
    }
};

// Comparison function for sorting by phone name
bool cmpPhoneName(const MOBILE &p1, const MOBILE &p2) {
    return p1.getPhoneName() < p2.getPhoneName();
}

class QuanLy {
  private:
    vector<MOBILE> ListPhone;

  public:
    QuanLy(const vector<MOBILE> &phoneList) : ListPhone(phoneList) {}

    void findAndPrintAllByName(const string &name) {
        // Sắp xếp danh sách theo tên trước khi tìm kiếm nhị phân
        sort(ListPhone.begin(), ListPhone.end(), cmpPhoneName);

        int l = 0, r = ListPhone.size() - 1;
        int foundIndex = -1;

        // Tìm kiếm nhị phân để tìm một mục có tên trùng với `name`
        while (l <= r) {
            int m = (l + r) / 2;
            if (ListPhone[m].getPhoneName() == name) {
                foundIndex = m;
                break;
            }
            else if (ListPhone[m].getPhoneName() < name) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }

        if (foundIndex == -1) {
            cout << "Không tìm thấy điện thoại với tên: " << name << endl;
            return;
        }

        // In các mục có tên trùng nhau
        cout << "Các điện thoại có tên " << name << ":\n";
        // Kiểm tra các phần tử ở bên trái của `foundIndex`
        int i = foundIndex;
        while (i >= 0 && ListPhone[i].getPhoneName() == name) {
            cout << ListPhone[i] << endl;
            i--;
        }

        // Kiểm tra các phần tử ở bên phải của `foundIndex`
        i = foundIndex + 1;
        while (i < ListPhone.size() && ListPhone[i].getPhoneName() == name) {
            cout << ListPhone[i] << endl;
            i++;
        }
    }
};

int main() {
    vector<MOBILE> phoneList = {
        MOBILE(1, "iPhone 12", "Apple", 1000, 2815, 64),
        MOBILE(2, "Galaxy S21", "Samsung", 800, 4000, 128),
        MOBILE(3, "Mi 11", "Xiaomi", 700, 4600, 256),
        MOBILE(4, "iPhone 12", "Apple", 1000, 2815, 128),
        MOBILE(5, "iPhone 12", "Apple", 1200, 2815, 256)
    };

    QuanLy manager(phoneList);

    // Tìm kiếm và in ra tất cả các điện thoại có tên "iPhone 12"
    manager.findAndPrintAllByName("iPhone 12");

    return 0;
}
