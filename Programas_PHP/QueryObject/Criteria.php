<?php

// carrega as classes necessárias
include_once "TExpression.class.php";
include_once "TCriteria.class.php";
include_once "TFilter.class.php";

// aqui vemos um exemplo do critério utilizando o operador OR
// a idade deve ser menor que 16 anose maior que 60 anos

$criteria = new TCriteria;

$criteria->Add(new TFilter('idade','<', 16), TExpression::OR_OPERATOR);
$criteria->Add(new TFilter('idade', '>', 60), TExpression::OR_OPERATOR);

echo $criteria->dump();
echo "\n";

// aqui vemos um exemplo do criterio utilizando o operador lógico AND
// juntamente com os operadores de conjunto IN (dentro do conjunto) e
// NOT IN (fora do conjunto)
// a idade deve ser estar dentro do conjunto (24,25,26) e deve estar fora do conjunto (10)

$criteria = new TCriteria;

$criteria->Add(new TFilter('idade', 'IN', array(24,25,26)));
$criteria->Add(new TFilter('idade', 'NOT IN', array(10)));

echo $criteria->dump();
echo "\n";

// aqui vemos um exemplo de critério utilizando o operador de comparação
// o nome deve iniciar por "pedro" ou deve iniciar por "maria"

$criteria = new TCriteria;

$criteria->Add(new TFilter('nome', 'like', 'pedro%'), TExpression::OR_OPERATOR);
$criteria->Add(new TFilter('nome', 'like', 'maria%'), TExpression::OR_OPERATOR);

echo $criteria->dump();
echo "\n";

// aqui vemos um exemplo de critério utilizando os operadores "=" e IS NOT
// neste caso o telefone não pode conter o valor nulo(IS NOT NULL)
// e o genero deve ser feminino(sexo = 'F')

$criteria = new TCriteria;

$criteria->Add(new TFilter('telefone', 'IS NOT', NULL));
$criteria->Add(new TFilter('sexo', '=', 'F'));

echo $criteria->dump();
echo "\n";

// aqui vemos o uso dos operadores de comparação IN e NOT IN juntamente
// com conjuntos de strings. nesse caso a UF deve estar entre (RS, SC, PR)
// não deve estar entre (AC, PI)

$criteria = new TCriteria;

$criteria->Add(new TFilter('UF', 'IN', array('RS','SC','PR')));
$criteria->Add(new TFilter('UF', 'NOT IN', array('AC','PI')));

echo $criteria->dump();
echo "\n";

// neste caso temos o uso de um critério completo
// o primeiro critério aponta para o sexo = 'F' (sexo feminino) e idade > 18

$criteria1 = new TCriteria;

$criteria1->Add(new TFilter('sexo', '=', 'F'));
$criteria1->Add(new TFilter('idade', '>', 18));

// o segundo critério aponta para o sexo = 'M'
// e idade menor que 16

$criteria2 = new TCriteria;

$criteria2->Add(new TFilter('sexo', '=', 'M'));
$criteria2->Add(new TFilter('idade', '<', 16));

// agora juntamos os dois criterios utilizando o operador lógico OR
// o resultado deve conter "mulheres maiores de 18 anos" ou "homens menores que 16"

$criteria = new TCriteria;

$criteria->Add($criteria1, TExpression::OR_OPERATOR);
$criteria->Add($criteria2, TExpression::OR_OPERATOR);

echo $criteria->dump();
echo "\n";