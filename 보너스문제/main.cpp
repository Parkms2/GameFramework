#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string>
// �ѱ��ھ� ���ذ��鼭 ���Ⱑ������ ���� �ܾ� ���ڼ��� (�ָ�)
//���� ���ؼ� ���� ū �ܾ� ��ȯ

void VeryLongWord(char* sen[]) {
	printf("%s\n", *sen);
	char *ptr = strtok(*sen, " ");

	while (ptr != NULL)
	{// while�� �ϳ� ���Ἥ ���ڼ� ���� �Ѿ��
		printf("%s\n", ptr);
		ptr = strtok(NULL, " ");
	}

}


		


int main() {
	char *name = (char*)malloc(sizeof(char) * 100);
	//char name[100];
	printf("���ڿ��� �Է��ϼ���: ");
	scanf("%[^\n]s", name);
	VeryLongWord(&name);

	

	getchar();
	getchar();
	getchar();
	free(name);
}