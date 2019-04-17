//NAME: Trenton Hohle Robyn Arnecke
//Serial Number: 23         4
//Group Number: 8
//Due Date: 3/27/19

//At least when I was compiling, for whatever reason it kept echoing all my inputs
//whether I got them from scanf, or gets... Do you know why? (Trenton)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validation(char[], int);
void populateArray(char arr[][94], int key);
void encrypt(char message[], int key, char [][94]);
void decrypt(char message[], int key, char [][94]);
int length(char message[]);
int isUpper(char x);
int isLower(char x);
int isDigit(char x);
int isPunct(char x);

int main(void)
{
    char answer[10];
    char message[100];
    int key = 2;
    int val = 0;
    int breaking = 1;
    char test;
    char array[2][94];
    array[0][0] = 'A';
    array[0][1] = 'B';
    array[0][2] = 'C';
    array[0][3] = 'D';
    array[0][4] = 'E';
    array[0][5] = 'F';
    array[0][6] = 'G';
    array[0][7] = 'H';
    array[0][8] = 'I';
    array[0][9] = 'J';
    array[0][10] = 'K';
    array[0][11] = 'L';
    array[0][12] = 'M';
    array[0][13] = 'N';
    array[0][14] = 'O';
    array[0][15] = 'P';
    array[0][16] = 'Q';
    array[0][17] = 'R';
    array[0][18] = 'S';
    array[0][19] = 'T';
    array[0][20] = 'U';
    array[0][21] = 'V';
    array[0][22] = 'W';
    array[0][23] = 'X';
    array[0][24] = 'Y';
    array[0][25] = 'Z';
    array[0][26] = 'a';
    array[0][27] = 'b';
    array[0][28] = 'c';
    array[0][29] = 'd';
    array[0][30] = 'e';
    array[0][31] = 'f';
    array[0][32] = 'g';
    array[0][33] = 'h';
    array[0][34] = 'i';
    array[0][35] = 'j';
    array[0][36] = 'k';
    array[0][37] = 'l';
    array[0][38] = 'm';
    array[0][39] = 'n';
    array[0][40] = 'o';
    array[0][41] = 'p';
    array[0][42] = 'q';
    array[0][43] = 'r';
    array[0][44] = 's';
    array[0][45] = 't';
    array[0][46] = 'u';
    array[0][47] = 'v';
    array[0][48] = 'w';
    array[0][49] = 'x';
    array[0][50] = 'y';
    array[0][51] = 'z';
    array[0][52] = '0';
    array[0][53] = '1';
    array[0][54] = '2';
    array[0][55] = '3';
    array[0][56] = '4';
    array[0][57] = '5';
    array[0][58] = '6';
    array[0][59] = '7';
    array[0][60] = '8';
    array[0][61] = '9';
    array[0][62] = '!';
    array[0][63] = '"';
    array[0][64] = '#';
    array[0][65] = '$';
    array[0][66] = '%';
    array[0][67] = '&';
    array[0][68] = '\'';
    array[0][69] = '(';
    array[0][70] = ')';
    array[0][71] = '*';
    array[0][72] = '+';
    array[0][73] = ',';
    array[0][74] = '-';
    array[0][75] = '.';
    array[0][76] = '/';
    array[0][77] = ':';
    array[0][78] = ';';
    array[0][79] = '<';
    array[0][80] = '=';
    array[0][81] = '>';
    array[0][82] = '?';
    array[0][83] = '@';
    array[0][84] = '[';
    array[0][85] = '\\';
    array[0][86] = ']';
    array[0][87] = '^';
    array[0][88] = '_';
    array[0][89] = '`';
    array[0][90] = '{';
    array[0][91] = '|';
    array[0][92] = '}';
    array[0][93] = '~';

    printf("Welcome to cryptography\n");

    while(1)
    {
        memset(answer, 0, sizeof answer);
        memset(message, 0, sizeof message);
        key = 2;
        printf("\nWhat would you like to do to a message?(encrypt, decrypt, exit)\n");
        printf("Enter your choice: \t");
        gets(answer);
        val = validation(answer, key);
        if(val != -1 && val != 3)
        {
            if(val != 3)
            {
                printf("\nEnter your message:\n");
                gets(message);
                printf("Enter the key number (1-93)\n");
                scanf(" %d", &key);
                fflush(stdin);

                val = validation(answer, key);
            }
        }
        if(val != -1)
        {
            switch(val)
            {
                case 1:
                    //printf("This is the encryption part\n");
                    encrypt(message, key, array);
                    break;
                case 2:
                    printf("This is the decryption part\n");
                    decrypt(message, key, array);
                    break;
                case 3:
                    goto end;
            }
        }
        fflush(stdin);
    }
    end:    printf("\nTrenton and Robyn Security Systems\n");
    printf("3-27-19\n\n");
}
int validation(char answer [], int key)
{
    int reply = 0;
    char test[10];
    int compare = 0;
    char encrypt [] = "encrypt";
    char decrypt [] = "decrypt";
    char exit [] = "exit";
    int i;

    for(i = 0; i < 10; i++)
    {
        test[i] = answer[i];
    }
    for(i = 0; i< 10; i++)
    {
        if(test[i]>='A' && test[i]<='Z')
            test[i]=test[i]^32;
    }
    i = 0;
    while(compare == 0)
    {
        if(test[i] < encrypt[i])
            compare = -1;
        if(test[i] > encrypt[i])
            compare = 1;
        if(test[i] == '\0' || encrypt[i] == '\0')
            break;
        i++;
    }
    if(compare == 0)
    {
        reply = 1;
    }
    compare = 0;
    i = 0;
    while(compare == 0)
    {
        if(test[i] < decrypt[i])
            compare = -1;
        if(test[i] > decrypt[i])
            compare = 1;
        if(test[i] == '\0' || decrypt[i] == '\0')
            break;
        i++;
    }
    if(compare == 0)
        reply = 2;
    compare = 0;
    i = 0;
    while(compare == 0)
    {
        if(test[i] < exit[i])
            compare = -1;
        if(test[i] > exit[i])
            compare = 1;
        if(test[i] == '\0' || exit[i] == '\0')
            break;
        i++;
    }
    if(compare == 0)
        reply = 3;

    if(reply == 0)
    {
        printf("\nInvalid Message\n");
        return -1;
    }

    if(key < 1 || key > 93)
    {
        printf("\nInvalid Key Number\n\n");
        return -1;

    }

    return reply;
}
void populateArray(char arr[][94], int key)
{
    int i;
    if(key > 0)
    {
        for(i = 0; i < 94; ++i)
        {
            arr[1][i] = arr[0][(i+key)%94];
        }
    }else
    {
        for(i = 0; i < 94; ++i)
        {
            arr[1][i] = arr[0][(i+key+94)%94];
        }
    }

}

