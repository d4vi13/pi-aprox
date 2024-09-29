# Davi Campos Ribeiro 

# Limitações

A partir do valor de 1e-17, as aproximações utilizadas no cálculo deixam de progredir, pois após 86 operações, o limite de precisão estabelecido pelo valor de entrada (threshold) é atingido. Isso ocorre porque o resultado gerado é automaticamente arredondado para zero, o que faz com que o cálculo seja interrompido. Em outras palavras, o sistema não consegue representar com precisão valores tão pequenos após esse ponto, levando à cessação das operações.
