<?php

require "./veiculo.class.php";

class Moto extends Veiculo {
    public int $cilindrada;

    public function __construct($codigo, $descricao, $combustivel, $fabricante, $cilindrada) {
        parent::__construct($codigo, $descricao, $combustivel, $fabricante);
        $this->cilindrada = $cilindrada;
    }

    public function empinar() {
        print("A moto empinou.\n");
    }
}