# POO em Java — Resumo para a prova

> Fontes: slides (Aula 01, Aula 02, Encapsulamento, Polimorfismo ×2, Learn Java, Plano de Ensino) + questionários de revisão Fundamentos A, B e C.
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

## 11. Erros que já aconteceram: confira de novo

| Questão | Pegadinha | Resposta certa |
|---|---|---|
| **A5** | `new Produto()` com só `Produto(String)` declarado | **Erro de compilação** (construtor padrão sumiu) |
| **A16** | O que o upcasting permite | **Tratar subclasses de forma uniforme** |
| **B4** | Definição de abstração | **Considerar só o relevante**, ignorando o resto |
| **B8** | Variável imutável | **`final`** |
| **B15** | Objeto após `new` | Contém **todos os atributos e métodos** da classe |
| **C5** | "4 pilares derivados da abstração" | **Encapsulamento, herança, composição, polimorfismo** |

---

## 12. Perguntas de revisão (responda sem olhar)

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

## 13. Mini exercícios

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

## 14. Checklist final

- [ ] Sei a tabela `private / default / protected / public` de cabeça
- [ ] Sei explicar sobrecarga x sobreposição com 4 diferenças
- [ ] Sei por que `new Produto()` falha quando há só `Produto(String)`
- [ ] Sei o que o upcasting permite **e** o que não permite
- [ ] Sei separar abstração de encapsulamento
- [ ] Sei as duas listas de pilares/princípios e quando usar cada uma
- [ ] Sei que `final` (não `const`) impede alteração
- [ ] Revisei exceções, `equals`, `Comparable` e Collections (**não estão nos slides enviados**)
