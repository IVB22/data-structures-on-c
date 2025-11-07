// C program on students details using command line arguments
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <name> <roll_number> <marks>\n", argv[0]);
        return 1;
    }
    
    printf("\n===== Student Details =====\n");
    printf("Name: %s\n", argv[1]);
    printf("Roll Number: %s\n", argv[2]);
    printf("Marks: %s\n", argv[3]);
    printf("===========================\n");
    
    return 0;
}
