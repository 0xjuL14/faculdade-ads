package Aula14.ProjetoForm;

public class ValidaEmail {
    private static final String REGEX =
            "^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$";

    public static boolean isEmail(String email) {
        if (email == null) {
            return false;
        }
        return email.trim().matches(REGEX);
    }
}