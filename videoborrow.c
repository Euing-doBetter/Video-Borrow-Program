#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "VideoBorrow.h"

int people_n = 0;//��� �� ī��Ʈ

int video_n = 0;//���� ���� ī��Ʈ

int add_count = 0;//������ �ִ��� ������ Ȯ���ϴ� ����

int bandr_n = 0;//�ݳ� �뿩 Ȯ�� ����

void print_video(video* v)//���� ������ �ִ� ���� ���
{

    for (int i = 0; i < video_n; i++) {
        printf("����: %s\t", v[i].title);//���� v ������ ���� title ���
        printf("�帣: %s\t", v[i].genre);//���� v ������ ���� genre ���
        printf("�뿩��: %d\t", v[i].charge);//���� v ������ ���� charge ��� 
        if (v[i].borrow == 0) { printf("�뿩����\n"); }//borrow �μ��� 0�̸� �뿩���� 1�̸� �뿩�Ұ��� ���
        else { printf("�뿩�Ұ���\n"); }

    }
}
void print_User(user* u, br* b)//���� ������ �� ���� ���� ���
{
    int pp_im;// ���� Ȯ�� ����
    int user_id_sample;//���� ���̵� ���� ����
    printf("��ü ���� ��� = 0, ���κ� ���� ��� =1\n");
    scanf("%d", &pp_im);
    if (pp_im == 0) {//��ü ���� ���
        for (int i = 0; i < people_n; i++) 
        {
            printf("�̸� :%s\n", u[i].name);
            printf("��ȭ��ȣ :%s\n", u[i].p_num);
            printf("�������̵� :%d\n", u[i].id);
            printf("--------------------\n");
        }
    }
    if (pp_im == 1) {//���κ� ���� ���
        printf("�������̵� �Է����ּ���\n");
        scanf("%d", &user_id_sample);
        for (int i = 0; i < people_n; i++) {
            if (user_id_sample == u[i].id) {//���� ���� ���̵� u��� ���������� ���� ���ڿ� �����Ҷ� ���� printf���
                printf("�̸� :%s\n", u[i].name);
                printf("��������: %s\n", u[i].borrow_video);
                printf("���� ���� ���� %d\n", u[i].sum);
            }
        }
    }
}

void add_video(video* v)//���� �߰�
{
    
    printf("���� �Է�\n");
    scanf("%s", v[video_n].title);
    printf("�帣 ����\n");
    scanf("%s", v[video_n].genre);
    printf("�뿩��\n");
    scanf("%d", &v[video_n].charge);
    printf("-------------------\n");
    v[video_n].borrow = 0;//�뿩�� �����ϴٴ� �� �˷��ִ� ����
   
   
    video_n++;
    add_count = 1;//������ �ϳ��� �߰��� �� ī��Ʈ�� �ö�
    save_video(v);//���� ������ �߰� �� �ٷ� �����Ѵ�.
}

void add_User(user* u)//�� �߰�
{
    printf("�� ������ �Է����ּ���\n");
    printf("------------------------\n");
    printf("�̸� �Է�\n");
    scanf("%s", u[people_n].name);//user����ü�� name�� ����.
    printf("��ȭ��ȣ �Է�\n");
    scanf("%s", u[people_n].p_num);
    printf("���� ���̵� �Է�(���ڷ� �Է����ּ���)\n");
    scanf("%d", &u[people_n].id);
    printf("�� �߰��� �Ϸ�Ǿ����ϴ�\n");    
    
    people_n++;
    printf("%d\n", people_n);
    
    save_user(u);//�� ���� ����
}

