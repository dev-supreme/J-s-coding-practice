//
//  main.c
//  daily_Practice2
//
//  Created by Jay on 2018. 10. 21..
//  Copyright © 2018년 Jay. All rights reserved.
//
//  나중에 연결 리스트로도 구현.
//  영화 데이터베이스 관리 프로그램.
//
//  1. 영화 정보를 입력받아 파일에 저장한다.
//  2. 영화 정보로는 제목, 장르, 개봉연도, 감독, 주연 등이 있다.
//  3. 영화 정보에 대해서 추가, 검색, 수정, 삭제가 가능해야 한다.
//  4. 영화에 대해 다수가 평점을 부여할 수 있다.
//  5. 영화 정보 출력시 평균 평점을 보여준다.
//  프로그램 실행시 메뉴를 출력하고 메뉴에 따라 영화 정보를 추가, 검색, 수정, 삭제, 평점부여를 수행한다.
//  모든 데이터는 파일에 저장되도록 구현한다.
//  이번 목표: 장르 처리 비트연산자로 전부 변경해서 장르 중복 입력 가능하게,


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAIN_ACTOR_COUNT 3
#define MOVIE_INFO_ARRAY_SIZE 10
#define RATING_INFO_ARRAY_SIZE 10


typedef struct movieRating
{
    char ID[8];
    int ratings;
    
}movieRating;

typedef struct movieInfo
{
    char title[20];
    char director[20];
    char mainActor[MAIN_ACTOR_COUNT][20];
//    char mainActor[20];
    int year;
    int enumGenre;
    
    movieRating ratingInfo[RATING_INFO_ARRAY_SIZE];

}movieInfo;


// 추가할때는 반드시 문자열과 enum을 같이 추가할 것.
enum genre
{
    genre_None      = 0,
    genre_Drama     = 1,
    genre_Romance   = 2,
    genre_Action    = 4,
    genre_Thriller  = 8,
    genre_Fantasy   = 16,
    genre_Comedy    = 32,
    genre_Musical   = 64,
    genre_Sports    = 128,
    genre_Adventure = 256,
    genre_SF        = 512
};
const int GENRE_COUNT = 11;
const char STRING_GENRE[GENRE_COUNT][12] = {"Drama", "Romance", "Action", "Thriller", "Fantasy", "Comedy", "Musical", "Sports", "Adventure", "SF"};

//룩업 테이블
const int INT_GENRE[GENRE_COUNT] = { genre_None, genre_Drama, genre_Romance, genre_Action, genre_Thriller, genre_Fantasy, genre_Comedy, genre_Musical, genre_Sports, genre_Adventure, genre_SF };






enum menu_enum
{
    menu_Finish,
    menu_Input,
    menu_Search,
    menu_Edit,
    menu_Rating,
    menu_Delete,
    menu_Show,
    menu_Count
};
const char sMenu[menu_Count][8] = {"Finish", "Input", "Search", "Edit", "Rating", "Delete", "Show"};

void inputMovies(movieInfo*);
movieInfo* searchMovies(movieInfo*);
void editMovies(void);
void showMovies(movieInfo*);
void deleteMovies(void);
void rateMovies(void);
int movieGenreManager(int);


int main(int argc, const char * argv[]) {
    
    movieInfo movieInfoArray[MOVIE_INFO_ARRAY_SIZE];
    
    int menu = 0;
    
//    // 토크나이즈 기법.
//    char buff[1024] = "1 2 5";
//    char* savePoint;
//    char* temp = strtok_r(buff, " ", &savePoint);
//    while (temp)
//    {
//        temp = strtok_r(NULL, " ", &savePoint);
//    }
    
    
    printf("영화 데이터베이스 관리 프로그램 시작. \n");
    
    while (1)
    {
        menu = 0;
        printf("메뉴 선택. \n\n");
        for (int i = 1; i < menu_Count; i++)
        {
            printf("%d. %s \n", i, sMenu[i]);
        }
        printf("%d. %s \n\n", 0, sMenu[0]);
        scanf("%d", &menu);

        switch (menu)
        {
            case menu_Finish:   // 종료.
                printf("%d. %s \n\n", menu, sMenu[menu]);
                printf("프로그램 종료. \n");
                return 0;
                break;
            
            case menu_Input:    // 영화 정보 초기 입력.
                printf("%d. %s \n\n", menu, sMenu[menu]);
                inputMovies(movieInfoArray);
                break;
               
            case menu_Search:   // 검색.
                printf("%d. %s \n\n", menu, sMenu[menu]);
                searchMovies(movieInfoArray);
                break;
                
            case menu_Edit:     // 수정.
                printf("%d. %s \n\n", menu, sMenu[menu]);
                break;
                
            case menu_Rating:   // 평점 매기기.
                printf("%d. %s \n\n", menu, sMenu[menu]);
                break;
                
            case menu_Delete:   // 삭제.
                printf("%d. %s \n\n", menu, sMenu[menu]);
                break;
                
            case menu_Show:     // 보여주기. 전체 프로그램이 완성되면 주석처리.
                printf("%d. %s \n\n", menu, sMenu[menu]);
                showMovies(movieInfoArray);
                break;
                
            default:
                printf("그런 메뉴 없음. \n\n");
                break;
        }
    }
    
    return 0;
}

