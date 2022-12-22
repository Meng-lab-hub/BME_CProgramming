//
//  main.c
//  smallLetterCapitalLetter
//
//  Created by Khongmeng Kormoua on 2020. 10. 09..
//  Copyright © 2020. khonmeng Kormoua. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>  // for isupper, toupper, islower, tolower

int BuiltinFunction(void);

int main(void) {
    char cin, cout;
    
    while(scanf("%c", &cin) == 1) {
        if (cin >= 'A' && cin <= 'Z')
            cout = cin + 'a' - 'A';    /* this is 32. 32 is the different between capital let
                                        ter and its lowercase letter in ascii table */
        else if (cin >= 'a' && cin <= 'z')
            cout = cin - 'a' + 'A';
        else cout = cin;
        printf("%c", cout);
    }
    return 0;
}

int BuiltinFunction(void) {
    char cin, cout;
    
    while(scanf("%c", &cin) == 1) {
        if (isupper(cin))
            cout = tolower(cin);
        else if (islower(cin))
            cout = toupper(cin);
        else cout = cin;
        printf("%c", cout);
    }
    return 0;
}
