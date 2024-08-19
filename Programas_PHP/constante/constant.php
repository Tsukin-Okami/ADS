<?php

class Biblioteca {
    const Nome = "GTK";
}

class Aplicacao extends Biblioteca {
    
    const Ambiente = "GNOME Desktop";
    const Versao = "3.8";

    function __construct($nome) {
        echo parent::Nome . " " . self::Ambiente . " " . self::Versao . " " . $nome . "\n";
    }

    static function GetVersao() {
        return self::Versao;
    }
}

// chamado externo de atributos
echo Biblioteca::Nome . " " . Aplicacao::Ambiente . " " . Aplicacao::Versao . "\n";

// chamar o nome do parent usando o child como base
echo Aplicacao::Nome . "\n";

new Aplicacao("Dia");
new Aplicacao("Gimp");
