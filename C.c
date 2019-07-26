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

int insert_list(BookInfo* Bookinfo);

int main()
{
	BookInfo Bookinfo;
	int i;

	for (i = 0; i < BOOK_LIST; i++)
	{
		printf("*********도서 정보 입력*********\n");
		printf("%d번째 도서 정보 입력.\n", i + 1);

		printf("도서 제목 : ");
		gets_s(Bookinfo.bookTitle, sizeof(Bookinfo.bookTitle));

		printf("출판사 명 : ");
		gets_s(Bookinfo.bookPub, sizeof(Bookinfo.bookPub));

		printf("도서 가격 : ");
		scanf_s("%d", &Bookinfo.bookPrice);

		getchar(); // 버퍼 제거
		puts("");

		NumOfData = insert_list(&Bookinfo);
		
	}

	for (i = 0; i < BOOK_LIST; i++)
	{
		printf("*********도서 정보 출력*********\n");
		printf("%d번째 도서 정보 출력.\n", i + 1);

		printf("도서 제목 : ");
		fputs(BOOKINFO[i].bookTitle, stdout);
		puts("");

		printf("출판사 명 : ");
		fputs(BOOKINFO[i].bookPub, stdout);
		puts("");

		printf("도서 가격 : ");
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

	for (i = NumOfData; i > InputIdx; i--) // shift하는 구간
	{
		BOOKINFO[i] = BOOKINFO[i - 1];
	}

	BOOKINFO[InputIdx] = (*Bookinfo); // 데이터 입력

	NumOfData++;

	return NumOfData;
}