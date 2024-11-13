#include <stdio.h>
#include "VideoBorrow.h"

int main()
{
	video* v;
	user* u;
	br* b;
	v = (video*)malloc(sizeof(video) * 10);
	u = (user*)malloc(sizeof(user) * 10);
	b = (br*)malloc(sizeof(br) * 20);
	

	while (1) {
		printf("------------------------------\n");
		printf("1.�� �߰�\n");
		printf("2.���� �߰�\n");
		printf("3.���� ���� ���\n");
		printf("4.���� ���� ���\n");
		printf("5.���� �뿩\n");
		printf("6.���� �ݳ�\n");
		printf("7.���� �˻�\n");
		printf("8.���� �ҷ�����\n");
		printf("9.����\n");
		printf("------------------------------\n");

		int num1 = 0;
		scanf("%d", &num1);
		switch (num1)
		{
		case 1:
			add_User(u);
			break;
		case 2:
			add_video(v);
			break;
		case 3:
			print_User(u,b);
			break;
		case 4:
			print_video(v);
			break;
		case 5:
			borrow_video(v,b,u);
			break;
		case 6:
			return_video(v,b,u);
			break;
		case 7:
			search(v);//���� �˻�
			break;
		case 8:
			load_user(u);
			load_video(v);
			load_bandr(b);
			break;
		default:
			printf("���α׷��� �����մϴ�");
			free(v);
			free(u);
			free(b);
			return 0;
		}
	}
}