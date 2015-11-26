#include <iostream>
#include <assert.h>
#include "LinkedList.h"

using namespace std;

int main() {
    LinkedList<int> t;
    assert(t.Check(0));
    t.addFront(1);
    assert(t.Check(1));
    t.addFront(2);
    assert(t.Check(2));
    t.addFront(3);
    assert(t.Check(3));
    t.addFront(4);
    assert(t.Check(4));
    t.getFirst()->insertBefore(-100);
    assert(t.Check(5));
    t.getFirst()->insertAfter(-50);
    assert(t.Check(6));
    t.addBack(5);
    assert(t.Check(7));
    t.getLast()->getPrevious()->getPrevious()->insertBefore(10);
    assert(t.Check(8));
    t.addBack(-1);
    assert(t.Check(9));
    //t.addFront(6);
    
    cout << t << endl;
    
    LinkedList<int> t1;
    assert(t1.Check(0));
    t1.addBack(3);
    assert(t1.Check(1));
    t1.addBack(4);
    assert(t1.Check(2));
    t1.popBack();
    t1.popBack();
    assert(t1.Check(0));
    
    cout << t1 << endl;

    //cin.get();

    return 0;
}