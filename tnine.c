#include <stdio.h>
#include <string.h>
#include <ctype.h>
/*maximalni delka retezce je nastavena na 102, protoze vyuzivame funkci fgets,
ktera krom znaku '\0' navic pridava i znak '\n'*/
#define MAX_LEN 102

// parametry funkce load_input jsou retezce name a number,do kterych budeme nahravat jmeno a cislo kontaktu
// funkce slouzi k nacteni jmena a cisla kontaktu do retezcu
// k tomu vyuziva fgets, vstup nacitame po dvojici radku (proudove zpracovani)
// funkce zaroven kontroluje maximalni delku radku
// pokud dojdeme na konec seznamku, nebo porusime podminku vraci funkce 1, jinak 0

int load_input(char name[], char number[])
{
    if (fgets(name, MAX_LEN, stdin) == NULL)
    {
        return 1;
    }
    // testuju, jestli je string ukoncen '\n'
    // pokud neni a nejsme ani na konci vstupu (!feof(stdin)) -> vstup delsi nez povolena delka, vracime 1
    if (name[strlen(name) - 1] != '\n')
    {
        if (!feof(stdin))
        {
            fprintf(stderr, "Unavalaible contact!\n");
            return 1;
        }
    }
    // funkce strcspn najde prvni index vyskytu '\n' a a nahradi jej za '\0'
    name[strcspn(name, "\n")] = '\0';

    // to same, jen pro number
    if (fgets(number, MAX_LEN, stdin) == NULL)
    {
        return 1;
    }

    if (number[strlen(number) - 1] != '\n')
    {
        if (!feof(stdin))
        {
            fprintf(stderr, "Unavalaible contact!\n");
            return 1;
        }
    }
    number[strcspn(number, "\n")] = '\0';

    return 0;
}

// parametry funkce test_contacts jsou retezce name a number s nactenym jmenem a cislem kontaktu
// funkce zjistuje, jestli vstupni seznam odpovida zadani - jedna se o ASCII textova data
// pokud je podminka porusena, program vraci 1, jinak 0
// dale funkce prevede kazdy znak v retezci name[] na male pismeno

