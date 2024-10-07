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

// cria o critério de seleção de dados
$criteria = new TCriteria;
$criteria->Add(new TFilter('nome', 'like', 'maria%'));
$criteria->Add(new TFilter('cidade', 'like', 'Porto%'));

// define o ordenamento da consulta
$criteria->setProperty('orde', 'nome');

// cria a instrução de SELECT
$sql = new TSqlSelect;

// define o nome da entidade
$sql->setEntity('aluno');

// acrescenta colunas a consulta
$sql->addColumn('nome');
$sql->addColumn('fone');

// define o critério de seleção dos dados
$sql->setCriteria($criteria);

// processa a instrução SQL
echo $sql->getInstruction();
echo "<br>\n";