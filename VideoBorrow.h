#pragma once
//���� ���� ����ü
typedef struct Video
{
    char genre[10]; //���� �帣
    char title[20]; //���� ����
    int charge; //�뿩��
    int borrow;//�뿩 ����

}video;
//���� ���� ����ü
typedef struct User
{
    char name[20]; //�̸�
    char p_num[12]; //��ȭ��ȣ
    int id; //���� ���� ���̵�
    char borrow_video[20];//���� ������ ��Ÿ��
    int sum; //�뿩��
}user;
//�ݳ� �뿩 ����ü
typedef struct borrow_return
{
    //char name[20]; //�̸�
    int id; //���� ���� ���̵�
    char genre[10]; //���� �帣
    char title[20]; //���� ����
    int charge; //�뿩��
}br;

void print_video(video* v);//���� ������ �ִ� ���� ���
void print_User(user* u, br* b);//���� ������ �� ���� ���� ���
void add_video(video* v);//���� �߰�
void add_User(user* u);//�� �߰�
void borrow_video(video* v, br* b, user* u);//���� �뿩
void return_video(video* v, br* b, user* u);//���� �ݳ�
void search(video* v);//���� �˻�
void save_video(video* v);//���� ����
void save_user(user* u);//���� ����
void save_bandr(br* b);//�ݳ� �뿩 ����
void load_video(video* v);//���� �ҷ�����
void load_user(user* u);//�������� �ҷ�����
void load_bandr(br* b);//�ݳ� �뿩 �ҷ�����