// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO - NÍVEL NOVATO
// ============================================================================
//        
// ============================================================================
//
// Bibliotecas necessárias para o desenvolvimento do exercício
#include <stdio.h>
#include <string.h>

// --- Constantes Globais ---
// Definem valores fixos para o número de territórios, missões e tamanho máximo de strings, facilitando a manutenção.
#define MAX_TERRITORIOS 5
#define TAM_NOME 30
#define TAM_COR 10

// --- Estrutura de Dados ---
// Define a estrutura para um território, contendo seu nome, a cor do exército que o domina e o número de tropas.
struct territorio{
    char nome[TAM_NOME];
    char cor[TAM_COR];
    int numTropas;
};

// Caso necessário, uma função para limpar o buffer de entrada
void limparBufferEntrada(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- Função Principal (main) ---
int main() {
    struct territorio mapa[MAX_TERRITORIOS];
    
    printf("===============================================================\n");
    printf("Olá, a seguir vamos cadastrar os 5 territorios iniciais do jogo\n");
    printf("===============================================================\n");

    for(int i=0; i < MAX_TERRITORIOS; i++){
        printf("Cadastrando o territorio %d\n", i + 1);
        printf("Digite o nome do territorio: ");
        fgets(mapa[i].nome, TAM_NOME, stdin);

        printf("Digite uma cor para o territorio (Ex: Azul, Vermelho): ");
        fgets(mapa[i].cor, TAM_COR, stdin);

        printf("Digite o numero de tropas do territorio: ");
        scanf("%d", &mapa[i].numTropas);

        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0';
        mapa[i].cor[strcspn(mapa[i].cor, "\n\n")] = '\0';
        limparBufferEntrada();
    }

    printf("=========================================\n");
    printf("---TERRITORIOS CADASTRADOS COM SUCESSO--- \n\n");
    printf("=========================================\n");

    printf("=========================================\n");
    printf("---LISTAGEM DOS TERRITORIOS DO MAPA---\n\n");
    printf("=========================================\n");

    for (int i = 0; i < MAX_TERRITORIOS; i++) {
        printf("Território %d:\n", i + 1);
        printf("Nome: %s\n", mapa[i].nome);
        printf("Cor: %s\n", mapa[i].cor);
        printf("Tropas: %d\n\n", mapa[i].numTropas);
    }
    
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
