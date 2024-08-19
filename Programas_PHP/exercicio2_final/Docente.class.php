<?php

final class Docente extends Pessoa {
    public $formacao;
    public $curso;
    public $salario;

    public function __construct($nome, $cpf, $endereco, $telefone, $formacao, $curso, $salario) {
        parent::__construct($nome, $cpf, $endereco, $telefone);
        $this->formacao = $formacao;
        $this->curso = $curso;
        $this->salario = $salario;
    }

    public function __destruct() {
        echo ("Objeto {$this->nome} foi destruido.");
    }
/*
    public function formar($formacao) {
        $this->formacao = $formacao;
    }*/

    /*      ERRO DESCONHECIDO NA FUNÇÃO FORMAR - PARENT::FORMAR() já existente porém não existe
        Resolve se retirar o parametro '$salario'
*/
    public function formar($formacao,$salario){
        $this->formacao = $formacao;
        $this->salario = ($salario * 20);
    }

    public function aumentarSalario($salario) {
        $this->salario += $salario;
        echo ("O salario da pessoa {$this->nome} aumentou para R\$ {$this->salario}.");
    }
}