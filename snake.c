#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
//
#define DEFAULT_X 0
#define DEFAULT_Y 0
//키보드 방향키 정의
#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

#define MAP_SIZE 22
#define WALL 1
#define EMPTY 0
#define HEAD 2
#define TAIL 3
#define FRUIT 5
#define COLLISION 10
//
#define TRUE 1
#define FALSE 0
//
#define NORMAL 10

// 형식 정의

typedef int MData;

// 구조체fruitxy를 만들고Fruitpos로 정의하겠다
typedef struct fruitxy
{
  int x;
  int y;
  int numofFruit;
}Fruitpos;

typedef struct snakexp
{
    int x;
    int y;  
}Snakepos;

//////////////////////queue/////////////////////////
// typedef int QDATA;
typedef struct _mynode
{
  Snakepos data;
  struct _mynode *next;
} node;

typedef struct _myqueue {
  node * rear;
  node * front;
} MYqueue;
// 구조체 정의
typedef MYqueue Queue;

void QueueInit(Queue * pq)
{
  pq->rear = NULL;
  pq->front = NULL;
}
int isEmpty(Queue * pq)
{
  if (pq->front == NULL)
    return TRUE;
    else
    return FALSE;
}
//큐에 데이터 삽입/////////////////////
void Enqueue(Queue * pq, Snakepos data)
{
  node * newnode = (node *)malloc(sizeof(node));
  newnode->next = NULL;
  newnode->data = data;
  if (isEmpty(pq))
  {
    pq->rear = newnode;
    pq->front = newnode;
  }
  else {
    pq->rear->next = newnode;
    pq->rear = newnode;
  }
}
Snakepos Dequeue(Queue * pq)
  {
     node * delnode;
     Snakepos deldata;
     if (isEmpty(pq)){
      return deldata;
     }
     delnode = pq -> front;
     deldata = delnode->data;
     pq->front = pq ->front->next;
     free(delnode);
     return deldata;
  }
  Snakepos peek(Queue * pq)
  {
    return pq->front->data;
  }
  //////////////////////////////////////////////
  //kebord input
  int Getkeydown()
  {
    if (_kbhit()) return _getch( );
    return -1; 
  }
  
//move cursor (커서 : 명령프롬프트떄 깜빡깜빡거린거 글자칠떄 앞에있는거)

void gotoxy(int x, int y)
{
  COORD Pos;
  Pos.X = 2 * x;
  Pos.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
}

