<?php

require "./veiculo.class.php";

class Trem extends Veiculo {
    public int $qtde_vagao;

    public function __construct($codigo, $descricao, $combustivel, $fabricante, $qtde_vagao) {
        parent::__construct($codigo, $descricao, $combustivel, $fabricante);
        $this->qtde_vagao = $qtde_vagao;
    }

    public function apitar() {
        print("O trem apitou.\n");
    }
}