void borrow_video(video* v, br* b, user* u)//���� �뿩
{
    int personal_id;//���� ���̵� ����
    char y_n[5];//yes or no
   
    u->sum = 0;//�ʹ� ���������� ���� sum������ 0���� ����
    char borrow_video[10];//�뿩�� ���� ����
    if (add_count != 0) {//���� ī��Ʈ�� 0�� �ƴ϶�� if�� ����
        for (int i = 0; i < video_n; i++) {
            if (v[i].borrow == 0) {//�뿩�� ������ 0�� ���� �μ��� ���
                printf("����: %s\n", v[i].title);
                printf("�帣: %s\n", v[i].genre);
                printf("�뿩��: %d\n", v[i].charge);
                printf("---------------------------\n");
            }
        }
        printf("�뿩�� ���� ������ �Է��ϼ���\n");
        scanf("%s", &borrow_video);
        for (int i = 0; i < video_n; i++) {
            if (strcmp(v[i].title, borrow_video) == 0) { //v[i].title,borrow_video �� ���� ������ 0 ���
                v[i].borrow = 1;//���� ������ Ȯ���� ���� �뿩 �� 1�� ��ȯ
                strcpy(b[i].title, v[i].title);//b[i].title �ȿ� v[i].title�� ����
                strcpy(b[i].genre, v[i].genre);//b[i].genre �ȿ� v[i].genre�� ����
                b[i].charge = v[i].charge;//b[i].charge �ȿ� v[i].charge�� ����

                printf("�� ������ �Է����ּ���\n");
                printf("------------------------\n");
                printf("���� ���̽Ű���?(yes �Ǵ� no �� ������ּ���)\n");
                scanf("%s", y_n);//���� ������ �ƴ����� ���� Ȯ��.
                if (strcmp(y_n,"yes")==0) 
                {
                    //printf("%d\n", people_n);
                    printf("���� ���̵� �Է�(���ڷ� �Է����ּ���)\n");
                    scanf("%d", &personal_id);
                    for (int j = 0; j < people_n; j++) {
                        if (personal_id == u[j].id) {//personal_id �� u[j].id�� ���ٸ� if�� ����
                            strcpy(u[j].borrow_video, v[i].title);//user����ü ���� borrow_video�� v[i].title�� ����
                            u[j].sum = v[i].charge;//u[j].sum �� v[i].charge�� ����
                            printf("�뿩�� �Ϸ�ƽ��ϴ�\n");
                            save_video(v); //���� ���� 
                            save_user(u); //���� ����
                            
                            save_bandr(b);//�ݳ� �뿩 ����
                            //bandr_n++;
                            //tof = 1;
                        }
                    }

                }
                if(strcmp(y_n, "no") == 0)
                {
                    add_User(u);//���� �߰� �Լ�
                    strcpy(u[people_n - 1].borrow_video, borrow_video);// people_n-1�� ������ ������ ��ġ
                    u[people_n - 1].sum = v[i].charge;//������ �뿩�� ������ ����
                    printf("�뿩�� �Ϸ�ƽ��ϴ�\n");
                    save_video(v);//���� ����
                    save_user(u);//���� ����
                    
                    save_bandr(b);//�ݳ� �뿩 ����
                    //bandr_n++;
                    break;
                }
             
            }
        }
    }
    else {
        printf("���� �� �ִ� ������ �����ϴ�.\n");
        return 0;
    }
}

void return_video(video* v, br* b, user* u)//���� �ݳ�
{
    char return_video[10];//�ݳ��� ���� ����
    int user_id_sample;
    if (add_count != 0) {//������ �Ѱ��� ���� �� ����
        printf("�������̵� �Է����ּ���\n");
        scanf("%d", &user_id_sample);
        for (int i = 0; i < people_n; i++) {
            if (user_id_sample == u[i].id) {
                printf("��������: %s \n", u[i].borrow_video);
                printf("---------------------------------\n");
                printf("�ݳ��� ���� ������ �Է����ּ���\n");
                scanf(" %s", return_video);
                for (int i = 0; i < video_n; i++) {
                    if (strcmp(v[i].title, return_video) == 0) {
                        v[i].borrow = 0;//�ݳ��� �߱⿡ 1�̾��� �ٽ� 0���� ��ȯ
                        //strcpy(v[i].title, b[i].title);
                        //strcpy(v[i].genre, b[i].genre);
                        strcpy(b[i].title, "\0");//�ݳ��� �߱⿡ ���� �����͸� 0���� ��ȯ
                        strcpy(b[i].genre, "\0");
                        //strset(u[i].borrow_video, "\0");
                        //v[i].charge = b[i].charge;
                        for (int j = 0; j < people_n; j++) {//�ε��� ���߱� ����
                            if (user_id_sample == u[j].id) {
                                strcpy(u[j].borrow_video, "����");
                                u[j].sum = 0;
                                printf("�ݳ��� �Ϸ�ƽ��ϴ�\n");
                                save_video(v);//�ݳ��� �Ϸ�� ���¸� ����.
                                save_user(u);
                            }
                        }
                    }
                }
            }
            
            
        }
        
    }
    else {
        printf("�ݳ� �� �� �ִ� ������ �����ϴ�.\n");
        return 0;
    }
}

