#include <iostream>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

#include <cstring>
#include<fstream>
#include "flux_date.h"
#include "opereaza_fraza.h"
#include <unordered_map>
#include <vector>

#include "functions.h"
#include "Button.h"

#define VIEWPORT_HEIGHT 600
#define VIEWPORT_LENGHT 1200

ifstream f("DATE.IN");

using namespace std;

int main()
{
    char inputCharacter;

    char fullSentence[300];
    resetSentence(fullSentence);

    // int l_matrice;
    // alocate memory for 2-dimensional array

    char** eachWord;
    int numberOfWords;

    eachWord = new char*[50];
    for(int i = 0; i < 50; i++)
    {
        eachWord[i] = new char[50];
    }

    viewportPoint centerPoint;
    centerPoint.x = VIEWPORT_LENGHT / 2;
    centerPoint.y = VIEWPORT_HEIGHT / 2;

    initwindow(VIEWPORT_LENGHT, VIEWPORT_HEIGHT);

    drawInputField(VIEWPORT_LENGHT, fullSentence);

    inputCharacter = (char)getch();

    // se citeste din fisiere
    citire();

    while(true)
    {
        readingInputText(VIEWPORT_LENGHT, fullSentence, inputCharacter);


        // se face o copie la stringul original
        char temp[300];
        strcpy(temp, fullSentence);


        // se creaza matricea 3-dimensionala
        // matr.m, i,j --> dimensiunea in 2d
        //           k --> numarul de elemente din casuta
        int tempValue = creaza_matricea(temp, matr.m, map_cuvinte, map_pdv);
        // afiseaza_matricea(tempValue);


        // se extrage numarul de cuvinte din propozitie
        numberOfWords = getEachWordFromText(fullSentence, eachWord);


        drawInputField(VIEWPORT_LENGHT, fullSentence);


        if(numberOfWords > 0)
        {
             drawWholeTableField(
                        eachWord,
                        numberOfWords,
                        matr.m,
                        centerPoint,
                        FIELD_HEIGHT,
                        FIELD_LENGHT);
        }

        inputCharacter = (char)getch();

        if((int)inputCharacter == CLOSE_KEY_1 || (int)inputCharacter == CLOSE_KEY_2)
        {
            break;
        }
        else
        {
            resetSentence(fullSentence);
            clearviewport();
            drawInputField(VIEWPORT_LENGHT, fullSentence);
        }
    }

    getch();
    closegraph();

    return 0;
}
