#include <stdio.h>
#include <stdlib.h>

int calc_fuel(int fuel){
    int ans = 0;
    while (fuel > 0){
        fuel = fuel / 3 -2;
        if (fuel > 0) ans += fuel;
    }
    return ans;
}

int main() {
    FILE *file;
    char line[50];

    file = fopen("data.txt", "r");

    int ans = 0;
    while (fgets(line, 50, file) != NULL) {
        ans += calc_fuel(atoi(line));
    }
    fclose(file);
    printf("%d", ans);
    return 0;
}
