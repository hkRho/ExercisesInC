/* Software Systems SP2020
 * Head First C
 * @Author: HK Rho
 */

#include <stdio.h>
#include <stdlib.h>

void get_input(char *card_name);
int update_count(int value, int count);
void count_cards(int count, char *card_name);

int main() {
    char card_name[3];
    int count = 0;

    count_cards(count, card_name);

    return 0;
}

/* Prompts the user for input and puts the reply in the given buffer.
   User input is truncated to the first two characters.

   card_name: buffer where result is stored
*/
void get_input(char *card_name) {
    puts("Enter the card_name: ");
    scanf("%2s", card_name);
}

/* Updates the count variable depending on the value of the selected card.

   value: card value
*/
int update_count(int val, int count) {
    if ((val > 2) && (val < 7)) {
        count++;
    }
    else if (val == 10) {
        count--;
    }
    return count;
}

/* Keeps track of the frequency that high value cards were drawn to increase
   the chance of winning in Blackjack.

   High value -> decrease count
   Low value  -> increase count

   count: integer value that indicates whether it is good or bad to place a bet
   card_name: buffer where result is stored
*/
void count_cards(int count, char *card_name) {
      do {
          int val = 0;
          get_input(card_name);

          switch(card_name[0]) {
              case 'K':
              case 'Q':
              case 'J':
                  val = 10;
                  break;
              case 'A':
                  val = 11;
                  break;
              case 'X':
                  continue;
              default:
                  val = atoi(card_name);
                  if ((val < 1) || (val > 10)) {
                      puts("I don't understand that value!");
                      continue;
                  }
          }
          update_count(val, count);
          printf("current count: %i\n", count);
    } while (card_name[0] != 'X');
}
