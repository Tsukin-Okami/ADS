<?php

/**
 * Classe TTransaction
 * essa classe provê métodos necessários para manipular transações
*/

final class TTransaction
{
    private static $conn; // conexão ativa

    /**
     * Método __construct()
     * está declarando como private para impedir que se crie instâncias de TTransaction
    */
    private function __construct() {}
    
    /**
     * Método open()
     * abre uma transação e conexão com o BD
     * @param string $database = nome do banco de dados
    */
    public static function open($database) 
    {
        // abre conexão com o banco de dados armazena na propriedade estática $conn
        if (empty(self::$conn))
        {
            self::$conn = TConnection::open($database);
        }
    }

    /**
     * Método get()
     * retorna a conexão ativa da transação
     * @return PDO $conn = conexão ativa
    */
    public static function get()
    {
        // retorna a conexão ativa
        return self::$conn;
    }

    /**
     * Método rollback()
     * desfaz as operações realizadas na transação
    */
    public static function rollback()
    {
        if (self::$conn)
        {
            // desfaz as operações realizadas
            self::$conn->rollBack();
            self::$conn = null;
        }
    }

    /**
     * Método close()
     * aplica todas as operações realizadas e fecha a transação
    */
    public static function close()
    {
        if (self::$conn)
        {
            // aplica as operações realizadas durante a transação
            self::$conn->commit();
            self::$conn = null;
        }
    }
}