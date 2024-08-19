<?php

abstract class Funcionario {
    public $nome;
    protected $codigo;
    protected string $nascimento;
    protected float $salario;

    public function __construct($nome, $codigo, $nascimento, $salario) {
        $this->nome = $nome;
        $this->codigo = $codigo;
        $this->nascimento = $nascimento;
        $this->SetSalario($salario);
    }

    public function __destruct() {
        echo "O funcionario {$this->nome} com o codigo {$this->codigo} foi destruido.";
    }

    protected function SetSalario(float $salario) {
        if (is_float($salario) and ($salario>0)) {
            $this->salario = $salario;
        }
    }

    protected function GetSalario() {
        return $this->salario;
    }
}

final class Estagiario extends Funcionario {
    public function __construct($nome, $codigo, $nascimento, $salario) {
        parent::__construct($nome, $codigo, $nascimento, $salario);
    }

    public function SetSalario(float $salario) {
        parent::SetSalario($salario);
    }

    public function GetSalario() {
        return parent::GetSalario() * 1.12;
    }
}

$pedro = new Estagiario("Pedro", 261, "21/12/1996", 3600);
//print_r($pedro);

$pedro->SetSalario(248);
echo "Salario: R\$ {$pedro->GetSalario()}.\n";
