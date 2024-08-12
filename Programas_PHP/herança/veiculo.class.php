<?php

class Veiculo {
    public int $codigo;
    public string $descricao;
    public string $combustivel;
    public string $fabricante;

    public function __construct($codigo, $descricao, $combustivel, $fabricante) {
        $this->codigo = $codigo;
        $this->descricao = $descricao;
        $this->combustivel = $combustivel;
        $this->fabricante = $fabricante;
    }

    public function __destruct() {
        echo("objeto Veiculo destruido.\n");
    }

    public function andar() {
        print("O veiculo andou.\n");
    }

    public function parar() {
        print("O veiculo parou.\n");
    }

    public function frear() {
        print("O veiculo freiou.\n");
    }
}