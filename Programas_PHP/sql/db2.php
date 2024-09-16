<?php

// configuração do banco de dados
$host = "localhost";
$dbname = "livro";
$username = "root";
$password = "";

// criar conexão com banco de dados
$conn = mysqli_connect($host, $username, $password);

// seleciona banco de dados ativo
mysqli_select_db($conn, $dbname);

// consulta
$query = "SELECT id, nome, nacionalidade FROM autores";

// envia consulta ao banco de dados
$result = mysqli_query($conn, $query);

if ($result) {
    // percorre resultados
    while ($row = mysqli_fetch_assoc($result)) {
        echo ($row["id"]."-".$row["nome"]."-".$row["nacionalidade"]."\n");
    }
}

mysqli_close($conn);