
#include "set.h"
#include <iostream>

using namespace std;

int main() {

    set s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    cout << "set s..." << endl;
    s.print_set();

    set t;
    t.insert(4);
    t.insert(5);
    t.insert(88);
    t.insert(88);
    t.insert(6);
    t.insert(7);
    cout << "set t..." << endl;
    t.print_set();

    s.make_union(t);
    cout << "set s made union with t..." << endl;
    s.print_set();

    s.make_intersection(t);
    cout << "set s made intersection with t... " << endl;
    s.print_set();

    cout << "----------------" << endl;
    cout << "More testing...\n";

    set r;
    cout << "set r inserting 1, 2, 3, 3, 2 " << endl;
    r.insert(1);
    r.insert(2);
    r.insert(3);
    r.insert(3);
    r.insert(2);
    cout << "set r...\n";
    r.print_set();

    cout << "set r size: " << r.size() << endl;
    cout << "erase a single 2..." << endl;
    r.erase_one(2);
    r.print_set();
    cout << "erase all 3s (which is only one as it's a set..." << endl;
    r.erase(3);
    cout << "set r..." << endl;
    r.print_set();

    cout << "r size: " << r.size() << endl;

    cout << "r union s..." << endl;
    r.make_union(s);
    r.print_set();

    cout << "----------------" << endl;
    cout << "more testing union..." << endl;
    set p;
    p.insert(2);
    p.insert(4);
    p.insert(6);
    p.insert(8);
    cout << "set p..." << endl;
    p.print_set();

    set q;
    q.insert(6);
    q.insert(8);
    q.insert(10);
    cout << "set q..." << endl;
    q.print_set();

    cout << "set p made union with q" << endl;
    p.make_union(q);
    p.print_set();

    cout << "set s..." << endl;
    s.print_set();

    cout << "set p made union with s" << endl;
    p.make_union(s);
    p.print_set();

    cout << "indexing p at 3..." << endl;   // 8
    cout << p[3] << endl;

    return 0;
}