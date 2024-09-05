<?php

interface Calculadora
{
    public function somar($a, $b);
    public function subtrair($a, $b);
}

class CalculadoraAvancada implements Calculadora
{
    public function somar($a, $b) {
        return $a + $b;
    }

    public function subtrair($a, $b) {
        return $a - $b;
    }

    public function multiplicar($a, $b) {
        return $a * $b;
    }
}

$calculadora = new CalculadoraAvancada;
echo $calculadora->somar(1,2) . "\n";
echo $calculadora->subtrair(1,2) . "\n";
echo $calculadora->multiplicar(1,2). "\n";