void encrypt(char message[], int key, char arr[][94])
{
    int capCount = 0, lowCount = 0, digitCount = 0, symCount = 0;
    int len = length(message);
    populateArray(arr, key);
    char converted[len], encrypted[len];
    char *concat = malloc(len + len + 1);
    int i = 0;
    for(i = 0; i < len; i++)
    {
        if(isUpper(message[i])){
            capCount++;
            converted[i] = (message[i])^32;
        }
        else if(isLower(message[i])){
            lowCount++;
            converted[i] = (message[i])^32;
        }
        else if(isDigit(message[i])){
            digitCount++;
            converted[i] = message[i];
        }
        else if(isPunct(message[i])){
            symCount++;
            converted[i] = message[i];
        }
        else
            converted[i] = message[i];
    }
    int j = 0;
    for(i =0; i < len; i++)
    {
        for(j = 0; j < 94; j++)
        {
            if(message[i] == arr[0][j])
            {
                encrypted[i] = arr[1][j];
                break;
            }

        }
    }
    memcpy(concat, message, len); //Concatenates the strings
    memcpy(concat + len, encrypted, len + 1);

    printf("Number of Capital Letters: %d \n", capCount);
    printf("Number of Small Letters: %d \n", lowCount);
    printf("Number of Digits: %d \n", digitCount);
    printf("Number of Symbols: %d \n", symCount);
    printf("Number of Characters in the message: %d \n", len);
    printf("Converting Letters: %s \n", converted);
    printf("The encrypted text is: \n");
    printf(encrypted);
    printf("\n\n");
    printf("Concatenation of original and encrypted text: %s \n\n", concat);

}

void decrypt(char message[], int key, char arr[][94])
{
    int capCount = 0, lowCount = 0, digitCount = 0, symCount = 0;
    int len = length(message);
    populateArray(arr, key*-1);
    char converted[len], decrypted[len];
    char *concat = malloc(len + len + 1);
    int i = 0;
    for(i = 0 ; i < len; i++)
    {
        if(isUpper(message[i])){
            capCount++;
            converted[i] = (message[i])^32;
        }
        else if(isLower(message[i])){
            lowCount++;
            converted[i] = (message[i])^32;
        }
        else if(isDigit(message[i])){
            digitCount++;
            converted[i] = message[i];
        }
        else if(isPunct(message[i])){
            symCount++;
            converted[i] = message[i];
        }
        else
            converted[i] = message[i];
    }
    int j = 0;
    for(i =0; i < len; i++)
    {
        for(j = 0; j < 94; j++)
        {
            if(message[i] == arr[0][j])
            {
                decrypted[i] = arr[1][j];
                break;
            }

        }
    }
    memcpy(concat, message, len); //Concatenates the strings
    memcpy(concat + len, decrypted, len + 1);

    printf("Number of Capital Letters: %d \n", capCount);
    printf("Number of Small Letters: %d \n", lowCount);
    printf("Number of Digits: %d \n", digitCount);
    printf("Number of Symbols: %d \n", symCount);
    printf("Number of Characters in the message: %d \n", len);
    printf("Converting Letters: %s \n", converted);
    printf("The encrypted text is: \n");
    printf(decrypted);
    printf("\n\n");
    printf("Concatenation of original and encrypted text: %s \n\n", concat);

}

int length(char message[]) //returns length of the string
{
    int count = 0;
    int i = 0;
    for(i = 0; i < 100; i++)
    {
        if(message[i] != '\0')
            count++;
    }
    return count;
}
int isUpper(char x) //checks if char is Caps
{
    if(x >= 65 && x <= 90)
        return 1;
    else
        return 0;
}

int isLower(char x) //checks if char is lowercase
{
    if(x >= 97 && x <= 122)
        return 1;
    else
        return 0;
}

int isDigit(char x) //checks if char is a digit
{
    if(x >= 48 && x <= 57)
        return 1;
    else
        return 0;
}

int isPunct(char x) //checks if is punctuation
{
    if((x >= 33 && x <= 47) || (x >= 58 && x <=64) ||
       (x >= 91 && x <=96) || (x >= 123 && x <= 126))
        return 1;
    else
        return 0;
}














