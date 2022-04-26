#include <stdlib.h>
    #include <stdio.h>

    struct fila {
        char nome [30];
        char dado;
        struct fila *proximoPtr;    
    };
    typedef struct fila Fila;
    typedef Fila *PtrFila;
    void imprimeFila (PtrFila atualPtr);
    int ehVazia(PtrFila headPtr );
    //void dequeue(PtrFila *headPtr, PtrFila *tailPtr );
    void enqueue(PtrFila *headPtr, PtrFila *tailPtr, char nome[30]);

    int main(){
            PtrFila headPtr = NULL;
            PtrFila tailPtr = NULL;
        for ( ; ; ){
            char linha[1024];
            puts("Escreva Nomes Separados por Virgula");
            fgets(linha, 1024 , stdin);
            char item;
            char* tok;
            char* tmp = strdup(linha);

            tok=strtok(tmp, ",");
            int cont=0;
            while (tok != NULL) {
                cont++;
                enqueue( &headPtr, &tailPtr, tok);

                tok = strtok (NULL, ",");
            }
            imprimeFila(headPtr);
            //dequeue (&headPtr, &tailPtr); A função que não está funcionando

        }
    }
    /*void dequeue(PtrFila *headPtr, PtrFila *tailPtr ) {
        char aux;
        PtrFila tempPtr;

        aux = ( *headPtr )->aux;
        tempPtr = *headPtr; 
        *headPtr = ( *headPtr )->proximoPtr; 

        if ( *headPtr == NULL ) {
            *tailPtr = NULL; 
        } 

        free( tempPtr );
        imprimeFila(headPtr);
    } */

    int ehVazia( PtrFila headPtr ){
        return headPtr == NULL;
    }

    void imprimeFila( PtrFila atualPtr ){
        PtrFila inicioPtr;
        inicioPtr=atualPtr;
        if ( atualPtr == NULL ) {
            puts( "Fila esta vazia.\n" );
        } 

            atualPtr=inicioPtr;
            while ( atualPtr != NULL ) {
                printf( "%s --> ", atualPtr->nome );
                atualPtr = atualPtr->proximoPtr;
            } 
            puts( "NULL\n" );

        } 

    void enqueue( PtrFila *headPtr, PtrFila *tailPtr, char nome[30]){

        char * novalinha = strchr(nome, '\n');
        if (novalinha)
            *novalinha = '\0';  

        PtrFila newPtr; 
        newPtr=malloc(sizeof(Fila));

        if ( newPtr != NULL ) { 
            newPtr->dado = nome;
            newPtr->proximoPtr = NULL;

            strcpy( newPtr->nome,nome);


            if ( ehVazia( *headPtr ) ) {
                *headPtr = newPtr;
            } 
            else {
                ( *tailPtr )->proximoPtr = newPtr;
            } 

            *tailPtr = newPtr;
        } 
        else {
            printf( "%c nao foi inserido. Memoria nao foi disponibilizada.\n");
        } 
    } 