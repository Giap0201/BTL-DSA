#include <bits/stdc++.h>
using namespace std;

// Node Class
template <class T>
class Node {
private:
    T data;
    Node* next;
public:
    Node() : next(nullptr) {}
    Node(T x, Node* N = nullptr) : data(x), next(N) {}

    void setData(T x) {
        data = x;
    }

    void setNext(Node* N = nullptr) {
        next = N;
    }

    T& getData() {
        return data;
    }

    Node*& getNext() {
        return next;
    }
};

// Singly Linked List Class (slist)
template <class T>
class slist {
private:
    Node<T>* head;
    Node<T>* tail;
    int num;

public:
    slist() : head(nullptr), tail(nullptr), num(0) {}

    void push_back(T x) {
        if (num == 0) {
            head = tail = new Node<T>(x);
        } else {
            tail->setNext(new Node<T>(x));
            tail = tail->getNext();
        }
        num++;
    }

    void insert(T x, int pos) {
        if (pos < 1 || pos > num + 1) {
            cout << "Invalid position" << endl;
            return;
        }

        if (pos == 1) {
            Node<T>* newNode = new Node<T>(x, head);
            head = newNode;
            if (num == 0) tail = newNode;
            num++;
            return;
        }

        Node<T>* t = head;
        for (int i = 1; i < pos - 1; i++) {
            t = t->getNext();
        }

        Node<T>* newNode = new Node<T>(x, t->getNext());
        t->setNext(newNode);
        if (newNode->getNext() == nullptr) tail = newNode;  // Update tail if needed
        num++;
    }

    void displayList() {
        if (num == 0) {
            cout << "List is empty." << endl;
            return;
        }
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->getData() << " ";
            current = current->getNext();
        }
        cout << endl;
    }

    int countOccurrences(T k) {
        int count = 0;
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->getData() == k) {
                count++;
            }
            current = current->getNext();
        }
        return count;
    }

    bool checkEvenTriples() {
        Node<T>* current = head;
        int pos = 1;
        while (current != nullptr && current->getNext() != nullptr && current->getNext()->getNext() != nullptr) {
            if (current->getData() > 0 && current->getData() % 2 == 0 &&
                current->getNext()->getData() > 0 && current->getNext()->getData() % 2 == 0 &&
                current->getNext()->getNext()->getData() > 0 && current->getNext()->getNext()->getData() % 2 == 0) {
                cout << "Found at position " << pos << ", " << pos + 1 << ", " << pos + 2 << endl;
                return true;
            }
            current = current->getNext();
            pos++;
        }
        return false;
    }

    void sort() {
        if (num <= 1) return;
        for (Node<T>* i = head; i != nullptr; i = i->getNext()) {
            for (Node<T>* j = i->getNext(); j != nullptr; j = j->getNext()) {
                if (i->getData() > j->getData()) {
                    swap(i->getData(), j->getData());
                }
            }
        }
    }

    bool isPrime(int x) {
        if (x <= 1) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }

    void removePrimes() {
        Node<T>* prev = nullptr;
        Node<T>* curr = head;

        while (curr != nullptr) {
            if (isPrime(curr->getData())) {
                if (curr == head) {
                    head = curr->getNext();
                    delete curr;
                    curr = head;
                } else {
                    prev->setNext(curr->getNext());
                    delete curr;
                    curr = prev->getNext();
                }
                num--;
            } else {
                prev = curr;
                curr = curr->getNext();
            }
        }
    }

    void removeDuplicates() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* runner = current;
            while (runner->getNext() != nullptr) {
                if (runner->getNext()->getData() == current->getData()) {
                    Node<T>* duplicate = runner->getNext();
                    runner->setNext(duplicate->getNext());
                    delete duplicate;
                    num--;
                } else {
                    runner = runner->getNext();
                }
            }
            current = current->getNext();
        }
    }

    ~slist() {
        while (head) {
            Node<T>* temp = head;
            head = head->getNext();
            delete temp;
        }
    }
};

// Menu class to manage user inputs and options
template <class T>
class Menu {
private:
    slist<T>& list;

public:
    Menu(slist<T>& l) : list(l) {}

    void showMenu() {
        int choice, value, pos, k;

        while (true) {
            cout << "\nMenu Options:\n";
            cout << "1. Add an element at a specific position\n";
            cout << "2. Count occurrences of a number\n";
            cout << "3. Check for three consecutive even positive numbers\n";
            cout << "4. Sort the list\n";
            cout << "5. Remove prime numbers\n";
            cout << "6. Remove duplicates\n";
            cout << "7. Display the list\n";
            cout << "8. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter value and position to insert: ";
                    cin >> value >> pos;
                    list.insert(value, pos);
                    break;
                case 2:
                    cout << "Enter value to count occurrences: ";
                    cin >> k;
                    cout << "Occurrences of " << k << ": " << list.countOccurrences(k) << endl;
                    break;
                case 3:
                    if (!list.checkEvenTriples()) {
                        cout << "No 3 consecutive positive even numbers found.\n";
                    }
                    break;
                case 4:
                    cout << "List before sorting: ";
                    list.displayList();
                    list.sort();
                    cout << "List after sorting: ";
                    list.displayList();
                    break;
                case 5:
                    list.removePrimes();
                    cout << "List after removing prime numbers: ";
                    list.displayList();
                    break;
                case 6:
                    list.removeDuplicates();
                    cout << "List after removing duplicates: ";
                    list.displayList();
                    break;
                case 7:
                    list.displayList();
                    break;
                case 8:
                    return;  // Exit the menu
                default:
                    cout << "Invalid choice! Please try again.\n";
            }
        }
    }
};

// Main function to test the functionalities
int main() {
    slist<int> list;
    Menu<int> menu(list);

    // a. Tạo danh sách số từ input, dừng khi gặp dấu '#'
    cout << "Enter numbers to add to the list (enter '#' to stop):\n";
    string input;
    while (true) {
        cin >> input;
        if (input == "#") break;
        list.push_back(stoi(input));  // Convert input string to integer and add to list
    }

    // Call the menu to allow user to interact with the list
    menu.showMenu();

    return 0;
}
