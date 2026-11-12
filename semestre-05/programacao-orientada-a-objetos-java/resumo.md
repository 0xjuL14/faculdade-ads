# POO em Java — Resumo para a prova

> Fontes: slides (Aula 01, Aula 02, Encapsulamento, Polimorfismo ×2, Learn Java, Plano de Ensino, Aula 11 GUI, Pacotes na prática, AULA_FORMULARIO_NOV) + Texto 04 (Destrutores e Pacotes) + questionários de revisão Fundamentos A, B e C.
> Códigos como **(A5)**, **(B12)**, **(C9)** indicam em qual questão do questionário o tema apareceu.
> ⚠️ marca os pontos em que houve erro nos questionários.

---

## 0. Ordem de prioridade

| Prioridade | Tema |
|---|---|
| 1 ⚠️ | Polimorfismo (upcasting, ligação tardia) |
| 1 ⚠️ | Construtores (construtor padrão, `this`, sobrecarga) |
| 1 ⚠️ | Abstração x Encapsulamento + as duas listas de princípios/pilares |
| 2 | Modificadores de acesso (cai muito, em verdadeiro/falso) |
| 2 | Objetos e referências |
| 3 | Herança, classes abstratas, interfaces, UML, mensagens |
| 3 | Extras: `final`, escopo, `equals`, `Comparable`, exceções, Collections |
| 2 (matéria nova) | Destrutores/garbage collector, pacotes e `import`, GUI com Swing, `JOptionPane` |

---

## 1. Java: plataforma e sintaxe básica

### Como o Java roda
```
código-fonte (.java) --compilador--> bytecode (.class) --JVM--> executa no SO
```
- **Bytecode** é independente de plataforma. Qualquer **JVM** (Linux, Windows, macOS…) o interpreta. Isso é a **portabilidade**.
- **Garbage Collector**: a JVM libera sozinha a memória de objetos que ninguém mais referencia. O programador **não faz aritmética de ponteiros** (diferente de C).
- **JDK** = kit de desenvolvimento (compilador + ferramentas). **BlueJ**, Eclipse e NetBeans são IDEs.

### Características citadas nos slides
Portabilidade, uso geral, linguagem distribuída, segurança (**sandbox**), multithreading, evolução pela comunidade (**JCP**), suporte a Web, orientação a objetos, ecossistema open source.

### Edições
| Sigla | Para quê |
|---|---|
| **JavaSE** | Base da linguagem, aplicações desktop |
| **JavaME** | Micro-dispositivos (celulares, pagers) |
| **JavaEE** | Aplicações corporativas distribuídas, multicamadas |

### Histórico mínimo
1991 Projeto Green (linguagem **Oak**, James Gosling) → 1995 lançamento oficial → 1996 JDK 1.0 → 1998 Java 2 (JDK 1.2).

### Sintaxe básica (Learn Java)
```java
public class Main {
    public static void main(String[] args) {
        System.out.println("Olá");   // println pula linha
        System.out.print("Sem ");    // print NÃO pula linha
        System.out.print("pular");
        /* comentário
           de várias linhas */
        String nome = "John";   // texto, aspas duplas
        int idade = 15;         // inteiro
        float preco = 19.99f;   // decimal
        char letra = 'a';       // um caractere, aspas simples
        boolean ok = true;      // true ou false
    }
}
```
Molde de declaração: `tipo nomeDaVariavel = valor;`

---

## 2. Paradigmas: estruturado x orientado a objetos

| | Estruturada | Orientada a Objetos |
|---|---|---|
| **Vantagens** | Controle do fluxo, código fácil de ler, **desempenho maior** | **Reutilização**, melhor organização, mais próxima do ser humano |
| **Desvantagens** | Código confuso sem modularização, **reuso difícil** | **Desempenho menor**, confusa se mal aplicada |
| **Apropriada para** | Operações lógicas e aritméticas | Sistemas de informação |

- Visão diferente do mundo: estruturado pensa em **funções** (`efetuarEmprestimoLivro()`); OO pensa em **objetos com comportamento** (`livro.emprestar()`).
- **Histórico da POO (C6):** surgiu com **Simula-68** (fim dos anos 60), amadureceu com **Smalltalk** (anos 70, **Alan Kay**, Xerox) e se popularizou nos anos 80/90 com **C++ e Java**.
- **Java x C++:** Java é mais fácil de aprender e tem foco em web, mobile e corporativo. C++ é de mais baixo nível e usa melhor os recursos da máquina (jogos, embarcados).

---

## 3. Conceitos básicos de POO

| Conceito | Definição |
|---|---|
| **Objeto** | Entidade com **características** (atributos) e **comportamentos** (métodos). É uma **instância** de uma classe. |
| **Classe** | **Molde** que define atributos e métodos comuns. É abstrata (não existe concretamente). |
| **Atributo** | Característica/dado (ex.: `cor`, `nome`). |
| **Método** | Comportamento/operação (ex.: `ligar()`, `acelerar()`). |
| **Instanciação** | Criar um objeto com o operador `new`. |
| **Referência** | A **variável** que aponta para o objeto. |

```java
public class Carro {
    private String cor;
    public void setCor(String cor) { this.cor = cor; }   // altera
    public String getCor() { return cor; }               // lê
}

Carro c = new Carro();   // c é uma REFERÊNCIA ao objeto (A12)
c.setCor("PRETO");
```

### Objetos e referências (B14, B15, B17)
- `new` **aloca memória** (B14).
- Antes do `new`, a variável é `null`. Depois, o objeto tem **todos os atributos e métodos** da classe ⚠️ (B15).
- Atribuir uma referência a outra **não copia o objeto**:
```java
Professor prof1 = new Professor();
Professor prof2 = new Professor();
Professor prof3 = prof1;   // prof1 e prof3 apontam para o MESMO objeto
```
Existem **2 objetos**, não 3 (B17).

### Troca de mensagens (A6, A8, A13, A17, B1)
Mensagem = **chamar um método** de um objeto (ou ler/alterar seu estado).
```java
// Main -> pessoa -> carro (delegação)
pessoa.ligarCarro();              // Main manda mensagem à Pessoa
// dentro de Pessoa: carro.ligar();  // Pessoa repassa ao Carro
carro.setDono(pessoa);            // Main envia setDono ao carro, passando pessoa como parâmetro
System.out.println(carro.getDono().getNome());  // getDono() devolve a Pessoa; getNome() devolve o nome DELA
```

---

## 4. Construtores ⚠️

**Para quê:** definir os **valores iniciais** dos atributos no momento da criação (B7).

