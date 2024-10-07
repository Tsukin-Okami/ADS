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

// cria seleção de dados
$criteria = new TCriteria();
$criteria->Add(new TFilter('id','=','3'));

// cria instrução de DELETE
$sql = new TSqlDelete;

// define a entidade
$sql->setEntity('aluno');

// define o critério de seleção de dados
$sql->setCriteria($criteria);

// processa a instrução sql
echo $sql->getInstruction();
echo "<br>\n";