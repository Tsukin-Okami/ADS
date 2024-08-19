<?php

abstract class Fruta {
    protected string $cor;

    abstract public function Comer();

    protected function DefinirCor($cor) {
        $this->cor = $cor;
    }
}

final class Banana extends Fruta {
    public $nome;
    protected $proteinas;

    public function __construct($tipo, $proteinas) {
        $this->proteinas = $proteinas;
        $this->nome = "Banana {$tipo}";
        $this->DefinirCor("Amarelo");
    }

    public function Comer() {
        echo "Hmmm... Tem gosto de {$this->nome}.\n";
    }

    public function getCor() {
        print $this->cor . "\n";
    }
}

$banana = new Banana("da terra", 312);
$banana->Comer();
$banana->getCor();