**Regras:**
- Mesmo nome da classe e **sem tipo de retorno** (nem `void`) (C11).
- É chamado **automaticamente** pelo `new` (A2).
- Pode haver **vários** na mesma classe, com parâmetros diferentes = **sobrecarga** (C13).
- Se a classe **não declara nenhum**, o Java cria o **construtor padrão** (sem parâmetros) (C8).
- Se a classe **declara qualquer construtor**, o padrão **deixa de existir** ⚠️.
- `this.atributo = parametro;` diferencia o atributo do parâmetro de mesmo nome (A14).

```java
public class Produto {
    String nome;
    double preco;

    public Produto(String nome) {                 // construtor 1
        this.nome = nome;
        this.preco = 0.0;
    }
    public Produto(String nome, double preco) {   // construtor 2 (sobrecarga)
        this.nome = nome;
        this.preco = preco;
    }
}

Produto p1 = new Produto("Caneta");
Produto p2 = new Produto("Caderno", 15.90);
Produto p3 = new Produto();   // ERRO DE COMPILAÇÃO: não há construtor sem parâmetros (A5)
```

**Armadilha (A5 x C8):** o construtor padrão só existe se você **não escreveu nenhum**. Escreveu um? `new Produto()` não compila.

---

## 5. Princípios e pilares da OO ⚠️

> Os slides trazem **duas listas diferentes**. Associe a lista à **frase da pergunta**.

| Frase da pergunta | Lista |
|---|---|
| "Quatro **pilares** da POO **derivados do princípio da abstração**" ⚠️ (C5) | **Encapsulamento, Herança, Composição e Polimorfismo** |
| "**Princípios** da Orientação a Objetos" (slide de Princípios OO) | **Abstração, Encapsulamento, Modularização e Herança** |

### Definições que caem
| Princípio | Ideia central |
|---|---|
| **Abstração** ⚠️ | Considerar **apenas os elementos relevantes** de uma entidade, ignorando o resto (B4). Ex.: um médico foca em um órgão. |
| **Encapsulamento** | **Ocultar** os detalhes internos e proteger o estado, expondo só o necessário (A20, B10). |
| **Modularidade** | Decompor o sistema em módulos **coesos e fracamente acoplados** (A19). |
| **Herança** | Classe filha aproveita atributos e métodos da classe mãe. |
| **Polimorfismo** | Mesma ação executada de formas diferentes conforme o objeto. |

**Cuidado (B4):** "ocultar detalhes internos" é **encapsulamento**, não abstração. Abstração enfoca o **comportamento observável**; encapsulamento esconde a **implementação** que o gera.

---

## 6. Encapsulamento e modificadores de acesso

### Ideia
Como uma cápsula: a **interface** (métodos públicos) fica visível e a **implementação** (atributos, métodos internos) fica protegida. O Automóvel expõe a direção; a Pessoa não precisa saber **como** ela funciona.

### Exemplo dos slides (Agenda)
**Sem encapsulamento:** atributos sem modificador permitem `agenda2.mes = 15;` direto, **pulando a validação** da data.
**Com encapsulamento:** atributos `private`, métodos `public`. Agora `agenda2.mes = 15;` **não compila**.

```java
public class Agenda {
    private int dia, mes, ano;
    private String anotacao;

    public void anote(int dia, int mes, int ano, String nota) {
        this.dia = dia; this.mes = mes; this.ano = ano; this.anotacao = nota;
        validaData();                    // validação sempre passa por aqui
    }
    private void validaData() { /* zera tudo se a data for inválida */ }
    public void mostraAnotacao() { System.out.println(dia + "/" + mes + "/" + ano + ": " + anotacao); }
}
```

### Tabela de acesso (decore!) (A9, C12, C15, C17–C21)

| Modificador | Própria classe | Mesmo pacote | Subclasse (outro pacote) | Qualquer classe |
|---|:-:|:-:|:-:|:-:|
| `private` | ✅ | ❌ | ❌ | ❌ |
| *(default)* sem modificador | ✅ | ✅ | ❌ | ❌ |
| `protected` | ✅ | ✅ | ✅ | ❌ |
| `public` | ✅ | ✅ | ✅ | ✅ |

**Pegadinhas dos verdadeiro/falso (C18–C21):**
- `private` em método = só a própria classe enxerga → **Verdadeiro**.
- `protected` = qualquer classe → **Falso** (é pacote + subclasses).
- `private` em atributo = visível só para métodos `public` → **Falso** (é visível para **qualquer** método da própria classe).
- `protected` em atributo = visível só para métodos `protected` → **Falso**.

### Getters e setters (B6, B11)
- Finalidade: **leitura e alteração controlada** de atributos privados.
- **Atributos `public` + getters/setters = NÃO é bom encapsulamento** (B11). O atributo precisa ser `private`.

### Benefícios (B5, B9)
- ✅ A implementação interna pode mudar sem afetar quem usa a classe (desde que a interface não mude).
- ✅ Menor interdependência entre as classes.
- ❌ Atributos públicos **não** são vantagem. Mudança de implementação **não** impede de compilar.

---

## 7. Herança, classes abstratas e interfaces

### Herança
- `class Cachorro extends Animal` → Cachorro é **subclasse (filha)**; Animal é **superclasse (mãe)** (A10).
- Herança é uma relação **entre classes** (não entre objetos) (B12).
- A subclasse acessa membros **públicos e protegidos** da mãe, **não os privados** (B13).
- Java: uma classe estende **somente UMA** classe (C3). Não há herança múltipla de classes.
- Uma classe pode **implementar várias interfaces**.

### Classe abstrata (C10)
- **Não pode ser instanciada.**
- Serve para **centralizar comportamento comum**, definido uma única vez.
- Pode ter **métodos abstratos** (só assinatura, sem corpo), que as subclasses são **obrigadas a implementar**.
```java
public abstract class Forma {
    public abstract double calcularArea();   // sem corpo
}
public class Circulo extends Forma {
    @Override
    public double calcularArea() { return Math.PI * raio * raio; }
}
```

### Interface
Um **contrato** de métodos que a classe deve implementar. Qualquer classe que implementa a interface pode ser tratada **pelo tipo da interface**.
```java
public interface Veiculo { void acelerar(); void frear(); }
public class Carro implements Veiculo { /* implementa os métodos */ }

Veiculo meuVeiculo = new Carro();   // uso polimórfico
meuVeiculo.acelerar();
```

---

## 8. Polimorfismo ⚠️

### Ideia
**"Muitas formas"**: um mesmo método se comporta de jeito diferente conforme o objeto (B3). Em Java, o polimorfismo se manifesta **na chamada de métodos**.

