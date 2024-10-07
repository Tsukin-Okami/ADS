<?php

// arquivo para teste de funcionamento da classe TSqlInsert.class

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

// cria uma instrução de INSERT
$sql = new TSqlInsert;

// define o nome da entidade
$sql->setEntity('aluno');

// atribui valor para cada coluna
$sql->setRowData('id', 3);
$sql->setRowData('nome', 'Pedro Cardoso');
$sql->setRowData('fone', '(88)4444-7777');
$sql->setRowData('nascimento', '1985-12-06');
$sql->setRowData('sexo', 'M');
$sql->setRowData('serie', '4');
$sql->setRowData('mensalidade', 280.40);

// processa a instrução SQL
echo $sql->getInstruction();
echo "\n";