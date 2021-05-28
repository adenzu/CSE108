#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node
{
    int data;
    float number;
    char* name;
    struct node *next;
};


void insert_end(struct node **head, int val, float num, char* name_)
{
    //create a new node
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->number = num;
    newNode->name = name_;
    newNode->next = NULL;

    //if head is NULL, it is an empty list
    if(*head == NULL)
         *head = newNode;
    //Otherwise, find the last node and add the newNode
    else
    {
        struct node *lastNode = *head;

        //last node's next address will be NULL.
        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }

        //add the newNode at the end of the linked list
        lastNode->next = newNode;
    }

}




/*---helper functions of mine---*/

// Prints given node
void print_node(struct node *n){
    printf("%d->%f->%s", n->data, n->number, n->name);
    if(n->next) 
        printf(","); 
}

// Returns lower of given char
char lower_char(char c){
    if(c < 'a')         // If it's before 'a' then it's uppercase
        return c + 32;  // 'A' + 32 == 'a'
    return c;
}

// Returns 1 if w2 is after w1 (in dictionary ordering case), 0 otherwise
int is_after(const char *w1, const char *w2){
    int charIndex;  // Character index
    char l1, l2;    // Lower chars
    for(charIndex = 0; w1[charIndex] && w2[charIndex]; ++charIndex){    // As long as neither word is all checked
        l1 = lower_char(w1[charIndex]);  // Get lower
        l2 = lower_char(w2[charIndex]);  // Get lower
        
        if(l1 < l2)         // If given first word's current character comes before
            return 1;       // then given second word is after
        else if(l1 > l2)    // If given first word's current character comes after
            return 0;       // then given second word is before
                            // If they are the same character
                            // continue
    }
    // Here can only be reached if all checked characters are the same
    // there's only one remaining condition for w2 to be after, that is
    // w1 being exempted of some of last characters of w2 so '\0' of w1
    // should be reached if that's the case, if it's so return 1, 0 otherwise
    return !w1[charIndex];
}





// Prints linked list with loop
void printList_withLoop(struct node *head)
{
    struct node *currNode = head;           // Iterator variable
    
    while(currNode){                // Until the very last node
        print_node(currNode); printf("\n"); // Print node
        currNode = currNode->next;          // Get to next node
    }

}

// Prints linked list with recursion
void printList_withRecursive(struct node *list) {
    // I don't think it is possible to print '[' without any other helper function or parameter 
    if(list){
        printf("%d->%f->%s", list->data, list->number, list->name); // Print node
        if(list->next)                                              // If there's a next node 
            printf(", ");                                           // Print ", " 
        printList_withRecursive(list->next);                        // Get to next node
    }
    else 
        printf("]");   
}


// Inserts given node with its name in alphabetical order
void sortedInsert(struct node** head_ref, struct node* new_node)
{
    struct node *currNode = *head_ref;                      // Iterator variable
    
    if(is_after(new_node->name, currNode->name)){           // If new node's name coms first
        free(new_node->next);                               // Free new node's next, if there's any
        new_node->next = currNode;                          // Set its next to head
        *head_ref = new_node;                               // Set head to new node
        return;                                             
    }
    
    // If doesn't come before the head, then iterate through the list
    while(currNode->next){                          // Untill last node is reached
        if(is_after(new_node->name, currNode->next->name)){ // Check if next node comes after given node or not
            free(new_node->next);                           // If so free new node's next, if there's any
            new_node->next = currNode->next;                // Set its next to current node's next
            currNode->next = new_node;                      // Set current node's next to given node
            return;
        }
        currNode = currNode->next;                          // Get to next node
    }

    currNode->next = new_node;                              // Last node is reached, next node shall be given node
}
 
 
/* A utility function to create a new node */
struct node* newNode(int new_data, float num, char* name_)
{
    struct node *nNode = (struct node *) malloc(sizeof(struct node));   // Allocate

    // Set properties
    nNode->data = new_data; 
    nNode->number = num;
    nNode->name = name_;
    nNode->next = NULL;

    // Return
    return nNode;
}


// Searches given linked list by given integer
bool search(struct node* head, int x)
{
    struct node *currNode = head;   // Iterator variable

    while(currNode){        // Until the end is reached
        if(currNode->data == x)     // Check if data and given integer are identical
            return currNode;        // Return current node if so
        currNode = currNode->next;  // Get to next node
    }

    return NULL;                    // Return NULL since given integer couldnt be found
}

int main()
{
     struct node *head = NULL;

     insert_end(&head,10,5.5,"hello1");
     insert_end(&head,20,5.5,"hello2");
     insert_end(&head,30,5.5,"hello3");

     printf("Print List with Loop: \n");
     printList_withLoop(head);
     
     struct node* new_node = newNode(1,5.5, "a");
     sortedInsert(&head, new_node);

     
     new_node = newNode(3,5.5, "c");
     sortedInsert(&head, new_node);

     
     new_node = newNode(2,5.5, "d");
     sortedInsert(&head, new_node);
     
     new_node = newNode(2,5.5, "b");
     sortedInsert(&head, new_node);
     
     printf("Print List with Recursive: \n");
     printList_withRecursive(head);
	 
	 printf("\nIs 20 belong this linked list?: " );
     printf(search(head, 20) ? "YES \n" : "NO \n");
     
     printf("\nIs 18 belong this linked list?: " );
     printf(search(head, 18) ? "YES \n" : "NO \n");


     return 0;
}