#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int difficulty;
    int value1;
    int value2;
    int operation;
    int result;
} calculate;

void play();
void showInfo(calculate calc);
int add(int answer, calculate calc);
int subtract(int answer, calculate calc);
int multiply(int answer, calculate calc);

int points = 0;

int main() {
    srand(time(NULL));
    play();
    return 0;
}

void play() {
    calculate calc;
    int difficulty;

    printf("Please select a difficulty level [1, 2, 3 or 4]:\n");
    scanf("%d", &difficulty);
    fflush(stdin);
    calc.difficulty = difficulty;

    calc.operation = rand() % 3;

    if(calc.difficulty == 1) {
        calc.value1 = rand() % 11;
        calc.value2 = rand() % 11;
    } else if(calc.difficulty == 2) {
        calc.value1 = rand() % 101;
        calc.value2 = rand() % 101;
    } else if(calc.difficulty == 3) {
        calc.value1 = rand() % 1001;
        calc.value2 = rand() % 1001;
    } else if(calc.difficulty == 4) {
        calc.value1 = rand() % 10001;
        calc.value2 = rand() % 10001;
    } else {
        calc.value1 = rand() % 100001;
        calc.value2 = rand() % 100001;
    }

    int answer;
    printf("Inform the result to the following operation:\n");

    if(calc.operation == 0) {
        printf("%d + %d\n", calc.value1, calc.value2);
        scanf("%d", &answer);
        fflush(stdin);

        if(add(answer, calc)) {
            points++;
            printf("You have %d point(s).\n", points);
        }
    } else if (calc.operation == 1) {
        printf("%d - %d\n", calc.value1, calc.value2);
        scanf("%d", &answer);
        fflush(stdin);

        if(subtract(answer, calc)) {
            points++;
            printf("You have %d point(s).\n", points);
        }
    } else if (calc.operation == 2) {
        printf("%d * %d\n", calc.value1, calc.value2);
        scanf("%d", &answer);
        fflush(stdin);

        if(multiply(answer, calc)) {
            points++;
            printf("You have %d point(s).\n", points);
        }
    } else {
        printf("Unrecognised operation.\n");
    }

    printf("Do you wish to keep playing? [1=Y/2=N]\n");
    int cont;
    scanf("%d", &cont);
    fflush(stdin);

    while (cont != 1 && cont != 2) {
        printf("Invalid option!\n");
        printf("Do you wish to keep playing? [1=Y/2=N]\n");
        scanf("%d", &cont);
        fflush(stdin);
    }

    if(cont == 1) {
        play();
    } else if (cont == 2) {
        printf("Thank you for playing! You finished with %d point(s)\n", points);
        exit(0);
    }
}

void showInfo(calculate calc) {
    char op[25];

    if (calc.operation == 0) {
        sprintf(op, "Add");
    } else if (calc.operation == 1) {
        sprintf(op, "Subtract");
    } else if (calc.operation == 2) {
        sprintf(op, "Multiply");
    } else {
        sprintf(op, "Invalid operation");
    }

    printf("Value 1: %d\nValue 2: %d\nDifficulty: %d\nOperation: %s", calc.value1, calc.value2, calc.difficulty, op);
}

int add(int answer, calculate calc) {
    int result = calc.value1 + calc.value2;
    calc.result = result;
    int correct = 0;

    if(answer == calc.result) {
        printf("Correct answer!\n");
        correct = 1;
    } else {
        printf("Incorrect answer!\n");
    }
    printf("%d + %d = %d\n", calc.value1, calc.value2, calc.result);
    return correct;
}

int subtract(int answer, calculate calc) {
    int result = calc.value1 - calc.value2;
    calc.result = result;
    int correct = 0;

    if(answer == calc.result) {
        printf("Correct answer!\n");
        correct = 1;
    } else {
        printf("Incorrect answer!\n");
    }
    printf("%d - %d = %d\n", calc.value1, calc.value2, calc.result);
    return correct;
}

int multiply(int answer, calculate calc) {
    int result = calc.value1 * calc.value2;
    calc.result = result;
    int correct = 0;

    if(answer == calc.result) {
        printf("Correct answer!\n");
        correct = 1;
    } else {
        printf("Incorrect answer!\n");
    }
    printf("%d * %d = %d\n", calc.value1, calc.value2, calc.result);
    return correct;
}