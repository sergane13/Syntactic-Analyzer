#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

/**
*lexic = structura care implementeaza vocabularul posibil folosit si are ca parametrii
*pdv = parte de vorbire
*cuv = cuvant
*pdv = 1 - det
*pdv = 2 - pron
*pdv = 3 - n
*pdv = 4 - v
*pdv = 5 - a
*pdv = 6 - c
*/
struct lexic{
    int contor =0;//numara cate cuvinte de acelasi tip sunt
    char parte_dv[100];
    int cdv = 0;//contor parte de vorbire
    char parte_dp[100][100];
    int cdp = 0;//contor parti de propozitie
    char cuv[1000][100];//retine cuvintele respective unei anumite parti de vorbire
} pdv[1000];

struct gram {

}s;


void citire_lexic(){
    FILE *ptr;//deschid fisierul
    ptr = fopen("LEX.TXT", "r");

    char c[100];//cuvant de citit din fisier
    char p[100];//parte de vorbire de citit din fisier
    char cpy_c[100] = "";

//initializez structul corespunzator lexicului

    strcpy(pdv[1].parte_dv, "Det");
    strcpy(pdv[2].parte_dv, "Pron");
    strcpy(pdv[3].parte_dv, "N");
    strcpy(pdv[4].parte_dv, "V");
    strcpy(pdv[5].parte_dv, "A");
    strcpy(pdv[6].parte_dv, "C");

    while(fscanf(ptr, " %s %s", p, c) && strcmp(c, cpy_c)!=NULL){
        if(strcmp(p, "Det") == 0){
            strcpy(pdv[1].cuv[pdv[1].contor++], c);
        } else if(strcmp(p, "Pron") == 0){
            strcpy(pdv[2].cuv[pdv[2].contor++], c);
        } else if(strcmp(p, "N") == 0){
            strcpy(pdv[3].cuv[pdv[3].contor++], c);
        } else if(strcmp(p, "V") == 0){
            strcpy(pdv[4].cuv[pdv[4].contor++], c);
        } else if(strcmp(p, "A") == 0){
            strcpy(pdv[5].cuv[pdv[5].contor++], c);
        } else if(strcmp(p, "C") == 0){
            strcpy(pdv[6].cuv[pdv[6].contor++], c);
        }
        strcpy(cpy_c, c);
    }

    fclose(ptr);
}

void citire_gram(){

    char s[100];
    ifstream f("GRAM.TXT");
    while(f>>s){
        cout<<s<<' ';
    }

    f.close();

}
