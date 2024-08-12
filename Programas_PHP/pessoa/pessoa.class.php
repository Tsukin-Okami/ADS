<?php

class pessoa {
    public $codigo;
    public $nome;
    public $altura;
    public $idade;
    public $nascimento;
    public $escolaridade;
    public $salario;

    public function __construct($codigo, $nome, $altura, $idade, $nascimento, $escolaridade, $salario) {
        $this->codigo = $codigo;
        $this->nome = $nome;
        $this->altura = $altura;
        $this->idade = $idade;
        $this->nascimento = $nascimento;
        $this->escolaridade = $escolaridade;
        $this->salario = $salario;
    }

    public function __destruct() {
        echo "objeto ($this->nome) finalizado... <br>\n";
    }

    public function crescer($centimetros) {
        if ($centimetros > 0) {
            $this->altura += $centimetros;
        }
    }

    public function formar($titulo) {
        $this->escolaridade = $titulo;
    }
    
    public function envelhecer($anos) {
        if ($anos > 0) {
            $this->idade += $anos;
        }
    }
}