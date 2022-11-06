#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#pragma warning (disable : 4996)

typedef struct Loto
{
    int Loto_Num;
    char Loto_Date[1000];
    struct Loto* Next;
    struct Loto* Prev;
}t_Loto;


t_Loto* Tail = NULL;
t_Loto* Head = NULL;
t_Loto* previtem = NULL;
int ItemCount = 0;

void AddItem(int Loto_Num, char Loto_Date[1000])
{
    t_Loto* curr = NULL;
    curr = (t_Loto*)malloc(sizeof(t_Loto));
    curr->Loto_Num = Loto_Num;
    strcpy(curr->Loto_Date, Loto_Date);
    ItemCount++;

    if (Head == NULL) {
        //EventLogval("added the First number to the list", number);
        Head = curr;
        Tail = curr;
        curr->Prev = NULL;
        curr->Next = NULL;
        previtem = curr;
    }
    else
    {
        //EventLogval("added a number to the list", number);
        curr->Next = NULL;
        curr->Prev = previtem;
        previtem->Next = curr;
        Tail = curr;
        previtem = curr;
    }
}

void LoadFile()
{
    char str[1000];
    char Loto_Num[1000];
    char Loto_Date[1000];
    char Loto_grbish[10000];
    char* token = strtok(str, ",");

    FILE* f = fopen("Lotto.txt", "r");
    if (f) {

        fgets(str, 1000, f);

        while (fgets(str, 1000, f) != NULL)
        {
            token = strtok(str, ",");
            strcpy(Loto_Num, token);
            token = strtok(NULL, ",");
            strcpy(Loto_Date, token);
            AddItem(atoi(Loto_Num), Loto_Date);
        }
    }
}

void Printlist()
{
    t_Loto* currItem1 = Head;
    t_Loto* printL = Head;

    while (printL->Next != NULL)
    {
        printL = currItem1;
        currItem1 = currItem1->Next;
        printf("Loto_Num:%d\t Loto_Date:%s\n\n",printL->Loto_Num,printL->Loto_Date);
    }
    printf("\nin the list you have:%d items\n\n", ItemCount);
}

void GetDateByIndex(int Loto_Num)
{
    t_Loto* currentItem1 = Head;
    t_Loto* printL = Head;

    while (printL->Next != NULL)
    {
        printL = currentItem1;
        currentItem1 = currentItem1->Next;

        if (printL->Loto_Num == Loto_Num) {
            printf("Loto_Num:%d\t Loto_Date:%s\n\n", printL->Loto_Num, printL->Loto_Date);
        }
    }

}

void FreeList()
{
    t_Loto* currentItem1 = Head;
    t_Loto* printL = Head;

    while (currentItem1 != NULL)
    {
        printL = currentItem1;
        currentItem1 = currentItem1->Next;
        free(printL);
    }
}

void Replace(t_Loto* item)
{
    if (item == NULL) {
        //EventLogval("No need to swap", 0);
        return;
    }

    t_Loto CopyList;
    t_Loto* NextItem;
    t_Loto* List;

   

    List = item;
    CopyList.Next = item->Next;
    CopyList.Prev = item->Prev;
    NextItem = item->Next;


    if (item == Tail) {
        // EventLogval("No need to swap", item->num);
        return;
    }
    else if (List == Head && NextItem == Tail)
    {
        List->Prev = NextItem;
        List->Next = NextItem->Next;
        NextItem->Prev = CopyList.Prev;
        NextItem->Next = List;
        Tail = List;
        Head = NextItem;
    }
    else if (item == Head) {
        List->Prev = NextItem;
        List->Next = NextItem->Next;
        NextItem->Prev = CopyList.Prev;
        NextItem->Next = List;
        List->Next->Prev = List;
        Head = NextItem;
    }
    else if (item == Tail->Prev)
    {
        List->Prev = NextItem;
        List->Next = NextItem->Next;
        NextItem->Prev = CopyList.Prev;
        NextItem->Next = List;
        NextItem->Prev->Next = NextItem;
        if (Tail == NextItem) {
            Tail = List;
        }
    }
    else
    {
        List->Prev = NextItem;
        List->Next = NextItem->Next;
        NextItem->Prev = CopyList.Prev;
        NextItem->Next = List;
        NextItem->Prev->Next = NextItem;
        List->Next->Prev = List;
    }
}

void Shaiker_BubleSort()
{

    int Bublecounter = 1;

    t_Loto* curr = Head;

    if (!curr/* !curr = curr!=NULL*/) {
        //EventLog("the list is empty");
        return;
    }

    t_Loto* CheckItem = Head->Next;

    t_Loto* CopyHead = NULL;
    t_Loto* CopyTail = NULL;

    //EventLog("Start sorting");
    while (Bublecounter != 0)
    {
        curr = Head;
        CheckItem = Head->Next;

        while (Bublecounter != 0)
        {
            Bublecounter = 0;

            while (CheckItem != NULL && curr->Next != CopyTail)
            {
                if (curr->Loto_Num > CheckItem->Loto_Num) {
                    Replace(curr);
                    CheckItem = curr->Next;
                    Bublecounter++;
                }
                else
                {
                    curr = curr->Next;
                    CheckItem = CheckItem->Next;
                }
            }
            CopyTail = curr;
            curr = curr->Prev;
            CheckItem = curr->Prev;


            while (CheckItem != NULL && curr->Prev != CopyHead)
            {
                if (curr->Loto_Num < CheckItem->Loto_Num) {
                    Replace(CheckItem);
                    CheckItem = curr->Prev;
                    Bublecounter++;
                }
                else
                {
                    curr = curr->Prev;
                    CheckItem = CheckItem->Prev;
                }
            }
            CopyHead = curr;
            curr = curr->Next;
            CheckItem = curr->Next;

        }
    }
    //EventLog("End sorting");

}

#define clear() printf("\033[H\033[J")


int main()
{

    char UserRispon = 0;
    int loto_Dic = 0;

    while (UserRispon != 'Q'|| UserRispon!='q') {
        printf("\n\n\n****MENU****\n~Type Option Number For Execution~\nN.Data for Number of lottery\nS.Sort the List By Loto number, and print\nQ.Quit\ntype here:");
        UserRispon = getch();
        printf("\n\n\n\n");
        
        switch (UserRispon)
        {
        case 'n':
        case 'N':
            LoadFile();
            //Printlist();
            printf("Which lottery number are you interested in getting a date on?:");
            scanf("%d", &loto_Dic);
            GetDateByIndex(loto_Dic);
            Sleep(3000);
            break;
        case 's':
        case 'S':
            LoadFile();
            Shaiker_BubleSort();
            Printlist();
            break;
        case 'Q':
        case 'q':
            clear();
            printf("bye bye:)\n");
            FreeList();
            Sleep(1000);
            return;
        default:
            printf("invalid number");
            printf("\n\n");
            break;
        }
    }

    return 0;
}
