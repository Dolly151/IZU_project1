# Jméno spustitelného programu
PROG = tnine

# Výchozí cíl - spustit testy
all: test

# Cíl pro spuštění testů
test:
	python3 test.py $(PROG)

# Cíl pro čistění, pokud bys chtěl
clean:
	rm -f *.o $(PROG)

.PHONY: all test clean
