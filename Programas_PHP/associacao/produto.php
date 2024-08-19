<?php

class Fornecedor
{
    public int $codigo;
    public string $razao;
    public string $endereco;
    public string $cidade;

    public function __construct($codigo, $razao, $endereco, $cidade)
    {
        $this->codigo = $codigo;
        $this->razao = $razao;
        $this->endereco = $endereco;
        $this->cidade = $cidade;
    }
}

class Produto 
{
    public int $codigo;
    public string $descricao;
    public float $preco;
    public int $quantidade;
    public $fornecedor;

    public function __construct($codigo, $descricao, $preco, $fornecedor)
    {
        $this->codigo = $codigo;
        $this->descricao = $descricao;
        $this->preco = $preco;
        $this->quantidade = 1;
        $this->fornecedor = $fornecedor;
    }
}

$fornecedor = new Fornecedor(
    848, 
    "Bom Gosto Alimentos LTDA", 
    "Rua Ipiranga", 
    "Poços de Caldas"
);

$produto = new Produto(
    462,
    "Doce de Pessego",
    1.24,
    $fornecedor
);

echo "\tProduto:\n";
echo "Codigo: {$produto->codigo} \n";
echo "Descricao: {$produto->descricao} \n";

echo "\tFornecedor:\n";
echo "Codigo: {$produto->fornecedor->codigo} \n";
echo "Razao Social: {$produto->fornecedor->razao} \n";
