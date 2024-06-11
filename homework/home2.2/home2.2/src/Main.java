public class Main {

    public static void main(String[] args) {
        if (args.length != 5 && args.length != 8) {
            System.out.println("Usage: <input file> <R> <G> <B> <output file> [unfavorite R] [unfavorite G] [unfavorite B]");
            return;
        }

        String inputFileName = args[0];
        int r = Integer.parseInt(args[1]);
        int g = Integer.parseInt(args[2]);
        int b = Integer.parseInt(args[3]);
        String outputFileName = args[4];

        if (!ImageProcessor.isValidColorValue(r) || !ImageProcessor.isValidColorValue(g) || !ImageProcessor.isValidColorValue(b)) {
            System.out.println("Error: Invalid favorite color value. Each component must be in the range [0, 255].");
            return;
        }

        int[] favoriteColor = {r, g, b};

        int[] unfavoriteColor = {-1, -1, -1};
        if (args.length == 8) {
            int unfavoriteR = Integer.parseInt(args[5]);
            int unfavoriteG = Integer.parseInt(args[6]);
            int unfavoriteB = Integer.parseInt(args[7]);
            if (!ImageProcessor.isValidColorValue(unfavoriteR) || !ImageProcessor.isValidColorValue(unfavoriteG) || !ImageProcessor.isValidColorValue(unfavoriteB)) {
                System.out.println("Error: Invalid unfavorite color value. Each component must be in the range [0, 255].");
                return;
            }
            unfavoriteColor = new int[]{unfavoriteR, unfavoriteG, unfavoriteB};
        }

        try {
            ImageProcessor.processImage(inputFileName, favoriteColor, outputFileName, unfavoriteColor);
            System.out.println("Image processing complete.");
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
