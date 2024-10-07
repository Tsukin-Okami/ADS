<?php

// arquivo para teste de funcionamento da classe TSqlUpdate.class

/**
 * Função autoload()
 * carrega uma classe quando ela é necessária, ou seja, quando ela é instanciada pela primeira vez
*/

spl_autoload_register(function ($classe) {
    if (file_exists("{$classe}.class.php")) {
        include_once "{$classe}.class.php";
    }
});

// cria um criterio de seleção de dados
$criteria = new TCriteria;
$criteria->Add(new TFilter('id', '=', 3));

// cria instrução de UPDATE
$sql = new TSqlUpdate;

// define a entidade
$sql->setEntity('aluno');

// atribui o valor de cada coluna
$sql->setRowData('nome', 'Pedro Cardoso da Silva');
$sql->setRowData('rua', 'Machado de Assis');
$sql->setRowData('fone', '(88)5555');

// define o critério da seleção de dados
$sql->setCriteria($criteria);

// processa instrução SQL
echo $sql->getInstruction();
echo "<br>\n";