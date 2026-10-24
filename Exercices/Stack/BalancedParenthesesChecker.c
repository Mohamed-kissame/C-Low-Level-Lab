#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    char value;
    struct Node *Next;
};


bool Push(struct Node **Top, char value)
{
    if (Top == NULL)
    {
        return false;
    }

    struct Node *newNode = malloc(sizeof *newNode);

    if (newNode == NULL)
    {
        return false;
    }

    newNode->value = value;
    newNode->Next = *Top;

    *Top = newNode;

    return true;
}


bool Pop(struct Node **Top)
{
    if (Top == NULL || *Top == NULL )
    {
        return false;
    }

    struct Node *nodeToDelete = *Top;

  
    *Top = nodeToDelete->Next;

    free(nodeToDelete);

    return true;
}

bool IsEmpty(struct Node *Top){

    return Top == NULL;
}

void FreeStack(struct Node **Top)
{
    if(Top == NULL || *Top == NULL){
        return;
    }

    struct Node *Current = *Top;

    while(Current != NULL){

        struct Node *Next = Current->Next;
        
        free(Current);

        Current = Next;
    }

    *Top = NULL;
}

bool IsBalanced(const char * expression){

    if (expression == NULL)
    {
       return false;
    }

    struct Node *Top = NULL;

    int i = 0;

    while (expression[i] != '\0')
    {
      
        if(expression[i] == '('){

          if (!Push(&Top, expression[i]))
            {
              FreeStack(&Top);
              return false;
            }
        }

        else if (expression[i] == ')')
        {
            if (IsEmpty(Top))
            {
                FreeStack(&Top);
                return false;
            }
          
                Pop(&Top);
            
        }

        i++;
        
    }

    if (IsEmpty(Top))
    {
      return true;
    }
    
    FreeStack(&Top);

    return false;
    

}

int main(void)
{
    const char *tests[] =
    {
        "()", // Valid
        "(())", // Valid
        "(()())", // Valid
        "(()", // InValid
        "())", // InValid
        ")(", // InValid
        "((()))", // Valid
        "" // Valid
    };

    int testCount = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < testCount; i++)
    {
        printf("Expression: \"%s\"\n", tests[i]);

        if (IsBalanced(tests[i]))
        {
            printf("Result: Valid\n");
        }
        else
        {
            printf("Result: Invalid\n");
        }

        printf("--------------------\n");
    }

    return 0;
}