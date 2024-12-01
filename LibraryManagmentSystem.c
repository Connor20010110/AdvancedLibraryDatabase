#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// book structur

typedef struct {
    char title[MAX_LENGTH];
    char author[MAX_LENGTH];
    int year;
    float price;
} Book;

Book* collectionTest(Book *collection, int size) {
    Book *newCollection = (Book*)malloc(size * sizeof(Book));
    if (newCollection == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    
    if (collection != NULL) {
        for (int i = 0; i < size; i++) {
            newCollection[i] = collection[i];
        }
        free(collection);
    }
    return newCollection;
}

void displayMenu() {

    printf("\nLibrary Managment System:\n");
    printf("1. Add a Book\n");
    printf("2. View All Books\n");
    printf("3. Remove a Book\n");
    printf("4. Display Library Summary\n");
    printf("5. Exit\n");
}

void addBook(Book **collection, int *count){

    (*count)++;
    *collection = collectionTest(*collection, *count);
    if (*collection == NULL) {
        printf("Failed");
        return;
    }

    printf("Enter the title: ");
    scanf("%s", (*collection)[*count].title);

    printf("Enter the author: ");
    scanf("%s", (*collection)[*count].author);

    printf("Enter the year: ");
    scanf("%d", &(*collection)[*count].year);

    printf("Enter the price: ");
    scanf("%f", &(*collection)[*count].price);

    (count)++;
    printf("Book added sccesfully!\n");

}

void viewBooks(Book *collection, int count) {
    if (count == 0) {
        printf("No books available.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("Book %d: \"%s\" by %s, Published in %d, Price: $%f\n", 
        i + 1, 
        collection[i].title, 
        collection[i].author, 
        collection[i].year, 
        collection[i].price);

        // displays correctly; output is completely wrong
    }
}

void removeBook(Book **collection, int *count)
{
/*
    Prompt the user to enter the index of the book to remove.
    Validate the index (must be between 1 and the total number of books).
    Remove the book from the collection and reallocate memory to shrink the array.
    Display a confirmation message after successful removal.
    If the index is invalid, display an error message
*/
};


void displaySummary(Book *collection, int count)
{
/*
    Show the total number of books in the library.
    Calculate and display the total cost of all books, formatted to two decimal places:
    Total Books: X
    Total Cost: $XX.XX    
*/
};


int main() {

    Book *collection = NULL; // Dynamic array of books
    int count = 0; // Number of books
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(&collection, &count);
                break;
            case 2:
                viewBooks(collection, count);
                break;
            case 3:
                removeBook(&collection, &count);
                break;
            case 4:
                displaySummary(collection, count);
                break;
            case 5:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
                        
    } while (choice != 5);

    // Free allocated memory
    free(collection);

    return 0;
}
