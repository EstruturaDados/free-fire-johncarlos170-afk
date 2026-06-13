#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_ITEN 30
#define MAX_STR_TIPO 20

#define TAM_MAX 10 //define o numero maximo de itens na lista





struct iten{
    char dados[MAX_STR_ITEN];//matriz 30linhas
    char tipo[MAX_STR_TIPO];
    int quantidade;
    
    
};


int valor=0;
char* texto[MAX_STR_ITEN];


void inserirLista(struct iten *mochila){
    if (valor == TAM_MAX){
        printf("mochila cheia\n");
        return;
    }else{
     printf("Adicionar novo iten:");
     fgets(mochila[valor].dados,MAX_STR_ITEN,stdin);
     printf("Tipo do iten(arma,municao,cura,etc.):");
     fgets(mochila[valor].tipo,MAX_STR_TIPO,stdin);
     printf("Digite a quantidade:");
     scanf("%d",&mochila[valor].quantidade);

     printf("iten adicionado na mochila\n");

     valor++;
  
    }
}

void removerIten(struct iten *mochila,char* texto){
    int i, pos = -1;
    printf("Digite o nome do item que deseja remover:");
    fgets(texto,MAX_STR_ITEN,stdin);

    for(i=0; i< valor; i++){
        if (strcmp(mochila[i].dados,texto)==0){
        pos =i;
        break;
  }
 }
 if (pos == -1){
    printf("Erro iten %s nao encontrado\n",texto);
    return;
 }
 for(i=pos;i<valor-1;i++){
    strcpy(mochila[i].dados,mochila[i+1].dados);
 }
 valor--;
 printf("iten removido com sucesso\n");


}

void listariten(struct iten *mochila){

    if(valor==0){
        printf("lista vazia\n");
    return; }
              printf("Itens na mochila\n");
    for (int i=0; i< valor; i++){
        
        printf("------------------------------------------\n");
        printf(" Nome: %s \n", mochila[i].dados);
        printf("Tipo:%s \n",mochila[i].tipo);
        printf("quantidade: %d\n",mochila[i].quantidade);
        printf("------------------------------------------\n");
    }

}
void  limparBufferEntrada(){
  int c;
  while ((c = getchar()) != '\n' && c != EOF);

}


int main(){

struct iten *mochila;
mochila = (struct iten *) calloc(TAM_MAX, sizeof(struct iten));
int opcao;
do{
    printf("===============================\n");
    printf("   MOCHILA DE SOBREVIVENCIA\n");
    printf("===============================\n");
    printf("Itens da Mochila: %d/10\n",valor);
    printf("\n");

    printf("1. Adicionar Iten\n");
    printf("2. Remover Iten\n");
    printf("3. Listar Itens na mochila\n");
    printf("0. Sair\n");
    printf("----------------------------------\n");
    printf("Escolha uma opcao:");
    scanf("%d",&opcao);
    limparBufferEntrada();

    switch(opcao){
        case 1:
         
        inserirLista(mochila);
        break;
        case 2:
          removerIten(mochila, texto);
        break;
        case 3:
        listariten(mochila);
        break;
        case 0:
        printf("Saindo do sistema\n");
        break;
    }

}while(opcao!=0);

free(mochila);
printf("Memoria liberada");

return 0;

}
