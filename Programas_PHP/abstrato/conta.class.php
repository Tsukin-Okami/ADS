<?php

abstract class Conta {
    public int $agencia;
    public string $codigo;
    public $datacriacao;
    public $titular;
    public string $senha;
    public float $saldo;
    public bool $cancelada;

    public function __construct($agencia, $codigo, $datacriacao, $titular, $senha, $saldo) {
        $this->agencia = $agencia;
        $this->codigo = $codigo;
        $this->datacriacao = $datacriacao;
        $this->titular = $titular;
        $this->senha = $senha;
        $this->saldo = $saldo;
        $this->cancelada = false;
    }

    public function __destruct() {
        echo "objeto conta {$this->codigo} de {$this->titular->nome} foi finalizada... <br>\n";
    }

    public function retirar($quantia) {
        if ($quantia > 0) {
            $this->saldo -= $quantia;
        }
    }

    public function depositar($quantia) {
        if ($quantia > 0) {
            $this->saldo += $quantia;
        }
    }

    public function obterSaldo() : float {
        return $this->saldo;
    }
}