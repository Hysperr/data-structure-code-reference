#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include "node2.h"
#include "bag5.h"

using namespace std;



// PROTOTYPE for a function used by this demonstration program
template <class Item, class SizeType, class MessageType>
void get_items(bag<Item>& collection, SizeType n, MessageType description)
// Postcondition: The string description has been written as a prompt to the
// screen. Then n items have been read from cin and added to the collection.
// Library facilities used: iostream, bag4.h
{
    Item user_input; // An item typed by the program's user
    SizeType i;

    cout << "Please type " << n << " " << description;
    cout << ", separated by spaces.\n";
    cout << "Press the <return> key after the final entry:\n";
    for (i = 1; i <= n; ++i)
    {
        cin >> user_input;
        collection.insert(user_input);
    }
    cout << endl;
}

int main()
{
    //demostrate how to use set template class
    set <string> actors1;
    set <string> actors2;
    set <string> result;
    set<string>::iterator role;
    actors1.insert("moe");
    actors1.insert("curly");
    actors2.insert("larry");
    actors2.insert("curly");
    
    for(role = actors1.begin(); role != actors1.end(); ++role)
        cout<<*role<<" ";
    cout<<endl;
    
    for(role = actors2.begin(); role != actors2.end(); ++role)
        cout<<*role<<" ";
    cout<<endl;
    
    // Notice how we create the output iterator for the fifth argument:
    set_union(actors1.begin(), actors1.end(),
              actors2.begin(), actors2.end(),
              inserter(result, result.begin()));
    for (role = result.begin(); role != result.end(); ++role) {
        cout << *role << " ";
    }
    cout << endl;


    
    
    //demonstrate how to use node iterator for node template class
    node<int> *head_ptr = new node<int>();
    list_head_insert(head_ptr, 42);
    list_head_insert(head_ptr, 13);
    list_head_insert(head_ptr, 67);

    
    node_iterator<int> start(head_ptr);
    node_iterator<int> finish;
    node_iterator<int> position;
    
    for(position = start; position != finish; ++position)
        cout<<*position<< " ";
    cout<<endl;  
    
    
    //demonstrate bag template class
    bag<int> bag_of_int;
    bag<string> bag_of_string;

    bag_of_int.insert(3);
    bag_of_string.insert("hello");
    bag_of_string.insert("goodbye");
    bag_of_string.insert("auf wiedersehen");
    bag_of_string.insert("goodbye");
    bag_of_string.insert("hello");
    bag_of_string.insert("goodbye");

    cout << "count of goodbye: " << bag_of_string.count("goodbye") << endl;
    cout << "count of guten morgen: " << bag_of_string.count("guten morgen") << endl;
    cout << "count of 3: " << bag_of_int.count(3) << endl;
    

    for(bag<string>::iterator cursor = bag_of_string.begin(); cursor != bag_of_string.end(); ++cursor)
        cout<<*cursor<< " ";
    cout<<endl <<endl;

    cout << "//-----------------------------------------------------------------\\\\" << endl;
    cout << "//--------//\\__//\\__//\\__//\\\\MY LAB BELOW//\\__//\\__//\\__//\\--------\\\\" << endl;
    cout << "//-----------------------------------------------------------------\\\\" << endl;

    cout << endl << endl;

    bag<int> coffee_bag;
    int data[] = {7,1,6,5,4,3,3,2,1,1};

    for (int i = 0; i < 10; i++) {
        coffee_bag.insert(data[i]);
    }

    cout << "removing repetitions..." << endl;

    for (bag<int>::iterator chestnut = coffee_bag.begin(); chestnut != coffee_bag.end(); ++chestnut) {
        cout << *chestnut << " ";
    }

    coffee_bag.remove_repetitions();
    cout << endl;

    for (bag<int>::iterator chestnut = coffee_bag.begin(); chestnut != coffee_bag.end(); ++chestnut) {
        cout << *chestnut << " ";
    }


    cout << endl << endl;

    cout << "Testing range function using numbers 1-7..." << endl;
    cout << "Between range 2 - 5..." << endl; coffee_bag.printty_value_range(2,5);
    cout << "Between range 2 - 1..." << endl; coffee_bag.printty_value_range(2,1);
    cout << "Between range 8 - 5 (out of range)..." << endl; coffee_bag.printty_value_range(8,5);

	return EXIT_SUCCESS;
}
