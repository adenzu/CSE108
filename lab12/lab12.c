#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct node_list
{
    int data;
    float number;
    char* name;
    struct node_list *next;
};

/*Do not modify the following function.*/

void insert_end(struct node_list **head, int val, float num, char* name_)
{ 
    struct node_list *newnode = malloc(sizeof(struct node_list));
    newnode->data = val;
    newnode->number = num;
    newnode->name = name_;
    newnode->next = NULL;

    if(*head == NULL)
 		*head = newnode;
    else
    {
        struct node_list *lastnode = *head;

        while(lastnode->next != NULL)
			lastnode = lastnode->next;

        lastnode->next = newnode;
    }
}

/*Do not modify the following function.*/

void print_list(struct node_list *head)
{
	struct node_list *temp = head;

    while(temp != NULL)
    {
		printf("%d->", temp->data);
		printf("%lf->", temp->number);
		printf("%s", temp->name);
		printf("\t");
		temp = temp->next;
    }
    
    printf("NULL\n\n");
}

/*Do not modify the following function.*/

void print_array(struct node_list *array, int sizeof_array)
{
	int i;
	
	for(i=0;i<sizeof_array;i++)
	{
		printf("%d->", (array+i)->data);
    	printf("%lf->", (array+i)->number);
		printf("%s", (array+i)->name);
		printf("\t");
	}
		
    	printf("NULL\n\n");
}

/*You can modify following functions.*/

struct node_list* merge_list(struct node_list* head_1, struct node_list* head_2)
{
	struct node_list *currNode1 = head_1;   // head_1 iterator

    while(currNode1->next)
        currNode1 = currNode1->next;        // get to last node of head_1
    
    currNode1->next = head_2;               // add head_2 to end
    
	return head_1;
}

struct node_list* merge_interleaved(struct node_list* head_1, struct node_list* head_2)
{
	struct node_list *currNode1 = head_1->next; // head_1 node to add to merge
	struct node_list *currNode2 = head_2;       // head_2 node to add to merge
    struct node_list *merged = head_1;          // merged list node

    while(currNode2){                       // until head_2's last node is reached
        
        merged->next = currNode2;           // add head_2 node
        currNode2 = currNode2->next;        // get to next head_2 node so it can be added next iteration

        if(currNode1){                      // if there's next node in head_1, this isn't necessary for head_2 since it's checked in while cond
            merged->next->next = currNode1; // add it to merged list's end
            currNode1 = currNode1->next;    // get to head_1's next node so it can be added next iteration

            merged = merged->next->next;    // get to next node for merging
        }
        /**
         * visualization
         * node 1      .     .     .       
         *             |_---^|_---^|
         * node 2      .     .     .
         * 
         */
    }
        
	return head_1;
}

struct node_list* merge_array(struct node_list* a, int na, struct node_list* b, int nb)
{
    int size = na + nb; // merged array size
	struct node_list *merged = (struct node_list *) calloc(size, sizeof(struct node_list)); // merged array

    int indexA = 0; // index of element of a
    int indexB = 0; // index of element of b
    int index;      // index of element of merged array
    for(index = 0; index < size;){                  // until every element is set in merged array
        if(indexA < na){                            // if end of array a is not reached
            merged[index].data = a[indexA].data;    // copy 
            merged[index].number = a[indexA].number;
            merged[index].name = a[indexA].name;
            merged[index].next = a[indexA].next;
            ++indexA;   // increase array a index
            ++index;    // increase merged array index
        }
        if(indexB < nb){                            // if end of array b is not reached
            merged[index].data = b[indexB].data;    // copy 
            merged[index].number = b[indexB].number;
            merged[index].name = b[indexB].name;
            merged[index].next = b[indexB].next;
            ++indexB;   // increase array b index
            ++index;    // increase merged array index
        }
    }

	return merged;
}


int main()
{
	/*Do not modify anything between 95 and 130 lines.*/
	
	struct node_list *head_1 = NULL;
	struct node_list *head_2 = NULL;
	struct node_list *merged = NULL;
	struct node_list *interleaved = NULL;
	
	insert_end(&head_1,10,1.5,"hello1");
	insert_end(&head_1,30,3.5,"hello3");
	insert_end(&head_1,50,5.5,"hello5");
	 
	insert_end(&head_2,20,2.5,"hello2");
	insert_end(&head_2,40,4.5,"hello4");
	insert_end(&head_2,60,6.5,"hello6");
	
	printf("Print List 1: \n");
	 
	print_list(head_1);
	 
	printf("Print List 2: \n");
	 
	print_list(head_2);
	 
	merged=merge_list(head_1, head_2);
	
	printf("Print List Merged: \n");

    print_list(merged);

    /*---sorry made changes here but otherwise wouldn't work as intended---*/
	struct node_list *head_3 = NULL;        // ADDED THIS LINE
	struct node_list *head_4 = NULL;        // ADDED THIS LINE
	insert_end(&head_3,10,1.5,"hello1");    // ADDED THIS LINE
	insert_end(&head_3,30,3.5,"hello3");    // ADDED THIS LINE
	insert_end(&head_3,50,5.5,"hello5");    // ADDED THIS LINE
	 
	insert_end(&head_4,20,2.5,"hello2");    // ADDED THIS LINE
	insert_end(&head_4,40,4.5,"hello4");    // ADDED THIS LINE
	insert_end(&head_4,60,6.5,"hello6");    // ADDED THIS LINE

	interleaved=merge_interleaved(head_3, head_4);  // CHANGED TO head_3 and head_4
	
	printf("Print List Interleaved: \n");
	
	print_list(interleaved);
 	
 	/*Do not modify anything between 95 and 130 lines.*/    
 	
	/*YOU CAN MODIFY BELOW THIS LINE FOR ONLY PART 3.*/
	
	struct node_list arr1[4];
	struct node_list arr2[3];
	struct node_list *arr3;

    // arr 1
    arr1[0].data = 10;
    arr1[0].number = 1.5;
    arr1[0].name = "arr1_1";
    arr1[0].next = NULL;

    arr1[1].data = 30;
    arr1[1].number = 3.5;
    arr1[1].name = "arr1_3";
    arr1[1].next = NULL;

    arr1[2].data = 50;
    arr1[2].number = 5.5;
    arr1[2].name = "arr1_5";
    arr1[2].next = NULL;

    arr1[3].data = 70;
    arr1[3].number = 7.5;
    arr1[3].name = "arr1_7";
    arr1[3].next = NULL;

    // arr 2
    arr2[0].data = 20;
    arr2[0].number = 2.5;
    arr2[0].name = "arr2_2";
    arr2[0].next = NULL;

    arr2[1].data = 40;
    arr2[1].number = 4.5;
    arr2[1].name = "arr2_4";
    arr2[1].next = NULL;

    arr2[2].data = 60;
    arr2[2].number = 6.5;
    arr2[2].name = "arr2_6";
    arr2[2].next = NULL;
    
	arr3 = merge_array(arr1, 4, arr2, 3);

    // to prove
    for(int i = 0; i < 7; ++i){
		printf("%d->", arr3[i].data);
		printf("%lf->", arr3[i].number);
		printf("%s", arr3[i].name);
		printf("\t");
    }
    printf("\n");
	
	
	
	
	
	
	
	
	return 0;
}
