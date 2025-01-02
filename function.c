#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

//Khai bao logic ham
int choose(){
	printf("***Library Management System Using C***\n\n");
	printf("           CHOOSE YOUR ROLE\n");
	printf("      ==========================\n");
	printf("      [1] Admin\n");
	printf("      [2] Customer\n");
	printf("      [0] Exit the Program\n");
    printf("      ==========================\n");
}
void login(){
	system("cls");
	char email[50];
	char password[100];
	printf("***Library Management System Using C***\n\n");
	printf("                LOGIN\n");
	printf("      ==========================\n");
	printf("      Email: ");
	scanf("%s",&email);
	getchar();
	printf("      Password: ");
	scanf("%s",&password);
    printf("      ==========================\n");
    while(strcmp(email,"admin123@gmail.com")!=0||strcmp(password,"admin2508@")!=0){
    	system("cls");
		printf("email hoac mat khau khong dung");
    	printf("      Email: ");
		scanf("%s",&email);
		getchar();
		printf("      Password: ");
		scanf("%s",&password);
	}
}
void menu(){	
	system("cls");
	printf("***Library Management System Using C***\n\n");
	printf("                Menu\n");
	printf("      ==========================\n");
	printf("      [1] Danh sach sach\n");
	printf("      [2] Them sach\n");
	printf("      [3] Sua thong tin sach\n");
	printf("      [4] Xoa sach\n");
	printf("      [5] Tim kiem sach\n");
	printf("      [6] Sap xep sach\n");
	printf("      [7] Thoat\n");
    printf("      ==========================\n");
}
void printList(struct Book book[], int n){
	system("cls");
	printf("\t******************************************\n");
    printf("\t*************** Book List ****************\n");
    printf("\t******************************************\n");
    printf("|============|===========================|======================|============|============|=================|\n");
    printf("|   BookID   |           Name            |        AUTHOR        |  QUANTITY  |    PRICE   |   PUBLICATION   |\n");
    printf("|============|===========================|======================|============|============|=================|\n");
    for (int i = 0; i < n; i++) {
        printf("| %-10d | %-25s | %-20s | %-10d | %-10.2f | %02d/%02d/%04d      |\n", 
               book[i].bookId, 
               book[i].title, 
               book[i].author, 
               book[i].quantity, 
               book[i].price, 
               book[i].publication.day, 
               book[i].publication.month, 
               book[i].publication.year);
        printf("|------------|---------------------------|----------------------|------------|------------|-----------------|\n");
    }

}
char getValidSelection(char *select){
	printf("Go back(b)? or Exit(0)?: ");
    scanf(" %c",select);
    getchar();
    while (*select != '0' && *select != 'b') {
        printf("Lua chon khong hop le!");
        printf("Hay nhap lai di: ");
		scanf("%c",select);
		getchar();
    }
    return *select;
}
char selection(char *rightWrong){
	scanf(" %c",rightWrong);
	while (*rightWrong != 'Y' && *rightWrong != 'N') {
        printf("Lua chon khong hop le!");
        printf("Hay nhap lai di: ");
		scanf(" %c",rightWrong);
    }
}
int isEmpty(const char *str) {
    return str[0] == '\0';
}
int isDuplicase(struct Book book[], int n,const char *title) {
    for (int i = 0; i < n; i++) {
        if (strcmp(book[i].title,title) == 0) {
            return 1;
		}
    }
    return 0;
}
void addBook(struct Book book[],  int *n){
	system("cls");
	int addIndex;
	printf("\t\t**** Add A New Book ****\n");
	printf("Enter The ID: ",*n+1);
	scanf("%d",&addIndex);
	while(addIndex >= 1&&addIndex <= *n) {
        printf("This ID is already exists\n");
        printf("Enter The ID: ",*n+1);
        scanf("%d", &addIndex);
    }
    while(addIndex<1){
    	printf("Invalid ID");
    	printf("Enter The ID: ",*n+1);
        scanf("%d", &addIndex);
	}
	for (int i = *n; i >= addIndex; i--) { 
		book[i] = book[i - 1];	
	}
	book[addIndex-1].bookId=addIndex;
	while(1){
	getchar();
		printf("Moi ban nhap ten sach: ");
		fgets(book[addIndex-1].title, 30, stdin);
		book[addIndex-1].title[strcspn(book[addIndex-1].title, "\n")] = '\0';
		if(isEmpty(book[addIndex-1].title)){
			printf("Ten sach khong duoc de trong!Hay nhap lai di a!\n");
			continue;
		}
		if(isDuplicase(book,*n,book[addIndex-1].title)){
			printf("Ten sach da ton tai!Hay nhap lai di a!\n");
			continue;
		}
		if(strlen(book[addIndex-1].title)>30){
			printf("Ten sach vuot so ki tu cho phep!Hay nhap lai di a!\n");
			continue;
		}
		break;
	}
	while(1){
	printf("Moi ban nhap vao ten tac gia: ");
	fgets(book[addIndex-1].author,20, stdin);
	book[addIndex-1].author[strcspn(book[addIndex-1].author, "\n")] = '\0';
	if(isEmpty(book[addIndex-1].author)){
		printf("Ten tac gia khong duoc de trong!Hay nhap lai di a!\n");
		continue;
	}
	if(isDuplicase(book,*n,book[addIndex-1].author)){
		printf("Ten tac gia da ton tai!Hay nhap lai di a!\n");
		continue;
	}
	if(strlen(book[addIndex-1].author)>20){
		printf("Ten tac gia vuot so ki tu cho phep!Hay nhap lai di a!\n");
		continue;
	}
		break;	
	}
	printf("Moi ban nhap so luong sach: ");
	scanf("%d",&book[addIndex-1].quantity);
	getchar();
	printf("Moi ban nhap vao gia tien: ");
	scanf("%f", &book[addIndex-1].price);
	printf("Moi ban nhap vao thoi gian xuat ban: \n");
	printf("Ngay: ");
	scanf(" %d",&book[addIndex-1].publication.day);
	printf("Thang: ");
	scanf(" %d",&book[addIndex-1].publication.month);
	printf("Nam: ");
	scanf(" %d",&book[addIndex-1].publication.year);
	(*n)++;
	printf("Them sach thanh cong!\n");
}
void updateBook(struct Book book[], int n){
	system("cls");
	int position;
	printf("Moi ban nhap vao id muon update: ");
	scanf("%d", &position);
	int findIndex=-1;
	for(int i=0;i<n;i++){
		if(book[i].bookId==position){
			findIndex =i;
			break;
		}
	} 
	while(findIndex==-1){
		printf("Khong tim thay sach de update \n");
		printf("Hay nhap lai id ban muon sua sach: ");
		scanf("%d",&position);
		for(int i=0;i<n;i++){
			if(book[i].bookId==position){
				findIndex =i;
				break;
			}
		} 
	}
	printf(" One Book Found For ID: %d\n\n",book[position-1].bookId);
	printf(" Book Informations\n");
	printf("------------------------\n");
	printf("ID: %d\n",book[position-1].bookId);
	printf("bookName: %s\n",book[position-1].title);
	printf("Author: %s\n",book[position-1].author);
	printf("Quantity: %d\n",book[position-1].quantity);
	printf("Price: %.2f\n",book[position-1].price);
	printf("Publication: %d/%d/%d\n",book[position-1].publication.day,book[position-1].publication.month,book[position-1].publication.year);
	printf("\t\t**** Update The New Book ****\n");
	getchar();
	while(1){
	printf("Moi ban nhap vao ten sach: ");
	fgets(book[findIndex].title, 30, stdin);
	book[findIndex].title[strcspn(book[findIndex].title, "\n")] = '\0';
	if(isEmpty(book[findIndex].title)){
		printf("Ten sach khong duoc de trong!Hay nhap lai di a!\n");
		continue;
		}
	if(isDuplicase(book,n,book[findIndex].title)){
		printf("Ten sach da ton tai!Hay nhap lai di a!\n");
		continue;
		}
	if(strlen(book[findIndex].title)>30){
		printf("Ten sach vuot so ki tu cho phep!Hay nhap lai di a!\n");
		continue;
		}
		break;
	}
	while(1){
	printf("Moi ban nhap vao ten tac gia: ");
	fgets(book[findIndex].author, 20, stdin);
	book[findIndex].author[strcspn(book[findIndex].author, "\n")] = '\0';
	if(isEmpty(book[findIndex].author)){
		printf("Ten tac gia khong duoc de trong!Hay nhap lai di a!\n");
		continue;
		}
	if(isDuplicase(book,n,book[findIndex].author)){
		printf("Ten tac gia da ton tai!Hay nhap lai di a!\n");
		continue;
		}
	if(strlen(book[findIndex].author)>20){
		printf("Ten tac gia vuot so ki tu cho phep!Hay nhap lai di a!\n");
		continue;
		}
		break;	
	}
	printf("Moi ban nhap so luong sach: ");
	getchar();
	scanf("%d",&book[findIndex].quantity);
	getchar();
	printf("Moi ban nhap vao gia tien: ");
	scanf(" %f", &book[findIndex].price);
	printf("Moi ban nhap vao thoi gian xuat ban: \n");
	printf("Ngay: ");
	scanf("%d",&book[findIndex].publication.day);
	printf("Thang: ");
	scanf("%d",&book[findIndex].publication.month);
	printf("Nam: ");
	scanf("%d",&book[findIndex].publication.year);
	printf("Sua thanh cong!\n");
}
void deleteBook(struct Book book[],  int *n){
	system("cls");
	char rightWrong;
	int position;
	printf("\t\t**** Delete a Book ****\n");
	printf("Moi ban nhap vao id muon xoa: ");
	scanf("%d", &position);
	int findIndex=-1;
	for(int i=0;i<*n;i++){
		if(book[i].bookId==position){
			findIndex =i;
			break;
		}
	} 
	if(findIndex==-1){
		printf("Khong tim thay sach de xoa\n");
		return ;
	}else{
	printf(" One Book Found For ID: %d\n\n",book[findIndex].bookId);
	printf(" Book Informations\n");
	printf("------------------------\n");
	printf("ID: %d\n",book[findIndex].bookId);
	printf("bookName: %s\n",book[findIndex].title);
	printf("Author: %s\n",book[findIndex].author);
	printf("Quantity: %d\n",book[findIndex].quantity);
	printf("Price: %.2f\n",book[findIndex].price);
	printf("Publication: %d/%d/%d\n",book[findIndex].publication.day,book[findIndex].publication.month,book[findIndex].publication.year);
	printf("Are you sure want to delete this student?(Y/N): ");
		selection(&rightWrong);
		if (rightWrong == 'Y'){
			for (int i = findIndex; i < *n - 1; i++) {
                book[i] = book[i + 1];
            }
            (*n)--;
			printf("Book Deleted Successfully\n");
		}else{
			printf("Book deletion canceled.\n");
		}
	}
}
void search(struct Book book[], int n){
	system("cls");
	int check=0;
	char search[30];
	printf("\t\t**** Search a Book ****\n");
	printf("Nhap ten cuon sach muon tim: ");
	scanf("%s",&search);
	getchar();
	for(int i=0;i<n;i++){
		if(strcmp(search,book[i].title)==0){
			check=i+1;
		}
	}
	if(check>0){
		printf("\t******************************************\n");
    	printf("\t*************** Book List ****************\n");
   		printf("\t******************************************\n");
    	printf("|============|===========================|======================|============|============|=================|\n");
    	printf("|   BookID   |           Name            |        AUTHOR        |  QUANTITY  |    PRICE   |   PUBLICATION   |\n");
    	printf("|============|===========================|======================|============|============|=================|\n");
    	printf("| %-10d | %-25s | %-20s | %-10d | %-10.2f | %02d/%02d/%04d      |\n", 
               book[check-1].bookId, 
               book[check-1].title, 
               book[check-1].author, 
               book[check-1].quantity, 
               book[check-1].price, 
               book[check-1].publication.day, 
               book[check-1].publication.month, 
               book[check-1].publication.year);
        printf("|------------|---------------------------|----------------------|------------|------------|-----------------|\n");
    }else{
    	printf("Khong tim thay quyen sach muon tim!");
	}
}
void arrangeDetention(struct Book book[],int n){
	system("cls");
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(book[j].price<book[j+1].price){
				struct Book temp=book[j+1];
				book[j+1]=book[j];
				book[j]=temp;
			}
		}			
	}
	printf("Sap xep thanh cong!\n");
}
void funeralArrangements(struct Book book[],int n){
	system("cls");
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(book[j].price>book[j+1].price){
				struct Book temp=book[j];
				book[j]=book[j+1];
				book[j+1]=temp;
			}
		}			
	}
	printf("Sap xep thanh cong!\n");
}
void menuIncreaseDecrease(){
	system("cls");
	printf("\t**** Arrange a Book ****\n");
	printf("                Menu\n");
	printf("      ==========================\n");
	printf("      [1] Sap xep giam dan\n");
	printf("      [2] sap xep tang dan\n");
    printf("      ==========================\n");
}
//void saveBooksToFile(Book book[],int n){
//	FILE *ptr=fopen("Danh Sach.dat","wb");
//	if(ptr==NULL){
//		printf("Khong mo duoc file");
//	}
//	fwrite(book,sizeof(Book),n,ptr);
//	printf("Luu tru du lieu thanh cong");
//	fclose(ptr);
//}
//void loadBooksFromFile(Book book[],int*n){
//	FILE *ptr=fopen("Danh Sach.dat","rb");
//	Book readBook[100];
//	if(ptr==NULL){
//		printf("Khong mo duoc file");
//	}
//	*n=fread(readBook,sizeof(Book),50,ptr);
//	for(int i=0;i<*n;i++){
//		printf("ID: %d\n",book[position-1].bookId);
//		printf("bookName: %s\n",book[position-1].title);
//		printf("Author: %s\n",book[position-1].author);
//		printf("Quantity: %d\n",book[position-1].quantity);
//		printf("Price: %.2f\n",book[position-1].price);
//		printf("Publication: %d/%d/%d\n",book[position-1].publication.day,book[position-1].publication.month,book[position-1].publication.year);
//		}
//	printf("Lay thong tin thanh cong");
//	fclose(ptr);
//}