void search(video* v)//���� �˻�
{
    int tof = 0;
    char search_video_title[10];
    printf("�˻��� ������ �Է����ּ���\n");
    scanf("%s", search_video_title);
    for (int i = 0; i < video_n; i++) {

        if (strcmp(search_video_title, v[i].title) == 0) {
            printf("--------------------------\n");
            printf("������ %s �Դϴ�\n", v[i].title);
            printf("�帣�� %s �Դϴ�\n", v[i].genre);
            if (v[i].borrow == 0) { printf("�뿩����\n"); }
            else { printf("�뿩�Ұ���\n"); }
            printf("--------------------------\n");
            tof = 1;
            break;
        }
    }
    if (tof == 0)
    {
        printf("�ٽ��Է�\n");
    }
}

void save_video(video* v)//���� ����
{
    int i;
    FILE* fp1;

    fp1 = fopen("SaveFile_video.txt", "w");
    if (fp1 == NULL) {
        printf("���� ����\n");
    }
   /* else {
        printf("���� �Ϸ�\n");
    }*/
    for (i = 0; i < video_n; i++) {
        fprintf(fp1, "%s %s %d %d\n", v[i].title, v[i].genre, v[i].charge,v[i].borrow);
        

    }
    fclose(fp1);
}

void save_user(user* u)//���� ����
{
    int i;
    FILE* fp2;

    fp2 = fopen("SaveFile_user.txt", "w");
    if (fp2 == NULL) {
        printf("���� ����\n");
    }
    /*else {
        printf("���� �Ϸ�\n");
    }*/
  
   
    for (i = 0; i < people_n; i++) {
       
       fprintf(fp2, "%s %s %d %s %d\n", u[i].name, u[i].p_num, u[i].id, u[i].borrow_video,u[i].sum);
       
       

    }
    fclose(fp2);
}
void save_bandr(br* b)//�ݳ� �뿩 ���� ����
{
    int i;
    FILE* fp2;

    fp2 = fopen("SaveFile_bandr.txt", "w");
    if (fp2 == NULL) {
        printf("���� ����\n");
    }
    /*else {
        printf("���� �Ϸ�\n");
    }*/

    
    for (i = 0; i < bandr_n; i++) {

        fprintf(fp2, "%s %s %d\n", b[i].title, b[i].genre, b[i].charge);
      


    }
    fclose(fp2);
}

void load_video(video* v)//���� �ҷ�����
{
    int i;
    FILE* fp1;
    
    fp1 = fopen("SaveFile_video.txt", "r");
    if (fp1 == NULL) {
        printf("�ҷ����� ����\n");
    }
    /*else {
        printf("�ҷ����� �Ϸ�\n");
    }*/

    while (!feof(fp1)) {
        fscanf(fp1, "%s %s %d %d\n", v[video_n].title, v[video_n].genre, &v[video_n].charge, &v[video_n].borrow);
        
        
        video_n++;//�ؽ�Ʈ �� �����Ͱ� �ִ� ��ŭ �ø�.
        add_count = 1;//���߿� �ҷ��ö� ������ �ִٰ� �ν��ϱ� ����
        
    }

    fclose(fp1);
}
void load_user(user* u)//���� �ҷ�����
{
    int i;
    FILE* fp2;
    
    fp2 = fopen("SaveFile_user.txt", "r");
    if (fp2 == NULL) {
        printf("�ҷ����� ����\n");
    }
    /*else {
        printf("�ҷ����� �Ϸ�\n");
    }*/

    while (!feof(fp2)) {
        fscanf(fp2, "%s %s %d %s %d\n", u[people_n].name, u[people_n].p_num, &u[people_n].id,u[people_n].borrow_video,&u[people_n].sum);
        
        
        people_n++;//�ؽ�Ʈ �� �����Ͱ� �ִ� ��ŭ �ø�.

    }
    
    fclose(fp2);
}
void load_bandr(br* b)//�ݳ� �뿩 ���� �ҷ�����
{
    int i;
    FILE* fp3;

    fp3 = fopen("SaveFile_bandr.txt", "r");
    if (fp3 == NULL) {
        printf("�ҷ����� ����\n");
    }
    else {
        printf("�ҷ����� �Ϸ�\n");
    }

    while (!feof(fp3)) {
        fscanf(fp3, "%s %s %d\n", b[bandr_n].title, b[bandr_n].genre, &b[bandr_n].charge);
       

        bandr_n++;//�ؽ�Ʈ �� �����Ͱ� �ִ� ��ŭ �ø�.

    }

    fclose(fp3);
}