
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
*declaração de constantes para o programa no final do tempo de execução.
*/

#define ERRO 0
#define OK 1
/**
*underflow será causado quando o número nos pixeis for menor que 0, já ques estamos usando números do tipo com unsigned.
*/
#define UNDERFLOW 2

/**
*struct dos pixels.
*/
struct cor{
	unsigned char red, green, blue;
	int color;
};

typedef enum cores_pixeis { red, green, blue }colors;

/**
*struct posição da matriz.
*/
struct posMatriz {
	unsigned int x;
	unsigned int y;
	struct posMatriz *Mat;
};
/**
*struct de armazenamento das informações para a imagem.
*/
struct Dados {
	int quant;
	struct posMatriz *top;
};

struct Dados *criadata (int *result){
	struct Dados *dado;
	dado = (struct Dados *) malloc (sizeof(struct Dados));
	if(dado == NULL) *result = ERRO;
	else{
		dado->top = NULL;
		dado->quant = 0;
		*result = OK;
	}
	return dado;
}

void jogarfundo(int x, int y, struct Dados *dado, int *result){
	struct posMatriz *posMat = (struct posMatriz *)malloc(sizeof(struct posMatriz));
	if(posMat == NULL) *result = ERRO;
	else{
		posMat->x;
		posMat->y;
		if(dado->top == NULL){
			posMat->Mat = NULL;
			dado->top = posMat;
		} else {
			posMat->Mat = dado->top;
			dado->top = posMat;
		}
		dado->quant++;
		*result = OK;
	}
}

void devolver(struct Dados *dado, struct posMatriz *posMat, int *result){
    struct posMatriz *auxiliar;
    if(dado->top == NULL){
    	*result = UNDERFLOW;
	} else {
		auxiliar = dado->top;
		posMat->x = auxiliar->x;
		posMat->y = auxiliar->y;
		
		dado->top = auxiliar->Mat;
		dado->quant--;
		free(auxiliar);
	}
}



/**
*função cria dados para o armazenamento.
*/
struct Dados *criadata (int *result);

/**
*funcoes para o armazenamento da matriz.
*/
void jogarfundo(int x, int y, struct Dados *dado, int *result);
void devolver(struct Dados *dado, struct posMatriz *posMat, int *result);

/**
*analisa a matriz e seus elementos.
*/
//void verificar(struct cor **img, int i, int j, int lin, int col, struct Dados *dado);

int main(){
	/**
	*criando a leitura do arquivo e chamando as variaveis para cada struct.
	*/
	FILE *arquivo;
	char farq[30];
	
	\param farq vetor para a leitura da imagem pronta.
	char chave[3], c;
	int i, j, col, lin, max255;
	struct cor **img;
	unsigned char red, green, blue, fred, fblue, fgreen;
	\param linha posição i da matriz.
	\param coluna posição j da matriz.
	int linha, coluna;
	long int pos;
	int cont = 0;
	
	struct Dados *dado;
	struct posMatriz posMat;
	int resulta;
	
	/**
	*chamando um repositório.
	*/
	dado = criadata(&resulta);
	
	/**
	*verificando o arquivo.
	*/
	printf("DIGITE O NOME DO ARQUIVO NO FORMATO PPM: ");
	scanf("%s", farq);
	
	/**
	*abrindo o arquivo.
	*/
	arquivo=fopen(farq, "rb");
	if(arquivo==NULL){
		printf("Erro para abrir o arquivo %s\n", farq);
		return 0;
	}

/**
*verificando se o arquivo é PPM.
*/
fscanf(arquivo,"%s", chave);
if (strcmp(chave,"P3") !=0){
	printf("Arquivo não é PPM\n");
	fclose(arquivo);
	return 0;
}

/**
*olhando o número de linhas e colunas, junto com o número dos pixeis.
*/
fscanf(arquivo,"%d %d %d", &col, &lin, &max255);
fscanf(arquivo, "%c", &c);

linha = lin;
coluna = col;

/**
*alocação dinâmica da matriz para alocar a matriz zerada na memória.
*/
img=(struct cor**) calloc(linha,sizeof(struct cor*));

for (j=0; j<linha;j++){
	img[j]=calloc(coluna,sizeof(struct cor));
}

/**
*preenchendo a matriz com os dados dos pixeis RGB.
*/
for(i=0;i<lin;i++){
	for(j=0;j<col;j++){
		fscanf(arquivo, "%c%c%c", &img[i][j].red, &img[i][j].green, &img[i][j].blue);
	}
}
fclose(arquivo);

/**
*locais do fundo da matriz na imagem com o RGB.
*/
fred = img[0][0].red;
fgreen = img[0][0].green;
fblue = img[0][0].blue;


/**
*analisa a matriz.
*/
for(i=0;i<lin;i++){
	for(j=0;j<col;j++){
		/**
		*comparação dos pixeis diferentes do fundo e assim ele marca com 1 caso ja tenha passado pelo fundo.
		*/
		if(((img[i][j].red!=fred) || (img[i][j].green!=fgreen) || (img[i][j].blue!=fblue)) &&(img[i][j].color!=1)){
		
		
		img[i][j].color = 1;
		
		/**
		*passa a matriz e o armazenamento das informações em dado na struct dados.
		*/
		//verificar(img, i, j, lin, col, dado);
		
	}
		while(dado->quant>0){
			/**
			*se houver elementos no armazenamento em dado, devolvendo o resultado da posição na matriz.
			*/
			devolver (dado, &posMat, &resulta);
			/**
			*verifica o vetor nas posições x e y no último elemento incluso em dado.
			*/
			//verificar(img, posMat.x, posMat.y, lin, col, dado);
		}
		/**
		*quando sair da parte do while na função de devolver, a contagem será iniciada para dizer o número de imagens.
		*/
		cont++;
	}
}

\param cont teste de pixeis presentes na imagem.
printf("Quantidade de pixeis = %d", cont);

return 0;

}
