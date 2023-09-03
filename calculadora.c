#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    char op;
    int quantidadedesomas = 0, tipos[100];
    double resultados[100], conta1[100], conta2[100];
    double numero, numero2, resultado;
    int tipo;

    while (1) {
        system("cls");

        printf("1. Adição\n2. Subtração\n3. Multiplicação\n4. Divisão\nQual tipo de conta você quer fazer? ");
        scanf("%d", &tipo);

        if (tipo < 1 || tipo > 4) {
            printf("Opção inválida, escolha uma das opções abaixo.\n\n");
            continue;
        }

        printf("Digite um número:");
        scanf("%lf", &numero);

        printf("Digite outro número para a operação:");
        scanf("%lf", &numero2);

        if (tipo == 1) {
            resultado = numero + numero2;
        } else if (tipo == 2) {
            resultado = numero - numero2;
        } else if (tipo == 3) {
            resultado = numero * numero2;
        } else if (tipo == 4) {
            if (numero2 != 0) {
                resultado = numero / numero2;
            } else {
                printf("Erro: Divisão por zero.\n");
                continue;
            }
        }

        conta1[quantidadedesomas] = numero;
        conta2[quantidadedesomas] = numero2;
        resultados[quantidadedesomas] = resultado;
        tipos[quantidadedesomas] = tipo;

        quantidadedesomas++;

        printf("\nResultado: %.2lf\n", resultado);

        do {
            printf("\nDeseja digitar outro? (s/n): ");
            scanf(" %c", &op);

            if (op != 'S' && op != 's' && op != 'N' && op != 'n') {
                printf("Opção inválida, escolha 's' para sim ou 'n' para não.\n");
            }
        } while (op != 'S' && op != 's' && op != 'N' && op != 'n');

        if (op != 'S' && op != 's') {
            break;
        }
    }

    system("cls");

    if (quantidadedesomas == 1) {
        printf("Você fez uma única operação\n\n");
    } else {
        printf("Você fez %d operações\n\n", quantidadedesomas);
    }

    for (int i = 0; i < quantidadedesomas; i++) {
        char operacao[20];
        if (tipos[i] == 1) {
            strcpy(operacao, "+");
        } else if (tipos[i] == 2) {
            strcpy(operacao, "-");
        } else if (tipos[i] == 3) {
            strcpy(operacao, "x");
        } else if (tipos[i] == 4) {
            strcpy(operacao, "/");
        }

        if (quantidadedesomas == 1) {
            printf("A operação foi: %.2lf %s %.2lf = %.2lf\n", conta1[i], operacao, conta2[i], resultados[i]);
        } else {
            printf("A operação %d foi: %.2lf %s %.2lf = %.2lf\n", i + 1, conta1[i], operacao, conta2[i], resultados[i]);
        }
    }

    return 0;
}
