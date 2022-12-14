#include <iostream>
#include <cstring>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <map>
#include <list>

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

unordered_map <string, string>  map_cuvinte;

map<pair<string, string>, string> map_pdv;

list<string> matrice[100][100];

struct lexic{
    int contor =0;//numara cate cuvinte de acelasi tip sunt
    char parte_dv[100];
    char cuv[1000][100];//retine cuvintele respective unei anumite parti de vorbire
} pdv[1000];


void init_lex_pdv(){
    //initializez structul corespunzator lexicului
    strcpy(pdv[1].parte_dv, "Det");
    strcpy(pdv[2].parte_dv, "Pron");
    strcpy(pdv[3].parte_dv, "N");
    strcpy(pdv[4].parte_dv, "V");
    strcpy(pdv[5].parte_dv, "A");
    strcpy(pdv[6].parte_dv, "C");
}

void adauga_in_map(){
    for(int i=1; i<=6; ++i){
        for(int j=0; j<pdv[i].contor; ++j){
            map_cuvinte[pdv[i].cuv[j]] = pdv[i].parte_dv;
        }
    }
}

void citire_lexic(){
    FILE *ptr;//deschid fisierul
    ptr = fopen("LEX.TXT", "r");
    init_lex_pdv();
    char c[100];//cuvant de citit din fisier
    char p[100];//parte de vorbire de citit din fisier
    char cpy_c[100] = "";

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

    adauga_in_map();

    fclose(ptr);
}

void adauga_in_map_pdv(char s[]){
    int nr_rez;
    string r, p1, p2;//rezultat, parte de vb1, parte de vb2

    char *p;

    p = strtok(s, " ");
    r = p;

    p = strtok(NULL, " ");
    p1 = p;

    if(p = strtok(NULL, " ")){
        p2 = p;
    } else {
        p2 = "";
    }

    map_pdv[{p1, p2}] = r;

}

void citire_gram(){
    char s[100];
    ifstream f("GRAM.TXT");
    while(f.getline(s, 100, '\n')){
        adauga_in_map_pdv(s);
    }
}

void afisare_lex(){
    for(int i=1; i<=6; ++i){
        cout<<pdv[i].parte_dv<<' ';
        for(int j=0; j<pdv[i].contor; ++j){
            cout<<pdv[i].cuv[j]<<' ';
        }
        cout<<'\n';
    }
}
