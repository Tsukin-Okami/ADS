<?php

// arquivo para teste de funcionamento da classe TConnection.class

/**
 * Função autoload()
 * carrega uma classe quando ela é necessária, ou seja, quando ela é instanciada pela primeira vez
*/

spl_autoload_register(function ($classe) {
    if (file_exists("{$classe}.class.php")) {
        include_once "{$classe}.class.php";
    } else if(file_exists("../CompositePattern/{$classe}.class.php")) {
        include_once "../CompositePattern/{$classe}.class.php";
    }
});

// cria a instrução de SELECT
$sql = new TSqlSelect;

// define o nome da entidade
$sql->setEntity('famosos');

// acrescenta colunas a consulta
$sql->addColumn('codigo');
$sql->addColumn('nome');

// crio o critério de seleção
$criteria = new TCriteria;

// obtem a pessoa código "1"
$criteria->add(new TFilter('codigo', '=', '1'));

// atribui o critério de seleção
$sql->setCriteria($criteria);

// abre conexão com o banco de dados my_livro(mysql)
try {
    $conn = TConnection::open("my_livro");

    // executa a instrução SQL
    $result = $conn->query($sql->getInstruction());

    if ($result) {
        $row = $result->fetch(PDO::FETCH_ASSOC);
        // exibe os resultados
        if ($row) {
            echo $row['codigo'] . '-' . $row['nome'] . "<br>\n";
            //print_r($row); 
        } else {
            echo "sem dados";
        }
    }

    // fecha a conexão
    $conn = null;

} catch (PDOException $e) {
    throw $e;
}
/*
// abre conexão com a base pg_livro
try {
    $conn = TConnection::open("pg_livro");

    // executa a instrução SQL
    $result = $conn->query($sql->getInstruction());
    
    if ($result) {
        $row = $result->fetch(PDO::FETCH_ASSOC);
        // exibe os resultados
        echo $row['codigo'] . '-' . $row['nome'] . "<br>\n";
    }

    // fecha a conexão
    $conn = null;

} catch (PDOException $e) {
    throw $e;
}
*/