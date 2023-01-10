#include <iostream>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string>
#include <cstring>

#include "functions.h"
#include "Button.h"

#define chenarImg "chenarSimplu.jpg" // chenar pentru un field din tabel

using namespace std;


/// -- READY --
// draw the conclusion of analysis
void drawConclusion(int windowLenght, bool conclusion)
{
    if(conclusion)
    {
        setcolor(GREEN);
        setbkcolor(BLACK);

        outtextxy(windowLenght/2 + 350 - 170, 20, "The sentence is CORRECT");
    }
    else
    {
        setcolor(RED);
        setbkcolor(BLACK);

        outtextxy(windowLenght/2 + 350 - 160, 20, "The sentence is WRONG");
    }
}


/// -- In progress --
// draws the input field where user add his sentence
// automatic resize in progress
void drawInputField(int windowLenght, char fullSentence[300], int sentanceLenght)
{
    outtextxy(windowLenght/2 - 350 + 2, 20, "Add your text here. Press ENTER when ready. ");

    int necesaryRows = sentanceLenght / 100 + 1;
    int heightSize = 50 + necesaryRows * 20;

    rectangle(
        windowLenght / 2 - 350, 50,
        windowLenght / 2 + 350, heightSize
    );

    for(int i = 0 ; i < necesaryRows; i++)
    {
         outtextxy(windowLenght/2 - 350 + 2, heightSize - 20 + 2, fullSentence);
    }
}


/// -- READY --
// draw the table with the analyzed sentance
// the table si n x n
void drawTableField(
        int startX,
        int startY,
        int endX,
        int endY,
        char word[50])
{
    rectangle(
        startX,
        startY,
        endX,
        endY
    );

    // the image for a table field
    readimagefile(chenarImg, startX, startY, endX, endY);

    setbkcolor(COLOR(242, 242, 242));
    setcolor(BLACK);
    outtextxy(startX + 5, startY + 5, word);
}


/// -- READY --
// reading input text from keyboard
// and display it on the viewport
void readingInputText(
        int windowLenght,
        char fullSentence[300],
        char auxCharacter)
{
    int counterFullSentence = 0;

    while((int)auxCharacter != ENTER_KEY)
    {
        // if backspace delete characters
        // else add characters
        if((int)auxCharacter == BACKSPACE_KEY && counterFullSentence > 0)
        {
            counterFullSentence--;
            fullSentence[counterFullSentence] = NULL;
        }
        else
        {
            fullSentence[counterFullSentence] = auxCharacter;
            counterFullSentence++;
        }

        clearviewport();
        drawInputField(windowLenght, fullSentence, counterFullSentence);

        //drawButton(120, 60);
        //buttonClicked(120, 60, mouseClicked);

        auxCharacter = (char)getch();

    }
}


/// -- READY --
// draw the input field with all the elements
void drawWholeTableField(
       char** eachWord,
       int numberOfWords,
       string matrice[30][30][30],
       viewportPoint centerPoint,
       int fieldHeight,
       int fieldLenght)
{
    char temp[50];
    //string temp;

    viewportPoint startPoint;
    startPoint.x = centerPoint.x - ((numberOfWords + 1) * (FIELD_LENGHT * 0.5));
    startPoint.y = 100; // need to be dynamic

    for(int i = 0; i < numberOfWords + 1; i++)
    {
        for(int j = 0; j < numberOfWords + 1; j++)
        {
            if(i == 0 && i != j)
            {
                temp[0] = j + '0';
            }
            else if(j == 0 && i != j)
            {
                strcpy(temp, eachWord[i - 1]);
            }
            else if(i == j && i == 0 && j == 0)
            {
                strcpy(temp, "");
            }
            else
            {
                strcpy(temp, matrice[j - 1][i - 1][0].c_str()); // the word analyzed
            }

            drawTableField(
                startPoint.x + (fieldLenght * i),
                startPoint.y + (fieldHeight * j),
                startPoint.x + fieldLenght * (i + 1),
                startPoint.y + fieldHeight * (j + 1),
                temp
            );
        }
    }

    // show the result
    if(matrice[0][numberOfWords - 1][0] == "S")
    {
        drawConclusion(1200, TRUE);
    }
    else
    {
        drawConclusion(1200, FALSE);
    }

    setcolor(WHITE);

    // show text that user need to press ENTER to run the program again
    int textPositionY = centerPoint.y + (numberOfWords * 0.5) * FIELD_HEIGHT;
    outtextxy(startPoint.x, textPositionY, "Press ENTER again to run the program.");
}


/// -- READY --
// obtain each word from text
int getEachWordFromText(
        char* sentence,
        char** eachWord)
{
    int index = 0;
    char* word = strtok(sentence, " ");

    while(word)
    {
        eachWord[index] = word;
        index++;

        word = strtok(NULL, " ");
    }

    return index;
}


/// -- READY --
// initiate the whole sentance with NULL
void resetSentence(char fullSentence[300])
{
    for(int i = 0; i < 300; i++)
    {
        fullSentence[i] = NULL;
    }
}
