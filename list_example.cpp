#include <iostream>
#include "List.hpp"

using namespace l;
using namespace std;

int main(){
    auto l=cons(1,cons(3,cons(4,List<int>::empty)));
    cout<<reverse(l)->toString();
}