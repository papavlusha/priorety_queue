#pragma once
#include <string>
class pr_q {
public:
	void type_info(int _a) const;
	void push(int _val, int _pr);
	bool is_empty() const;
	void print() const;
	void front_info() const;
	bool pop();
	unsigned amount() const;
	pr_q& operator = (const pr_q&);
	pr_q& operator = (pr_q&& other);
	void swap(pr_q* one, pr_q* two) {
		pr_q* tmp = new pr_q(std::move(*one));
		*one = std::move(*two);
		*two = std::move(*tmp);
	}
	void move(pr_q&& other);
	pr_q();
	~pr_q();
	pr_q(pr_q&& other) noexcept :
		first(std::move(other.first)),
		last(std::move(other.last)),
		last_h(std::move(other.last_h)),
		last_m(std::move(other.last_m)) {
		other.first = nullptr;
		other.last = nullptr;
		other.last_h = nullptr;
		other.last_m = nullptr;
	}
private:
	struct Node {
		int val;
		int priority;
		Node* next;
		Node(int _val, int _pr) : val(_val), next(nullptr), priority(_pr) {}
	};
	unsigned size{ 0 };
	void Erase();
	void clone(const pr_q&);
	void move(Node*&, Node*&);
	Node* first;
	Node* last;
	Node* last_h;
	Node* last_m;
};

