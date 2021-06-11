#include "SortedList.h"
using namespace mtm;
using namespace std;

using std::string;
string getLen(string str)
{
    return std::to_string(str.length());
}


bool longer_than_5(string str)
{
    return str.length() > 5 ? true : false;
    
}


int main()
{

    SortedList<string> lst1 = SortedList<string>();lst1.insert("Charlie");lst1.insert("Bob");lst1.insert("Alice");lst1.insert("Donald");
    // lst1.insert("AAB");
    // lst1.insert("ABA");
    // lst1.insert("AA");
    lst1.print();
    
    cout << "\n\n";

    SortedList<string> lst2 = lst1;
    lst2 = lst2.apply(getLen);
    lst2.print();

    cout << "\n\n";

    SortedList<string> lst3 = lst1;
    lst3 = lst3.filter(longer_than_5);
    lst3.print();


    
    // SortedList<int> list = SortedList<int>();

    // list.insert(5);
    // list.insert(4);
    // list.insert(-2);
    // list.insert(-1);

    // list.print();

    /* SortedList list2(list);

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


    //-1 -4 5 
    int index = 0;
    for(SortedList::const_iterator i = list.begin(); !(i == list.end()); i = list.begin())
    {
        list.remove(i);
        //cout << "the index " << index << " in list is :" << *i << endl;
        list.print();
        //index++;
    }
*/

    return 0;
}
