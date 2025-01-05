#include "datatypes.h"

//Khai bao nguyen mau ham
void choose();
void login();
void menuBook();
void memberMenu();
void printList(struct Book book[], int n);
char getValidSelection();
char selection();
int getValidIntInput();
int isDuplicase(struct Book books[], int n,const char *title);
int isEmpty(const char *str);
int isDuplicateID(struct Book books[], int n, int id);
int isValidInteger(int *num);
int isValidFloat(float *num);
void addBook(struct Book book[],  int *n);
void updateBook(struct Book book[], int n);
void deleteBook(struct Book book[],  int *n);
void search(struct Book book[], int n);
void arrangeDetention(struct Book book[],int n);
void funeralArrangements(struct Book book[],int n);
void menuIncreaseDecrease();
void saveBooksToFile(struct Book book[],int n);
void loadBooksFromFile(struct Book book[],int*n);
void saveAdminToFile();
void loadAdminFromBinaryFile();
void displayMembers(struct member members[],int totalMembers);