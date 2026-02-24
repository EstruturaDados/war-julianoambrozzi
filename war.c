// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO - NÍVEL NOVATO
// ============================================================================
//        
// ============================================================================
//
// Bibliotecas necessárias para o desenvolvimento do exercício
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// === Constantes Globais ===
// Definido valores fixos para tamanho de nome e cor.
// #define MAX_TERRITORIOS 5 - aqui conforme solicitado retirado valor fixo.
#define TAM_NOME 30
#define TAM_COR 10
#define QTD_TERRITORIOS 5

// === Estrutura de Dados ===
// Definida a struct com nome de território, contendo seu nome, a cor do exército e o número de tropas.
typedef struct {
    char nome[TAM_NOME];
    char cor[TAM_COR];
    int numTropas;
} Territorio;

//Aqui eu fiz o uso de uma função para limpar o buffer de entrada,
//utilizei baseado a orientação da profesora Deisy Albuquerque,
//para evitar possiveis problemas com o scanf.
void limparBufferEntrada(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//Função de ataque e desefa do jogo
void atacar(Territorio* atacante, Territorio* defensor) {
    int dadoAtacante = (rand() % 6) + 1;
    int dadoDefensor = (rand() % 6) + 1;

    printf("\n=== BATALHA ENTRE %s e %s ===\n", atacante->nome, defensor->nome);
    printf("Dado do atacante: %d\n", dadoAtacante);
    printf("Dado do defensor: %d\n", dadoDefensor);
    
    //Caso o atacante vença a rodada ele ganha 1 tropa do defensor   
    if (dadoAtacante >= dadoDefensor) {
        printf("=== O atacante venceu a rodada! ===\n");

        defensor->numTropas -= 1; //Defensor perde 1 tropa
        atacante->numTropas += 1; //Atacante ganha 1 tropa do defensor

        //Caso o defensor eprca todas as tropas, ele perde seu território para o atacante
        if (defensor->numTropas <= 0) {
            printf("=== O defensor perdeu o território! ===\n");
            strcpy(defensor->cor, atacante->cor);
            defensor->numTropas = 1; //Território conquistado começa com 1 tropa
        }
    }
    
    //Caso o atacante perca a rodada    
    else{
        printf("=== O defensor resistiu ao ataque! ===\n");

        atacante->numTropas -= 1;

        //caso o atacante perca todas tropas, ele perde o território para o defensor
        if (atacante->numTropas <= 0) {
            printf(">> O atacante perdeu o território ao fracassar no ataque!\n");
            strcpy(atacante->cor, defensor->cor);
            atacante->numTropas = 1;
        }
    }
}

// Meu Principal
void menuPrincipal() {
    printf("\n=========================\n");
    printf("       MENU PRINCIPAL    \n");
    printf("=========================\n");
    printf("1 - Atacar\n");
    printf("2 - Verificar Missao\n");
    printf("0 - Sair\n");
    printf("=========================\n");
    printf("Escolha uma opcao: ");
}

//Função que inicializa automaticamente os territórios do jogo
void inicializarMapa(Territorio* mapa) {

    strcpy(mapa[0].nome, "Brasil");
    strcpy(mapa[0].cor, "Azul");
    mapa[0].numTropas = 5;

    strcpy(mapa[1].nome, "Argentina");
    strcpy(mapa[1].cor, "Vermelho");
    mapa[1].numTropas = 5;

    strcpy(mapa[2].nome, "Chile");
    strcpy(mapa[2].cor, "Verde");
    mapa[2].numTropas = 5;

    strcpy(mapa[3].nome, "Uruguai");
    strcpy(mapa[3].cor, "Azul");
    mapa[3].numTropas = 5;

    strcpy(mapa[4].nome, "Paraguai");
    strcpy(mapa[4].cor, "Verde");
    mapa[4].numTropas = 5;
}

//Função para mostrar estado atual do mapa
void mostrarMapa(const Territorio* mapa, int qtdTerritorios) {
    printf("\n=== ESTADO ATUAL DO MAPA ===\n");
    for (int i = 0; i < qtdTerritorios; i++) {
        printf("%d. %s (Exercito %s, Tropas: %d)\n",
               i + 1,
               mapa[i].nome,
               mapa[i].cor,
               mapa[i].numTropas);
    }
}

// === Função Principal (main) ===
int main() {
    //Inicialização para números aleatórios de dados de batalha e missões
    srand(time(NULL));

    // Quantidade fixa de territórios
    const int qtdTerritorios = 5;

    //Alocação dinâmica do mapa usando calloc
    Territorio* mapa = calloc(qtdTerritorios, sizeof(Territorio));
    if (mapa == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    // Inicializa automaticamente os territórios
    inicializarTerritorios(mapa, qtdTerritorios);

    // Sorteia a missão do jogador
    int missao = sortearMissao();

    int opcao;
    do {
        //Exibe o menu principal
        menuPrincipal();
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao) {
            case 1:
                //Executa a fase de ataque
                faseAtaque(mapa, qtdTerritorios);
                break;

            case 2:
                //Verifica se a missão foi cumprida
                if (verificarMissao(mapa, qtdTerritorios, missao)) {
                    printf("\n🎉 PARABENS! Missao cumprida com sucesso!\n");
                    opcao = 0; // Encerra o jogo após vitória
                }
                break;

            case 0:
                printf("\nEncerrando o jogo...\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    // Libera a memória alocada
    free(mapa);

    return 0;
}

// --- Implementação das Funções ---

// alocarMapa():
// Aloca dinamicamente a memória para o vetor de territórios usando calloc.
// Retorna um ponteiro para a memória alocada ou NULL em caso de falha.

// inicializarTerritorios():
// Preenche os dados iniciais de cada território no mapa (nome, cor do exército, número de tropas).
// Esta função modifica o mapa passado por referência (ponteiro).

// liberarMemoria():
// Libera a memória previamente alocada para o mapa usando free.

// exibirMenuPrincipal():
// Imprime na tela o menu de ações disponíveis para o jogador.

// exibirMapa():
// Mostra o estado atual de todos os territórios no mapa, formatado como uma tabela.
// Usa 'const' para garantir que a função apenas leia os dados do mapa, sem modificá-los.

// exibirMissao():
// Exibe a descrição da missão atual do jogador com base no ID da missão sorteada.

// faseDeAtaque():
// Gerencia a interface para a ação de ataque, solicitando ao jogador os territórios de origem e destino.
// Chama a função simularAtaque() para executar a lógica da batalha.

// simularAtaque():
// Executa a lógica de uma batalha entre dois territórios.
// Realiza validações, rola os dados, compara os resultados e atualiza o número de tropas.
// Se um território for conquistado, atualiza seu dono e move uma tropa.

// sortearMissao():
// Sorteia e retorna um ID de missão aleatório para o jogador.

// verificarVitoria():
// Verifica se o jogador cumpriu os requisitos de sua missão atual.
// Implementa a lógica para cada tipo de missão (destruir um exército ou conquistar um número de territórios).
// Retorna 1 (verdadeiro) se a missão foi cumprida, e 0 (falso) caso contrário.

// limparBufferEntrada():
// Função utilitária para limpar o buffer de entrada do teclado (stdin), evitando problemas com leituras consecutivas de scanf e getchar.
