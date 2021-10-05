## get_next_line

A função get_next_line retorna a linha que acabou de ser lida por nosso programa, incluindo, caso seja possível, a quebra de linha '\n'.
Para tal, devemos buscar em nosso FileDescriptor, durante a totalidade de nosso BUFFER_SIZE a quebra de linha '\n' ou o final de nossa string '\0'.
O retorno do get_next_line deverá ser a última linha lida da string de nosso fd. Vale ressaltar a importância de antecipar condições de erro, estejam eslas inseridas em nosso fd, ou em nosso BUFFER_SIZE.

Protótipo da função get_next_line:
```
char  *get_next_line(int fd)
```



### get_next_line_utils

As funções da libft modificadas que deverão ser utilizadas durante a concepção do programa são: strjoin, strlen e strchr.
Outras três funções são de extrema importância para a execução do projeto, sendo elas:

ft_read_line

> função responsável por retornar uma parte da string de nosso fd, sendo está, a linha lida naquele momento


ft_save

> o restante da string de nosso fd que não foi retornado deverá ser armazenado em um ponteiro estático, para que assim todas as linhas sejam retornadas


ft_get_line

> função responsável exclusivamente por armazenar memória e localizar em nosso BUFFER_SIZE a linha que será lida na string de nosso fd



### get_next_line conceitos

BUFFER_SIZE

> BUFFER_SIZE nada mais é que um armazenamento temporário que armazena em sua totalidade as informações para ele fornecidas


FileDescriptor

> o fd, como o próprio nome sugere, é o arquivo de input e/ou output de nosso programa, sendo ele o responsável por informar o conteúdo que deve ser lido durante o gnl


read

> a função read retorna o número de bytes lidos em fd durante a totalidade de nosso BUFFER



### get_next_line tester

Para testar seu gnl é recomendável utilizar o  tester do usuário Tripouille ou o main abaixo:
```
#include <stdio.h>
#include <fcntl.h>

int    main(void)
{
    char    *line;
    int        i;
//  int        fd1;
    int        fd2;
//  int        fd3;

//  fd1 = open("test.txt", O_RDONLY);
    fd2 = open("test2.txt", O_RDONLY);
//  fd3 = open("test3.txt", O_RDONLY);
    i = 1;
    while (i < 7)
    {
//      line = get_next_line(fd1);
//      printf("line [%02d] test1: %s", i, line);
//      free(line);
        line = get_next_line(fd2);
        printf("line [%02d] test2: %s", i, line);
//      free(line);
//      line = get_next_line(fd3);
//      printf("line [%02d] test2: %s", i, line);
        free(line);
        i++;
    }
//  close(fd1);
    close(fd2);
//  close(fd3);
    return (0);
}
```




##### CRÉDITOS
MCoscia
Matheus Coscia        / / designer gráfico
