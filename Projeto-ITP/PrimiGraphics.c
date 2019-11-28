#include "StructsIniciais.h"
#include "Funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//https://rosettacode.org/wiki/Bitmap/Write_a_PPM_file#C
//Salva a imagem no arquivo de acordo com a matriz de pixels
void save(imagem *img, char name_arq[]){

    FILE *file = fopen(name_arq, "wb");
    fprintf(file, "P3\n%d %d\n255\n", img->larguraimg, img->alturaimg);
    
    for (int i = 0; i < img->alturaimg; ++i)
    {
        for (int j = 0; j < img->larguraimg; ++j)
        {
            for (int z = 0; z < 3; ++z)
            {   
                fprintf(file, "%d ", img->matrizimg[i][j][z]);
            }
        }
    }

    fclose(file); 
}

//https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm#All_cases
//Função para criar uma reta na imagem
void line(imagem *img, int entrance[]) {

    int x0 = entrance[0];
    int x1 = entrance[2];
    int y0 = entrance[1];
    int y1 = entrance[3];
    int err, dy, dx, sx, sy, e2;

    dx = abs(x1 - x0);

    if(x0 < x1){

        sx = 1;

    } else {

        sx = -1;
    }

    dy = abs(y1 - y0) * -1;

    if(y0 < y1){

        sy = 1;

    } else {

        sy = -1;
    }
    
    err = dx+dy;
    while (1){

        for (int i = 0; i < 3; ++i)
        {
           img->matrizimg[y0][x0][i] = img->cor_img[i];
        }

        if (x0==x1 && y0==y1){
            break;
        }

        e2 = 2*err;

        if (e2 >= dy){

            err += dy;
            x0 += sx;
        }

        if (e2 <= dx){
            err += dx;
            y0 += sy;
        }
    }
}

void repeat_line(imagem *img, int entrance[], entrada *digita_final){

    if(strcmp(digita_final->nome_entrada, "line") == 0){

        int quant = entrance[0];
        int delx0 = entrance[1];
        int dely0 = entrance[2];
        int delx1 = entrance[3];
        int dely1 = entrance[4];
        int nova_entrada[4];

        for (int i = 0; i < quant; ++i)
        {   
            nova_entrada[0] = digita_final->entrance[0] + delx0 * (i + 1);
            nova_entrada[1] = digita_final->entrance[1] + dely0 * (i + 1);
            nova_entrada[2] = digita_final->entrance[2] + delx1 * (i + 1);
            nova_entrada[3] = digita_final->entrance[3] + dely1 * (i + 1);
            line(img, nova_entrada);
        }
        
    }
}

//Função para criar uma reta na imagem
void polygon(imagem *img, entrada in){

    int qtd_point = in.entrance[0];
    int ordenY = in.qtdentrada -1;
    int entrance[4];
    int rect[ordenY][4];
    int ind_rect = 0;

    //cria as retas
    for (int i = 0; i < ordenY; i += 2)
    {
        if(i == ordenY - 2) {

            rect[ind_rect][0] = in.entrance[i + 1];
            rect[ind_rect][1] = in.entrance[i + 2];
            rect[ind_rect][2] = in.entrance[1];
            rect[ind_rect][3] = in.entrance[2];

            ind_rect++;
                
        } else {

            rect[ind_rect][0] = in.entrance[i + 1];
            rect[ind_rect][1] = in.entrance[i + 2];
            rect[ind_rect][2] = in.entrance[i + 3];
            rect[ind_rect][3] = in.entrance[i + 4];

            ind_rect++;
        }
    }

    //coloca as retas na imagem.
    for (int i = 0; i <  ind_rect; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {

            entrance[j] = rect[i][j];  

        }

        line(img, entrance);
    }
}

//Repete um polígono definido na linha anterior n vezes com incrementos na posição x e y
void repeat_polygon(imagem *img, int entrance[], entrada *digita_final){

    if(strcmp(digita_final->nome_entrada, "polygon") == 0){

        int quant = entrance[0];
        int delx = entrance[1];
        int dely = entrance[2];
        int ordenY = digita_final->entrance[0] * 2;

        entrada new_polygon = *digita_final;

        for (int i = 0; i < quant; ++i)
        {
            for (int j = 1; j < ordenY + 1; j+=2)
            {
                new_polygon.entrance[j] += delx;
                new_polygon.entrance[j + 1] += dely;
            }

            polygon(img, new_polygon);
        }
    }
}

//Copia o polígono definido na linha anterior para uma nova coordenada
void copy_polygon(imagem *img, int entrance[], entrada *digita_final){

    int distancy_x = entrance[0] - digita_final->entrance[1];
    int distancy_y = entrance[1] - digita_final->entrance[2];
    int points = digita_final->entrance[0];
    int qtdentrada = digita_final->qtdentrada;

    for (int i = 0; i < points * 2; i += 2)
    {
        digita_final->entrance[i + 1] += distancy_x;
        digita_final->entrance[i + 2] += distancy_y;
    }

    polygon(img, *digita_final);
}

//Definindo a cor atual
void color(imagem *img, int entrance[]){
    
    for (int i = 0; i < 3; ++i)
    {
        img->cor_img[i] = entrance[i];
    }
}

//Limpa a imagem deixando todos os pixels com a cor recebida por parâmetro
void clear(imagem *img, int entrance[]){

    for(int i = 0; i < img->alturaimg; i++)
    {
        for (int j = 0; j < img->larguraimg; ++j)
        {   
            img->matrizimg[i][j][0] = entrance[0];
            img->matrizimg[i][j][1] = entrance[1];
            img->matrizimg[i][j][2] = entrance[2];
        }
    }
}

