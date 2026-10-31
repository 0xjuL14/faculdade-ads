package Desafio2;
import Desafio1.*;
import javax.swing.*;

public class CadastroLogin {
        static void main(String[] args) {

            String email = JOptionPane.showInputDialog("Digite o seu e-mail: ");

            if (email == null || !email.contains("@")) {
                JOptionPane.showMessageDialog(null, "E-mail inválido!", "Erro", JOptionPane.ERROR_MESSAGE);
                return; // termina
            } else {
                JOptionPane.showMessageDialog(null, "E-mail válido: " + email, "Informação", JOptionPane.INFORMATION_MESSAGE);
            }

            String senha = JOptionPane.showInputDialog("Digite uma senha: ");
            if (ValidaSenha.senhaForte(senha) == true) {
                JOptionPane.showMessageDialog(null, "Cadastro aprovado!", "Informação", JOptionPane.INFORMATION_MESSAGE);
            } else {
                JOptionPane.showMessageDialog(null, "Senha podre!", "Erro", JOptionPane.ERROR_MESSAGE);
            }

        }
}


