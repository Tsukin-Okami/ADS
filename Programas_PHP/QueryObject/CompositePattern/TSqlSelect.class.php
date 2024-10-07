<?php

/**
 * Classe Select
 * Essa classe provê meios para manipulação de uma instrução de SELECT no BD 
*/

final class TSqlSelect extends TSqlInstruction
{
    private $column; // array de colunas a serem retornadas.

    /**
     * Método addColumn()
     * adiciona uma coluna a ser retornada pelo SELECT
     * @param $column = coluna de tabela
    */

    public function addColumn($column)
    {
        $this->column[] = $column;
    }

    /**
     * Método getInstruction
     * retorna a instrução de Delete em forma de String
    */

    public function getInstruction()
    {
        // monta a instrução do SELECT
        $this->sql = "SELECT ";

        // monta string com os nomes das colunas
        $this->sql .= implode(', ', $this->column);

        // adiciona na clausula FROM o nome da tabela
        $this->sql .= " FROM " . $this->entity;

        // adiciona na clausula WHERE do objeto $this->criteria
        if ($this->criteria)
        {
            $expression = $this->criteria->dump();
            if ($expression) 
            {
                $this->sql .= " WHERE " . $expression;
            }

            // obtem as propriedades do criterio
            $order = $this->criteria->getProperty('order');
            $limit = $this->criteria->getProperty('limit');
            $offset = $this->criteria->getProperty('offset');

            // obtem a ordenação do select
            if ($order)
            {
                $this->sql .= " ORDER BY ". $order;
            }

            if ($limit)
            {
                $this->sql .= " LIMIT ". $limit;
            }

            if ($offset)
            {
                $this->sql .= " OFFSET ". $offset;
            }
        }

        return $this->sql;
    }
}