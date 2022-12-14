#include <iostream>
#include<fstream>
#include <cstring>
#include <unordered_map>
#include <vector>
#include <map>
//#include <list>
#include <vector>


using namespace std;


char* citeste_fraza()
{
    char* ch = new char;
    cin.get(ch, 100);
    return ch;
}


int citeste_matricea(char s[], vector<vector<string>> matrice
                     , unordered_map<string, string> map_list){
    int l_matrice=0;
    char*ptr;
    ptr =strtok(s, " ");
    while(ptr!=NULL){
//        strcpy(matrice[0][l_matrice++], map_list[ptr].c_str());
        cout<<"test";
        matrice[l_matrice][l_matrice]=map_list[ptr].c_str();
        cout<<"test";
        l_matrice++;
        cout<<"test";
        ptr = strtok(NULL, " ");
        cout<<"test";
    }
    return l_matrice;
}


void afiseaza_matricea(char s[], vector<string> matrice[100][100], int l_matrice ){
    for(int i=0; i<=l_matrice; ++i){
        for(int j=0; j<l_matrice; ++j){

        }
        cout<<'\n';
    }
}


int verifica(int i, int j){
    for(int k = i; k<j; ++k){
        cout<<i<<k<<" + "<<k+1<<j<<'\n';
    }
}

void parcurgere_matrice(int n){
    for(int i=0; i<n; ++i){
        for(int j = 0, l = i; l<n; ++j, ++l){
            ///j si l sunt contorii pe care ii urmarim
            verifica(j, l);
            cout<<endl;
        }
    }
}
