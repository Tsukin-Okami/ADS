<?php

// configuração do banco de dados
$host = "localhost";
$dbname = "pdo";
$username = "root";
$password = "";

// conexão com dados
try {
    $conn = new PDO("mysql:host=$host;dbname=$dbname", $username, $password);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    echo "Conexão realizada com sucesso\n";
} catch (PDOException $e) {
    echo "Falha na conexão: ".$e->getMessage();
    die();
}

function tabelar(string $title, array $subt, array $val) : void {
    echo $title . ": \n";
    foreach ($subt as $key => $value) {
        echo "\t". $value .": " . $val[$key] . "\n";
    }
}

// transação
try {
    $conn->beginTransaction();

    // modelo de consulta
    $query = "INSERT INTO produtos (nome, prec) VALUES (?, ?)";
    
    // prepara a consulta
    $stmt = $conn->prepare($query);
    $stmt->execute(['uva',2.6]);

    // finaliza as alterações
    $conn->commit();
    echo "sucesso";

} catch(PDOException $err) {
    // volta todas as alterações caso ocorra erro
    $conn->rollBack();
    //echo "Erro: \n\tCódigo: ".$err->getCode() . "\n\tMensagem: ".$err->getMessage() . "\n\tArquivo: ".$err->getFile();
    tabelar("Erro", ["Código", "Mensagem", "Arquivo"], [$err->getCode(), $err->getMessage(), $err->getFile()]);
}

tabelar("Aviso", ["Mensagem"], ["Conexão fechada"]);

// fecha a conexão
$conn = null;