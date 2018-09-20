#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string>
// 한글자씩 더해가면서 띄어쓰기가나오면 다음 단어 숫자세기 (애매)
//숫자 비교해서 제일 큰 단어 반환

void VeryLongWord(char* sen[]) {
	printf("%s\n", *sen);
	char *ptr = strtok(*sen, " ");

	while (ptr != NULL)
	{// while문 하나 더써서 글자수 세고 넘어가기
		printf("%s\n", ptr);
		ptr = strtok(NULL, " ");
	}

}


		


int main() {
	char *name = (char*)malloc(sizeof(char) * 100);
	//char name[100];
	printf("문자열을 입력하세요: ");
	scanf("%[^\n]s", name);
	VeryLongWord(&name);

	

	getchar();
	getchar();
	getchar();
	free(name);
}