<?php

/**
 * Classe TLogger TXT
 * implementa algoritmo de log em TXT
*/

class TLoggerTXT extends TLogger
{
    /**
     * Método write
     * escreva uma mensagem no arquivo de LOG
     * @param $message = mensagem a ser escrita
    */
    public function write($message)
    {
        date_default_timezone_set("America/Sao_Paulo");
        $time = date("Y-m-d H:i:s");

        // monta a string
        $text = "$time::$message\n";

        // adiciona ao final do arquivo
        $handler = fopen($this->filename, 'a');
        fwrite($handler, $text);
        fclose($handler);
    }
}