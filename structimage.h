#ifndef structs_h 
#define structs_h

//! Struct do usuário para o input.
/*! Recebe os comandos de cada linha input.*/
typedef struct entrada_t
{
    char nome_entrada[10]; /*!< nome da primitiva. */  
    int qtdentrada; /*!< quantidade de entrada passados na primitiva. */  
    int entrada[30]; /*!< entrada da primitiva. */  
    char estradastring[30]; /*!< Parêmetros em String da primitiva*/  
    
}entrada;

//! Struct da imagem criada.
/*! Armazena os pixels da imagem, cor usada na primitiva, tamanho, nome */
typedef struct  image_t
{
    int ***matrizimg; /*!< vetor tridimensional de pixels. */  
    int alturaimg; /*!< altura da imagem. */  
    int larguraimg; /*!< largura da imagem. */  
    int cor_img[3]; /*!< cor atual da imagem, para uso nas primitivas. */  
    char name_image[21]; /*!< nome do arquivo da imagem. */  
    
}image;

#endif