void hidecursor()
{
  HANDLE consolehandle = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO info;
}
// show start menu//
int drawstartmenu()
{
  HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hand, 13);
  gotoxy(DEFAULT_X,DEFAULT_Y);
  printf("============================================");
  SetConsoleTextAttribute(hand, 14);
  printf("======snake game======================");
  SetConsoleTextAttribute(hand, 11);
  printf("============================================");
  SetConsoleTextAttribute(hand, 15);
  gotoxy(DEFAULT_X, DEFAULT_Y + 4);
  printf("> key : up down left right");
  gotoxy(DEFAULT_X,DEFAULT_Y+5);
  printf(" > exit : 't'");
  
  gotoxy(DEFAULT_X + 11 , DEFAULT_Y + 14);
  printf("<made by blockdmask.& practice wooseok");
  gotoxy(DEFAULT_X + 11, DEFAULT_Y + 15);
  printf("<kwoos333@naver.com>");

  SetConsoleTextAttribute(hand, 14);
  while (1)
  {
    int keydown = Getkeydown();
    if (keydown == 's' || keydown == 'S')
    {SetConsoleTextAttribute(hand, 7);
    return TRUE;
    }
    if (keydown == 't' || keydown == 'T')
    {SetConsoleTextAttribute(hand, 7);
    return FALSE;
    }
    gotoxy(DEFAULT_X + 5, DEFAULT_Y + 9);
    printf(" -- press 's' or 'S' to start --");
    Sleep(1000/3);
    gotoxy(DEFAULT_X + 5, DEFAULT_Y + 9);
    printf("                                 ");
    Sleep(1000/3);
      }
}
//show stage menu and score ;
int drawspeedmenu(int *scoreArr)
{
  HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);

  int i;
  FILE *rfp , *wfp;
  rfp = fopen("score.txt", "r");
  SetConsoleTextAttribute(hand, 11);
  gotoxy(DEFAULT_X, DEFAULT_Y);
  printf("============================================");
  SetConsoleTextAttribute(hand,14);
  gotoxy(DEFAULT_X, DEFAULT_Y + 1);
  printf("================ BEST SCORE ================");
  SetConsoleTextAttribute(hand, 13);
  gotoxy(DEFAULT_X, DEFAULT_Y + 2);
  printf("============================================");
  SetConsoleTextAttribute(hand, 15);
  if (rfp == NULL)
  { wfp == fopen("score.txt", "w");
    fprintf(wfp, "%d %d %d %d", scoreArr[0], scoreArr[1], scoreArr[2], scoreArr[3]);
    for (i = 0; i < 4 ; i++)
    {
      gotoxy(DEFAULT_X, DEFAULT_Y + (i + 4));
      printf( " stage [%d] : %d", i + 1 , scoreArr[i]);
    }
    fclose(wfp);
  }
  fscanf(rfp, " %d %d %d %d ", &scoreArr[0], &scoreArr[1],&scoreArr[2],&scoreArr[3] );
  for (i = 0 ; i < 4; i++)
  {
    gotoxy(DEFAULT_X, DEFAULT_Y + (i + 4));
    printf(" stage [%d] : %d", i +1 , scoreArr[i]);
  }
  fclose(rfp);

  while(1)
  {
    int keydown = Getkeydown();
    if ( keydown == '1'){
      SetConsoleTextAttribute(hand, 7);
      return 1;
    }
    if ( keydown == '2'){
      SetConsoleTextAttribute(hand, 7);
      return 2;
    }
    if ( keydown == '3'){
      SetConsoleTextAttribute(hand, 7);
      return 3;
    }
    if ( keydown == '4'){
      SetConsoleTextAttribute(hand, 7);
      return 4;
    }
    SetConsoleTextAttribute(hand, 14);
    gotoxy(DEFAULT_X, DEFAULT_Y + 9);
    printf(" >> choose stage : 1, 2, 3, 4 ");
    Sleep(1000 / 3);
    gotoxy(DEFAULT_X, DEFAULT_Y + 9);
    printf("                              ");
    Sleep(1000 / 3);
  }

}

///////////////////////stage map setting//////////
void StageClear(MData map[MAP_SIZE][MAP_SIZE])
{
  int i, j;
  for (i = 0; i<=MAP_SIZE; i++){
    for (j = 0; i <= MAP_SIZE; j++){
        map[i][j] = EMPTY;
    } 
  }
}

void stageOneInit(MData map[MAP_SIZE][MAP_SIZE]) {
    int i, j;
    for (i = 0; i < MAP_SIZE; i++) { 
            for (j = 0; j < MAP_SIZE; j++) {
        if (i == 0 || i == MAP_SIZE - 1 || j == 0 || j == MAP_SIZE - 1)
        {
                map[i][j] = WALL;
            }
        else {
                    map[i][j] = EMPTY;
            }
        }
 
    }
}
//2탄
void stagetwoinit(MData map[MAP_SIZE][MAP_SIZE])
{
  int i, j ;
  for ( i = 0; i < MAP_SIZE; i++){
    for ( j= 0; j < MAP_SIZE; j++){
      if (i == (int)MAP_SIZE / 2 || j == 0 || j == MAP_SIZE - 1)
      {
        map[i][j] = WALL;
      }
      else {
        map[i][j] = EMPTY;
      }
    }
  }
}
//3탄
void stageThreeInit(MData map[MAP_SIZE][MAP_SIZE]) {
    int i, j;
    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            if (i == MAP_SIZE / 2 || j == MAP_SIZE / 2) {
                map[i][j] = WALL;
            }
            else {
                map[i][j] = EMPTY;
            }
        }
    }
}
 //4탄
