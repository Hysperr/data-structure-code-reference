
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
    cout << "update set s - union s U t..." << endl;
    s.print_set();

    s.make_intersection(t);
    cout << "updated set s - intersection with t: " << endl;
    s.print_set();

    cout << "More testing...\n";

    set yellow;
    yellow.insert(1);
    yellow.insert(2);
    yellow.insert(3);
    yellow.insert(3);
    yellow.insert(2);

    cout << "original yellow...\n";
    yellow.print_set();

    cout << "yellow size: " << yellow.size() << endl;
    cout << "erase a single 2..." << endl;
    yellow.erase_one(2);
    yellow.print_set();
    cout << "erase all 3s (which is only one as it's a set..." << endl;
    yellow.erase(3);

    yellow.print_set();

    cout << "yellow size: " << yellow.size() << endl;

    cout << "yellow union s..." << endl;
    yellow.make_union(s);

    yellow.print_set();


    return 0;
}