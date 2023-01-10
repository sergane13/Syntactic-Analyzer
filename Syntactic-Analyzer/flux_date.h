#include <iostream>
#include <cstring>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <map>
#include <list>

using namespace std;

unordered_map <string, string>  map_cuvinte;

map<pair<string, string>, string> map_pdv;

void adauga_in_map_pdv(char s[]);

void citire_lexic(){
    cout<<"Hello";
    FILE *ptr;  //deschid fisierul
    ptr = fopen("LEX.TXT", "r");
    char c[100];    //cuvant de citit din fisier
    char p[100];    //parte de vorbire de citit din fisier
    char cpy_c[100] = "";

    while(fscanf(ptr, " %s %s", p, c) && strcmp(c, cpy_c)!=NULL){
        strcpy(cpy_c, c);
       // cout<<c<<" "<<p<<'\n';
        map_cuvinte.insert({c, p});
        map_cuvinte[c] = p;
    }

    fclose(ptr);
}

void citire_gram(){
    char s[100];
    ifstream f("GRAM.TXT");
    while(f.getline(s, 100, '\n')){
        adauga_in_map_pdv(s);
    }
}

void citire(){
    citire_lexic();
    citire_gram();
}

void adauga_in_map_pdv(char s[]){
    int nr_rez;
    string r, p1, p2;   //rezultat, parte de vb1, parte de vb2

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
