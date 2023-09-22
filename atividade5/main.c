#include <stdio.h>
#include <stdlib.h>
#include "bubbleSort.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <arquivo_de_entrada>\n", argv[0]);
        return 1;
    }

    char *input_filename = argv[1];

    // Abrir o arquivo de entrada
    FILE *input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    // Ler as palavras do arquivo de entrada e armazená-las em um array
    char **words = NULL;
    int num_words = 0;
    char word[100]; // Supomos que cada palavra tenha no máximo 100 caracteres

    while (fscanf(input_file, "%s", word) != EOF) {
        words = realloc(words, (num_words + 1) * sizeof(char *));
        words[num_words] = strdup(word);
        num_words++;
    }

    // Fechar o arquivo de entrada
    fclose(input_file);

    // Chamar a função de ordenação (bubble sort)
    bubble_sort(words, num_words);

    // Criar e escrever o arquivo de saída
    char output_filename[100];
    snprintf(output_filename, sizeof(output_filename), "%s_ordenado.txt", input_filename);
    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        perror("Erro ao criar o arquivo de saída");
        return 1;
    }

    for (int i = 0; i < num_words; i++) {
        fprintf(output_file, "%s\n", words[i]);
        free(words[i]);
    }
    free(words);

    // Fechar o arquivo de saída
    fclose(output_file);

    printf("Arquivo ordenado com sucesso: %s\n", output_filename);

    return 0;
}
