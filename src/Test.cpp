////#include <iostream>
#include "Test.h"


#define X_ADD 100


Rectangle::Rectangle()
{
    width = 1;
    height = 1;
}

Rectangle::~Rectangle()
{
    
}

void do_math(int a) {
    a += 5;
}
//
void Rectangle::set_values (int x, int y) {
    width = x;
    height = y;
}

int Rectangle::fun1 () {
    set_values(100, 200);
    do_math(1);
    UU::sss(false, false);
    int i = X_ADD;
    return i;
}

void UU::sss(bool x, bool y)
{
    
}
//
//
//int main () {
//    int val =4;
//    Rectangle rect; //class
//    rect.set_values (3,4);
//    do_math(&val);
//    int c = X_ADD(1, 2);
////    cout << "area: " << rect.area()<<"\n";
//    return 0;
//}
//

//int main () {
//    int val =4;
//    return 0;
//}

