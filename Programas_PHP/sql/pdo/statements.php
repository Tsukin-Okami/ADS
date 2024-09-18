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

/*
CREATE TABLE produtos (
	id int NOT NULL PRIMARY KEY,
    nome varchar(255) NOT NULL,
    preco float NOT NULL
)
*/

$nome = ["leite", "pera", "limão"];
$preco = [2.60, 1.20, 4.50];

// query
$sql = "INSERT INTO produtos(nome, preco) VALUES (?, ?)";

// prepara a conexão
$stmt = $conn->prepare($sql);

print_r($stmt);
for ($i=0; $i < 3; $i++) {
    if ($stmt->execute([$nome[$i], $preco[$i]])) {
        echo "dados inseridos com sucesso\n";
    } else {
        echo "Erro ao inserir dados\n";
    }
}

// fecha a conexão
$conn = null;