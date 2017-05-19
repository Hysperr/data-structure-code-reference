#include <iostream>
#include "bag.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    bag a;
    a.insert(1);
    a.insert(2);
    a.insert(3);

    bag b;
    b.insert(4);
    b.insert(5);
    b.insert(6);

    bag c;
    c.insert(1);
    c.insert(2);
    c.insert(3);

    std::cout << "bag a...\n";
    a.print_bag();
    std::cout << "a size: " << a.size() << '\n';

    std::cout << "erase one 1 from a...\n";
    a.erase_one(1);
    a.print_bag();

    std::cout << "insert few 5's into a...\n";
    a.insert(5);
    a.insert(5);
    a.insert(5);
    a.print_bag();

    std::cout << "erase all 5's from a...\n";
    a.erase(5);
    a.print_bag();

    std::cout << "clear bag a...\n";
    a.clear();
    std::cout << "a size: " << a.size() << '\n';

    std::cout << "reset a with 1, 2, 3...\n";
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.print_bag();


    std::cout << "-------------\n";


    std::cout << "bag b...\n";
    b.print_bag();

    std::cout << "bag b contains 6 ?...\n";
    std::cout << b.contains(6) << '\n';     // 1 = true, 0 = false

    std::cout << "bag b capacity...\n";
    std::cout << b.get_capacity() << '\n';


    std::cout << "-------------\n";


    std::cout << "bag c..." << std::endl;
    c.print_bag();

    std::cout << "add c to bag b...\n";
    bag added_bag = c + b;
    added_bag.print_bag();

    std::cout << "bag a + bag b + bag c" << std::endl;
    added_bag = (a + b) + c;
    added_bag.print_bag();

    std::cout << "count 3's in big bag...\n";
    std::cout << added_bag.count(3) << '\n';


    using namespace std;

    cout << "-------------\n";

    bag g;
    g.insert(1);
    g.insert(2);
    g.insert(3);
    g.insert(4);

    bag f;
    f.insert(3);
    f.insert(4);
    f.insert(5);
    f.insert(6);

    cout << "bag g...\n";
    g.print_bag();

    cout << "bag f...\n";
    f.print_bag();

    cout << "f -= g...\n";
    cout << (f -= g) << " Item(s) removed from bag f" << endl;
    cout << "updated bag f...\n";
    f.print_bag();


    return 0;
}