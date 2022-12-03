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
    char cuv[1000][100];//retine cuvintele respective unei anumite parti de vorbire
} pdv[1000];

struct gram {
    char rezultat[100]; // partea de propozitie care rezulta din posib[].p1 si posib[].p2

    int cont = 0;
    struct combinatii{
        char p1[100];
        char p2[100];
    }posib[100];

} rez[100];



void init_lex_pdv(){
    //initializez structul corespunzator lexicului
    strcpy(pdv[1].parte_dv, "Det");
    strcpy(pdv[2].parte_dv, "Pron");
    strcpy(pdv[3].parte_dv, "N");
    strcpy(pdv[4].parte_dv, "V");
    strcpy(pdv[5].parte_dv, "A");
    strcpy(pdv[6].parte_dv, "C");
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

    fclose(ptr);
}

void init_rez(){
    strcpy(rez[1].rezultat, "S");
    strcpy(rez[2].rezultat, "NP");
    strcpy(rez[3].rezultat, "AP");
    strcpy(rez[4].rezultat, "CP");
    strcpy(rez[5].rezultat, "VP");
}

int verifica_pp(char p[]){ ///
    if(strcmp(p, "S") == 0)
        return 1;
    else if(strcmp(p, "NP") == 0)
        return 2;
    else if(strcmp(p, "AP") == 0)
        return 3;
    else if(strcmp(p, "CP") == 0)
        return 4;
    else if(strcmp(p, "VP") == 0)
        return 5;

    return 0;
}

int verifica_si_adauga(char p[]){
    return 0;
}

void adauga_in_gram(char s[]){
    init_rez();
    int nr_rez;
    char *p;

    p = strtok(s, " ");
    nr_rez = verifica_pp(p);

    p = strtok(NULL, " ");
    strcpy(rez[nr_rez].posib[rez[nr_rez].cont].p1, p);

    if(p = strtok(NULL, " ")){
        strcpy(rez[nr_rez].posib[rez[nr_rez].cont].p2, p);
    }

    rez[nr_rez].cont++;
}

void citire_gram(){

    char s[100];
    ifstream f("GRAM.TXT");
    while(f.getline(s, 100, '\n')){
        adauga_in_gram(s);
    }
}


void afisare_gram(){
    for(int i=1; i<5; ++i){
        cout<<rez[i].rezultat<<'\n';
        for(int j=0; j<rez[i].cont; ++j){
            cout<<"  "<<rez[i].posib[j].p1<<' '<<rez[i].posib[j].p2<<'\n';
        }
        cout<<'\n';
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