### Os dois tipos (decore a tabela) (A3, A4, A18, C9)

| | **Sobrecarga** (overloading) | **Sobreposição** (overriding) |
|---|---|---|
| Tipo | **Estático** (de compilação) | **Dinâmico** (de execução) |
| Onde | **Mesma classe** | **Classes diferentes** (mãe e filha) |
| Assinatura | **Diferente** (nº ou tipos de parâmetros) | **Exatamente a mesma** |
| Resolvido | Em **compilação**, pela **lista de parâmetros** da chamada | Em **execução**, pelo **tipo real do objeto** |
| Ligação | **Estática** (static binding) | **Tardia** (late binding) |
| Herança | **Não** exige | **Exige** |
| `@Override` | Não usa | Recomendado |

### Sobrecarga
```java
public class Calculadora {
    public int    somar(int a, int b)           { return a + b; }
    public int    somar(int a, int b, int c)    { return a + b + c; }
    public double somar(double a, double b)     { return a + b; }
}
calc.somar(5, 3);        // 8   (versão int)
calc.somar(5.2, 3.8);    // 9.0 (versão double)
```
Construtores sobrecarregados também contam como sobrecarga (C13).

### Sobreposição e ligação tardia
```java
public class Animal  { public void fazerSom() { System.out.println("som genérico"); } }
public class Cachorro extends Animal {
    @Override public void fazerSom() { System.out.println("Au au!"); }
}
public class Gato extends Animal {
    @Override public void fazerSom() { System.out.println("Miau!"); }
}

Animal a1 = new Cachorro();   // variável: Animal | objeto real: Cachorro
Animal a2 = new Gato();
a1.fazerSom();   // Au au!   <- decidido em EXECUÇÃO pelo objeto real
a2.fazerSom();   // Miau!
```

**`@Override` (A1):** avisa o **compilador** de que o método sobrescreve um da superclasse. Se a assinatura não bater, dá erro de compilação. Não cria método novo, não sobrecarrega e não deixa o método privado.

### Upcasting ⚠️ (A16)
`Animal a = new Cachorro();` é **upcasting**: referência da **superclasse** apontando para objeto da **subclasse**.
- ✅ Permite **tratar objetos de várias subclasses de forma uniforme** (ex.: um `Animal[]` com cachorro, gato e animal genérico, percorrido com um `for`).
- ❌ **Não** permite acessar métodos **exclusivos da subclasse** pela referência da superclasse. A variável só "enxerga" o que existe em `Animal`.

```java
Animal[] animais = { new Cachorro(), new Gato(), new Animal() };
for (Animal an : animais) an.fazerSom();   // cada um responde do seu jeito
```

### `instanceof`
```java
peao instanceof Peca   // true: peão, cavalo e bispo são do tipo Peca
```

### Vantagens do polimorfismo
**Flexibilidade** (código genérico), **extensibilidade** (novas classes sem alterar o código existente) e **acoplamento reduzido**.

---

## 9. UML e cardinalidade

- **UML**: padrão para especificar, visualizar e documentar sistemas OO.
- Retângulo de classe com **3 compartimentos**: **nome da classe / atributos / métodos** (A11).

### Cardinalidade (A15, C16)
| Situação | Relação |
|---|---|
| Computador imprime em várias impressoras **e** cada impressora recebe de vários computadores | **Muitos-para-muitos** |
| Automóvel comporta várias pessoas, mas cada pessoa está em **um** automóvel | **Um-para-muitos** |

**Dica:** monte a frase dos dois lados. "Um X tem quantos Y?" e "Um Y está em quantos X?".

### Ligações e associações
- **Ligação** = relação entre **objetos** (João *possui* Carro A).
- **Associação** = relação entre **classes** (Pessoa *possui* Carro).

---

## 10. Extras que apareceram nos questionários

### `final` ⚠️ (B8)
Variável que **não pode ser alterada**: `final`. Em Java, **`const` não é usada**.
```java
final double PI = 3.14;
```

### Escopo (B16)
- Variáveis **locais** (declaradas no método ou parâmetros) só valem **dentro do método**.
- Atributos da classe valem para toda a classe.

### Operadores e laços (C2, C4)
- Operadores válidos: `+ - * / % == != > < >= <=`. **Não existem** em Java: `**`, `<>`, `:=`.
- **Laços de repetição:** `for`, `while`, `do while`. (`if/else` é **condicional**, não laço.)

### `equals` (B20)
Por padrão, `equals()` compara **endereço de memória** (referência). Dois objetos com valores iguais dão `false`. Para comparar valores, **sobrescreva `equals()`** na classe (boa prática: também `hashCode()`).

### `Comparable` (B18)
Para ordenar objetos de uma classe em coleções, ela deve **implementar `Comparable`** e o método **`compareTo()`**.

### Collections (C1)
| Interface | Característica |
|---|---|
| `List` | Coleção **ordenada** (por posição); aceita repetidos |
| `Set` | **Não** permite elementos duplicados |
| `Map` | Mapeia **chave → valor** (cada elemento = uma chave e um valor) |

### Exceções (B19)
```
Throwable
├── Error
└── Exception
    ├── IOException
    └── RuntimeException
        ├── NullPointerException
        └── IndexOutOfBoundsException
```
`RuntimeException` **é subclasse de** `Exception`. `Error` **não** herda de `Exception`.

### Afirmativas de POO (B12)
- ✅ Objetos são instâncias de classes.
- ✅ Atributos devem ser privados para esconder o funcionamento interno.
- ✅ Herança é relação **entre classes**.
- ❌ Herança entre objetos. ❌ Classes "apenas" agrupam métodos. ❌ Herança múltipla = herdar mais de um método.

---

## 11. Destrutores e garbage collector
*(Texto 04, Prof. Carlos Tadeu; garbage collector também na Aula 01)*

> Construtor **cria e inicializa**. Destrutor **libera** os recursos. Em Java quem limpa é o **garbage collector**, sozinho.

- Destrutores "finalizam": liberam os recursos usados pelos objetos (principalmente **memória**). Sem liberar, os recursos podem **se esgotar**.
- Construtores **alocam** espaço; destrutores **liberam**.
- Em Java **não existe o conceito de destrutor**. O programador não destrói objeto.

**Objeto perdido na memória** (classe `Garrafa` com dois construtores, sobrecarga):

```java
public class Garrafa {
    private String material;
    private int capacidade;

    public Garrafa(String material) {                    // construtor 1
        this.material = material;
    }
    public Garrafa(String material, int capacidade) {    // construtor 2 (sobrecarga)
        this.material = material;
        this.capacidade = capacidade;
    }
}
```

