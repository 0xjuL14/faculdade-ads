import javax.swing.*;

public class ESNomeJOptionPane {
    static void main(String[] args) {
        String nome = JOptionPane.showInputDialog("Digite o nome: ");
        String sobrenome = JOptionPane.showInputDialog("Digite o sobrenome");
        String NomeCompleto = nome + " " + sobrenome;

        JOptionPane.showMessageDialog(null, "Nome completo: "+ NomeCompleto, "Informação",JOptionPane.INFORMATION_MESSAGE);

    }
}
