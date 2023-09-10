#include <stdio.h>

char*** k_subsets(char* array) {

}

int main(int argc, char **argv) {
        char*** subsets = k_subsets(argv[0]);

        for (int i = 0; subsets[i] ; ++i) {
                printf("[");
                for (int j = 0; subsets[i][j] ; ++j) {
                        printf("%s,\n", subsets[i][j]);
                }
        }

        return 0;
}


