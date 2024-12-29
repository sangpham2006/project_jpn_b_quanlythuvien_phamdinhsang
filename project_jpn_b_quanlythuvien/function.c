#include <stdio.h>
#define MAX_BOOKS 100
#include "datatype.h"

struct Book books[MAX_BOOKS];
int bookCount = 0;


void menu() {
    printf("***Book Management System Using C***\n");
    printf("\n");
    printf("               MENU                     \n");
    printf("      =======================\n");
    printf("      [1] Add A New Book.\n");
    printf("      [2] Show All Books.\n");
    printf("      [3] Search A Book.\n");
    printf("      [4] Edit A Book.\n");
    printf("      [5] Delete A Book.\n");
    printf("      [6] Sort Books by Price.\n");
    printf("      [0] Exit the Program.\n");
    printf("      ==========================\n");
    printf("Enter The Choice: ");
}

//Tiet 1
void displayBooks() {
   
    if (bookCount == 0) {
        printf("There are no books in the list.\n");
        return;
    }

    printf("                         **** All Books ****\n");
    printf("|============|======================|======================|============|============|\n");
    printf("| %-10s | %-20s | %-20s | %-10s | %-10s |\n", "ID", "Title", "Author", "Quantity", "Price");
    printf("|============|======================|======================|============|============|\n");

	int i;  
    for (i = 0; i < bookCount; i++) {
        printf("| %-10s | %-20s | %-20s | %-10d | %-10d |\n", 
               books[i].bookId, 
               books[i].title, 
               books[i].author, 
               books[i].quantity, 
               books[i].price);
      
        printf("|------------|----------------------|----------------------|------------|------------|\n");
    }

    printf("\n");
    char choice;
    do {
        printf("Go back (b)? or Exit (0)?: ");
        scanf(" %c", &choice);
        if (choice == 'b') {
            return; 
        } else if (choice == '0') {
            printf("==========Thank You==========\n");
            printf("==========See You Soon==========\n\n");
            printf("--------------------------------------");
            exit(0); 
        } else {
            printf("Invalid choice. Please enter 'b' or '0'.\n");
        }
    } while (choice != 'b' && choice != '0');
    printf("\n");
    printf("\n");
    printf("\n");
}


//Tiet 4
int isValidDate(int day, int month, int year) {
   
    if (year < 1 || month < 1 || month > 12 || day < 1) {
        return 0;
    }

 
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        daysInMonth[1] = 29; 
    }

    if (day > daysInMonth[month - 1]) {
        return 0;
    }

    return 1;
}


//Tiet 4
int isValidBook(struct Book newBook) {
    if (strlen(newBook.bookId) == 0 || strlen(newBook.title) == 0 || strlen(newBook.author) == 0 || 
	    strlen(newBook.bookId) > 10 || strlen(newBook.title) > 30 || strlen(newBook.author) > 20) {
        printf("Error: Book information cannot be empty.\n");
        return 0;
    }

	if (!isValidDate(newBook.publication.day, newBook.publication.month, newBook.publication.year)) {
	    printf("Error: Invalid publication date (%02d/%02d/%04d).\n", 
	        newBook.publication.day, 
	        newBook.publication.month, 
	        newBook.publication.year);
	    return 0;
    }
    
	int i;
    for (i = 0; i < bookCount; i++) {
        if (strcmp(books[i].bookId, newBook.bookId) == 0) {
            printf("Error: Book ID '%s' already exists.\n", newBook.bookId);
            return 0;
        }
        if (strcmp(books[i].title, newBook.title) == 0) {
            printf("Error: Book Title '%s' already exists.\n", newBook.title);
            return 0;
        }
    }
    return 1;
}

//Tiet 1
void addBook() {
	printf("                         **** Add A New Book ****\n");
    if (bookCount >= MAX_BOOKS) {
        printf("Cannot add book, list is full.\n");
        return;
    }
	
    struct Book newBook;
    do {
	    printf("Enter the Book ID: ");
	    scanf("%s", newBook.bookId);
	    printf("Enter the Title: ");
	    scanf(" %[^\n]%*c", newBook.title);
	    printf("Enter the Author: ");
	    scanf(" %[^\n]%*c", newBook.author);
	    printf("Enter the Quantity: ");
	    scanf("%d", &newBook.quantity);
	    printf("Enter the Price: ");
	    scanf("%d", &newBook.price);
	    printf("Enter the Publication Date (dd mm yyyy): ");
        scanf("%d %d %d", &newBook.publication.day, &newBook.publication.month, &newBook.publication.year);
    } while (!isValidBook(newBook)); 

    books[bookCount] = newBook;
    bookCount++;
	
	printf("\n");
    printf("Book Added Successfully.\n");
    printf("\n");

    char choice;
    do {
        printf("Go back (b)? or Exit (0)?: ");
        scanf(" %c", &choice);
        if (choice == 'b') {
            return; 
        } else if (choice == '0') {
            printf("==========Thank You==========\n");
            printf("==========See You Soon==========\n\n");
            printf("--------------------------------------");
            exit(0); 
        } else {
            printf("Invalid choice. Please enter 'b' or '0'.\n");
        }
    } while (choice != 'b' && choice != '0');
}

