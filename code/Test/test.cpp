
#include <iostream> 
#include <string> 
using namespace std; 

int main() { 
    string str1; 
    string str2 = "caterpillar"; 
    string str3(str2); 

    cout << "str1= " << str1.empty() << endl;
    cout << "str1.size()= " << str1.size() << endl;
    cout << "str2= " << str2.size() << endl;
    cout << "str3.length()= " << str3.length() << endl;

    cout << "str1 = str2 " << (str1 == str2) << endl;
    cout << "str2 = str3 " << (str3 == str3) << endl;

    return 0; 
}