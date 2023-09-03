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

        printf("1. Adi��o\n2. Subtra��o\n3. Multiplica��o\n4. Divis�o\nQual tipo de conta voc� quer fazer? ");
        scanf("%d", &tipo);

        if (tipo < 1 || tipo > 4) {
            printf("Op��o inv�lida, escolha uma das op��es abaixo.\n\n");
            continue;
        }

        printf("Digite um n�mero:");
        scanf("%lf", &numero);

        printf("Digite outro n�mero para a opera��o:");
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
                printf("Erro: Divis�o por zero.\n");
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
                printf("Op��o inv�lida, escolha 's' para sim ou 'n' para n�o.\n");
            }
        } while (op != 'S' && op != 's' && op != 'N' && op != 'n');

        if (op != 'S' && op != 's') {
            break;
        }
    }

    system("cls");

    if (quantidadedesomas == 1) {
        printf("Voc� fez uma �nica opera��o\n\n");
    } else {
        printf("Voc� fez %d opera��es\n\n", quantidadedesomas);
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
            printf("A opera��o foi: %.2lf %s %.2lf = %.2lf\n", conta1[i], operacao, conta2[i], resultados[i]);
        } else {
            printf("A opera��o %d foi: %.2lf %s %.2lf = %.2lf\n", i + 1, conta1[i], operacao, conta2[i], resultados[i]);
        }
    }

    return 0;
}
