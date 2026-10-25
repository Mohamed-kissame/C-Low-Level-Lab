#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {

    char Value;
    struct Node *Next;

};

bool Push(struct Node **Top , char Value){

    if(Top == NULL){
        return false;
    }

    struct Node *newNode = malloc(sizeof *newNode);

    if(newNode == NULL){

        return false;
    }

    newNode->Value = Value;

    newNode->Next = *Top;
    *Top = newNode;

    return true;
}

bool Pop(struct Node **Top){

    if(Top == NULL || *Top == NULL){
           return false;
    }

    struct Node *nodeToDelte = *Top;

    *Top = nodeToDelte->Next;

    free(nodeToDelte);

    return true;
}

bool Peek(struct Node *Top , char * TopValue){

    if(Top == NULL || TopValue == NULL)
    {
        return false;
    }

    *TopValue = Top->Value;

    return true;
}

bool IsMatchingPair(char opening, char closing)
{
    return (opening == '(' && closing == ')') ||
           (opening == '[' && closing == ']') ||
           (opening == '{' && closing == '}');
}

bool IsEmpty(struct Node *Top){

    return Top == NULL;
}

void FreeStack(struct Node **Top){

    if(Top == NULL || *Top == NULL){

        return;
    }

    struct Node *Current = *Top;

    while (Current != NULL)
    {
       struct Node *Next = Current->Next;

       free(Current);

       Current = Next;
    }

    *Top = NULL;
    
}


bool IsBalanced(const char * Expression){

    if(Expression == NULL){

        return false;
    }

    struct Node *Top = NULL;

    int i = 0;

    while (Expression[i] != '\0')
    {


        if(Expression[i]  == '(' || Expression[i] == '[' || Expression[i] == '{'){

            if(!Push(&Top , Expression[i])){

                FreeStack(&Top);
                return false;
            }
        }

        else if (Expression[i] == ')' || Expression[i] == ']' || Expression[i] == '}'){

            if(IsEmpty(Top)){

                FreeStack(&Top);
                return false;
            }


        char TopValue;

           if (!Peek(Top, &TopValue))
           {
               FreeStack(&Top);
               return false;
            }

            if (!IsMatchingPair(TopValue, Expression[i])){

                FreeStack(&Top);
                return false;
            }
             
            Pop(&Top);
        }

      i++;

    }
    
    
      if(IsEmpty(Top)){

        return true;
      }

      FreeStack(&Top);

      return false;
}

int main(void)
{
    const char *tests[] =
    {
        "()",                    // Valid
        "[]",                    // Valid
        "{}",                    // Valid

        "([])",                  // Valid
        "{[]}",                  // Valid
        "{[()]}",                // Valid
        "([]{})",                // Valid

        "([)]",                  // Invalid
        "{[(])}",                // Invalid
        "((]",                   // Invalid
        "{[",                    // Invalid

        "]",                     // Invalid
        "}{",                    // Invalid

        "",                      // Valid

        "(a + b) * [c - d]",     // Valid
        "{a + [b * (c + d)]}",   // Valid

        "(]",                    // Invalid
        "[}",                    // Invalid
        "{)",                    // Invalid

        "(((())))",              // Valid
        "[{()}]",                // Valid
        "[{(})]"                 // Invalid
    };

    int testCount = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < testCount; i++)
    {
        printf("Test %d\n", i + 1);
        printf("Expression: \"%s\"\n", tests[i]);

        if (IsBalanced(tests[i]))
        {
            printf("Result: Valid\n");
        }
        else
        {
            printf("Result: Invalid\n");
        }

        printf("-----------------------------\n");
    }


    // Extra NULL test
    printf("\nNULL Expression Test:\n");

    if (!IsBalanced(NULL))
    {
        printf("Correct: NULL expression rejected.\n");
    }
    else
    {
        printf("Error: NULL expression should be invalid.\n");
    }


    return 0;
}