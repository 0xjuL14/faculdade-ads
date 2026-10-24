package Aula04;

public class Main {
    static void main() {

        Livro livro1 = new Livro("Ecce Homo", "Nietzsche", "Filosofia", "Abril", 1997, 2, 200);
        Livro livro2 = new Livro("O Fim da Eternidade", "Isaac Asimov", "Sci-Fi", "Aleph", 1955, 2, 256);

        Usuario usuario1 = new Usuario("Julia", 29, "Feminino", 999654389);
        Usuario usuario2 = new Usuario("Maria", 30, "Feminino", 987654321);

        Emprestimo emprestimo1 = new Emprestimo("20/04/2025", "10:00", livro1, usuario1);
        Emprestimo emprestimo2 = new Emprestimo("21/04/2025", "12:00", livro2,usuario2);

        System.out.println("Empréstimo: ");
        System.out.println("Livro: " + emprestimo1.getLivroEmprestimo().getTitulo());
        System.out.println("Emprestado para: " + emprestimo1.getUsuarioEmprestimo().getNome());
        System.out.println("Data: " + emprestimo1.getDataEmprestimo() + " " + emprestimo1.getHoraEmprestimo());
        System.out.println();
        System.out.println("Empréstimo: ");
        System.out.println("Livro: " + livro2.getTitulo());
        System.out.println("Emprestado para: " + emprestimo2.getUsuarioEmprestimo().getNome());
        System.out.println("Data: " + emprestimo2.getDataEmprestimo() + " " + emprestimo2.getHoraEmprestimo());
    }
}
