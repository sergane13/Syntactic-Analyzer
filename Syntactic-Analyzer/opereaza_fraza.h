#include <iostream>
#include<fstream>
#include <cstring>
#include <unordered_map>


using namespace std;


char* citeste_fraza()
{
    char* ch = new char;
    cin.get(ch, 100);
    return ch;
}


int citeste_matricea(char s[], char matrice[][100][100]
                     , unordered_map<string, string> map_list){
    int l_matrice=0;
    char*ptr;
    ptr =strtok(s, " ");
    while(ptr!=NULL){
        strcpy(matrice[0][l_matrice++], map_list[ptr].c_str());
        ptr = strtok(NULL, " ");
    }
    return l_matrice;
}


void afiseaza_matricea(char s[], char matrice[][100][100], int l_matrice ){
    /*for(int i=0; i<=l_matrice; ++i){
        for(int j=0; j<l_matrice; ++j){
            if(i==0)
                cout<<matrice[i][j]<<' ';
            else
                cout<<'0'<<' ';
        }
        cout<<'\n';
    }*/

    for(int j=0; j<l_matrice; ++j){
        cout<<matrice[0][j]<<' ';
    }
}