```java
public class TesteGarrafa {
    public static void main(String[] args) {
        Garrafa garrafapequena;
        garrafapequena = new Garrafa("Plástico");       // cria o objeto 1
        garrafapequena = new Garrafa("Vidro", 2000);    // cria o objeto 2: o objeto 1 perde a referência

        // O objeto 1 ficou "perdido" na memória (ninguém aponta para ele).
        // O garbage collector o marca para eliminação futura.

        Garrafa g = new Garrafa("Vidro", 2000);
        g = null;     // o objeto fica sem referência; o GC poderá recolhê-lo quando quiser
    }
}
```

Ao reatribuir `garrafapequena` ao objeto de vidro, o de **plástico fica sem referência**.

**Coleta de lixo (garbage collection):**
1. Objeto que **deixa de ser referenciado** recebe marcação para eliminação.
2. Quando o programa fica **ocioso**, o gerenciador de memória destrói os perdidos e libera os recursos.
3. Por isso **não é preciso liberar memória explicitamente**.

| | C++ (o texto diz "C/C++") | Java |
|---|---|---|
| Quem libera | O programador (destrutor, `delete`) | Garbage collector |
| Destrutor | Existe | Não existe |
| Controle do *quando* | Total | Nenhum |

> ⚠️ **Pegadinha:** `obj = null;` **não destrói na hora**. Só tira a referência; o GC destrói quando achar conveniente, e **não é garantido**.
> Além do texto: em C puro não há destrutor nem `delete`, é `malloc`/`free` à mão.

**Revisão:** (1) Para que serve destrutor? (2) Java tem destrutor? Quem limpa? (3) O que acontece com o objeto de plástico? (4) `null` destrói imediatamente?

---

## 12. Pacotes e `import`
*(Texto 04; slides "Pacotes, colocando em Prática" e AULA_FORMULARIO_NOV)*

> **Pacote** (`package`) = **pasta** com classes relacionadas. Organiza o projeto e **evita colisão de nomes**.

- Toda classe pertence a algum pacote. Sem especificar, fica no **pacote default** (a própria pasta).
- Nome em **minúsculas**, partes separadas por **ponto**, de preferência o **nome reverso do site**: `www.pacotes.com.br` + `meupacote` → `br.com.pacotes.meupacote`.
- `package nome;` vai na **primeira linha** da classe.
- Cada parte do nome vira uma pasta: `br.com.loja` → `src/br/com/loja`.
- Pacotes do próprio Java: `awt`, `beans`, `io`, `lang`, `math`, `net`, `rmi`.

```java
package br.com.loja;

public class Filial {
    private String cidade;

    public String getCidade() { return cidade; }
    public void setCidade(String cidade) { this.cidade = cidade; }
}
```

**Usar classe de outro pacote.** Sem import, precisa do nome completo; com import, basta o nome simples:

```java
package br.com.transporte;

public class Transportadora {
    public void transportar(br.com.loja.Filial remetente, br.com.loja.Filial destinatario) {
        // movimentar carga do remetente para o destinatário
    }
}
```

```java
package br.com.transporte;
import br.com.loja.Filial;

public class Transportadora {
    public void transportar(Filial remetente, Filial destinatario) {
        System.out.println("De " + remetente.getCidade() + " para " + destinatario.getCidade());
    }
}
```

**Importar uma classe ou o pacote inteiro:**

```java
package br.com.transporte;
import br.com.loja.Filial;                 // uma classe
import br.com.loja.produto.*;              // todas as classes do pacote produto

public class Estoque {
    Filial filial = new Filial();
    Eletrica e = new Eletrica();
    Hidraulica h = new Hidraulica();
}
```

| Instrução | O que importa |
|---|---|
| `import br.com.loja.Filial;` | Só a `Filial` |
| `import br.com.loja.produto.*;` | `Eletrica` e `Hidraulica` |
| `import br.com.loja.*;` | Só as de `br.com.loja` (a `Filial`). **Não** as de `br.com.loja.produto` |

> ⚠️ **Pegadinha:** o `*` **não alcança sub-pacotes**.

**Classes com nomes iguais:**
- No **mesmo pacote**: não pode. Em **pacotes diferentes**: pode (evita colisão).
- A `Filial` de `br.com.transporte` não tem relação com a de `br.com.loja`.
- Se uma classe precisar das duas, use o nome completo de uma (além do texto):

```java
package br.com.transporte;

public class UsaAsDuas {
    br.com.loja.Filial daLoja = new br.com.loja.Filial();    // nome completo
    Filial doTransporte = new Filial();                      // mesmo pacote: nome simples
}
```

> Ligação com a seção 6: acesso sem modificador (default) libera para o **mesmo pacote**.
> Além do texto: classes do mesmo pacote se enxergam sem `import`; classe no pacote default não pode ser usada por classe de pacote nomeado.

**Revisão:** (1) O que é pacote? (2) Onde e como se declara? (3) Convenção de nome? (4) Sem `package`, vai para onde? (5) `import a.b.C;` x `import a.b.*;`? (6) `import br.com.loja.*;` traz `Eletrica`? (7) Duas `Filial` no mesmo projeto?

**Mini exercício:** pacote `br.com.escola` com `Aluno` (atributo `nome` privado) e pacote `br.com.escola.app` com um `Main` que o usa:

```java
package br.com.escola;

public class Aluno {
    private String nome;

    public Aluno(String nome) { this.nome = nome; }

    public String getNome() { return nome; }
}
```

```java
package br.com.escola.app;

import br.com.escola.Aluno;

public class Main {
    public static void main(String[] args) {
        Aluno a = new Aluno("Ana");
        System.out.println(a.getNome()); // Ana
        // a.nome  -> ERRO: nome é private
    }
}
```

---

## 13. Interfaces gráficas (GUI): AWT e Swing
*(Aula 11 "Programação GUI" e "Pacotes na prática"; códigos compilados)*

> GUI é feita de **objetos** (botão, campo, janela). Tudo de POO aparece aqui: herança, interface, construtor.

- **GUI** = interface gráfica; dá ao usuário familiaridade sem ele nunca ter usado o programa.
- É construída com **componentes** (controles, widgets); cada um é um **objeto**.

| | AWT | Swing |
|---|---|---|
| Pacote | `java.awt` | `javax.swing` |
| Origem | Ideia inicial da Sun | JDK 1.2, construída do zero |
| Peso | Mais pesado, depende do sistema de janelas local | Mais leve, flexível, poderoso |
| Limitação | Aparência/comportamento mudam por plataforma | Não depende de máquina |

