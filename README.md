# Sistema Statup Desenvolvimento 2 Periodo

## Exercício envolvendo os conceitos de Estrutura, Vetores e Funções em C.

A Startup de desenvolvimento de software “Tudo Podemos”, em que você trabalha. está em pleno desenvolvimento. Entretanto, a sua área comercial/administrativa está um perfeito Caos. Visando sanar esse problema seu gerente chamou alguns desenvolvedores para criar um programa que controle as receitas, despesas, datas, etc. dos projetos.

Considere que atualmente, a empresa consegue desenvolver simultaneamente no máximo 15 projetos. E para cada projeto as informações administrativas necessária são:

Código do Projeto
Gerente
Data de entrega prevista para o projeto.
Cliente
Despesas associadas com o projeto, sendo as principais:
Salário com Desenvolvedores
Valor pago em Horas extras
Valor pago para o Deslocamento de reuniões
Outros Gastos
Receita do Projeto

PROJETO:

Você e seu Time vão desenvolver este programa de controle. Para tal será necessário criar uma estrutura para armazenar as informações:

Código do Projeto (inteiro de máximo 2 dígitos)
Gerente (cadeia de caracteres com no máximo 50 caracteres). Cada projeto é gerenciado por um único gerente. Um gerente pode gerenciar mais de um projeto
Data de entrega prevista para o projeto. Construa uma estrutura data contendo os campos dia, mês e ano
Cliente (cadeia de caracteres com no máximo 50 caracteres).
Despesas associadas com o projeto. Construa uma estrutura denominada despesa com os seguintes campos:
Salário com Desenvolvedores – um número real
Valor pago em Horas extras – um número real
Valor pago para o Deslocamento de reuniões – um número real
Outros Gastos – um número real
Receita do Projeto – o valor que a empresa receberá ao entregar o projeto - um número real
A partir dessas informações o programa deverá ser apto a informar:

O lucro Total dos projetos em andamento
Quantos projetos estão atrasados
O código do projeto e o nome do gerente do projeto com maior gasto com horas extras
O código do projeto e o nome do gerente com o projeto com maior gasto total
Dado o nome de um gerente imprimir as seguintes informações sobre o(s) projeto(s) que ele está gerenciando
Código do projeto
Cliente
Data prevista de Entrega
Lucro
Dado o nome do cliente imprimir as seguintes informações do projeto
Código do projeto
Gerente
Data prevista de Entrega
Custo Total
O programa deverá ter um menu principal com todas as opções acima disponíveis para que o usuário possa decidir aquela que ele necessite
