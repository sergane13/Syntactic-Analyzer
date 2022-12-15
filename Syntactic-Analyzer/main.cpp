#include <iostream>
#include <cstring>
#include<fstream>
#include "flux_date.h"
#include "opereaza_fraza.h"
#include <unordered_map>
#include <vector>

using namespace std;

ifstream f("DATE.IN");


int main()
{
    citire();

    char s[100];
    strcpy(s, citeste_fraza());//copiem fraza in s

    int l_matrice = creaza_matricea(s, matr.m, map_cuvinte, map_pdv);

    afiseaza_matricea(l_matrice);
    return 0;
}
