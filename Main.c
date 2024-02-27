#include "StrList.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX 500
#define MAX_WORD 20

StrList* text_to_list(char* str)
{
    char* split = strtok(str," ");
    printf("%s",split);
    StrList* list = StrList_alloc(split);
    while(split!=NULL)
    {
        printf("%s",split);
        StrList_insertLast(list,split);
        split = strtok(NULL," ");
    }
    return list;
}


int main()
{
    char buffer[MAX];
    int action=0;
    int amount=0;
    int index=0;
    StrList* user;

    do
    {
        scanf("%d",&action);

        switch (action)
        {
        case 1:
            scanf(" %d ",&amount); //amount of words

            fgets(buffer,MAX,stdin); // list insertion

            size_t len = strlen(buffer); //New line character deletion
            buffer[len-1]='\0';

            char* split = strtok(buffer," "); //space seperation
            user = StrList_alloc();
            while(amount>0) // inserting each word to the String list
            {
                amount--;
                StrList_insertLast(user,split);
                split = strtok(NULL," ");
            }
            break;

        case 2:
            scanf(" %d ",&index); //index input
            char word[MAX_WORD]; //word buffer
            
            fgets(word,MAX_WORD,stdin);
            len = strlen(word); //New line character deletion
            word[len-1]='\0';

            StrList_insertAt(user,word,index);
            break;
        case 3:
            StrList_print(user);
            break;
        case 4:
            printf("%ld\n", StrList_size(user));
            break;
        case 5:
            scanf("%d",&index); //index input
            StrList_printAt(user,index);
            break;
        case 6:
            printf("%d\n",StrList_printLen(user));
            break;
        case 7:
            char target[MAX_WORD]; //word buffer
            
            scanf(" %s", target);

            printf("%d\n", StrList_count(user,target));
            break;
        case 8:
            char target2[MAX_WORD]; //word buffer
            
            scanf("%s", target2);

            StrList_remove(user,target2);
            break;
        case 9:
            scanf("%d ",&index); //index input
            StrList_removeAt(user, index);
            break;
        case 10:
            StrList_reverse(user);
            break;
        case 11:
            StrList_free(user);
            user = StrList_alloc();
            break;
        case 12:
            StrList_sort(user);
            break;
        case 13:
            int state = StrList_isSorted(user);
            if(state==1)
            {
                printf("true\n");
            }
            else
            {
                printf("false\n");
            }
            break;
        default:
            break;
        }
    }  
    while (action!=0);

    printf("exit\n");
    return 0;

    
}