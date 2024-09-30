# Davi Campos Ribeiro 

## Arquivos

### calc.c e calc.h

Neste arquivo se encontra as funções responsaveis pela aproximação do pi, além do calculo dos erros e contagem de iterações e flops

### common.c e common.h

Aqui se encontra a definição da estrutura que guarda os resultados e as funções que operam nela, estes arquivos permite a comunicação entre o calc e o pi.c

### pi.c 

Neste se encontra as chamadas para fazer as funcionalidades requeridas  

# Limitações

A partir do valor de 1e-15, as aproximações utilizadas no cálculo deixam de progredir, o limite de precisão estabelecido pelo valor de entrada (threshold) é atingido. Isso ocorre porque o resultado gerado é automaticamente arredondado para zero, o que faz com que o cálculo seja interrompido. Em outras palavras, o sistema não consegue representar com precisão valores tão pequenos após esse ponto, levando à cessação das operações.
