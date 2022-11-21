#include<bits/stdc++.h>
#include "./linkedList.hpp"
using namespace std;

int main(){
    dsa::LinkedList<int> List1;
    dsa::LinkedList<int> List2;
    List1.beginInsert(1);
    List1.beginInsert(2);
    List1.beginInsert(3);
    List1.beginInsert(4);
    List1.beginInsert(5);
    List2.beginInsert(6);
    List2.beginInsert(7);
    List1.display();
    List2.display();
    return 0;
}