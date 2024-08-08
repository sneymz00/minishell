#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "echo "Hola mundo" > saludo.txt";
    const char s[2] = " ";
    char *token;

    // Obtiene el primer token
    token = strtok(str, s);

    // Recorre los tokens
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, s);
    }

    return 0;
}

