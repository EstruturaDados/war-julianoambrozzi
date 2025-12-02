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
// Definido valores fixos para o número de territórios, tamanho nome e cor.
#define MAX_TERRITORIOS 3
#define TAM_NOME 30
#define TAM_COR 10

// --- Estrutura de Dados ---
// Definida a struct com nome de território, contendo seu nome, a cor do exército e o número de tropas.
struct territorio{
    char nome[TAM_NOME];
    char cor[TAM_COR];
    int numTropas;
};

// Aqui eu fiz o uso de uma função para limpar o buffer de entrada,
//utilizei baseado a orientação da profesora Deisy Albuquerque,
//para evitar possiveis problemas com o scanf.
void limparBufferEntrada(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- Função Principal (main) ---
int main() {
    struct territorio mapa[MAX_TERRITORIOS];
    
    printf("===============================================================\n");
    printf("Olá, a seguir vamos cadastrar os 5 territórios iniciais do jogo\n");
    printf("===============================================================\n");

    //Aqui foi utilizado o "for" junto com as variáveis para definir quantas vezes o codigo vai executar.
    for(int i=0; i < MAX_TERRITORIOS; i++){
        printf("Cadastrando o território %d\n", i + 1);
        printf("Digite o nome do território: ");
        fgets(mapa[i].nome, TAM_NOME, stdin);

        printf("Digite uma cor para o território (Ex: Azul, Vermelho): ");
        fgets(mapa[i].cor, TAM_COR, stdin);

        printf("Digite o numero de tropas do território: ");
        scanf("%d", &mapa[i].numTropas);

        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0';
        mapa[i].cor[strcspn(mapa[i].cor, "\n\n")] = '\0';
        limparBufferEntrada();
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
    for (int i = 0; i < MAX_TERRITORIOS; i++) {
        printf("%d.", i + 1);
        printf(" %s", mapa[i].nome);
        printf(" (Exercito %s,", mapa[i].cor);
        printf(" Tropas: %d)\n\n", mapa[i].numTropas);
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
