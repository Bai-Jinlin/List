#include <iostream>
#include "List.hpp"

using namespace l;

int main() {
    List<int> *l = cons(1, cons(4, cons(3, List<int>::empty)));
    std::cout << l->toString() << '\n';

    List<int> *c1 = cons(5, l);
    std::cout << c1->toString() << '\n';

    int h1 = head(l);
    std::cout << h1 << '\n';

    List<int> *t1=tail(l);
    std::cout << t1->toString() << '\n';
}