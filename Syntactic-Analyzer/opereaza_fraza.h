#include <iostream>
#include<fstream>
#include <cstring>
#include <unordered_map>
#include <vector>
#include <map>
#include <vector>


using namespace std;


struct Matrice{
    string m[30][30][30];//se va salva matricea
    int c[30][30];//in acest tablou se vor salva contorii
                         //acea casuta
}matr;


char* citeste_fraza()
{
    char* ch = new char;
    cin.get(ch, 100);
    return ch;
}


void prima_parcurgere_pe_diagonala(int n, map<pair<string, string>, string> map_pdv){
    for(int i=0; i<n; ++i){
        matr.c[i][i] = 1;
    }

    for(int i=0; i<n; ++i){
        if(!map_pdv[{matr.m[i][i][0],""}].empty()){
            matr.m[i][i][matr.c[i][i]] = map_pdv[{matr.m[i][i][0],""}];
            ++matr.c[i][i];
        }
    }
}

int verifica(int i, int j){
    for(int k = i; k<j; ++k){
        //cout<<i<<k<<" + "<<k+1<<j<<'\n';
        for(int cont_1 = 0; cont_1<matr.c[i][k]; cont_1++)
            for(int cont_2 = 0; cont_2<matr.c[k+1][j]; cont_2++)
                 if(!map_pdv[{matr.m[i][k][cont_1],matr.m[k+1][j][cont_2]}].empty())
                    matr.m[i][j][matr.c[i][j]++] = map_pdv[{matr.m[i][k][cont_1],matr.m[k+1][j][cont_2]}];
    }
}

void parcurgere_matrice(int n, map<pair<string, string>, string> map_pdv){
    for(int i=0; i<n; ++i){
        for(int j = 0, l = i; l<n; ++j, ++l){
            ///j si l sunt contorii pe care ii urmarim
            verifica(j, l);
            //cout<<endl;
        }
    }
}

int creaza_matricea(char s[], string matrice[30][30][30]
                     , unordered_map<string, string> map_list
                     , map<pair<string, string>, string> map_pdv){
    int l_matrice=0;
    char*ptr;
    ptr =strtok(s, " ");
    while(ptr!=NULL){
        matrice[l_matrice][l_matrice][0]=map_list[ptr].c_str();
        l_matrice++;
        ptr = strtok(NULL, " ");
    }

    prima_parcurgere_pe_diagonala(l_matrice, map_pdv);
    parcurgere_matrice(l_matrice, map_pdv);
    return l_matrice;
}

/**
    *n = nr de elem de pe o linie
*/
