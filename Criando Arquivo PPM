#include <stdlib.h>
#include <stdio.h>

/**
*@author Thiago Andrew e Samuel Dumaresq.
*@since nov 2019.
*@version 1.0.
*criação do arquivo ppm.
*/

/**
*criando um arquivo (imagem) no formato ppm.
*/
int main()
{
  printf("image: ");
  int dimx, dimy;
  scanf("%d %d", &dimx, &dimy);
  
  printf("save: ");
  char arq[50];
  /**
  *iniciação da criação do arquivo
  */
  
  \param arq criação do nome do arquivo.
  
  for (int i = 0; i < 50; ++i)
   {
    arq[i] = '\0';
   }

  scanf("%s", arq);

  
  int i, j;
  FILE *img = fopen(arq, "wb"); /* b - binary mode */
  fprintf(img, "P3\n%d %d\n255\n", dimx, dimy);
  \param img abre o nome do arquivo.
  for (j = 0; j < dimy; j++)
  {
    for (i = 0; i < dimx; i++)
    {
      \param color vetor de cores da variavel.
      static unsigned char color[3];
      color[0] = 255;  //red
      color[1] = 255;  //green 
      color[2] = 255;  //blue 
      fprintf(img, "%d ", color[0]);
      fprintf(img, "%d ", color[1]);
      fprintf(img, "%d ", color[2]);
    }
  }
  fclose(img);
  return EXIT_SUCCESS;
}
