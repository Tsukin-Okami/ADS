<?php

// arquivo para teste de funcionamento da classe TSqlSelect.class

/**
 * Função autoload()
 * carrega uma classe quando ela é necessária, ou seja, quando ela é instanciada pela primeira vez
*/

spl_autoload_register(function ($classe) {
    if (file_exists("{$classe}.class.php")) {
        include_once "{$classe}.class.php";
    }
});

// define o LOCALE do sistema para permitir ponto decimal
setlocale(LC_ALL, "english");

// cria critério de seleção
$criteria1 = new TCriteria;

// seleciona todas as meninas (F) que estão na terceira (3) série
$criteria1->add(new TFilter('sexo', '=', 'F'));
$criteria1->add(new TFilter('serie', '=', '3'));

// seleciona todos os meninos (M) que estão na quarta (4) serie
$criteria2 = new TCriteria;
$criteria2->add(new TFilter('sexo', '=', 'M'));
$criteria2->add(new TFilter('serie', '=', '4'));

// agora juntamos os dois critérios utilizando o operador lógico OR (ou)
// o resultado deve conter meninas da 3ª série ou meninos da 4ª série
$criteria = new TCriteria;
$criteria->add($criteria1, TExpression::OR_OPERATOR);
$criteria->add($criteria2, TExpression::OR_OPERATOR);

// define o ordenamento
$criteria->setProperty('order', 'nome');

// cria a instrução de SELECT
$sql = new TSqlSelect;

// define o nome da entidade
$sql->setEntity('aluno');

// acrescenta todas as colunas a consulta
$sql->addColumn('*');

// define o critério de seleção dos dados
$sql->setCriteria($criteria);

// processa a instrução SQL
echo $sql->getInstruction();
echo "<br>\n";