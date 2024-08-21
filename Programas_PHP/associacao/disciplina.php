<?php

class Disciplina
{
    public int $codigo;
    public string $nome;
    protected int $curso;
    private object $professor;

    public function __construct($codigo, $nome, $curso, $professor)
    {
        $this->codigo = $codigo;
        $this->nome = $nome;
        $this->curso = $curso;
        $this->professor = $professor;
    }

    public function __destruct()
    {
        return;
    }

    // getter

    public function __get($name)
    {
        return $this->$name;
    }

    // setter

    public function __set($name, $value)
    {
        $this->$name = $value;
    }
}

class Professor
{
    public int $codigo;
    public string $nome;
    protected string $formacao;
    private $cpf;

    public function __construct($codigo, $nome, $formacao, $cpf)
    {
        $this->codigo = $codigo;
        $this->nome = $nome;
        $this->formacao = $formacao;
        $this->cpf = $cpf;
    }

    public function __destruct()
    {
        return;
    }

    // getter

    public function __get($name)
    {
        return $this->$name;
    }

    // setter

    public function __set($name, $value)
    {
        $this->$name = $value;
    }
}

$professor = new Professor(1, "Alexandre Silveira", "Bacharel em Desenvolvimento de Sistemas", 8368768083);
$disciplina = new Disciplina(1, "Quantica Biologica", 3, $professor);

echo "Disciplina nome: " . $disciplina->__get("nome") . "\n";
echo "Disciplina curso: " . $disciplina->__get("curso") . "\n";

echo "Professor nome: " . $disciplina->__get("professor")->__get("nome") . "\n";
echo "Professor formação: " . $disciplina->__get("professor")->__get("formacao") . "\n";

echo "etcho";