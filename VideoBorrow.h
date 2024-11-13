#pragma once
//비디오 정보 구조체
typedef struct Video
{
    char genre[10]; //비디오 장르
    char title[20]; //비디오 제목
    int charge; //대여료
    int borrow;//대여 여부

}video;
//유저 정보 구조체
typedef struct User
{
    char name[20]; //이름
    char p_num[12]; //전화번호
    int id; //유저 고유 아이디
    char borrow_video[20];//빌린 비디오를 나타냄
    int sum; //대여료
}user;
//반납 대여 구조체
typedef struct borrow_return
{
    //char name[20]; //이름
    int id; //유저 고유 아이디
    char genre[10]; //비디오 장르
    char title[20]; //비디오 제목
    int charge; //대여료
}br;

void print_video(video* v);//현재 가지고 있는 비디오 출력
void print_User(user* u, br* b);//현재 데이터 내 유저 정보 출력
void add_video(video* v);//비디오 추가
void add_User(user* u);//고객 추가
void borrow_video(video* v, br* b, user* u);//비디오 대여
void return_video(video* v, br* b, user* u);//비디오 반납
void search(video* v);//비디오 검색
void save_video(video* v);//비디오 저장
void save_user(user* u);//비디오 저장
void save_bandr(br* b);//반납 대여 저장
void load_video(video* v);//비디오 불러오기
void load_user(user* u);//유저정보 불러오기
void load_bandr(br* b);//반납 대여 불러오기