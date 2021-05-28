#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// defined constraints
#define BOOK_TITLE_LEN_MAX 100
#define BOOK_AUTHOR_LEN_MAX 50
#define BOOK_SUBJECT_LEN_MAX 100

// book struct
typedef struct book_s{
    char title[BOOK_TITLE_LEN_MAX];
    char author[BOOK_AUTHOR_LEN_MAX];
    char subject[BOOK_SUBJECT_LEN_MAX];
    int year;
    int id;
} Book;


// functions, see implementations
void CopyBook(Book *destination,  Book *source);
void ResizeBookArray(Book **bookArray, int size, int newSize);
void AddBook(Book **bookArray, Book **bookArraySorted, int size);
void AddBookByYear(Book **bookArray, int size, Book *newBook);
Book * GetByTitle(Book *bookArray, int size,  char *title);
Book * GetByAuthor(Book *bookArray, int size,  char *author);
Book * GetBySubject(Book *bookArray, int size,  char *subject);
void PrintBook( Book *book);
void SubMenu( Book *bookArray,  Book *bookArraySorted, int size);



int main(){
    Book *myBooks;          // book array
    Book *myBooksSorted;    // book array sorted by year
    int numberOfBooks = 0;

    int userInput = 0;

    while(userInput != 3){
        printf("MENU\n");
        printf("\t1. Add New Book\n");
        printf("\t2. List Books\n");
        printf("\t3. EXIT\n");
        printf("\n");
        printf("Choose = ");
        scanf("%d", &userInput);

        switch (userInput)
        {
        case 1:
            AddBook(&myBooks, &myBooksSorted, numberOfBooks);
            ++numberOfBooks;
            break;
        case 2:
            SubMenu(myBooks, myBooksSorted, numberOfBooks);
            break;
        case 3:
            break;
        
        default:
            printf("TRY AGAIN.\n");
        }
    }

    return 0;
}


// copies one book info to other
void CopyBook(Book *destination,  Book *source){
    strcpy(destination->title, source->title); 
    strcpy(destination->author, source->author); 
    strcpy(destination->subject, source->subject);
    destination->year = source->year;
    destination->id = source->id; 
}

// resizes book array
void ResizeBookArray(Book **bookArray, int size, int newSize){
    Book *newBookArray = (Book *) calloc(newSize, sizeof(Book));    // create new array
    Book *oldBookArray = *bookArray;                                // old array

    if(newSize > size){
        for(int i = 0; i < size; ++i){
            CopyBook(newBookArray + i, oldBookArray + i);           // copy old books
        }
    }
    else{
        for(int i = 0; i < newSize; ++i){
            CopyBook(newBookArray + i, oldBookArray + i);           // copy old books
        }
    }

    free(oldBookArray);         // delete old books
    *bookArray = newBookArray;  // set to new book array 
}

// binary search to put new book at right index by year
int AddBookYearBinarySearch( Book *bookArray, int l, int r,  Book *newBook){
    int mid = l + (r - l) / 2;

    if(l == r)  // If left and right equal then right index is found
        return r;
    if(bookArray[mid].year > newBook->year) // If lesser
        return AddBookYearBinarySearch(bookArray, l, mid, newBook);
    else                                    // If greater
        return AddBookYearBinarySearch(bookArray, mid + 1, r, newBook);
}

// Get info about book from user and add to book arrays
void AddBook(Book **bookArray, Book **bookArraySorted, int size){
    ResizeBookArray(bookArray, size, size + 1);

    Book *newBook = *bookArray + size;

    printf("Please enter book title = ");
    fflush(stdin);
    scanf("%[^\n]%*c", newBook->title);

    printf("Please enter book author = ");
    fflush(stdin);
    scanf("%[^\n]%*c", newBook->author);

    printf("Please enter book subject = ");
    fflush(stdin);
    scanf("%[^\n]%*c", newBook->subject);

    printf("Please enter book year = ");
    scanf("%d", &newBook->year);

    AddBookByYear(bookArraySorted, size, newBook);
}

// add book by year
void AddBookByYear(Book **bookArray, int size, Book *newBook){
    int index = AddBookYearBinarySearch(*bookArray, 0, size, newBook);  // right index to put the book

    Book *newBookArray = (Book *) calloc(size + 1, sizeof(Book));    // create new array

    ResizeBookArray(bookArray, size, size + 1); // resize array

    int j = 0;
    for(int i = 0; i < size + 1; ++i){
        if(i == index){
            CopyBook(newBookArray + i, newBook);
            j = 1;  // if book is put to right index then next old books shall be put next to it thus j is set to 1
        }
        else{
            CopyBook(newBookArray + i + j, *bookArray + i);   // copy old books
        }
    }
    
    free(*bookArray);
    *bookArray = newBookArray;

}

Book * GetByTitle(Book *bookArray, int size,  char *title){

    for(int i = 0; i < size; ++i)
        if(!strcmp(title, bookArray[i].title))
            return bookArray + i;

    return NULL;
}

Book * GetByAuthor(Book *bookArray, int size,  char *author){

    for(int i = 0; i < size; ++i)
        if(!strcmp(author, bookArray[i].author))
            return bookArray + i;

    return NULL;
}

Book * GetBySubject(Book *bookArray, int size,  char *subject){

    for(int i = 0; i < size; ++i)
        if(!strcmp(subject, bookArray[i].subject))
            return bookArray + i;

    return NULL;
}

void PrintBook( Book *book){
    printf("\n");
    printf("Title => %s\n", book->title);
    printf("Author => %s\n", book->author);
    printf("Subject => %s\n", book->subject);
    printf("Year => %d\n", book->year);
    printf("\n");
}

void SubMenu( Book *bookArray,  Book *bookArraySorted, int size){
    int userInput = 0;
    char userStringInput[200];

    while(userInput != 6){
        printf("SUBMENU\n");
        printf("\t1. Get By Title\n");
        printf("\t2. Get By Author\n");
        printf("\t3. Get By Subject\n");
        printf("\t4. Sorted List By Year (DESC)\n");
        printf("\t5. List All Books\n");
        printf("\t6. EXIT SUBMENU\n");
        printf("\n");
        printf("Choose = ");
        scanf("%d", &userInput);

        switch(userInput){
            case 1:
                printf("Enter a book title = ");
                fflush(stdin);
                scanf("%[^\n]%*c", userStringInput);

                PrintBook(GetByTitle(bookArray, size, userStringInput));
                break;
            case 2:
                printf("Enter a book author = ");
                fflush(stdin);
                scanf("%[^\n]%*c", userStringInput);

                PrintBook(GetByAuthor(bookArray, size, userStringInput));
                break;
            case 3:
                printf("Enter a book subject = ");
                fflush(stdin);
                scanf("%[^\n]%*c", userStringInput);

                PrintBook(GetBySubject(bookArray, size, userStringInput));
                break;
            case 4:
                for(int i = size - 1; i > -1; --i){
                    printf("%d. Book;\n", i + 1);
                    PrintBook(bookArraySorted + i);
                    printf("\n");
                }
                break;
            case 5:
                for(int i = 0; i < size; ++i){
                    printf("%d. Book;\n", i + 1);
                    PrintBook(bookArray + i);
                    printf("\n");
                }
                break;
            case 6:
                break;
            default:
                printf("TRY AGAIN\n");
        }
    }
}