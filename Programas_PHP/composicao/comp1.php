<?php

class Fornecedor
{
    private int $codigo;
    private string $razao;
    private string $endereco;
    private string $cidade;
    private object $contato;

    public function __construct($codigo, $razao, $endereco, $cidade, $contato)
    {
        $this->codigo = $codigo;
        $this->razao = $razao;
        $this->endereco = $endereco;
        $this->cidade = $cidade;
        // composição
        $this->contato = $contato;
    }
}