int movieGenreManager(int genre)
{
    int genreData = genre_None;
    
    genreData = genre;
    
    
    
    
    
    
    
    return genreData;
}


void inputMovies(movieInfo* movieInfoArray)
{
    printf("영화 정보 입력. \n");
    
    // 스트링에 띄어쓰기도 받을 수 있게 수정.
    printf("제목을 입력하세요. \n");
//    gets(movieInfoArray->title);
    scanf("%s", movieInfoArray->title);
    printf("영화 감독 이름을 입력하세요. \n");
//    gets(movieInfoArray->director);
    scanf("%s", movieInfoArray->director);
    printf("주연 배우 이름을 입력하세요. 최대 세명까지 가능합니다. \n");
//    gets(movieInfoArray->mainActor);    // 나중에 3명 이상 입력받을 수 있게 수정.
    
    for (int i = 0; i < MAIN_ACTOR_COUNT; i++)
    {
        scanf("%s", movieInfoArray->mainActor[i]);
    }
    printf("개봉 연도를 입력하세요. \n");
    scanf("%d", &movieInfoArray->year);
    
    while (1)
    {
        int nGenre = 0;
        
        printf("영화 장르의 번호를 입력하세요. \n");
        for (int i = 1; i < GENRE_COUNT; i++)
        {
            printf("%d. %s \n", i, STRING_GENRE[i]);
        }
        
        
        
        
        scanf("%d", &nGenre);
        printf("\n");

        if ( nGenre >= 0 || nGenre <= GENRE_COUNT )
        {
            
            break;
        }
        else
        {
            printf("지정된 범위를 벗어난 값입니다. 다시 선택해 주세요. \n");
            continue;
        }
    }
    
    printf("영화 정보 입력 종료.\n");
    printf("\n");
}


void showMovies(movieInfo* movieInfoArray)
{
    printf("제목: %s \n", movieInfoArray->title);
    printf("감독: %s \n", movieInfoArray->director);
    printf("주연 배우: ");
    for (int i = 0; i < MAIN_ACTOR_COUNT; i++)
    {
        printf("%s ", movieInfoArray->mainActor[i]);
    }
    printf("\n");
    printf("개봉 연도: %d \n", movieInfoArray->year);
//    printf("장르: %d. %s \n", movieInfoArray->enumGenre, sGenre[movieInfoArray->enumGenre]);
//    for (int i = 0; i < RATING_INFO_ARRAY_SIZE; i++)
//    {
//        if ( !*(movieInfoArray->ratingInfo->ID) )
//        {
//            break;
//        }
//        else
//        {
//            printf("%s: %d", movieInfoArray->ratingInfo->ID, movieInfoArray->ratingInfo->ratings);
//        }
//    }
    printf("영화 정보 보여주기 완료. \n");
    printf("\n");
}

movieInfo* searchMovies(movieInfo* movieInfoArray)
{
    char titleSearch[20];
    
    printf("찾으시는 영화 제목을 입력해주세요.\n");
    scanf("%s", titleSearch);
    
    for (int i = 0; i < MOVIE_INFO_ARRAY_SIZE; i++)
    {
        if(strstr((movieInfoArray + i)->title, titleSearch))
        {
            showMovies(movieInfoArray + i);
            return (movieInfoArray + i);
        }
    }
    printf("그런 제목의 영화가 발견되지 않았습니다. \n");
    return NULL;
}

