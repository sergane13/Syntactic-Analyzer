#include <iostream>
#include <cstring>
#include<fstream>
#include "flux_date.h"
#include "opereaza_fraza.h"
#include <unordered_map>
//#include <list>
#include <vector>

using namespace std;

ifstream f("DATE.IN");


int main()
{

    citire_lexic();
    citire_gram();
   // afisare_gram();
    //afisare_lex();

    char s[100];
    strcpy(s, citeste_fraza());//copiem fraza in s


    //TODO: de facut matricea???
    char matrice[][][];
    int l_matrice = citeste_matricea(s, matrice, map_cuvinte);

    cout<<matrice[0][0];

    //matrice[0][0];
    //afiseaza_matricea(s, matrice, l_matrice);
    //cout<<"Hello world!";
    //cout<<map_pdv[{"C","A"}];



    return 0;
}
