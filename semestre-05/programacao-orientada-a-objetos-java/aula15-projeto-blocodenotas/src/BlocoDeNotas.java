import javax.swing.*;
import java.awt.Color;
import java.awt.Font;
import java.awt.Insets;

public class BlocoDeNotas extends JFrame { // ainda tem que ajustar o design de algumas coisas e o botão formatar que é inútil atm

    private JTextArea areaTexto;

    public BlocoDeNotas() {

        setTitle("Bloco de Notas da Juju!");
        setSize(700, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        areaTexto = new JTextArea();

        Color fundoEscuro = new Color(20, 12, 36);
        Color textoClaro = new Color(0, 255, 34);
        Color selecaoFundo = new Color(120, 81, 169);

        areaTexto.setBackground(fundoEscuro);
        areaTexto.setForeground(textoClaro);
        areaTexto.setCaretColor(new Color(255, 20, 147));
        areaTexto.setSelectionColor(selecaoFundo);
        areaTexto.setSelectedTextColor(Color.WHITE);

        areaTexto.setFont(new Font("Consolas", Font.PLAIN, 15));
        areaTexto.setLineWrap(true); // quebra linha automaticamente ao chegar no limite
        areaTexto.setWrapStyleWord(true); // evita cortar palavra no meio na quebra de linha
        areaTexto.setMargin(new Insets(12, 15, 12, 15));

        JScrollPane painel = new JScrollPane(areaTexto);
        painel.setBorder(BorderFactory.createEmptyBorder());

        add(painel);
        criarMenu();
    }

    private void criarMenu() {

        JMenuBar barra = new JMenuBar();

        barra.setBackground(new Color(13, 8, 24));
        barra.setBorder(BorderFactory.createMatteBorder(0, 0, 1, 0, new Color(255, 20, 147)));


        JMenu arquivo = new JMenu("Arquivo");
        JMenu editar = new JMenu("Editar");
        JMenu formatar = new JMenu("Formatar");
        JMenu ajuda = new JMenu("Ajuda");

        Color corTextoMenu = new Color(255, 20, 147);
        arquivo.setForeground(corTextoMenu);
        editar.setForeground(corTextoMenu);
        formatar.setForeground(corTextoMenu);
        ajuda.setForeground(corTextoMenu);

        barra.add(arquivo);
        barra.add(editar);
        barra.add(formatar);
        barra.add(ajuda);

        setJMenuBar(barra);

        JMenuItem novo = new JMenuItem("Novo");
        JMenuItem abrir = new JMenuItem("Abrir");
        JMenuItem salvar = new JMenuItem("Salvar");
        JMenuItem sair = new JMenuItem("Sair");

        novo.setForeground(corTextoMenu);
        abrir.setForeground(corTextoMenu);
        salvar.setForeground(corTextoMenu);
        sair.setForeground(corTextoMenu);

        arquivo.add(novo);
        arquivo.add(abrir);
        arquivo.add(salvar);
        arquivo.addSeparator();
        arquivo.add(sair);

        novo.addActionListener(e -> {
            areaTexto.setText("");
        });

        sair.addActionListener(e -> {
            System.exit(0);
        });

        JMenuItem recortar = new JMenuItem("Recortar");
        JMenuItem copiar = new JMenuItem("Copiar");
        JMenuItem colar = new JMenuItem("Colar");
        JMenuItem selecionar = new JMenuItem("Selecionar Tudo");

        editar.add(recortar);
        editar.add(copiar);
        editar.add(colar);
        editar.add(selecionar);

        recortar.addActionListener(e -> areaTexto.cut());
        copiar.addActionListener(e -> areaTexto.copy());
        colar.addActionListener(e -> areaTexto.paste());
        selecionar.addActionListener(e -> areaTexto.selectAll());

        abrir.addActionListener(e -> abrirArquivo());
        salvar.addActionListener(e -> salvarArquivo());

        JMenuItem sobre = new JMenuItem("Sobre");
        ajuda.add(sobre);

        sobre.addActionListener(e -> {
            JOptionPane.showMessageDialog(this, "Bloco de Notas da Juju! \n Feito em Java - 0xjuL14", "Sobre", JOptionPane.INFORMATION_MESSAGE);
        });
    }

    private void abrirArquivo() {

        JFileChooser escolha = new JFileChooser();

        if (escolha.showOpenDialog(this) == JFileChooser.APPROVE_OPTION) {
            try {
                java.io.FileReader leitor = new java.io.FileReader(escolha.getSelectedFile());
                areaTexto.read(leitor, null);
                leitor.close();
            } catch (Exception erro) {
                JOptionPane.showMessageDialog(this, "Erro ao abrir arquivo!");
            }
        }
    }

    private void salvarArquivo() {

        JFileChooser escolha = new JFileChooser();

        if (escolha.showSaveDialog(this) == JFileChooser.APPROVE_OPTION) {
            try {
                java.io.FileWriter escritor = new java.io.FileWriter(escolha.getSelectedFile());
                escritor.write(areaTexto.getText());
                escritor.close();
                JOptionPane.showMessageDialog(this, "Arquivo salvo com sucesso!");
            } catch (Exception erro) {
                JOptionPane.showMessageDialog(this, "Erro ao salvar arquivo!!");
            }
        }
    }

    private static void aplicarTema() { // define as cores antes de criar a janela

        Color violeta = new Color(20, 12, 36);
        Color violetaEscuro = new Color(13, 8, 24);
        Color verdeNeon = new Color(0, 255, 60);
        Color rosaChoque = new Color(255, 20, 147);
        Color roxoRoyal = new Color(120, 81, 169);

        UIManager.put("PopupMenu.background", violetaEscuro); // menu que abre quando clicka
        UIManager.put("PopupMenu.border", BorderFactory.createLineBorder(rosaChoque));

        UIManager.put("MenuItem.background", violetaEscuro); // textos dentro dos menus
        UIManager.put("MenuItem.foreground", rosaChoque);
        UIManager.put("MenuItem.selectionBackground", roxoRoyal);
        UIManager.put("MenuItem.selectionForeground", verdeNeon);
        UIManager.put("MenuItem.acceleratorForeground", verdeNeon);

        UIManager.put("MenuItem.border", BorderFactory.createEmptyBorder(2, 2, 2, 2)); // tira a bordinha branca que o Swing desenha no item selecionado
        UIManager.put("Menu.border", BorderFactory.createEmptyBorder(2, 2, 2, 2));

        UIManager.put("Menu.selectionBackground", roxoRoyal); // menus da barra quando estão abertos
        UIManager.put("Menu.selectionForeground", verdeNeon);

        UIManager.put("Separator.foreground", roxoRoyal); // linha para separar
        UIManager.put("Separator.background", violetaEscuro);

        UIManager.put("OptionPane.background", violeta); // caixinhas de diálogos
        UIManager.put("OptionPane.messageForeground", verdeNeon);
        UIManager.put("Panel.background", violeta);
        UIManager.put("Label.foreground", verdeNeon);


        UIManager.put("Button.background", violetaEscuro); // botões
        UIManager.put("Button.foreground", rosaChoque);
        UIManager.put("Button.select", roxoRoyal);
        UIManager.put("Button.focus", verdeNeon);

        UIManager.put("List.background", violetaEscuro); // ajustes de detalhes da janela
        UIManager.put("List.foreground", verdeNeon);
        UIManager.put("List.selectionBackground", roxoRoyal);
        UIManager.put("List.selectionForeground", Color.WHITE);
        UIManager.put("TextField.background", violetaEscuro);
        UIManager.put("TextField.foreground", verdeNeon);
        UIManager.put("TextField.caretForeground", rosaChoque);
        UIManager.put("ComboBox.background", violetaEscuro);
        UIManager.put("ComboBox.foreground", verdeNeon);
        UIManager.put("ComboBox.selectionBackground", roxoRoyal);
        UIManager.put("ComboBox.selectionForeground", Color.WHITE);
    }

    public static void main(String[] args) {

        aplicarTema();
        new BlocoDeNotas().setVisible(true);
    }
}