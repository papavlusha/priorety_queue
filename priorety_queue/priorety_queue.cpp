#include <iostream>
#include "pr_q.h"
#include <vector>

using namespace std;

void func_push(pr_q &a) {
    cout << "Enter amount of elements\n";
    int n;
    cin >> n;
    int el, b;
    for (int i = 0; i < n; i++) {
        cout << "enter value:";
        cin >> el;
        cout << "enter prioritet(1-high,2-medium,3-low):";
        cin >> b;
        try {
            a.push(el, b);
        }
        catch (exception t) {
            cerr << t.what();
        }
        system("Cls");
    }
}

void func_pop(pr_q& a) {
    cout << "Enter amount of elements u want to pop\n";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        a.pop();

    }
}

int main() {
    pr_q elements;
    pr_q second;
    int choice;
    int check;
    choice = 7;
    while (choice != 0) {
        cout << "1)Push\n";
        cout << "2)POP\n";
        cout << "3)1 - st info\n";
        cout << "4)amount of type\n";
        cout << "5)print\n";
        cout << "6)swap\n";
        cout << "7)copy to second\n";
        cout << "8)amount of elements\n";
        cout << "9)IS empty?\n";
        cout << "10)clear console\n";
        cout << "0)end\n";
        cin >> choice;
        switch (choice) {
        case 1:
            func_push(elements);
            break;
        case 2:
            func_pop(elements);
            break;
        case 3:
            elements.front_info();
            cout << "\n";
            break;
        case 4:
            cout << "enter priority u want to know info about:";
            cin >> check;
            elements.type_info(check);
            cout << "\n";
            break;
        case 5:
            cout << "1-st)";
            elements.print();
            cout << "2-nd)";
            second.print();
            break;
        case 6:
            swap(second, elements);
            break;
        case 7:
            second = elements;
            break;
        case 8:
            cout <<elements.amount()<< "\n";
            break;
        case 9:
            if (elements.is_empty()) {
                cout << "yes";
            }
            else {
                cout << "no";
            }
            cout << "\n";
            break;
        case 10:
            system("Cls");
            break;
        case 0:
            break;
        default:
            cout << "enter a right choice\n";
            break;
        }
    }
}