//Criar retângulos
void rect(imagem *img, int entrance[]){

    entrada in;
    in.qtdentrada = 9; 

    in.entrance[0] = 4;
    in.entrance[1] = entrance[0];
    in.entrance[2] = entrance[1];
    in.entrance[3] = entrance[0] + entrance[2];
    in.entrance[4] = entrance[1];
    in.entrance[5] = entrance[0] + entrance[2];
    in.entrance[6] = entrance[1] + entrance[3];
    in.entrance[7] = entrance[0];
    in.entrance[8] = entrance[1] + entrance[3];

    polygon(img, in);
}

//https://rosettacode.org/wiki/Bitmap/Midpoint_circle_algorithm#C
//Criar círculos
void circle(imagem *img, int entrance[]){

    int r = entrance[2];
    int x0 = entrance[0];
    int y0 = entrance[1];
    int f = 1 - r;
    int ddF_x = 0;
    int ddF_y = -2 * r;
    int x = 0;
    int y = r;

    for (int i = 0; i < 3; ++i)
    {
        img->matrizimg[x0][y0 + r][i] = img->cor_img[i];
        img->matrizimg[x0][y0 - r][i] = img->cor_img[i];
        img->matrizimg[x0 + r][y0][i] = img->cor_img[i];
        img->matrizimg[x0 - r][y0][i] = img->cor_img[i];
    }

    while(x < y){

        if(f >= 0){

            y--;
            ddF_y += 2;
            f += ddF_y;
        }

        x++;
        ddF_x += 2;
        f += ddF_x + 1;

        for (int i = 0; i < 3; ++i)
        {
            img->matrizimg[x0 + x][y0 + y][i] = img->cor_img[i];
            img->matrizimg[x0 - x][y0 + y][i] = img->cor_img[i];
            img->matrizimg[x0 + x][y0 - y][i] = img->cor_img[i];
            img->matrizimg[x0 - x][y0 - y][i] = img->cor_img[i];
            img->matrizimg[x0 + y][y0 + x][i] = img->cor_img[i];
            img->matrizimg[x0 - y][y0 + x][i] = img->cor_img[i];
            img->matrizimg[x0 + y][y0 - x][i] = img->cor_img[i];
            img->matrizimg[x0 - y][y0 - x][i] = img->cor_img[i];
        }
    }
}

//Função recursiva adaptada do colega de classe Rodrigo para a execução do fill no preenchimento
void rec_fill(imagem *img, int x, int y, int cor_inicial[]){

    int pixel_validate = 1;

    for (int i = 0; i < 3; ++i)
    {
        if(cor_inicial[i] != img->matrizimg[y][x][i]){

            pixel_validate = 0;
            break;
        }
    }

    if(pixel_validate == 1){

        for (int i = 0; i < 3; ++i)
        {
            img->matrizimg[y][x][i] = img->cor_img[i];
        }

        if(x - 1 >= 0){

            rec_fill(img, x - 1, y, cor_inicial);
        }

        if(x + 1 < img->larguraimg){

            rec_fill(img, x + 1, y, cor_inicial);
        }

        if(y - 1 >= 0){

            rec_fill(img, x, y - 1, cor_inicial);
        }
    
        if(y + 1 < img->alturaimg){

            rec_fill(img, x, y + 1, cor_inicial);
        }
    }
}

// preenchimento de figuras
void fill(imagem *img, int entrance[]){

    int x = entrance[0];
    int y = entrance[1];
    int cor_inicial[3];
    int colorido = 1;

    for (int i = 0; i < 3; ++i)
    {
        cor_inicial[i] = img->matrizimg[y][x][i];
    }

    for (int i = 0; i < 3; ++i)
    {
       if(img->cor_img[i] != img->matrizimg[y][x][i]){

            colorido = 0;
            break;
        }
    }

    if(colorido == 0){

        rec_fill(img, x, y, cor_inicial);  
    } 
}
 
//Abre um arquivo de imagem ppm para edição pelo usuário.
void open(imagem *img, char name_arq[]){

    char texto[15];
    char texto_split[3][50];
    char alturaimg[5];
    char larguraimg[5];
    char name_arq_read[30];
    int qtd_colors;

    for (int i = 0; i < 30; ++i)
    {
        name_arq_read[i] = '\0';
    }

    clean_str_arq(name_arq, name_arq_read);

    FILE *file;
    file = fopen(name_arq_read, "r");

    printf("%s\n",name_arq_read);

    if(file == NULL){

        puts("Arquivo não Localizado");

    } else {

        fgets(texto, 10, file);
        fgets(texto, 10, file);
        
        split(texto, " ", texto_split);
        
        strcpy(alturaimg, texto_split[1]);
        strcpy(larguraimg, texto_split[0]);
        
        strcpy(img->nome_image, name_arq_read);

        sscanf(alturaimg, "%d", &img->alturaimg);
        sscanf(larguraimg, "%d", &img->larguraimg);

        realoc_mat(img);

        qtd_colors = img->alturaimg * img->larguraimg * 3;

        char colors[(qtd_colors + 1) * 12];
        char vector_colors[qtd_colors][50];

        fgets(texto, 15, file);
        fgets(colors, qtd_colors * 4 , file);

        split(colors, " ", vector_colors);

        int ind = 0;
        for (int i = 0; i < img->alturaimg; ++i)
        {
            for (int j = 0; j < img->larguraimg; ++j)
            {
                for (int k = 0; k < 3; ++k)
                {   
                    sscanf(vector_colors[ind], "%d", &img->matrizimg[i][j][k]);
                    ind++;
                }
            }
        }
    }
}

//Define a resolução da imagem criada, adaptado do colega Rodrigo
void image(imagem *img, int entrance[]) {

    img->alturaimg = entrance[1];
    img->larguraimg = entrance[0];
    
    realoc_mat(img);
}
