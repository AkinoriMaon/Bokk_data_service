// Visual Studio에서 작성된 코드입니다.

#include <stdio.h>
#include <string.h>

#define STR_LEN 40
#define BOOK_LIST 3

typedef struct _BookInfo
{
	char bookTitle[STR_LEN];
	char bookPub[STR_LEN];
	int bookPrice;
}BookInfo;

int NumOfData = 0;
BookInfo BOOKINFO[BOOK_LIST];
BookInfo* PtrBook[BOOK_LIST];

enum{SORT_TITLE = 1, SORT_PUB, SORT_PRICE, EXIT};

int insert_list(BookInfo* Bookinfo);
void InitList();

void book_data_input(BookInfo* Bookinfo);
void book_data_output();

void SortByPub();
void SortByPrice();

int main()
{
	BookInfo Bookinfo;
	int i, menu;

	book_data_input(&Bookinfo);
	InitList();
	system("cls");

	while (1)
	{
		printf("*********도서 정보 출력*********\n\n");

		printf("정렬방식 선택...\n");
		printf("%d. 도서 제목 순 %d. 출판사 순 %d. 가격 순 %d. 종료\n", 1, 2, 3, 4);
		scanf_s("%d", &menu);
		getchar(); // 버퍼 제거

		switch (menu)
		{
			case SORT_TITLE:
				book_data_output();
				break;
			case SORT_PUB:
				SortByPub();
				book_data_output();
				break;
			case SORT_PRICE:
				SortByPrice();
				book_data_output();
				break;
			case EXIT:
				printf("프로세스를 종료합니다.\n");
				return 0;
			default:
				printf("메뉴를 잘못 선택하셨습니다. 다시 입력해주세요.\n\n");
				break;
		}

		system("pause");
		system("cls");
	}

	return 1;
}

int insert_list(BookInfo* Bookinfo)
{
	int InputIdx = NumOfData, i = 0;

	for (i = 0; i < NumOfData; i++)
	{
		if (strcmp(BOOKINFO[i].bookTitle, (*Bookinfo).bookTitle) > 0)
		{
			InputIdx = i;
			break;
		}
	}

	for (i = NumOfData; i > InputIdx; i--) // shift하는 구간
	{
		BOOKINFO[i] = BOOKINFO[i - 1];
	}

	BOOKINFO[InputIdx] = (*Bookinfo); // 데이터 입력

	NumOfData++;

	return NumOfData;
}

void InitList()
{
	int i;

	for (i = 0; i < BOOK_LIST; i++)
	{
		PtrBook[i] = &BOOKINFO[i];
	}
}

void book_data_input(BookInfo* Bookinfo)
{
	int i;

	for (i = 0; i < BOOK_LIST; i++)
	{
		printf("*********도서 정보 입력*********\n\n");

		printf("%d번째 도서 정보 입력.\n", i + 1);

		printf("도서 제목 : ");
		gets_s(Bookinfo->bookTitle, sizeof((*Bookinfo).bookTitle));

		printf("출판사 명 : ");
		gets_s(Bookinfo->bookPub, sizeof((*Bookinfo).bookPub));

		printf("도서 가격 : ");
		scanf_s("%d", &Bookinfo->bookPrice);

		getchar(); // 버퍼 제거
		puts("");

		NumOfData = insert_list(Bookinfo);
	}
}

void book_data_output()
{
	int i;

	for (i = 0; i < BOOK_LIST; i++)
	{
		//printf("*********도서 정보 출력*********\n");
		printf("%d번째 도서 정보 출력.\n", i + 1);

		printf("도서 제목 : ");
		fputs(PtrBook[i]->bookTitle, stdout);
		puts("");

		printf("출판사 명 : ");
		fputs(PtrBook[i]->bookPub, stdout);
		puts("");

		printf("도서 가격 : ");
		printf("%d\n", PtrBook[i]->bookPrice);
		puts("");
	}
}

void SortByPub()
{
	int i, j;
	BookInfo* temp;

	for (i = 0; i < BOOK_LIST - 1; i++)
	{
		for (j = 0; j < (BOOK_LIST - i) - 1; j++)
		{
			if (strcmp(PtrBook[j]->bookPub, PtrBook[j + 1]->bookPub) > 0)
			{
				temp = PtrBook[j];
				PtrBook[j] = PtrBook[j + 1];
				PtrBook[j + 1] = temp;
			}
		}
	}
}

void SortByPrice()
{
	int i, j;
	BookInfo* temp;

	for (i = 0; i < BOOK_LIST - 1; i++)
	{
		for (j = 0; j < (BOOK_LIST - i) - 1; j++)
		{
			if (PtrBook[j]->bookPrice > PtrBook[j + 1]->bookPrice)
			{
				temp = PtrBook[j];
				PtrBook[j] = PtrBook[j + 1];
				PtrBook[j + 1] = temp;
			}
		}
	}
}