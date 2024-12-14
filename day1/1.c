#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char line[50];

    file = fopen("data.txt", "r");

    int ans = 0;
    while (fgets(line, 50, file) != NULL) {
        int num = atoi(line);
        ans += num / 3 - 2;
    }
    fclose(file);
    printf("%d", ans);
    return 0;
}
