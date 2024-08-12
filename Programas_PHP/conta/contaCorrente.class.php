<?php

require "./conta.class.php";

class ContaCorrente extends Conta {
    public $limite;
    // metodo construtor sobrescrito //
    public function __construct($agencia, $codigo, $datacriacao, $titular, $senha, $saldo, $limite) {
        // chamada do método construtor da classe pai //
        parent::__construct($agencia, $codigo, $datacriacao, $titular, $senha, $saldo);
        $this->limite = $limite;
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

