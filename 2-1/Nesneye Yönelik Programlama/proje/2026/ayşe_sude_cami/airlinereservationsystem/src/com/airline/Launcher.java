package com.airline;

/**
 * JAR dosyası için Launcher sınıfı.
 * --cli veya --no-gui argümanı ile terminal modunda çalışır.
 * Argüman verilmezse GUI modunda çalışır.
 */
public class Launcher {
    public static void main(String[] args) {
        boolean cliMode = false;

        // Argümanları kontrol et
        int argIndex = 0;
        while (argIndex < args.length) {
            String arg = args[argIndex];
            if (arg.equals("--cli") || arg.equals("--no-gui") || arg.equals("-c")) {
                cliMode = true;
                break;
            }
            argIndex++;
        }

        if (cliMode) {
            // Terminal modunda çalıştır (JavaFX gerektirmez)
            CliApp.main(args);
        } else {
            // GUI modunda çalıştır (JavaFX gerektirir)
            MainApp.main(args);
        }
    }
}
