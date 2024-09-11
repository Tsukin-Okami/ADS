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

$num = 5;
$res;

$res = $calculadora->somar($num,3);
$res = $calculadora->multiplicar($res, 5);
$res = $calculadora->subtrair($res, -12);

echo $res;