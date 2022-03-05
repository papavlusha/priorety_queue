#include "pr_q.h"
#include <iostream>
#include <string>
#include <exception>

using namespace std;

bool pr_q::is_empty() const {
	return first == nullptr;
}

void pr_q::print() const{
    if (is_empty()) {
        cout << "queue is empty\n";
        return;
    }
        Node* now = first;
        while (now) { 
            std::cout << now->val << " ";
            now = now->next;
        }
        std::cout << "\n";
}

void pr_q::front_info() const{
    if (is_empty()) {
        cout << "queue is empty\n";
        return;
    }
    else {
        std::string answer;
        if (first->priority == 1) {
            answer = "High";
        }
        if (first->priority == 2) {
            answer = "Medium";
        }
        if (first->priority == 3) {
            answer = "Low";
        }
        cout << answer << "-priority and value= "<< first->val;
    }
}

 bool pr_q::pop()
{
    if (is_empty()) {
        return false;
    }
    else {
        Node* a = first->next;
        if (first == last_h) {
            last_h = nullptr;
        }
        if (first == last_m) {
            last_m = nullptr;
        }
        delete first;
        first =a;
        return true;
    }
}

 void pr_q::amount() const {
     if (is_empty()) {
         cout << "queue is empty\n";
         return;
     }
     unsigned number = 0;
     Node* now = first;
     while (now) {
         number++;
         now = now->next;
     }
     std::cout << number;
 }

pr_q& pr_q::operator=(const pr_q& Q)
{

    if (this != &Q)
    {
        Erase();
        clone(Q);
    }
    return *this;
}

pr_q& pr_q::operator=(pr_q&& other) {
    if (this == &other) {
        return *this;
    }
    Erase();
    first = other.first;
    last = other.last;
    last_h = other.last_h;
    last_m = other.last_m;
    other.first =nullptr;
    other.last = nullptr;
    other.last_h = nullptr;
    other.last_m = nullptr;
    return *this;
}

void pr_q::Erase()
{
    while (pop());
}

void pr_q::clone(const pr_q& Q)
{   
    Node* now = Q.first;
    while(now) {
        push(now->val,now->priority);
        now = now->next;
    }
}

void pr_q::move(Node*& first, Node*& second) {
    first = second;
    second = nullptr;
} 

void pr_q::move(pr_q&& other) {
    move(first, other.first);
    move(last_m, other.last_m);
    move(last_h, other.last_h);
    move(last, other.last);
}

pr_q::pr_q() {
    first = nullptr;
    last = nullptr;
    last_h = nullptr;
    last_m = nullptr;
}

pr_q::~pr_q()
{
    Erase();
}

	
void pr_q::type_info(int _a) const {
    if (first == nullptr) {
        cout << "queue is empty\n";
    }
    else {
        int  a = 0;
        Node* now = first;
        while (now) {
            if (now->priority == _a) {
                a++;
            }
            now = now->next;
        }
        cout << "amount of " << _a << " priority:" <<a;
    }  
}

void pr_q::push(int _val, int _pri) {
        Node* p = new Node(_val,_pri);
        if (_pri > 3 || _pri < 1) {
            throw std::exception("not right priority");
        }
        if (is_empty()) {
            first = p;
            last = p;
            if (_pri == 1) {
                last_h = p;
            }
            if (_pri == 2) {
                last_m = p;
            }
            return;
        }
        if (p->priority == 1) { 
            if (last_h == nullptr) {
                p->next = first;
                first = p;
                last_h = p;
            }
            else { 
                Node* connect = last_h->next;
                last_h->next = p;
                last_h = p;
                p->next = connect;
                if (connect == nullptr) {
                    last = p;
                }
            }
        }
        if (p->priority == 2) { 
            if (last_m == nullptr) {
                if (last_h == nullptr) {
                    p->next = first;
                    first = p;
                    last_m = p;
                }
                else {
                    Node* connect = last_h->next;
                    last_h->next = p;
                    p->next = connect;
                    last_m = p;
                    if (connect == nullptr) {
                        last = p;
                    }
                }
            }
            else {  
                Node* connect = last_m->next;
                last_m->next = p;
                last_m = p;
                p->next = connect;
                if (connect == nullptr) {
                    last = p;
                }
            }
        }
        if (p->priority == 3) {
        last->next = p;
        last = p;
    }
}
