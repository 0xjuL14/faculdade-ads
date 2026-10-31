import javax.swing.*;
import java.awt.*;

public class ExemploSwing extends JFrame{
    public ExemploSwing(){
        super("Exemplo da swingueira");
        final JLabel label = new JLabel("mas tá freaky demais pqp");
        getContentPane().add(label);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setMinimumSize(new Dimension(300,50));
        setLocationRelativeTo(null);
        pack();
        setVisible(true);
    }
}

void main(String[] args) {
    ExemploSwing frame = new ExemploSwing();
}