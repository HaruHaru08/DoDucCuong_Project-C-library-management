#include "datatypes.h"

//Khai bao nguyen mau ham
int choose();
void login();
void menu();
void printList(struct Book book[], int n);
char getValidSelection();
char selection();
int getValidIntInput();
int isDuplicase(struct Book books[], int n,const char *title);
int isEmpty(const char *str);
void addBook(struct Book book[],  int *n);
void updateBook(struct Book book[], int n);
void deleteBook(struct Book book[],  int *n);
void search(struct Book book[], int n);
void arrangeDetention(struct Book book[],int n);
void funeralArrangements(struct Book book[],int n);
void menuIncreaseDecrease();