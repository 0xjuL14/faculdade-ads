import javax.swing.*;

public class Media_Alunos {
    static void main(String[] args) {
        float nota1,nota2,nota3,calculaMedia;

        nota1 = Float.parseFloat(JOptionPane.showInputDialog("Digite a Primeira Nota: "));
        nota2 = Float.parseFloat(JOptionPane.showInputDialog("Digite a Segunda Nota: "));
        nota3 = Float.parseFloat(JOptionPane.showInputDialog("Digite a Terceira Nota: "));
        calculaMedia = (nota1+nota2+nota3)/3;
        JOptionPane.showMessageDialog(null,"A média da nota do aluno é: "+calculaMedia,"Informação",JOptionPane.WARNING_MESSAGE);
    }
}
