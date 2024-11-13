#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "VideoBorrow.h"

int people_n = 0;//사람 수 카운트

int video_n = 0;//비디오 개수 카운트

int add_count = 0;//비디오가 있는지 없는지 확인하는 변수

int bandr_n = 0;//반납 대여 확인 변수

void print_video(video* v)//현재 가지고 있는 비디오 출력
{

    for (int i = 0; i < video_n; i++) {
        printf("제목: %s\t", v[i].title);//비디오 v 포인터 내의 title 출력
        printf("장르: %s\t", v[i].genre);//비디오 v 포인터 내의 genre 출력
        printf("대여료: %d\t", v[i].charge);//비디오 v 포인터 내의 charge 출력 
        if (v[i].borrow == 0) { printf("대여가능\n"); }//borrow 인수가 0이면 대여가능 1이면 대여불가능 출력
        else { printf("대여불가능\n"); }

    }
}
void print_User(user* u, br* b)//현재 데이터 내 유저 정보 출력
{
    int pp_im;// 유저 확인 변수
    int user_id_sample;//유저 아이디를 받을 변수
    printf("전체 유저 출력 = 0, 개인별 정보 출력 =1\n");
    scanf("%d", &pp_im);
    if (pp_im == 0) {//전체 유저 출력
        for (int i = 0; i < people_n; i++) 
        {
            printf("이름 :%s\n", u[i].name);
            printf("전화번호 :%s\n", u[i].p_num);
            printf("유저아이디 :%d\n", u[i].id);
            printf("--------------------\n");
        }
    }
    if (pp_im == 1) {//개인별 유저 출력
        printf("유저아이디를 입력해주세요\n");
        scanf("%d", &user_id_sample);
        for (int i = 0; i < people_n; i++) {
            if (user_id_sample == u[i].id) {//받은 유저 아이디가 u라는 유저포인터 내의 숫자와 동일할때 밑의 printf출력
                printf("이름 :%s\n", u[i].name);
                printf("빌린비디오: %s\n", u[i].borrow_video);
                printf("빌린 비디오 가격 %d\n", u[i].sum);
            }
        }
    }
}

void add_video(video* v)//비디오 추가
{
    
    printf("제목 입력\n");
    scanf("%s", v[video_n].title);
    printf("장르 종류\n");
    scanf("%s", v[video_n].genre);
    printf("대여료\n");
    scanf("%d", &v[video_n].charge);
    printf("-------------------\n");
    v[video_n].borrow = 0;//대여가 가능하다는 걸 알려주는 변수
   
   
    video_n++;
    add_count = 1;//비디오가 하나라도 추가될 시 카운트가 올라감
    save_video(v);//비디오 정보를 추가 시 바로 저장한다.
}

void add_User(user* u)//고객 추가
{
    printf("고객 정보를 입력해주세요\n");
    printf("------------------------\n");
    printf("이름 입력\n");
    scanf("%s", u[people_n].name);//user구조체의 name에 저장.
    printf("전화번호 입력\n");
    scanf("%s", u[people_n].p_num);
    printf("유저 아이디 입력(숫자로 입력해주세요)\n");
    scanf("%d", &u[people_n].id);
    printf("고객 추가가 완료되었습니다\n");    
    
    people_n++;
    printf("%d\n", people_n);
    
    save_user(u);//고객 정보 저장
}

