<?php

/**
 * Classe TLogger
 * classe que prove uma interface para definição do algoritmo de log
*/

abstract class TLogger
{
    protected $filename; // local do arquivo de LOG

    /**
     * Método Construtor
     * instancia um logger
     * @param $filename = local do arquivo de log
    */

    public function __construct($filename)
    {
        $this->filename = $filename;
        // reseta o conteúdo do arquivo
        file_put_contents($filename, "");
    }

    // define o método write como obrigatório
    abstract function write($message);
}