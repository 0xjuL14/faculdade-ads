package Desafio1;

import javax.swing.*;


public class PessoaExistente {
    static void main(String[] args) {
        String nome = JOptionPane.showInputDialog("Digite o seu nome: ");

        JOptionPane.showMessageDialog(null, "Nome: " + nome, "Informação", JOptionPane.INFORMATION_MESSAGE);

        String email = JOptionPane.showInputDialog("Digite o seu e-mail: ");

        if (email == null || !email.contains("@")) { // alguma hora eu faço algo melhor aqui
            JOptionPane.showMessageDialog(null, "E-mail inválido!", "Erro", JOptionPane.ERROR_MESSAGE);
            return; // termina
        } else {
            JOptionPane.showMessageDialog(null, "E-mail válido: " + email, "Informação", JOptionPane.INFORMATION_MESSAGE);
        }

        String CPF = JOptionPane.showInputDialog("Digite o seu CPF: ");

        if (ValidaCPF.isCPF(CPF) == true) {
            JOptionPane.showMessageDialog(null, "CPF cadastrado: " + CPF, "Informação", JOptionPane.INFORMATION_MESSAGE);
        } else {
            JOptionPane.showMessageDialog(null,"Erro! CPF inválido!","Informação", JOptionPane.INFORMATION_MESSAGE);
    }




        //JOptionPane.showMessageDialog(null, "Cadastro: "+ NomeCompleto,
        // "Informação",
        // JOptionPane.INFORMATION_MESSAGE);

    }
}
