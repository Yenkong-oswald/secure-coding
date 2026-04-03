#include <stdio.h>
int main() {
    char buffer[5];
    printf("Enter text: ");
    fgets(buffer, sizeof(buffer), stdin);
    printf("You entered: %s\n", buffer);
    return 0;
}
