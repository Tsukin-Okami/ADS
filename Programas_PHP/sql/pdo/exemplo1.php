<?php

// configuração do banco de dados
$host = "localhost";
$database = "livro";
$username = "root";
$password = "";

//$conn = new mysqli($host, $username, $password, $database);

try {
    $conn = new PDO("mysql:host = $host,dbname=$database", $username, $password);

    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRORMODE_EXCEPTION);
    echo "Conexão realizada com sucesso";
}
catch {
    
}