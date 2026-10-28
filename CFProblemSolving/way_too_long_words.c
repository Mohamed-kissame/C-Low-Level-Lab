#include <stdio.h>
#include <string.h>

void PrintAbbreviatedWord(const char *word)
{

    if (word == NULL)
    {
      return;
    }
    

    int length = strlen(word);

    if (length <= 10)
    {
        printf("%s\n", word);
    }
    else
    {
        printf("%c%d%c\n", word[0], length - 2, word[length - 1]);
    }
}

int main(void){

    int n ;

    char word[101];

    scanf("%d" , &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%100s" , word);

        PrintAbbreviatedWord(word);
    }
    

    return 0;

}