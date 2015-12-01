#include <iostream>
#include <assert.h>
#include "LinkedList.h"

using namespace std;

int main(int argc, char *argv[]) {
    LinkedList<int> t;
    t.addFront(1);
    t.addFront(2);
    t.addFront(3);
    t.addFront(4);
    t.getFirst()->insertBefore(-100);
    t.getFirst()->insertAfter(-50);
    t.addBack(5);
    t.getLast()->getPrevious()->getPrevious()->insertBefore(10);
    t.addBack(-1);
    
    cout << t << endl;
    cout << t.size() << endl;
    cout << t.contains(5) << endl;
    cout << t.contains(-100) << endl;
    
    cout << endl;
    
    LinkedList<int> t1;
    t1.addBack(3);
    t1.addBack(4);
    t1.popBack();
    t1.popBack();
    
    cout << t1 << endl;
    cout << t1.size() << endl;
    
    
    cout << endl;
    
    LinkedList<int> t2;
    t2.addFront(3);
    t2.addBack(4);

    //cin.get();

    return 0;
}