//Tiet 2
void editBook() {
    printf("                         **** Edit A Book ****\n");
    char id[10];
    
    printf("Enter the Book ID : ");
    scanf("%s", id);

    int index = -1;
    int i;
    for (i = 0; i < bookCount; i++) {
        if (strcmp(books[i].bookId, id) == 0) {
            index = i;
            break;
        }
    }
    
  

    if (index == -1) {
        printf("Error: Book with ID '%s' not found.\n", id);
        return;
    }
    
    printf("One Book Found for ID: %s\n\n", books[index].bookId);
	printf("Book Information\n");
	printf("------------------------------\n");
	printf("%-15s: %s\n", "ID", books[index].bookId);
	printf("%-15s: %s\n", "Title", books[index].title);
	printf("%-15s: %s\n", "Author", books[index].author);
	printf("%-15s: %d\n", "Quantity", books[index].quantity);
	printf("%-15s: %d\n", "Price", books[index].price);
	printf("%-15s: %02d/%02d/%04d\n\n", "Publication Date", 
	       books[index].publication.day, 
	       books[index].publication.month, 
	       books[index].publication.year);
	printf("------------------------------\n");
	printf("                  ***************Update The New Book *****\n");
	
    char newTitle[30];
    int titleExists = 0;
    do {
        titleExists = 0; 
        printf("Enter the new Title: ");
        scanf(" %[^\n]%*c", newTitle);

       	int i;
        for (i = 0; i < bookCount; i++) {
            if (i != index && strcmp(books[i].title, newTitle) == 0) {
                printf("Error: Book Title '%s' already exists. Please enter a different title.\n", newTitle);
                titleExists = 1;
                break;
            }
        }
    } while (titleExists);

   
    strcpy(books[index].title, newTitle); 
    printf("Enter the Author: ");
    scanf(" %[^\n]%*c", books[index].author);

    printf("Enter the Quantity: ");
    scanf("%d", &books[index].quantity);

    printf("Enter the Price: ");
    scanf("%d", &books[index].price);

    printf("Enter the Publication Date (dd mm yyyy): ");
    scanf("%d %d %d", &books[index].publication.day, &books[index].publication.month, &books[index].publication.year);

    printf("Book Updated successfully.\n");

  
    char choice;
    do {
        printf("Go back (b)? or Exit (0)?: ");
        scanf(" %c", &choice);
        if (choice == 'b') {
            return; 
        } else if (choice == '0') {
            printf("==========Thank You==========\n");
            printf("==========See You Soon==========\n\n");
            printf("--------------------------------------");
            exit(0); 
        } else {
            printf("Invalid choice. Please enter 'b' or '0'.\n");
        }
    } while (choice != 'b' && choice != '0');
}

//Tiet 3
void deleteBook() {
	printf("                         **** Delete A Book ****\n");
    char id[10];
    printf("Enter the Book ID to delete: ");
    scanf("%s", id);

    
    int index = -1;
    int i;
    for (i = 0; i < bookCount; i++) {
        if (strcmp(books[i].bookId, id) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: Book with ID '%s' not found.\n", id);
        return;
    }
    
    printf("One Book Found for ID: %s\n\n", books[index].bookId);
	printf("Book Information\n");
	printf("------------------------------\n");
	printf("%-15s: %s\n", "ID", books[index].bookId);
	printf("%-15s: %s\n", "Title", books[index].title);
	printf("%-15s: %s\n", "Author", books[index].author);
	printf("%-15s: %d\n", "Quantity", books[index].quantity);
	printf("%-15s: %d\n", "Price", books[index].price);
	printf("%-15s: %02d/%02d/%04d\n\n\n", "Publication Date", 
	       books[index].publication.day, 
	       books[index].publication.month, 
	       books[index].publication.year);

  
    printf("Are you sure you want to delete this book? (Y/N): ");
    int confirm;
    scanf(" %c", &confirm);
    if (confirm == 'Y') {
       
        int j;
        for (j = index; j < bookCount - 1; j++) {
            books[j] = books[j + 1];
        }
        bookCount--;
        printf("Book Deleted Successfully.\n");
    } else {
        printf("Book Deletion Cancelled.\n");
    }

    char choice;
    do {
        printf("Go back (b)? or Exit (0)?: ");
        scanf(" %c", &choice);
        if (choice == 'b') {
            return;
        } else if (choice == '0') {
            printf("==========Thank You==========\n");
            printf("==========See You Soon==========\n\n");
            printf("--------------------------------------");
            exit(0); 
        } else {
            printf("Invalid choice. Please enter 'b' or '0'.\n");
        }
    } while (choice != 'b' && choice != '0');
}

//Tiet 3
void sortBooksByPrice() {
    int choice;
    printf("Choose sorting order:\n");
    printf("[1] Ascending (Low to High)\n");
    printf("[2] Descending (High to Low)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

	int i;
    for (i = 0; i < bookCount - 1; i++) {
    	int j;
        for (j = i + 1; j < bookCount; j++) {
            if ((choice == 1 && books[i].price > books[j].price) ||
                (choice == 2 && books[i].price < books[j].price)) {
                struct Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }

    printf("Books sorted successfully.\n");
    displayBooks();
}


//Tiet 4
void searchBookByTitle() {
    char keyword[30];
    printf("Enter the title keyword to search: ");
    scanf(" %[^\n]%*c", keyword);

    int found = 0;
    printf("\nBooks matching '%s':\n", keyword);
    printf("|============|======================|======================|============|============|\n");
    printf("| %-10s | %-20s | %-20s | %-10s | %-10s |\n", "ID", "Title", "Author", "Quantity", "Price");
    printf("|============|======================|======================|============|============|\n");

	int i;
    for (i = 0; i < bookCount; i++) {
        if (strstr(books[i].title, keyword) != NULL) { 
            printf("| %-10s | %-20s | %-20s | %-10d | %-10d |\n",
                   books[i].bookId, books[i].title, books[i].author, books[i].quantity, books[i].price);
            printf("|------------|----------------------|----------------------|------------|------------|\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No books found with the keyword '%s'.\n", keyword);
    }
}


