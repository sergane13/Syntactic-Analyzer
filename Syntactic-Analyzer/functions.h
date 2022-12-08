#pragma once

#define ENTER_KEY 13
#define BACKSPACE_KEY 8
#define CLOSE_KEY_1 120
#define CLOSE_KEY_2 88

#define FIELD_HEIGHT 40
#define FIELD_LENGHT 100

struct viewportPoint
{
    int x;
    int y;
};

void drawTableField(int startX, int startY, int endX, int endY, char word[]);
void drawInputField(int windowLenght, char fullSentence[], int sentanceLenght = 0);
void readingInputText(int windowLenght, char fullSentence[], char auxCharacter);
void drawWholeTableField(char** eachWord, int numberOfWords, viewportPoint centerPoint, int fieldHeight = 1 ,int fieldLenght = 1);
int getEachWordFromText(char* sentence, char** eachWord);
void resetSentence(char fullSentence[]);




