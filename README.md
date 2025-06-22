Popis projektu
Cílem projektu je vytvořit program, který by emuloval zjednodušený algoritmus hledání kontaktů zadaných pomocí posloupnosti číslic. Vstupem programu je posloupnost číslic. Výstup programu bude obsahovat seznam kontaktů, které odpovídají zadanému číselnému filtru.

Detailní specifikace
Program implementujte ve zdrojovém souboru ''tnine.c''. Vstupní data budou čtena ze standardního vstupu (stdin), výstup bude tisknut na standardní výstup (stdout).

Překlad a odevzdání zdrojového souboru
Odevzdání: Odevzdejte zdrojový soubor ''tnine.c'' prostřednictvím informačního systému.
Překlad: Program překládejte s následujícími argumenty:

gcc -std=c11 -Wall -Wextra -Werror tnine.c -o tnine

Syntax spuštění
Program se spouští v následující podobě: (./tnine značí umístění a název programu):

./tnine CISLO
CISLO zde představuje hledané kritérium, sekvenci číslic 0 až 9, které reprezentují sekvenci hledaných znaků.
Pokud je program spuštěn bez argumentů, program se bude chovat, jako by hledanému kritériu odpovídal každý kontakt ze seznamu.

Implementační detaily
Vstupní telefonní seznam
Telefonní seznam jsou ASCII textová data. Každý záznam o kontaktu obsahuje dva neprázdné řádky: jméno osoby a jeho telefonní číslo. Každý řádek obsahuje maximálně 100 znaků, jinak se jedná o neplatná data. Seznam kontaktů je neuspořádaný. U všech dat nezáleží na velikosti písmen (tzv. case insensitive). Program musí podporovat alespoň 42 kontaktů.

Kritérium nalezení kontaktu
Pro zjednodušení budeme v tomto projektu uvažovat hledání '''nepřerušené posloupnosti''' zadaných znaků/číslic v telefonním kontaktu. Nepřerušenou posloupností znaků se myslí takový podřetězec, u kterého se na každé pozici vyskytuje znak, který odpovídá jednomu ze znaků, které reprezentuje číslice na stejné pozici v zadaném řetězci. Každá číslice kromě sebe sama reprezentuje ještě následující znaky: 2 (abc), 3 (def), 4 (ghi), 5 (jkl), 6 (mno), 7 (pqrs), 8 (tuv), 9 (wxyz), 0 (+).

Výstup programu
Výstup programu může být dvojího druhu:

žádný kontakt nenalezen,
nalezen jeden a více kontaktů.
Kontakt nenalezen

Not found
Pokud v telefonním seznamu neexistuje kontakt, u něhož by nějaká část odpovídala hledanému řetězci CISLO, vytiskne program toto hlášení.

Kontakt(y) nalezen(y)
Každý kontakt, který odpovídá hledanému kritériu, program vytiskne na jeden řádek ve formátu "JMENO, TELCISLO", kde JMENO je jméno kontaktu z telefonního seznamu a TELCISLO je záznam o telefonním čísle. Program tiskne všechny kontakty, které kritériu odpovídají. Na pořadí řádků nezáleží. Stejně tak nezáleží ani na velikosti písmen.
