import javax.swing.*;

public class Calculadora {
    static void main(String[] args) {
        float valorA,valorB,calculaResultado = 0;
        valorA = Float.parseFloat(JOptionPane.showInputDialog("Informe o Primeiro valor"));
        String operador = JOptionPane.showInputDialog("Informe o Operador (+,-,/,*,%)");
        char calc = operador.charAt(0);
        valorB = Float.parseFloat(JOptionPane.showInputDialog("Informe o Segundo Valor: "));

        switch(calc){
            case '+':
                calculaResultado = valorA+valorB;
                break;
            case '-':
                calculaResultado = valorA-valorB;
                break;
            case '*':
                calculaResultado = valorA*valorB;
                break;
            case '/':
                if(valorA == 0 || valorB == 0){
                    JOptionPane.showMessageDialog(null,"Não é possível realizar a divisão por zero.","Warning",JOptionPane.WARNING_MESSAGE);
                    break;
                }
                else
                    calculaResultado = valorA/valorB;
                break;
            case '%':
                calculaResultado = valorA%valorB;
                break;
            default:
                JOptionPane.showMessageDialog(null, "Operador inválido!");
                return;
        }
        JOptionPane.showMessageDialog(null,"Resultado do cáculo: "+calculaResultado,"Informação",JOptionPane.INFORMATION_MESSAGE);
    }
}

