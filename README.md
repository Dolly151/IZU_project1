# IZP – Projekt 1: Telefonní seznam

## Popis projektu
Cílem tohoto projektu je vytvořit program, který emuluje zjednodušený algoritmus vyhledávání kontaktů na základě posloupnosti číslic. Vstupem programu je seznam kontaktů, zatímco vstupní argument představuje hledané číselné kritérium. Výstupem je seznam kontaktů, jejichž jméno nebo telefonní číslo odpovídá zadanému filtru.

## Specifikace
- Program implementujte ve zdrojovém souboru `tnine.c`.
- Vstupní data jsou čtena ze standardního vstupu (stdin).
- Výstup programu je tisknut na standardní výstup (stdout).

## Překlad
K překladu použijte následující příkaz:
```bash
gcc -std=c11 -Wall -Wextra -Werror tnine.c -o tnine
```

## Syntax spuštění
Program se spouští následovně:
```bash
./tnine [CISLO]
```
kde `CISLO` představuje hledané kritérium - sekvenci číslic 0-9. Pokud není argument zadán, program vypíše všechny kontakty.

## Vstupní data
Telefonní seznam obsahuje ASCII textová data. Každý kontakt se skládá ze dvou řádků:
1. Jméno osoby
2. Telefonní číslo

Maximální délka řádku je 100 znaků. Program musí podporovat alespoň 42 kontaktů.

## Algoritmus vyhledávání
Program hledá nepřerušenou posloupnost znaků odpovídající zadaným číslicím. Každá číslice reprezentuje následující znaky:
- 2: abc
- 3: def  
- 4: ghi
- 5: jkl
- 6: mno
- 7: pqrs
- 8: tuv
- 9: wxyz
- 0: +

Vyhledávání je case-insensitive (nerozlišuje velikost písmen).

## Výstup
- **Nalezené kontakty:** `JMENO, TELCISLO`
- **Žádný kontakt:** `Not found`

### Kontakt(y) nalezen(y)
Každý kontakt, který odpovídá hledanému kritériu, program vytiskne na jeden řádek ve formátu "JMENO, TELCISLO", kde JMENO je jméno kontaktu z telefonního seznamu a TELCISLO je záznam o telefonním čísle. Program tiskne všechny kontakty, které kritériu odpovídají. Na pořadí řádků nezáleží. Stejně tak nezáleží ani na velikosti písmen.
