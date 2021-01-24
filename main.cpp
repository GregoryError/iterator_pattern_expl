#include <iostream>

// List Iter example:
//struct Node
//{
//    double item;
//    Node* p_next;
//};
//class Iterator
//{
//    Node* pt;
//public:
//    Iterator() : pt(nullptr) {}
//    Iterator(Node* pn) : pt(pn) {}
//    double operator*()
//    {
//        return pt->item;
//    }
//    Iterator& operator++()
//    {
//        pt = pt->p_next;
//        return *this;
//    }

//    Iterator operator++(int)
//    {
//        Iterator tmp = *this;
//        pt = pt->p_next;
//        return tmp;
//    }
//};


// Stack iter example:

template <typename T, int S>
class Stack;

template <typename T, int S>
class StackIter
{
private:
    Stack<T, S>& s;
    int p_pos;
public:
    StackIter(Stack<T, S>& stk, int pos) : s(stk)
    {
        p_pos = pos;
    }

    T& operator*()
    {
        return s.items[p_pos];
    }

    StackIter& operator++()
    {
        ++p_pos;
        return *this;
    }

    StackIter& operator--()
    {
        --p_pos;
        return *this;
    }

    bool operator==(const StackIter<T, S>& op)
    {
        return p_pos == op.p_pos;
    }

    bool operator!=(const StackIter<T, S>& op)
    {
        return p_pos != op.p_pos;
    }   
};


template <typename T, int S>
class Stack
{
private:
    T* items = new T[S];
    int top_p;
    StackIter<T, S>* beg_it = nullptr;
    StackIter<T, S>* end_it = nullptr;
    friend class StackIter<T, S>;
public:
    Stack()
    {
        top_p = 0;
    }

    bool empty()
    {
        return top_p <= 0;
    }

    void push(const T& itm)
    {
        if (top_p < S)
            items[top_p++] = itm;
        else
            std::cout << "Trying to push out of shack size.\n";
    }

    T pop()
    {
        if (!empty())
            return items[--top_p];
        else
            std::cout << "Trying to pop on empty stack.\n";
        return 0;
    }

    StackIter<T, S>& begin()
    {
        beg_it = new StackIter<T, S>(*this, 0);
        return *beg_it;
    }

    StackIter<T, S>& end()
    {
        end_it = new StackIter<T, S>(*this, top_p);
        return *end_it;
    }


    ~Stack()
    {
        delete [] items;
        delete beg_it;
        delete end_it;
    }
};


int main()
{
    Stack<int, 10> s;

    int t_val;
    std::cout << "Enter your values:\n\n";
    for (int i = 0; i < 10; ++i)
    {
        std::cin >> t_val;
        s.push(t_val);
    }


    std::cout << '\n';

    for (auto beg = s.begin(); beg != s.end(); ++beg)
        std::cout << *beg << " - ";


    std::cout << '\n';


    return EXIT_SUCCESS;
}