void stageFourinit(MData map[MAP_SIZE][MAP_SIZE]) {
    int i, j;
    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            if (i == j || i + j == MAP_SIZE - 1) {
                if (i == MAP_SIZE / 2 - 1 || i == MAP_SIZE / 2)
                    map[i][j] = EMPTY;
                else
                    map[i][j] = WALL;
 
            }
            else {
                map[i][j] = EMPTY;
            }
        }
    }
}
 
/////////////////////////////////////////////////////
///////////////////////////////draw//////////////////
// draw game map
void drawmainmap(MData map[MAP_SIZE][MAP_SIZE])
{
  HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hand , 15);
  int i, j;
  for ( i = 0; i < MAP_SIZE; i++)
  {
    for (j = 0 ; j < MAP_SIZE; j++)
    {
      if (map[i][j] == WALL){
        gotoxy(i , j);
        printf("■");
      }
      else if (map[i][j] == EMPTY)
      {
        gotoxy(i, j);
        printf(" ");
      }
    }
  }
  SetConsoleTextAttribute(hand, 7);
}

void drawSubmap(int score, int best , int stage)
{
  HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hand, 15);

  gotoxy(DEFAULT_X, MAP_SIZE + 1);
  printf(" stage[%d] best score : %4d", stage , best);
  gotoxy(DEFAULT_X, MAP_SIZE + 2);
  printf("stage[%d] your score : %4d", stage, score);
  gotoxy(DEFAULT_X + 8 , MAP_SIZE + 5);
  printf("[EXIT - 'T' / Pause - 'p']\n");
  SetConsoleTextAttribute(hand, 7);

}
///////////////////////////////////////////////////
int setFruit(MData map[MAP_SIZE][MAP_SIZE], Fruitpos * fp)
{
  HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);
  int i , j ;
  srand((unsigned int)time(NULL));
  while (1)
  {
    i =rand() % (MAP_SIZE - 2) + 1;
    j =rand() % (MAP_SIZE - 2) + 1;
    if (map[i][j] == EMPTY){
        map[i][j] = FRUIT;
        fp->x = i;
        fp->y = j;
        (fp->numofFruit)++;
        SetConsoleTextAttribute(hand, 10);
        gotoxy(i, j);
        printf("♥");
        SetConsoleTextAttribute(hand, 7);
        return 1;
    }
  }
}

int setBonusfruit(MData map[MAP_SIZE][MAP_SIZE], Fruitpos * fp)
{
  int i , j, numOfFruit = 0;
  for (i=0 ; i < MAP_SIZE -1; i++)
  {
    for (j = 0; j < MAP_SIZE; j++)
    {
      if (map[i][j] == EMPTY){
          map[i][j] = FRUIT;
          numOfFruit++;
      }
    }
  }
  return numOfFruit;
}

void setsnaketail(MData map[MAP_SIZE][MAP_SIZE], int snake_x,int snake_y)
{
  HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hand, 14);
  gotoxy(snake_x, snake_y);
  printf("0");
  map[snake_x][snake_y] = TAIL;
  SetConsoleTextAttribute(hand, 7);
}

void setsnake(MData map[MAP_SIZE][MAP_SIZE], int snake_x, int snake_y)
    { HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);
      gotoxy(snake_x, snake_y);
      SetConsoleTextAttribute(hand, 14);
      printf("o");
      SetConsoleTextAttribute(hand, 7);
      map[snake_x][snake_y] = HEAD;
    }

    void removeSnake(MData map[MAP_SIZE][MAP_SIZE], int snake_x, int snake_y)
    {
      gotoxy(snake_x, snake_y);
      printf(" ");
      map[snake_x][snake_y] = EMPTY;
    }

    int rotate(int xy, int way)
    {
      if (way == UP || way == LEFT){
        if(xy - 1 == -1){
           xy = MAP_SIZE - 1;
        }
        else {
          --(xy);
        }
      return xy;
      }
      if (way == DOWN || way == RIGHT){
        if ( xy + 1 == MAP_SIZE){
          xy = 0;
        }
        else {
          ++xy;
        }
        return xy;
      }
      return FALSE;
    }

