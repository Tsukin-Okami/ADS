<?php

/**
 * Função autoload()
 * carrega uma classe quando ela é necessária, ou seja, quando ela é instanciada pela primeira vez
*/

spl_autoload_register(function ($classe) {
    if (file_exists("{$classe}.class.php")) {
        include_once "{$classe}.class.php";
    }
});

try {
    // abre uma transação
    TTransaction::open("my_livro");

    // cria uma instrução de insert
    $sql = new TSqlInsert;

    // define o nome da entidade
    $sql->setEntity('famosos');

    // atribui o valor de cada coluna
    $sql->setRowData('codigo', 8);
    $sql->setRowData('nome', 'Galileu');
    
    // obtem a conexão ativa
    $conn = TTransaction::get();

    // executa a instrução sql
    $result = $conn->query($sql->getInstruction());

    // cria uma instrução UPDATE
    $sql = new TSqlUpdate;

    // define o valor da entidade
    $sql->setEntity('famosos');

    // atribui o valor de cada coluna
    $sql->setRowData('nome', 'Galileu Galilei');

    // cria uma critério de seleção de dados
    $criteria = new TCriteria;

    // obtem a pessoa de codigo "8"
    $criteria->add(new TFilter('codigo', '=', '8'));

    // atribui o criterio de seleção
    $sql->setCriteria($criteria);

    // obtem a conexão ativa
    $conn = TTransaction::get();

    // executa a instrução SQL
    $result = $conn->query($sql->getInstruction());

    // fecha a transação aplicando todas as operações
    TTransaction::close();

} catch (Exception $e) {
    // desfaz operações realizadas durante a transação
    TTransaction::rollback();
    // exibe a mensagem de erro
    throw $e;
}