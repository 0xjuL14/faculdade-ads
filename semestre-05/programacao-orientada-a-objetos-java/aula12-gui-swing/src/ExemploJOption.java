import javax.swing.*;

public class ExemploJOption {
    static void main(String[] args) {
        int input = JOptionPane.showConfirmDialog(null,"Você gosta de maçã?");
        // 0 = ss / 2 = nn, 3 = fodase
        System.out.println(input);
    }
}
