#include <iostream>
using namespace std;

int main(){
    int var = 100, var1;
    int *p;

    p = &var;

    cout << "&var : " << &var << endl;
    cout << "   p : " << p << endl;
    cout << "  &p : " << &p << endl << endl;

    *p = 500;
    cout << "var  : " << var << endl;
    cout << "  *p : " << *p << endl;

    p = &var1;
    *p = 5000;
    cout << "var1 : " << var1 << endl;
    cout << "  *p : " << *p << endl;

    return 0;
}