int colwithTAIL(MData map[MAP_SIZE][MAP_SIZE], Snakepos * sp, int way)
{
  if (way == UP) 
  {
    if (map[sp->x][rotate(sp->y, way)] == TAIL)
        return TRUE;
  }
  if (way == DOWN) 
  {
    if (map[sp->x][rotate(sp->y, way)] == TAIL)
        return TRUE;
  }
  if (way == LEFT) 
  {
    if (map[rotate(sp->x, way)][sp->y] == TAIL)          
        return TRUE;
  }
  if (way == RIGHT) 
  {
    if (map[rotate(sp->x, way)][sp->y] == TAIL)
        return TRUE;
  }
  return FALSE;
}

int colwithwall(MData map[MAP_SIZE][MAP_SIZE], Snakepos * sp, int way)
{
  if (way == UP){
    if (map[sp->x][rotate(sp->y, way)] == WALL)
        return TRUE;
  }
  if (way == DOWN) {
    if (map[sp->x][rotate(sp->y, way)] == WALL)
      return TRUE;
  }
  if (way == LEFT)
  {
    if (map[rotate(sp->x, way)][sp->y] == WALL)
      return TRUE;
  }
  if (way == RIGHT)
  {
    if (map[rotate(sp->x, way)][sp->y] == WALL)
      return TRUE;
  }
  return FALSE;
}

int Movesnakehead(MData map[MAP_SIZE][MAP_SIZE], Snakepos *snake, int way)
{
  removeSnake(map, snake->x, snake->y);
  if (colwithwall(map, snake, way) == TRUE)
  {
    gotoxy(1, 1);
    printf("hit : wall");
    return COLLISION;
  }
  if(colwithTAIL(map, snake, way) == TRUE)
  {
    gotoxy(1, 1);
    printf("hit : tail");
    return COLLISION;
  }

  if(way == UP)
  {
    if(snake->y - 1 == -1)
    {
      snake->y = MAP_SIZE - 1;
    }
    else {
      --(snake->y); 
    }
    setsnake(map, snake->x, (snake->y));
    return UP;
  }
  if( way == DOWN)
  {
    if (snake->y + 1 == MAP_SIZE)
    {
        snake->y = 0;
    }
    else {
          ++(snake->y);
    }
    setsnake(map, snake->x, (snake->y));
    return DOWN;
  }
  if (way == LEFT)
  {
    if (snake->x -1 == -1)
    {
      snake->x = MAP_SIZE - 1;  
    }
    else{
          --(snake->x);
    }
    setsnake(map, (snake->x), snake->y);
    return LEFT;
  }
  if (way == RIGHT)
  {
    if (snake->x + 1 == MAP_SIZE) 
    {
      snake->x = 0;
    }
    else {
          ++(snake->x);
    }
    setsnake(map, snake->x, snake->y);
    return RIGHT;
  }
  return way;
}

int overlap(int savedkey, int key)
  {
    if(savedkey == UP && key == DOWN)
      return TRUE;
    if(savedkey == DOWN && key == UP)
      return TRUE;
    if(savedkey == LEFT && key == RIGHT)
      return TRUE;
    if(savedkey == RIGHT && key == LEFT)
      return TRUE;
return FALSE;
  }

int colwithfruit(Snakepos * sp, Fruitpos * fp)
{
  if ((sp->x == fp->x && sp->y == fp->y))
  {
      return TRUE;
  }
  return FALSE;
}

