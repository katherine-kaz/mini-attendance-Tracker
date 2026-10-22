#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 60

char attendance[MAX];   // P, A, or -
int N = 0;              // class size

void resetSession() {
    for (int i = 0; i < N; i++) {
        attendance[i] = '-';
    }
}

void setClassSize() {
    int size;

    printf("Enter class size (1..60): ");
    if (scanf("%d", &size) != 1) {
        printf("Invalid input.\n");
        while(getchar()!='\n');
        return;
    }

    if (size < 1 || size > 60) {
        printf("Class size must be between 1 and 60\n");
        return;
    }

    N = size;
    resetSession();
    printf("[OK] Class size set to %d. All statuses cleared.\n", N);
}

void markAll() {
    if (N == 0) {
        printf("Set class size first.\n");
        return;
    }

    char status;

    for (int i = 0; i < N; i++) {

        while (1) {
            printf("Roll %d (P/A): ", i + 1);
            scanf(" %c", &status);
            status = toupper(status);

            if (status == 'P' || status == 'A') {
                attendance[i] = status;
                break;
            } else {
                printf("Invalid. Enter P or A.\n");
            }
        }

    }

    printf("[OK] Marking complete.\n");
}

void updateOne() {
    if (N == 0) {
        printf("Set class size first.\n");
        return;
    }

    int roll;
    char status;

    printf("Roll to update (1..%d): ", N);
    scanf("%d", &roll);

    if (roll < 1 || roll > N) {
        printf("Invalid roll number.\n");
        return;
    }

    printf("Current = %c\n", attendance[roll-1]);

    while (1) {
        printf("New (P/A): ");
        scanf(" %c", &status);
        status = toupper(status);

        if (status == 'P' || status == 'A') {
            attendance[roll-1] = status;
            printf("[OK] Updated.\n");
            break;
        } else {
            printf("Invalid. Enter P or A.\n");
        }
    }
}

void showSummary() {

    int present = 0;
    int absent = 0;
    int marked = 0;

    for (int i = 0; i < N; i++) {

        if (attendance[i] == 'P') {
            present++;
            marked++;
        }

        else if (attendance[i] == 'A') {
            absent++;
            marked++;
        }
    }

    float percent = 0;

    if (marked > 0)
        percent = (present * 100.0) / marked;

    printf("Marked: %d/%d   Present=%d   Absent=%d   Percent Present=%.2f%%\n",
           marked, N, present, absent, percent);
}

void showPresent() {

    printf("Present: ");

    for (int i = 0; i < N; i++) {
        if (attendance[i] == 'P')
            printf("%d ", i + 1);
    }

    printf("\n");
}

void showAbsent() {

    printf("Absent: ");

    for (int i = 0; i < N; i++) {
        if (attendance[i] == 'A')
            printf("%d ", i + 1);
    }

    printf("\n");
}

int main() {

    int choice;

    while (1) {

        printf("\n=== MINI ATTENDANCE TRACKER (Session-Only) ===\n");
        printf("1) Set/Change Class Size\n");
        printf("2) Mark All (1..N)\n");
        printf("3) Update One Roll\n");
        printf("4) Show Summary\n");
        printf("5) Show Present List\n");
        printf("6) Show Absent List\n");
        printf("7) Reset Session\n");
        printf("8) Exit\n");

        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                setClassSize();
                break;

            case 2:
                markAll();
                break;

            case 3:
                updateOne();
                break;

            case 4:
                showSummary();
                break;

            case 5:
                showPresent();
                break;

            case 6:
                showAbsent();
                break;

            case 7:
                resetSession();
                printf("[OK] Session reset.\n");
                break;

            case 8:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }

    }

}