import javax.swing.*;
import java.awt.*;

public class ExemploJButton {
    static void main(String[] args) {
        JFrame f=new JFrame("Botãozin");
        JButton b = new JButton("CLICA AQUI");
        JButton b2 = new JButton("NUH UH");
        b.setBounds(100,100,95,30);
        b2.setBounds(200,100,95,30);
        f.add(b);
        f.add(b2);
        f.setSize(400,300);
        f.setMinimumSize(new Dimension(200,200));
        f.setLayout(null);
        f.setVisible(true);
        f.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
    }
}
