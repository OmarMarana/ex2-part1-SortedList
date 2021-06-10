#include "SortedList.h"
using namespace mtm;
using namespace std;


int main()
{
    SortedList list = SortedList();

    list.insert(5);
    list.insert(4);
    list.insert(-2);
    list.insert(-1);

    list.print();

    SortedList list2(list);

    cout << "list 2 prints: \n";
    list2.print();
    list2.insert(69);
    list2.print();

    cout << " \n\n";

    SortedList::const_iterator i = list.begin();
    i;
    list.remove(i);
    cout << "list after removal of first element: \n";
    list.print();

    
    // cout << " \n\n";    
    // list2 = list;
    // cout << "list2 after assignment to list: \n";
    // list.print();
    
    
    cout << " \n\n";
    
    SortedList list3;
    cout << "list 3 empty print: \n";
    list3.print();
    
    cout << " \n\n";
    
    cout << "list 3 after assign to list2 prints: \n";
    list3 = list2;
    list3.print();

    cout << " \n\n";


    cout << "list 3 after assign to first list prints: \n";
    list3 = list;
    list3.print();

    // int index =1;
    // for(SortedList::const_iterator i = list.begin(); !(i == list.end()); ++i)
    // {   
    //     cout << "the index " << index << " in list is :" << *i << endl;
    //     index++;
    // }


    return 0;
}
