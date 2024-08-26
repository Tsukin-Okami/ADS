<?php

class Unidades
{
    public $codigo;
    private array $funcionarios;
    private $gestor;
    private int $qtde_funcionario;

    public function __construct($codigo, array $funcionarios = [], $gestor, $qtde_funcionario)
    {
        $this->codigo = $codigo;
        $this->funcionarios = $funcionarios;
        $this->gestor = $gestor;
        $this->qtde_funcionario = $qtde_funcionario;
    }

    private function addFuncionario(object $funcionario)
    {
        $this->funcionarios[] = $funcionario;
        $this->qtde_funcionario = count($this->funcionarios);
    }

    private function cadastrarFuncionario($cpf, $nome, $sobrenome, $endereco, $telefone) 
    {
        $this->addFuncionario(new Pessoa($cpf, $nome, $sobrenome, $endereco, $telefone));
    }
}

class Pessoa
{
    public int $cpf;
    private string $nome;
    private string $sobrenome;
    private string $endereco;
    private $telefone;

    public function __construct($cpf, $nome, $sobrenome, $endereco, $telefone)
    {
        $this->cpf = $cpf;
        $this->nome = $nome;
        $this->sobrenome = $sobrenome;
        $this->endereco = $endereco;
        $this->telefone = $telefone;
    }

    private function alterarEndereco($endereco)
    {
        $this->endereco = $endereco;
    }

    private function cadastrarTelefone($telefone)
    {
        $this->telefone = $telefone;
    }
}