int test_contacts(char name[], char number[])
{
    for (int i = 0; name[i] != '\0'; i++)
    {
        if ((unsigned char)name[i] > 127)
        {
            return 1;
        }
        else
        {
            name[i] = tolower((unsigned char)name[i]);
        }
    }

    for (int i = 0; number[i] != '\0'; i++)
    {
        if ((unsigned char)number[i] > 127)
        {
            return 1;
        }
    }
    return 0;
}
// parametrem funkce test_argument je ukazatel na retezec typu char
// funkce testuje, jestli je argument zadan ve spravnem formatu - sekvenci cislic 0-9
// pokud neni argument zadan spravne vraci 1, jinak 0
int test_argument(char *arg)
{
    for (int i = 0; arg[i] != '\0'; i++)
    {
        if ((arg[i] < '0' || arg[i] > '9'))
        {
            return 1;
        }
    }
    return 0;
}
// paremetry funkce compare_number jsou retezce number a arg s aktualne nactenym cislem kontaktu a argumentem
// funkce slouzi k porovnani znaku v retezcich name a arg
// pomoci funkce strstr hledame vyskyt podretezce 'arg' v retezci 'number'
// pokud je ukazatel na char *matchnumber po zavolani strstr prazdny,funkce vraci 1 (zadny podretezec sme nenasli)
// pokud sme nejaky podretezec nasli, funkce vraci 0
int compare_number(char number[], char arg[])
{
    char *match_number = strstr(number, arg);

    if (match_number == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// parametry funkce num_to_char jsou znaky digit (predstavujici cislo 0-9) a character(znak, ktery danemu cislu odpovida)
// funkce slouzi k namapovani pismen na jednotliva cisla dle zadani, pro ucely funkce compare_characters
// funkce vyuziva switch case, pro kazde cislo vraci 1, pokud k nemu odpovida jedno z danych pismen
//  pro cislo 1 a ostatni znaky vraci 0
int num_to_char(char digit, char character)
{
    switch (digit)
    {
    case '2':
        return (character == 'a' || character == 'b' || character == 'c');
    case '3':
        return (character == 'd' || character == 'e' || character == 'f');
    case '4':
        return (character == 'g' || character == 'h' || character == 'i');
    case '5':
        return (character == 'j' || character == 'k' || character == 'l');
    case '6':
        return (character == 'm' || character == 'n' || character == 'o');
    case '7':
        return (character == 'p' || character == 'q' || character == 'r' || character == 's');
    case '8':
        return (character == 't' || character == 'u' || character == 'v');
    case '9':
        return (character == 'w' || character == 'x' || character == 'y' || character == 'z');
    case '0':
        return (character == '+');
    case '1':
        return 0;
    default:
        return 0;
    }
}
// parametry funkce comapre_characters jsou retezce name, obsahujici nactene jmeno kontaktu
//  a arg, obsahujici argument
// funkce slouzi k porovnavani znaku v retezcich name a arg a zjistuje, jestli existuje shoda
// na zaklade funkce num_to_char
// pokud jsou nalezeny alespon 2 po sobe jdouci shody, funkce vraci 0, jnak 1

int compare_characters(char name[], char arg[])
{
    int name_len = strlen(name);
    int arg_len = strlen(arg);
    int match_count = 0;
    // vnejsi loop prochazi kazdy znak v retezci name
    for (int i = 0; i < name_len; i++)
    {
        // vnitrni loop prochazi vsechny znaku v arg + kontroluje ze neprekrocime delku retezce name
        for (int j = 0; j < arg_len && (i + j) < name_len; j++)
        {
            // pomoci funkce num_to_char kontrolujeme, jestli doslo ke shode
            if (num_to_char(arg[j], name[i + j]))
            {
                match_count++; // pokud sme nasli shodu inkrementujeme match_count
            }
        }
    }
    if (match_count >= 2)
    {
        return 0;
    }
    return 1;
}

int main(int argc, char *argv[])
{
    // name slouzi k nacteni jmena kontaktu, number slouzi k nacteni telefoniho cisla kontaktu
    // counter slouzi k uchovani informace, jestli jsme vypsali nejake kontakty, nebo program musel neocekavane skoncit
    char name[MAX_LEN], number[MAX_LEN];
    int counter = 0;
    // testujeme neocekavany pocet argumentu
    if (argc > 2)
    {
        fprintf(stderr, "Too many arguments!\n");
        return 1;
    }
    // pokud neni zadan zadny argument, pomoci while loopu zacneme nacitat vstup funkci load_input
    // funkce test_contacts v kazde iteraci otestuje ,jestli je vstup platny, pokud najdeme chybu ve vstupu
    // funkce vrati 1, inkrementuje counter a vypise chybove hlaseni, pokud vrati 0, vypisou se vsechny kontakty

    if (argc == 1)
    {
        while (load_input(name, number) == 0)
        {
            if (test_contacts(name, number) != 0)
            {
                counter++;
                fprintf(stderr, "Unavalaible contact!\n");
                return 1;
            }
            printf("%s, %s\n", name, number);
        }
    }
    else
    {
        //pokud je zadan 1 argument, funkce test_argument otestuje, jestli je platny
        //pokud neni, inkrementuje counter a vypise chybove hlaseni
        if (test_argument(argv[1]) != 0)
        {
            counter++;
            fprintf(stderr, "Unavalaible input!\n");
            return 1;
        }
        else
        {
            //jinak zacneme opet nacitat kontakty, funkci test_contact v kazde iteraci testujeme vstup(viz u argc == 1)
            while (load_input(name, number) == 0)
            {
                if (test_contacts(name, number) != 0)
                {
                    counter++;
                    fprintf(stderr, "Unavalaible contact!\n");
                    return 1;
                }
                //pokud funkce compare_number nebo compare_characters vrati 0 (nasli sme pozadovanou poslouponost)
                //vypise se dany kontakt a inkrementuje se counter
                if (compare_number(number, argv[1]) == 0 || compare_characters(name, argv[1]) == 0)
                {
                    printf("%s, %s\n", name, number);
                    counter++;
                }
            }
        }
        //pokud counter zustane na 0, znamena to ze jsme nenasli zadny kontakt a program neocekavane neskoncil
        if (counter == 0)
        {
            printf("Not found");
        }
    }

    return 0;
}
