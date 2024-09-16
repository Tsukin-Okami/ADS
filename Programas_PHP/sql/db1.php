<?php

// configuração do banco de dados
$host = "localhost";
$dbname = "livro";
$username = "root";
$password = "";

// criar conexão com banco de dados
//$conn = mysqli_connect($host, $username, $password, $dbname);
$conn = new mysqli($host, $username, $password, $dbname);

// verifica se houve erro na conexão
if ($conn->connect_error) {
    die("Falha na conexão".$conn->connect_error);
}
echo("Conexão realizada com sucesso\n");

// inserção de dados
$sql = "INSERT INTO autores (nome, nacionalidade, dataNascimento) VALUES ('Machado de Assis', 'Brasil', '1839-06-21')";

// executar a instrução e verificar o erro
if ($conn->query($sql) === true) {
    echo("Dados inseridos");
} else {
    echo("falha ao inserir dados".$conn->error);
}

// fecha a conexão
$conn->close();