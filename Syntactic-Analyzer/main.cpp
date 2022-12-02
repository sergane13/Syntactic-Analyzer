#include <iostream>
//#include <cstring>
#include<fstream>
#include "flux_date.h"


using namespace std;

ifstream f("DATE.IN");

int main()
{
    char s[100];
    f.get(s, 100);
    cout<<s;
 //   citire_lexic();
//    citire_gram();

    return 0;
}