void borrow_video(video* v, br* b, user* u)//비디오 대여
{
    int personal_id;//유저 아이디 변수
    char y_n[5];//yes or no
   
    u->sum = 0;//초반 유저포인터 내의 sum변수를 0으로 지정
    char borrow_video[10];//대여할 비디오 제목
    if (add_count != 0) {//비디오 카운트가 0이 아니라면 if문 수행
        for (int i = 0; i < video_n; i++) {
            if (v[i].borrow == 0) {//대여가 가능한 0을 가진 인수만 출력
                printf("제목: %s\n", v[i].title);
                printf("장르: %s\n", v[i].genre);
                printf("대여료: %d\n", v[i].charge);
                printf("---------------------------\n");
            }
        }
        printf("대여할 비디오 제목을 입력하세요\n");
        scanf("%s", &borrow_video);
        for (int i = 0; i < video_n; i++) {
            if (strcmp(v[i].title, borrow_video) == 0) { //v[i].title,borrow_video 이 둘이 같으면 0 출력
                v[i].borrow = 1;//빌린 여부의 확인을 위해 대여 시 1로 변환
                strcpy(b[i].title, v[i].title);//b[i].title 안에 v[i].title를 복사
                strcpy(b[i].genre, v[i].genre);//b[i].genre 안에 v[i].genre를 복사
                b[i].charge = v[i].charge;//b[i].charge 안에 v[i].charge를 넣음

                printf("고객 정보를 입력해주세요\n");
                printf("------------------------\n");
                printf("기존 고객이신가요?(yes 또는 no 로 대답해주세요)\n");
                scanf("%s", y_n);//기존 고객인지 아닌지의 여부 확인.
                if (strcmp(y_n,"yes")==0) 
                {
                    //printf("%d\n", people_n);
                    printf("유저 아이디 입력(숫자로 입력해주세요)\n");
                    scanf("%d", &personal_id);
                    for (int j = 0; j < people_n; j++) {
                        if (personal_id == u[j].id) {//personal_id 가 u[j].id와 같다면 if문 수행
                            strcpy(u[j].borrow_video, v[i].title);//user구조체 내의 borrow_video에 v[i].title로 복사
                            u[j].sum = v[i].charge;//u[j].sum 에 v[i].charge를 넣음
                            printf("대여가 완료됐습니다\n");
                            save_video(v); //비디오 저장 
                            save_user(u); //유저 저장
                            
                            save_bandr(b);//반납 대여 저장
                            //bandr_n++;
                            //tof = 1;
                        }
                    }

                }
                if(strcmp(y_n, "no") == 0)
                {
                    add_User(u);//유저 추가 함수
                    strcpy(u[people_n - 1].borrow_video, borrow_video);// people_n-1은 직전의 데이터 위치
                    u[people_n - 1].sum = v[i].charge;//마지막 대여료 데이터 저장
                    printf("대여가 완료됐습니다\n");
                    save_video(v);//비디오 저장
                    save_user(u);//유저 저장
                    
                    save_bandr(b);//반납 대여 저장
                    //bandr_n++;
                    break;
                }
             
            }
        }
    }
    else {
        printf("빌릴 수 있는 비디오가 없습니다.\n");
        return 0;
    }
}

void return_video(video* v, br* b, user* u)//비디오 반납
{
    char return_video[10];//반납할 비디오 제목
    int user_id_sample;
    if (add_count != 0) {//비디오가 한개라도 있을 시 시행
        printf("유저아이디를 입력해주세요\n");
        scanf("%d", &user_id_sample);
        for (int i = 0; i < people_n; i++) {
            if (user_id_sample == u[i].id) {
                printf("빌린비디오: %s \n", u[i].borrow_video);
                printf("---------------------------------\n");
                printf("반납할 비디오 제목을 입력해주세요\n");
                scanf(" %s", return_video);
                for (int i = 0; i < video_n; i++) {
                    if (strcmp(v[i].title, return_video) == 0) {
                        v[i].borrow = 0;//반납을 했기에 1이었다 다시 0으로 변환
                        //strcpy(v[i].title, b[i].title);
                        //strcpy(v[i].genre, b[i].genre);
                        strcpy(b[i].title, "\0");//반납을 했기에 빌린 데이터를 0으로 전환
                        strcpy(b[i].genre, "\0");
                        //strset(u[i].borrow_video, "\0");
                        //v[i].charge = b[i].charge;
                        for (int j = 0; j < people_n; j++) {//인덱스 맞추기 위함
                            if (user_id_sample == u[j].id) {
                                strcpy(u[j].borrow_video, "없음");
                                u[j].sum = 0;
                                printf("반납이 완료됐습니다\n");
                                save_video(v);//반납이 완료된 상태를 저장.
                                save_user(u);
                            }
                        }
                    }
                }
            }
            
            
        }
        
    }
    else {
        printf("반납 할 수 있는 비디오가 없습니다.\n");
        return 0;
    }
}