- Por compatibilidade, usamos **as duas**: `import javax.swing.*;` **e** `import java.awt.*;` (`GridLayout` é do AWT).
- ⚠️ Slide de Pacotes escreve `javax.awt`: o certo é **`java.awt`**.
- ⚠️ Conflito: um slide diz que o Swing tem a mesma aparência em todo sistema; outro, que o look and feel se adapta. Para prova: AWT depende do sistema local; Swing não.

### Elementos
| Elemento | O que é | Exemplos |
|---|---|---|
| Componente | Desenhado na tela | Botão, textbox, label |
| Container | Agrupa componentes | Panel |
| Top-level | Ocupa espaço no desktop | `JFrame`, `JDialog`, `JApplet` |

- Todo programa Swing tem **pelo menos um top-level**. Todo componente precisa estar numa **hierarquia de contenção** com um top-level na raiz.
- Todo top-level tem um **content pane**, que guarda os componentes visíveis.
- Slide manda usar `frame.getContentPane().add(label)`; os formulários usam `add(...)` direto. Desde o Java 5 os dois funcionam (além dos slides).

### Hierarquia (é herança!)
```
Object
└─ Component
   └─ Container
      ├─ JComponent → JButton, JLabel, JMenuBar, JOptionPane, JPanel, JTextField
      └─ Window → Frame → JFrame
```
- `JComponent` é a superclasse de todos os componentes Swing (menos top-levels). Como é subclasse de `Container`, **todo componente Swing também é Container**.
- `class X extends JFrame` = sua classe **é uma** janela. Upcasting vale: `Component c = new JButton("OK");`.

### JFrame e métodos
| Método | Para quê |
|---|---|
| `setTitle(String)` | Título |
| `setVisible(true)` | Mostra a janela (sem isso não aparece). `show()` é **obsoleto** |
| `setDefaultCloseOperation(int)` | O que acontece ao fechar |
| `pack()` | Ajusta ao tamanho preferido dos componentes |
| `setLocationRelativeTo(null)` | Centraliza |
| `setSize` / `setLocation` / `setBackground` / `setFont` / `setEnabled` / `repaint` | Tamanho, posição, cor, fonte, habilita, redesenha |

O slide lista `getLength/Width`; os reais são `getWidth()` e `getHeight()`.

| Constante | Efeito ao fechar |
|---|---|
| `EXIT_ON_CLOSE` | Encerra o **programa inteiro** |
| `DISPOSE_ON_CLOSE` | Fecha só **aquela janela** |

Sem `setDefaultCloseOperation`, fechar a janela não encerra o programa.

### Primeiro programa
```java
import javax.swing.*;

public class ExemploSwing {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Aprendendo JSwing");
        final JLabel label = new JLabel(" AGOSTO 2021");
        frame.getContentPane().add(label);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);
    }
}
```

O mesmo, numa classe que **estende** `JFrame` (`super("...")` define o título):

```java
import javax.swing.*;

public class ExemploSwing extends JFrame {
    public ExemploSwing() {
        super("Exemplo Jswing Frame");
        final JLabel label = new JLabel(" Exemplo Swing Frame AGOSTO 2021 ");
        getContentPane().add(label);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        pack();
        setVisible(true);
    }

    public static void main(String[] args) {
        ExemploSwing frame = new ExemploSwing();
    }
}
```

### Componentes
| Componente | Para quê |
|---|---|
| `JLabel` | Texto **não editável** |
| `JTextField` | Texto **editável** (`getText`, `setText`) |
| `JButton` | Clique dispara evento |
| `JCheckBox` | Marcado ou não (`isSelected`) |
| `JRadioButton` | Em grupo mutuamente exclusivo |
| `ButtonGroup` | Grupo **lógico** (não gráfico): um só selecionado |
| `JComboBox` | Lista suspensa (`getSelectedItem`) |
| `JList` | Lista com seleção múltipla |
| `JTextArea` | Várias linhas |
| `JPanel` | Container intermediário |

> ⚠️ `ButtonGroup` não vai para a tela. Cada radio é adicionado **duas vezes**: ao `ButtonGroup` (exclusividade) e ao `JPanel` (aparecer).

### Eventos: fazer o botão responder
Sem tratador de evento, clicar não faz nada.

```java
import javax.swing.*;

public class ExemploJButton {
    public static void main(String[] args) {
        JFrame f = new JFrame("Exemplo de Botão");
        JButton b = new JButton("Clica AQUI");
        b.setBounds(50, 100, 95, 30);   // posição absoluta: x, y, largura, altura
        f.add(b);
        f.setSize(200, 200);
        f.setLayout(null);              // sem layout manager
        f.setVisible(true);
    }
}
```

A classe **implementa** `ActionListener`, registra-se no botão e escreve `actionPerformed`:

```java
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;

public class ExemploJButton01 implements ActionListener {
    private JButton botao;

    public void janela() {
        JFrame frame = new JFrame();
        botao = new JButton();
        botao.addActionListener(this);                  // REGISTRA O EVENTO
        frame.getContentPane().add(botao);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 100);
        frame.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent evento) {
        botao.setText("Botão foi clicado!");
        botao.setFont(new Font("SansSerif", Font.BOLD, 20));   // ALTERA A FONTE
    }

    public static void main(String[] args) {
        ExemploJButton01 captura = new ExemploJButton01();
        captura.janela();
    }
}
```

| | `implements ActionListener` | Lambda |
|---|---|---|
| Registro | `botao.addActionListener(this);` | `botao.addActionListener(e -> { ... });` |
| Ação | No método `actionPerformed` | No corpo do lambda |
| Aparece em | Slides de GUI | Formulários |

> ⚠️ `implements ActionListener` sem `actionPerformed` **não compila**.

### Layouts
- Em outras linguagens: posicionamento **absoluto** (aqui: `setLayout(null)` + `setBounds(x, y, largura, altura)`). Em Java: **layout managers**.

| Layout | Como organiza |
|---|---|
| `FlowLayout` | Em fila (padrão do `JPanel`) |
| `BorderLayout` | Em regiões (`CENTER` etc.) |
| `GridLayout(l, c, espH, espV)` | Grade. `(6, 2, 10, 10)` = 6 linhas, 2 colunas, 10 px de espaço |

- Containers intermediários: `JPanel`, `JScrollPane`, `JTabbedPane`. Bordas: `BorderFactory` (`createLineBorder`, `createCompoundBorder`...).

