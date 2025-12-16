#include <stdio.h>  // Per il printf originale
#include <limits.h> // Per testare INT_MAX e INT_MIN
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
    int len_ft = 0;
    int len_std = 0;
    char *null_ptr = NULL; // Trucco per evitare l'errore in compilazione

    printf("\n=== TEST BASE ===\n");
    
    // Test Carattere
    printf("--- CHAR ---\n");
    len_ft = ft_printf("Mio: %c\n", 'A');
    len_std = printf("Org: %c\n", 'A');
    printf("Len: Mio=%d | Org=%d\n", len_ft, len_std);

    // Test Stringa
    printf("\n--- STRING ---\n");
    len_ft = ft_printf("Mio: %s\n", "Ciao Mondo");
    len_std = printf("Org: %s\n", "Ciao Mondo");
    printf("Len: Mio=%d | Org=%d\n", len_ft, len_std);

    // Test Stringa NULL
    // Usiamo la variabile 'null_ptr' per non far arrabbiare il compilatore
    printf("\n--- STRING NULL ---\n");
    len_ft = ft_printf("Mio: %s\n", null_ptr);
    len_std = printf("Org: %s\n", null_ptr); 
    printf("Len: Mio=%d | Org=%d\n", len_ft, len_std);

    // Test Numeri (Decimali e Interi)
    printf("\n--- DECIMAL/INT ---\n");
    len_ft = ft_printf("Mio: %d, %i\n", 42, -12345);
    len_std = printf("Org: %d, %i\n", 42, -12345);
    printf("Len: Mio=%d | Org=%d\n", len_ft, len_std);

    // Test Unsigned
    printf("\n--- UNSIGNED ---\n");
    // Aggiunto cast esplicito a (unsigned int) per correggere l'errore del long
    len_ft = ft_printf("Mio: %u\n", (unsigned int)3000000000); 
    len_std = printf("Org: %u\n", (unsigned int)3000000000);
    printf("Len: Mio=%d | Org=%d\n", len_ft, len_std);

    // Test Hex (x e X)
    printf("\n--- HEX (x, X) ---\n");
    len_ft = ft_printf("Mio: %x, %X\n", 255, 255);
    len_std = printf("Org: %x, %X\n", 255, 255);
    printf("Len: Mio=%d | Org=%d\n", len_ft, len_std);

    // Test Pointer
    printf("\n--- POINTER ---\n");
    int a = 42;
    len_ft = ft_printf("Mio: %p\n", &a);
    len_std = printf("Org: %p\n", &a);
    printf("Len: Mio=%d | Org=%d\n", len_ft, len_std);
    
    // Test Pointer NULL
    printf("\n--- POINTER NULL ---\n");
    len_ft = ft_printf("Mio: %p\n", NULL);
    len_std = printf("Org: %p\n", NULL);
    printf("Len: Mio=%d | Org=%d\n", len_ft, len_std);

    // Test Percentuale
    printf("\n--- PERCENT ---\n");
    len_ft = ft_printf("Mio: %%\n");
    len_std = printf("Org: %%\n");
    printf("Len: Mio=%d | Org=%d\n", len_ft, len_std);

    return (0);
}