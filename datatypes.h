#include <stdbool.h>

struct Date{
	int day,month,year;
};
struct Book{
	int bookId;
	char title[30];
	char author[20];
	int quantity;
	float price;
	struct Date publication;
};
struct member{
	char memberId[10];
	char name[20];
	char phone[10];
	bool status;
	struct Book BorrowedBooks[];
};
struct Admin{
	char emailAdmin[50];
	char passwordAdmin[50];
};