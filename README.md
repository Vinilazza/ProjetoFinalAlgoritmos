# ProjetoFinalAlgoritmos

    O projeto foi realizado na primeira fase de ciencia da computação, foi desenvolvido um algoritmo que resolva um caca-palavras em C.
  O projeto foi realizado na primeira fase de ciencia da computação, foi desenvolvido um algoritmo que resolva um caca-palavras em C.
  O desenvolvimento do projeto foi feito com a seguindo ideia é fornecida uma string com os valores da matriz que forma um caca-palavras,
para resolver o caca-palavras foi necessario criar funções que verifique onde está as palavras forncecidas pelo usuario, então o usuario pode digitar qual a palavra que ele deseja procurar e o algoritmo dara um resultado fornecendo em quais coordenadas o usuario encontra essa palavra, um exemplo disso é quando nos testamos em uma matriz que já esta definida no codigo, se digitarmos no terminal a palavra "SAPATO" ele deve retornar o valor que está localizado na matriz.


![WhatsApp Image 2023-06-29 at 19 20 05](https://github.com/Vinilazza/ProjetoFinalAlgoritmos/assets/108952051/68af52aa-e5c4-451d-9468-92aa919ff5d5)![WhatsApp Image 2023-06-29 at 19 22 39](https://github.com/Vinilazza/ProjetoFinalAlgoritmos/assets/108952051/cb7a5c70-5730-41c1-98be-d778a3a634de)

 Nessas duas imagens mostra o resultado. A matriz ela começa em 0, então se analizarmos a matriz o resultado está correto, pois a primeira letra está no 0 e termina no 5.
	Para chegarmos nesse resultado foi necessario fazer 8 verificações, sendo elas horizontais, verticais e diagonais, as palavras podem ser encontradas da direita para a esquerda e da esquerda para a direita, foi prototipado essas funções, que estão presente depois da Main().
	O projeto conta um menu, caso o usuario digite 1, ele mostrara a matriz que foi colocada na String, caso a resposta seja 2, ele faz a verificação de cada palavra que usuario digitar, 
as verificações foram feitas a partir da primeira letra encontrada, caso seja encontrada ele continua executando o codigo até que a palavra seja encontrada, então foi definido um lenght para a quantidade de letras que a palavra tem, sendo assim se a palavra estiver na verificação e estiver completa com todas suas letras o codigo vai parar de rodar e retornar o valor obtido atravez de uma Struct chamada Data, que nela consta quais são os locais que foram o começo da linha chamado no codigo de Li, achando tambem a linha final chamado de Lf, tambem achando a coluna inicial Ci,coluna final Cf e tambem conta com uma variavel Achou que se a palavra for encontrada ele ira mostrar para o usuario, a variavel Achou ela tem a função de um booleano que quando o resultado dela foi igual a 1 ela retornara os valores obtidos Li,Lf,Ci,Cf.
	Essa variavel é usada na função localizaPalavra() que serve para chamar todas as verificações e assim quando for encontrado parar de rodar o codigo, caso seja encontrado ele vai printar para o usuario a informação de onde está essa palavra.
	O codigo é bem simples, foi usado struct para armazenar os valores obtidos caso a palavra seja encontrada, void para criar as funções necessarias para verificar cada coluna e cada linha, foi tambem criado duas funções para montar a matriz e outra para mostrar a matriz caso seja preciso, outra função que foi criada foi o struture() que serve para criar o menu, com as opções do usuario escolher, podendo futuramente ser acrescentado mais opções para o usuario.
	Assim resolvendo um caca-palavras que o usuario definir.


 Autor: Vinicius Lazarotto
