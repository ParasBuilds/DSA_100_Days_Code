#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 1000
#define MAX_LEN        100

int main() {
    int n;
    scanf("%d", &n);

    char names[MAX_CANDIDATES][MAX_LEN];   // unique candidate names
    int  count[MAX_CANDIDATES];            // vote count per candidate
    int  total = 0;                        // number of unique candidates

    // ── Read each vote ──
    for (int i = 0; i < n; i++) {
        char vote[MAX_LEN];
        scanf("%s", vote);

        // Search if candidate already exists
        int found = -1;
        for (int j = 0; j < total; j++) {
            if (strcmp(names[j], vote) == 0) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            count[found]++;          // existing candidate → increment
        } else {
            strcpy(names[total], vote);  // new candidate
            count[total] = 1;
            total++;
        }
    }

    // ── Find winner ──
    int  maxVotes   = -1;
    char winner[MAX_LEN];
    winner[0] = '\0';

    for (int i = 0; i < total; i++) {
        if (count[i] > maxVotes) {
            // New max found → update winner
            maxVotes = count[i];
            strcpy(winner, names[i]);

        } else if (count[i] == maxVotes) {
            // Tie → pick lexicographically smaller name
            if (strcmp(names[i], winner) < 0)
                strcpy(winner, names[i]);
        }
    }

    printf("%s %d\n", winner, maxVotes);
    return 0;
}