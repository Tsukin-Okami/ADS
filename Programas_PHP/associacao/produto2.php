<?php

class Produto
{
    private $codigo;
    public $nome;
    protected $quantidade;
    public $fornecedor;

    public function __construct($codigo, $nome, $quantidade, $fornecedor) {
        $this->codigo = $codigo;
        $this->nome = $nome;
        $this->quantidade = $quantidade;
        $this->fornecedor = $fornecedor;
    }

    public function __destruct()
    {
        //echo "\n" . $this->nome . " foi destruido.";
        return;
    }

    // getter
    public function __get($name)
    {
        return $this->$name;
    }

    // setter
    public function __set($name, $value)
    {
        $this->$name = $value;
    }
}

class Fornecedor
{
    private $codigo;
    public $nome;
    protected $razao; // razao social

    public function __construct($codigo, $nome, $razao)
    {
        $this->codigo = $codigo;
        $this->nome = $nome;
        $this->razao = $razao;
    }

    public function __destruct() 
    {
        //echo "\n" . $this->nome . " foi destruido.";
        return;
    }

    // getter

    public function __get($name)
    {
        return $this->$name;
    }

    // setter

    public function __set($name, $value)
    {
        $this->$name = $value;
    }
}

// execute

$fornecedor = new Fornecedor(1, "Alimentos LTDA", "Trazendo alegria para as familias!");
$produto = new Produto(21, "Tomate", 1, $fornecedor);

// exibe informações do produto e do fornecedor

echo "Produto: " . $produto->__get("nome") . "\n";
echo "Quantidade: " . $produto->__get("quantidade") . "\n";

echo "Fornecedor: " . $produto->__get("fornecedor")->__get("nome") . "\n";
echo "Razao Social: " . $produto->__get("fornecedor")->__get("razao") . "\n";

// modifica informações do produto e do fornecedor

$produto->__set("nome", "Big Potato");
$produto->__set("quantidade",5);

$novofornecedor = new Fornecedor(2, "Miata Auto Restaurantes", "Servindo os impossíveis!");

$produto->__set("fornecedor", $novofornecedor);

// exibe informações do produto e do fornecedor atualizado

echo "\n\tProduto atualizado\n\n";

echo "Produto: " . $produto->__get("nome") . "\n";
echo "Quantidade: " . $produto->__get("quantidade") . "\n";

echo "Fornecedor: " . $produto->__get("fornecedor")->__get("nome") . "\n";
echo "Razao Social: " . $produto->__get("fornecedor")->__get("razao") . "\n";