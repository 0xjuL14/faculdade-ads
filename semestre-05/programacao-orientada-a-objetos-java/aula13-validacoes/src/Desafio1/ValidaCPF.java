package Desafio1;
import java.util.InputMismatchException;

public class ValidaCPF {
    public static boolean isCPF(String CPF) {

        if (CPF.equals("00000000000") || CPF.equals("11111111111") ||
                CPF.equals("22222222222") || CPF.equals("33333333333") ||
                CPF.equals("44444444444") || CPF.equals("55555555555") ||
                CPF.equals("66666666666") || CPF.equals("77777777777") ||
                CPF.equals("88888888888") || CPF.equals("99999999999") ||
                (CPF.length() != 11))
            return(false); // erro vários nºs iguais

        char dig10, dig11;
        int sm, i, r, num, peso;

        try { // evita erro de conversao
            sm = 0; // 1º dig. verificador
            peso = 10;
            for (i=0; i<9; i++) {
                num = (int)(CPF.charAt(i) - 48); // converte o inésimo char do CPF em um nº, 48 = '0' em ASCII
                sm = sm + (num * peso);
                peso = peso - 1;
            }

            r = 11 - (sm % 11);
            if ((r == 10) || (r == 11)) {
                dig10 = '0';
            } else {
                dig10 = (char)(r + 48); // converte no respectivo caractere numérico
            }

            sm = 0; // 2º dig. verificador
            peso = 11;
            for(i=0; i<10; i++) {
                num = (int)(CPF.charAt(i) - 48);
                sm = sm + (num * peso);
                peso = peso - 1;
            }

            r = 11 - (sm % 11);
            if ((r == 10) || (r == 11)) {
                dig11 = '0';
            } else {
                dig11 = (char)(r + 48);
            }

            if ((dig10 == CPF.charAt(9)) && (dig11 == CPF.charAt(10))) { // verif. se os dígitos calculados conferem com os dígitos informados
                return (true);
            } else {
                return(false);
            }
        } catch(InputMismatchException erro) {
            return(false);
        }
    }
}

