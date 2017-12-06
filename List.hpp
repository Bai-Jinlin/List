#ifndef List_H
#define List_H

#include <iostream>
#include <sstream>
#include <string>
#include <exception>

namespace l {
    template<typename T>
    struct List {
        T key;
        List *next;
        static constexpr List *empty = nullptr;

        std::string toString() {
            List *xs = this;
            std::ostringstream strm;
            strm << '[';
            if (!xs) {
                strm << ']';
                return strm.str();
            }
            for (; tail(xs); xs = tail(xs))
                strm << head(xs) << ',';
            strm << head(xs) << ']';
            return strm.str();
        };
    };

    template<typename T>
    inline T head(List<T> *xs) { return xs->key; };

    template<typename T>
    inline List<T> *tail(List<T> *xs) { return xs->next; };

    template<typename T>
    List<T> *cons(T x, List<T> *xs) {
        List<T> *lst = new List<T>;
        lst->key = x;
        lst->next = xs;
        return lst;
    }

    template<typename T>
    T getAt(List<T> *xs, int n) {
        while (xs && n--)
            xs = tail(xs);
        if (!xs) throw std::length_error("range overflow");
        return head(xs);
    }

    template<typename T>
    T last(List<T> *xs) {
        if (!xs) throw std::logic_error("List is empty");
        for (; tail(xs); xs = tail(xs));
        return head(xs);
    }

    template<typename T>
    List<T> *init(List<T> *xs) {
        if (!xs) throw std::logic_error("List is empty");
        List<T> *ys = nullptr;
        for (; tail(xs); xs = tail(xs))
            ys = append(ys, head(xs));
        return ys;
    }

    template<typename T>
    int length(List<T> *xs) {
        int n = 0;
        for (; xs; ++n, xs = tail(xs));
        return n;
    }

    template<typename T>
    int lengthF(List<T> *xs) {
        if (xs)
            return 1 + length(tail(xs));
        return 0;
    }

    template<typename T>
    List<T> *append(List<T> *xs, T x) {
        List<T> *h, *t;
        for (h = t = xs; xs; xs = tail(xs))
            t = xs;
        if (!h)
            h = cons<T>(x, nullptr);
        else
            t->next = cons<T>(x, nullptr);
        return h;
    }

    template<typename T>
    List<T> *appendF(List<T> *xs, T x) {
        if (xs) return cons<T>(head(xs), appendF(tail(xs), x));
        return cons<T>(x, nullptr);
    }

    template<typename T>
    List<T> *copyF(List<T> *xs) {
        if (xs) return cons(head(xs), copyF(tail(xs)));
        return nullptr;
    }

    template<typename T>
    List<T> *concatF(List<T> *ll, List<T> *lr) {
        if (ll) return cons(head(ll), concatF(tail(ll), lr));
        return copyF(lr);
    }

    template<typename T>
    bool isEqual(List<T> *ll, List<T> *lr) {
        for (; ll && lr; ll = tail(ll), lr = tail(lr))
            if (ll->key != ll->key)
                return false;
        return !(ll || lr);

    }

    template<typename T>
    bool isEqualF(List<T> *ll, List<T> *lr) {
        if (ll == nullptr || lr == nullptr)
            return !(ll || lr);
        if (head(ll) == head(lr))
            return isEqualF(tail(ll), tail(lr));
        else
            return false;
    }


    template<typename T>
    void deleteList(List<T> *xs) {
        List<T> *c = xs;
        List<T> *t = nullptr;
        for (; c; c = t) {
            t = tail(c);
            c->next = nullptr;
            delete c;
        }
    }

    template<typename T>
    void deleteListF(List<T> *xs) {
        if (!xs) {
            deleteListF(tail(xs));
            delete xs;
        } else
            return;
    }

    template<typename T>
    List<T> *replicateF(int n, T x) {
        if (n <= 0)
            return List<T>::empty;
        return cons(x, replicateF(n - 1, x));
    }

    template<typename T>
    List<T> *reverseF(List<T> *xs) {
        if (!xs) return List<T>::empty;
        return append(reverseF(tail(xs)), head(xs));
    }

    template<typename T>
    List<T> *reverse(List<T> *xs) {
        List<T> *h = xs;
        List<T> *n = tail(xs);
        List<T> *t;
        h->next = nullptr;
        for (; n;) {
            t = tail(n);
            n->next = h;
            h = n;
            n = t;
        }
        return h;
    }

    template<typename T>
    void beautifulPrint(List<T> *xs) {
        std::cout << '[';
        if (!xs) {
            std::cout << ']';
            return;
        }
        for (; tail(xs); xs = tail(xs))
            std::cout << head(xs) << ',';
        std::cout << head(xs) << ']' << std::endl;
    }
}
#endif