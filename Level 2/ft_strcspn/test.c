#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
  
int main() 
{ 
  
    int score1 = 0, score2 = 0, k = 0, sizen = 0, size = 0; 
  
    // initial Round1 strings 
    char player1[] = "geeks"; 
    char play2[] = ""; 
  
    while (1) { 
        // generating random character 
        char randoml = 'a' + (random() % 26); 
        play2[k++] = randoml; 
  
        size = strcspn(play2, player1); 
  
        if (size == sizen) { 
            // if the character is present, break 
            score2 = size; 
            break; 
        } 
        else { 
            sizen = size; 
        } 
    } 
  
    // initial Round2 strings 
    const char player2[] = "geeks"; 
    char play1[] = ""; 
    k = 0, sizen = 0; 
  
    while (1) { 
        // generating random character 
        char randoml = 'a' + (random() % 26); 
        play1[k++] = randoml; 
  
        size = strcspn(play1, player2); 
  
        if (size == sizen) { 
  
            // if the character is present, break 
            score1 = size; 
            break; 
        } 
        else { 
            sizen = size; 
        } 
    } 
  
    if (score1 > score2) 
        printf("Player 1 won!! Score : %d", score1); 
    else if (score2 > score1) 
        printf("Player 2 won!! Score : %d", score2); 
    else
        printf("Match Drawn!! Score : %d", score1); 
} 