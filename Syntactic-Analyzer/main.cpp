#include <iostream>
//#include <cstring>
#include<fstream>
#include "flux_date.h"


using namespace std;

ifstream f("DATE.IN");



int main()
{
    citire_lexic();
    citire_gram();
    afisare_gram();
    afisare_lex();

    return 0;
}
