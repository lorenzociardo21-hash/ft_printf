*Questo progetto è stato creato come parte del curriculum di 42 da lciardo.*

# ft_printf

## Descrizione
Questo progetto consiste nel recodificare la funzione `printf` della libreria standard del C. L'obiettivo è creare una libreria (`libftprintf.a`) che contenga la funzione `ft_printf`, capace di replicare il comportamento dell'originale gestendo le seguenti conversione: caratteri (%c), stringhe (%s), puntatori (%p), decimali (%d, %i), interi senza segno (%u), esadecimali (%x, %X) e il simbolo percentuale (%%).

L'obiettivo principale di questo progetto è imparare:
* L'utilizzo delle funzioni variadiche in C (`stdarg.h`).
* La gestione avanzata della formattazione delle stringhe e dell'output.
* La creazione e la gestione di librerie statiche strutturate.

## Istruzioni

### Compilazione
Poiché il progetto è una libreria, il comando `make` genererà il file `libftprintf.a`. Esegui il comando nella root del progetto:

    make

Per rimuovere i file oggetto creati durante la compilazione:

    make clean

Per rimuovere tutti i file compilati (incluso la libreria `libftprintf.a`):

    make fclean

### Esecuzione
Essendo una libreria statica, `ft_printf` non può essere eseguito direttamente. Devi compilare un file `.c` (es. `main.c`) collegandolo alla tua libreria.

## Risorse

### Riferimenti
Ecco alcuni riferimenti classici e documentazione utilizzati per questo progetto:
* [Man page printf (3)](https://man7.org/linux/man-pages/man3/printf.3.html) - Documentazione ufficiale sul comportamento dei formati.
* [Man page stdarg (3)](https://linux.die.net/man/3/stdarg) - Documentazione sulle macro va_start, va_arg, va_copy, va_end.
* [C Variadic Functions Tutorial](https://www.geeksforgeeks.org/variadic-functions-in-c/) - Guida pratica all'uso di argomenti variabili.

### Utilizzo dell'IA
Come richiesto dai requisiti del progetto, strumenti di Intelligenza Artificiale sono stati utilizzati nelle seguenti modalità:

**Compiti (Tasks):**
* Spiegazione del funzionamento delle macro `va_list`, `va_start` e `va_end`.
* Chiarimenti sulla logica matematica per la conversione da base decimale a esadecimale.
* Generazione di casi di test complessi (edge cases) per verificare la parità con la printf originale.
