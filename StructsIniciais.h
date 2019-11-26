#ifndef StructsIniciais_h 
#define StructsIniciais_h

//! Struct do usuário para o input.
/*! Recebe os comandos de cada linha input.*/
typedef struct entrada_t
{
    char nome_entrada[30]; /*!< nome da primitiva. */  
    int qtdentrada; /*!< quantidade de entrada passados na primitiva. */  
    int entrada[30]; /*!< entrada da primitiva. */  
    char estradastring[30]; /*!< Parâmetros em String da primitiva*/  
    
}entrada;

//! Struct da imagem criada.
/*! Armazena os pixels da imagem, cor usada na primitiva, tamanho, nome */
typedef struct  image_t
{
    int ***matrizimg; /*!< vetor tridimensional de pixels. */  
    int alturaimg; /*!< altura da imagem. */  
    int larguraimg; /*!< largura da imagem. */  
    int cor_img[3]; /*!< cor atual da imagem, para uso nas primitivas. */  
    char nome_image[21]; /*!< nome do arquivo da imagem. */  
    
}image;

#endif
