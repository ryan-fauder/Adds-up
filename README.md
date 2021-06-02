# Projeto

- Nome do Projeto: Adds Up

* Desenvolvedores:
  * Ryan Fernandes Auder Lopes
  * Pedro Augusto Serafim Belo


## Descrição
<h1> AHH </h1>
&ensp;&ensp;O projeto consiste em um programa que simula um tocador de músicas. O usuário pode criar/inserir novas músicas, acessá-las e visualizar suas informações. O programa também permite criar playlists - onde as músicas serão armazenadas - e ordenar as músicas que estão contidas nela conforme os critérios do usuário. Uma música pode ser tocada individualmente, e há também a opção de tocar uma playlist inteira. Ademais, é possível alterar o nome de uma música ou playlist, bem como remover uma música de uma playlist ou deletar uma playlist inteira.
	
&ensp;&ensp;A estrutura de dados escolhida foi a lista duplamente encadeada, e o método de ordenação adotado foi o Merge Sort. Todas as estutruturas são armazenadas em um único arquivo binário.
<br>

## Comandos

- Comando para compilação: 
```
gcc *.c -lm -o main
```
- Comandos do usuário:
```java
./main -help → //Exibe todos comandos possíveis.

./main -create (nome) → //Cria uma nova playlist.

./main -view → //Exibe todas as playlists.

./main -view (playlist) → //Exibe informações da playlist escolhida e permite visualizar informações das músicas contidas nela.

./main -add (playlist) → //Cria e insere uma nova música na playlist escolhida.
//(Caso o nome não seja especificado, será exibido antes um menu com todas as playlists)

./main -play (playlist) → //Toca as músicas da playlist escolhida.
//(Caso o nome não seja especificado, será exibido antes um menu com todas as playlists)

./main -playsong (playlist) → //Aparece uma interface com as músicas da playlist escolhida para selecionar uma a ser tocada.
// (Caso o nome não seja especificado, será exibido antes um menu com todas as playlists)

./main -sort (playlist) → //Exibe as opções de ordenamento de uma playlist.
//(Caso o nome não seja especificado, será exibido antes um menu com todas as playlists)

./main -update (playlist) → //Mostra uma lista de músicas para alterar os nomes dessas.

./main -update (playlist) (novo_nome) → //Atualiza o nome da playlist escolhida.

./main -remsong (playlist) → //Aparece uma interface para escolher a música a ser removida da playlist escolhida.
//(Caso o nome não seja especificado, será exibido antes um menu com todas as playlists)

./main -delete (playlist) → //Deleta a playlist escolhida.
//(Caso o nome não seja especificado, será exibido antes um menu com todas as playlists)
```
<br>

## Observação

&ensp;&ensp;O arquivo Data.bin armazena todos os registros de playlists. Ele foi entregue 
com informações cadastradas. Então, caso seja necessário para limpar os registros, 
basta excluir o arquivo. O arquivo será gerado novamente ao executar o programa.