**Revisão:** (1) AWT x Swing? (2) Pacotes de cada um? (3) Superclasse dos componentes Swing? (4) Efeito de `EXIT_ON_CLOSE` x `DISPOSE_ON_CLOSE`? (5) O que faz `pack()`? (6) Por que o botão não faz nada? (7) `ButtonGroup` é gráfico? (8) O que é `new GridLayout(6, 2, 10, 10)`?

---

## 14. `JOptionPane` e conversão de dados
*(Aula 11; códigos compilados e conferidos com as imagens dos slides)*

> `JOptionPane` abre **diálogos prontos** em uma linha. O que o usuário digita chega como **`String`**: para fazer conta, converta.

- Todo diálogo **depende de um frame**. Pode ser **modal**: bloqueia a entrada nos outros componentes. Todos os `showXxxDialog` são modais.
- `JOptionPane` (`javax.swing`, subclasse de `JComponent`) cria diálogos modais simples. Para personalizados, `JDialog`.

| Método | Para quê | Devolve |
|---|---|---|
| `showMessageDialog` | Informar | nada |
| `showInputDialog` | Ler do teclado | `String` (`null` se Cancelar) |
| `showConfirmDialog` | Sim, não ou cancelar | `int`: **0 = SIM, 1 = NÃO, 2 = CANCELAR** |
| `showOptionDialog` | Os três em um | `int` |

```java
import javax.swing.JOptionPane;

public class ExemploJOption {
    public static void main(String[] args) {
        int input = JOptionPane.showConfirmDialog(null, "Você gosta de Maçã ?");
        // 0=SIM, 1=NÃO, 2=CANCELAR
        System.out.println(input);
    }
}
```

```java
import javax.swing.JOptionPane;

public class ESNomeJOptionPane {
    public static void main(String[] args) {
        String nome = JOptionPane.showInputDialog("Digite o nome : ");
        String sobreNome = JOptionPane.showInputDialog("Digite o sobrenome: ");
        String nomeCompleto = nome + " " + sobreNome;

        JOptionPane.showMessageDialog(null, "Nome Completo: " + nomeCompleto,
                "Informação", JOptionPane.INFORMATION_MESSAGE);
    }
}
```

Argumentos de `showMessageDialog(null, msg, "Informação", JOptionPane.INFORMATION_MESSAGE)`: 1º **posição** (`null` = centralizada), 2º **mensagem**, 3º **título**, 4º **tipo** (constante, muda o ícone: `WARNING_MESSAGE`, `ERROR_MESSAGE`, `QUESTION_MESSAGE`, `PLAIN_MESSAGE`). Nos formulários o 1º é `this`.

### Converter String em número
| Para | Use |
|---|---|
| `int` | `Integer.parseInt(texto)` |
| `float` | `Float.parseFloat(texto)` |

Texto inválido gera erro (`NumberFormatException`).

```java
import javax.swing.JOptionPane;

public class SaidaValoresInteiros {
    public static void main(String[] args) throws NumberFormatException {

        int valorA = Integer.parseInt(JOptionPane.showInputDialog("Informe o valor A: "));
        int valorB = Integer.parseInt(JOptionPane.showInputDialog("Informe o valor B: "));

        int resultado = valorA * valorB;

        JOptionPane.showMessageDialog(null, "Resultado final: " + resultado, "Resultado",
                JOptionPane.INFORMATION_MESSAGE);
    }
}
```

> ⚠️ O slide se chama "Soma de Valores", mas o código faz `valorA * valorB` (**multiplicação**): 1500 × 1250 = 1875000. Para somar, troque por `+` (2750).

```java
import javax.swing.JOptionPane;

public class Media_Alunos {

    public static void main(String[] args) {
        float nota1, nota2, nota3, calculaMedia;

        nota1 = Float.parseFloat(JOptionPane.showInputDialog("Digite a primeira nota"));
        nota2 = Float.parseFloat(JOptionPane.showInputDialog("Digite a segunda nota"));
        nota3 = Float.parseFloat(JOptionPane.showInputDialog("Digite a terceira nota"));
        calculaMedia = (nota1 + nota2 + nota3) / 3;

        JOptionPane.showMessageDialog(null, "Resultado da Média = " + calculaMedia, "Resultado",
                JOptionPane.WARNING_MESSAGE);
    }
}
```

- Média com 7, 8 e 9 = `8.0`; tipo `WARNING_MESSAGE` (ícone de aviso).
- Decimal com **ponto** (`7.5`); com vírgula o `parseFloat` falha (além dos slides).
- Sem conversão, o `+` **junta texto**: `"1500" + "1250"` = `"15001250"`.

**Revisão:** (1) Pacote do `JOptionPane`? (2) O que é diálogo modal? (3) O que devolve `showInputDialog`? E `showConfirmDialog`? (4) Os 4 argumentos de `showMessageDialog`? (5) Por que `parseInt`? (6) Digitar "abc" onde se espera `int`?

---

## 15. Prática: formulários com Swing
*(AULA_FORMULARIO_NOV; os 3 formulários foram compilados, a janela não foi aberta em tela)*

> Junta tudo: herança (`extends JFrame`), construtor, encapsulamento (`private`), pacotes, eventos e diálogos.

**5 passos no NetBeans:**
1. **Projeto:** File → New Project → Java Application → `ProjetoForm`. **Desmarque "Create Main Class"**.
2. **Classe:** botão direito em Source Packages → New → Java Class → `FormAluno`, pacote **vazio** (default).
3. **Código:** apague o gerado e cole o código.
4. **Executar:** botão direito → Run, ou **F6**. Se pedir a Main Class, selecione `FormAluno`.
5. **Testar:** validação, cadastro, limpar.

Quatro partes: **atributos**, **construtor**, **eventos**, **main**. Os slides dividem em duas telas, mas é **um único construtor**.

