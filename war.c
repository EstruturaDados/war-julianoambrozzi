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
    if (dadoAtacante > dadoDefensor) {
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


// === Função Principal (main) ===
int main() {
    
    printf("===============================================================\n");
    printf("Olá, a seguir vamos cadastrar os territórios iniciais do jogo\n");
    printf("===============================================================\n");

    int qtdTerritorios;
    printf("=====================================\n");
    printf("Quantos territorios deseja cadastrar?\n");
    printf("=====================================\n");
    scanf("%d", &qtdTerritorios);
    limparBufferEntrada(); //limpa o \n do buffer deixado pelo scanf

    //Alocação dinamica da memória
    Territorio* mapa = malloc(qtdTerritorios* sizeof(Territorio));

    if(mapa == NULL){
        printf("Erro ao alocar memoria!\n");
        return 1; //retorna 1 para indicar erro
    }

    //Aqui foi utilizado o "for" junto com as variáveis para definir quantas vezes o codigo vai executar.
    for(int i=0; i < qtdTerritorios; i++){
        printf("Cadastrando o território %d\n", i + 1);
        printf("Digite o nome do território: ");
        fgets(mapa[i].nome, TAM_NOME, stdin);

        printf("Digite uma cor para o território (Ex: Azul, Vermelho): ");
        fgets(mapa[i].cor, TAM_COR, stdin);

        printf("Digite o numero de tropas do território: ");
        scanf("%d", &mapa[i].numTropas);
        limparBufferEntrada();

        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0';
        mapa[i].cor[strcspn(mapa[i].cor, "\n\n")] = '\0';        
    }

    //Fiz o uso da sequencia de alguns printfs para deixar o codigo um pouco mais bonito e melhor de se visualizar.
    printf("=========================================\n");
    printf("---TERRITÓRIOS CADASTRADOS COM SUCESSO---\n");
    printf("=========================================\n\n");

    printf("=========================================\n");
    printf("---LISTAGEM DOS TERRITÓRIOS DO MAPA---\n");
    printf("=========================================\n\n");

    //Nestre trecho do codigo fiz novamente o uso do "for",
    //a fins de facilitar a saida e exibição dos dados, aonde cada vez que o "i" for encrementado em +1,
    //e o laço repetir, vai exibir os dados contidos em cada posição do vetor.
    for (int i = 0; i < qtdTerritorios; i++) {
        printf("%d.", i + 1);
        printf(" %s", mapa[i].nome);
        printf(" (Exercito %s,", mapa[i].cor);
        printf(" Tropas: %d)\n", mapa[i].numTropas);
    }    

    //=== FASE DE ATAQUE ===
    int atacante, defensor;

    while (1) {
        printf("\n====================\n");
        printf("---FASE DE ATAQUE---\n");
        printf("======================\n");

        //Escolher atacante
        printf("Escolha o território ATACANTE de 1 a %d ou 0 para sair: ", qtdTerritorios);
        scanf("%d", &atacante);
        limparBufferEntrada();

        if (atacante == 0) {
            printf("Saindo da fase de ataque...\n");
            break;
        }
        atacante--; //Ajustar para índice

        if (atacante < 0 || atacante >= qtdTerritorios) {
            printf("Opção inválida! Tente novamente.\n");
            continue;
        }

        //Escolher defensor
        printf("Escolha o território DEFENSOR de 1 a %d ou 0 para sair: ", qtdTerritorios);
        scanf("%d", &defensor);
        limparBufferEntrada();

        if (defensor == 0) {
            printf("Saindo da fase de ataque...\n");
            break;
        }
        defensor--; //Ajustar para índice

        if (defensor < 0 || defensor >= qtdTerritorios) {
            printf("Opção inválida! Tente novamente.\n");
            continue;
        }

        if (atacante == defensor) {
            printf("Um território não pode atacar ele mesmo!\n");
            continue;
        }

        // Executar o ataque
        atacar(&mapa[atacante], &mapa[defensor]);

        // Mostrar estado atualizado após o ataque
        printf("\n--- ESTADO ATUAL DO MAPA ---\n");
        for (int i = 0; i < qtdTerritorios; i++) {
        printf("%d.", i + 1);
        printf(" %s", mapa[i].nome);
        printf(" (Exercito %s,", mapa[i].cor);
        printf(" Tropas: %d)\n", mapa[i].numTropas);
        }
    }
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
