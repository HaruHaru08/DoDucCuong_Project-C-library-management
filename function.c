#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

//Khai bao logic ham
void choose(){
	system("cls");
	printf("***Library Management System Using C***\n\n");
	printf("           CHOOSE YOUR ROLE\n");
	printf("      ==========================\n");
	printf("      [1] Book Management\n");
	printf("      [2] Customer Management\n");
	printf("      [0] Exit the Program\n");
    printf("      ==========================\n");
}
void login(){
	system("cls");
	char email[50];
	char password[100];
	char adminEmail[] = "admin123@gmail.com";
	char adminPassword[] = "admin2508@";
    do{
		printf("***Library Management System Using C***\n\n");
		printf("                LOGIN\n");
		printf("      ==========================\n");
		printf("      Email(admin123@gmail.com): ");
		scanf("%s",&email);
		getchar();
		printf("      Password(admin2508@): ");
		scanf("%s",&password);
		printf("      ==========================\n");
		if(strcmp(email,"admin123@gmail.com")!=0||strcmp(password,"admin2508@")!=0){
			system("cls");
		    printf("Email or Password is wrong\n");
		}else{
			break;
		}
	}while(1);
}
void menuBook(){	
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
void memberMenu() {
	system("cls");
    printf("=========================================\n");
    printf("               Member Menu               \n");
    printf("=========================================\n");
    printf("1. Hien thi danh sach khach hang\n");
    printf("2. Them khach hang\n");
    printf("3. Sua thong tin khach hang\n");
    printf("4. Tim kiem khach hang theo ten\n");
    printf("5. Quay lai menu chinh\n");
    printf("=========================================\n");
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
int isValidInteger(int *num) {
    if (scanf("%d", num) != 1) {
        while (getchar() != '\n');
        return 0;
    }
    return 1;
}
int isValidFloat(float *num) {
    if (scanf("%f", num) != 1) {
        while (getchar() != '\n');
        return 0;
    }
    return 1;
}
int isDuplicateID(struct Book book[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (book[i].bookId == id) {
            return 1;
        }
    }
    return 0;
}
void addBook(struct Book book[],  int *n){
	system("cls");
	int addIndex;
	printf("\t\t**** Add A New Book ****\n");
	do {
        printf("Enter The ID: ");
        if (scanf("%d", &addIndex) != 1) {
            printf("Invalid ID\n");
            while (getchar() != '\n');
            continue;
        }
        if (addIndex < 1 || addIndex > *n + 1) {
            printf("Invalid ID\n");
        } else if (isDuplicateID(book, *n, addIndex)) {
            printf("This ID is already exists\n");
        } else {
            break;
        }
    } while (1);
    for (int i = *n; i >= addIndex; i--) {
        book[i] = book[i - 1];
    }
    book[addIndex - 1].bookId = addIndex;
    do {
        getchar();
        printf("Moi ban nhap ten sach: ");
        fgets(book[addIndex - 1].title, 30, stdin);
        book[addIndex - 1].title[strcspn(book[addIndex - 1].title, "\n")] = '\0';
        if (isEmpty(book[addIndex - 1].title)) {
            printf("Ten sach khong duoc de trong! Vui long nhap lai di a!\n");
        } else if (isDuplicase(book, *n, book[addIndex - 1].title)) {
            printf("Ten sach da ton tai! Hay nhap lai di a!\n");
        } else if (strlen(book[addIndex - 1].title) > 30) {
            printf("Ten sach vuot so ki tu cho phep! Hay nhap lai di a!\n");
        } else {
            break;
        }
    } while (1);
    do {
        printf("Moi ban nhap vao ten tac gia: ");
        fgets(book[addIndex - 1].author, 20, stdin);
        book[addIndex - 1].author[strcspn(book[addIndex - 1].author, "\n")] = '\0';
        if (isEmpty(book[addIndex - 1].author)) {
            printf("Ten tac gia khong duoc de trong! Hay nhap lai di a!\n");
        } else if (strlen(book[addIndex - 1].author) > 20) {
            printf("Ten tac gia vuot so ki tu cho phep! Hay nhap lai di a!\n");
        } else {
            break;
        }
    } while (1);
    do {
        printf("Moi ban nhap so luong sach: "); 
        if (!isValidInteger(&book[addIndex - 1].quantity) || book[addIndex - 1].quantity < 0) {
            printf("So luong sach khong hop le!");
        while (getchar() != '\n');
        } else {
            break;
        }
    } while (1);
    do {
        printf("Moi ban nhap gia tien: ");
        if (!isValidFloat(&book[addIndex - 1].price) || book[addIndex - 1].price < 0) {
            printf("Gia tien khong hop le!");
        while (getchar() != '\n');
        } else {
            break;
        }
    } while (1);
    printf("Moi ban nhap vao thoi gian xuat ban: \n");
    while (book[addIndex - 1].publication.day < 1 || book[addIndex - 1].publication.day > 31) {
        printf("Ngay: ");
        scanf("%d", &book[addIndex - 1].publication.day);
    }
    while (book[addIndex - 1].publication.month < 1 || book[addIndex - 1].publication.month > 12) {
        printf("Thang: ");
        scanf("%d", &book[addIndex - 1].publication.month);
    }
    printf("Nam: ");
    scanf("%d", &book[addIndex - 1].publication.year);
    (*n)++;
    printf("Them sach thanh cong!\n");
}
void updateBook(struct Book book[], int n){
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
	do {
        getchar();
        printf("Moi ban nhap ten sach: ");
        fgets(book[ position].title, 30, stdin);
        book[ position].title[strcspn(book[position].title, "\n")] = '\0';
        if (isEmpty(book[ position].title)) {
            printf("Ten sach khong duoc de trong! Vui long nhap lai di a!");
        } else if (isDuplicase(book, n, book[ position].title)) {
            printf("Ten sach da ton tai! Hay nhap lai di a!\n");
        } else if (strlen(book[ position].title) > 30) {
            printf("Ten sach vuot so ki tu cho phep! Hay nhap lai di a!\n");
        } else {
            break;
        }
    } while (1);
    do {
        printf("Moi ban nhap vao ten tac gia: ");
        fgets(book[ position].author, 20, stdin);
        book[ position].author[strcspn(book[ position].author, "\n")] = '\0';
        if (isEmpty(book[ position].author)) {
            printf("Ten tac gia khong duoc de trong! Hay nhap lai di a!\n");
        } else if (strlen(book[position].author) > 20) {
            printf("Ten tac gia vuot so ki tu cho phep! Hay nhap lai di a!\n");
        } else {
            break;
        }
    } while (1);
    do {
        printf("Moi ban nhap so luong sach: "); 
        if (!isValidInteger(&book[ position].quantity) || book[ position].quantity < 0) {
            printf("So luong sach khong hop le!");
        while (getchar() != '\n');
        } else {
            break;
        }
    } while (1);
    do {
        printf("Moi ban nhap gia tien: ");
        if (!isValidFloat(&book[ position].price) || book[ position].price < 0) {
            printf("Gia tien khong hop le!");
        while (getchar() != '\n');
        } else {
            break;
        }
    } while (1);
    printf("Moi ban nhap vao thoi gian xuat ban: \n");
    while (book[ position].publication.day < 1 || book[ position].publication.day > 31) {
        printf("Ngay: ");
        scanf("%d", &book[ position].publication.day);
    }
    while (book[ position].publication.month < 1 || book[ position].publication.month > 12) {
        printf("Thang: ");
        scanf("%d", &book[ position].publication.month);
    }
    printf("Nam: ");
    scanf("%d", &book[ position].publication.year);
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
 printf("\t******************************************\n");
    printf("\t*************** Book List ****************\n");
    printf("\t******************************************\n");
    printf("|============|===========================|======================|============|============|=================|\n");
    printf("|   BookID   |           Name            |        AUTHOR        |  QUANTITY  |    PRICE   |   PUBLICATION   |\n");
    printf("|============|===========================|======================|============|============|=================|\n");
	for(int i = 0; i < n; i++) { 
		if(strstr(book[i].title, search) != NULL) { 
			check=1; 
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
	if(check==0) { 
		printf("Book not found!\n"); 
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
void saveBooksToFile(struct Book book[], int n) {
    FILE *ptr = fopen("BookList.bin", "wb");
    if (ptr == NULL) {
        printf("Khong the mo file\n");
        return;
    }
    fwrite(book, sizeof(struct Book), n, ptr);
    printf("Luu tru du lieu thanh cong\n");
    fclose(ptr);
}
void loadBooksFromFile(struct Book book[], int *n) {
    FILE *ptr = fopen("BookList.bin", "rb");
    if (ptr == NULL) {
        printf("Khong the mo file\n");
        return;
    }
    *n = fread(book, sizeof(struct Book), 100, ptr);
    if (*n <= 0) {
        printf("Khong co du lieu trong file\n");
        fclose(ptr);
        return;
    }
    system("cls");
    printf("\t******************************************\n");
    printf("\t*************** Book List ****************\n");
    printf("\t******************************************\n");
    printf("|============|===========================|======================|============|============|=================|\n");
    printf("|   BookID   |           Name            |        AUTHOR        |  QUANTITY  |    PRICE   |   PUBLICATION   |\n");
    printf("|============|===========================|======================|============|============|=================|\n");
    for (int i = 0; i < *n; i++) {
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

    printf("Lay thong tin thanh cong\n");
    fclose(ptr);
}
void saveAdminToFile(struct Admin *admin) {
    FILE *file = fopen("admin.bin", "wb");
    if (file == NULL) {
        printf("Khong the mo file để luu du lieu admin.\n");
        return;
    }

    fwrite(admin, sizeof(struct Admin), 1, file);
    fclose(file);
    printf("Luu thong tin admin vao file thanh cong!\n");
}
void displayMembers(struct member members[],int totalMembers) {
	system("cls");
    printf("\t******************************************\n");
    printf("\t*************** Member List ****************\n");
    printf("\t******************************************\n");
    printf("|============|===========================|======================|============|\n");
    printf("| Member ID  |           Name            |       Phone       	|   Status   |\n");
    printf("|============|===========================|======================|============|\n");
    for (int i = 0; i < totalMembers; i++) {
        printf("| %-10s | %-25s | %-20s | %-10s |\n", 
              members[i].memberId, 
			  members[i].name, 
			  members[i].phone, 
			  members[i].status ? "Active" : "Locked");
        printf("|------------|---------------------------|----------------------|------------|\n");
    }
}
void addMember(struct member members[],int *totalMembers) {
	system("cls");
    if (*totalMembers >= 100) {
        printf("Cannot add member, list is full!\n");
        return;
    }
    struct member newMember;
    printf("Enter Member ID: ");
    getchar();
    fgets(newMember.memberId, sizeof(newMember.memberId), stdin);
    newMember.memberId[strcspn(newMember.memberId, "\n")] = 0;
    for (int i = 0; i < *totalMembers; i++) {
        if (strcmp(members[i].memberId, newMember.memberId) == 0) {
            printf("ID already exists!\n");
            return;
        }
    }
    printf("Enter name: ");
    fgets(newMember.name, sizeof(newMember.name), stdin);
    newMember.name[strcspn(newMember.name, "\n")] = 0;
    printf("Enter phone number: ");
    fgets(newMember.phone, sizeof(newMember.phone), stdin);
    newMember.phone[strcspn(newMember.phone, "\n")] = 0;
    newMember.status = 0;
    newMember.borrowedCount = 0;
    members[*totalMembers] = newMember;
    (*totalMembers)++;
    printf("Member added successfully!\n");
}
void editMember(struct member members[],int totalMembers) {
    char memberId[10];
    printf("Enter the Member ID to edit: ");
    fgets(memberId, sizeof(memberId), stdin);
    memberId[strcspn(memberId, "\n")] = 0;
    for (int i = 0; i < totalMembers; i++) {
        if (strcmp(members[i].memberId, memberId) == 0) {
            printf("Current information:\n");
            printf("Name: %s, Phone: %s, Status: %s\n",
                   members[i].name,
                   members[i].phone,
                   members[i].status ? "Locked" : "Unlocked");
            printf("Enter new name: ");
            fgets(members[i].name, sizeof(members[i].name), stdin);
            members[i].name[strcspn(members[i].name, "\n")] = 0;

            printf("Enter new phone number: ");
            fgets(members[i].phone, sizeof(members[i].phone), stdin);
            members[i].phone[strcspn(members[i].phone, "\n")] = 0;

            printf("Member information updated successfully!\n");
            return;
        }
    }
    printf("Member with the entered ID was not found!\n");
}
void searchMemberByName(struct member members[],int totalMembers) {
	system("cls");
    char name[20];
    printf("Enter the name to search: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;
    int found = 0;
    printf("\t******************************************\n");
    printf("\t*************** Member List ****************\n");
    printf("\t******************************************\n");
    printf("|============|===========================|======================|============|==========|\n");
    printf("| Member ID  |           Name            |       Phone       	|   Status   | Borrowed |\n");
    printf("|============|===========================|======================|============|==========|\n");
    for (int i = 0; i < totalMembers; i++) {
    	if (strstr(members[i].name, name) != NULL) {
	        printf("| %-10s | %-25s | %-20s | %-10s | %-10d |\n", 
	              members[i].memberId, 
				  members[i].name, 
				  members[i].phone, 
				  members[i].status ? "Active" : "Locked",
				  members[i].borrowedCount);
			found=1;
		}
        printf("|------------|---------------------------|----------------------|------------|\n");
    }
    if (found==0) {
        printf("No members found with the name '%s'.\n", name);
    }
}
void saveMemberToFile(struct member members[],int totalMembers) {
    FILE *file = fopen("memberList.bin", "wb");
    if (file == NULL) {
        printf("Error opening file for saving.\n");
        return;
    } 
    fwrite(members, sizeof(struct member),totalMembers, file);  
    fclose(file);
    printf("Data saved to file successfully.\n");
}
void loadMemberFromFile(struct member members[],int *totalMembers) {
    FILE *file = fopen("memberList.bin", "rb");
    if (file == NULL) {
        printf("No existing data file found.\n");
        return;
    } 
    *totalMembers=fread(members, sizeof(struct member), 100, file);
    if (*totalMembers <= 0) {
        printf("Khong co du lieu trong file\n");
        fclose(file);
        return;
    }
    system("cls");
    printf("\t******************************************\n");
    printf("\t*************** Member List ****************\n");
    printf("\t******************************************\n");
    printf("|============|===========================|======================|============|\n");
    printf("| Member ID  |           Name            |       Phone       	|   Status   |\n");
    printf("|============|===========================|======================|============|\n");
    for (int i = 0; i < *totalMembers; i++) {
        printf("| %-10s | %-25s | %-20s | %-10s |\n", 
              members[i].memberId, 
			  members[i].name, 
			  members[i].phone, 
			  members[i].status ? "Active" : "Locked");
        printf("|------------|---------------------------|----------------------|------------|\n");
    }
    fclose(file);
    printf("Data loaded from file successfully.\n");
}
