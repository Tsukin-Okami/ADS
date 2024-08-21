<?php

class Cesta
{
    private array $itens;

    // <<

    public function __construct()
    {
        $this->itens = [];
    }

    public function __destruct()
    {
        return;
    }

    // <<

    public function __get($name)
    {
        return $this->$name;
    }

    public function __set($name, $value)
    {
        $this->$name = $value;
    }

    // >>

    public function adicionarItem(Produto $produto)
    {
        $this->itens[] = $produto;
    }

    public function exibeLista()
    {
        echo "\tLista:\n";
        foreach ($this->itens as $item)
        {
            echo "Produto: " . $item->__get("descricao") . "\n";
            echo "\tPreço: R\$ " . $item->__get("preco") . "\n";
            echo "\tQuantidade: " . $item->__get("quantidade") . "\n";
        }
    }

    public function calculaTotal()
    {
        $total = 0;

        foreach ($this->itens as $item) {
            $total += $item->__get("preco") * $item->__get("quantidade");
        }

        return $total;
    }
}

class Produto
{
    public int $codigo;
    public string $descricao;
    public float $preco;
    public int $quantidade;
    public $fornecedor;

    public function __construct($codigo, $descricao, $preco, $quantidade, $fornecedor)
    {
        $this->codigo = $codigo;
        $this->descricao = $descricao;
        $this->preco = $preco;
        $this->quantidade = $quantidade;
        $this->fornecedor = $fornecedor;
    }

    public function __destruct()
    {
        return;
    }

    public function __get($name)
    {
        return $this->$name;
    }

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

    // <<

    public function __construct($codigo, $nome, $razao)
    {
        $this->codigo = $codigo;
        $this->nome = $nome;
        $this->razao = $razao;
    }

    public function __destruct() 
    {
        return;
    }

    // <<

    public function __get($name)
    {
        return $this->$name;
    }

    public function __set($name, $value)
    {
        $this->$name = $value;
    }
}

$fornecedor = new Fornecedor(007, "James", "MI6");

$produtos = [
    new Produto(1,"Ameixa",1.40, 10, $fornecedor),
    new Produto(2,"Morango",2.87, 5, $fornecedor),
    new Produto(3,"Tamarindo",99.99, 1, $fornecedor),
    new Produto(4,"Mirtilo",10.00, 45, $fornecedor)
];

$cesta = new Cesta;

foreach ($produtos as $produto) {
    $cesta->adicionarItem($produto);
}

$cesta->exibeLista();

echo "\nPreço total da cesta: R\$ " . $cesta->calculaTotal() . "\n";

/*
    nl2br = new line to break

    echo nl2br("BAG\nBAG\nBAG\n",false);

    BAG<br>
    BAG<br>
    BAG<br>
*/

//print_r($cesta);