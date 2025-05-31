#include <stdio.h>
#include <string.h>

#define PASSWORD "admin123"

char candidates[3][20] = {"Arpit", "Anand", "Patel"};
int votes[3] = {0, 0, 0};

void displayMenu() {
    printf("Welcome to the Mini Voting System\n");
    printf("1. Vote\n");
    printf("2. View Vote Count (Admin Only)\n");
    printf("3. View Leading Candidate (Admin Only)\n");
    printf("4. Exit\n");
}

void Vote() {
    int choice;
    printf("Vote for your candidate:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s\n", i + 1, candidates[i]);
    }
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 3) {
        votes[choice - 1]++;
        printf("Thank you for voting!\n");
    } else {
        printf("Invalid choice. Vote not counted.\n");
    }
}

int checkPassword() {
    char input[20];
    printf("Enter password: ");
    scanf("%s", input);

    if (strcmp(input, PASSWORD) == 0) {
        return 1;
    } else {
        printf("Incorrect password. Access denied.\n");
        return 0;
    }
}

void showVoteCount() {
    printf("Vote Count:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s: %d votes\n", candidates[i], votes[i]);
    }
}

void leadingCandidate() {
    int maxIndex = 0;
    for (int i = 1; i < 3; i++) {
        if (votes[i] > votes[maxIndex]) {
            maxIndex = i;
        }
    }
    printf("Leading Candidate: %s with %d votes\n", candidates[maxIndex], votes[maxIndex]);
}

int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Vote();
                break;
            case 2:
                if (checkPassword()) {
                    showVoteCount();
                }
                break;
            case 3:
                if (checkPassword()) {
                    leadingCandidate();
                }
                break;
            case 4:
                printf("Exiting the system. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
        printf("\n");
    } while (choice != 4);

    return 0;
}