int iscollision(int state) 
{
  if (state == COLLISION) 
  return TRUE;
return FALSE;
}
void Gameover(int score, int best, Queue *pq, int stage, int * scorearr)
{
  FILE * wfp;
  HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);
  if (score >= best){
      scorearr[stage - 1] = score;
    }
    else{
      scorearr[stage - 1] = best;
    }
  wfp = fopen("score.txt", "w");
  fprintf(wfp, "%d %d %d %d", scorearr[0], scorearr[1], scorearr[2], scorearr[3]);
  fclose(wfp);
  SetConsoleTextAttribute(hand, 14);
  gotoxy(MAP_SIZE / 2 - 4, MAP_SIZE / 2 - 5);
  printf("@@@<game over>@@@\n");
  gotoxy(MAP_SIZE / 2 -3, MAP_SIZE / 2 - 3);
  printf("your score : %d\n" , score);
  gotoxy(DEFAULT_X + 8, MAP_SIZE + 5 );
  printf("\n");
  SetConsoleTextAttribute(hand, 7);

while (!isEmpty(pq)){
    Dequeue(pq);
}
}

void Gamestart(MData map[MAP_SIZE][MAP_SIZE], int stage, int * scorearr)
{
  int best = scorearr[stage - 1];
  int score = 0;
  int key, savedkey = 0 ;
  Queue queue;
  QueueInit(&queue);
  Snakepos snake = { MAP_SIZE / 4 -2, MAP_SIZE / 4 + 1};
  Snakepos snakeSecond;
  Snakepos snaketail;
  int time = FALSE;
  Fruitpos fruit;
  fruit.numofFruit = 0;

   if( stage == 1)
   {
    stageOneInit(map);
   }
   else if(stage == 2)
   {
    stagetwoinit(map);
   }
   else if(stage == 3)
   {
    stageThreeInit(map);
   }
   else
   {
    stageFourinit(map);
   }

  drawmainmap(map);
  setsnake(map, snake.x, snake.y);

while(1)
{
  Sleep(1000 / (DWORD)NORMAL);
  if (fruit.numofFruit == 0){
    setFruit(map, &fruit);
  }
  drawSubmap(score, best, stage);

  if (colwithfruit(&snake, &fruit) == TRUE)
  {
    (fruit.numofFruit)--;
    time = FALSE;
    score +=5;
  }

  if (_kbhit())
  {
    key = _getch();
    if (key == 't' || key == 'T')
    { return ;}
    if (key == 'p' || key == 'P')
    {
      system("pause");
      gotoxy(DEFAULT_X, MAP_SIZE +6);
      printf("                                 ");
      gotoxy(DEFAULT_X, DEFAULT_Y);
    }

     if (key == 224 || key == 0)
     {
      key = _getch();
      if (overlap(savedkey, key) == TRUE){
        key = savedkey;
      }
      snakeSecond = snake;
      savedkey = Movesnakehead(map, &snake, key);
      Enqueue(&queue, snakeSecond);
      setsnaketail(map, snakeSecond.x, snakeSecond.y);
      if (time == TRUE) {
        snaketail = Dequeue(&queue);
        removeSnake(map, snaketail.x, snaketail.y);
      }
        else{
          time = TRUE;
        }
        if (iscollision(savedkey))
        { Gameover(score, best,&queue, stage , scorearr ); return;}
     }
  }
  else{
    snakeSecond = snake;
    savedkey = Movesnakehead(map, &snake, savedkey);
    Enqueue(&queue, snakeSecond);
    setsnaketail(map, snakeSecond.x, snakeSecond.y);
    if (time == TRUE){
      snaketail = Dequeue(&queue);
      removeSnake(map, snaketail.x, snaketail.y);
    }
    else {
      time = TRUE;
    }
    if (iscollision(savedkey))
    { Gameover(score, best, &queue, stage, scorearr); return;}
  }
}
}

int main()
{
  MData map[MAP_SIZE][MAP_SIZE];
  system("color 7");
  hidecursor();
  int stage;
  int scorearr[4] = { 0 };
  while (1)
  {
    system("mode con: cols=44 lines = 30");
    if (drawstartmenu() == FALSE) break;
    system("cls") ;
    stage = drawspeedmenu(scorearr);
    system("cls");
    Gamestart(map, stage, scorearr);
    system("pause");
  }
    return 0;
  
}