//
//  main.c
//  Competitors
//
//  Created by Khongmeng Kormoua on 2020. 10. 14..
//  Copyright © 2020. khonmeng Kormoua. All rights reserved.
//

#include <stdio.h>
 
typedef struct Date {
    int year, month, day;
} Date;
 
typedef struct Competitor {
    char name[31];
    Date birth;
    int rank;
} Competitor;
 
void Date_print(Date d);
 
void Competitor_print(Competitor c);
 
int main() {
    Competitor competitors[5] = {
        { "Am, Erica", {1984, 5, 6}, 1 },
        { "Abnorm, Al", {1982, 9, 30}, 3 },
        { "Pri, Mary", {1988, 8, 25}, 2 },
        { "Duck, Ling", {1979, 6, 10}, 5 },
        { "Mac, Donald", {1992, 4, 5}, 4 },
    };
 
    /* name of competitor 0 - printf %s */
    printf("%s\n", competitors[0].name);
    /* rank of competitor 2 */
    printf("%d\n", competitors[2].rank);
    /* birth date of competitor 4, use the given function */
    Date_print(competitors[4].birth);
    /* the first letter of the name of competitor 1 (a string is an array of characters) */
    printf("%c\n", competitors[1].name[0]);
    /* is competitor 1 among the best three? yes/no, may use ?: operator */
    (competitors[1].rank == 1 || competitors[1].rank == 2 || competitors[1].rank == 3) ? printf("yes\n") : printf("no\n");
    /* is competitor 4 faster than competitor 3? */
    (competitors[4].rank < competitors[3].rank) ? printf("yes\n") : printf("no\n");
    /* was competitor 1 born in the same year as competitor 2? */
    (competitors[1].birth.year == competitors[2].birth.year) ? printf("yes\n") : printf("no\n");
    /* complete the Competitor_print() function,
     * then print all data of competitor 1 */
    Competitor_print(competitors[1]);
    /* at last print all data of all competitors. */
    for (int i = 0; i < 5; i += 1)
        Competitor_print(competitors[i]);
    return 0;
}
 
void Date_print(Date d) {
    /* print year, month and day */
    printf("%d/%d/%d\n", d.year, d.month, d.day);
}
 
void Competitor_print(Competitor c) {
    /* print all data of the competitor */
    printf("%s\n", c.name);
    Date_print(c.birth);
    printf("%d\n", c.rank);
}
