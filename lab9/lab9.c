#include <stdio.h>

/*=====part1=====*/

typedef struct line_s{
    float x1, y1;
    float x2, y2;
    float x3, y3;
    float slope;
} Line;

float GetSlope(float x1, float y1, float x2, float y2){
    return (y2 - y1) / (x2 - x1);
}

float GetY(float slope, float x, float b){
    return slope * x + b;
}


/*=====part2=====*/

#define NAME_MAX_LEN 20
#define SURNAME_MAX_LEN 20
#define STUDENT_COUNT_MAX 100

typedef struct grades_s{
    float midterm, final, homework;
} Grades;

typedef struct students_s{
    char name[NAME_MAX_LEN];
    char surname[SURNAME_MAX_LEN];
    int id;
    Grades grades;
} Students;


/*=====part3=====*/

#include <string.h>

#define GAME_NAME_MAX_LEN 20
#define GAME_COUNT_MAX 100
#define CONSOLE_NAME_MAX_LEN 20
#define CONSOLE_COUNT_MAX 10

typedef struct game_s{
    char name[GAME_NAME_MAX_LEN];
    char consoles[CONSOLE_COUNT_MAX][CONSOLE_NAME_MAX_LEN];
    float score;
} Game;



int main(){

    /*---part1---*/
    Line myLine;

    printf("Enter x1, y1:");
    scanf("%f %f", &myLine.x1, &myLine.y1);
    printf("Enter x2, y2:");
    scanf("%f %f", &myLine.x2, &myLine.y2);
    printf("Enter x3:");
    scanf("%f", &myLine.x3);

    myLine.slope = GetSlope(myLine.x1, myLine.y1, myLine.x2, myLine.y2);
    myLine.y3 = GetY(myLine.slope, myLine.x3, myLine.y1 - myLine.slope * myLine.x1);

    printf("\nSlope of line = %f\ny3 = %f\n\n", myLine.slope, myLine.y3);


    /*---part2---*/
    Students students[STUDENT_COUNT_MAX];
    Students *currentStudent;

    int numberOfStudents;
    printf("Enter -1 to exit any time.\n");
    for(numberOfStudents = 0; 1; ++numberOfStudents){
        currentStudent = students + numberOfStudents;

        printf("Enter name and surname:\n");
        scanf("%s", currentStudent->name);

        if((currentStudent->name[0] == '-' && currentStudent->name[1] == '1'))
            break;

        scanf("%s", currentStudent->surname);
        
        if((currentStudent->surname[0] == '-' && currentStudent->surname[1] == '1'))
            break;

        printf("Enter id:\n");
        scanf("%d", &currentStudent->id);

        if(currentStudent->id == -1)
            break;
        
        printf("Enter midterm, final, and homework grades:\n");
        scanf("%f %f %f", &(currentStudent->grades.midterm), &(currentStudent->grades.final), &(currentStudent->grades.homework));

        if(currentStudent->grades.midterm == -1.0f || currentStudent->grades.final == -1.0f || currentStudent->grades.homework == -1.0f)
            break;
    }

    Grades avgGrades = {0, 0, 0};

    for(int i = 0; i < numberOfStudents; ++i){
        avgGrades.midterm += students[i].grades.midterm;
        avgGrades.final += students[i].grades.final;
        avgGrades.homework += students[i].grades.homework;
    }

    avgGrades.midterm /= numberOfStudents;
    avgGrades.final /= numberOfStudents;
    avgGrades.homework /= numberOfStudents;

    printf("Average grades:\nMidterm: %f\nFinal: %f\nHomework: %f\n", avgGrades.midterm, avgGrades.final, avgGrades.homework);

    int searchedId;
    int found = 0;
    printf("Enter an id to search student:\n");
    scanf("%d", &searchedId);

    for(int i = 0; i < numberOfStudents; ++i){
        if(students[i].id == searchedId){
            printf("\n");
            printf("%s %s\n", students[i].name, students[i].surname);
            printf("%d\n", students[i].id);
            printf("Midterm: %f\tFinal: %f\tHomework: %f\t\n\n", students[i].grades.midterm, students[i].grades.final, students[i].grades.homework);
            found = 1;
            break;
        }
    }

    if(!found){
        printf("No student found with id %d.\n\n", searchedId);
    }
    

    /*---part3---*/
    Game games[GAME_COUNT_MAX];
    Game *currentGame;

    char consoles[CONSOLE_COUNT_MAX][CONSOLE_NAME_MAX_LEN];
    int consoleCount = 0;

    int numberOfGames;
    printf("Enter -1 any time to exit.\n");
    for(numberOfGames = 0; 1; ++numberOfGames){
        currentGame = games + numberOfGames;
        
        printf("Enter game's name:\n");
        scanf("%s", currentGame->name);

        if(!strncmp(currentGame->name, "-1", 2)){
            break;
        }

        printf("Enter consoles, enter -1 to exit:\n");
        char inputConsole[CONSOLE_NAME_MAX_LEN];
        int numberOfConsoles;
        for(numberOfConsoles = 0; 1; ++numberOfConsoles){
            scanf("%s", inputConsole);
            
            if(!strncmp(inputConsole, "-1", 2))
                break;
            strcpy(currentGame->consoles[numberOfConsoles], inputConsole);

            int isNewConsole = 1;
            for(int i = 0; i < consoleCount; ++i){
                if(!strcmp(inputConsole, consoles[i])){
                    isNewConsole = 0;
                    break;
                }
            }

            if(isNewConsole){
                strcpy(consoles[consoleCount], inputConsole);
                ++consoleCount; 
            }
        }

        printf("Enter score of the game:\n");
        scanf("%f", &currentGame->score);
    }

    float avgGameScore = 0;
    for(int i = 0; i < numberOfGames; ++i){
        avgGameScore += games[i].score;
    }

    avgGameScore /= numberOfGames;
    printf("\nAverage score of all games = %f\n", avgGameScore);

    for(int i = 0; i < consoleCount; ++i){
        printf("%s\t\t", consoles[i]);
    }
    printf("\n");

    for(int i = 0; i < numberOfGames; ++i){
        for(int j = 0; j < consoleCount; ++j){
            int isOn = 0;
            for(int k = 0; games[i].consoles[k][0]; ++k){
                if(!strcmp(games[i].consoles[k], consoles[j])){
                    isOn = 1;
                    break;
                }
            }
            if(isOn){
                printf("%s\t\t", games[i].name);
            }
            else
                printf("\t\t");
        }
        printf("\n");
    }

    return 0;
}