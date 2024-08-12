<?php

require "./conta.class.php";

class ContaPoupanca extends Conta {
    public $aniversario;
    // metodo construtor sobrescrito //
    public function __construct($agencia, $codigo, $datacriacao, $titular, $senha, $saldo, $aniversario) {
        // chamada do método construtor da classe pai //
        parent::__construct($agencia, $codigo, $datacriacao, $titular, $senha, $saldo);
        $this->aniversario = $aniversario;
    }

    // metodo retirar sobrescrito
    public function retirar($quantia) {
        if ($this->saldo >= $quantia) {
            parent::retirar($quantia);
        } else {
            echo "Retirada não permitida... \n";
            return false;
        }
        return true;
    }
}