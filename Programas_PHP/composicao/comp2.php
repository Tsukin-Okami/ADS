<?php

class Funcionario
{
    private int $codigo;
    public string $nome;
    public $setor;
    public string $dataAdmissao;
    public $regime;
    public float $salario;
    private Dependente $dependente;

    // <<

    public function __construct($codigo, $nome, $setor, $dataAdmissao, $regime, $salario, $d_codigo, $d_nome, $d_parentesco)
    {
        $this->codigo = $codigo;
        $this->nome = $nome;
        $this->setor = $setor;
        $this->dataAdmissao = $dataAdmissao;
        $this->regime = $regime;
        $this->salario = $salario;
        //$this->dependente = $dependente;
        $this->dependente = new Dependente($d_codigo, $d_nome, $d_parentesco);
    }

    public function __destruct()
    {
        return;
    }

    // <<

    public function __set($name, $value)
    {
        $this->$name = $value;
    }

    public function __get($name)
    {
        return $this->$name;
    }

    // >>

    public function trocaSalario($salario)
    {
        if (is_float($salario) && $salario > 0) {
            $this->__set("salario", $salario);
        }
    }

    public function trocaSetor($setor)
    {
        $this->__set("setor", $setor);
    }

    public function exibeDependente()
    {
        echo "\nDependente:\n";
        echo "\tCodigo:" . $this->__get("dependente")->codigo;
        echo "\tNome: " . $this->__get("dependente")->nome;
        echo "\tParentesco: " . $this->__get("dependente")->parentesco;
        echo "\n";
    }
}

class Dependente
{
    private int $codigo;
    private string $nome;
    private $parentesco;

    public function __construct($codigo, $nome, $parentesco)
    {
        $this->codigo = $codigo;
        $this->nome = $nome;
        $this->parentesco = $parentesco;
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

$dependente = new Dependente(1, "Franco", "Marcelene");
$funcionario = new Funcionario(1, "Marcos", "Mecanica", "21/05/2024","8 horas", 2600, $dependente);

//print_r($funcionario);
//print_r($dependente);

$funcionario->exibeDependente();