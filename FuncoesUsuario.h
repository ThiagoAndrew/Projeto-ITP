/*! \Arquivo */ 

#ifndef FuncoesUsuario_h 
#define FuncoesUsuario_h

//! Função Compila, utilizada no main do arquivo "Usuario.c".
/*!
	\param name_arq recebe uma string correspondente ao nome do arquivo de instruções do usuário.
*/
void compila(char name_arq[]);

//! Função de leitura dos comandos.
/*!
	Essa função recebe do usuário as informações que ele pretende criar na imagem, lendo cada linha de comando 
  das primitivas e chama a função da primitiva correspondente com os parâmetros necessários.
  
	\param digita_inicial recebe um ponteiro de uma struct comando com as informações da instrução a ser executada.
	\param digita_final recebe um ponteiro de uma struct comando com a ultima primitiva "salva".
 
  *Obs* "salva":  digita_final somente armazena uma primitiva quando corresponde a line ou polygon, 
	para uso das funções repeat_line e repeat_polygon
	
  \param picture recebe um ponteiro de uma struct image com a imagem a ser modificada pelas primitivas
*/

void leitura(entrada *digita_inicial, comando *digita_final, image *img);

#endif
