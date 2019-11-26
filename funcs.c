#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "structs.h"

//Divide uma string em um vetor de strings usando um delimitador (delim)
//str_in == string_entrada
void split(char str_in[], char delim[], char retorno[][50]){
 
    int tam_delim = 0;
    int indice_str_atual = 0; 
    int indice_retorno = 0; 
 
    while(delim[tam_delim] != '\0'){
        tam_delim++;
    }

    int i = 0;
    while(str_in[i] != '\0'){

        if(str_in[i] == delim[0]){
 
            int corresponde = 1;
            int loops = 0;
            for (int j = 1; j < tam_delim; ++j)
            {
                loops++;
 
                if(str_in[i + j] != delim[j] ){
 
                    corresponde = 0;
                    break;
                }
            }

            if(corresponde == 1){
 
                retorno[indice_retorno][indice_str_atual] = '\0';
                i += tam_delim -1; 
                indice_retorno++; 
                indice_str_atual = 0; 
 
            } else {
 
                for (int l = i; l <= i + loops; ++l)
                {
                    retorno[indice_retorno][indice_str_atual] = str_in[l];
                    indice_str_atual++;
                }
                i += loops;
            }
 
        } else {
 
            retorno[indice_retorno][indice_str_atual] = str_in[i];
            indice_str_atual++;
        }
        i++;
    }
    retorno[indice_retorno][indice_str_atual] = '\0'; 
}
//in == entrada
int numero(char in){

    int i = 0;
    int indice = 0;
    int numeros[] = {'1','2','3','4','5','6','7','8','9','0'};

    for (int i = 0; i < 10; ++i)
    {
       if(in == numeros[i]){
            return 1;
       }
    }
    return 0;
}

//Retira os espaços em branco e caracteres que não são alfanuméricos ou em branco
//saída == out
void limpar_string_arquivo(char in[], char out[]){

    int i = 0;
    while(1){

        if(isalpha(in[i]) || in[i] == '.' || in[i] == '_' || numero(in[i])){

            out[i] = in[i];

        } else if(in[i] == '\0'){

            break;
        }

        i++;
    }
}

//Limpa a matriz que representa a imagem na memória
//desalocar_matriz == desaloc_mat
void desaloc_mat(imagem *img){

    //puts("desalocando a matriz");
    for (int i = 0; i < img->altura; ++i)
    {
        for (int j = 0; j < img->largura; ++j)
        {
            free(img->matriz[i][j]);
                  
        }
    }

    for (int i = 0; i < img->altura; ++i)
    {
        free(img->matriz[i]);
    }

    free(img->matriz);
}
//alocar_matriz == aloc_mat
imagem aloc_mat(){

    imagem img;

    img.matriz = malloc(sizeof(int**) * 1);
    img.matriz[0] = malloc(sizeof(int*) * 1);
    img.matriz[0][0] = malloc(sizeof(int) * 3); 

    return img;
}

//Realoca a matriz que representa a imagem na memória de acordo com resolução desejada
//realocar_matriz == realoc_mat
void realoc_mat(imagem *img){

    //printf("Alt: %d\n", img->altura);
    //printf("Larg: %d\n", img->largura);
    //puts("realocando...");
    img->matriz = realloc(img->matriz, sizeof(int**) * img->altura);
  
    for (int i = 0; i < img->altura; ++i)
    {
        img->matriz[i] = realloc(img->matriz[i], sizeof(int*) * img->largura);
    }

    for (int i = 0; i < img->altura; ++i)
    {
        for (int j = 0; j < img->largura; ++j)
        {
            img->matriz[i][j] = realloc(img->matriz[i][j], sizeof(int) * 3); 
        }
    }
    //puts("realocou");
}
