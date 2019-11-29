# Projeto-ITP
**Autores**

Samuel Dumaresq

Thiago Andrew

**Sobre o Programa**

O programa tem como o seu objetivo trazer ao usuário uma ferramenta para desenvolvimento básico de desenho gráfico. Os desenhos são criados por meio de comandos: save, image, color, clear, line, open, circle, rect, fill, e seus parâmetros, para os casos necessários.

Primeiramente, o usuário deve digitar o tamanho da imagem, e logo em seguida, salvar com o nome do arquivo. Depois de ter criado o nome arquivo, o usuário irá passar o nome do arquivo como PPM para que o programa ( na parte de leitura dos arquivos ) possa achar a imagem e mostrar que foi criada corretamente.

Posteriormente, é necessário fazer o uso do comando "clear" para limpar e mudar as cores na imagem para as cores especificadas cujos parâmetros são os desejáveis para fazer o desenho.

Após isso, o usuário pode salvar o seu projeto utilizando o comando "save", especificando o nome e a extensão ".ppm".

Ademais, há a possibilidade de abrir uma imagem já existente a fim de que possa ser editada a partir do comando "open" e o nome do arquivo com a extensão “.ppm”

Instruções para os comandos presentes que podem ser utilizados:

O comando “color” deve possuir três parâmetros que definirão a cor da forma que será declarada em sequência. O color deve possuir o formato “color 90 104 225”, por exemplo, seguindo o sistema RGB no qual o primeiro parâmetro é a intensidade da cor vermelha, o segundo da cor verde e o terceiro da cor azul.

o comando “fill” como o color deve possuir três parâmetros que definirão a cor desejada, o diferencial do fill é que ele preencherá o interior da “figura” ou o espaço selecionado até os limites da imagem ou de outra figura. O fill possui o formato “fill 0 0 0”, por exemplo.

O comando “line” possui quatro parâmetros sendo eles os pares ordenado que definirão o início e fim da linha. O formato do comando line deve possuir o padrão “line 100 100 200 100”, por exemplo. Contudo, é importante ressaltar que os parâmetros não devem ultrapassar as dimensões totais da imagem.

O comando “polygon” é composto do primeiro parâmetro que deve ser a quantidade de vértices do polígono, os parâmetros seguintes serão os pares ordenados que definem a posição de cada vértice. Dessa maneira, o formato a ser seguido deve ser “polygon 3 0 300 50 300 0 300” com mais parâmetros, tendo em vista que a menor quantidade de vértices para um polígono são três pontos.

O comando “rect” recebe quatro parâmetros, sendo eles o par ordenado onde será desenhado o retângulo e suas dimensões de largura e altura. Assim, o comando terá o seguinte formato “rect 50 110 100 120”, por exemplo.

O comando “circle” possui três parâmetros os quais são o par ordenado e o raio da circunferência. Sendo assim, o padrão a ser seguido pelo usuário deve ser como o exemplificado a seguir “circle 100 120 50”.

O comando “repeat_line” basicamente repete o comando line anterior e os parâmetros são definidos pela quantidade de vezes que a linha será repetida, a distância entres os pares ordenados iniciais e finais que serão repetidos. Portanto, o comando terá o seguinte formato “repeat-line 1 0 50 0 -50”, por exemplo.

O comando “repeat_polygon” recebe como parâmetro a quantidade de vezes que o polígono será repetido e a distância entre eles. Desse modo, o formato a ser seguido deve ser “repeat-polygon 25 5 -5”, por exemplo.

O comando “copy_polygon” mantém as dimensões, ou seja o formato, do polígono chamado anteriormente e o copia para local indicado nos parâmetros. Assim, o comando copy_polygon deve seguir o exemplo a seguir “copy-polygon 100 150”.

Note que existem ações as quais podem ocasionar erros na execução como os exemplos a seguir:

Coordenadas que passem dos limites da imagem, como supracitado no comando “line”, causam erro na execução do programa. Ademais, esse cuidado deve ser seguido para os demais comandos.

Imagens com dimensões grandes pode ocasionar um risco para a execução do programa. tendo em vista que recursos como o comando “fill” utilizam recursão e exigem um grande quantidade de memória.

Além dos fatores anteriores, cuidados devem ser tomados na hora de escrever os comandos no arquivo “input.txt” como por exemplo parâmetros errados, parâmetros a mais ou a menos que o desejado e espaços a mais entre os parâmetros.

**Compilando e Executando o programa**

gcc ExecUsuario.c Funcs.c PrimiGraphics.c Usuario.c -o exec

./exec

assim ele irá compilar e executar.

**Valgrind**

caso tenha o Valgrind na sua máquina ubuntu, use o comanado:

valgrind ./exec

usandoo comando ele irá resultar:

**Terminal de Saída**

==3199== Conditional jump or move depends on uninitialised value(s)
==3199==    at 0x4E94875: _itoa_word (_itoa.c:179)
==3199==    by 0x4E97F0D: vfprintf (vfprintf.c:1642)
==3199==    by 0x4EA0E53: fprintf (fprintf.c:32)
==3199==    by 0x1099B3: save (in /home/machine/Downloads/Projeto-ITP-master/exec)
==3199==    by 0x108A7F: leitura (in /home/machine/Downloads/Projeto-ITP-master/exec)
==3199==    by 0x10910D: compila (in /home/machine/Downloads/Projeto-ITP-master/exec)
==3199==    by 0x10B1AA: main (in /home/machine/Downloads/Projeto-ITP-master/exec)
==3199== 
==3199== Conditional jump or move depends on uninitialised value(s)
==3199==    at 0x4E98014: vfprintf (vfprintf.c:1642)
==3199==    by 0x4EA0E53: fprintf (fprintf.c:32)
==3199==    by 0x1099B3: save (in /home/machine/Downloads/Projeto-ITP-master/exec)
==3199==    by 0x108A7F: leitura (in /home/machine/Downloads/Projeto-ITP-master/exec)
==3199==    by 0x10910D: compila (in /home/machine/Downloads/Projeto-ITP-master/exec)
==3199==    by 0x10B1AA: main (in /home/machine/Downloads/Projeto-ITP-master/exec)
==3199== 
==3199== Conditional jump or move depends on uninitialised value(s)
==3199==    at 0x4E98B4C: vfprintf (vfprintf.c:1642)
==3199==    by 0x4EA0E53: fprintf (fprintf.c:32)
==3199==    by 0x1099B3: save (in /home/machine/Downloads/Projeto-ITP-master/exec)
==3199==    by 0x108A7F: leitura (in /home/machine/Downloads/Projeto-ITP-master/exec)
==3199==    by 0x10910D: compila (in /home/machine/Downloads/Projeto-ITP-master/exec)
==3199==    by 0x10B1AA: main (in /home/machine/Downloads/Projeto-ITP-master/exec)
==3199== 
==3199== 
==3199== HEAP SUMMARY:
==3199==     in use at exit: 0 bytes in 0 blocks
==3199==   total heap usage: 102,728 allocs, 102,728 frees, 2,059,884 bytes allocated
==3199== 
==3199== All heap blocks were freed -- no leaks are possible
==3199== 
==3199== For counts of detected and suppressed errors, rerun with: -v
==3199== Use --track-origins=yes to see where uninitialised values come from
==3199== ERROR SUMMARY: 1619750 errors from 65 contexts (suppressed: 0 from 0)

