#include <stdio.h>

// Programa: Calculadora de IMC com Recomendação de Dieta

int main() {
    // ==== Declaração de variáveis ====
    int sexo, idade, objetivo;
    float peso, imc, imcIdeal, tmb, caloriasRecomendadas, altura;

    // ==== Apresentação ====
    printf("=== Calculadora de IMC com Recomendacao de Dieta ===\n");

    // ==== Entrada de dados ====
    // Sexo
    printf("Digite 1 para Homem ou 2 para Mulher: ");
    scanf("%d", &sexo);
    if (sexo != 1 && sexo != 2) {
        printf("Opcao invalida. Use 1 para Homem ou 2 para Mulher.\n");
        return 1;
    }

    // Idade
    printf("Digite a idade: ");
    scanf("%d", &idade);

    // Altura
    printf("Digite a altura (em metros ex: 1.70): ");
    scanf("%f", &altura);

    // Peso
    printf("Digite o peso (em kg): ");
    scanf("%f", &peso);

    // Validação
    if (altura <= 0 || peso <= 0) {
        printf("Altura e peso devem ser positivos.\n");
        return 1;
    }

    // ==== Cálculos iniciais ====
    // IMC
    imc = peso / (altura * altura);

    // IMC Ideal estimado
    if (sexo == 1) {
        imcIdeal = (0.5 * imc) + (0.03 * idade) + 11.5; // Homem
    } else {
        imcIdeal = (0.5 * imc) + (0.03 * idade) + 10.5; // Mulher
    }

    // Exibição do IMC
    printf("\nSeu IMC eh: %.2f\n", imc);
    printf("IMC ideal estimado: %.2f\n", imcIdeal);

    // ==== Escolha do objetivo ====
    printf("\nEscolha seu objetivo:\n");
    printf("1 - Perder peso\n");
    printf("2 - Ganhar massa muscular\n");
    printf("Opcao: ");
    scanf("%d", &objetivo);

    if (objetivo != 1 && objetivo != 2) {
        printf("Objetivo invalido.\n");
        return 1;
    }

    // ==== Cálculo da TMB (Taxa Metabólica Basal) ====
    float altura_cm = altura * 100;
    if (sexo == 1) {
        tmb = 10 * peso + 6.25 * altura_cm - 5 * idade + 5;
    } else {
        tmb = 10 * peso + 6.25 * altura_cm - 5 * idade - 161;
    }

    // ==== Cálculo das Calorias Recomendadas ====
    if (objetivo == 1) {
        caloriasRecomendadas = tmb - 500; // Déficit calórico
    } else {
        caloriasRecomendadas = tmb + 300; // Superávit calórico
    }

    // ==== Recomendações baseadas no objetivo e IMC ====
    printf("\nRecomendacoes:\n");
    if (objetivo == 1) {
        printf("Objetivo: Perda de peso\n");
        if (imc <= imcIdeal - 1)
            printf("Atencao: Voce ja esta abaixo do IMC ideal.\n");
        printf("Recomenda-se uma dieta com deficit calorico.\n");
    } else {
        printf("Objetivo: Ganho de massa muscular\n");
        if (imc >= imcIdeal + 2)
            printf("Atencao: IMC elevado. Avalie antes o emagrecimento.\n");
        printf("Recomenda-se uma dieta com superavit calorico.\n");
    }

    // ==== Resultados finais ====
    printf("TMB estimada: %.2f kcal/dia\n", tmb);
    printf("Calorias recomendadas por dia: %.2f kcal\n", caloriasRecomendadas);

    return 0;
}
