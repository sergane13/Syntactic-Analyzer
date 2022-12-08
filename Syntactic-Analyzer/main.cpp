#include <iostream>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

#include "functions.h"
#include "Button.h"

#define VIEWPORT_HEIGHT 600
#define VIEWPORT_LENGHT 1200

using namespace std;


int main()
{
    char inputCharacter;

    char fullSentence[300];
    resetSentence(fullSentence);

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

    // code goes here
    //      ||
    //      ||
    //      \/

    inputCharacter = (char)getch();

    while(true)
    {
        readingInputText(VIEWPORT_LENGHT, fullSentence, inputCharacter);
        numberOfWords = getEachWordFromText(fullSentence, eachWord);

        drawInputField(VIEWPORT_LENGHT, fullSentence);
        drawWholeTableField(
                        eachWord,
                        numberOfWords,
                        centerPoint,
                        FIELD_HEIGHT,
                        FIELD_LENGHT);

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

    //      /\
    //      ||
    //      ||
    // code goes here

    getch();
    closegraph();

    return 0;
}
