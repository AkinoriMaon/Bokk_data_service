// Visual Studio���� �ۼ��� �ڵ��Դϴ�.

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
		printf("*********���� ���� ���*********\n\n");

		printf("���Ĺ�� ����...\n");
		printf("%d. ���� ���� �� %d. ���ǻ� �� %d. ���� �� %d. ����\n", 1, 2, 3, 4);
		scanf_s("%d", &menu);
		getchar(); // ���� ����

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
				printf("���μ����� �����մϴ�.\n");
				return 0;
			default:
				printf("�޴��� �߸� �����ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n\n");
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

	for (i = NumOfData; i > InputIdx; i--) // shift�ϴ� ����
	{
		BOOKINFO[i] = BOOKINFO[i - 1];
	}

	BOOKINFO[InputIdx] = (*Bookinfo); // ������ �Է�

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
		printf("*********���� ���� �Է�*********\n\n");

		printf("%d��° ���� ���� �Է�.\n", i + 1);

		printf("���� ���� : ");
		gets_s(Bookinfo->bookTitle, sizeof((*Bookinfo).bookTitle));

		printf("���ǻ� �� : ");
		gets_s(Bookinfo->bookPub, sizeof((*Bookinfo).bookPub));

		printf("���� ���� : ");
		scanf_s("%d", &Bookinfo->bookPrice);

		getchar(); // ���� ����
		puts("");

		NumOfData = insert_list(Bookinfo);
	}
}

void book_data_output()
{
	int i;

	for (i = 0; i < BOOK_LIST; i++)
	{
		//printf("*********���� ���� ���*********\n");
		printf("%d��° ���� ���� ���.\n", i + 1);

		printf("���� ���� : ");
		fputs(PtrBook[i]->bookTitle, stdout);
		puts("");

		printf("���ǻ� �� : ");
		fputs(PtrBook[i]->bookPub, stdout);
		puts("");

		printf("���� ���� : ");
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