#pragma once

#include "univer.h"
#include <functional>

using namespace std;

template <typename T>
class node {
public:
    T data;
    node* sled;
    node* pred;

    node() {}
    node(T d) {
        data = d;
    }

    friend ostream& operator << (ostream& s, node<T>& d) {
        s << d.data;
        return s;
    }

    bool operator > (node<T>& rhs) {
        return data > rhs.data;
    }

    bool operator < (node<T>& rhs) {
        return data < rhs.data;
    }

    bool operator== (node<T>& rhs) {
        return data == rhs.data;
    }
};

template <typename T>
class Spisok
{
private:
    node<T>* first;
    int countElements;
public:

    class Iterator;

    Spisok() { first = NULL; countElements = 0; }
    
    void add(T data) {
        countElements++;
        if (first == NULL) {
            first = new node<T>(data);
            (*first).pred = first;
            (*first).sled = first;
            return;
        }

        auto itBegin = begin();
        auto itEnd = end();

        node<T>* n = new node<T>(data);
        (*itEnd).sled = n;
        n->pred = &*itEnd;
        n->sled = &*itBegin;
        (*itBegin).pred = n;
    }

    void print() {
        auto it = begin();
        do {
            cout << *it << endl;
            it++;
        } while (it != begin());
    }

    void printReverse() {
        auto it = end();
        do {
            cout << *it << endl;
            it--;
        } while (it != end());
    }

    void sort(function<bool(T, T)> comparator) {
        auto it1 = begin();
        do{
            Spisok<T>::Iterator e = end();
            auto it2 = begin();
            do {
                auto kk = it2 + 1;
                if (comparator((*it2).data, (*kk).data)) {
                    T d = (*it2).data;
                    (*it2).data = (*kk).data;
                    (*kk).data = d;
                }
                it2++;
            } while (it2 != e);
            it1++;
        } while (it1 != end());
    }

    int size() { return countElements; }

    void removeDuplicate(function<bool(T, T)> comparator) {
        auto it1 = begin();
        int i = 0;
        do {
            int j = 0;
            auto it2 = begin();
            do {
                if (i != j) {
                    if (comparator((*it1).data, (*it2).data)) {
                        node<T>& n = it2[1];
                        node<T>& p = it2[-1];
                        n.pred = &p;
                        p.sled = &n;
                    }
                }
                it2++;
                j++;
            } while (it2 != begin());
            i++;
            it1++;
        } while (it1 != begin());
    }

    int firstInclude(Spisok<T>::Iterator b, Spisok<T>::Iterator e, function<bool(T, T)> comparator) {
        int index = 0;

        auto it1 = begin();
        do {
            index++;
            auto it2 = b;
            if (comparator((*it1).data, (*it2).data)) {
                auto it3 = it1;
                do {
                    if (!comparator((*it2).data, (*it3).data))
                        break;
                    it2++;
                    it3++;
                } while (it2 != b);
                if (it2 == b)
                    return index - 1;
            }
            it1++;
        } while (it1 != begin());

        return -1;
    }

    Spisok<T>::Iterator begin() { return  Spisok<T>::Iterator(first); }
    Spisok<T>::Iterator end() { return  Spisok<T>::Iterator(first->pred); }

    node<T>& operator[](int index) {
        return *begin()[index];
    }

#pragma region Iterator
    class Iterator {
        node<T>* cur;
    public:
        Iterator(node<T>* first) : cur(first) {}

        node<T>& operator++(int) {
            cur = cur->sled;
            return *cur;
        }
        node<T>& operator--(int) {
            cur = cur->pred;
            return *cur;
        }

        node<T>& operator* () { return *cur; }

        bool operator!= (const Iterator& it) { return cur != it.cur; }
        bool operator== (const Iterator& it) { return cur == it.cur; }

        node<T>& operator=(const T& data) {
            cur->data = data;
            return *cur;
        }

        Iterator& operator- (int n) {
            Iterator it(cur);
            for (int i = 0; i < n; i++)
                it--;
            return it;
        }

        Iterator& operator+ (int n) {
            Iterator it(cur);
            for (int i = 0; i < n; i++)
                it++;
            return it;
        }

        node<T>& operator[] (int index) {
            if (index == 0)
                return *cur;
            node<T> *c = cur;
            for (int i = 0; i < abs(index); i++) {
                if (index > 0)
                    c = c->sled;
                else
                    c = c->pred;
            }
            return *c;
        }
    };
#pragma endregion
};

