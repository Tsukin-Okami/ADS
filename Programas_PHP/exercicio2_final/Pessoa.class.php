<?php

abstract class Pessoa {
    public string $nome;
    public $cpf;
    public string $endereco;
    public $telefone;

    function __construct($nome, $cpf, $endereco, $telefone) {
        $this->nome = $nome;
        $this->cpf = $cpf;
        $this->endereco = $endereco;
        $this->telefone = $telefone;
    }

    function __destruct() {
        echo("O objeto {$this->nome} foi destruido.\n");
    }
    /*
    function cadastrar($nome, $cpf, $endereco, $telefone) {
        $this->nome = $nome;
        $this->cpf = $cpf;
        $this->endereco = $endereco;
        $this->telefone = $telefone;
    }*/

    function alterarTelefone($telefone) {
        $this->telefone = $telefone;
    }

    function alterarEndereco($endereco) {
        $this->endereco = $endereco;
    }
}