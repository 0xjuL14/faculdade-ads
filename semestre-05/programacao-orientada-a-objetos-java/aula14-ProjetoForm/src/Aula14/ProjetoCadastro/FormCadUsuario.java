package Aula14.ProjetoCadastro;

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
        JButton btnVoltar = new JButton("Voltar");

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
        add(btnVoltar);

        btnSalvar.addActionListener(e -> { // botão de salvar
            JOptionPane.showMessageDialog(this, "Usuário cadastrado com sucesso!");
            dispose();
        });

        btnLimpar.addActionListener(e -> { // botão de limpar
            txtNome.setText("");
            txtEmail.setText("");
            txtUsuario.setText("");
            txtSenha.setText("");
        });

        btnVoltar.addActionListener(e -> { // botão de voltar
            dispose();
        });
    }
}