void search(video* v)//비디오 검색
{
    int tof = 0;
    char search_video_title[10];
    printf("검색할 제목을 입력해주세요\n");
    scanf("%s", search_video_title);
    for (int i = 0; i < video_n; i++) {

        if (strcmp(search_video_title, v[i].title) == 0) {
            printf("--------------------------\n");
            printf("제목은 %s 입니다\n", v[i].title);
            printf("장르는 %s 입니다\n", v[i].genre);
            if (v[i].borrow == 0) { printf("대여가능\n"); }
            else { printf("대여불가능\n"); }
            printf("--------------------------\n");
            tof = 1;
            break;
        }
    }
    if (tof == 0)
    {
        printf("다시입력\n");
    }
}

void save_video(video* v)//비디오 저장
{
    int i;
    FILE* fp1;

    fp1 = fopen("SaveFile_video.txt", "w");
    if (fp1 == NULL) {
        printf("생성 실패\n");
    }
   /* else {
        printf("생성 완료\n");
    }*/
    for (i = 0; i < video_n; i++) {
        fprintf(fp1, "%s %s %d %d\n", v[i].title, v[i].genre, v[i].charge,v[i].borrow);
        

    }
    fclose(fp1);
}

void save_user(user* u)//유저 저장
{
    int i;
    FILE* fp2;

    fp2 = fopen("SaveFile_user.txt", "w");
    if (fp2 == NULL) {
        printf("생성 실패\n");
    }
    /*else {
        printf("생성 완료\n");
    }*/
  
   
    for (i = 0; i < people_n; i++) {
       
       fprintf(fp2, "%s %s %d %s %d\n", u[i].name, u[i].p_num, u[i].id, u[i].borrow_video,u[i].sum);
       
       

    }
    fclose(fp2);
}
void save_bandr(br* b)//반납 대여 정보 저장
{
    int i;
    FILE* fp2;

    fp2 = fopen("SaveFile_bandr.txt", "w");
    if (fp2 == NULL) {
        printf("생성 실패\n");
    }
    /*else {
        printf("생성 완료\n");
    }*/

    
    for (i = 0; i < bandr_n; i++) {

        fprintf(fp2, "%s %s %d\n", b[i].title, b[i].genre, b[i].charge);
      


    }
    fclose(fp2);
}

void load_video(video* v)//비디오 불러오기
{
    int i;
    FILE* fp1;
    
    fp1 = fopen("SaveFile_video.txt", "r");
    if (fp1 == NULL) {
        printf("불러오기 실패\n");
    }
    /*else {
        printf("불러오기 완료\n");
    }*/

    while (!feof(fp1)) {
        fscanf(fp1, "%s %s %d %d\n", v[video_n].title, v[video_n].genre, &v[video_n].charge, &v[video_n].borrow);
        
        
        video_n++;//텍스트 내 데이터가 있는 만큼 늘림.
        add_count = 1;//나중에 불러올때 정보가 있다고 인식하기 위해
        
    }

    fclose(fp1);
}
void load_user(user* u)//유저 불러오기
{
    int i;
    FILE* fp2;
    
    fp2 = fopen("SaveFile_user.txt", "r");
    if (fp2 == NULL) {
        printf("불러오기 실패\n");
    }
    /*else {
        printf("불러오기 완료\n");
    }*/

    while (!feof(fp2)) {
        fscanf(fp2, "%s %s %d %s %d\n", u[people_n].name, u[people_n].p_num, &u[people_n].id,u[people_n].borrow_video,&u[people_n].sum);
        
        
        people_n++;//텍스트 내 데이터가 있는 만큼 늘림.

    }
    
    fclose(fp2);
}
void load_bandr(br* b)//반납 대여 정보 불러오기
{
    int i;
    FILE* fp3;

    fp3 = fopen("SaveFile_bandr.txt", "r");
    if (fp3 == NULL) {
        printf("불러오기 실패\n");
    }
    else {
        printf("불러오기 완료\n");
    }

    while (!feof(fp3)) {
        fscanf(fp3, "%s %s %d\n", b[bandr_n].title, b[bandr_n].genre, &b[bandr_n].charge);
       

        bandr_n++;//텍스트 내 데이터가 있는 만큼 늘림.

    }

    fclose(fp3);
}