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
    return str.length() >= 5 ? true : false;
    
}


int main()
{

    SortedList<string> lst1 = SortedList<string>();
    lst1.insert("Charlie");
    lst1.insert("Bob");
    lst1.insert("Alice");
    lst1.insert("Donald");

    lst1.print();
    
    cout << "\n\n";

    SortedList<string> lst2 = lst1;
    lst2 = lst2.apply(getLen);
    lst2.print();

    cout << "\n\n";

    SortedList<string> lst3 = lst1;

    bool myBool = false;

    lst3 = lst3.filter(longer_than_5);
    lst3.print();

    return 0;
}
