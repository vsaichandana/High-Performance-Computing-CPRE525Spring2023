#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Get number of doors and prizes from user
    int num_doors, num_prizes;
    printf("How many doors are there? ");
    scanf("%d", &num_doors);
    printf("How many prizes are there? ");
    scanf("%d", &num_prizes);

    // Make sure there are enough doors for the prizes
    if (num_prizes >= num_doors) {
        printf("Error: There must be more doors than prizes.\n");
        return 1;
    }

    // Create array of doors
    int doors[num_doors];
    for (int i = 0; i < num_doors; i++) {
        doors[i] = i;
    }

    // Shuffle doors
    for (int i = num_doors - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = doors[i];
        doors[i] = doors[j];
        doors[j] = temp;
    }

    // Randomly select the doors that have prizes
    int prize_doors[num_prizes];
    for (int i = 0; i < num_prizes; i++) {
        prize_doors[i] = doors[i];
    }

    // Ask contestant to pick a door
    printf("\n");
    printf(" =-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(" ** Monty Hall Simulator **\n");
    printf(" =-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n");
    int pick = -1;
    while (pick < 0 || pick >= num_doors) {
        printf(" Pick a door (0-%d): ", num_doors - 1);
        scanf("%d", &pick);
    }
    printf("\n You entered: %d\n", pick);

    // Tell contestant about another door
    int other = -1;
    printf("\n Interesting choice ...\n");
    for (int i = 0; i < num_doors; i++) {
        if (i != pick && !contains(prize_doors, num_prizes, i)) {
            other = i;
            break;
        }
    }
    printf("\n I can tell you for sure that the prize is not behind door: %d\n", other);

    // Ask if they want to change
    int change = -1;
    while (change != 0 && change != 1) {
        printf("\n Stay with Door %d (press 0) or switch to Door %d (press 1): ", pick, other);
        scanf("%d", &change);
    }
    int final_pick;
    if (change == 0) {
        final_pick = pick;
        printf("\n You stayed with Door %d\n ", final_pick);
    }
    else {
        final_pick = other;
        printf("\n You switched to Door %d\n ", final_pick);
    }

    // Check answer
    if (contains(prize_doors, num_prizes, final_pick)) {
        printf("\n *** WINNER ***\n\n");
    }
    else {
        printf("\n --- LOSER ---\n\n");
    }
    printf(" The prize was behind Door(s):");
    for (int i = 0; i < num_prizes; i++) {
        printf(" %d", prize_doors[i]);
    }
    printf("\n\n");

    return 0;
}

// int contains(int array[], int length, int element) {
//     for
int contains(int array[], int length, int element) {
    for (int i = 0; i < length; i++) {
        if (array[i] == element) {
            return 1;
        }
    }
    return 0;
}
