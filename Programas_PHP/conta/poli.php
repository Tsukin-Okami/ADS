<?php

# carregas as classes

include_once 'pessoa.class.php';
include_once 'conta.class.php';
include_once 'contaPoupanca.class.php';
include_once 'contaCorrente.class.php';

# criação de um objeto $Carlos

$Carlos = new Pessoa(10, "Carlos da Silva", 1.85, 48, "10/04/1976", "Ensino Medio", 650.00);

echo("Manipulando o Objeto {$Carlos->nome}: \n");

# criação do objeto $contas_carlos

$contas[1] = new ContaCorrente(6677, "CC.1234.56", "10/07/2002", $Carlos, 9876, 500.00, 200.00);
$contas[2] = new ContaPoupanca(6678, "PP.1234.57", "10/07/2002", $Carlos, 9876, 500.00, "10/07");

// percorrer as contas

foreach ($contas as $key => $conta) {
    echo("Manipulando a conta $key de:{$conta->titular->nome}:\n");
    echo("O saldo atual da conta $key é R\$ {$conta->obterSaldo()} \n");
    $conta->depositar(200);
    echo("O saldo atual da conta $key é R\$ {$conta->obterSaldo()} \n");
    $conta->retirar(100);
    echo("O saldo atual da conta $key é R\$ {$conta->obterSaldo()} \n");
}

