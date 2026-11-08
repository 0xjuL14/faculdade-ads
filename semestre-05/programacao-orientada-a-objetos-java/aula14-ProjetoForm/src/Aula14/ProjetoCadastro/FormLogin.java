package Aula14.ProjetoCadastro;

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

            add(new JLabel("Usuário:"));
            add(txtUsuario);
            add(new JLabel("Senha:"));
            add(txtSenha);
            add(btnEntrar);
            add(btnCadastrar);

            // fazer as validações e deixar bonitinho
            btnEntrar.addActionListener(e -> { // botão entrar
                JOptionPane.showMessageDialog(this, "Bem-vindo ao Sistema!!");
            });

            btnCadastrar.addActionListener(e -> { // botão cadastro user
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