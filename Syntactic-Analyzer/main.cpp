#include <iostream>
#include <cstring>
#include<fstream>
#include "flux_date.h"
#include "opereaza_fraza.h"
#include <unordered_map>


using namespace std;

ifstream f("DATE.IN");


int main()
{
    citire_lexic();
   // citire_gram();
   // afisare_gram();
    //afisare_lex();

    char s[100];
    strcpy(s, citeste_fraza());//copiem fraza in s

    char matrice[100][100][100];
    int l_matrice = citeste_matricea(s, matrice, map_cuvinte);

    afiseaza_matricea(s, matrice, l_matrice);



    return 0;
}
