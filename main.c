#include <stdio.h>
#include <stdlib.h>
#include "function.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
//	struct Book books[50]={
//	{1, "De Men Phieu Luu Ky", "To Hoai",100, 5.00, {1, 6, 1941}},
//	{2, "Truyen Co Tich Viet Nam", "Nhieu Tac Gia",90, 6.00, {1, 1, 1950}},
//	{3, "Tat Den", "Ngo Tat To",85, 4.50, {1, 1, 1939}},
//	{4, "Que Noi", "Vo Quang",70, 5.50, {1, 1, 1974}},
//    {5, "Dat Rung Phuong Nam", "Doan Gioi",65, 6.50, {1, 1, 1957}},
//    {6, "Doraemon", "Fujiko F.Fujio",60, 3.99, {1, 12, 1969}},
//    {7, "Than Dong Dat Viet", "Le Linh",55, 2.50, {1, 1, 2002}},
//    {8, "Conan - Tham Tu Lung Danh", "Gosho Aoyama",50, 4.50, {1, 1, 1994}},
//    {9, "7 Vien Ngoc Rong", "Akira Toriyama",45, 5.00, {1, 11, 1984}},
//    {10, "One Piece", "Eiichiro Oda",40, 5.00, {22, 7, 1997}},
//	};
//	saveBooksToFile(books,10);
	struct Book books[50];
	struct member members[100];
	struct Admin admin={"admin123@gmail.com","admin2508@"};
	saveAdminToFile(&admin);
	int totalMembers = 0;
	int n=10;
	int choice;
	int choiceMember;
	int choiceMenu;	
	char select;
	int isRunning = 1;
	login();
	while (isRunning) {
        choose();;
        int choice;
		printf("Enter The Choice: ");
		scanf("%d",&choice);
        switch (choice) {
            case 1:
				do{
					menuBook();
					printf("Enter The Choice: ");
					scanf("%d",&choiceMenu);
					switch(choiceMenu){
						case 1:
							loadBooksFromFile(books,&n);
//							printList(books,n);
							getValidSelection(&select);
							if(select== '0'){
								printf("========= Thank You =========\n");
								printf("========= See You Soon =========\n");
									return 1;
							}else if(select== 'b'){
								continue;
							}
							break;
						case 2:
							addBook(books, &n);
							saveBooksToFile(books,n);
							getValidSelection(&select);
							if(select== '0'){
								printf("========= Thank You =========\n");
								printf("========= See You Soon =========\n");
									return 1;
							}else if(select== 'b'){
								continue;
							}
							break;
						case 3:
							updateBook(books,n);
							saveBooksToFile(books,n);
							getValidSelection(&select);
							if(select== '0'){
								
								printf("========= Thank You =========\n");
								printf("========= See You Soon =========\n");
									return 1;
							}else if(select== 'b'){
								continue;
							}
							break;
						case 4:
							deleteBook(books,&n);
							saveBooksToFile(books,n);
							getValidSelection(&select);
							if(select== '0'){
							printf("========= Thank You =========\n");
							printf("========= See You Soon =========\n");
								return 1;
							}else if(select== 'b'){
								continue;
							}
							break;
						case 5:
							search(books,n);
							getValidSelection(&select);
							if(select== '0'){
							printf("========= Thank You =========\n");
							printf("========= See You Soon =========\n");
								return 1;
							}else if(select== 'b'){
								continue;
							}
							break;
						case 6:
							menuIncreaseDecrease();
							printf("Enter The Choice: ");
				    		scanf("%d",&choiceMenu);
				    		if(choice==1){
				    			arrangeDetention(books,n);
							}
							if(choice==2){
								funeralArrangements(books,n);
							}
							getValidSelection(&select);
							if(select== '0'){
							printf("========= Thank You =========\n");
							printf("========= See You Soon =========\n");
								return 1;
							}else if(select== 'b'){
								continue;
							}
							break;
						case 7:
							printf("========= Thank You =========\n");
							printf("========= See You Soon =========\n");
							break;
						default:
							printf("Lua chon khong hop le xin hay nhap lai");
							break;
					}
				}while(choiceMenu!=7);
				break;
			case 2:
				do{
					memberMenu(); 
					printf("Enter The Choice: ");
					scanf("%d",&choiceMember);
					switch(choiceMember){
					case 1:
						displayMembers(members,totalMembers);
						break;
					case 2:
						
						break;
					case 3:
						
						break;
					case 4:
						
						break;
					case 5:
						
						break;
					case 6:
						
						break;
					case 7:
						
						break;
					case 8:
						printf("========= Thank You =========\n");
						printf("========= See You Soon =========\n");
						break;
					default:
						printf("Lua chon khong hop le!");
						break;
					}
				}while(choiceMember!=8);
			case 0:
				isRunning = 0;
				printf("========= Thank You =========\n");
				printf("========= See You Soon =========\n");
				break;
		}
	}			
	return 0;
}