```java
import javax.swing.*;
import java.awt.*;

public class FormAluno extends JFrame {

    // ---------- 1) ATRIBUTOS: campos e botões ----------
    private final JTextField nome = new JTextField();
    private final JTextField email = new JTextField();
    private final JComboBox<String> curso =
        new JComboBox<>(new String[]{"Informática"});
    private final JRadioButton manha = new JRadioButton("Manhã");
    private final JRadioButton tarde = new JRadioButton("Tarde");
    private final JRadioButton noite = new JRadioButton("Noite");
    private final JButton cadastrar = new JButton("Cadastrar");
    private final JButton limpar = new JButton("Limpar");

    // ---------- 2) CONSTRUTOR: janela e componentes ----------
    public FormAluno() {
        super("Formulário de cadastro de alunos");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new GridLayout(6, 2, 10, 10));

        add(new JLabel("Cadastro de aluno")); add(new JLabel(""));
        add(new JLabel("Nome:")); add(nome);
        add(new JLabel("E-mail:")); add(email);
        add(new JLabel("Curso:")); add(curso);

        ButtonGroup turnos = new ButtonGroup();
        turnos.add(manha); turnos.add(tarde); turnos.add(noite);
        JPanel painelTurnos = new JPanel();
        painelTurnos.add(manha); painelTurnos.add(tarde); painelTurnos.add(noite);
        add(new JLabel("Turno:")); add(painelTurnos);
        add(cadastrar); add(limpar);

        // ---------- 3) EVENTOS: ações dos botões (ainda dentro do construtor) ----------
        cadastrar.addActionListener(e -> {
            String n = nome.getText().trim();
            String em = email.getText().trim();
            if (n.isEmpty() || em.isEmpty() || turnos.getSelection() == null) {
                JOptionPane.showMessageDialog(this, "Preencha todos os campos!");
                return;
            }
            String turno = manha.isSelected() ? "Manhã" :
                (tarde.isSelected() ? "Tarde" : "Noite");
            JOptionPane.showMessageDialog(this, "Cadastro realizado!\nNome: " + n
                + "\nE-mail: " + em + "\nCurso: " + curso.getSelectedItem()
                + "\nTurno: " + turno);
        });
        limpar.addActionListener(e -> {
            nome.setText(""); email.setText("");
            curso.setSelectedIndex(0); turnos.clearSelection();
        });
        pack();
        setLocationRelativeTo(null);
    }

    // ---------- 4) MAIN: início da aplicação ----------
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new FormAluno().setVisible(true));
    }
}
```

| Trecho | O que faz |
|---|---|
| `extends JFrame` + `super("...")` | A classe é uma janela; título |
| `private final JTextField ...` | Atributo privado; `final` = referência não troca |
| `GridLayout(6, 2, 10, 10)` | 6 linhas × 2 colunas; cada `add` ocupa a próxima célula |
| `JRadioButton` + `ButtonGroup` | Só **um** turno |
| `nome.getText().trim()` | Lê e tira espaços das pontas |
| `turnos.getSelection() == null` | Nenhum turno marcado |
| `curso.getSelectedItem()` | Item escolhido |
| `turnos.clearSelection()` | Desmarca (Limpar) |
| `pack()` + `setLocationRelativeTo(null)` | Ajusta e centraliza |
| `SwingUtilities.invokeLater(...)` | Inicia a GUI na thread de eventos |

**Testes esperados:** campos vazios → "Preencha todos os campos!" (o `return;` interrompe o cadastro); preenchido → "Cadastro realizado!" com os dados; Limpar → campos vazios, curso Informática, turno desmarcado.

**Problemas comuns:**
| Sintoma | Solução |
|---|---|
| `Cannot find symbol JFrame` | Conferir imports `javax.swing.*` e `java.awt.*` |
| `Class does not have a main method` | Project Properties → Run → Main Class = `FormAluno` |
| Janela não abre | Build Project (**F11**) e conferir o `main` |
| Erro de encoding em "Manhã" | Encoding **UTF-8** em Project Properties → Sources |

### Duas janelas: login e cadastro
`FormLogin` abre `FormCadUsuario` (as duas no pacote `cadastro`):

```java
package cadastro;

import javax.swing.*;
import java.awt.*;

public class FormCadUsuario extends JFrame {
  public FormCadUsuario() {
    setTitle("Cadastro de Usuário");
    setSize(350, 250);
    setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
    setLocationRelativeTo(null);
    setLayout(new GridLayout(5, 2, 10, 10));

    JTextField txtNome = new JTextField();
    JTextField txtEmail = new JTextField();
    JTextField txtUsuario = new JTextField();
    JPasswordField txtSenha = new JPasswordField();
    JButton btnSalvar = new JButton("Salvar");
    JButton btnLimpar = new JButton("Limpar");

    // JLabel
    add(new JLabel("Nome:"));
    add(txtNome);
    add(new JLabel("E-mail:"));
    add(txtEmail);
    add(new JLabel("Usuário:"));
    add(txtUsuario);
    add(new JLabel("Senha:"));
    add(txtSenha);
    add(btnSalvar);
    add(btnLimpar);

    // Botão Salvar
    btnSalvar.addActionListener(e -> {
      JOptionPane.showMessageDialog(
        this,
        "Usuário cadastrado com sucesso!"
      );
      dispose();
    });

    // Botão Limpar
    btnLimpar.addActionListener(e -> {
      txtNome.setText("");
      txtEmail.setText("");
      txtUsuario.setText("");
      txtSenha.setText("");
    });
  }
}
```

```java
package cadastro;

import javax.swing.*;
import java.awt.*;

public class FormLogin extends JFrame {
  public FormLogin() {
    setTitle("Sistema - Login");
    setSize(350, 220);
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    setLocationRelativeTo(null);
    setLayout(new GridLayout(4, 2, 10, 10));

    JTextField txtUsuario = new JTextField();
    JPasswordField txtSenha = new JPasswordField();
    JButton btnEntrar = new JButton("Entrar");
    JButton btnCadastrar = new JButton("Cadastrar Usuário");

    // JLabel
    add(new JLabel("Usuário:"));
    add(txtUsuario);
    add(new JLabel("Senha:"));
    add(txtSenha);
    add(btnEntrar);
    add(btnCadastrar);

    // Botão Entrar
    btnEntrar.addActionListener(e -> {
      JOptionPane.showMessageDialog(
        this, "Bem-vindo ao Sistema!"
      );
    });

    // Botão Cadastrar Usuário
    btnCadastrar.addActionListener(e -> {
      FormCadUsuario cadastro = new FormCadUsuario();
      cadastro.setVisible(true);
    });
  }

  public static void main(String[] args) {
    SwingUtilities.invokeLater(() -> {
      new FormLogin().setVisible(true);
    });
  }
}
```

- **Objeto criando objeto:** `new FormCadUsuario()` no lambda, depois `setVisible(true)`.
- `DISPOSE_ON_CLOSE` + `dispose()` na janela de cadastro fecha **só ela**. Com `EXIT_ON_CLOSE`, encerraria o login também.
- Só o `FormLogin` tem `main`. `JPasswordField` esconde o que é digitado.
- ⚠️ "Entrar" só mostra "Bem-vindo ao Sistema!": **não valida** usuário nem senha.
- ⚠️ No slide, o `package cadastro;` aparece só no `FormLogin`; o `FormCadUsuario` também precisa dele.

**Desafios do slide:** validar e-mail; campo telefone; campo CPF; validar CPF.

