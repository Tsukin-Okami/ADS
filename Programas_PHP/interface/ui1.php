<?php
/*
abstract class Ans 
{
    abstract public function Tep();
}

class Anse extends Ans
{
    public function Tep()
    {
        echo "funciona";
    }
}
*/

interface Animal
{
    public function emitirSom();
}

class Cachorro implements Animal
{
    public function emitirSom()
    {
        echo "latido\n";
    }
}

class Gato implements Animal
{
    public function emitirSom()
    {
        echo "miau\n";
    }
}

// exemplo de uso
$animais = [
    new Cachorro, 
    new Gato
];

foreach ($animais as $animal) {
    $animal->emitirSom(); // cada animal chamará seu método especifico
}