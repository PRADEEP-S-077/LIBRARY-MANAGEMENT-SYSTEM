#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

// Structure for Book
typedef struct {
    int id;
    char title[100];
    char author[100];
} Book;

Book library[MAX_BOOKS];
int bookCount = 0;

// Function to add a book
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full!\n");
        return;
    }
    printf("Enter Book ID: ");
    scanf("%d", &library[bookCount].id);
    getchar();
    printf("Enter Book Title: ");
    fgets(library[bookCount].title, sizeof(library[bookCount].title), stdin);
    printf("Enter Author: ");
    fgets(library[bookCount].author, sizeof(library[bookCount].author), stdin);
    bookCount++;
    printf("Book added successfully!\n");
}

// Function to display all books
void displayBooks() {
    if (bookCount == 0) {
        printf("No books available!\n");
        return;
    }
    printf("\n--- Library Books ---\n");
    for (int i = 0; i < bookCount; i++) {
        printf("ID: %d\nTitle: %sAuthor: %s\n", library[i].id, library[i].title, library[i].author);
    }
}

// Function to search for a book by ID
void searchBook() {
    int searchId, found = 0;
    printf("Enter Book ID to search: ");
    scanf("%d", &searchId);
    
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == searchId) {
            printf("Book Found:\nID: %d\nTitle: %sAuthor: %s\n", library[i].id, library[i].title, library[i].author);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book not found!\n");
    }
}

// Function to delete a book by ID
void deleteBook() {
    int deleteId, found = 0;
    printf("Enter Book ID to delete: ");
    scanf("%d", &deleteId);
    
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == deleteId) {
            found = 1;
            for (int j = i; j < bookCount - 1; j++) {
                library[j] = library[j + 1];  // Shift books left
            }
            bookCount--;
            printf("Book deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Book ID not found!\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n2. Display Books\n3. Search Book\n4. Delete Book\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: deleteBook(); break;
            case 5: return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}
