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

int insert_list(BookInfo* Bookinfo);

int main()
{
	BookInfo Bookinfo;
	int i;

	for (i = 0; i < BOOK_LIST; i++)
	{
		printf("*********���� ���� �Է�*********\n");
		printf("%d��° ���� ���� �Է�.\n", i + 1);

		printf("���� ���� : ");
		gets_s(Bookinfo.bookTitle, sizeof(Bookinfo.bookTitle));

		printf("���ǻ� �� : ");
		gets_s(Bookinfo.bookPub, sizeof(Bookinfo.bookPub));

		printf("���� ���� : ");
		scanf_s("%d", &Bookinfo.bookPrice);

		getchar(); // ���� ����
		puts("");

		NumOfData = insert_list(&Bookinfo);
		
	}

	for (i = 0; i < BOOK_LIST; i++)
	{
		printf("*********���� ���� ���*********\n");
		printf("%d��° ���� ���� ���.\n", i + 1);

		printf("���� ���� : ");
		fputs(BOOKINFO[i].bookTitle, stdout);
		puts("");

		printf("���ǻ� �� : ");
		fputs(BOOKINFO[i].bookPub, stdout);
		puts("");

		printf("���� ���� : ");
		printf("%d\n", BOOKINFO[i].bookPrice);
		puts("");
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