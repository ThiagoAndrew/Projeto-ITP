/* referencias: 
https://www.inf.pucrs.br/~pinho/PRGBAIXONIVEL/Trabalhos/T1-2016-2/T1-2016-2.html
http://linguagemc.com.br/constantes-em-c-usando-define/
https://www.ime.usp.br/~pf/algoritmos/aulas/io.html
https://pt.wikibooks.org/wiki/Programar_em_C/Entrada_e_sa%C3%ADda_em_arquivos
https://www.youtube.com/watch?v=BNIW_dcB3uY&t=212s
https://www.youtube.com/results?search_query=Gera%C3%A7%C3%A3o+de+imagens+PPM
https://www.youtube.com/watch?v=O5lqpxZQP-Y&t=137s
*/



#include "StructsIniciais.h"
#include "Funcs.h"
#include "PrimiGraphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Recebe a imagem e os comandos vindo do arquivo do Usuário, chamando a 
função com a imagem a ser modificada */
void leitura(entrada *digita_inicial, entrada *digita_final, imagem *img){


    if(strcmp(digita_inicial->nome_entrada, "save") == 0){

        save(img, digita_inicial->entradastring);
    }

    else if(strcmp(digita_inicial->nome_entrada, "image") == 0){

        image(img, digita_inicial->entrance);   
    }

    else if(strcmp(digita_inicial->nome_entrada, "color") == 0){

        color(img, digita_inicial->entrance);
    }

    else if(strcmp(digita_inicial->nome_entrada, "clear") == 0){

        clear(img,digita_inicial->entrance);
    }

    else if(strcmp(digita_inicial->nome_entrada, "line") == 0){

        line(img, digita_inicial->entrance);
    }

    else if(strcmp(digita_inicial->nome_entrada, "open") == 0){

        open(img, digita_inicial->entradastring);
    }

    else if(strcmp(digita_inicial->nome_entrada, "polygon") == 0){

        polygon(img, *digita_inicial);
    }

    else if(strcmp(digita_inicial->nome_entrada, "rect") == 0){

        rect(img, digita_inicial->entrance);
    }

    else if(strcmp(digita_inicial->nome_entrada, "circle") == 0){

        circle(img, digita_inicial->entrance);
    }

    else if(strcmp(digita_inicial->nome_entrada, "fill") == 0){

        fill(img, digita_inicial->entrance);
    }

    else if(strcmp(digita_inicial->nome_entrada, "repeat-line") == 0){

        repeat_line(img, digita_inicial->entrance, digita_final);
    }

    else if(strcmp(digita_inicial->nome_entrada, "copy-polygon") == 0){

        copy_polygon(img, digita_inicial->entrance, digita_final);
    }

    else if(strcmp(digita_inicial->nome_entrada, "repeat-polygon") == 0){

        repeat_polygon(img, digita_inicial->entrance, digita_final);
    }

}


/* Lê o arquivo de entradas, criando uma struct de entrada que é passado 
para a função que faz a leitura juntamente com uma instância da imagem*/
void compila(char name_arq[]){
//alocar_matriz == aloc_mat
    imagem img = aloc_mat();
    entrada instrucao_inicial;
    entrada instrucao_final;

    strcpy(instrucao_final.nome_entrada, "vazio");

    strcpy(img.nome_image, "test.ppm");

    FILE *file;
    file = fopen(name_arq, "r");

    char texto[50]; 
    char entradas[50][50];
    char nome_entrada[50];
    int entrance[30];
    int qtdentrada = 0;

    //limpa os vetores
    for (int i = 0; i < 30; ++i)
    {
        entrance[i] = -1;
    }

    for (int i = 0; i < 49; ++i)
    {   
        texto[i] = ' ';
        strcpy(entradas[i], " ");
    }
    texto[49] = ' ';
    strcpy(entradas[49], " ");


    if(file == NULL){

        printf("Arquivo não foi localizado\n");

    } else {

        while(fgets(texto, 50, file) != NULL){

            qtdentrada = 0;
            split(texto, " ", entradas);

            strcpy(nome_entrada, entradas[0]);

            strcpy(instrucao_inicial.nome_entrada, nome_entrada);

            if(strcmp(nome_entrada, "open") == 0 || strcmp(nome_entrada, "save") == 0 ){

                strcpy(instrucao_inicial.entradastring, entradas[1]);
            }

            // separando os comandos
            for (int i = 0; i < 29; ++i)
            {
                //converte a string vindo de entradas para o vetor de inteiros "parametros"
                sscanf(entradas[i + 1], "%d", &entrance[i]);
            }

            for (int i = 0; i < 30; ++i)
            {
                if(entrance[i] == -1){
                    break;
                }

                else{
                    qtdentrada++;
                }
            }

            instrucao_inicial.qtdentrada = qtdentrada;

            // limpa o vetor de instrução da struct
            for (int i = 0; i < 30; ++i)
            {
               instrucao_inicial.entrance[i] = -1;
            }

            //copiar os parâmetros extraídos para o vetor de parâmetros
            for (int i = 0; i < 10; ++i)
            {
               instrucao_inicial.entrance[i] = entrance[i];
            }
            
            leitura(&instrucao_inicial, &instrucao_final, &img);


            //preenche a struct com a entrada atual após executá-lo, servindo como um histórico

            if(strcmp(nome_entrada, "line") == 0 || strcmp(nome_entrada, "polygon") == 0){

                strcpy(instrucao_final.nome_entrada, nome_entrada);

                instrucao_final.qtdentrada = qtdentrada;

                // limpa o vetor de instrução da struct
                for (int i = 0; i < 30; ++i)
                {
                   instrucao_final.entrance[i] = -1;
                }

                //copiar os parâmetros extraídos para o vetor de parâmetros
                for (int i = 0; i < 10; ++i)
                {
                   instrucao_final.entrance[i] = entrance[i];
                }

            }

            //limpa os vetores para guardar novos valores
            for (int i = 0; i < 30; ++i)
            {
                entrance[i] = -1;
            }

            for (int i = 0; i < 49; ++i)
            {   
                texto[i] = ' ';
                strcpy(entradas[i], " ");
            }
            texto[49] = ' ';
            strcpy(entradas[49], " ");

        }
        
        fclose(file);
//desaloc_mat desaloca a matriz
        desaloc_mat(&img);
    }
}
