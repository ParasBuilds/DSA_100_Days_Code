#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    
    // Store candidate names and their vote counts
    char names[100][100];      // stores candidate names
    int voteCount[100];         // stores corresponding vote counts
    int uniqueCount = 0;        // total unique candidates
    
    // Read all votes and count them
    for(int i = 0; i < n; i++) {
        char currentVote[100];
        scanf("%s", currentVote);
        
        // Check if this candidate already received votes before
        int found = 0;
        for(int j = 0; j < uniqueCount; j++) {
            if(strcmp(names[j], currentVote) == 0) {
                // Candidate found, increment their vote count
                voteCount[j]++;
                found = 1;
                break;
            }
        }
        
        // If it's a new candidate, add them
        if(found == 0) {
            strcpy(names[uniqueCount], currentVote);
            voteCount[uniqueCount] = 1;
            uniqueCount++;
        }
    }
    
    // Find the candidate with maximum votes
    int maxVotes = voteCount[0];
    char winner[100];
    strcpy(winner, names[0]);
    
    // Check all other candidates
    for(int i = 1; i < uniqueCount; i++) {
        // If more votes, or same votes but lexicographically smaller
        if(voteCount[i] > maxVotes) {
            maxVotes = voteCount[i];
            strcpy(winner, names[i]);
        }
        else if(voteCount[i] == maxVotes && strcmp(names[i], winner) < 0) {
            strcpy(winner, names[i]);
        }
    }
    
    // Print the winner and their vote count
    printf("%s %d\n", winner, maxVotes);
    
    return 0;
}
