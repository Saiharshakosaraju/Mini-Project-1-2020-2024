#include<bits/stdc++.h>
#include "./linkedList.hpp"
using namespace std;
using namespace dsa;

int main(){
    LinkedList<int> List1;
    LinkedList<int> List2;
    List1.beginInsert(21);
    List1.beginInsert(75);
    List1.beginInsert(50);
    List2.beginInsert(11);
    List2.beginInsert(32);
    List1.display();
    List2.display();
    List1.isSorted();
    List1.sort();
    List1.display();
    return 0;
}
