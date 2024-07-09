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

        Color favoriteColor;
        try {
            favoriteColor = new Color(r, g, b);
        } catch (IllegalArgumentException e) {
            System.out.println("Error: " + e.getMessage());
            return;
        }

        Color unfavoriteColor = null;
        if (args.length == 8) {
            int unfavoriteR = Integer.parseInt(args[5]);
            int unfavoriteG = Integer.parseInt(args[6]);
            int unfavoriteB = Integer.parseInt(args[7]);
            try {
                unfavoriteColor = new Color(unfavoriteR, unfavoriteG, unfavoriteB);
            } catch (IllegalArgumentException e) {
                System.out.println("Error: " + e.getMessage());
                return;
            }
        }

        try {
            Image image = new Image();
            image.load(inputFileName);
            image.transform(favoriteColor, unfavoriteColor);
            image.save(outputFileName);
            System.out.println("Image processing complete.");
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
