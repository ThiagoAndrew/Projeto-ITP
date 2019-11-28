#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "StructsIniciais.h"

//Divide uma string em um vetor de strings usando um delimitador (delim)
//str_in entrada
void split(char str_in[], char delim[], char retorno[][50]){
 
    int tam_delim = 0;
    int indice_str_atual = 0; 
    int indice_retorna = 0; 
 
    while(delim[tam_delim] != '\0'){
        tam_delim++;
    }

    int i = 0;
    while(str_in[i] != '\0'){

        if(str_in[i] == delim[0]){
 
            int correspondente = 1;
            int loops = 0;
            for (int j = 1; j < tam_delim; ++j)
            {
                loops++;
 
                if(str_in[i + j] != delim[j] ){
 
                    correspondente = 0;
                    break;
                }
            }

            if(correspondente == 1){
 
                retorno[indice_retorna][indice_str_atual] = '\0';
                i += tam_delim -1; 
                indice_retorna++; 
                indice_str_atual = 0; 
 
            } else {
 
                for (int l = i; l <= i + loops; ++l)
                {
                    retorno[indice_retorna][indice_str_atual] = str_in[l];
                    indice_str_atual++;
                }
                i += loops;
            }
 
        } else {
 
            retorno[indice_retorna][indice_str_atual] = str_in[i];
            indice_str_atual++;
        }
        i++;
    }
    retorno[indice_retorna][indice_str_atual] = '\0'; 
}
//in entrada da variavel.
int numero(char in){

    int i = 0;
    int indice = 0;
    int numbers[] = {'1','2','3','4','5','6','7','8','9','0'};

    for (int i = 0; i < 10; ++i)
    {
       if(in == numbers[i]){
            return 1;
       }
    }
    return 0;
}

//Retira os espaços em branco e caracteres que não são alfanuméricos ou em branco
//out saída do resultado.
void clean_str_arq(char in[], char out[]){

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
//desaloc_mat desalocar a matriz
void desaloc_mat(imagem *img){

    for (int i = 0; i < img->alturaimg; ++i)
    {
        for (int j = 0; j < img->larguraimg; ++j)
        {
            free(img->matrizimg[i][j]);
                  
        }
    }

    for (int i = 0; i < img->alturaimg; ++i)
    {
        free(img->matrizimg[i]);
    }

    free(img->matrizimg);
}
//aloc_mat aloca matriz
imagem aloc_mat(){

    imagem img;

    img.matrizimg = malloc(sizeof(int**) * 1);
    img.matrizimg[0] = malloc(sizeof(int*) * 1);
    img.matrizimg[0][0] = malloc(sizeof(int) * 3); 

    return img;
}

//Realoca a matriz que representa a imagem na memória de acordo com resolução desejada
//realocar_matriz == realoc_mat
void realoc_mat(imagem *img){

    
    img->matrizimg = realloc(img->matrizimg, sizeof(int**) * img->alturaimg);
  
    for (int i = 0; i < img->alturaimg; ++i)
    {
        img->matrizimg[i] = realloc(img->matrizimg[i], sizeof(int*) * img->larguraimg);
    }

    for (int i = 0; i < img->alturaimg; ++i)
    {
        for (int j = 0; j < img->larguraimg; ++j)
        {
            img->matrizimg[i][j] = realloc(img->matrizimg[i][j], sizeof(int) * 3); 
        }
    }
    
}
