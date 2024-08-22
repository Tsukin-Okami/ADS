<?php

class Estante
{
    private string $local;
    private string $biblioteca;
    private string $campus;
    private int $corredor;
    private array $livro;

    // <<

    public function __construct($local, $biblioteca, $campus, $corredor, $livro = [])
    {
        $this->local = $local;
        $this->biblioteca = $biblioteca;
        $this->campus = $campus;
        $this->corredor = $corredor;
        // agregação
        $this->livro = $livro;
    }

    public function __destruct()
    {
        return;
    }

    // <<

    public function __get($name)
    {
        return $this->$name;
    }

    public function __set($name, $value)
    {
        $this->$name = $value;
    }

    // >>

    public function adicionarLivro(object $livro)
    {
        $this->livro[] = $livro;
    }

    public function exibirLivros()
    {
        echo "\n\tEstante " . $this->__get("local") . " " . $this->__get("biblioteca") . "\n";
        foreach ($this->livro as $livro_selecionado) {
            echo "" . "[" . $livro_selecionado->__get("codigo") . "] " . $livro_selecionado->__get("nome") . "\n"; 
            echo "\tAutor: " . $livro_selecionado->__get("autor") . "\n"; 
            echo "\tEditora: " . $livro_selecionado->__get("editora") . "\n";
        }
    }
}

class Livro
{
    private string $nome;
    private int $codigo;
    private string $autor;
    private string $editora;

    // <<

    public function __construct($nome, $codigo, $autor, $editora)
    {
        $this->nome = $nome;
        $this->codigo = $codigo;
        $this->autor = $autor;
        $this->editora = $editora;
    }

    public function __destruct()
    {
        return;
    }

    // <<

    public function __get($name)
    {
        return $this->$name;
    }

    public function __set($name, $value)
    {
        $this->$name = $value;
    }
}

// lista de 30 livros aleatorios
$nomeslivro = [
    "O Senhor dos Anéis: A Sociedade do Anel",
    "Dom Quixote",
    "O Hobbit",
    "Orgulho e Preconceito",
    "1984",
    "A Revolução dos Bichos",
    "Moby Dick",
    "Cem Anos de Solidão",
    "O Sol é para Todos",
    "A Menina que Roubava Livros",
    "Harry Potter e a Pedra Filosofal",
    "O Pequeno Príncipe",
    "A Guerra dos Tronos",
    "O Código Da Vinci",
    "A Cabana",
    "O Nome do Vento",
    "O Alquimista",
    "O Morro dos Ventos Uivantes",
    "A Mãe",
    "O Diário de Anne Frank",
    "O Senhor das Moscas",
    "Jane Eyre",
    "O Perfume",
    "O Silêncio dos Inocentes",
    "O Casamento",
    "A Vida de Pi",
    "Os Miseráveis",
    "O Retrato de Dorian Gray",
    "O Vendedor de Sonhos",
    "O Lobo da Estepe",
    "A Arte da Guerra",
    "O Estrangeiro"
];
// lista de 30 autores aleatorios
$autoreslivro = [
    "J.R.R. Tolkien",
    "Miguel de Cervantes",
    "J.K. Rowling",
    "Jane Austen",
    "George Orwell",
    "Aldous Huxley",
    "Herman Melville",
    "Gabriel García Márquez",
    "Harper Lee",
    "Markus Zusak",
    "J.D. Salinger",
    "F. Scott Fitzgerald",
    "Stephen King",
    "Jorge Luis Borges",
    "Ernest Hemingway",
    "Leo Tolstoy",
    "Charles Dickens",
    "Oscar Wilde",
    "Liam Neeson",
    "Isaac Asimov",
    "Tolkien",
    "Ray Bradbury",
    "Agatha Christie",
    "John Steinbeck",
    "William Faulkner",
    "Sylvia Plath",
    "H.P. Lovecraft",
    "J.D. Salinger",
    "Dan Brown",
    "Paul Coelho",
    "Alice Walker"
];

$estante = new Estante("Univalle", "Limentar", "Edu", 7);

// cria 20 livros com nome e autor aleatorio e coloca eles na estante
for ($i = 0; $i < 20; $i++) {
    $rand_nome = $nomeslivro[array_rand($nomeslivro, 1)];
    $rand_autor = $autoreslivro[array_rand($autoreslivro, 1)];

    $livro = new Livro($rand_nome, $i, $rand_autor, "Eclipse");
    $estante->adicionarLivro($livro);
}

$estante->exibirLivros();