**Revisão:** (1) Por que desmarcar "Create Main Class"? (2) E-mail vazio no Cadastrar? (3) Por que cada radio vai ao `ButtonGroup` **e** ao `JPanel`? (4) `EXIT` x `DISPOSE`? (5) Por que só o `FormLogin` tem `main`? (6) "Entrar" valida a senha?

**Mini exercícios:**

1. Contador de cliques (`JLabel` + `JButton`):

```java
import javax.swing.*;
import java.awt.FlowLayout;

public class ContadorCliques extends JFrame {
    private int cliques = 0;

    public ContadorCliques() {
        super("Contador");
        JLabel texto = new JLabel("Cliques: 0");
        JButton botao = new JButton("Clique aqui");

        botao.addActionListener(e -> {
            cliques++;
            texto.setText("Cliques: " + cliques);
        });

        setLayout(new FlowLayout());
        add(texto);
        add(botao);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        pack();
        setLocationRelativeTo(null);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new ContadorCliques().setVisible(true));
    }
}
```

`cliques` é **atributo**, por isso o lambda pode alterá-lo.

2. Adicionar **Telefone** ao `FormAluno`. A armadilha é a grade: de 6 para **7 linhas**.
```java
private final JTextField telefone = new JTextField();   // NOVO
setLayout(new GridLayout(7, 2, 10, 10));                 // 6 -> 7
add(new JLabel("Telefone:")); add(telefone);             // NOVO
String tel = telefone.getText().trim();                  // NOVO (no cadastrar)
// incluir tel.isEmpty() na validação e a linha "Telefone" na mensagem
telefone.setText("");                                    // NOVO (no limpar)
```

3. Somar dois números com `JOptionPane`, com e sem conversão:

```java
import javax.swing.JOptionPane;

public class SomaDeDois {
    public static void main(String[] args) {
        String a = JOptionPane.showInputDialog("Informe o valor A:");
        String b = JOptionPane.showInputDialog("Informe o valor B:");

        String junto = a + b;                                   // SEM conversão: + junta texto
        int soma = Integer.parseInt(a) + Integer.parseInt(b);   // COM conversão: + soma números

        JOptionPane.showMessageDialog(null,
            "Sem conversão: " + junto + "\nCom conversão: " + soma,
            "Resultado", JOptionPane.INFORMATION_MESSAGE);
    }
}
```

Com 1500 e 1250: sem conversão `15001250`; com conversão `2750`.

---

## 16. Erros que já aconteceram: confira de novo

| Questão | Pegadinha | Resposta certa |
|---|---|---|
| **A5** | `new Produto()` com só `Produto(String)` declarado | **Erro de compilação** (construtor padrão sumiu) |
| **A16** | O que o upcasting permite | **Tratar subclasses de forma uniforme** |
| **B4** | Definição de abstração | **Considerar só o relevante**, ignorando o resto |
| **B8** | Variável imutável | **`final`** |
| **B15** | Objeto após `new` | Contém **todos os atributos e métodos** da classe |
| **C5** | "4 pilares derivados da abstração" | **Encapsulamento, herança, composição, polimorfismo** |

---

## 17. Perguntas de revisão (responda sem olhar)

1. Qual a diferença entre classe e objeto? E entre objeto e referência?
2. O que acontece ao executar `new Carro();`?
3. Quando o construtor padrão deixa de existir?
4. Para que serve `this` em `this.cor = cor;`?
5. Sobrecarga ou sobreposição: qual exige herança? Qual é resolvida em execução?
6. Em `Animal a = new Cachorro();`, que versão de `fazerSom()` roda? Por quê? Dá para chamar um método só de `Cachorro` por `a`?
7. Qual a diferença entre abstração e encapsulamento?
8. Quais são os "4 pilares derivados da abstração"? E os "4 princípios da OO"?
9. Quem acessa um membro `protected`? E um sem modificador?
10. Por que atributo `public` com getter/setter **não** é bom encapsulamento?
11. Uma classe abstrata pode ser instanciada? Para que serve?
12. Quantas classes uma classe pode estender? E quantas interfaces pode implementar?
13. Em `prof3 = prof1;`, quantos objetos existem?
14. Por que `equals()` padrão retorna `false` para dois produtos com os mesmos valores?
15. Computador↔impressora e automóvel↔pessoa: qual a cardinalidade de cada um?

---

## 18. Mini exercícios

**1. Construtores.** Crie `Livro` com dois construtores (`titulo`) e (`titulo`, `paginas`). Depois tente `new Livro();` e explique o erro.

**2. Encapsulamento.** Reescreva este código para ficar bem encapsulado, com validação para `saldo` nunca ficar negativo:
```java
public class Conta { public double saldo; }
```

**3. Polimorfismo.** Crie `Peca` (abstrata, método `mover()`), `Peao`, `Cavalo` e `Bispo`. Monte um `Peca[]` e percorra chamando `mover()`. Confirme com `instanceof`.

**4. Previsão.** O que imprime?
```java
class A { void f() { System.out.println("A"); } }
class B extends A { @Override void f() { System.out.println("B"); } }
A x = new B();
x.f();
```
*(Resposta: `B`. Ligação tardia, decidida pelo tipo real do objeto.)*

**5. Referências.** Quantos objetos existem e o que cada variável referencia?
```java
Professor p1 = new Professor();
Professor p2 = new Professor();
Professor p3 = p1;
```
*(Resposta: 2 objetos. `p1` e `p3` → mesmo objeto; `p2` → outro.)*

---

## 19. Checklist final

- [ ] Sei a tabela `private / default / protected / public` de cabeça
- [ ] Sei explicar sobrecarga x sobreposição com 4 diferenças
- [ ] Sei por que `new Produto()` falha quando há só `Produto(String)`
- [ ] Sei o que o upcasting permite **e** o que não permite
- [ ] Sei separar abstração de encapsulamento
- [ ] Sei as duas listas de pilares/princípios e quando usar cada uma
- [ ] Sei que `final` (não `const`) impede alteração
- [ ] Revisei exceções, `equals`, `Comparable` e Collections (**não estão nos slides enviados**)
- [ ] Sei explicar por que Java não tem destrutor e o que o garbage collector faz
- [ ] Sei usar `package` e `import`, e sei que o `*` não importa sub-pacotes
- [ ] Sei a diferença entre AWT e Swing, e entre `EXIT_ON_CLOSE` e `DISPOSE_ON_CLOSE`
- [ ] Sei fazer um botão responder (`ActionListener` ou lambda) e ler dados com `JOptionPane` + `parseInt`
