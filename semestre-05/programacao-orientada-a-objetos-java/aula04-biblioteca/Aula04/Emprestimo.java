package Aula04;

public class Emprestimo {
    private String dataEmprestimo;
    private String horaEmprestimo;
    private Livro livroEmprestimo;
    private Usuario usuarioEmprestimo;

    public Emprestimo() {
    }

    public Emprestimo(String dataEmprestimo, String horaEmprestimo, Livro livroEmprestimo, Usuario usuarioEmprestimo) {
        this.dataEmprestimo = dataEmprestimo;
        this.horaEmprestimo = horaEmprestimo;
        this.livroEmprestimo = livroEmprestimo;
        this.usuarioEmprestimo = usuarioEmprestimo;
    }

    public String getDataEmprestimo() {
        return dataEmprestimo;
    }

    public void setDataEmprestimo(String dataEmprestimo) {
        this.dataEmprestimo = dataEmprestimo;
    }

    public String getHoraEmprestimo() {
        return horaEmprestimo;
    }

    public void setHoraEmprestimo(String horaEmprestimo) {
        this.horaEmprestimo = horaEmprestimo;
    }

    public Livro getLivroEmprestimo() {
        return livroEmprestimo;
    }

    public void setLivroEmprestimo(Livro livroEmprestimo) {
        this.livroEmprestimo = livroEmprestimo;
    }

    public Usuario getUsuarioEmprestimo() {
        return usuarioEmprestimo;
    }

    public void setUsuarioEmprestimo(Usuario usuarioEmprestimo) {
        this.usuarioEmprestimo = usuarioEmprestimo;
    }
}
