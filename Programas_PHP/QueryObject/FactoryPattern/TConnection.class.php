<?php

/**
 * Classe TConnection
 * gerencia conexões com o banco de dados através de arquivos de configuração 
*/

final class TConnection
{
    /**
     * Método __construct()
     * não existirão instancias de TConnection, por isso estamos marcando-o como private
    */

    private function __construct()
    {

    }

    /**
     * Método open()
     * recebe o nome do banco de dados e instancia o objeto PDO correspondente
     * @param string $name
    */

    public static function open($name) {
        // verifica se existe arquivo de configuração para este banco de dados
        if (file_exists("app.config/{$name}.ini"))
        {
            // le o INI e retorna um Array
            $db = parse_ini_file("app.config/{$name}.ini");
        }
    }
}