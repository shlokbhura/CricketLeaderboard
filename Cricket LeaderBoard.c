#include <stdio.h>
#include <stdlib.h>
struct Node {
    int runs;
    int playerNo;
    struct Node* next;
};

struct Node1 {
    int wickets;
    int playerNo;
    struct Node1* next;
};

void BatsmenSortedInsert(struct Node** head_ref, struct Node* new_node)
{
    struct Node* current;
    if (*head_ref == NULL || (*head_ref)->runs >= new_node->runs) 
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else 
    {
        current = *head_ref;
        while (current->next != NULL
            && current->next->runs < new_node->runs) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void BowlersSortedInsert(struct Node1** head_ref, struct Node1* new_node1)
{
    struct Node1* current1;
    if (*head_ref == NULL || (*head_ref)->wickets >= new_node1->wickets) 
    {
        new_node1->next = *head_ref;
        *head_ref = new_node1;
}
    else 
    {
        current1 = *head_ref;
        while (current1->next != NULL && current1->next->wickets < new_node1->wickets) 
        {
            current1 = current1->next;
        }
        new_node1->next = current1->next;
        current1->next = new_node1;
    }
}

struct Node* newNode(int new_data, int new_player)
{

    struct Node* new_node= (struct Node*)malloc(sizeof(struct Node));

    new_node->runs = new_data;
    new_node->playerNo=new_player;
    new_node->next = NULL;

    return new_node;
}

struct Node1* newNode1(int new_data, int new_player)
{

    struct Node1* new_node= (struct Node1*)malloc(sizeof(struct Node1));

    new_node->wickets = new_data;
    new_node->playerNo=new_player;
    new_node->next = NULL;

    return new_node;
}

void reverseBatsmen(struct Node** head_ref2)
{
    struct Node* prev   = NULL;
    struct Node* current = *head_ref2;
    struct Node* next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
       prev = current;
        current = next;
    }
    *head_ref2 = prev;
}

void reverseBowlers(struct Node1** head_ref3)
{
    struct Node1* prev   = NULL;
    struct Node1* current = *head_ref3;
    struct Node1* next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *head_ref3 = prev;
}

void printBatsmenList(struct Node* head)
{
    struct Node* temp = head;
    printf("---------------------------");
    printf("\nJersey No.\tRuns Scored");
    printf("\n---------------------------\n");
    while (temp != NULL) 
    {
        printf("%d\t\t\t", temp->playerNo);
        printf("%d ", temp->runs);
        printf("\n");
        temp = temp->next;
    }
}

void printBowlersList(struct Node1* head)
{
    struct Node1* temp = head;
    printf("---------------------------");
    printf("\nJersey No.\tWickets Taken");
    printf("\n---------------------------\n");
    while (temp != NULL) 
    {
        printf("%d\t\t\t", temp->playerNo);
        printf("%d ", temp->wickets);
       printf("\n");
        temp = temp->next;
    }
}

int main()
{   int n,p=0,q=0;
    int n1;
    int ch=0;
    struct Node* head = NULL;
    struct Node1* head1 = NULL;
    while(ch<5)
    {
        printf("Choose from the following:\n1.Add runs scored by Batsman\n2.Add wickets taken by Bowler\n3.Batsmen Leaderboard\n4.Bowlers Leaderboard\n5.Exit\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("Enter jersey no. of player \n");
                    scanf("%d",&n1);
                    printf("Enter runs scored by batsmen no. \n");
                    scanf("%d",&n);
                    struct Node* new_node = newNode(n,n1);
                    BatsmenSortedInsert(&head, new_node); 
                    break;
                    
            case 2: printf("Enter jersey no. of player \n");
                    scanf("%d",&n1);
                    printf("Enter wickets taken by bowler no. \n");
                    scanf("%d",&n);
                    struct Node1* new_node1 = newNode1(n,n1);
                    BowlersSortedInsert(&head1, new_node1); 
                    break;
            
            case 3:reverseBatsmen(&head);
                    printBatsmenList(head); break;
            
            case 4: reverseBowlers(&head1);
                    printBowlersList(head1); break;
            
            case 5: break;
        }
    }
    return 0;
}